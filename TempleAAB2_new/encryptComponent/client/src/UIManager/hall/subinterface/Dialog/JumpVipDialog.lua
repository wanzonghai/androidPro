

local JumpVipDialog = class("JumpVipDialog", function(msg,callback,outClose)
	local JumpVipDialog = display.newLayer(cc.c4b(0, 0, 0, 175))    
    return JumpVipDialog
end)

function JumpVipDialog:ctor(args)--msg, callback,outClickClose)
    local parent = (args and args.parent) and args.parent or cc.Director:getInstance():getRunningScene() 
    if args.name then
        self:setName(args.name)
    end
    parent:addChild(self,ZORDER.POPUP)

    local msg = args.msg

    self.callback = args.callback or args.callback
    self.outClickClose = args.outClickClose

	self.csbNode = g_ExternalFun.loadCSB("JumpVip/JumpVipDialog.csb")
    -- self.csbNode:setContentSize(display.size)
    -- self.csbNode:setPosition(cc.p(0,0))
    ccui.Helper:doLayout(self.csbNode)
	self:addChild(self.csbNode)

    self.bg = self.csbNode:getChildByName("bg")    
    self.bg:setVisible(false)
    self.content = self.csbNode:getChildByName("content")
    ShowCommonLayerAction(self.bg,self.content)
    self.bg:onClicked(function ()
        if self.outClickClose ~= false then
            self:onClickEvent("close",self.callback)
        end
    end)
    self.bg:setVisible(false)
    
    self.btnClose = self.content:getChildByName("btnClose")
    self.btnClose:onClicked(function ()        
        self:onClickEvent("close",self.callback)        
    end)
    
    self.btnSure = self.content:getChildByName("btnSure")
    self.btnSure:onClicked(function ()        
        self:onClickEvent("middle",self.callback)       
    end)

    self.btnLeft = self.content:getChildByName("btnLeft")
    self.btnLeft:onClicked(function ()        
        self:onClickEvent("ok",self.callback) 
    end)

    self.btnRight = self.content:getChildByName("btnRight")
    self.btnRight:onClicked(function ()        
        self:onClickEvent("cancel",self.callback) 
    end)

    self.btnMiddle_0 = self.content:getChildByName("btnMiddle_0")
    self.btnMiddle_0:onClicked(function ()        
        self:onClickEvent("middle",self.callback)        
    end)

    self.btnLeft_0 = self.content:getChildByName("btnLeft_0")
    self.btnLeft_0:onClicked(function ()        
        self:onClickEvent("ok",self.callback) 
    end)

    self.btnRight_0 = self.content:getChildByName("btnRight_0")
    self.btnRight_0:onClicked(function ()        
        self:onClickEvent("cancel",self.callback) 
    end)

    self.title = self.content:getChildByName("title")
    self.TXT = self.content:getChildByName("TXT")    

    -- self:showTxt(msg)

    -- self.btnSure:setVisible(false)
    -- self.btnMiddle_0:setVisible(true)
    -- self.btnLeft_0:setVisible(true)
    -- self.btnRight_0:setVisible(true)
end

function JumpVipDialog:updateLayer()
	self.csbNode:setScale(0.7)
end

function JumpVipDialog:setCanTouchOutside()
end

function JumpVipDialog:showTxt(msg)
    local pString = ""
    if type(msg) == "table" then
        for i, v in ipairs(msg) do
            pString = pString .. v
            if i~=#msg then
                pString = pString .. "\n"
            end
        end
    else
        pString = msg
    end
    self.TXT:setString(pString)
end

function JumpVipDialog:onClickEvent(click,callback)
    if DoHideCommonLayerAction == nil or type(DoHideCommonLayerAction) ~= "function" then
	     if callback then
	         callback(click)
	     end
         if tolua.cast(self,"cc.Layer") then
             self:removeSelf()
         end         
        return
    end
    DoHideCommonLayerAction(self.bg,self.content,function() 
	     if callback then
	         callback(click)
	     end
         if tolua.cast(self,"cc.Layer") then
             self:removeSelf()
         end 
    end)        
end

return JumpVipDialog
