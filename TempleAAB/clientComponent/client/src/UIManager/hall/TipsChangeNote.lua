--[[
	游戏通用 未充值切换筹码提示界面
]]
local TipsChangeNote = class("TipsChangeNote", function()
	return display.newLayer(cc.c4b(0, 0, 0, 125))    
end)


function TipsChangeNote:ctor(args)
	self.callback = args.callback 
	if width == nil or height == nil then
		self:setContentSize(display.width,display.height)
	else
		self:setContentSize(width,height)
	end
	
	
	local function onTouch(eventType, x, y)
        return true
    end
	self:setTouchEnabled(true)
	self:registerScriptTouchHandler(onTouch)

    self.csbNode = g_ExternalFun.loadCSB("dialog/TipsChangeNote.csb")
    self:addChild(self.csbNode)    
    g_ExternalFun.loadChildrenHandler(self,self.csbNode)

	self.mm_ButtonJump:onClicked(handler(self,self.onClickJump),true)
	self.mm_ButtonClose:onClicked(handler(self,self.onClickClose),true)
end

function TipsChangeNote:updateLayer()
	self.csbNode:setScale(0.7)
end

function TipsChangeNote:onClickJump()
	GlobalUserItem.GameBackJump = "Recharge" 
	if self.callback then
		self.callback()
	end
end

function TipsChangeNote:onClickClose()
    self:removeSelf() 
end

return TipsChangeNote