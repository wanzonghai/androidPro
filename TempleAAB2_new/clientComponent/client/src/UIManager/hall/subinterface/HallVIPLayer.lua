---------------------------------------------------
--Desc:VIP主界面
--Date:2023-02-15 14:37:40
--Author:A*
---------------------------------------------------
local HallVIPLayer = class("HallVIPLayer",function(args)
    local HallVIPLayer =  display.newLayer()
    return HallVIPLayer
end)

HallVIPLayer.ColorW = cc.c3b(91,31,5)
HallVIPLayer.ColorP = cc.c3b(63,17,121)
local TypeID = g_ExternalFun.enum{
    "Week = 1",   --周礼包
    "Month = 2",   --月礼包
    "Growth = 3",    --成长礼包
}

local Status = g_ExternalFun.enum{
    "Unactivated = 1",   --未激活
    "Unreceived = 2",    --未领取
    "Received = 3",   --已领取
    "WaitReceive = 4",   --已激活未到领取时间
}

local m_MaxBaseEnsureTakeTimes = 2

function HallVIPLayer:onExit()
    G_event:RemoveNotifyEvent(G_eventDef.CMD_MB_AlmzLoadConfigResult)  
    G_event:RemoveNotifyEvent(G_eventDef.EVENT_VIP_TAKE_GIFT_RESULT)  
    --G_event:RemoveNotifyEvent(G_eventDef.CMD_MB_AlmzGetUserStatus) 
    G_event:RemoveNotifyEvent(G_eventDef.EVENT_BaseEnsureLoadConfig)  
    --G_event:RemoveNotifyEvent(G_eventDef.EVENT_BaseEnsureGetStatus)  
    G_event:RemoveNotifyEvent(G_eventDef.EVENT_BaseEnsureTakeReward)  

    local RemoveNotifyEventTwo = handler(G_event,G_event.RemoveNotifyEventTwo)
    RemoveNotifyEventTwo(self,G_eventDef.EVENT_VIP_GIFT_STATUS)   
    RemoveNotifyEventTwo(self,G_eventDef.EVENT_BaseEnsureGetStatus)
    RemoveNotifyEventTwo(self,G_eventDef.CMD_MB_AlmzGetUserStatus)
end

