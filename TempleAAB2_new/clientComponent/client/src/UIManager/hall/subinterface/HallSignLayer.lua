---------------------------------------------------
--Desc:每日签到界面
--Date:2022-09-21 15:28:47
--Author:A*
---------------------------------------------------
local HallSignLayer = class("HallSignLayer",function(args)
    local HallSignLayer =  display.newLayer()
    return HallSignLayer
end)

function HallSignLayer:onExit()
    G_event:RemoveNotifyEvent(G_eventDef.NET_CHECKIN_RESULT)
    G_event:RemoveNotifyEvent(G_eventDef.SIGN_CONTINUE_RESULT)
     G_event:RemoveNotifyEvent(G_eventDef.REFRESH_SEVENDAILY)
    
    for k = 1,7 do
        local effectAction = self["mm_EffectGetAction"..k]
        if effectAction then
            effectAction:release()
        end
    end
    -- G_event:RemoveNotifyEvent(G_eventDef.UI_GET_SERVER_TIME)
end

function HallSignLayer:ctor(args)
    self.NoticeNext = args and args.NoticeNext 
    self.HandlerSign = false
    local parent = (args and args.parent) and args.parent or cc.Director:getInstance():getRunningScene()
    parent:addChild(self,ZORDER.POPUP)
    
    local csbNode = g_ExternalFun.loadCSB("signin/SigninLayer.csb")
    self:addChild(csbNode)
    g_ExternalFun.loadChildrenHandler(self,csbNode)
    ShowCommonLayerAction(self.mm_bg,self.mm_content)
    self.mm_bg:onClicked(handler(self,self.onClickClose),true)
    self.mm_btnClose:onClicked(handler(self,self.onClickClose),true)
    local function touchCallBack(event)
        if event.name == "ended" then
            self:onClickContent()
        end
    end
    self.mm_clickTochPanel:setTouchEnabled(true)
    self.mm_clickTochPanel:onTouch(touchCallBack)

    local pDayPath = "client/res/signin/GUI/qd_Dia%d.png"
    local pCoinPath = "client/res/signin/GUI/mrdl_jb%d.png"

    for i=1,7 do
        self["mm_Day"..i]:onClicked(handler(self,self.onSignInClick),true) 
        local pDay = self["mm_EffectDay"..i]:getChildByName("Day")
        pDay:loadTexture(string.format(pDayPath,i),UI_TEX_TYPE_PLIST)  
        pDay:ignoreContentAdaptWithSize(true)
        if i ~= 7 then
            pDay:setPositionY(126 + (i - 1) * 12)
        end
        if not (i==7) then            
            local pCoin = self["mm_EffectDay"..i]:getChildByName("Coin")
            pCoin:ignoreContentAdaptWithSize(true)
            pCoin:loadTexture(string.format(pCoinPath,i),1) 
            pCoin:setAnchorPoint(0.5,0)
            pCoin:setPositionY(-80)
        end
    end  
    --标题效果
    local pEffectTitleCsb = "signin/EffectTitle.csb"    
    local pEffectTitle = g_ExternalFun.loadTimeLine(pEffectTitleCsb)
    pEffectTitle:gotoFrameAndPlay(0, true)
    self.mm_EffectTitle:runAction(pEffectTitle)
    self.mm_vipText:setString(tostring(GlobalUserItem.VIPLevel))
    --光效
    -- local pEffectLightCsb = "signin/EffectLight.csb"    
    -- local pEffectLight = g_ExternalFun.loadTimeLine(pEffectLightCsb)
    -- pEffectLight:gotoFrameAndPlay(0, true)
    -- self.mm_EffectLight:runAction(pEffectLight)
    
    G_event:AddNotifyEvent(G_eventDef.NET_CHECKIN_RESULT,handler(self,self.onCheckResult))   --签到返回结果
    G_event:AddNotifyEvent(G_eventDef.SIGN_CONTINUE_RESULT,handler(self,self.receiveContinue))   --连续签到返回结果
    -- G_event:AddNotifyEvent(G_eventDef.UI_GET_SERVER_TIME,handler(self,self.onGetServerTime))   --获取服务器时间
    G_event:AddNotifyEvent(G_eventDef.REFRESH_SEVENDAILY,handler(self,self.setSevenContinousInfo))   --连续签到得数据
    G_event:AddNotifyEvent(G_eventDef.C_SUB_LOAD_SIGN_CONFIG,handler(self,self.receiveSignConfig))  --获取签到配置
    showNetLoading()
    --查询签到
    
    self.mm_grayPanel:hide()
    self.mm_grayPanel:onClicked(function() 
        local txt = "Ser VIP desbloqueia recompensas de check-in melhores?"     
            local pData = {
                msg = txt,
                callback = function(click)
                    if click == "ok" then 
                        self:onClickClose() 
                        G_ServerMgr:C2S_GetVIPInfo(1)
                    end					
                end
            }
            G_event:NotifyEvent(G_eventDef.UI_OPEN_COMMON_DIALOG,pData)
    end)
    G_ServerMgr:loadSignConfig()
    --查询签到
    G_ServerMgr:C2S_QueryCheckIn()
    self.mm_listView:removeAllChildren()
    self:addBackSpine()
    self:doDisplay()
