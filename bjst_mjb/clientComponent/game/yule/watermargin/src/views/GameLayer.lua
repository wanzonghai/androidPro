local GameModel = appdf.req(appdf.CLIENT_SRC.."gamemodel.GameModel")
local GameLayer = class("GameLayer", GameModel)

--local Game2Layer = class("Game2Layer", GameModel)

local module_pre = "game.yule.watermargin.src";
require("cocos.init")

local cmd = module_pre .. ".models.CMD_Game"

local GameViewLayer = appdf.req(module_pre .. ".views.layer.GameViewLayer")
local g_var = g_ExternalFun.req_var
local GameLogic = appdf.req(module_pre .. ".models.GameLogic")
local QueryDialog = appdf.req(appdf.CLIENT_SRC.."UIManager.QueryDialogNew")
--local GameFrame = appdf.req(module_pre .. ".models.GameFrame")
local EventPost = appdf.req(appdf.CLIENT_SRC.."Tools.EventPost")
local emGameState =
{
    "GAME_STATE_WAITTING",              --等待
    "GAME_STATE_WAITTING_RESPONSE",     --等待服务器响应
    "GAME_STATE_MOVING",                --转动
    "GAME_STATE_RESULT",                --结算
    "GAME_STATE_WAITTING_GAME2",        --等待游戏2
    "GAME_STATE_END"                    --结束
}
local GAME_STATE = g_ExternalFun.declarEnumWithTable(0, emGameState)

local emGame2State = 
{
    "GAME2_STATE_WAITTING",
    "GAME2_STATE_WAVING",
    "GAME2_STATE_WAITTING_CHOICE",
    "GAME2_STATE_OPEN",
    "GAME2_STATE_RESULT"
}
local GAME2_STATE = g_ExternalFun.declarEnumWithTable(0, emGame2State)

function GameLayer:ctor( frameEngine,scene )

    g_ExternalFun.registerNodeEvent(self)

    self.m_bLeaveGame = false

    GameLayer.super.ctor(self,frameEngine,scene)

    GlobalUserItem.bAutoConnect = false
    --selfcreate._gameFrame:QueryUserInfo( self:GetMeUserItem().wTableID,ylAll.INVALID_CHAIR)
    self:addAnimationEvent()  --监听加载完动画的事件
end
--进入后台 
function GameLayer:enterBackground()
    local  data= CCmd_Data:create(1)
    data:pushbyte(0)
    self:SendData(g_var(cmd).SUB_S_USER_ONLINE_STATE, data)
end
--进入前台
function GameLayer:enterForeground()
    local  data= CCmd_Data:create(1)
    data:pushbyte(1)
    self:SendData(g_var(cmd).SUB_S_USER_ONLINE_STATE, data)
end

function GameLayer:getFrame()
    return self._gameFrame
end

--创建场景
function GameLayer:CreateView()
     self._gameView = GameViewLayer[1]:create(self)
     g_ExternalFun.adapterWidescreen(self._gameView)
     self:addChild(self._gameView,0,2001)
     return self._gameView
end

function GameLayer:OnInitGameEngine()
    GameLayer.super.OnInitGameEngine(self)

    self.m_bIsLeave             = false     --是否离开游戏
    self.m_bIsPlayed            = false       --是否玩过游戏
    self.m_cbGameStatus         = 0         --游戏状态

    self.m_cbGameMode           = 0         --游戏模式

    --游戏逻辑操作
    self.m_bIsItemMove          = false     --动画是否滚动的标示
    self.m_lCoins               = 0         --游戏币
    self.m_lYaxian              = GameLogic.YAXIANNUM         --压线
    self.m_lYafen               = 0         --压分
    self.m_lTotalYafen          = 0         --总压分
    self.m_lGetCoins            = 0         --获得金钱

    self.m_bEnterGame3          = false     --是否小玛丽
    self.m_bEnterGame2          = true     --是否比倍
    self.m_bYafenIndex          = 1         --压分索引（数组索引）
    self.m_lBetScore            = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}        --压分存储数组
    self.m_cbItemInfo           = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}          --开奖信息

    --中奖位置
    self.m_ptZhongJiang = {}
    for i=1,GameLogic.ITEM_COUNT do
        self.m_ptZhongJiang[i] = {}
        for j=1,GameLogic.ITEM_X_COUNT do
            self.m_ptZhongJiang[i][j] = {}
            self.m_ptZhongJiang[i][j].x = 0
            self.m_ptZhongJiang[i][j].y = 0
        end
    end

    self.m_UserActionYaxian     = {}           --用户压线的情况

    --self.m_bYafenIndexNow       = 0         --发送服务器时的压分索引
    self.m_bIsAuto                 = false        --控制自动开始按钮
    self.m_bReConnect1             = false
    self.m_bReConnect2             = false
    self.m_bReConnect3             = false

    self.tagActionOneKaiJian = {}
    self.tagActionOneKaiJian.nCurIndex = 0
    self.tagActionOneKaiJian.nMaxIndex = 9
    self.tagActionOneKaiJian.lScore = 0
    self.tagActionOneKaiJian.lQuanPanScore = 0
    self.tagActionOneKaiJian.cbGameMode = 0
    self.tagActionOneKaiJian.bZhongJiang = {}
    for i=1, GameLogic.ITEM_Y_COUNT do
        self.tagActionOneKaiJian.bZhongJiang[i] = {}
        for j=1,GameLogic.ITEM_X_COUNT do
             self.tagActionOneKaiJian.bZhongJiang[i][j] = false
        end
    end

    --游戏2结果
    self.m_pGame2Result = {}
    self.m_pGame2Result.cbOpenSize = {0,0}
    self.m_pGame2Result.lScore = 0