function HallVIPLayer:ctor(args)
    --提前加载合图
    local spriteFrameCache = cc.SpriteFrameCache:getInstance()
    spriteFrameCache:addSpriteFrames("client/res/VIP/VIPPlist.plist", "client/res/VIP/VIPPlist.png")

    local parent = (args and args.parent) and args.parent or cc.Director:getInstance():getRunningScene()
    parent:addChild(self,ZORDER.POPUP)    
    local csbNode = g_ExternalFun.loadCSB("VIP/VIPLayer.csb")
    self:addChild(csbNode)    
    g_ExternalFun.loadChildrenHandler(self,csbNode)
    --
    -- dump(GlobalUserItem.VIPInfo,"GlobalUserItem.VIPInfo",5)
    --[[
        dump from: [string "client/src/UIManager/hall/subinterface/HallVI..."]:25: in function 'ctor'
        [LUA-print] - "GlobalUserItem.VIPInfo" = {
        [LUA-print] -     "cbGrowLevel"          = 1
        [LUA-print] -     "dwPayCurrent"         = 0
        [LUA-print] -     "dwPayRequire"         = 0
        [LUA-print] -     "llBetCurrent"         = 104000
        [LUA-print] -     "llBetRequire"         = 0
        [LUA-print] -     "wDailyAddition"       = 0
        [LUA-print] -     "wDailyAdditionNext"   = 0
        [LUA-print] -     "wMonthlyAddition"     = 0
        [LUA-print] -     "wMonthlyAdditionNext" = 0
        [LUA-print] -     "wWeeklyAddition"      = 0
        [LUA-print] -     "wWeeklyAdditionNext"  = 0
        [LUA-print] - }
    ]]
    self.nextLevel = GlobalUserItem.VIPInfo.cbGrowLevel + 1 --下一个vip等级 最大20级目前
    if self.nextLevel > 20 then
        self.nextLevel = 20
    end
    --当前VIP
    self.mm_CurLevelValue:setString(GlobalUserItem.VIPInfo.cbGrowLevel)
    self.mm_CurLevel:loadTexture(string.format("client/res/VIP/GUI/%d.png",GlobalUserItem.VIPInfo.cbGrowLevel),UI_TEX_TYPE_PLIST)
    --下一级VIP
    self.mm_NextLevel:loadTexture(string.format("client/res/VIP/GUI/%d.png",self.nextLevel),UI_TEX_TYPE_PLIST)
    --充值进度条    
    self.mm_LoadingBar_1:setPercent(GlobalUserItem.VIPInfo.dwPayCurrent*100/GlobalUserItem.VIPInfo.dwPayRequire)
    local listView = self.mm_LoadingBar_1:getChildByName("listview_1")
    listView:setBounceEnabled(false) 
    listView:setScrollBarEnabled(false)
    listView:setTouchEnabled(false)
    local pCurrProgress = listView:getChildByName("CurrProgress")
    local pNeedProgress = listView:getChildByName("NeedProgress")
    local CurProgress = GlobalUserItem.VIPInfo.dwPayCurrent
    local NeedProgress = GlobalUserItem.VIPInfo.dwPayRequire

    if CurProgress < NeedProgress then
        self.mm_Less_score:setVisible(true)
        local score = g_format:formatNumber(NeedProgress-CurProgress,g_format.fType.standard)
        self.mm_Less_score:setString("Faltando "..score)
    else
        self.mm_Less_score:setVisible(false)
    end
    self.mm_Button_Jump:onClicked(function () self:jumpGiftCenter() end)

    CurProgress = g_format:formatNumber(CurProgress,g_format.fType.standard)
    NeedProgress = g_format:formatNumber(NeedProgress,g_format.fType.standard)        
    pCurrProgress:setString(CurProgress)
    pNeedProgress:setString(NeedProgress)
    if CurProgress >= NeedProgress then
        pCurrProgress:setColor(cc.c3b(138,241,247))
    else
        pCurrProgress:setColor(cc.c3b(242,229,27))
    end
    performWithDelay(listView,function() listView:jumpToRight () end,0)

    
    --投注进度条
    if GlobalUserItem.VIPInfo.llBetRequire and tonumber(GlobalUserItem.VIPInfo.llBetRequire) == 0 then
        self.mm_LoadingBar_2:setPercent(100)
    else
        self.mm_LoadingBar_2:setPercent(GlobalUserItem.VIPInfo.llBetCurrent*100/GlobalUserItem.VIPInfo.llBetRequire)
    end
    
    local listView = self.mm_LoadingBar_2:getChildByName("listview_2")
    listView:setBounceEnabled(false) 
    listView:setScrollBarEnabled(false)
    listView:setTouchEnabled(false)
    local pCurrProgress = listView:getChildByName("CurrProgress")
    local pNeedProgress = listView:getChildByName("NeedProgress")
    local CurProgress = GlobalUserItem.VIPInfo.llBetCurrent
    local NeedProgress = GlobalUserItem.VIPInfo.llBetRequire
    CurProgress = g_format:formatNumber(CurProgress,g_format.fType.standard)
    NeedProgress = g_format:formatNumber(NeedProgress,g_format.fType.standard) 
    pCurrProgress:setString(CurProgress)
    pNeedProgress:setString(NeedProgress)
    if CurProgress >= NeedProgress then
        pCurrProgress:setColor(cc.c3b(138,241,247))
    else
        pCurrProgress:setColor(cc.c3b(242,229,27))
    end
    performWithDelay(listView,function() listView:jumpToRight () end,0)

    
    self.mm_Right_6:onClicked(function () self:onClickRescueFunds() end)
    self.mm_Right_0:onClicked(function () self:onClickGiftLeft() end)
    self.mm_Right_1:onClicked(function () self:onWeekGiftClicked() end)
    self.mm_Right_2:onClicked(function () self:onMonthGiftClicked() end)
    self.mm_Right_3:onClicked(function () self:onRightClicked(1) end)
    self.mm_Right_5:onClicked(function () self:onBaseEnsureClicked() end)
    self.mm_Right_3:getChildByName("ValueCurr_1"):setString("+"..GlobalUserItem.VIPInfo.wDailyAddition.."%")
    self.mm_Right_3:getChildByName("ValueNext_1"):setString("+"..GlobalUserItem.VIPInfo.wDailyAdditionNext.."%")
    self.mm_Right_3:getChildByName("ValueCurr_2"):setString("+"..GlobalUserItem.VIPInfo.wWeeklyAddition.."%")
    self.mm_Right_3:getChildByName("ValueNext_2"):setString("+"..GlobalUserItem.VIPInfo.wWeeklyAdditionNext.."%")
    self.mm_Right_3:getChildByName("ValueCurr_3"):setString("+"..GlobalUserItem.VIPInfo.wMonthlyAddition.."%")
    self.mm_Right_3:getChildByName("ValueNext_3"):setString("+"..GlobalUserItem.VIPInfo.wMonthlyAdditionNext.."%")
    self.mm_Right_6:getChildByName("Button_Reward"):onClicked(function () self:onClickRescueFunds() end)
    self.mm_Right_0:getChildByName("Button_Reward"):onClicked(function () self:onClickGiftLeft() end)
    self.mm_Right_1:getChildByName("Button_Reward"):onClicked(function () self:onWeekGiftClicked() end)
    self.mm_Right_2:getChildByName("Button_Reward"):onClicked(function () self:onMonthGiftClicked() end)
    self.mm_Right_5:getChildByName("Button_Reward"):onClicked(function () self:onBaseEnsureClicked() end)
    self.mm_Right_6:getChildByName("vipBiLiBtn"):onClicked(function ()
        G_event:NotifyEvent(G_eventDef.UI_SHOW_VipHelperMoneyConfig,self._vipHelperConfigData)
    end)

    local vipBiLiText = self.mm_Right_6:getChildByName("vipBiLiText")
    self._vipBiLiText = self:getCountTextByNode("client/res/VIP/VipHelpMoney/lb_sc3_%s.png")
    vipBiLiText:addChild(self._vipBiLiText)
    self._vipBiLiText:setString("0b")
    local text_vip_level = self.mm_Right_3:getChildByName("ImageV1"):getChildByName("vip_level")
    text_vip_level:setString(self.nextLevel)
    local text_vip_level = self.mm_Right_3:getChildByName("ImageV2"):getChildByName("vip_level")
    text_vip_level:setString(self.nextLevel)
    local text_vip_level = self.mm_Right_3:getChildByName("ImageV3"):getChildByName("vip_level")
    text_vip_level:setString(self.nextLevel)

    --背景
    local bgSpine = sp.SkeletonAnimation:create("client/res/VIP/spine/VIP_2.json","client/res/VIP/spine/VIP_2.atlas", 1)
    bgSpine:addTo(self.mm_Spine_bg)
    bgSpine:setPosition(0, 0)
    bgSpine:setAnimation(0, "ruchang", false)
    bgSpine:registerSpineEventHandler( function( event )
        if event.type == "complete" then
            bgSpine:setAnimation(0, "daiji", true)
        end
    end, sp.EventType.ANIMATION_COMPLETE)

    --光效
    local bgSpine2 = sp.SkeletonAnimation:create("client/res/VIP/spine/VIP_1.json","client/res/VIP/spine/VIP_1.atlas", 1)
    bgSpine2:addTo(self.mm_Spine_pre)
    bgSpine2:setPosition(0, 0)
    bgSpine2:setAnimation(0, "ruchang", false)
    bgSpine2:registerSpineEventHandler( function( event )
        if event.type == "complete" then
            bgSpine2:setAnimation(0, "daiji", true)
        end
    end, sp.EventType.ANIMATION_COMPLETE)

    self.mm_bg:onClicked(handler(self,self.onClickClose),true)
    self.mm_btnClose:onClicked(handler(self,self.onClickClose),true)
    self.mm_btnHelp:onClicked(handler(self,self.onClickHelp),true)
    --self.mm_btnHelp:setVisible(false)

    self.mm_Button_Left:onClicked(handler(self,self.onClickLeft),true)
    self.mm_Button_Right:onClicked(handler(self,self.onClickRight),true)

    -- self.mm_Button_Gift_Left:onClicked(handler(self,self.onClickGiftLeft),true)
    -- self.mm_Button_Gift_Right:onClicked(handler(self,self.onClickGiftRight),true)

    -- --左边礼包动画
    -- local vipwlq = sp.SkeletonAnimation:create("client/res/VIP/spine/vipwlq.json","client/res/VIP/spine/vipwlq.atlas", 1)
    -- vipwlq:addTo(self.mm_Button_Gift_Left)
    -- vipwlq:setPosition(80, 80)
    -- vipwlq:setAnimation(0, "daiji1", true)

    -- --右边礼包动画
    -- local vipwlq = sp.SkeletonAnimation:create("client/res/VIP/spine/vipwlq.json","client/res/VIP/spine/vipwlq.atlas", 1)
    -- vipwlq:addTo(self.mm_Button_Gift_Right)
    -- vipwlq:setPosition(80, 80)
    -- vipwlq:setAnimation(0, "daiji2", true)
    --第一个礼包
    local ImageTips2 = self.mm_Right_0:getChildByName("ImageTips2")
    self.vipwlq = sp.SkeletonAnimation:create("client/res/VIP/spine/vipwlq.json","client/res/VIP/spine/vipwlq.atlas", 1)
    self.vipwlq:addTo(ImageTips2)
    self.vipwlq:setPosition(30, 30)
    self.vipwlq:setAnimation(0, "daiji2", true)

    --破产补助礼包动画
    local ImageTips2 = self.mm_Right_5:getChildByName("ImageTips2")
    self.vipbuzhu = sp.SkeletonAnimation:create("client/res/VIP/spine/vipwlq.json","client/res/VIP/spine/vipwlq.atlas", 1)
    self.vipbuzhu:addTo(ImageTips2)
    self.vipbuzhu:setPosition(30, 30)
    self.vipbuzhu:setAnimation(0, "daiji2_1", true)

    --呼出动效
    ShowCommonLayerAction(self.mm_bg,self.mm_content)

    G_event:AddNotifyEvent(G_eventDef.CMD_MB_AlmzLoadConfigResult,handler(self,self.vipHelperConfig))
    G_event:AddNotifyEvent(G_eventDef.EVENT_VIP_TAKE_GIFT_RESULT,handler(self,self.onTakeGrowGiftResult))   --提取成长礼包 返回
    G_event:AddNotifyEvent(G_eventDef.EVENT_BaseEnsureLoadConfig,handler(self,self.onBaseEnsureLoadConfigResult))   -- 破产补助 - 加载配置 返回
    --G_event:AddNotifyEvent(G_eventDef.EVENT_BaseEnsureGetStatus,handler(self,self.onBaseEnsureGetStatusResult))   -- 破产补助 - 获取用户状态 返回
    G_event:AddNotifyEvent(G_eventDef.EVENT_BaseEnsureTakeReward,handler(self,self.onBaseEnsureTakeRewardResult))   --破产补助 - 领取奖励 返回
    --G_event:AddNotifyEvent(G_eventDef.CMD_MB_AlmzGetUserStatus,handler(self,self.vipUserGoldStatusResult))         --获取VIP的救援金用户状态返回
    local AddNotifyEventTwo = handler(G_event,G_event.AddNotifyEventTwo)
    AddNotifyEventTwo(self,G_eventDef.EVENT_VIP_GIFT_STATUS,handler(self,self.onGetGrowGiftStatusResult))   --获取成长等级界面礼包状态 返回
    AddNotifyEventTwo(self,G_eventDef.EVENT_BaseEnsureGetStatus,handler(self,self.onBaseEnsureGetStatusResult)) -- 破产补助 - 获取用户状态 返回
    AddNotifyEventTwo(self,G_eventDef.CMD_MB_AlmzGetUserStatus,handler(self,self.vipUserGoldStatusResult))         --获取VIP的救援金用户状态返回

    G_ServerMgr:C2S_GetGrowGiftStatus()            --先请求数据再打开转盘

    if not GlobalUserItem.BaseEnsureConfig then
        G_ServerMgr:C2S_BaseEnsureLoadConfig()            --破产补助 - 加载配置
    else
        G_ServerMgr:C2S_BaseEnsureGetStatus()            --破产补助 - 获取用户状态
    end

 
    showNetLoading()
    G_ServerMgr:CMD_MB_AlmzLoadConfig() 
