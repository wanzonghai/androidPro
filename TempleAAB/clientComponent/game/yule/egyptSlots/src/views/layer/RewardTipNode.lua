-- 大奖提示界面
--local DialogBase = appdf.req("game.yule.bonanza.src.views.layer.DialogBase")
local RewardTipNode = class("RewardTipNode", cc.Layer)

local GameLogic = appdf.req("game.yule.egyptSlots.src.models.GameLogic")

--[[
	_data =
	{
		_rateNum = 倍率
		_nums = 金额数
	}
]]
function RewardTipNode:ctor(_data)
    tlog('RewardTipNode:ctor')
    self.sound_handle = nil
    self.m_touchRet = true
    self._scollGold = true
    self.m_callBack = _data._callBack

    self:createColorLayer(_pos, _opacity)
    --注册事件
	local function onLayoutEvent( event )
		if event == "exit" then
			self:onExit()
        elseif event == "enterTransitionFinish" then
        	self:onEnterTransitionFinish()
        end
	end
	self:registerScriptHandler(onLayoutEvent)
    
	local csbNode = ccui.Widget:create()
    self:addChild(csbNode)
    csbNode:setScale(1.2)

    self.spineNode = ccui.Widget:create()
    csbNode:addChild(self.spineNode)
    local win_num = ccui.TextBMFont:create()
    win_num:setFntFile("fonts/jnh_bigwin_num.fnt")
    win_num:hide()
    csbNode:addChild(win_num)

    win_num:setPositionY(-20)
    win_num:setScale(1.2)

    local totalTimes = 1.5+1.5 --比start动画多一秒
    local runTimes = 50 --数字跑动次数

    self:createAnimate(_data._rateNum)

    local delay = cc.DelayTime:create(0.3)
    local call = cc.CallFunc:create(function (t, p)
		win_num:setVisible(true)
		win_num._lastNum = 0
		win_num._curNum = p.num
		self:updateGoldShow(win_num, p.num / p.runTimes)
	end, {num = _data._nums, runTimes = runTimes})
    local delay1 = cc.DelayTime:create(totalTimes)
    local call1 = cc.CallFunc:create(function (t, p)
    	-- if self.m_callBack then
    	-- 	self.m_callBack()
    	-- end
    	-- self:removeFromParent()
    end)
    csbNode:runAction(cc.Sequence:create(delay, call, delay1, call1))
end

function RewardTipNode:createAnimate(_rateNum)
    --粒子
    local particleFile = "spine/particle/za_lb_jbfzmpdl"
	local particleAniName = "a1"--string.format("%s_start", aniNamePrefix)

    local soundTxt = "Level0.mp3"
    local sound = "YOUWIN.mp3"
    
    local aniNamePrefix = "a1"
    local spineFile = "spine/sb_lbjs_YOUWIN/sb_lbjs_MEGAWIN"
    if _rateNum >= GameLogic.Reward_Scope.superbig then
        spineFile = "spine/sb_lbjs_SUPERWIN/sb_lbjs_MEGAWIN"
    	aniNamePrefix = "a1"
        particleAniName = "a3"
        soundTxt = "Level3.mp3"
        sound = "SUPERWIN.mp3"
    elseif _rateNum >= GameLogic.Reward_Scope.big then
        spineFile = "spine/sb_lbjs_MEGAWIN/sb_lbjs_MEGAWIN"
    	aniNamePrefix = "a1"
        particleAniName = "a2"
        soundTxt = "Level2.mp3"
        sound = "MEGAWIN.mp3"
    elseif _rateNum >= GameLogic.Reward_Scope.middle then
        spineFile = "spine/sb_lbjs_BIGWIN/sb_lbjs_BIGWIN"
    	aniNamePrefix = "a1"
        particleAniName = "a1"
        soundTxt = "Level1.mp3"
        sound = "BIGWIN.mp3"
    end

    if _rateNum >= GameLogic.Reward_Scope.middle then
        local animation = self:createAnimateShow(self.spineNode, particleFile, particleAniName, true, 0, 0)
    end

    if self.animation ~= nil then
        self.animation:removeFromParent(true)
        self.animation = nil
    end
    local aniName = "a1"
    self.animation = self:createAnimateShow(self.spineNode, spineFile, aniName, false, 0, 0)
    self.animation:registerSpineEventHandler( function( event )
        tlog("RewardTipNode animation is", event.animation)
        if event.animation == aniName then
            self.animation:setAnimation( 0, "a2", true)
        end
    end, sp.EventType.ANIMATION_COMPLETE)

    if self.sound_handle then
        g_ExternalFun.stopEffect(self.sound_handle)
        self.sound_handle = nil
    end
    self.sound_handle = g_ExternalFun.playSoundEffect(sound)
    

