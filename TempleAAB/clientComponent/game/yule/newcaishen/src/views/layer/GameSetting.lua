-- local module_pre = "game.yule.bonanza.src"
-- local HelpLayer = appdf.req(module_pre .. ".views.layer.HelpLayer")
-- local GameLogic = appdf.req(module_pre .. ".models.GameLogic")

-- 设置界面
local GameSetting = class("GameSetting", function(args)
	local GameSetting =  display.newLayer()
    return GameSetting
end)

function GameSetting:ctor(_gameView)
    tlog('GameSetting:ctor')
    self._gameView = _gameView
    self._scene = self._gameView._scene

    self.csbNode = g_ExternalFun.loadCSB("UI/Node_Setting.csb", self, false)
    self.csbNode:setPosition(display.cx-860,display.height-80)
    g_ExternalFun.loadChildrenHandler(self,self.csbNode)

    self.listener = cc.EventListenerTouchOneByOne:create()
    self.listener:registerScriptHandler(function(touch, event)
        --self:onClickClose()
        --self:reqEggBreak()
        --self:onClickBtnMenu()
        if self.mm_spExpand:isVisible() then
            self.mm_spExpand:setVisible(false)
        end
        return true
    end,cc.Handler.EVENT_TOUCH_BEGAN )
    local eventDispatcher = self:getEventDispatcher()
    eventDispatcher:addEventListenerWithSceneGraphPriority(self.listener, self)
    self.listener:setSwallowTouches(false)

    self.mm_spExpand:setVisible(false)
    self.mm_btnMenu:onClicked(handler(self,self.onClickBtnMenu),true)
    self.mm_btnRule:onClicked(handler(self,self.onClickBtnRule),true)
    self.mm_btnSound:onClicked(handler(self,self.onClickBtnSound),true)
    self.mm_btnMusic:onClicked(handler(self,self.onClickBtnMusic),true)
    self.mm_btnBack:onClicked(handler(self,self.onClickBtnBack),true)

    self:flushSoundResShow()
    self:flushMusicResShow()
end

function GameSetting:onClickBtnMenu()
    if self.mm_spExpand:isVisible() then
        self.mm_spExpand:setVisible(false)
    else
        self.mm_spExpand:setVisible(true)
    end
end

function GameSetting:onClickBtnRule()
    self.mm_spExpand:setVisible(false)
    self._gameView:createHelp()
end

function GameSetting:flushSoundResShow()
    local bSound = GlobalUserItem.bSoundAble
    bSound = bSound and 1 or 0
    local soundBg = {[0]="game_common_effect_off.png","game_common_effect_on.png"}
    self.mm_btnSound:loadTextures(soundBg[bSound],soundBg[bSound],"",ccui.TextureResType.plistType)
end

function GameSetting:onClickBtnSound()
    GlobalUserItem.setSoundAble(not GlobalUserItem.bSoundAble)
    self:flushSoundResShow()
end

function GameSetting:flushMusicResShow()
    local bVoice = GlobalUserItem.bVoiceAble
    bVoice = bVoice and 1 or 0
    local musicBg = {[0]="game_common_music_off.png","game_common_music_on.png"}
    self.mm_btnMusic:loadTextures(musicBg[bVoice],musicBg[bVoice],"",ccui.TextureResType.plistType)
end

function GameSetting:onClickBtnMusic()
    GlobalUserItem.setVoiceAble(not GlobalUserItem.bVoiceAble)
    self:flushMusicResShow()

    self._gameView:onPlayMusic()
end

function GameSetting:onClickBtnBack()
    self.mm_spExpand:setVisible(false)
    self._gameView:onExitClick()
end

return GameSetting