end

--救援金
function HallVIPLayer:onClickRescueFunds()
    if self.UserGoldStatusResult then
        G_event:NotifyEvent(G_eventDef.UI_SHOW_VipHelpMoney,{self.UserGoldStatusResult,self._vipHelperConfigData})
    end
end

-- 周六周日才能领取
-- 25号之后才能领取
-- Só é possível receber no sábado e domingo.
-- Só é possível receber após o dia 25.
function HallVIPLayer:onWeekGiftClicked()
    local cbStatus = self.GiftStatus.weekGift.cbStatus --当前奖励的状态：1未激活 2 可领取 3已领取
    if cbStatus == Status.Unactivated then
        showToast("Desbloqueie pacotes de presente com qualquer recarga esta semana") 
        self:showQueryDialog()
        --G_ServerMgr:C2S_TakeGrowGift(1)
    elseif cbStatus == Status.WaitReceive then
            showToast("Só é possível receber no sábado e domingo.") 
    elseif cbStatus == Status.Unreceived then
        G_ServerMgr:C2S_TakeGrowGift(TypeID.Week) --1表示周礼金，2表示月礼金, 3表示成长礼金
    end
end
function HallVIPLayer:onMonthGiftClicked()
    local cbStatus = self.GiftStatus.monthGift.cbStatus --当前奖励的状态：1未激活 2 可领取 3已领取
    if cbStatus == Status.Unactivated then
        showToast("Desbloqueie o pacote de presente com qualquer recarga este mês")
        self:showQueryDialog()
        --G_ServerMgr:C2S_TakeGrowGift(2) 
    elseif cbStatus == Status.WaitReceive then
        showToast("Só é possível receber após o dia 25.") 
    elseif cbStatus == Status.Unreceived then
        G_ServerMgr:C2S_TakeGrowGift(TypeID.Month) --1表示周礼金，2表示月礼金, 3表示成长礼金
    end
