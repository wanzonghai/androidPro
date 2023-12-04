local BaseLayer = appdf.req(appdf.CLIENT_SRC.."UIManager.BaseLayer")
local VipHelperMoneyConfig = class("VipHelperMoneyConfig",BaseLayer)


function VipHelperMoneyConfig:onExit()
    VipHelperMoneyConfig.super.onExit(self)
end

function VipHelperMoneyConfig:ctor(args)
    --提前加载合图
    local parent = (args and args.parent) and args.parent or cc.Director:getInstance():getRunningScene()
    parent:addChild(self,ZORDER.POPUP)    
    self:loadLayer("VIP/vipHelperMoneyConfig.csb") 
    ccui.Helper:doLayout(self._rootNode)
    self._args = args
    self:init()
    ShowCommonLayerAction(self.bg,self.content)
end

function VipHelperMoneyConfig:init()
    self:initView()
    self:initListener()
    self:doDisplay()
end

function VipHelperMoneyConfig:initView()
    self.bg = self:getChildByName("bg")
    self.content = self:getChildByName("Image_bg")
    self.btnClose = self:getChildByName("btnClose")
    self.listView = self:getChildByName("listView")
    self.listView:setScrollBarEnabled(false)
    self.Panel_item = self:getChildByName("Panel_item")
    self.Panel_item:hide()
end

function VipHelperMoneyConfig:initListener()
    self.btnClose:addTouchEventListener(handler(self,self.onTouch))
end

function VipHelperMoneyConfig:doDisplay()
    for k = 1,#self._args do
        local vipData = self._args[k]
        local item = self.Panel_item:clone()
        self.listView:pushBackCustomItem(item)
        item:show()
        local itemBG = item:getChildByName("itemBG")
        local vipText = item:getChildByName("vipText")
        local vipDataText = item:getChildByName("vipDataText")
        vipText:setString("VIP"..(k - 1))
        vipDataText:setString((vipData / 10).."%")
        itemBG:setVisible((k % 2) == 1 and true or false)
    end
end

function VipHelperMoneyConfig:onTouch(sender,eventType)
    if eventType == ccui.TouchEventType.ended then
        local name = sender:getName()
        if name == "btnClose" then
            self:close()
        end
    end
end

return VipHelperMoneyConfig