local BaseLayer = appdf.req(appdf.CLIENT_SRC.."UIManager.BaseLayer")
local TurnTableItem = appdf.req(appdf.CLIENT_SRC.."UIManager.hall.subinterface.TurnTable.TurnTableItem")
local TurnTableLayer = class("TurnTableLayer",BaseLayer)
local TurnTableManager = appdf.req(appdf.CLIENT_SRC.."UIManager.hall.subinterface.TurnTable.TurnTableManager")
local EventPost = appdf.req(appdf.CLIENT_SRC.."Tools.EventPost")

function TurnTableLayer:ctor(args)
    local spriteFrameCache = cc.SpriteFrameCache:getInstance()
    spriteFrameCache:addSpriteFrames("client/res/Truntable/TruntablePlist.plist", "client/res/Truntable/TruntablePlist.png")

    TurnTableLayer.super.ctor(self)
    local parent = (args and args.parent) and args.parent or cc.Director:getInstance():getRunningScene()
    parent:addChild(self,ZORDER.POPUP)
    self:setName("TurnTableLayer")
    self:init()
end

function TurnTableLayer:init()
    self:loadLayer("Truntable/TruntableLayer2.csb")
    local pAction = g_ExternalFun.loadTimeLine("Truntable/TruntableLayer.csb")
    pAction:gotoFrameAndPlay(0,false)
    self._rootNode:runAction(pAction)  
    ccui.Helper:doLayout(self._rootNode)
    self:initData()
    self:initView()
   -- ShowCommonLayerAction(nil,self.content)
    self:initListener()
    self:setSpineAnimation()
    self:checkTurnHelperIsOpen()
    self:initLeftListView()
    if not GlobalUserItem.vipGrowLevelConfig then
        showNetLoading()
        G_ServerMgr:C2S_GetGrowLevelConfig()           
    else
        self:onGetGrowLevelConfig(GlobalUserItem.vipGrowLevelConfig)
    end
end

function TurnTableLayer:initData()
    self._initLeftIndex = TurnTableManager.getShowType() or 1
    self._turnEffect = nil
    self._initRightIndex = 1
    self._nowResolve = false
    self._platformHistoryData1 = {}
    self._platformHistoryData2 = {}
    self._platformHistoryData3 = {}
    self._userHistoryData = nil
    self._userLevel = nil
    self._continuationDay = nil
    self._weekLoginDay = 0
    self._weekLoginMaxDay = 0
    self._monthLoginDay = 0
    self._monthLoginMaxDay = 0
    self._extraBaifenBi = nil
    self._dailyCount = 0
    self._wWeeklyCount = 0
    self._wMonthlyCount = 0
    self._dailyAddition = 0
    self._weeklyAddition = 0
    self._monthlyAddition = 0
    self._rightInfos = {}
    self._platformMaxIndex1 = 0
    self._platformMaxIndex2 = 0
    self._platformMaxIndex3 = 0
    self._platformMinIndex1 = nil
    self._platformMinIndex2 = nil
    self._platformMinIndex3 = nil
    self._userHistoryPageCount = 10
    self._lastVipLeftIndex = 0
    self._requestTime = 0
    self._nowUserPageIndex = 1
    self._userHistoryIsBottom = nil
    self._platformHistoryIsBottom1 = nil
    self._platformHistoryIsBottom2 = nil
    self._platformHistoryIsBottom3 = nil
    self._wDailyAddition = nil           --日转盘额外加成百分比
    self._wWeeklyAddition = nil         --周转盘额外加成百分比
    self._wMonthlyAddition = nil       --月转盘额外加成百分比
    self._nowIndex = 1                  --当前旋转的item
    self._cbItemStatus = {}
    self._isResolve = true
    self._rechargeTabs = {}
    self._chipTabs = {}
    self._bigZhuanPanAni = nil
    performWithDelay(self,function() 
        self._isResolve = false
    end,0.5)                            --动画结束后
    self._cbLogonAddition = 0
    self._lastJiaoDu = 0                --上一次已经转动的角度
    self.NoticeNext = TurnTableManager.getNoticeNext()
end 