end

function RewardTipNode:createColorLayer(_pos, _opacity)
	self:removeChildByName("ColorLayer")
	_pos = _pos or cc.p(-display.width * 0.5, -display.height * 0.5)
	_opacity = _opacity or 125

	local layer = display.newLayer(cc.c4b(0, 0, 0, _opacity))
	layer:setContentSize(display.size)
	layer:setPosition(_pos)
	layer:addTo(self)
	layer:setName("ColorLayer")
end


function RewardTipNode:onEnterTransitionFinish()
	self:registerTouch()
end

function RewardTipNode:registerTouch()
	local function onTouchBegan( touch, event )
		return self.m_touchRet
	end

	local function onTouchEnded( touch, event )
		tlog('function onTouchEnded ', self.m_spBg)
		local pos = touch:getLocation()
        if not self._scollGold then
            if self.m_spBg then
                pos = self.m_spBg:convertToNodeSpace(pos)
                local rec = cc.rect(0, 0, self.m_spBg:getContentSize().width, self.m_spBg:getContentSize().height)
                if not cc.rectContainsPoint(rec, pos) then
                    self:removeNodeEvent()
                end
            else
                self:removeNodeEvent()
            end
        end
	end

	local listener = cc.EventListenerTouchOneByOne:create()
	listener:setSwallowTouches(true)
	self.listener = listener
    listener:registerScriptHandler(onTouchBegan,cc.Handler.EVENT_TOUCH_BEGAN )
    listener:registerScriptHandler(onTouchEnded,cc.Handler.EVENT_TOUCH_ENDED )
    self:getEventDispatcher():addEventListenerWithSceneGraphPriority(listener, self)
end

function RewardTipNode:removeNodeEvent()
	tlog('DialogBase:removeNodeEvent')
	-- if self.m_callBack then
	-- 	self.m_callBack()
	-- end
    self:removeFromParent()
end

function RewardTipNode:updateGoldShow(_nodeText, _gapNums)
    self._scollGold = true
    tlog("RewardTipNode:updateGoldShow")
    _nodeText:stopAllActions()
    local lastNum = _nodeText._lastNum
    local curNum = _nodeText._curNum
    -- _nodeText:setString(lastNum)
    self:formatNumShow(_nodeText, lastNum)
    local loopNums = 30 -- math.ceil(4.8 / 0.1) --每0.05秒更新一次
    local gapNums = _gapNums and _gapNums or ((curNum - lastNum) / loopNums)
    self:addGoldNumsShowInterval(_nodeText, lastNum, curNum, gapNums)
end

function RewardTipNode:addGoldNumsShowInterval(_node, _srcNums, _dstNums, _addNums)
    -- tlog('RewardTipNode:addGoldNumsShowInterval')
    local nowNums = math.ceil(_srcNums + _addNums)
    if nowNums >= _dstNums then
        nowNums = _dstNums
        -- _node:setString(nowNums)
        self:formatNumShow(_node, nowNums)
        self._scollGold = false
        return
    end
    -- _node:setString(nowNums)
    self:formatNumShow(_node, nowNums)
    _node:runAction(cc.Sequence:create(cc.DelayTime:create(0.03), cc.CallFunc:create(function (t, p)
        self:addGoldNumsShowInterval(p.node, p.srcNums, p.dstNums, p.addNums)
    end, {node = _node, srcNums = nowNums, dstNums = _dstNums, addNums = _addNums})))
end

function RewardTipNode:formatNumShow(_node, _nums)
	local serverKind = G_GameFrame:getServerKind()
	local formatMoney = g_format:formatNumber(_nums,g_format.fType.standard,serverKind)
	tlog('formatMoney is ', formatMoney)
	_node:setString(formatMoney)
end


function RewardTipNode:createAnimateShow(_parent, _file, _animateName, _loop, _posx, _posy, _scale)
    _scale = _scale or 1.2
    local animateAct = sp.SkeletonAnimation:create(string.format("%s.json", _file), string.format("%s.atlas", _file), 1)
    animateAct:addTo(_parent)
    animateAct:setAnimation(0, _animateName, _loop)
    animateAct:setPosition(_posx, _posy)
    animateAct:setScale(_scale)
    return animateAct
end

function RewardTipNode:onExit()
    --RewardTipNode.super.onExit(self)
    if self.m_callBack then
		self.m_callBack()
	end

    self:getEventDispatcher():removeEventListener(self.listener)
    if self.sound_handle then
        g_ExternalFun.stopEffect(self.sound_handle)
        self.sound_handle = nil
    end
end


return RewardTipNode