end
function HallVIPLayer:onClickGiftLeft()
    local cbStatus = self.GiftStatus.growGift.cbStatus --当前奖励的状态：1未激活 2 可领取 3已领取
    if cbStatus == Status.Unreceived then
        G_ServerMgr:C2S_TakeGrowGift(TypeID.Growth) --1表示周礼金，2表示月礼金, 3表示成长礼金
    elseif cbStatus == Status.Received then --升级VIP，继续免费领取
        local str = "Atualize para VIP e continue obtendo gratuitamente."
        self:showQueryDialog(str)
    else
        showToast("Você ainda não atingiu o V"..self.nextLevel..". Não pode reivindicar.") 
        self:showQueryDialog()
    end
end
function HallVIPLayer:onClickGiftRight()
    showToast("Você ainda não atingiu o V"..self.nextLevel..". Não pode reivindicar.") 
end

function HallVIPLayer:showQueryDialog(str)
    --local QueryDialog = appdf.req("client.src.UIManager.hall.subinterface.CommonDialog")
    local txt = str or "Recarregue para desbloquear, gostaria de ir para a recarga?"     --您的话费订单已提交,如您三日内未

    local pData = {
        msg = txt,
        callback = function(click)
            if click == "ok" then      
                self:jumpGiftCenter()
            end					
        end
    }
    G_event:NotifyEvent(G_eventDef.UI_OPEN_COMMON_DIALOG,pData)
end

function HallVIPLayer:jumpGiftCenter()
    if  GlobalData.ProductsOver and GlobalData.GiftEnable and GlobalData.PayInfoOver then            
        local pData = {
            ShowType = 1,--展示礼包类型：1.首充 2.每日 3.一次性
            NoticeNext = self.NoticeNext
        }
        G_event:NotifyEvent(G_eventDef.UI_SHOW_GIFT_CENTER,pData)
    end
    self:removeSelf()
end

function HallVIPLayer:onGetGrowGiftStatusResult(pData)
    dump(pData)
    self.GiftStatus = pData or {}

    self:updateGiftItem(self.mm_Right_1,self.GiftStatus.weekGift)
    self:updateGiftItem(self.mm_Right_2,self.GiftStatus.monthGift)
    self:updateGiftItem(self.mm_Right_0,self.GiftStatus.growGift)

    -- local growGift = self.GiftStatus.growGift --成长礼金
    -- local cbStatus = growGift.cbStatus --当前奖励的状态：1未激活 2 可领取 3已领取
    -- self:updateGiftBtnStatus(self.mm_Right_0,cbStatus)
end