function TurnTableLayer:initView()
    self.bg = self:getChildByName("bg")
    g_ExternalFun.adapterScreen(self.bg)
    self.MyGoldText = self:getChildByName("MyGoldText")
    local str = g_format:formatNumber(GlobalUserItem.lUserScore,g_format.fType.abbreviation,g_format.currencyType.GOLD)
    self.MyGoldText:setString(str)
    self.content = self:getChildByName("content")
    self.closeBtn = self:getChildByName("closeBtn")
    self.wenHaoBtn = self:getChildByName("wenHaoBtn")
    self.wenHaoBtn2 = self:getChildByName("wenHaoBtn2")
    self.leftBtn1 = self:getChildByName("leftBtn1")  
    self.leftBtn2 = self:getChildByName("leftBtn2") 
    self.leftBtn3 = self:getChildByName("leftBtn3")
    self.red1 = self.leftBtn1:getChildByName("red")
    self.red2 = self.leftBtn2:getChildByName("red")
    self.red3 = self.leftBtn3:getChildByName("red")
    self.mainNode = self:getChildByName("mainNode")
    self.tipsLayer = self:getChildByName("tipsLayer")
    self.tipsLayer:hide()
    self.tipsImage = self.tipsLayer:getChildByName("tipsImage")
    self.giftNode = self:getChildByName("giftNode")
    self.vipTextRight = self:getChildByName("vipTextRight")
    self.vipText = self:getChildByName("vipText")
    self.nowvipAddText = nil
    self.vipdescText1 = self:getChildByName("vipdescText1")
    self.vipdescText2 = self:getChildByName("vipdescText2")
    self.vipdescText3 = self:getChildByName("vipdescText3")
    self.vipAddText1 = self:getChildByName("vipAddText1")
    self.vipAddText2 = self:getChildByName("vipAddText2")
    self.vipAddText3 = self:getChildByName("vipAddText3")
    self.loginAddText1 = self:getChildByName("loginAddText1")
    self.loginAddText = self:getChildByName("loginAddText")
    self.goToBtn = self:getChildByName("goToBtn")
    self.goToBtn:ignoreContentAdaptWithSize(true)
    self.revolveText = self.goToBtn:getChildByName("revolveText")
    self.stopBtn = self:getChildByName("stopBtn")
    self.stopBtn:hide()  
    self.LoadingBar1 = self:getChildByName("LoadingBar1")
    self.jinDuText1 = self:getChildByName("jinDuText1")
    self.jinDuText = self:getChildByName("jinDuText")
    self.LoadingBar2 = self:getChildByName("LoadingBar2")
    self.lockImage = self.goToBtn:getChildByName("lockImage")
    self.lockImage:hide()
    -- self.rightPanel = self:getChildByName("rightPanel")
    -- self.rightPanel:hide()
  --  self.noSumText = self.rightPanel:getChildByName("noSumText")
    self.tray = self:getChildByName("tray")    
    self.tray:ignoreContentAdaptWithSize(true)
    self.jianTou = self:getChildByName("jianTou")
    self.maskLayer = self:getChildByName("maskLayer")
    self.mainNodeMaskLayer = self:getChildByName("mainNodeMaskLayer")
    self.mainNodeMaskLayer:setOpacity(128)
    self.maskGiftLayer = self:getChildByName("maskGiftLayer")
    self.leftNode = self:getChildByName("leftNode")
    self.rightNode = self:getChildByName("rightNode")
    self.rightTopNode = self:getChildByName("rightTopNode")
    self.bottomNode = self:getChildByName("bottomNode")
    self.spineNode = self:getChildByName("spineNode")
    self.light = self:getChildByName("light")
  --  self.everySprite = self.leftNode:getChildByName("everySprite")
    --self.everyTextValue = self.everySprite:getChildByName("everyTextValue")
   -- self.everyTextValue:setColor(cc.c3b(255,217,3))
   -- self.signText = self.everySprite:getChildByName("signText")
   -- self.everyTextValueSum = self.everySprite:getChildByName("everyTextValueSum")
    self.textNode = self:getChildByName("textNode")
    self.grayMaskNode = self:getChildByName("grayMaskNode")
    self.goToShopBtn = self:getChildByName("goToShopBtn")
    self.clonePanel = self:getChildByName("clonePanel")
    self.clonePanel:hide()
    self.listView = self:getChildByName("listView")
    self.goToHistoryBtn = self:getChildByName("goToHistoryBtn")
    self.listView:removeAllChildren()
    self.maskGiftLayer:hide()
    self.maskLayer:hide()
    self.mainNode:setLocalZOrder(1)
    self.leftNode:setLocalZOrder(2)
    self.rightNode:setLocalZOrder(3)
    self.bottomNode:setLocalZOrder(4)
    self.maskLayer:setLocalZOrder(5)
    self.maskGiftLayer:setLocalZOrder(7)
    self.rightTopNode:setLocalZOrder(10)
    self.red1:hide()
    self.red2:hide()
    self.red3:hide()
    for k = 1,16 do
        local name = "bg_"..k
        self[name] = self.giftNode:getChildByName(name)
        self["numText_"..k] = self.textNode:getChildByName("numText_"..k)
        self["vipLockText_"..k] = self.textNode:getChildByName("vipLockText_"..k)
        self["grayMask_"..k] = self.grayMaskNode:getChildByName("grayMask_"..k)
        self["grayMask_"..k]:hide()
        self[name].grayMask = self["grayMask_"..k]
    end

    -- self.rightNode:setOpacity(0)
    -- local array = {
    --     cc.MoveBy:create(0.5,cc.p(-83,0));
    --     cc.FadeIn:create(0.5)
    -- }
    -- self.rightNode:runAction(cc.Spawn:create(array))
    local array = {
        cc.MoveBy:create(0.5,cc.p(0,-105));
        cc.FadeIn:create(0.5)
    }
    self.rightTopNode:setOpacity(0)
    self.rightTopNode:runAction(cc.Spawn:create(array))

    self.bottomNode:setOpacity(0)
    local array = {
        cc.MoveBy:create(0.5,cc.p(0,85));
        cc.FadeIn:create(0.5)
    }
    self.bottomNode:runAction(cc.Spawn:create(array))
end

function TurnTableLayer:initListener()
    local func = handler(self,self.onTouch)
    self.closeBtn:addTouchEventListener(func)
    self.wenHaoBtn:addTouchEventListener(func)
    self.wenHaoBtn2:addTouchEventListener(func)
    self.leftBtn1:addTouchEventListener(func)
    self.leftBtn2:addTouchEventListener(func)
    self.leftBtn3:addTouchEventListener(func)
    self.goToBtn:addTouchEventListener(func)
    self.goToShopBtn:addTouchEventListener(func)
    self.goToHistoryBtn:addTouchEventListener(func)
    self.mainNodeMaskLayer:addTouchEventListener(func)
    self.tipsLayer:addTouchEventListener(func)
    self.lockImage:addTouchEventListener(func)
    G_event:AddNotifyEvent(G_eventDef.EVENT_TURNTABLE_USERDATA,handler(self,self.userDataConfig))
    -- G_event:AddNotifyEvent(G_eventDef.EVENT_TURNTABLE_NEWDATALIST,handler(self,self.newDataList))
    -- G_event:AddNotifyEvent(G_eventDef.EVENT_TURNTABLE_OLDDATALIST,handler(self,self.oldDataList))
    -- G_event:AddNotifyEvent(G_eventDef.EVENT_TURNTABLE_USERHISTORYDATA,handler(self,self.userDataList))
    G_event:AddNotifyEvent(G_eventDef.EVENT_TURNTABLE_REVOLVERESULT,handler(self,self.resolveResult))
   -- G_event:AddNotifyEvent(G_eventDef.REFRESH_TURNCONFIG,handler(self,self.refreshData))
   G_event:AddNotifyEvent(G_eventDef.UPDATE_TURNTABLE,handler(self,self.updateMyGold))
   G_event:AddNotifyEvent(G_eventDef.EVENT_VIP_GET_LEVEL_CONFIG,handler(self,self.onGetGrowLevelConfig))   --提取成长礼包 返回
end

function TurnTableLayer:onExit()
    TurnTableLayer.super.onExit(self)
    TurnTableManager.setIsShowNext(nil)
    TurnTableManager.setShowType(nil)
    if self.NoticeNext then
        G_event:NotifyEvent(G_eventDef.UI_CLIENT_SCENE_NOTICE,{NoticeName="HallTurnTable"})
    end
    G_event:RemoveNotifyEvent(G_eventDef.EVENT_TURNTABLE_USERDATA)
    -- G_event:RemoveNotifyEvent(G_eventDef.EVENT_TURNTABLE_NEWDATALIST)
    -- G_event:RemoveNotifyEvent(G_eventDef.EVENT_TURNTABLE_OLDDATALIST)
    -- G_event:RemoveNotifyEvent(G_eventDef.EVENT_TURNTABLE_USERHISTORYDATA)
    G_event:RemoveNotifyEvent(G_eventDef.EVENT_TURNTABLE_REVOLVERESULT)
    G_event:RemoveNotifyEvent(G_eventDef.UPDATE_TURNTABLE)
    G_event:RemoveNotifyEvent(G_eventDef.EVENT_VIP_GET_LEVEL_CONFIG)  
