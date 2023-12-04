local BaseLayer = appdf.req(appdf.CLIENT_SRC.."UIManager.BaseLayer")
local TurnTableHistory = class("TurnTableHistory",BaseLayer)
local TurnTableManager = appdf.req(appdf.CLIENT_SRC.."UIManager.hall.subinterface.TurnTable.TurnTableManager")

function TurnTableHistory:ctor(args)
    TurnTableHistory.super.ctor(self)
    local parent = (args and args.parent) and args.parent or cc.Director:getInstance():getRunningScene()
    parent:addChild(self,ZORDER.POPUP)
    self._initLeftIndex = args.index
    self:setName("TruntableHistory")
    self:loadLayer("Truntable/TruntableHistory.csb")
    self:init()
end

function TurnTableHistory:init()
    self._platformMaxIndex1 = 0
    self._platformMaxIndex2 = 0
    self._platformMaxIndex3 = 0
    self._userHistoryData = nil
    self._initRightIndex = 1
    self._nowUserPageIndex = 1
    self._platformHistoryIsBottom1 = nil
    self._platformHistoryIsBottom2 = nil
    self._platformHistoryIsBottom3 = nil
    self._requestTime = 0
    self._userHistoryPageCount = 10
    self._rightInfos = {}
    self._userHistoryIsBottom = false
    self._platformHistoryData1 = {}
    self._platformHistoryData2 = {}
    self._platformHistoryData3 = {}

    self:initView()
    self:initTableView()
    self:initListener()
    self:doDisplay()
    ShowCommonLayerAction(self.bg,self.content)
    
end

function TurnTableHistory:initView()
    self.bg = self:getChildByName("bg")
    self.content = self:getChildByName("content")
    self.rightBtn1 = self:getChildByName("rightBtn1")
    self.rightBtn1.titleImage = self.rightBtn1:getChildByName("titleImage")
    self.rightBtn2 = self:getChildByName("rightBtn2")
    self.rightBtn2.titleImage = self.rightBtn2:getChildByName("titleImage")
    self.closeBtn = self:getChildByName("closeBtn")
    self.noSumText = self:getChildByName("noSumText")
    self.clonePanel = self:getChildByName("clonePanel")
    self.clonePanel:hide()

end

function TurnTableHistory:onExit()
    TurnTableHistory.super.onExit(self)
    G_event:RemoveNotifyEvent(G_eventDef.EVENT_TURNTABLE_NEWDATALIST)
    G_event:RemoveNotifyEvent(G_eventDef.EVENT_TURNTABLE_OLDDATALIST)
    G_event:RemoveNotifyEvent(G_eventDef.EVENT_TURNTABLE_USERHISTORYDATA)
end

function TurnTableHistory:initListener()
    G_event:AddNotifyEvent(G_eventDef.EVENT_TURNTABLE_NEWDATALIST,handler(self,self.newDataList))
    G_event:AddNotifyEvent(G_eventDef.EVENT_TURNTABLE_OLDDATALIST,handler(self,self.oldDataList))
    G_event:AddNotifyEvent(G_eventDef.EVENT_TURNTABLE_USERHISTORYDATA,handler(self,self.userDataList))
    self.closeBtn:addTouchEventListener(handler(self,self.onTouch))
    self.rightBtn1:addTouchEventListener(handler(self,self.onTouch))
    self.rightBtn2:addTouchEventListener(handler(self,self.onTouch))
    self._tableView:addEventListener(handler(self,self.scrollViewEvent))
end

function TurnTableHistory:onTouch(sender,eventType)
    if eventType == ccui.TouchEventType.ended then
        local name = sender:getName()
        if name == "closeBtn" then
            self:close()
        elseif name == "rightBtn1" then
            if self._initRightIndex == 1 then
                return
            end
            self:selectRight(1)
        elseif name == "rightBtn2" then
            if self._initRightIndex == 2 then
                return
            end
            self:selectRight(2)
        end
    end
end

function TurnTableHistory:doDisplay()
    self:selectRight(self._initRightIndex)
end

--请求服务器数据,获得平台最新记录
function TurnTableHistory:sendServerData()
    if self._initRightIndex == 2 then
        return
    end
    showNetLoading()
    self._tableView:jumpToTop()
    G_ServerMgr:C2s_getTurnPlatformNewGifts(20,self["_platformMaxIndex"..self._initLeftIndex],self._initLeftIndex)
end

function TurnTableHistory:selectRight(index,isInit)
    self._initRightIndex = index
    self["rightBtn"..index]:setBright(false)
    if index == 1 then                          --平台历史记录
        self.rightBtn2:setBright(true)
        self.rightBtn2.titleImage:loadTexture("client/res/Truntable/GUI/zp_lsju4.png",1)
        self.rightBtn1.titleImage:loadTexture("client/res/Truntable/GUI/zp_lsju1.png",1)
        if not isInit then                      --如果不是初始化才请求
            self:sendServerData()               --请求最新记录
        end
    else                                        --用户各人历史记录
        self.rightBtn1:setBright(true)
        self.rightBtn2.titleImage:loadTexture("client/res/Truntable/GUI/zp_lsju3.png",1)
        self.rightBtn1.titleImage:loadTexture("client/res/Truntable/GUI/zp_lsju2.png",1)

        if self._userHistoryData then
            table.sort(self._userHistoryData,function(v1,v2) 
                return v1.llTimestamp > v2.llTimestamp
            end) 
            self:refreshTableView()
            self._tableView:reloadData()
            self._tableView:jumpToTop()
        else
            G_ServerMgr:getTurnUserHistoryList(self._userHistoryPageCount,self._nowUserPageIndex)
            self._nowUserPageIndex = self._nowUserPageIndex + 1
        end
    end
   
