local BaseLayer = class("BaseLayer",function() 
    return display.newLayer()
end)
local iskindof = tolua.iskindof
local UIHelper = ccui.Helper
function BaseLayer:ctor()
    self._rootNode = nil
    local function onNodeEvent(event)
        if "enter" == event then
            self:onEnter()
        elseif "exit" == event then
            self:onExit()
        end
    end
    self:registerScriptHandler(onNodeEvent)
    self:setTouchEnabled(true)
end

function BaseLayer:loadLayer(csbPath)
    local node = cc.CSLoader:createNode(csbPath)
    node:setContentSize(cc.size(display.width,display.height))
    node:setAnchorPoint(cc.p(0.5,0.5))
    self._rootNode = node
    node:addTo(self):setPosition(display.cx,display.cy)
    UIHelper:doLayout(node)
    return node
end

function BaseLayer:getChildByName(name,rootNode)
    rootNode = rootNode or self._rootNode
    local curNode = nil
    if iskindof(rootNode,"ccui.Widget") then
        curNode = UIHelper:seekWidgetByName(rootNode,name) or rootNode:getChildByName(name)
    else
        curNode = rootNode:getChildByName(name)
    end
    if curNode then
        return curNode
    else
        local nodeTab = rootNode:getChildren()
        if #nodeTab>0 then		
            for i=1,#nodeTab do
                local  result = self:getChildByName(name,nodeTab[i])
                if result then					
                    return result
                end 
            end
        end

    end
    return nil
end

function BaseLayer:close()
    DoHideCommonLayerAction(self.bg,self.content,function() self:removeSelf() end)
end

function BaseLayer:onExit()
    self:unregisterScriptHandler()
end

function BaseLayer:onEnter()
    self:setTouchEvent()
end

function BaseLayer:setTouchEvent()
    local function onTouchBegan(event,params)
        return true
    end

    local function onTouchMoved(event,params)
        
    end

    local function onTouchEvent(event,params)
        self:onTouchEndEvent(event)
    end

    local listener = cc.EventListenerTouchOneByOne:create()
    listener:setSwallowTouches(true)
    listener:registerScriptHandler(onTouchBegan, cc.Handler.EVENT_TOUCH_BEGAN)
    listener:registerScriptHandler(onTouchMoved, cc.Handler.EVENT_TOUCH_MOVED)
    listener:registerScriptHandler(onTouchEvent, cc.Handler.EVENT_TOUCH_ENDED)

    local eventDispatcher =self:getEventDispatcher()
    eventDispatcher:addEventListenerWithSceneGraphPriority(listener,self)

    self:setTouchEnabled(true)
end

function BaseLayer:onTouchEndEvent()

end

function BaseLayer:performWithDelay(func,delayTime)
    if not func then return end
    local array = {
        cc.DelayTime:create(delayTime or (1/60)),
        cc.CallFunc:create(func)
    }
    self:runAction(cc.Sequence:create(array))
end

return BaseLayer