end

function TurnTableLayer:onTouch(sender,eventType)
    local name = sender:getName()
    if eventType == ccui.TouchEventType.ended then
        if name == "closeBtn" then
            self:close()
        elseif name == "leftBtn1" then
            if self._initLeftIndex == 1 then
                return
            end
            self:selectLeftBtn(1)
        elseif name == "leftBtn2" then
            if self._initLeftIndex == 2 then
                return
            end
            self:selectLeftBtn(2)
        elseif name == "leftBtn3" then
            if self._initLeftIndex == 3 then
                return
            end
            self:selectLeftBtn(3)
        elseif name == "goToBtn" then               --点击去抽奖
            -- self:goToResolve(math.random(1,6),2,1102,88)
            -- do return end
            
            if self._isResolve then
                return
            end 

            local vip_level = GlobalUserItem.VIPLevel or 0
            if vip_level < 1 then
                --showToast("É necessário alcançar o nível VIP1 para participar.") --达到vip3才可参与
                local txt = g_language:getString("vip_limit")--"É necessário alcançar o nível VIP1 para participar." 
                local pData = {
                    msg = txt,
                    callback = function(click)
                        if click == "ok" then      
                            G_ServerMgr:C2S_GetVIPInfo(1)
                            self:removeSelf()
                        end					
                    end
                }
                G_event:NotifyEvent(G_eventDef.UI_OPEN_COMMON_DIALOG,pData)
                return
            end
            
            if self._lastVipLeftIndex < vip_level then          --如果小于当前vip，跳转到当前vip
                self:selectLeft(vip_level)
                if vip_level > 3 then
                    local innterSize = self.listView:getInnerContainerSize()
                    local size = self.listView:getContentSize()
                    local allLong = innterSize.height - size.height
                    local curPercent = (vip_level - 3) * 126 / allLong
                    -- 设置滚动偏移量
                    self.listView:scrollToPercentVertical(curPercent * 100, 0.5, true)
                end
            end
            local isCanResolve = true
            -- if not self:checkCounts(self._initLeftIndex) then
            --     return
            -- end

            if self._initLeftIndex == 1 then
                if not (self.wDailyCount > 0) then
                    G_event:NotifyEvent(G_eventDef.TURNTABLE_DESCRIBLE,{ShowType = 1,parentObj = self})
                    isCanResolve = false
                end
            elseif self._initLeftIndex == 2 then
                if not (self.wWeeklyCount > 0) then
                    G_event:NotifyEvent(G_eventDef.TURNTABLE_DESCRIBLE,{ShowType = 2,parentObj = self})
                    isCanResolve = false
                end
            elseif self._initLeftIndex == 3 then
                if not (self.wMonthlyCount > 0) then
                    G_event:NotifyEvent(G_eventDef.TURNTABLE_DESCRIBLE,{ShowType = 3,parentObj = self})
                    isCanResolve = false
                end
            end
            if isCanResolve then
                local ip = ""
                if ylAll.LOGONSERVER_LIST and #ylAll.LOGONSERVER_LIST > 0 then
                    local ipConfig = ylAll.LOGONSERVER_LIST[1]
                    if not ipConfig then
                        return
                    end
                    ip = string.split(ipConfig.ip,"|")[1]
                end
                self._isResolve = true
                G_ServerMgr:goToRevolveTurnTable(self._initLeftIndex - 1,ip)
            end
        elseif name == "wenHaoBtn" then
            if not TurnTableManager.getHelperData() then
                G_ServerMgr:getTurnHelperConfig()
            else
                G_event:NotifyEvent(G_eventDef.UI_SHOW_TURNHELP)
            end
        elseif name == "wenHaoBtn2" then
            self.tipsLayer:show()
            local size = self.wenHaoBtn2:getContentSize()
            local wordPosition = self.wenHaoBtn2:convertToWorldSpace(cc.p(size.width/2,size.height/2))
            local nodePosition = self.tipsLayer:convertToNodeSpace(wordPosition)
            self.tipsImage:setPosition(cc.p(nodePosition.x,nodePosition.y + 14))
        elseif name == "goToShopBtn" then               --跳转到商城
            if not GlobalData.ProductsOver then return end
            if G_GameFrame  and G_GameFrame._viewFrame and G_GameFrame._viewFrame.goToShop then
                self:close()
                G_GameFrame._viewFrame:goToShop()
            end
        elseif name == "goToHistoryBtn" then            --点击去历史记录
            G_event:NotifyEvent(G_eventDef.UI_SHOW_TURNTABLEHISTORY,{index = self._initLeftIndex})            
        elseif name == "mainNodeMaskLayer" then
            local txt = "Ser VIP desbloqueia recompensas de check-in melhores?"     
            local pData = {
                msg = txt,
                callback = function(click)
                    if click == "ok" then 
                        self:close() 
                        G_ServerMgr:C2S_GetVIPInfo(1)
                    end					
                end
            }
            G_event:NotifyEvent(G_eventDef.UI_OPEN_COMMON_DIALOG,pData)
        elseif name == "tipsLayer" then
            self.tipsLayer:hide()
        elseif name == "lockImage" then
            G_event:NotifyEvent(G_eventDef.UI_SHOW_GIFT_CENTER,{ShowType = 1,})
            self:close()
        end
    end
end

function TurnTableLayer:selectLeftBtn(selectIndex)
    self:changeUiByIndex(selectIndex)
    if selectIndex ~= self._initLeftIndex then          --切换三种模式
        self._nowIndex = 1
        self._lastJiaoDu = 0
        self.giftNode:stopAllActions()
        self.giftNode:setRotation(0)
    end
    self._initLeftIndex = selectIndex
    self["leftBtn"..selectIndex]:setBright(false)
    for k = 1,3 do
        if k ~= selectIndex then
            self["leftBtn"..k]:setBright(true)
        end
    end
    if selectIndex == 3 then
        self:setBigZhuanPanAni()
        self.light:setScale(1.1)
     --   self.everySprite:show()
      --  self.everySprite:setSpriteFrame("client/res/Truntable/GUI/zp_wz7.png")
      --  self.everyTextValue:setString(self._monthLoginDay)
       -- self.everyTextValueSum:setString(self._monthLoginMaxDay)
    else
        self:hideBigZhuanPanAni()
        self.light:setScale(1)
        if selectIndex == 1 then
          --  self.everySprite:hide()
        else
           -- self.everySprite:show()
           -- self.everySprite:setSpriteFrame("client/res/Truntable/GUI/zp_wz8.png")
        --    self.everyTextValue:setString(self._weekLoginDay)
           -- self.everyTextValueSum:setString(self._weekLoginMaxDay)
        end
    end
    
    self:initTurnTableByLeftIndex()
    self:updateRevolveText()
    self:setBottomLoadBar()