end

function GameLayer:ResetAction( )
     self.tagActionOneKaiJian.nCurIndex = 0
     self.tagActionOneKaiJian.nMaxIndex = 9
     self.tagActionOneKaiJian.lScore = 0
     self.tagActionOneKaiJian.lQuanPanScore = 0
     self.tagActionOneKaiJian.cbGameMode = 0
     self.tagActionOneKaiJian.bZhongJiang = {}
     for i=1, GameLogic.ITEM_Y_COUNT do
         self.tagActionOneKaiJian.bZhongJiang[i] = {}
         for j=1,GameLogic.ITEM_X_COUNT do
             self.tagActionOneKaiJian.bZhongJiang[i][j] = false
         end
     end
end

function GameLayer:resetData()
    --GameLayer.super.resetData(self)

    self.m_cbGameStatus         = 0         --游戏状态

    self.m_cbGameMode           = 0         --游戏模式

    --游戏逻辑操作
    self.m_bIsItemMove          = false     --动画是否滚动的标示
    self.m_lCoins               = 0         --游戏币
    self.m_lYaxian              = GameLogic.YAXIANNUM         --压线
    self.m_lYafen               = self.m_lBetScore[self.m_bYafenIndex]        --压分
    self.m_lTotalYafen          = self.m_lBetScore[self.m_bYafenIndex]*self.m_lYafen*self.m_lYaxian         --总压分
    self.m_lGetCoins            = 0         --获得金钱

    self.m_bEnterGame3          = false     --是否小玛丽
    self.m_bEnterGame2          = false     --是否比倍
    self.m_bYafenIndex          = 1         --压分索引（数组索引）
    self.m_lBetScore            = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}         --压分存储数组
    self.m_cbItemInfo           = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}         --开奖信息
    --self.m_ptZhongJiang         = {{},{},{}}         
    --中奖位置
    self.m_ptZhongJiang = {}
    for i=1,9 do
        self.m_ptZhongJiang[i] = {}
        for j=1,5 do
            self.m_ptZhongJiang[i][j] = {}
            self.m_ptZhongJiang[i][j].x = 0
            self.m_ptZhongJiang[i][j].y = 0
        end
    end

    self.m_bIsAuto                 = false        --控制自动开始按钮
    self.m_bReConnect1             = false
    self.m_bReConnect2             = false
    self.m_bReConnect3             = false
    --游戏2结果
    self.m_pGame2Result = {}
    self.m_pGame2Result.cbOpenSize = {0,0}
    self.m_pGame2Result.lScore = 0
end

-- 重置游戏数据
function GameLayer:OnResetGameEngine()

    local useritem = self:GetMeUserItem()
    if (self.m_bIsAuto == true  and useritem.cbUserStatus == G_NetCmd.US_PLAYING and self.m_cbGameStatus == 101) or (self.m_cbGameStatus == 102 and self.m_bEnterGame2 == false) then--g_var(cmd).SHZ_GAME_SCENE_FREE 
        print("游戏1断线重连")
        self.m_bReConnect1 = true
    elseif self.m_cbGameStatus == 102 and self.m_bEnterGame2 == true then --g_var(cmd).g_var(cmd).SHZ_GAME_SCENE_TWO 
        print("游戏2断线重连")
        self.m_bReConnect2 = true
        local gameview = self._gameView
        if gameview then
            --gameview:setPosition(0,0)
            gameview:setVisible(true)
        end
        if self._game2View then
            self._game2View:removeFromParent()
            self._game2View = nil
        end

        self.m_bIsAuto = false
        self._gameView:setAutoStart(false)
        --祝您好运
        self._gameView.m_textTips:setString("Boa sorte!")
        self:setGameMode(0)
    elseif self.m_cbGameStatus == 103  then--g_var(cmd).g_var(cmd).SHZ_GAME_SCENE_THREE 
        print("游戏3断线重连")
        self.m_bReConnect3 = true
    end

end

function GameLayer:addAnimationEvent()
   --通知监听
  local function eventListener(event)
    cc.Director:getInstance():getEventDispatcher():removeCustomEventListeners(g_var(cmd).Event_LoadingFinish)

    --self._gameView:initMainView()
    print("移除监听事件")
    if self._gameView then
        self._gameView:initMainView()
        self:SendUserReady()
    end
  end

  local listener = cc.EventListenerCustom:create(g_var(cmd).Event_LoadingFinish, eventListener)
  cc.Director:getInstance():getEventDispatcher():addEventListenerWithFixedPriority(listener, 1)
end
--------------------------------------------------------------------------------------
function GameLayer:onExit()
    print("gameLayer onExit()...................................")
    self:KillGameClock()
end

--退出桌子
function GameLayer:onExitTable()
    self:KillGameClock()
   self:onExitRoom()
end

--离开房间
function GameLayer:onExitRoom()
    --self._scene:onKeyBack()  
    if self._gameFrame then 
        self._gameFrame:StandUp(1)
        self._gameFrame:onCloseSocket()
    end
    G_event:NotifyEvent(G_eventDef.UI_REMOVE_GAME_LAYER) 
end

--系统消息
function GameLayer:onSystemMessage( wType,szString )
    if wType == 515 then  --515 当玩家没钱时候
       self.m_querydialog = QueryDialog:create(szString,function()
        
            self:KillGameClock()
            local MeItem = self:GetMeUserItem()
            if MeItem and MeItem.cbUserStatus > G_NetCmd.US_FREE then
                self:showPopWait()
                self:runAction(cc.Sequence:create(
                    cc.CallFunc:create(
                        function () 
                            self._gameFrame:StandUp(1)
                        end
                        ),
                    cc.DelayTime:create(10),
                    cc.CallFunc:create(
                        function ()
                            print("delay leave")
                            self:onExitRoom()
                        end
                        )
                    )
                )
                return
            end
           self:onExitRoom()

        end,nil,1)
        self.m_querydialog:setCanTouchOutside(false)
        self.m_querydialog:addTo(self)
    end
