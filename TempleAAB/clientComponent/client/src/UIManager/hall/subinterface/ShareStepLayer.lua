local BaseLayer = appdf.req(appdf.CLIENT_SRC.."UIManager.BaseLayer")
local ShareStepLayer = class("ShareStepLayer",BaseLayer)

function ShareStepLayer:ctor(turnTable)
    ShareStepLayer.super.ctor(self)
    display.loadSpriteFrames("client/res/ShareTurnTable/ShareTurnTableGUI.plist","client/res/ShareTurnTable/ShareTurnTableGUI.png")
    local parent = cc.Director:getInstance():getRunningScene()
    parent:addChild(self,ZORDER.POPUP)
    self:loadLayer("ShareTurnTable/ShareStepLayer2.csb")
    self:init()
    self._parent = turnTable
    ShowCommonLayerAction(nil,self.content)
    self:doDisplay()
end

function ShareStepLayer:onExit()
    ShareStepLayer.super.onExit(self)
    -- if self.NoticeNext then
    --     G_event:NotifyEvent(G_eventDef.UI_CLIENT_SCENE_NOTICE,{NoticeName="ShareStepLayer"})
    -- end
    G_event:RemoveNotifyEvent(G_eventDef.RECEIVE_VIP_ANDGIFT2)
end

function ShareStepLayer:init()
    self._luckIndex = 1
    self._scrollTabItems = {}
    self.rTitle = self:getChildByName("rTitle")
    self.closeBtn = self:getChildByName("closeBtn")
    self.priceValue = self:getChildByName("priceValue")
    self.needValue = self:getChildByName("needValue")
    self.loadingBar = self:getChildByName("loadingBar")
    self.requireScore = self:getChildByName("requireScore")
    self.scoreTitle = self:getChildByName("scoreTitle")
    self.loadingBarPercent = self:getChildByName("loadingBarPercent")
    self.clonePanel = self:getChildByName("clonePanel")
    self.clonePanel:hide()
    self.historyPanel = self:getChildByName("historyPanel")
    self.title2Image = self:getChildByName("title2Image")
    self.content = self:getChildByName("bg1")
    self.bg = self:getChildByName("bg")
    self.closeBtn:addTouchEventListener(handler(self,self.onTouch))
    self.bg:addTouchEventListener(handler(self,self.onTouch))
    self._nowTitleX = self.scoreTitle:getPositionX()
    self._nowTitleSize = self.requireScore:getContentSize()
    self._nowRTitleX = self.rTitle:getPositionX()
    self._nowRTitleSize = self.priceValue:getContentSize()
    G_event:AddNotifyEvent(G_eventDef.RECEIVE_VIP_ANDGIFT2,handler(self,self.setHistory))
   -- self:requestVip_And_GIFT()
end

function ShareStepLayer:onTouch(sender,eventType)
    if eventType == ccui.TouchEventType.ended then
        local name = sender:getName()
        if name == "bg" then
            self:close()
        elseif name == "closeBtn" then
            self:close()
        elseif name == "inviteBtn" then
            self:close()
            G_ServerMgr:requestTurnTableUserStatus()
        end
    end
end

function ShareStepLayer:doDisplay()
    local llCurrentScore = self._parent.llCurrentScore
    local llRequireScore = self._parent.llRequireScore
    if llCurrentScore >= llRequireScore then
        llCurrentScore = llRequireScore
    end 

    self.requireScore:setString(tostring(math.floor(llRequireScore/100)))
    
    local size = self.requireScore:getContentSize()
    self.title2Image:setPositionX(78.49 + size.width + 12)
    -- if size.width > (self._nowTitleSize.width + 15) then
    --     self.requireScore:setScale((self._nowTitleSize.width + 15)/size.width)
    --     size.width = (self._nowTitleSize.width + 15)
    -- end
    self.scoreTitle:setPositionX(self._nowTitleX + (self._nowTitleSize.width - size.width)/2)
    local cha = llRequireScore - llCurrentScore
    if llCurrentScore == 0 then
        self.priceValue:setString(string.format("%s",g_format:formatNumber(10000,g_format.fType.standard)))
    else
        self.priceValue:setString(string.format("%s",g_format:formatNumber(llCurrentScore,g_format.fType.standard)))
    end
    
    local size = self.priceValue:getContentSize()
    self.rTitle:setPositionX(self._nowRTitleX + (self._nowRTitleSize.width - size.width)/2)
    
    self.needValue:setString(string.format("R$%s",g_format:formatNumber(cha >=0 and cha or 0,g_format.fType.standard)))
    local size = self.needValue:getContentSize()
    if size.width > 90 then
        self.needValue:setScale(90/size.width)
    end

    local percent = llCurrentScore / llRequireScore * 100
    if llRequireScore == 0 then
        self.loadingBarPercent:setString("0%")
    else
        self.loadingBarPercent:setString(string.format("%.2f",percent).."%")
    end
    if percent >= 99 and percent < 100 then
        percent = 98.5
    end  
    self.loadingBar:setPercent(percent)