end

function TurnTableLayer:updateRevolveText()
    local selectIndex = self._initLeftIndex
    if selectIndex == 1 then                --日转盘  loginAddText
       -- self.vipAddText1:setString(tostring(self._wDailyAddition).."%")
        self.revolveText:setString("（"..tostring(self.wDailyCount).."）")
       -- self.goToBtn:setBright(not (self.wDailyCount <= 0 and true or false))
    elseif selectIndex == 2 then            --周转盘
       -- self.vipAddText2:setString(tostring(self._wWeeklyAddition).."%")
        self.revolveText:setString("（"..tostring(self.wWeeklyCount).."）")
       -- self.goToBtn:setBright(not (self.wWeeklyCount <= 0 and true or false))
    elseif selectIndex == 3 then            --月转盘
      --  self.vipAddText3:setString(tostring(self._wMonthlyAddition).."%")
        self.revolveText:setString("（"..tostring(self.wMonthlyCount).."）")
        --self.goToBtn:setBright(not (self.wMonthlyCount <= 0 and true or false))
    end
    self.red1:setVisible(self.wDailyCount > 0 and true or false)
    self.red2:setVisible(self.wWeeklyCount > 0 and true or false)
    self.red3:setVisible(self.wMonthlyCount > 0 and true or false)
    
end


function TurnTableLayer:setBottomLoadBar()
    local rechargeConfig = self._rechargeTabs[self._initLeftIndex] or {}
    local chipConfig = self._chipTabs[self._initLeftIndex] or {}

   
    self.LoadingBar2:setPercent((rechargeConfig.CurVal/rechargeConfig.MaxVal) * 100)
    self.jinDuText:setString(string.format("%s/%s",g_format:formatNumber(rechargeConfig.CurVal,g_format.fType.standard),g_format:formatNumber(rechargeConfig.MaxVal,g_format.fType.standard)))

    self.LoadingBar1:setPercent((chipConfig.CurVal/chipConfig.MaxVal) * 100)
    self.jinDuText1:setString(string.format("%s/%s",g_format:formatNumber(chipConfig.CurVal,g_format.fType.standard),g_format:formatNumber(chipConfig.MaxVal,g_format.fType.standard)))
    
end

-- 获取幸运转盘用户配置 返回 1513
function TurnTableLayer:userDataConfig(pData)
    local int64 = Integer64:new()
    local cbGrowLevel = pData:readbyte()            -- 当前用户的成长等级[0,15]闭区间
    self.vipText:setString(tostring(cbGrowLevel))
    self._userLevel = cbGrowLevel

    for k = 1,3 do
        if k == 1 then
            self.wDailyCount = pData:readword()            
            self._wDailyAddition = pData:readword()            --日转盘剩余次数
        elseif k == 2 then
            self.wWeeklyCount = pData:readword()           --周转盘剩余次数
            self._wWeeklyAddition =  pData:readword() 
        elseif k == 3 then
            self.wMonthlyCount = pData:readword()          --月转盘剩余次数
            self._wMonthlyAddition = pData:readword()
        end
        local tab = {}                  --充值进度条  
        tab.CurVal =  pData:readdword()
        tab.MaxVal = pData:readdword()
        self._rechargeTabs[k] = tab
        local tab2 = {}                 --下注进度条
        tab2.CurVal = pData:readscore(int64):getvalue()
        tab2.MaxVal = pData:readscore(int64):getvalue()
        self._chipTabs[k] = tab2

        local tab = self._cbItemStatus[k] or {}
        for l = 1,16 do
            tab[l] = pData:readbyte()
        end
        self._cbItemStatus[k] = tab

    end

    local cbSerialLogonDays = pData:readbyte()      --连续登陆天数
    self.loginAddText1:setString(tostring(cbSerialLogonDays))  
    self._continuationDay = cbSerialLogonDays
    local cbLogonAddition = pData:readbyte()        --连续登陆额外附加 百分值
    self._cbLogonAddition = cbLogonAddition
    self.loginAddText:setString(tostring(cbLogonAddition).."%")
    self._weekLoginDay = pData:readbyte()           --本周登录天数
    self._weekLoginMaxDay = pData:readbyte()
    self._monthLoginDay = pData:readbyte()           --本月登录天数
    self._monthLoginMaxDay = pData:readbyte()          

    local wCount = pData:readword()                 --平台最新中奖历史记录条数
    -- local historyData = self:anaLyseLotteryPlatformData(wCount,pData)
    -- dump({
    --     tPayProgress = self._rechargeTabs,
    --     tBetProgress = self._chipTabs,
    --     cbSerialLogonDays = cbSerialLogonDays,
    --     cbLogonAddition = cbLogonAddition,
    --     tLogonDaysWeek = {self._weekLoginDay,self._weekLoginMaxDay},
    --     tLogonDaysMonth = {self._monthLoginDay,self._monthLoginMaxDay},
    --     wDailyCount = self.wDailyCount,
    --     wWeeklyCount = self.wWeeklyCount,
    --     wMonthlyCount = self.wMonthlyCount,
    --     wDailyAddition = self._wDailyAddition,
    --     wWeeklyAddition = self._wWeeklyAddition,
    --     wMonthlyAddition = self._wMonthlyAddition,
    --     cbItemStatus = self._cbItemStatus,
    --     lsItem = historyData
    -- })            
    -- G_ServerMgr:C2s_getTurnPlatformNewGifts(10,self._platformMaxIndex)
     
    self:selectLeftBtn(self._initLeftIndex)
   -- self:selectRight(self._initRightIndex,true)
end

--更新致灰格子
function TurnTableLayer:updateGrayCell()
    local grayConfig = self._cbItemStatus[self._initLeftIndex] or {}

    local turnData = TurnTableManager.getData()
    local nowConfig = turnData and turnData[self._initLeftIndex] or {}
    for k = 1,#nowConfig do
        local turnNode = self["bg_"..k]
        local grayMask = turnNode.grayMask
        local isGray = (grayConfig[k] == 1) and true or false 
        grayMask:setVisible(isGray)
    end
end