end

-- -------------------------------------------------------------------------------------
-- -------------------------------------------------------------------------------------场景消息

-- -- 场景信息
function GameLayer:onEventGameScene(cbGameStatus,dataBuffer)
    print("场景数据.....:" .. cbGameStatus)
    --self._gameView:removeAction()
    self:KillGameClock()
    --清空10S提示界面
    self:hideTipsExit()
    
    self._gameView.m_cbGameStatus = cbGameStatus;
	if cbGameStatus == g_var(cmd).SHZ_GAME_SCENE_FREE	then                        --空闲状态
        self:onEventGameSceneFree(dataBuffer);
	elseif cbGameStatus == g_var(cmd).SHZ_GAME_SCENE_ONE 	then                      
        self:onEventGameSceneStatus(dataBuffer);
	elseif cbGameStatus == g_var(cmd).SHZ_GAME_SCENE_TWO	then               
        self:onEventGame2SceneStatus(dataBuffer);
    elseif cbGameStatus == g_var(cmd).SHZ_GAME_SCENE_THREE    then                         
        self:onEventGameSceneStatus(dataBuffer);
	end
end

function GameLayer:onEventGameSceneFree(buffer)    --空闲 
    local cmd_table = g_ExternalFun.read_netdata(g_var(cmd).SHZ_CMD_S_StatusFree, buffer)
	print("======dump free scene data======")
	dump(cmd_table)
    --初始化数据
    self.m_bMaxNum = cmd_table.cbBetCount
    self.m_lYafen = cmd_table.lCellScore

    self.m_lCoins = self:GetMeUserItem().lScore  --cmd_table.lUserScore--self:GetMeUserItem().lScore

    self.m_lBetScore = GameLogic:copyTab(cmd_table.lBetScore[1])
    local max_line = self.m_lYaxian
    self.m_bYafenIndex = self:getBetIndex(self.m_lBetScore,max_line)
    if self.m_bYafenIndex > self.m_bMaxNum then
        self.m_bYafenIndex = self.m_bMaxNum
    end
    self.m_lTotalYafen = self.m_lBetScore[self.m_bYafenIndex]*self.m_lYafen*self.m_lYaxian
    --self.m_lTotalYafen = self.m_lBetScore[self.m_bYafenIndex]*self.m_lYafen*self.m_lYaxian
    --压分
    local serverKind = G_GameFrame:getServerKind()
    self._gameView.m_textYafen:setString(g_format:formatNumber(self.m_lBetScore[self.m_bYafenIndex],g_format.fType.abbreviation,serverKind))
    --总压分  Text_allyafen
    local serverKind = G_GameFrame:getServerKind()
    self._gameView.m_textAllyafen:setString(g_format:formatNumber(self.m_lTotalYafen,g_format.fType.abbreviation,serverKind))

end

function GameLayer:onEventGameSceneStatus(buffer)   
    local cmd_table = g_ExternalFun.read_netdata(g_var(cmd).SHZ_CMD_S_StatusFree, buffer)
    print("···游戏1 ====================== >")
    dump(cmd_table)
    self.m_lBetScore = GameLogic:copyTab(cmd_table.lBetScore[1])
end

function GameLayer:onEventGame2SceneStatus(buffer)   
    local cmd_table = g_ExternalFun.read_netdata(g_var(cmd).SHZ_CMD_S_StatusFree, buffer)
    print("···游戏2 ====================== >")
    dump(cmd_table)
    self.m_lBetScore = GameLogic:copyTab(cmd_table.lBetScore[1])
end


-----------------------------------------------------------------------------------
-- 游戏消息
function GameLayer:onEventGameMessage(sub,dataBuffer)
    if sub == g_var(cmd).SUB_S_GAME_START then 
        --print("watermargin 游戏开始")
        self:onGame1Start(dataBuffer)                       --游戏开始
        --清空10S提示界面
        self:hideTipsExit()
    elseif sub == g_var(cmd).SUB_S_GAME_CONCLUDE then 
        --print("watermargin 压线结束")
        self:onSubGame1End(dataBuffer)                      --压线结束
    elseif sub == g_var(cmd).SUB_S_TWO_START then 
        --print("watermargin 比倍开始")
        self:onGame2Start(dataBuffer)                       --比倍开始
    elseif sub == g_var(cmd).SUB_S_TWO_GAME_CONCLUDE then 
        --print("watermargin 比倍结束") 
        --self:onSubSendCard(dataBuffer)
    elseif sub == g_var(cmd).SUB_S_THREE_START then         --小玛丽开始
        --print("watermargin 小玛丽开始")
        self:onGame3Start(dataBuffer)
    elseif sub == g_var(cmd).SUB_S_THREE_KAI_JIANG then     --小玛丽开奖
        --print("watermargin 小玛丽开奖")
        self:onGame3Result(dataBuffer)
    elseif sub == g_var(cmd).SUB_S_THREE_END then 
        --print("watermargin 小玛丽结束")
        --self:onSubGetWinner(dataBuffer)
		--结帐
	elseif sub == g_var(cmd).SUB_S_USER_DATA then
		print("SUB_S_USER_DATA ==  收到用户积分信息")
		self:onGetUserData(dataBuffer)
    else
        print("unknow gamemessage sub is "..sub)
    end