end

function HallSignLayer:addBackSpine()
    local spine = self:addSpine(self.mm_spineNode,"client/res/spine/SignSevenDay/dengguang.json","client/res/spine/SignSevenDay/dengguang.atlas")
    spine:setAnimation(0, "daiji", true)
    spine:setPosition(cc.p(-10,-20))
end

function HallSignLayer:onSignInClick(target)
    if GlobalData.DailySign ~= 0 then
        G_ServerMgr:doSignDone()        
    else
        --if GlobalUserItem.szSeatPhone and  string.len(GlobalUserItem.szSeatPhone) > 0 then
            --已绑定 打开礼包
            showToast(g_language:getString("sign_tips_2"))
            --local QueryDialog = appdf.req("client.src.UIManager.hall.subinterface.CommonDialog")
            local txt = "Recarregue para desbloquear, gostaria de ir para a recarga?"     --您的话费订单已提交,如您三日内未
            
            local pData = {
                msg = txt,
                callback = function(click)
                    if click == "ok" then     
                        if  GlobalData.ProductsOver and GlobalData.GiftEnable and GlobalData.PayInfoOver and not GlobalData.TodayPay then            
                            local pData = {
                                ShowType = 1,--展示礼包类型：1.首充 2.每日 3.一次性
                                NoticeNext = self.NoticeNext
                            }
                            G_event:NotifyEvent(G_eventDef.UI_SHOW_GIFT_CENTER,pData)
                        end
                        self:removeSelf()
                    end					
                end
            }
            G_event:NotifyEvent(G_eventDef.UI_OPEN_COMMON_DIALOG,pData)
        -- else
        --     --未绑定 打开绑定
        --     showToast(g_language:getString("sign_tips_1"))
        --     G_event:NotifyEvent(G_eventDef.UI_CLIENT_SCENE_AUTH,self.NoticeNext)
        --     self:removeSelf()
        --end
    end
end

--签完返回  
function HallSignLayer:onCheckResult(result)
    dismissNetLoading()
    local int64 = Integer64:new()
    if result.dwErrorCode == 1602 then
        showToast("Hoje já fiz o check-in.")         --今天已签到过了
        return
    elseif result.dwErrorCode == 1603 then
        showToast("Não é permitido fazer o check-in hoje.")         --不允许签到
        return
    elseif result.dwErrorCode == 1604 then
        showToast("A máquina atual excedeu as restrições.")         --当前机器已经超过限制
        return
    elseif result.dwErrorCode == 100 then
        showToast("O usuário não existe ou a senha está incorreta.")         --用户信息不存在或者密码不正确
        return
    else
        
    end


    local lscore = result.llScore
    if GlobalUserItem.bSuccessed == 1 then
        GlobalUserItem.wSeriesDate = GlobalUserItem.wSeriesDate+1
        --非会员标记当日已签到
        if GlobalUserItem.cbMemberOrder == 0 then
            GlobalUserItem.setTodayCheckIn()
        end
    end

    if GlobalUserItem.bSuccessed ~= 1 then
        showToast(g_language:getString(104))
        self:onClickClose(self.mm_btnClose)
        return 
    end 
    self["mm_Day"..GlobalUserItem.wSeriesDate]:setTouchEnabled(false)
    local canReceive = self["mm_Day"..GlobalUserItem.wSeriesDate]:getChildByName("canReceive")  
    canReceive:hide()
    if self.canlingQuSpine then
        self.canlingQuSpine:hide()
    end
    self.HandlerSign = false
    -- self["mm_Light_"..GlobalUserItem.wSeriesDate]:hide()  
    -- self["mm_Got_"..GlobalUserItem.wSeriesDate]:show()
    if self["mm_EffectGetAction"..GlobalUserItem.wSeriesDate] then
        self["mm_EffectGetAction"..GlobalUserItem.wSeriesDate]:play("animation0",false)
    end

    if self["mm_EffectGet"..GlobalUserItem.wSeriesDate] then
        self["mm_EffectGet"..GlobalUserItem.wSeriesDate]:runAction(self["mm_EffectGetAction"..GlobalUserItem.wSeriesDate])
    end

    if self["mm_EffectDayAction"..GlobalUserItem.wSeriesDate] then
        self["mm_EffectDayAction"..GlobalUserItem.wSeriesDate]:play("animation0",true)
    end

    local imagePath = "client/res/signin/GUI/mrdl_jb"..GlobalUserItem.wSeriesDate..".png"
    self:showAward(lscore,imagePath)
    -- local continuousSevenSign = GlobalUserItem.continuousSevenSign
    -- continuousSevenSign.wSeriesDays = continuousSevenSign.wSeriesDays + 1
    G_ServerMgr:C2S_QueryCheckIn()                  --再获取一下签到信息