--初始化列表
function TurnTableLayer:initTurnTableByLeftIndex()
    local turnData = TurnTableManager.getData()
  --  dump(turnData)
    local _lastVipLeftIndex = self._lastVipLeftIndex
    local vipGrowConfig = GlobalUserItem.vipGrowLevelConfig and GlobalUserItem.vipGrowLevelConfig[_lastVipLeftIndex + 1]
    local addPercent = 0                --加成
    if vipGrowConfig and _lastVipLeftIndex > GlobalUserItem.VIPLevel then
        if self._initLeftIndex == 1 then
            addPercent = vipGrowConfig.wDailyAddition + self._cbLogonAddition
        elseif self._initLeftIndex == 2 then
            addPercent = vipGrowConfig.wWeeklyAddition + self._cbLogonAddition
        elseif self._initLeftIndex == 3 then
            addPercent = vipGrowConfig.wMonthlyAddition + self._cbLogonAddition
        end
    end

    local nowConfig = turnData[self._initLeftIndex] or {}
    local outLineTab = {cc.c3b(196,7,90),cc.c3b(83,19,149),cc.c3b(192,103,17),cc.c3b(33,157,109)}
    for k = 1,#nowConfig do
        local data = nowConfig[k]
        local dwItemID = data.dwItemID      -- 物品ID,没啥用
        local cbLevelRequire = data.cbLevelRequire or 0         -- 解锁等级
        local cbCurrencyType = data.cbCurrencyType          -- 货币类型 1金币，2TC币,100以上为线下实物
        local llCurrencyValue = data.llCurrencyValue        -- 奖励分
        local szName = data.szName
        local turnNode = self["bg_"..k]
        local numText = self["numText_"..k]  
        local icon = turnNode:getChildByName("icon")
        icon:ignoreContentAdaptWithSize(true)
        local lock = turnNode:getChildByName("lock")
        local vipLockText = self["vipLockText_"..k]
        if tonumber(GlobalUserItem.VIPLevel) >= tonumber(cbLevelRequire) then           --vip等级达标，解锁
            lock:hide()
            vipLockText:hide()
        else
            vipLockText:show()
            vipLockText:setString("V"..tostring(cbLevelRequire))
        end

        if cbCurrencyType >= 100 then
            numText:setString(szName)
            if llCurrencyValue == 3 then
                numText:setScale(0.7)
            else
                numText:setScale(0.8)
            end
            
            if llCurrencyValue > 8 or llCurrencyValue < 1 then
                llCurrencyValue = 8
            end
            if llCurrencyValue == 1 then 
                icon:loadTexture("client/res/Truntable/GUI/zp_jb1.png",1)
            else
                icon:loadTexture(string.format("client/res/Truntable/GUI/zp_dj%s.png",llCurrencyValue),1)
            end
            
            local iconSize = icon:getContentSize()
            if iconSize.width > 108 then
                icon:setScale(108 / iconSize.width)
            end
        else
            icon:loadTexture("client/res/Truntable/GUI/mrrw_jb_3.png",1)
            numText:setScale(1)
           -- if 
          
           
           llCurrencyValue = llCurrencyValue + llCurrencyValue * (addPercent / 100)
            if llCurrencyValue >= 100000 then
                llCurrencyValue = math.floor(llCurrencyValue / 100)
                llCurrencyValue = llCurrencyValue * 100
                numText:setString(g_format:formatNumber(llCurrencyValue,g_format.fType.Custom_1))
            else
                 numText:setString(g_format:formatNumber(llCurrencyValue,g_format.fType.standard))
            end         
        end
        
        local outlineColor = outLineTab[k % 4]
        if k%4 == 0 then
            outlineColor = outLineTab[4]
        end 
        numText:enableOutline(outlineColor,3)
       
    end
    self:updateGrayCell()
end

--旋转结果
function TurnTableLayer:resolveResult(pData)

    local int64 = Integer64:new()
    local dwErrorCode = pData:readdword()
    local cbLotteryType = pData:readbyte() 
    local cbItemIndex = pData:readbyte()
    cbItemIndex = cbItemIndex + 1
    local cbCurrencyType = pData:readbyte()
    local llCurrencyValue = pData:readscore(int64):getvalue()
    local wAdditionPercent = pData:readword()
    local llAdditionValue = pData:readscore(int64):getvalue()
    local wRestCount = pData:readword()

    if dwErrorCode == 1207 then                     --错误的转盘类型
        return
    elseif dwErrorCode == 1208 then                 --错误的抽奖时间
        return
    elseif dwErrorCode == 1202 then                 --抽奖次数不足
        return
    end
    local typeName = "日转盘"
    if cbLotteryType == 0 then
        typeName = "日转盘"
        self.wDailyCount = wRestCount
    elseif cbLotteryType == 1 then
        typeName = "周转盘"
        self.wWeeklyCount = wRestCount
    elseif cbLotteryType == 2 then
        typeName = "月转盘"
        self.wMonthlyCount = wRestCount
    end  
    -- dump({
    --     dwErrorCode = dwErrorCode,
    --     cbLotteryType = cbLotteryType,
    --     cbItemIndex = cbItemIndex,
    --     cbCurrencyType = cbCurrencyType,
    --     llCurrencyValue = llCurrencyValue,
    --     wAdditionPercent = wAdditionPercent,
    --     llAdditionValue = llAdditionValue,
    --     wRestCount = wRestCount
    -- })
  
    GlobalUserItem.lUserScore = GlobalUserItem.lUserScore + llCurrencyValue + llAdditionValue
    G_event:NotifyEventTwo(G_eventDef.NET_USER_SCORE_REFRESH)   --全局货币更新
    local desc = string.format("点击了%s抽奖",typeName)
    EventPost:addCommond(EventPost.eventType.CLICK,desc)
    local grayConfig = self._cbItemStatus[cbLotteryType + 1] or {}
    if grayConfig[cbItemIndex] then
        grayConfig[cbItemIndex] = 1
    end
    self:updateRevolveText()
    self:goToResolve(cbItemIndex,cbLotteryType,llCurrencyValue,llAdditionValue,cbCurrencyType)        --开始去旋转
end