end


function GameLayer:onGetUserData(dataBuffer)
	-- 从服务器收到当前玩家分值
	local cmd_table = g_ExternalFun.read_netdata(g_var(cmd).CMD_S_User_data, dataBuffer)
	dump(cmd_table)
	--self.m_lCoins = cmd_table.userScore;
	self.m_lRealCoins = cmd_table.userScore;
	self:GetMeUserItem().lScore = cmd_table.userScore;
end

--游戏开始
function GameLayer:onGame1Start(dataBuffer) --游戏开始
    print("GameLayer -------游戏开始------")
    local cmd_table = g_ExternalFun.read_netdata(g_var(cmd).SHZ_CMD_S_GameStart, dataBuffer)
    --dump(cmd_table)
    self.m_lGetCoins = cmd_table.lScore --中奖的分数
    --进入小玛丽
    if g_var(cmd).GM_TWO == cmd_table.cbGameMode then
        self.m_bEnterGame3 = true
    else
        self.m_bEnterGame3 = false
    end
    self._dwHashID = cmd_table.dwHashID or ""
    self.m_cbItemInfo = {{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}} 
    self.m_cbItemInfo = GameLogic:copyTab(cmd_table.cbItemInfo)
    dump(cmd_table.cbItemInfo)
    --检验是否中奖
    GameLogic:GetAllZhongJiangInfo(self.m_cbItemInfo,self.m_ptZhongJiang)

    --改变状态
    self.m_cbGameStatus = g_var(cmd).SHZ_GAME_SCENE_ONE

    if self.m_lGetCoins > 0 then
        --清空数组

        self.m_UserActionYaxian = {}
        --获取中奖信息，压线和中奖结果
        for i=1,GameLogic.ITEM_COUNT do
            if GameLogic:getZhongJiangInfo(i,self.m_cbItemInfo,self.m_ptZhongJiang) ~= 0 then
                local pActionOneYaXian = {}
                pActionOneYaXian.nZhongJiangXian = i
                pActionOneYaXian.lXianScore = GameLogic:GetZhongJiangTime(i,self.m_cbItemInfo)*self.m_lYafen*self.m_lBetScore[self.m_bYafenIndex]
                pActionOneYaXian.lScore = self.m_lGetCoins
                pActionOneYaXian.ptXian = self.m_ptZhongJiang[pActionOneYaXian.nZhongJiangXian]
                self.m_UserActionYaxian[#self.m_UserActionYaxian+1] = pActionOneYaXian
            end
        end
        self:ResetAction()
        self.tagActionOneKaiJian.nCurIndex = 0
        self.tagActionOneKaiJian.nMaxIndex = 9
        self.tagActionOneKaiJian.cbGameMode = cmd_table.cbGameMode
        self.tagActionOneKaiJian.lQuanPanScore = cmd_table.lScore
        self.tagActionOneKaiJian.lScore = cmd_table.lScore
        if GameLogic:GetQuanPanJiangTime(self.m_cbItemInfo) ~= 0 then
            for i=1,GameLogic.ITEM_Y_COUNT do
                for j=1,GameLogic.ITEM_X_COUNT do
                    self.tagActionOneKaiJian.bZhongJiang[i][j] = true
                end
            end

        else
            for i=1,GameLogic.ITEM_COUNT do
                for j=1,GameLogic.ITEM_X_COUNT do
                    if self.m_ptZhongJiang[i][j].x ~= 0xff then
                        self.tagActionOneKaiJian.bZhongJiang[self.m_ptZhongJiang[i][j].x][self.m_ptZhongJiang[i][j].y] = true
                    end
                end
            end
        end
    end
    self.m_bIsItemMove = true
    --开始游戏

    self._gameView:game1Begin()
    --切换旗帜动作
    self._gameView:game1ActionBanner(false)

    if self.m_bIsAuto == true then
        self._gameView:updateStartButtonState(true)
    else
        self._gameView:updateStartButtonState(false)
    end
end

function GameLayer:onSubGame1End( dataBuffer )
    print("GameLayer -------游戏1结束------")
    if self.m_lTotalYafen > self.m_lCoins + self.m_lGetCoins then
        --提示游戏币不足
        showToast("Aviso: Moedas de jogo insuficientes")
        self.m_bIsAuto = false
        self._gameView:setAutoStart(false)
    else
        if self.m_bIsAuto == true then

            if  (self:getGameMode() == GAME_STATE.GAME_STATE_END) then--and (self:getGameMode() == GAME_STATE.GAME_STATE_WAITTING_GAME2  or (self:getGameMode() == GAME_STATE.GAME_STATE_WAITTING) or (self:getGameMode() == GAME_STATE.GAME_STATE_END))  then
                self._gameView:stopAllActions()
                local useritem = self:GetMeUserItem()

                if useritem.cbUserStatus ~= G_NetCmd.US_READY then --self.m_bIsPlayed == true and 

                    self:SendUserReady()

                end
                --发送准备消息
                self:sendReadyMsg()

                self.m_cbGameStatus = g_var(cmd).SHZ_GAME_SCENE_FREE
                self:setGameMode(1)
            end
        end
    end
end

function GameLayer:setGameMode( state )
    if state == 0 then
        self.m_cbGameMode = GAME_STATE.GAME_STATE_WAITTING  --等待
    elseif state == 1 then
        self.m_cbGameMode = GAME_STATE.GAME_STATE_WAITTING_RESPONSE --等待服务器响应
    elseif state == 2 then
        self.m_cbGameMode = GAME_STATE.GAME_STATE_MOVING --转动
    elseif state == 3 then
        self.m_cbGameMode = GAME_STATE.GAME_STATE_RESULT --结算
    elseif state == 4 then
        self.m_cbGameMode = GAME_STATE.GAME_STATE_WAITTING_GAME2 --等待游戏2
    elseif state == 5 then
        self.m_cbGameMode = GAME_STATE.GAME_STATE_END  --结束
    else
        print("未知状态")
    end
    -- self.m_cbGameMode = GAME_STATE[state]
end
--游戏2
function GameLayer:setGame2Mode( state )
    if state == 0 then
        self.m_cbGameMode = GAME2_STATE.GAME2_STATE_WAITTING  --等待
    elseif state == 1 then
        self.m_cbGameMode = GAME2_STATE.GAME2_STATE_WAVING --摇奖
    elseif state == 2 then
        self.m_cbGameMode = GAME2_STATE.GAME2_STATE_WAITTING_CHOICE --等待下注
    elseif state == 3 then
        self.m_cbGameMode = GAME2_STATE.GAME2_STATE_OPEN --结算
    elseif state == 4 then
        self.m_cbGameMode = GAME2_STATE.GAME2_STATE_RESULT --等待游戏2
    else
        print("未知状态")
    end
    -- self.m_cbGameMode = GAME_STATE[state]
end

--获取游戏状态
function GameLayer:getGameMode()
    if self.m_cbGameMode then
        return self.m_cbGameMode
    end
end

--游戏开始
function GameLayer:onGameStart()
    local useritem = self:GetMeUserItem()
    self._gameView:onHideTopMenu()
    --自动开始
    if self.m_bIsAuto == true then
        if self:getGameMode() == GAME_STATE.GAME_STATE_MOVING then
            self._gameView:game1End()
            --return
        --elseif self.m_bIsItemMove == false and (self:getGameMode() == GAME_STATE.GAME_STATE_WAITTING_GAME2  or (self:getGameMode() == GAME_STATE.GAME_STATE_WAITTING) or (self:getGameMode() == GAME_STATE.GAME_STATE_END)) then
        elseif self:getGameMode() == GAME_STATE.GAME_STATE_WAITTING_GAME2  then
            print("游戏开始")
            self.m_bIsPlayed = true
            self._gameView:stopAllActions()
            --游戏2按钮不可用
            self._gameView:enableGame2Btn(false)
            --发送消息
            self:sendGiveUpMsg()
            --祝您好运
            self._gameView.m_textTips:setString("Boa sorte!")

             if self.m_lTotalYafen > self.m_lCoins + self.m_lGetCoins then
                --提示游戏币不足
                showToast("Aviso: Moedas de jogo insuficientes")
                return
            end
            self:SendUserReady()
            --发送准备消息
            self:sendReadyMsg()
            --减去押注
            --self._gameView.m_textScore:setString(self:GetMeUserItem().lScore-self.m_lTotalYafen)
            self.m_cbGameStatus = g_var(cmd).SHZ_GAME_SCENE_FREE
            self:setGameMode(1)
            --return 
        else
            --return
        end
    end
    --开始
    if self:getGameMode() == GAME_STATE.GAME_STATE_MOVING then
        print("jxlw==================game1End")
        self._gameView:game1End()
    --elseif  self.m_bIsItemMove == false and  (self:getGameMode() == GAME_STATE.GAME_STATE_WAITTING_GAME2) or (self:getGameMode() == GAME_STATE.GAME_STATE_WAITTING) or (self:getGameMode() == GAME_STATE.GAME_STATE_END) then
    elseif  (self:getGameMode() == GAME_STATE.GAME_STATE_WAITTING) or (self:getGameMode() == GAME_STATE.GAME_STATE_END) then
        --发送放弃到比大小的消息
        if self.m_lGetCoins > 0 then --or (self:getGameMode() == GAME_STATE.GAME_STATE_END) then
            self:sendGiveUpMsg()
        end

        if self.m_lTotalYafen > self.m_lCoins + self.m_lGetCoins then
            --提示游戏币不足
            showToast("Aviso: Moedas de jogo insuficientes")
            return
        end
        self.m_bIsPlayed = true
        self._gameView:stopAllActions()
        --游戏2按钮不可用
        self._gameView:enableGame2Btn(false)

        self:SendUserReady()
        --发送准备消息
        self:sendReadyMsg()
        self.m_cbGameStatus = g_var(cmd).SHZ_GAME_SCENE_FREE
        self:setGameMode(1)
    end
end

--自动游戏
function GameLayer:onAutoStart( )
    self._gameView:onHideTopMenu()

    --判断金钱是否够自动开始
    if self.m_bIsAuto == true then
        self.m_bIsAuto = false
        self._gameView:setAutoStart(false)
    else
        self.m_bIsAuto = true
        if self.m_lTotalYafen > self.m_lCoins + self.m_lGetCoins then
            --提示游戏币不足
            showToast("Aviso: Moedas de jogo insuficientes")
            self.m_bIsAuto = false
            self._gameView:setAutoStart(false)
            return
        end
        self._gameView:setAutoStart(true) 

        if  self.m_bIsItemMove == false  then--and (self:getGameMode() == GAME_STATE.GAME_STATE_WAITTING_GAME2  or (self:getGameMode() == GAME_STATE.GAME_STATE_WAITTING) or (self:getGameMode() == GAME_STATE.GAME_STATE_END))  then
            self._gameView:stopAllActions()

            if self.m_lGetCoins > 0 then 
                self:sendGiveUpMsg()
            end
            self.m_bIsPlayed = true
            self._gameView:enableGame2Btn(false)
            local useritem = self:GetMeUserItem()
            if useritem.cbUserStatus ~= G_NetCmd.US_READY then
                self:SendUserReady()
            end
            --发送准备消息
            self:sendReadyMsg()
            self.m_cbGameStatus = g_var(cmd).SHZ_GAME_SCENE_FREE
            self:setGameMode(1) --"GAME_STATE_WAITTING_RESPONSE",     --等待服务器响应
        end
    end
end

--最大加注
function GameLayer:onAddMaxScore()

    self._gameView:onHideTopMenu()

    self.m_bYafenIndex = self.m_bMaxNum 
    self.m_lTotalYafen = self.m_lBetScore[self.m_bYafenIndex]*self.m_lYafen*self.m_lYaxian
    --压分
    local serverKind = G_GameFrame:getServerKind()
    self._gameView.m_textYafen:setString(g_format:formatNumber(self.m_lBetScore[self.m_bYafenIndex],g_format.fType.abbreviation,serverKind))
    --总压分
    local serverKind = G_GameFrame:getServerKind()
    self._gameView.m_textAllyafen:setString(g_format:formatNumber(self.m_lTotalYafen,g_format.fType.abbreviation,serverKind))

end

--最小加注
function GameLayer:onAddMinScore( )
    self._gameView:onHideTopMenu()
    self.m_bYafenIndex = 1
    self.m_lTotalYafen = self.m_lBetScore[self.m_bYafenIndex]*self.m_lYafen*self.m_lYaxian
    --压分
    local serverKind = G_GameFrame:getServerKind()
    self._gameView.m_textYafen:setString(g_format:formatNumber(self.m_lBetScore[self.m_bYafenIndex],g_format.fType.abbreviation,serverKind))
    --总压分
    local serverKind = G_GameFrame:getServerKind()
    self._gameView.m_textAllyafen:setString(g_format:formatNumber(self.m_lTotalYafen,g_format.fType.abbreviation,serverKind))

end

--加注
function GameLayer:onAddScore()
    self._gameView:onHideTopMenu()
    if self.m_bYafenIndex < self.m_bMaxNum then
        self.m_bYafenIndex = self.m_bYafenIndex + 1
    else
        self.m_bYafenIndex = self.m_bMaxNum
    end
    self.m_lTotalYafen = self.m_lBetScore[self.m_bYafenIndex]*self.m_lYafen*self.m_lYaxian

    --压分
    local serverKind = G_GameFrame:getServerKind()
    self._gameView.m_textYafen:setString(g_format:formatNumber(self.m_lBetScore[self.m_bYafenIndex],g_format.fType.abbreviation,serverKind))
    --总压分
    local serverKind = G_GameFrame:getServerKind()
    self._gameView.m_textAllyafen:setString(g_format:formatNumber(self.m_lTotalYafen,g_format.fType.abbreviation,serverKind))
end

--减注
function GameLayer:onSubScore()
    self._gameView:onHideTopMenu()
    if self.m_bYafenIndex > 1  then
        self.m_bYafenIndex = self.m_bYafenIndex - 1
    else
        self.m_bYafenIndex = 1
    end
    self.m_lTotalYafen = self.m_lBetScore[self.m_bYafenIndex]*self.m_lYafen*self.m_lYaxian

    --压分
    local serverKind = G_GameFrame:getServerKind()
    self._gameView.m_textYafen:setString(g_format:formatNumber(self.m_lBetScore[self.m_bYafenIndex],g_format.fType.abbreviation,serverKind))
    --总压分
    local serverKind = G_GameFrame:getServerKind()
    self._gameView.m_textAllyafen:setString(g_format:formatNumber(self.m_lTotalYafen,g_format.fType.abbreviation,serverKind))
end
--接管父关准备消息
function GameLayer:SendUserReady()
    print("user ready")
end
--发送准备消息
function GameLayer:sendReadyMsg()
    print("发送准备消息成功")
    local  dataBuffer= CCmd_Data:create(1)
    dataBuffer:pushbyte(self.m_bYafenIndex-1)
    self:SendData(g_var(cmd).SHZ_SUB_C_ONE_START, dataBuffer)
    EventPost:addCommond(EventPost.eventType.SPIN,"slot每次spin",1,nil,{gameId = cmd.KIND_ID,
        roomId = GlobalUserItem.roomMark,betPrice = self.m_lTotalYafen
    })  
    if self.m_lGetCoins and self.m_lGetCoins > 0 then
        g_ExternalFun.playSoundEffect("defen.mp3")
        self.m_lCoins = self.m_lCoins + self.m_lGetCoins
        self.m_lGetCoins = 0
        local serverKind = G_GameFrame:getServerKind()
        self._gameView.m_textScore:setString(g_format:formatNumber(self.m_lCoins,g_format.fType.standard,serverKind))

        self:changeUserScore(-self.m_lTotalYafen)
        local serverKind = G_GameFrame:getServerKind()
        self._gameView.m_textGetScore:setString(g_format:formatNumber(self.m_lGetCoins,g_format.fType.abbreviation,serverKind))
    else
        local serverKind = G_GameFrame:getServerKind()
        self._gameView.m_textScore:setString(g_format:formatNumber(self.m_lCoins,g_format.fType.standard,serverKind))
        self:changeUserScore(-self.m_lTotalYafen)
        local serverKind = G_GameFrame:getServerKind()
        self._gameView.m_textGetScore:setString(g_format:formatNumber(self.m_lGetCoins,g_format.fType.abbreviation,serverKind))
    end

end
--发送放弃比倍消息
function GameLayer:sendGiveUpMsg( )
    print("放弃比倍消息")
    --发送数据
    local  dataBuffer= CCmd_Data:create(1)
    --dataBuffer:pushscore(0)
    self:SendData(g_var(cmd).SHZ_SUB_C_TWO_GIVEUP, dataBuffer)
end

--发送放弃游戏一消息
function GameLayer:sendEndGame1Msg()
    print("发送结束游戏1消息")
    --发送数据
    local  dataBuffer= CCmd_Data:create(1)
    --dataBuffer:pushscore(0)
    self:SendData(g_var(cmd).SHZ_SUB_C_ONE_END, dataBuffer)
end

--进入摇骰子
function GameLayer:onEnterGame2()
    if self.m_cbGameStatus == g_var(cmd).SHZ_GAME_SCENE_TWO then
        self._gameView:stopAllActions()

        self._gameView:enableGame2Btn(false)

        self._game2View = GameViewLayer[2]:create(self)
        g_ExternalFun.adapterWidescreen(self._game2View)
        self:addChild(self._game2View)

        --self._gameView:setPosition(-1334,0)
    end
end

--进入小玛丽
function GameLayer:onEnterGame3( )
    if self.m_cbGameStatus == g_var(cmd).SHZ_GAME_SCENE_THREE then
		print("GameLayer:onEnterGame3")
        --self.m_lCoins = self:GetMeUserItem().lScore
        self._gameView:stopAllActions()

        self._gameView:enableGame2Btn(false)

        self._game3View = GameViewLayer[3]:create(self)
        g_ExternalFun.adapterWidescreen(self._game3View)
        self:addChild(self._game3View)

        --self._gameView:setPosition(-1334,0)
    end
end

--刷新服务器分数
function GameLayer:refreshScore()
    local useritem = self:GetMeUserItem()
    local serverKind = G_GameFrame:getServerKind()
    self._gameView.m_textScore:setString(g_format:formatNumber(useritem.lScore,g_format.fType.standard,serverKind))
    self.m_lCoins = self:GetMeUserItem().lScore
end

function GameLayer:changeUserScore( changeScore )
    self.m_lCoins = self.m_lCoins + changeScore
    local serverKind = G_GameFrame:getServerKind()
    self._gameView.m_textScore:setString(g_format:formatNumber(self.m_lCoins,g_format.fType.standard,serverKind))
end

------------------------------------------------------------
--                      游戏2 摇骰子
------------------------------------------------------------
--游戏2开奖
function GameLayer:onGame2Start(dataBuffer)
    local cmd_table = g_ExternalFun.read_netdata(g_var(cmd).SHZ_CMD_S_GameTwoStart, dataBuffer)
	dump(cmd_table)
	print("当前金币值" .. self.m_lCoins)
	print("累积得分"..tostring(self.m_lAllGetCoin2))
    --self.m_pGame2Result = {}
    self.m_pGame2Result.cbOpenSize[1] = cmd_table.cbOpenSize[1][1]
    self.m_pGame2Result.cbOpenSize[2] = cmd_table.cbOpenSize[1][2]
    self.m_pGame2Result.lScore = cmd_table.lScore
    self.m_lGetCoins2 = cmd_table.lScore
    self.m_lAllGetCoin2 =  cmd_table.lScore -- self.m_lAllGetCoin2 + self.m_lGetCoins2
	
    self._game2View:initOpenDiceCup()
end

--初始化游戏2数据
function GameLayer:game2DataInit()
    self:setGame2Mode(0)
    self.m_lBaseYafen = self.m_lGetCoins
    self.m_lGetCoins2 = 0
    self.m_lAllGetCoin2 = 0
    self.m_bEnterGame2 = true
end

--半比
function GameLayer:onHalfIn(  )
    if self.m_cbGameMode ~= GAME2_STATE.GAME2_STATE_WAITTING then
        return
    end
    --发送消息
    self:sendReadyMsg2(0)
    self._game2View:initDiceView()
    --压分
    self.m_lYafen2 = self.m_lBaseYafen/2
    --设置压分label的数值
    local serverKind = G_GameFrame:getServerKind()
    self._game2View.m_textYafen:setString(g_format:formatNumber(self.m_lYafen2,g_format.fType.standard,serverKind))
    --设置用户分数
    self.m_lCoins = self.m_lCoins + self.m_lYafen2
    local serverKind = G_GameFrame:getServerKind()
    self._game2View.m_textScore:setString(g_format:formatNumber(self.m_lCoins,g_format.fType.standard,serverKind))
    --不能点击按钮
    self._game2View:enableButton(false)
end

--全比
function GameLayer:onAllIn( )
    if self.m_cbGameMode ~= GAME2_STATE.GAME2_STATE_WAITTING then
        return
    end
    --发送消息
    self:sendReadyMsg2(1)
    self._game2View:initDiceView()
    --压分
    self.m_lYafen2 = self.m_lBaseYafen
    --设置压分label的数值
    local serverKind = G_GameFrame:getServerKind()
    self._game2View.m_textYafen:setString(g_format:formatNumber(self.m_lYafen2,g_format.fType.standard,serverKind))
    --不能点击按钮
    self._game2View:enableButton(false)
end

--倍比
function GameLayer:onDoubleIn( )
    if self.m_cbGameMode ~= GAME2_STATE.GAME2_STATE_WAITTING then
        return
    end
    if self.m_lBaseYafen > self.m_lCoins then
        --提醒：游戏币不足，请选择其他倍率
        showToast("Aviso: sem moedas de jogo suficientes, escolha outro multiplicador")
    else
        --发送消息
        self:sendReadyMsg2(2)
        self._game2View:initDiceView()
        --压分
        self.m_lYafen2 = self.m_lBaseYafen*2
        --设置压分label的数值
        local serverKind = G_GameFrame:getServerKind()
        self._game2View.m_textYafen:setString(g_format:formatNumber(self.m_lYafen2,g_format.fType.standard,serverKind))
        --设置用户分数
        self.m_lCoins = self.m_lCoins - self.m_lBaseYafen
        local serverKind = G_GameFrame:getServerKind()
        self._game2View.m_textScore:setString(g_format:formatNumber(self.m_lCoins,g_format.fType.standard,serverKind))
        --不能点击按钮
        self._game2View:enableButton(false)
    end
end

--游戏2发送准备模式消息
function GameLayer:sendReadyMsg2( openMode )
    --发送数据 
    local  dataBuffer = CCmd_Data:create(1)
    dataBuffer:pushbyte(openMode)
    self:SendData(g_var(cmd).SHZ_SUB_C_TWO_MODE, dataBuffer)
    --print("游戏2准备消息")
end

--押注
function GameLayer:onYaZhu( cbtype )
    --不能再点击
	print("onYaZhu:当前金币:" .. self.m_lCoins);
    self._game2View:enableDickButton(false)
    local useritem = self:GetMeUserItem()
    if self:getGameMode() ~= GAME2_STATE.GAME2_STATE_WAITTING_CHOICE then
        return
    end
    self:setGame2Mode(3) --GAME2_STATE_OPEN
    --放置元宝
    self._game2View:setYuanBaoPostion(cbtype)  --1 是小 2是和 3 是大
    --发送开奖消息
    self:sendKaiJiangMsg(cbtype-1)
end

--游戏2发送准备模式消息
function GameLayer:sendKaiJiangMsg( openArea )
    print("发送开奖消息")
    --发送数据 
    local  dataBuffer = CCmd_Data:create(1)
    dataBuffer:pushbyte(openArea)
    self:SendData(g_var(cmd).SHZ_SUB_C_TWO_START, dataBuffer)
end
--取分
function GameLayer:onExitGame2()
    if self:getGameMode() ~= GAME2_STATE.GAME2_STATE_RESULT then
        return
    end
    self:sendGiveUpMsg()
	print("游戏2结帐:"..self.m_lCoins .. "," .. self.m_lAllGetCoin2);
    self.m_lCoins = self.m_lCoins + self.m_lAllGetCoin2
    self.m_lGetCoins2 = 0
    local serverKind = G_GameFrame:getServerKind()
    self._game2View.m_textScore:setString(g_format:formatNumber(self.m_lCoins,g_format.fType.standard,serverKind))
    local serverKind = G_GameFrame:getServerKind()
    self._gameView.m_textScore:setString(g_format:formatNumber(self.m_lCoins,g_format.fType.standard,serverKind))
    self._game2View:backOneGame()

    -- if self.m_bIsAuto == true then
    --     self:onGameStart()
    --     self:game1ActionBanner(false) --切换旗帜动作
    -- end
end

--继续
function GameLayer:onGoon()
	print("游戏2结帐:onGoon 当前金币"..self.m_lCoins);
    if self:getGameMode() ~= GAME2_STATE.GAME2_STATE_RESULT then
        return
    end
    self._game2View:initDiceView()

    --得分
    -- self.m_lCoins = self.m_lCoins - self.m_lYafen2
    --self._game2View.m_textScore:setString(self.m_lCoins)
end
----------------------------------------------------------------
--                      游戏3 小玛丽
----------------------------------------------------------------

function GameLayer:game3DataInit(  )
    --self.m_lCoins = self:GetMeUserItem().lScore
    self.m_lYafen3 = self.m_lTotalYafen
    self.m_lGetCoins3 = 0
    self.m_pGame3Info = {}
    self.m_pGame3Result = {}
    --self.m_lRunTime = 0
end

function GameLayer:onGame3Start( dataBuffer )
    print("小玛丽开始")
    local cmd_table = g_ExternalFun.read_netdata(g_var(cmd).SHZ_CMD_S_GameThreeStart, dataBuffer)
    dump(cmd_table)
    local pGame3Info = GameLogic:copyTab(cmd_table)

    self.m_pGame3Info[#self.m_pGame3Info+1] = pGame3Info
    self.m_lGetCoins3 =  self.m_lGetCoins3 + pGame3Info.lScore

    --如果元素个数等于小玛丽次数，则开始
    if cmd_table.cbBounsGameCount == 0 then
        self._game3View:game3Begin()
    end
end

function GameLayer:onGame3Result( dataBuffer )
    print("小玛丽结算")
    local cmd_table = g_ExternalFun.read_netdata(g_var(cmd).SHZ_CMD_S_GameThreeKaiJiang, dataBuffer)
    dump(cmd_table)
    local pGame3Result = GameLogic:copyTab(cmd_table)
    self.m_lGetCoins3 = self.m_lGetCoins3 + pGame3Result.lScore

    self.m_pGame3Result[#self.m_pGame3Result+1] =  pGame3Result
    --print("小玛丽结算 #self.m_pGame3Result",#self.m_pGame3Result)
end

--发送准备消息
function GameLayer:sendReadyMsg3()
    --发送数据
    local  dataBuffer= CCmd_Data:create(1)

    self:SendData(g_var(cmd).SHZ_SUB_C_THREE_START, dataBuffer)
end

function GameLayer:sendThreeEnd(  )
      --发送数据
    local  dataBuffer= CCmd_Data:create(1)

    self:SendData(g_var(cmd).SHZ_SUB_C_THREE_END, dataBuffer)  
end

--踢出消息10S 提示
function GameLayer:onOutGameTips()
    self:showTipsExit()
end

return GameLayer