end

function HallSignLayer:onClickClose(target)
    -- local flag = target == self.mm_btnClose
    -- if not flag and self.HandlerSign then
    --     self:onSignInClick()
    --     return
    -- end
    DoHideCommonLayerAction(self.mm_bg,self.mm_content,function()         
        if self.NoticeNext then
            G_event:NotifyEvent(G_eventDef.UI_CLIENT_SCENE_NOTICE,{NoticeName="HallSign"})
        end
        self:removeSelf() 
    end)
end

function HallSignLayer:onClickContent()
    if self.HandlerSign then
        self:onSignInClick()
        return
    end
end

--签到状态返回
function HallSignLayer:setSevenContinousInfo()
    --self:selectLeft(self._lastLeftIndex)
    if not self._lastLeftIndex then
        return
    end
    self:setRightInfo(self._lastLeftIndex)
end

function HallSignLayer:addIconSpine(icon)
    icon:onClicked(function() 
        showNetLoading()
        G_ServerMgr:takeContinueSign(icon._index)           --点击连续领奖
        self._onClickIndex = icon._index
    end)
    if icon._spine then
        icon._spine:show()
        return
    end
    icon._spine = self:addSpine(icon,"client/res/spine/SignSevenDay/kelingqu.json","client/res/spine/SignSevenDay/kelingqu.atlas")
    icon._spine:setAnimation(0,"daiji", true)
    icon._spine:setPosition(cc.p(icon:getContentSize().width/2,icon:getContentSize().height/2))
end

--连续签到领奖返回结果
function HallSignLayer:receiveContinue(pData)
    dismissNetLoading()
    local int64 = Integer64:new()
    local result = {
        dwErrorCode = pData:readdword(),                 -- 错误码
        llScore = pData:readscore(int64):getvalue()      -- 连续签到获取到的奖励分数
    }
    if result.dwErrorCode == 1601 then
        printf("连续签到天数不足以领取奖励")
        showToast(g_language:getString(104))
        return
    end

    local llScore = result.llScore
    local imagePath = "client/res/signin/GUI/mrdl_jd"..(self._onClickIndex + 2)..".png"
    self:showAward(llScore,imagePath)
    local continuousSevenSign = GlobalUserItem.continuousSevenSign
    continuousSevenSign.cbSeriesAllow[self._onClickIndex] = 0     --是否有可领取连续签到的奖励
    self:setRightInfo(self._lastLeftIndex)
end

function HallSignLayer:showAward(goldTxt,imagePath)
    local path = "client.src.UIManager.hall.subinterface.rewardLayer"
    local data = {}
    data.goldImg = imagePath
    data.goldImgPlistType = 1
    data.goldTxt = g_format:formatNumber(goldTxt,g_format.fType.standard)
    data.type = 1
    appdf.req(path).new(data)
end

function HallSignLayer:addSpine(parentNode,jsonPath,atlasPath)
    local spine = sp.SkeletonAnimation:createWithJsonFile(jsonPath,atlasPath, 1)        
    spine:addTo(parentNode)
    return spine
end