end

function ShareStepLayer:setHistory()
    local historyData = self._parent._playerHistoryData
    if #historyData <=0 then
        return
    end
    for k = 1,#historyData do
        local data = historyData[k]
        if data then
            local item = self.clonePanel:clone()
            self.historyPanel:addChild(item)
            local bgImage = item:getChildByName("bgImage")
            local userName = item:getChildByName("userName")
            local phoneNumber = item:getChildByName("phoneNumber")
            local scoreText = item:getChildByName("scoreText")
            bgImage:setVisible((k % 2)~=0)
            userName:setString(data.szNickName)
            local headNumber = math.random(10,99)
            local tailNumber = math.random(100,999)
            phoneNumber:setString(string.format("55%s******%s",headNumber,tailNumber))
            item:setAnchorPoint(0.5,1)
            table.insert(self._scrollTabItems,1,item)
            item:hide()
            item:setCascadeOpacityEnabled(true)
            scoreText:setString(string.format("+%s R$",g_format:formatNumber(data.llScore,g_format.fType.abbreviation,g_format.currencyType.GOLD)))
        end
    end
    self:startScroll()
end

--开始滑动
function ShareStepLayer:startScroll(speed)
    local sumCount = #self._scrollTabItems
    for k = 1,sumCount do
        local item = self._scrollTabItems[k]
        local initPosition = cc.p(302,258 -(k - 1) * 67)
        item:setPosition(initPosition)
        if k <= 4 and not speed  then
            item:show()
            local array = {
                cc.MoveTo:create((258 + 67 - item:getPositionY())/30,cc.p(302,258 + 67)),
                cc.CallFunc:create(function() 
                    item:setPosition(cc.p(302,-(k - 1) * 67))
                end)
            }
            item:runAction(cc.Sequence:create(array))
        elseif not speed then
            local initPosition = cc.p(302,-(k - 5) * 67)
            item:setPosition(initPosition)
            local time = (0 - item:getPositionY()) / (speed or 30)
            local time1 = (67) / (speed or 30)
            local time2 = (258 - 134) / (speed or 30)
            local time3 = 67 / (speed or 30)
            local array = {
                cc.MoveTo:create(time,cc.p(302,0)),
                cc.CallFunc:create(function() 
                    item:show()
                end),  
                cc.Spawn:create(
                    cc.MoveTo:create(time1,cc.p(302,67)),
                    cc.FadeIn:create(time1)
                ),
                cc.MoveTo:create(time2,cc.p(302,191)),
                cc.Spawn:create(
                    cc.MoveTo:create(time3,cc.p(302,260)),
                    cc.FadeOut:create(time3)
                ),
                cc.CallFunc:create(function() 
                    item:setPosition(cc.p(302,-(k - 5) * 67))
                    item:hide()
                    if k == sumCount then
                        self:startScroll(30)
                    end
                end)
            }
            item:setOpacity(0)
            item:hide()
            item:runAction(cc.Sequence:create(array))
        else
            local initPosition = cc.p(302,-(k - 1) * 67)
            item:setPosition(initPosition)
            local time = (0 - item:getPositionY()) / (speed or 30)
            local time1 = (67) / (speed or 30)
            local time2 = (258 - 134) / (speed or 30)
            local time3 = 67 / (speed or 30)
            local array = {
                cc.MoveTo:create(time,cc.p(302,0)),
                cc.CallFunc:create(function() 
                    item:show()
                end),  
                cc.Spawn:create(
                    cc.MoveTo:create(time1,cc.p(302,67)),
                    cc.FadeIn:create(time1)
                ),
                cc.MoveTo:create(time2,cc.p(302,191)),
                cc.Spawn:create(
                    cc.MoveTo:create(time3,cc.p(302,260)),
                    cc.FadeOut:create(time3)
                ),
                cc.CallFunc:create(function() 
                    item:setPosition(cc.p(302,-(k - 1) * 67))
                    item:hide()
                    if k == sumCount then
                        self:startScroll(30)
                    end
                end)
            }
            item:setOpacity(0)
            item:hide()
            item:runAction(cc.Sequence:create(array))
        end
    end
end

return ShareStepLayer