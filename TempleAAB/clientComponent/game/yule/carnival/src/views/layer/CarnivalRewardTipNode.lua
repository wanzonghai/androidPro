-- 大奖提示界面

local CarnivalDialogBase = appdf.req("game.yule.carnival.src.views.layer.CarnivalDialogBase")
local CarnivalRewardTipNode = class("CarnivalRewardTipNode", CarnivalDialogBase)
local GameLogic = appdf.req("game.yule.carnival.src.models.GameLogic")

--[[
	_data =
	{
		_rateNum = 倍率
		_nums = 金额数
	}
]]
function CarnivalRewardTipNode:ctor(_data)
    tlog('CarnivalRewardTipNode:ctor')
    self.sound_handle = nil
    CarnivalRewardTipNode.super.ctor(self, nil, nil, _data._callBack)
	local csbNode = g_ExternalFun.loadCSB("UI/CarnivalRewardTipNode.csb", self, false)

    local spineNode = csbNode:getChildByName("Node_spine")
    local win_num = csbNode:getChildByName("win_num"):hide()
    win_num:setPositionY(-20)
    win_num:setScale(1.2)
    local totalTimes = 7 --比start动画多一秒
    local runTimes = 150 --数字跑动次数
    --粒子
    local particleFile = "spine/particle/za_lb_jbfzmpdl"
	local particleAniName = "a1"--string.format("%s_start", aniNamePrefix)

    local sound = "sound_res/YOUWIN.mp3"

    local aniNamePrefix = "a1"
    local spineFile = "spine/sb_lbjs_YOUWIN/sb_lbjs_MEGAWIN"
    if _data._rateNum >= GameLogic.Reward_Scope.superbig then
        spineFile = "spine/sb_lbjs_SUPERWIN/sb_lbjs_MEGAWIN"
    	aniNamePrefix = "a1"
        particleAniName = "a3"
        totalTimes = 11
        runTimes = 150
        sound = "sound_res/SUPERWIN.mp3"
    elseif _data._rateNum >= GameLogic.Reward_Scope.big then
        spineFile = "spine/sb_lbjs_MEGAWIN/sb_lbjs_MEGAWIN"
    	aniNamePrefix = "a1"
        particleAniName = "a2"
        totalTimes = 11
        runTimes = 150
        sound = "sound_res/MEGAWIN.mp3"
    elseif _data._rateNum >= GameLogic.Reward_Scope.middle then
        spineFile = "spine/sb_lbjs_BIGWIN/sb_lbjs_BIGWIN"
    	aniNamePrefix = "a1"
        particleAniName = "a1"
        totalTimes = 9
        runTimes = 150
        sound = "sound_res/BIGWIN.mp3"
    end
    
    if _data._rateNum >= GameLogic.Reward_Scope.middle then
        local animation = GameLogic:createAnimateShow(spineNode, particleFile, particleAniName, true, 0, 0)
    end

	local aniName = aniNamePrefix--string.format("%s_start", aniNamePrefix)
    local animation = GameLogic:createAnimateShow(spineNode, spineFile, aniName, false, 0, 0)
    animation:registerSpineEventHandler( function( event )
        tlog("CarnivalRewardTipNode animation is", event.animation)
        if event.animation == aniName then
        	animation:setAnimation( 0, "a2", true)
        end
    end, sp.EventType.ANIMATION_COMPLETE)

    AudioEngine.playEffect(sound)
    self.sound_handle = g_ExternalFun.playSoundEffect(sound)

    local delay = cc.DelayTime:create(0.5)
    local call = cc.CallFunc:create(function (t, p)
		win_num:setVisible(true)
		win_num._lastNum = 0
		win_num._curNum = p.num
		GameLogic:updateGoldShow(win_num, p.num / p.runTimes)
	end, {num = _data._nums, runTimes = runTimes})
    local delay1 = cc.DelayTime:create(totalTimes)
    local call1 = cc.CallFunc:create(function (t, p)
    	-- if self.m_callBack then
    	-- 	self.m_callBack()
    	-- end
    	-- self:removeFromParent()
    	self:removeNodeEvent()
    end)
    csbNode:runAction(cc.Sequence:create(delay, call, delay1, call1))

end

function CarnivalRewardTipNode:onExit()
    CarnivalRewardTipNode.super.onExit(self)
    if self.sound_handle then
        g_ExternalFun.stopEffect(self.sound_handle)
        self.sound_handle = nil
    end
end
-- function CarnivalRewardTipNode:removeNodeEvent()
	
-- end

return CarnivalRewardTipNode