function HallSignLayer:doDisplay()
    self._lastLeftIndex = nil
    self.mm_clonePanel:hide()
    self.mm_listView:setScrollBarEnabled(false)
    for k = 1,21 do
        local item = self.mm_clonePanel:clone()
        item:show()
        self.mm_listView:pushBackCustomItem(item)
        local cloneBg = item:getChildByName("cloneBg")
        local cloneVip = item:getChildByName("cloneVip")
        local cloneFnt = item:getChildByName("cloneFnt")
        cloneFnt:setString(tostring(k - 1))
        item._tag = k - 1
        item:addTouchEventListener(function(sender,eventType) 
            if eventType == ccui.TouchEventType.began then
                sender:runAction(cc.ScaleTo:create(0.14,0.96))
            elseif eventType == ccui.TouchEventType.canceled then
                sender:runAction(cc.ScaleTo:create(0.14,1))
            elseif eventType == ccui.TouchEventType.ended then
                sender:runAction(cc.ScaleTo:create(0.14,1))
                if self._lastLeftIndex == (k - 1) then return end
                self:selectLeft(k - 1)
            end
        end)
        item._cloneBg = cloneBg
        item._cloneVip = cloneVip
        item._cloneFnt = cloneFnt
    end
    
end

function HallSignLayer:selectLeft(tag)
    local tag = tag
    local children = self.mm_listView:getChildren()
    for k = 1,#children do
        local child = children[k]
        local cloneBg = child._cloneBg
        local cloneVip = child._cloneVip
        local cloneFnt = child._cloneFnt
        if child and child._tag == tag then
            cloneBg:loadTexture("client/res/signin/GUI/leftPng/mrdl_vipan2.png",1)
            cloneVip:loadTexture("client/res/signin/GUI/leftPng/mrdl_vipwz2.png",1)
            cloneFnt:setFntFile("client/res/signin/GUI/leftPng/mrdl_sz1.fnt")
            cloneBg:setContentSize(cc.size(276,126))
        elseif child and child._tag == self._lastLeftIndex then
            cloneBg:loadTexture("client/res/signin/GUI/leftPng/mrdl_vipan1.png",1)
            cloneVip:loadTexture("client/res/signin/GUI/leftPng/mrdl_vipwz1.png",1)
            cloneFnt:setFntFile("client/res/signin/GUI/leftPng/mrdl_sz2.fnt")
            cloneBg:setContentSize(cc.size(270,120))
        end
    end
    self._lastLeftIndex = tag
    self:setRightInfo(tag)
end

--获取签到配置返回
function HallSignLayer:receiveSignConfig(pData)
    dismissNetLoading()
    if pData:getlen() ~= 2016 then
        printf("包长不正确")
        return
    end
    local result = {}
    local int64 = Integer64:new()
    for i=1,21 do
        local lNormalRewardGold = {}    -- 普通签到配置
        local lSerialRewardGold = {}    -- 连续签到配置
        for j=1,7 do
            table.insert(lNormalRewardGold, pData:readscore(int64):getvalue())
        end
        for k=1,4 do
            table.insert(lSerialRewardGold, {
                days = pData:readword(),
                score = pData:readscore(int64):getvalue()
            })
        end
        result[i] = {lNormalRewardGold = lNormalRewardGold, lSerialRewardGold = lSerialRewardGold }
    end
    self._signResult = result
    local finishIndex = GlobalUserItem.VIPLevel
    self:selectLeft(finishIndex)
    if finishIndex > 3 then
        local innterSize = self.mm_listView:getInnerContainerSize()
        local size = self.mm_listView:getContentSize()
        local allLong = innterSize.height - size.height
        local curPercent = (finishIndex - 3) * 124 / allLong
        -- 设置滚动偏移量
        self.mm_listView:scrollToPercentVertical(curPercent * 100, 0.5, true)
    end
end

function HallSignLayer:setRightInfo(index)
    index = index + 1
    local info = self._signResult[index]
    if not info then return end
    local lNormalRewardGold = info.lNormalRewardGold
    local lSerialRewardGold = info.lSerialRewardGold

    if (index - 1) == GlobalUserItem.VIPLevel then          --选择的是当前vip
        self:setNowBottomContinueGift(lSerialRewardGold)    
        self:onQuerySignInData(lNormalRewardGold)           --当前签到信息
    else
        self:setBottomGift(lSerialRewardGold)
        self:setSignInData(lNormalRewardGold)   
    end
    if (index - 1) > GlobalUserItem.VIPLevel then
        self.mm_grayPanel:show()
    else
        self.mm_grayPanel:hide()
    end