function TurnTableLayer:goToResolve(cbItemIndex,cbLotteryType,llCurrencyValue,llAdditionValue,cbCurrencyType)
    
    self.goToBtn:hide()
    self.stopBtn:show()
    local oneJiaoDu = 360 / 16
    local xiangChaIndex = 0
    if cbItemIndex > self._nowIndex then                --如果目的item大于现在的item
        xiangChaIndex = cbItemIndex - self._nowIndex
    else
        xiangChaIndex = 16 - self._nowIndex + cbItemIndex
    end
    local onefinishJiaoDu = 360 - xiangChaIndex * oneJiaoDu
    local zongTime = 9
    
    self.mainNode:setLocalZOrder(6)
    self._nowIndex = cbItemIndex
    
    self._zhuanPanAni:setAnimation(0, "zhuandong", true)
    local array = {
        cc.FadeIn:create(2),
        cc.DelayTime:create(zongTime - 3),
        cc.FadeOut:create(1)
    }  
    self._zhuanPanAni:runAction(cc.Sequence:create(array))                  --转盘转动
    local boomLight = function()   
        self._zhuanPanAni:stopAllActions()                    --爆亮
        self._zhuanPanAni:setOpacity(255)
        self._zhuanPanAni:setAnimation(0,"tingzhi2",false) 
        g_ExternalFun.playEffect("sound/turnBoom.mp3", false)
    end
    local showGiftLayer = function()                                        --结束后再展示奖励界面
        self._isResolve = false
        self.maskLayer:setOpacity(0)
        self.maskLayer:hide()
        self.mainNode:setLocalZOrder(1)
        self:updateGrayCell()
        self:showAward(llCurrencyValue,llAdditionValue,cbCurrencyType)                                 --把用户信息插入
        G_ServerMgr:C2s_getTurnUserConfig(6)                            --获取幸运转盘用户配置 返回 1513
    end
    local showGift = function()             --展示物品
        self:showGift(cbItemIndex,showGiftLayer)
    end

    local resolveFinished = function(delayTime)       
        self._nowResolve = false                        --旋转结束           
        self.stopBtn:hide()    
        self.goToBtn:show()
        self.giftNode:runAction(cc.Sequence:create(
            cc.DelayTime:create(delayTime or 0.6),
            cc.CallFunc:create(boomLight),                  --爆亮
            cc.DelayTime:create(1.5),
            cc.CallFunc:create(showGift)                    --展示物品
        ))
    end   
    self._lastJiaoDu = self._lastJiaoDu + onefinishJiaoDu + 360 * 4 
    self._nowResolve = true                                 --开始旋转
    self._turnEffect = AudioEngine.playEffect("sound/turnSolve.mp3", false)
    TweenLite.to(self.giftNode,zongTime,{ rotation = self._lastJiaoDu,ease = Cubic.easeInOut,
        onComplete = resolveFinished
    })
    self.maskLayer:setOpacity(0)
    self.maskLayer:show()
    self.maskLayer:runAction(cc.Sequence:create(cc.FadeTo:create(1.5,180)))
    self.stopBtn:addTouchEventListener(function(sender,eventType) 
        if eventType == ccui.TouchEventType.ended then
            if self._nowResolve then                        --如果还在旋转
                self.goToBtn:show()
                self.stopBtn:hide()
                self.giftNode:stopAllActions()  
                g_ExternalFun.stopEffect(self._turnEffect)
                self._turnEffect = nil
                TweenLite.killTweensOf(self.giftNode,zongTime,{ rotation = self._lastJiaoDu,ease = Cubic.easeInOut,
                    onComplete = function() 
                        self:resolveFinished(0)
                    end
                })
            end
        end
    end)
end

--展示奖励界面
function TurnTableLayer:showAward(llCurrencyValue,llAdditionValue,cbCurrencyType)
    local name = (cbCurrencyType == 1) and "mrrw_jb_1" or "tc_icon"
    local imagePath = string.format("client/res/public/%s.png",name)
    local goldTxt = llCurrencyValue
    local path = "client.src.UIManager.hall.subinterface.rewardLayer"
    local data = {}
    data.goldImg = imagePath
    data.goldTxt = g_format:formatNumber(goldTxt,g_format.fType.standard,cbCurrencyType)
    data.type = 1
    local layer = appdf.req(path).new(data)
    local vipGrowConfig = GlobalUserItem.vipGrowLevelConfig and GlobalUserItem.vipGrowLevelConfig[GlobalUserItem.VIPLevel + 1]
    local dailyAddtionTab = {vipGrowConfig.wDailyAddition,vipGrowConfig.wWeeklyAddition,vipGrowConfig.wMonthlyAddition}
    local addValue = dailyAddtionTab[self._initLeftIndex]
    local textTab = {}

    if tonumber(addValue) > 0 then
        local worldPosition = self.nowvipAddText:getParent():convertToWorldSpace(cc.p(self.nowvipAddText:getPosition()))
        textTab[2] = {position = worldPosition,value = addValue}
    end
    if self._cbLogonAddition and tonumber(self._cbLogonAddition) > 0 then
        local worldPosition = self.loginAddText:getParent():convertToWorldSpace(cc.p(self.loginAddText:getPosition()))
        textTab[1] = {position = worldPosition,value = self._cbLogonAddition} 
    end
    
    layer:setTurnTableInfo(textTab,llAdditionValue,llCurrencyValue)
end

--展示获得的道具
function TurnTableLayer:showGift(cbItemIndex,callBack)
    self.maskGiftLayer:setOpacity(0)
    self.maskGiftLayer:show()
    self.maskGiftLayer:removeAllChildren()
    self.maskGiftLayer:runAction(cc.Sequence:create(cc.FadeTo:create(0.25,200)))
    local nodeItem = self["bg_"..cbItemIndex]
    local wordPosition = self.giftNode:convertToWorldSpace(cc.p(nodeItem:getPosition()))
    local nodePosition = self.maskGiftLayer:convertToNodeSpace(wordPosition)
    self:showNodeAnimation(nodePosition,nodeItem,callBack,cbItemIndex)
end

function TurnTableLayer:showNodeAnimation(nodePosition,nodeItem,callBack,cbItemIndex)
    local parent = self.maskGiftLayer
    local spine = self:addSpine(parent,"client/res/spine/zhuanpangshanguang.json","client/res/spine/zhuanpangshanguang.atlas")
    spine:setPosition(cc.p(nodePosition.x - 2,nodePosition.y + 280)) 
    spine:setScale(0.445)
    spine:setAnimation(0,"animation",false)
    local numText = (self["numText_"..cbItemIndex]):clone()
    local icon = (nodeItem:getChildByName("icon")):clone()
    spine:addChild(numText)
    spine:addChild(icon)
    numText:setScale(2.1)
    numText:setRotation(-90)
    icon:setScale(2.1)
    numText:setAnchorPoint(1,0.5)
    icon:setAnchorPoint(0.5,0.5)
    numText:setPosition(cc.p(4,33))
    icon:setPosition(cc.p(-1.2,182))
    spine:registerSpineEventHandler( function( event )
        if event.animation == "animation" then
            self.maskGiftLayer:setOpacity(0)
            self.maskGiftLayer:hide()
            icon:hide()
            numText:hide()
            if callBack then
                callBack()
            end
        end
    end, sp.EventType.ANIMATION_COMPLETE)   
end