function HallVIPLayer:updateGiftItem(item,data)
    local cbStatus = data.cbStatus --当前奖励的状态：s1未激活 2 可领取 3已领取
    
    self:updateGiftItemStatus(item,cbStatus)

    --local nextLevel = GlobalUserItem.VIPInfo.cbGrowLevel + 1 --self.GiftStatus.cbGrowLevel + 1
    local rewardScore = g_format:formatNumber(data.llRewardScore,g_format.fType.abbreviation,g_format.currencyType.GOLD)
    local score = g_format:formatNumber(data.llScore,g_format.fType.abbreviation,g_format.currencyType.GOLD)
    local nextScore = g_format:formatNumber(data.llNextScore,g_format.fType.abbreviation,g_format.currencyType.GOLD)
    local Text_ValueCurr = item:getChildByName("Text_ValueCurr")
    if GlobalUserItem.VIPInfo.cbGrowLevel <= 0 then
        Text_ValueCurr:setString(nextScore)
    else
        Text_ValueCurr:setString(rewardScore)
    end
    
    local text_vip_level = item:getChildByName("ImageV1"):getChildByName("vip_level")
    text_vip_level:setString(self.nextLevel)
    local ValueCurr = item:getChildByName("ValueCurr")
    --local score = g_format:formatNumber(data.llScore,g_format.fType.abbreviation,g_format.currencyType.GOLD)
    ValueCurr:setString(score)--当前等级可领取的奖励，真金服需要除以100
    local ValueNext = item:getChildByName("ValueNext")
    --local nextScore = g_format:formatNumber(data.llNextScore,g_format.fType.abbreviation,g_format.currencyType.GOLD)
    ValueNext:setString(nextScore)--下一级可领取到的奖励，真金服需要除以100

end

-- "Unactivated = 1",   --未激活
-- "Unreceived = 2",    --未领取
-- "Received = 3",   --已领取
-- "WaitReceive = 4",   --已激活未到领取时间
--刷新周月礼包状态
function HallVIPLayer:updateGiftItemStatus(item,cbStatus) --当前奖励的状态：1未激活 2 可领取 3已领取
    local ImageLock = item:getChildByName("ImageLock")
    local ImageStatus = item:getChildByName("ImageStatus")
    local ImagePoint = item:getChildByName("ImagePoint")
    local Button_Reward = item:getChildByName("Button_Reward")
    local ValueCurr = item:getChildByName("ValueCurr")
    local ValueNext = item:getChildByName("ValueNext")
    --cbStatus = Status.Received
    if cbStatus == Status.Unactivated then
        --ImageLock:setVisible(true)
        ImageStatus:setVisible(false)
        ImagePoint:setVisible(false)
        Button_Reward:setVisible(true)
        ValueCurr:setVisible(false)
        ValueNext:setVisible(false)
        self.vipwlq:setAnimation(0, "daiji2", true)
        ImageStatus:ignoreContentAdaptWithSize(true)
        ImageStatus:loadTexture("client/res/VIP/GUI/vip_suozhu.png",UI_TEX_TYPE_PLIST)
    elseif cbStatus == Status.Unreceived then
        --ImageLock:setVisible(false)
        ImageStatus:setVisible(false)
        ImagePoint:setVisible(true)
        Button_Reward:setVisible(true)
        ValueCurr:setVisible(false)
        ValueNext:setVisible(false)
        self.vipwlq:setAnimation(0, "daiji1", true)
    elseif cbStatus == Status.Received then
        --ImageLock:setVisible(false)
        ImageStatus:setVisible(true)
        ImagePoint:setVisible(false)
        Button_Reward:setVisible(false)
        ValueCurr:setVisible(true)
        ValueNext:setVisible(true)
        self.vipwlq:setAnimation(0, "daiji2", true)
        ImageStatus:ignoreContentAdaptWithSize(true)
        ImageStatus:loadTexture("client/res/VIP/GUI/vip_jlingqu.png",UI_TEX_TYPE_PLIST)
    elseif cbStatus == Status.WaitReceive then
        --ImageLock:setVisible(false)
        ImageStatus:setVisible(false)
        ImagePoint:setVisible(false)
        Button_Reward:setVisible(true)
        ValueCurr:setVisible(false)
        ValueNext:setVisible(false)
        self.vipwlq:setAnimation(0, "daiji2", true)
    end
    ImageLock:setVisible(false)
    --ImageStatus:setVisible(false)

    if GlobalUserItem.VIPInfo.cbGrowLevel <= 0 then
        Button_Reward:setVisible(false)
        ValueCurr:setVisible(true)
        ValueNext:setVisible(true)
    end
end

function HallVIPLayer:updateBaseEnsureStatus(item,cbStatus) --当前奖励的状态：1未激活 2 可领取 3已领取
    local ImageLock = item:getChildByName("ImageLock")
    local ImageStatus = item:getChildByName("ImageStatus")
    local ImagePoint = item:getChildByName("ImagePoint")
    local Button_Reward = item:getChildByName("Button_Reward")
    local ValueCurr = item:getChildByName("ValueCurr")
    local ValueNext = item:getChildByName("ValueNext")
    local Text_Get = item:getChildByName("Text_Get")
    if cbStatus == Status.Unactivated then
        ImageStatus:setVisible(false)
        ImagePoint:setVisible(false)
        Button_Reward:setVisible(true)
        ValueCurr:setVisible(false)
        ValueNext:setVisible(false)
        self.vipbuzhu:setAnimation(0, "daiji2_1", true)
        ImageStatus:ignoreContentAdaptWithSize(true)
        ImageStatus:loadTexture("client/res/VIP/GUI/vip_suozhu.png",UI_TEX_TYPE_PLIST)
    elseif cbStatus == Status.Unreceived then
        ImageStatus:setVisible(false)
        ImagePoint:setVisible(true)
        Button_Reward:setVisible(true)
        ValueCurr:setVisible(false)
        ValueNext:setVisible(false)
        self.vipbuzhu:setAnimation(0, "daiji1_1", true)
    elseif cbStatus == Status.Received then
        ImageStatus:setVisible(true)
        ImagePoint:setVisible(false)
        Button_Reward:setVisible(false)
        ValueCurr:setVisible(true)
        ValueNext:setVisible(true)
        self.vipbuzhu:setAnimation(0, "daiji2_1", true)
        ImageStatus:ignoreContentAdaptWithSize(true)
        ImageStatus:loadTexture("client/res/VIP/GUI/vip_jlingqu.png",UI_TEX_TYPE_PLIST)
    elseif cbStatus == Status.WaitReceive then --当配置为0 的时候显示下一级
        ImageStatus:setVisible(false)
        ImagePoint:setVisible(false)
        Button_Reward:setVisible(false)
        ValueCurr:setVisible(true)
        ValueNext:setVisible(true)
        self.vipbuzhu:setAnimation(0, "daiji2_1", true)
    end
    ImageLock:setVisible(false)
    --Button_Reward:setVisible(true)