end

--设置底部礼物
function HallSignLayer:setBottomGift(lSerialCheckInReward)
    for k = 1,#lSerialCheckInReward do
        local info = lSerialCheckInReward[k]
        local llScore = info.score
        local wDays = info.days
        local text = self.mm_textNode:getChildByName("textDay"..k)
        local icon = self.mm_labarBg:getChildByName("icon"..k)
        text:setString(g_format:formatNumber(llScore,g_format.fType.standard,g_format.currencyType.GOLD))
        icon._index = k
        icon:onClicked(nil)
        if icon._spine then
            icon._spine:hide()
        end  
        icon:setTouchEnabled(false)
        icon:setColor(cc.c3b(255,255,255))
    end
    self.mm_dayLoadBar:setPercent(0)
    self.mm_dayText:setString("0")
    if self.receivedSpineNode then 
        self.receivedSpineNode:hide() 
    end
end

--设置当前底部连续签到奖励
function HallSignLayer:setNowBottomContinueGift(lSerialCheckInReward)
    local continuousSevenSign = GlobalUserItem.continuousSevenSign
    local wSeriesDays = continuousSevenSign.wSeriesDays         --连续签到天数
    local cbSeriesAllow = continuousSevenSign.cbSeriesAllow     --是否有可领取连续签到的奖励
    -- local lSerialCheckInReward = continuousSevenSign.lSerialCheckInReward   --连续签到奖励
    local barWidth = self.mm_labarBg:getContentSize().width
    local icon1 = self.mm_labarBg:getChildByName("icon1")
    local maxValue1 = (icon1:getPositionX() / barWidth) * 100
    local icon2 = self.mm_labarBg:getChildByName("icon2")
    local maxValue2 = (icon2:getPositionX() / barWidth) * 100
    local icon3 = self.mm_labarBg:getChildByName("icon3")
    local maxValue3 = (icon3:getPositionX() / barWidth) * 100
    local icon4 = self.mm_labarBg:getChildByName("icon4")
    local maxValue4 = 100
    local day1 = 10
    local day2 = 15
    local day3 = 20
    local day4 = 30
    if wSeriesDays <= day1 then
        self.mm_dayLoadBar:setPercent(wSeriesDays / day1 * maxValue1)
    elseif wSeriesDays <= day2 then
        self.mm_dayLoadBar:setPercent((wSeriesDays - day1) / (day2 - day1) * (maxValue2 - maxValue1) + maxValue1)
    elseif wSeriesDays <= day3 then
        self.mm_dayLoadBar:setPercent((wSeriesDays - day2) / (day3 - day2) * (maxValue3 - maxValue2) + maxValue2)
    elseif wSeriesDays <= day4 then
        self.mm_dayLoadBar:setPercent((wSeriesDays - day3) / (day4 - day3) * (maxValue4 - maxValue3) + maxValue3)
    end

    self.mm_dayText:setString(wSeriesDays)
    if self.receivedSpineNode then 
        self.receivedSpineNode:hide() 
    end

    for k = 1,#lSerialCheckInReward do
        local info = lSerialCheckInReward[k]
        local llScore = info.score
        local wDays = info.days
        local text = self.mm_textNode:getChildByName("textDay"..k)
        local icon = self.mm_labarBg:getChildByName("icon"..k)
        text:setString(g_format:formatNumber(llScore,g_format.fType.standard,g_format.currencyType.GOLD))
        icon._index = k
        icon:onClicked(nil)
        if icon._spine then
            icon._spine:hide()
        end  
        if wSeriesDays >= wDays then                 --如果签到超过了当前天
            if cbSeriesAllow[k] ~= 0 then                --如果还没领取
                icon:setTouchEnabled(true)
                icon:setColor(cc.c3b(255,255,255))
                self:addIconSpine(icon)
            else
                icon:setTouchEnabled(false)
                icon:setColor(cc.c3b(159,159,159))
            end
        else                                    
            if cbSeriesAllow[k] ~= 0 then                --如果可以领取
                self:addIconSpine(icon)
            end
            icon:setTouchEnabled(true)
            icon:setColor(cc.c3b(255,255,255))
        end
    end