function TurnTableLayer:setSpineAnimation()
    local spine = self:addSpine(self.spineNode,"client/res/spine/zhuanpan.json","client/res/spine/zhuanpan.atlas")
    spine:setPosition(cc.p(4,5))
    spine:registerSpineEventHandler( function( event )
        if event.animation == "zhuandong" then
            
        elseif event.animation == "tingzhi2" then
           self._zhuanPanAni:setOpacity(0)
        end
    end, sp.EventType.ANIMATION_COMPLETE)   
    self._zhuanPanAni = spine
    self._zhuanPanAni:setMix("zhuandong","tingzhi2",0.2)            --动画过渡
    self._zhuanPanAni:setOpacity(0)
    self._zhuanPanAni:setScale(0.995)

    local contentSize = self.leftBtn1:getContentSize()
    local spine = self:addSpine(self.leftBtn1,"client/res/spine/xuanzhongkuan.json","client/res/spine/xuanzhongkuan.atlas")
    spine:setAnimation(0, "animation", true)
    self.leftBtn1._spine = spine
    spine:setPosition(cc.p(contentSize.width/2,contentSize.height/2))
    local spine = self:addSpine(self.leftBtn2,"client/res/spine/xuanzhongkuan.json","client/res/spine/xuanzhongkuan.atlas")
    spine:setAnimation(0, "animation", true)
    self.leftBtn2._spine = spine
    spine:setPosition(cc.p(contentSize.width/2,contentSize.height/2))
    local spine = self:addSpine(self.leftBtn3,"client/res/spine/xuanzhongkuan.json","client/res/spine/xuanzhongkuan.atlas")
    spine:setAnimation(0, "animation", true)
    self.leftBtn3._spine = spine
    spine:setPosition(cc.p(contentSize.width/2,contentSize.height/2))
   
end

function TurnTableLayer:addSpine(parentNode,jsonPath,atlasPath)
    local spine = sp.SkeletonAnimation:createWithJsonFile(jsonPath,atlasPath, 1)        
    spine:addTo(parentNode)
    return spine
end

--货币加小数点
function TurnTableLayer:getValueFormat(numberStr,llCurrencyValue)
    numberStr = tostring(numberStr)
    llCurrencyValue = tostring(llCurrencyValue)
    local index = string.find(numberStr,",")
    local finishStr = ""
    local str = ""
    local sumCount = 0
 
    for k = 1,#numberStr do
        local st = string.sub(numberStr,k,k)
        if st ~= "." and st ~= "," then
            sumCount = sumCount + 1
        end
    end
    if sumCount < 6 then
        for k = 1,6 - sumCount do
            str = str .. "0"
        end
    end
    if index then
        finishStr = numberStr .. str
    else
        finishStr = numberStr..","..str
    end
    return finishStr
end

function TurnTableLayer:checkTurnHelperIsOpen()
    local bool = cc.UserDefault:getInstance():getBoolForKey("isOpenedturnTableHelper",false)
    if not bool then
        performWithDelay(self,function() 
            if not TurnTableManager.getHelperData() then
                G_ServerMgr:getTurnHelperConfig()
            else
                G_event:NotifyEvent(G_eventDef.UI_SHOW_TURNHELP)
            end
            cc.UserDefault:getInstance():setBoolForKey("isOpenedturnTableHelper",true)
        end,0.2)
    end
end

function TurnTableLayer:changeUiByIndex(index)
    if index == 1 then
        self.vipdescText1:setSpriteFrame("client/res/Truntable/GUI/zp_meiri1.png")
        self.vipdescText2:setSpriteFrame("client/res/Truntable/GUI/zp_wz7.png")
        self.vipdescText3:setSpriteFrame("client/res/Truntable/GUI/zp_wz2.png")
        self.vipAddText1:setFntFile("client/res/Truntable/GUI/zp_vipsz2.fnt")
        self.vipAddText2:setFntFile("client/res/Truntable/GUI/zp_vipsz1.fnt")
        self.vipAddText3:setFntFile("client/res/Truntable/GUI/zp_vipsz1.fnt")
        self.leftBtn1._spine:show()
        self.leftBtn2._spine:hide()
        self.leftBtn3._spine:hide()
    elseif index == 2 then
        self.vipdescText2:setSpriteFrame("client/res/Truntable/GUI/zp_meizhou1.png")
        self.vipdescText1:setSpriteFrame("client/res/Truntable/GUI/zp_meiri2.png")
        self.vipdescText3:setSpriteFrame("client/res/Truntable/GUI/zp_wz2.png")
        self.vipAddText1:setFntFile("client/res/Truntable/GUI/zp_vipsz1.fnt")
        self.vipAddText2:setFntFile("client/res/Truntable/GUI/zp_vipsz2.fnt")
        self.vipAddText3:setFntFile("client/res/Truntable/GUI/zp_vipsz1.fnt")
        self.leftBtn1._spine:hide()
        self.leftBtn2._spine:show()
        self.leftBtn3._spine:hide()
    elseif index == 3 then
        self.vipdescText3:setSpriteFrame("client/res/Truntable/GUI/zp_meiyue1.png")
        self.vipdescText1:setSpriteFrame("client/res/Truntable/GUI/zp_meiri2.png")
        self.vipdescText2:setSpriteFrame("client/res/Truntable/GUI/zp_wz7.png")
        self.vipAddText1:setFntFile("client/res/Truntable/GUI/zp_vipsz1.fnt")
        self.vipAddText2:setFntFile("client/res/Truntable/GUI/zp_vipsz1.fnt")
        self.vipAddText3:setFntFile("client/res/Truntable/GUI/zp_vipsz2.fnt")
        self.leftBtn1._spine:hide()
        self.leftBtn2._spine:hide()
        self.leftBtn3._spine:show()
    end
    self.nowvipAddText = self["vipdescText"..index]
    self.mainNode:stopAllActions()
    self.mainNode:setScale(1.0)
    local array = {
        cc.Spawn:create(
            cc.EaseBackOut:create(cc.ScaleTo:create(0.1,0.95)),
            cc.FadeOut:create(0.1)
        ),
        cc.CallFunc:create(function() 
            self.tray:loadTexture("BigImage/zhuanpan1_"..index..".png")
            self.jianTou:setTexture("Truntable/GUI/zp_zz"..index..".png")
            self.goToBtn:loadTextureNormal("Truntable/GUI/zp_zzBtn"..index..".png")
            self.goToBtn:loadTexturePressed("Truntable/GUI/zp_zzBtn"..index..".png")
            self.stopBtn:loadTextureNormal("Truntable/GUI/zp_zzBtn"..index.."2.png")
            self.stopBtn:loadTexturePressed("Truntable/GUI/zp_zzBtn"..index.."2.png")
            if index == 1 or index == 2 then
                self.tray:setPositionY(0)
            else
                self.tray:setPositionY(-26)
            end
        end),
        cc.Spawn:create(
            cc.EaseBackOut:create(cc.ScaleTo:create(0.4,1)),
            cc.FadeIn:create(0.4)
        ),
        
    }   
    self.mainNode:runAction(cc.Sequence:create(array))
