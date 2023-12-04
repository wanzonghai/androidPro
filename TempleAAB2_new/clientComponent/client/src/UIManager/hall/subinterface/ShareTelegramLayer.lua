local BaseLayer = appdf.req(appdf.CLIENT_SRC.."UIManager.BaseLayer")
local ShareTelegramLayer = class("ShareTelegramLayer",BaseLayer)

function ShareTelegramLayer:ctor(args)
    ShareTelegramLayer.super.ctor(self)
    local parent = (args and args.parent) and args.parent or cc.Director:getInstance():getRunningScene()
    parent:addChild(self,ZORDER.POPUP)
    self._args = args
    self.NoticeNext = args and args.NoticeNext
    self:loadLayer("ShareTurnTable/ShareTelegramLayer.csb")
    self:init()
end

function ShareTelegramLayer:onExit()
    ShareTelegramLayer.super.onExit(self)
    if self.NoticeNext then
        G_event:NotifyEvent(G_eventDef.UI_CLIENT_SCENE_NOTICE,{NoticeName="ShareTelegramLayer"})
    end
end

function ShareTelegramLayer:init()
    self:initView()
    self:initListener()
    self:doDisplay()
end

function ShareTelegramLayer:initView()
    self.content = self:getChildByName("bg1")
    self.closeBtn = self:getChildByName("closeBtn")
    self.inviteBtn = self:getChildByName("inviteBtn")
    self.enterBtn = self:getChildByName("enterBtn")
end

function ShareTelegramLayer:initListener()
    self.closeBtn:addTouchEventListener(handler(self,self.onTouch))
    self.inviteBtn:addTouchEventListener(handler(self,self.onTouch))
    self.enterBtn:addTouchEventListener(handler(self,self.onTouch))
end

function ShareTelegramLayer:onTouch(sender,eventType)
    if eventType == ccui.TouchEventType.ended then
        local name = sender:getName()
        if name == "closeBtn" then
            self:close()
        elseif name == "inviteBtn" then
            G_ServerMgr:requestTurnTableUserStatus()
        elseif name == "enterBtn" then
            OSUtil.openURL("https://t.me/PresenteSlots")
        end
    end
end

function ShareTelegramLayer:doDisplay()
    ShowCommonLayerAction(nil,self.content)
end

return ShareTelegramLayer