end

function HallVIPLayer:onBaseEnsureLoadConfigResult(data)
    dump(data)
    G_ServerMgr:C2S_BaseEnsureGetStatus()            --破产补助 - 获取用户状态
end

function HallVIPLayer:onBaseEnsureGetStatusResult(data)
    dump(data)
    self.BaseEnsure = data
    -- [LUA-print] dump from: [string "client/src/UIManager/hall/subinterface/HallVI..."]:476: in function 'event_notify'
    --     [LUA-print] - "<var>" = {
    --     [LUA-print] -     "cbGrowLevel"   = 1
    --     [LUA-print] -     "cbIsEnable"    = 0
    --     [LUA-print] -     "cbIsTodayPay"  = 0
    --     [LUA-print] -     "dwTakeTimes"   = 0
    --     [LUA-print] -     "llRewardScore" = 200
    --     [LUA-print] -     "llTotalScore"  = 179051194
    --     [LUA-print] - }
    --     [LUA-print] code = ,error:nil
    local item = self.mm_Right_5

    local rewardScore = g_format:formatNumber(data.llRewardScore,g_format.fType.abbreviation,g_format.currencyType.GOLD)
    local Text_ValueCurr = item:getChildByName("Text_ValueCurr")
    Text_ValueCurr:setString(rewardScore)

    local dwTakeTimes = data.dwTakeTimes
    local Text_Get = item:getChildByName("Text_Get")
    Text_Get:setString(dwTakeTimes.."/"..m_MaxBaseEnsureTakeTimes)

    local llLevelReward = GlobalUserItem.BaseEnsureConfig.llLevelReward
    local text_vip_level = item:getChildByName("ImageV1"):getChildByName("vip_level")
    text_vip_level:setString(self.nextLevel)
    local ValueCurr = item:getChildByName("ValueCurr")
    local llScore = llLevelReward[self.nextLevel]
    local totalScore = llScore.llScoreFirst + llScore.llScoreScecond
    local score = g_format:formatNumber(totalScore,g_format.fType.abbreviation,g_format.currencyType.GOLD)
    ValueCurr:setString(score)--当前等级可领取的奖励，真金服需要除以100
    local ValueNext = item:getChildByName("ValueNext")
    local llNextScore = llLevelReward[self.nextLevel+1]
    local totalNextScore = llNextScore.llScoreFirst + llNextScore.llScoreScecond
    local nextScore = g_format:formatNumber(totalNextScore,g_format.fType.abbreviation,g_format.currencyType.GOLD)
    ValueNext:setString(nextScore)--下一级可领取到的奖励，真金服需要除以100

    
    local cbStatus = Status.Unactivated --未激活

    if data.cbIsEnable > 0 then
        cbStatus = Status.Unreceived --未领取
    end
    if data.dwTakeTimes >= m_MaxBaseEnsureTakeTimes then
        cbStatus = Status.Received --已领取
        local rewardScore = g_format:formatNumber(llScore.llScoreScecond,g_format.fType.abbreviation,g_format.currencyType.GOLD)
        Text_ValueCurr:setString(rewardScore) 
    end
    
    if totalScore <= 0 then
        cbStatus = Status.WaitReceive --金额配置为0
        Text_ValueCurr:setVisible(false)
        Text_Get:setVisible(false)
    else
        Text_ValueCurr:setVisible(true)
        Text_Get:setVisible(true)
    end
    
    self:updateBaseEnsureStatus(self.mm_Right_5,cbStatus)
    --self:updateBaseEnsurePos(cbStatus)
end

function HallVIPLayer:updateBaseEnsurePos(cbStatus)
    local list = {self.mm_Right_0,self.mm_Right_1,self.mm_Right_2,self.mm_Right_5}
    if cbStatus == Status.Unreceived then --Unactivated  Unreceived
        list = {self.mm_Right_5,self.mm_Right_0,self.mm_Right_1,self.mm_Right_2}
    end
    for i, v in ipairs(list) do
        v:setPositionX(550+(i-1)*350)
    end
end