end

--核对所有的是否都上锁了
function TurnTableLayer:checkAllLock(index)
    local grayConfig = self._cbItemStatus[index] or {}
    local turnData = TurnTableManager.getData()
    local nowConfig = turnData[index] or {}
    local nowVip = tonumber(GlobalUserItem.VIPLevel)
    for k =1,#grayConfig do
        local data = nowConfig[k]
        local cbLevelRequire = data.cbLevelRequire or 0         -- 解锁等级
        if grayConfig[k] ~= 1 and nowVip >= tonumber(cbLevelRequire) then
            return false
        end
    end
    
    
    return true
end

function TurnTableLayer:setBigZhuanPanAni()
    if self._bigZhuanPanAni then
        self._bigZhuanPanAni:show()
        return
    end
    local spine = self:addSpine(self.spineNode,"client/res/spine/gaojizhuanpan.json","client/res/spine/gaojizhuanpan.atlas")
    spine:setPosition(cc.p(0,0))
    self._bigZhuanPanAni = spine
    spine:setAnimation(0,"animation2",true)
end

function TurnTableLayer:hideBigZhuanPanAni()
    if self._bigZhuanPanAni then
        self._bigZhuanPanAni:hide()
    end 
end

--核对能否抽奖
function TurnTableLayer:checkCounts(index)
    if index == 1 then
        return true
    elseif index == 2 then
        local time = GlobalData.serverTime.llServerTime + GlobalData.serverTime.dwZone * 3600
        local y = os.date("%Y", time)
        local m = os.date("%m", time)
        local d = os.date("%d", time)
    
        local hour = os.date("%H", time)
        local min = os.date("%M", time)
        local second = os.date("%S", time)

        local pToday = os.date("%w",GlobalData.serverTime.llServerTime + GlobalData.serverTime.dwZone * 3600)
        if (tonumber(pToday) == 0) or (tonumber(pToday) == 6) then                --如果是周末
            return true
        else
            showToast("Apenas para uso em sábados e domingo")          --周末才能使用
            return false
        end   
    elseif index == 3 then
        local pToday = os.date("*t",GlobalData.serverTime.llServerTime + GlobalData.serverTime.dwZone * 3600)
        if pToday.day >= 25 then                 --如果大于25号
            return true
        else
            showToast("Disponível somente após o dia 25 de cada mês")
            return false
        end
    end
end

function TurnTableLayer:updateMyGold()
    local str = g_format:formatNumber(GlobalUserItem.lUserScore,g_format.fType.abbreviation,g_format.currencyType.GOLD)
    self.MyGoldText:setString(str)
end

function TurnTableLayer:initLeftListView()
    self._lastVipLeftIndex = nil
    self.clonePanel:hide()
    self.listView:setScrollBarEnabled(false)
    for k = 1,21 do
        local item = self.clonePanel:clone()
        item:show()
        self.listView:pushBackCustomItem(item)
        local cloneBg = item:getChildByName("cloneBg")
        local cloneVip = item:getChildByName("cloneVip")
        local cloneFnt = item:getChildByName("cloneFnt")
        cloneFnt:setString(tostring(k - 1))
        item._tag = k - 1
        item:addTouchEventListener(function(sender,eventType) 
            if eventType == ccui.TouchEventType.began then
                sender:runAction(cc.ScaleTo:create(0.14,0.96))
            elseif eventType == ccui.TouchEventType.canceled then
                sender:runAction(cc.ScaleTo:create(0.14,1))
            elseif eventType == ccui.TouchEventType.ended then
                sender:runAction(cc.ScaleTo:create(0.14,1))
                if self._lastVipLeftIndex == (k - 1) then return end
                self:selectLeft(k - 1)
            end
        end)
        item._cloneBg = cloneBg
        item._cloneVip = cloneVip
        item._cloneFnt = cloneFnt
    end
end

function TurnTableLayer:selectLeft(tag)
    local tag = tag
    if GlobalUserItem.VIPLevel == 0 then
        self.lockImage:show()
        self.mainNodeMaskLayer:hide()
    else
        self.lockImage:hide()
        if tag <= GlobalUserItem.VIPLevel then
            self.mainNodeMaskLayer:hide()
        else
            self.mainNodeMaskLayer:show()
        end
    end
    
    local children = self.listView:getChildren()
    for k = 1,#children do
        local child = children[k]
        local cloneBg = child._cloneBg
        local cloneVip = child._cloneVip
        local cloneFnt = child._cloneFnt
        if child and child._tag == tag then
            cloneBg:loadTexture("client/res/signin/GUI/leftPng/mrdl_vipan2.png",1)
            cloneVip:loadTexture("client/res/signin/GUI/leftPng/mrdl_vipwz2.png",1)
            cloneFnt:setFntFile("client/res/signin/GUI/leftPng/mrdl_sz1.fnt")
            cloneBg:setContentSize(cc.size(276,126))
        elseif child and child._tag == self._lastVipLeftIndex then
            cloneBg:loadTexture("client/res/signin/GUI/leftPng/mrdl_vipan1.png",1)
            cloneVip:loadTexture("client/res/signin/GUI/leftPng/mrdl_vipwz1.png",1)
            cloneFnt:setFntFile("client/res/signin/GUI/leftPng/mrdl_sz2.fnt")
            cloneBg:setContentSize(cc.size(270,120))
        end
    end
    self._lastVipLeftIndex = tag
    self.vipTextRight:setString(tostring(tag))
    self:setRightInfo(tag)
    self:initTurnTableByLeftIndex()
end

function TurnTableLayer:setRightInfo(index)
    index = index + 1
    local vipGrowConfig = GlobalUserItem.vipGrowLevelConfig[index]
    if vipGrowConfig then
        self.vipAddText1:setString("+"..vipGrowConfig.wDailyAddition.."%")
        self.vipAddText2:setString("+"..vipGrowConfig.wWeeklyAddition.."%")
        self.vipAddText3:setString("+"..vipGrowConfig.wMonthlyAddition.."%")
    end
end

function TurnTableLayer:onGetGrowLevelConfig()
    dismissNetLoading()
    local finishIndex = GlobalUserItem.VIPLevel
    self:selectLeft(finishIndex)
    self:performWithDelay(function() 
        if finishIndex > 3 then
            local innterSize = self.listView:getInnerContainerSize()
            local size = self.listView:getContentSize()
            local allLong = innterSize.height - size.height
            local curPercent = (finishIndex - 3) * 126 / allLong
            -- 设置滚动偏移量
            self.listView:scrollToPercentVertical(curPercent * 100, 0.5, true)
        end
    end,1/30) 
end

return TurnTableLayer