end

function HallSignLayer:setSignInData(lNormalRewardGold)
    local lRewardGold = lNormalRewardGold

    for i,v in ipairs(lRewardGold) do
        local formatMoney = g_format:formatNumber(v,g_format.fType.standard,g_format.currencyType.GOLD)
        self["mm_EffectDay"..i]:getChildByName("Value"):setString(formatMoney)
        self["mm_Day"..i]:setTouchEnabled(false) 
        local canReceive = self["mm_Day"..i]:getChildByName("canReceive")     
        canReceive:hide()  
        if self["mm_EffectGetAction"..i] then
            self["mm_EffectGet"..i]:stopAllActions()
            self["mm_EffectGet"..i]:hide()
            self["mm_EffectGetAction"..i]:release()
            self["mm_EffectGetAction"..i] = nil
        end
    end
    if self.canlingQuSpine then
        self.canlingQuSpine:hide()
        self.canlingQuSpine:removeFromParent()
        self.canlingQuSpine = nil
    end
end 

function HallSignLayer:onQuerySignInData(lNormalRewardGold)
    local series = GlobalUserItem.wSeriesDate  --连续日期
	local today = GlobalUserItem.bTodayChecked 	--今日签到
    -- dump(GlobalUserItem.lRewardGold,"GlobalUserItem.lRewardGold",5)
    local lRewardGold = lNormalRewardGold
    self.HandlerSign = false
    for i,v in ipairs(lRewardGold) do
        local formatMoney = g_format:formatNumber(v,g_format.fType.standard,g_format.currencyType.GOLD)
        self["mm_EffectDay"..i]:getChildByName("Value"):setString(formatMoney)
        self["mm_Day"..i]:setTouchEnabled(false) 
        local canReceive = self["mm_Day"..i]:getChildByName("canReceive")     
        canReceive:hide()  
        if self["mm_EffectGetAction"..i] then
            self["mm_EffectGet"..i]:stopAllActions()
            self["mm_EffectGet"..i]:hide()
            self["mm_EffectGetAction"..i]:release()
            self["mm_EffectGetAction"..i] = nil
        end

        self["mm_EffectGetAction"..i] = g_ExternalFun.loadTimeLine("signin/EffectGet.csb")
        self["mm_EffectGetAction"..i]:retain()
        self["mm_EffectGetAction"..i]:play("animation1",true)
        if i < (series+1) then
            --历史前面签过的             
            self["mm_EffectGet"..i]:runAction(self["mm_EffectGetAction"..i])
            self["mm_EffectGet"..i]:show()
        end

        -- if i==7 then
        --     self["mm_EffectGet"..i]:getChildByName("Mask"):setContentSize(cc.size(301,633))
        -- end

        local pFlag = false
        if (today == 0) and (i == series+1) then     
            --没签  and  今天
            self["mm_Day"..i]:setTouchEnabled(true) 
            self.HandlerSign = true           
            pFlag = true
            local size = self["mm_Day"..i]:getContentSize()
            if not self.canlingQuSpine then
                self.canlingQuSpine = self:addSpine(self["mm_Day"..i],"client/res/spine/SignSevenDay/xuanzhekuan.json","client/res/spine/SignSevenDay/xuanzhekuan.atlas")          
                self.canlingQuSpine:setAnimation(0,tostring(i), true)
                self.canlingQuSpine:setPosition(cc.p(size.width/2,size.height/2))
            end
            canReceive:show()
        end
        
        
        if self["mm_EffectDayAction"..i] then
            self["mm_EffectDay"..i]:stopAllActions()
        end
        if (i==3 or i==7) then
            self["mm_EffectDayAction"..i] = g_ExternalFun.loadTimeLine(string.format("signin/EffectDay%d.csb",i))            
        else
            self["mm_EffectDayAction"..i] = g_ExternalFun.loadTimeLine("signin/EffectDayNormal.csb")            
        end
        if pFlag then
            self["mm_EffectDayAction"..i]:play("animation1",true)
         --   self["mm_Day"..i]:setLocalZOrder(100)
        else
            self["mm_EffectDayAction"..i]:play("animation0",true)
          --  self["mm_Day"..i]:setLocalZOrder(1)
        end
        self["mm_EffectDay"..i]:runAction(self["mm_EffectDayAction"..i])
    end
end


return HallSignLayer