function HallVIPLayer:onBaseEnsureClicked()
    if not GlobalUserItem.BaseEnsureConfig or not self.BaseEnsure then
        return
    end
    local data = self.BaseEnsure
    local dwTakeTimes = data.dwTakeTimes --已经领取的次数(dwTakeTimes=2，表示今天已领完了) 取值范围[0,2]
    local llFirstRequire = GlobalUserItem.BaseEnsureConfig.llFirstRequire
    local llSecondRequire = GlobalUserItem.BaseEnsureConfig.llSecondRequire
    local llLimitScore = llFirstRequire
    if dwTakeTimes == 1 then
        llLimitScore = llSecondRequire
    end
    --如玩家点击第一次免费领取破产补助时，不满足破产条件，点击领取，弹出提示TIPS，“您的金额不满足领取条件” 本次领取需要您金额不足XX
    if (GlobalUserItem.lUserScore + GlobalUserItem.lUserInsure) > llLimitScore then
        local score = g_format:formatNumber(llLimitScore,g_format.fType.abbreviation,g_format.currencyType.GOLD)
        showToast("Para receber nesta vez, você precisa de um valor inferior a "..score) 
        return
    end

    local cbStatus = Status.Unactivated --未激活

    if data.cbIsEnable > 0 then
        cbStatus = Status.Unreceived --未领取
    end
    if data.dwTakeTimes >= m_MaxBaseEnsureTakeTimes then
        cbStatus = Status.Received --已领取
    end
    local llLevelReward = GlobalUserItem.BaseEnsureConfig.llLevelReward
    local llScore = llLevelReward[self.nextLevel]
    local totalScore = llScore.llScoreFirst + llScore.llScoreScecond

    if totalScore <= 0 then
        cbStatus = Status.WaitReceive --金额配置为0
    end

    if cbStatus == Status.Unactivated then
        self:showQueryDialog()
    elseif cbStatus == Status.WaitReceive then
        self:showQueryDialog()
    elseif cbStatus == Status.Unreceived then
        G_ServerMgr:C2S_BaseEnsureTakeReward() 
    end


end

function HallVIPLayer:showRewardLayer(score)
    local name = "mrrw_jb_1"
    local imagePath = string.format("client/res/public/%s.png",name)
    local path = "client.src.UIManager.hall.subinterface.rewardLayer"
    local data = {}
    data.goldImg = imagePath
    data.goldTxt = g_format:formatNumber(score,g_format.fType.standard)
    data.type = 1
    local layer = appdf.req(path).new(data)
end

function HallVIPLayer:onBaseEnsureTakeRewardResult(data)
    dump(data)
    if data.dwErrorCode == 0 then
        printf("领取成功")
        -- self.BaseEnsure.dwTakeTimes = m_MaxBaseEnsureTakeTimes - data.dwRestTimes

        -- self:onBaseEnsureGetStatusResult(self.BaseEnsure)
        --刷新
        G_ServerMgr:C2S_BaseEnsureGetStatus()
        --刷新用户金币
        G_ServerMgr:C2S_RequestUserGold()

        self:showRewardLayer(data.llScore)
    else
        -- 可能引发的错误（在明知不可领取的时候发送了此协议，则会引发下面的错误）
        if data.dwErrorCode == 722 then
            printf("游戏币+银行金币未达到可领取破产补助的门槛")
        elseif data.dwErrorCode == 723 then
            printf("本日可领取破产补助次数已完毕")
        elseif data.dwErrorCode == 724 then
            printf("领取第二次破产补助需要有充值行为")
        else
            printf("未知错误")
        end
        showToast("Recebimento falhou:"..data.dwErrorCode)
    end  
end

function HallVIPLayer:onTakeGrowGiftResult(pData)
    dump(pData)
    local wCount = pData.wCount or 0 --如果用户升级的时候跳级，则可能有多个成长礼金下发,但周月礼金只有1个
    if wCount > 0 then
        --刷新当前界面状态
        local cbTypeID = pData.cbTypeID --1表示周礼金，2表示月礼金，3表示成长礼金
        if cbTypeID == TypeID.Week then
            self:updateGiftItemStatus(self.mm_Right_1,Status.Received) --当前奖励的状态：1未激活 2 可领取 3已领取
        elseif cbTypeID == TypeID.Month then
            self:updateGiftItemStatus(self.mm_Right_2,Status.Received)
        elseif cbTypeID == TypeID.Growth then
            self:updateGiftItemStatus(self.mm_Right_0,Status.Received)
            --self:updateGiftBtnStatus(self.mm_Right_0,Status.Received)
        end
        --显示奖励界面
        G_event:NotifyEvent(G_eventDef.UI_SHOW_HALL_VIP_REWARD,pData)
        --刷新用户金币
        G_ServerMgr:C2S_RequestUserGold()
    end
end

function HallVIPLayer:onClickLeft()
    self.mm_ScrollView_1:scrollToLeft(0.05,false)
end

function HallVIPLayer:onClickRight()
    self.mm_ScrollView_1:scrollToRight(0.05,false)
end

function HallVIPLayer:onClickHelp()
    appdf.req("client.src.UIManager.hall.subinterface.HallVIPHelpLayer").new(self._vipHelperConfigData)
end

--BonusValue
function HallVIPLayer:refreshBonusValue()
    --BonusValue
    G_ServerMgr:C2S_GetGrowGiftStatus()
    G_ServerMgr:C2S_BaseEnsureGetStatus()
    G_ServerMgr:AlmzGetUserStatus() --救援金
end

function HallVIPLayer:onClickClose()
    DoHideCommonLayerAction(self.mm_bg,self.mm_content,function()   
        self:refreshBonusValue()
        self:removeSelf() 
    end)
end