end

--平台新记录返回
function TurnTableHistory:newDataList(pData)
    dismissNetLoading()
    local wCount = pData:readword()
    local newData = self:anaLyseLotteryPlatformData(wCount,pData)
    -- dump({
    --     wCount = wCount,
    --     newData = newData
    -- })
    local type = nil
    for k = #newData,1,-1 do
        local data = newData[k]
        data.llCurrencyValue = data.llCurrencyValue or 0
        data.llAdditionValue = data.llAdditionValue or 0
        type = type or (newData[1].cbLotteryType + 1)
        if (data.llCurrencyValue + data.llAdditionValue) > 0 then
            table.insert(self["_platformHistoryData"..type],1,data)
        end
    end  
    if newData and #newData > 0 then
        self["_platformMaxIndex"..type] = newData[1].dwQueueIndex
        self["_platformMinIndex"..type] = self["_platformMinIndex"..type] or newData[#newData].dwQueueIndex
    end

    if self._initRightIndex == 1 then
        self:refreshTableView()
        self._tableView:reloadDataInPos()
    end
end

--平台旧纪录返回
function TurnTableHistory:oldDataList(pData)
    dismissNetLoading()
    local wCount = pData:readword()
    local oldData = self:anaLyseLotteryPlatformData(wCount,pData)
    -- dump({
    --     wCount = wCount,
    --     oldData = oldData
    -- })
    local type = self._initLeftIndex
    for k = 1,#oldData do
        local data = oldData[k]
        data.llCurrencyValue = data.llCurrencyValue or 0
        data.llAdditionValue = data.llAdditionValue or 0
        if (data.llCurrencyValue + data.llAdditionValue) > 0 then
            table.insert(self["_platformHistoryData"..type],data)
        end
    end  
    if oldData and #oldData > 0 then
        self["_platformMinIndex"..type] = oldData[#oldData].dwQueueIndex
    else
        self["_platformHistoryIsBottom"..type] = true
    end

    if self._initRightIndex == 1 then
        self:refreshTableView()
        self._tableView:reloadDataInPos()
    end
end

--平台用户记录
function TurnTableHistory:userDataList(pData)
    dismissNetLoading()
    local wCount = pData:readword()
    local userData = self:anaLyseLotteryUserData(wCount,pData)
    self._userHistoryData = self._userHistoryData or {} 
    if #userData > 0 then
        for k = 1,#userData do
            self._userHistoryData[#self._userHistoryData + 1] = userData[k]
        end
        table.sort(self._userHistoryData,function(v1,v2) 
            return v1.llTimestamp > v2.llTimestamp
        end) 
    else
        self._userHistoryIsBottom = true
    end
    if self._initRightIndex == 2 then
        self:refreshTableView()
        self._tableView:reloadDataInPos()
    end
end

--分析平台记录，返回
function TurnTableHistory:anaLyseLotteryPlatformData(wCount,pData)
    local int64 = Integer64:new()
    local historyData = {}
    for k = 1,wCount do
        local dwQueueIndex = pData:readdword()
        local llTimestamp = pData:readscore(int64):getvalue()
        local cbLotteryType = pData:readbyte()
        local cbItemIndex = pData:readbyte()
        local cbCurrencyType = pData:readbyte()
        local llCurrencyValue = pData:readscore(int64):getvalue()
        local llAdditionValue = pData:readscore(int64):getvalue()
        local szNickName = pData:readstring(32)
        local tab = {}
        tab.dwQueueIndex = dwQueueIndex
        tab.llTimestamp = llTimestamp
        tab.cbItemIndex = cbItemIndex
        tab.cbLotteryType = cbLotteryType
        tab.cbCurrencyType = cbCurrencyType  
        tab.llCurrencyValue = llCurrencyValue
        tab.llAdditionValue = llAdditionValue
        tab.szNickName = szNickName
        historyData[#historyData + 1] = tab
    end
    return historyData
end

function TurnTableHistory:anaLyseLotteryUserData(wCount,pData)
    local int64 = Integer64:new()
    local userData = {}
    local dataConfig = TurnTableManager.getData()
  
    for k = 1,wCount do
        local tab = {}
        tab.llTimestamp = pData:readscore(int64):getvalue()
        tab.cbLotteryType = pData:readbyte()
        tab.cbItemIndex = pData:readbyte()
        tab.cbCurrencyType = pData:readbyte()
        tab.llCurrencyValue = pData:readscore(int64):getvalue()
        tab.llAdditionValue = pData:readscore(int64):getvalue()
        local nowConfig = dataConfig[tab.cbLotteryType + 1] or {}
        tab.cbCurrencyType = nowConfig[tab.cbItemIndex + 1].cbCurrencyType
        userData[#userData + 1] = tab
    end
    return userData
end

function TurnTableHistory:scrollViewEvent(sender,evenType)
    if evenType == 1 then                                        --滚动到底部
        if self._initRightIndex == 1 then
            local leftIndex = self._initLeftIndex
            if not self["_platformHistoryIsBottom"..leftIndex] and (os.time() - self._requestTime) > 1.5 then
                self._requestTime = os.time()
                showNetLoading()
                G_ServerMgr:getTurnPlatformHistory(6,self["_platformMinIndex"..leftIndex],leftIndex)        --拉取老的记录
            end
        elseif self._initRightIndex == 2 then
            if not self._userHistoryIsBottom and (os.time() - self._requestTime) > 1.5  then
                self._requestTime = os.time()
                showNetLoading()
                G_ServerMgr:getTurnUserHistoryList(self._userHistoryPageCount,self._nowUserPageIndex)
                self._nowUserPageIndex = self._nowUserPageIndex + 1
            end
        end
    else                                                         --滚动到顶部
        
    end
    if evenType>=ccui.ScrollviewEventType.scrolling then
		self._tableView:_scrollViewDidScroll()
    end
end

function TurnTableHistory:refreshTableView()
    local infos = {}
    self._rightInfos = {}
    if self._initRightIndex == 1 then               --平台历史记录
        infos = self["_platformHistoryData"..self._initLeftIndex]
    elseif self._initRightIndex == 2 then           --用户各人记录
        infos = self._userHistoryData
    end
    self._rightInfos = infos
    self.noSumText:setVisible(#self._rightInfos == 0)
end

function TurnTableHistory:initTableView()
    local tab = cc.TableView2:create(cc.size(1156,652))
    tab:setAnchorPoint(cc.p(0,0))
    tab:setDirection(cc.TableViewDirection.vertical)
    tab:setFillOrder(cc.TableViewFillOrder.topToBottom)
    tab:registerFunc(cc.TableViewFuncType.cellSize, handler(self,self.setSize))
    tab:registerFunc(cc.TableViewFuncType.cellNum, handler(self,self.setNumber))
    tab:registerFunc(cc.TableViewFuncType.cellLoad, handler(self,self.loadCell))
    tab:addEventListener(handler(self,self.scrollViewEvent))
    self.content:addChild(tab)
    tab:setPosition(cc.p(-579.00,-359.79))
    tab:setScrollBarEnabled(false)
    self._tableView = tab
end


function TurnTableHistory:setSize()
    return 1160,96
end

function TurnTableHistory:setNumber()
    return #self._rightInfos
end

function TurnTableHistory:loadCell(view,index)
    local cell = view:dequeueCell()
	if not cell then
		cell = cc.TableViewCell2.new()
	end
    local item=cell._item
    
    if not cell._item then
        item = self.clonePanel:clone()
        item:show()
        cell._item=item
        cell:addChild(cell._item)   
        item:setPosition(cc.p(0,0))
    end
    self:initClonePanel(item,self._rightInfos[index],index)
	return cell
end

function TurnTableHistory:initClonePanel(clonePanel,info)
    local llTimestamp = info.llTimestamp
    local cbLotteryType = info.cbLotteryType
    local llCurrencyValue = info.llCurrencyValue
    local llAdditionValue = info.llAdditionValue
    local szNickName = info.szNickName
    local cbCurrencyType = info.cbCurrencyType
    local playerName = clonePanel:getChildByName("playerName")
    local dateText = clonePanel:getChildByName("dateText")
    local moneyText = clonePanel:getChildByName("moneyText")
    local tingsImage = clonePanel:getChildByName("tingsImage")
    tingsImage:ignoreContentAdaptWithSize(true)
    playerName:setString(szNickName or GlobalUserItem.szNickName)
    local typeDesc = ""
    if cbLotteryType == 0 then
        typeDesc = string.format("%s roleta","Sorteio diário")
    elseif cbLotteryType == 1 then
        typeDesc = string.format("%s roleta"," Sorteio semanal")
    elseif cbLotteryType == 2 then
        typeDesc = string.format("%s roleta","Sorteio mensal")
    end
    dateText:setString(typeDesc)
    if cbCurrencyType >= 100 then
        tingsImage:show()
        moneyText:hide()
        if llCurrencyValue > 8 or llCurrencyValue < 1 then llCurrencyValue = 2 end
        if llCurrencyValue == 1 then 
            tingsImage:loadTexture("client/res/Truntable/GUI/zp_jb1.png",1)
        else
            tingsImage:loadTexture(string.format("client/res/Truntable/GUI/zp_dj%s.png",llCurrencyValue),1)
        end
    else
        tingsImage:hide()
        moneyText:show()
        local str = g_format:formatNumber(llCurrencyValue + llAdditionValue,g_format.fType.abbreviation,g_format.currencyType.GOLD)
        moneyText:setString("R$"..str)
    end

end

return TurnTableHistory