function HallVIPLayer:onRightClicked(pIndex)
    DoHideCommonLayerAction(self.mm_bg,self.mm_content,function()        
        self:removeSelf()                 
        -- G_event:NotifyEvent(G_eventDef.UI_SHOW_TURNTABLE,{ShowType=pIndex}) --打开转盘
        local TurnTableManager = appdf.req(appdf.CLIENT_SRC.."UIManager.hall.subinterface.TurnTable.TurnTableManager")
        TurnTableManager.setShowType(pIndex)
        if not TurnTableManager.getData() then
            G_ServerMgr:C2s_getTurnConfig() 
        end
        G_ServerMgr:C2s_getTurnUserConfig(6)            --先请求数据再打开转盘
    end)
end

function HallVIPLayer:vipUserGoldStatusResult(data)
    dump(data)
    self.UserGoldStatusResult = data
    local item = self.mm_Right_6
    -- local ImageLock = item:getChildByName("ImageLock")
    -- local ImageStatus = item:getChildByName("ImageStatus")
    local ImageTitle = item:getChildByName("ImageTitle")
    local ImagePoint = item:getChildByName("ImagePoint")
    local Text_ValueCurr = item:getChildByName("Text_ValueCurr")

    -- local result = {
    --     yesterdayStatus = pData:readbyte(),             --状态 0,未发放；1：已发放(未领取、可领取。需要判断llAlmzScore是否为0) 2：已领取
    --     yesterdayLossScore = pData:readscore(int64):getvalue(), --损失  = 昨日总充值-昨日总提现-昨日用户余额
    --     yesterdayAmlzScore = pData:readscore(int64):getvalue(), --实际的救济金
    --     todayStatus = pData:readbyte(),  -- 0
    --     todayLossScore = pData:readscore(int64):getvalue(),
    --     todayAmlzScore = pData:readscore(int64):getvalue()
    -- }
    local yesterdayStatus = data.yesterdayStatus or 0
    local yesterdayAmlzScore = data.yesterdayAmlzScore or 0
    local todayAmlzScore = data.todayAmlzScore or 0
    if yesterdayAmlzScore < 0 then
        yesterdayAmlzScore = 0
    end
    if todayAmlzScore < 0 then
        todayAmlzScore = 0
    end
    if yesterdayStatus == 1 and yesterdayAmlzScore > 0 then ----状态 0,未发放；1：已发放(未领取、可领取。需要判断llAlmzScore是否为0) 2：已领取
        ImagePoint:setVisible(true)
        ImageTitle:loadTexture("client/res/VIP/GUI/vip_jyjj_puwen1.png",UI_TEX_TYPE_PLIST)
        local score = g_format:formatNumber(yesterdayAmlzScore,g_format.fType.abbreviation,g_format.currencyType.GOLD)
        Text_ValueCurr:setString(score)
        self._vipBiLiText:setString((self:getVipBiliByVipHelperConfig(data.yesterdaycbGrowLevel)/10) .. "b")
        self._vipBiLiText:setPositionX(-self._vipBiLiText:getContentSize().width/2)
    else
        ImagePoint:setVisible(false)
        ImageTitle:loadTexture("client/res/VIP/GUI/vip_jyjj_puwen2.png",UI_TEX_TYPE_PLIST)
        local score = g_format:formatNumber(todayAmlzScore,g_format.fType.abbreviation,g_format.currencyType.GOLD)
        Text_ValueCurr:setString(score)
        self._vipBiLiText:setString((self:getVipBiliByVipHelperConfig(data.todaycbGrowLevel)/10) .. "b")
        self._vipBiLiText:setPositionX(-self._vipBiLiText:getContentSize().width/2)
    end
 
end

function HallVIPLayer:getVipBiliByVipHelperConfig(vip)
    return self._vipHelperConfigData[vip + 1]
end

--vip配置返回
function HallVIPLayer:vipHelperConfig(pData)
    dismissNetLoading()
    local int64 = Integer64:new()
    local result = {}
    for i=1,21 do
        local data = pData:readword()
        table.insert(result, data)
    end
    self._vipHelperConfigData = result
    G_ServerMgr:AlmzGetUserStatus() --救援金
end

--通过图片数字创建文本
--spriteFrameName图片纹理名
function HallVIPLayer:getCountTextByNode(spriteFrameName)
    local node = cc.Node:create()
    local curLong = 2           --字体之间的间距
    local width = 0             --字体的宽度
    local strTab = {}
    node.setString = function(sender,str) 
      --  local spriteFrameCache = cc.SpriteFrameCache:getInstance()    
       -- spriteFrameCache:addSpriteFrames("client/res/Lobby/GameIconPlist.plist", "client/res/Lobby/GameIconPlist.png")
       -- spriteFrameCache:addSpriteFrames("client/res/Lobby/GameIconPlist2.plist", "client/res/Lobby/GameIconPlist2.png")
        str = str or ""
        str = tostring(str)
        width = 0
        for k = 1,#strTab do
            strTab[k]:hide()
        end
        for k = 1,#str do
            local st = string.sub(str,k,k)
            local sprite = strTab[k]
            if not sprite then
                sprite = display.newSprite()
                node:addChild(sprite)
                strTab[#strTab + 1] = sprite
                sprite:setAnchorPoint(cc.p(0,0.5))
            end
            sprite:show()
            sprite:setSpriteFrame(string.format(spriteFrameName,st))
            sprite:setPosition(cc.p(width,0))
            width = width + sprite:getContentSize().width + curLong
        end
        if width ~= 0 then width = width - curLong end
    end
    node.getContentSize = function(sender) 
        return cc.size(width,18)
    end

    return node
end

return HallVIPLayer