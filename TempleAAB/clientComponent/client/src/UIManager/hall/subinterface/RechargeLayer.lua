---------------------------------------------------
--Desc:商城界面
--Date:2022-09-23 16:01:47
--Author:A*
---------------------------------------------------
local EventPost = appdf.req(appdf.CLIENT_SRC.."Tools.EventPost")
local RechargeLayer = class("RechargeLayer",function(args)
	local RechargeLayer =  display.newLayer()
    return RechargeLayer
end)
function RechargeLayer:onExit()
     G_event:RemoveNotifyEventTwo(self,G_eventDef.NET_PRODUCTS_STATE_RESULT) 
    -- G_event:RemoveNotifyEventTwo(self,G_eventDef.NET_PAY_URL_RESULT)   
     G_event:RemoveNotifyEventTwo(self,G_eventDef.EVENT_HALL_BET_SCORE_DATA)  
    G_event:RemoveNotifyEvent(G_eventDef.NET_GET_PRODUCT_EXTEND_FLAG)
    G_event:RemoveNotifyEventTwo(self,G_eventDef.NET_PRODUCTS_RESULT)
    --查询充值信息
    G_ServerMgr:C2S_GetLastPayInfo() 
end

function RechargeLayer:ctor(args)
    local parent = (args and args.parent) and args.parent or cc.Director:getInstance():getRunningScene()
    parent:addChild(self)    
    self.quitCallback = args.quitCallback
    local csbNode = g_ExternalFun.loadCSB("recharge/RechargeLayer.csb")
    csbNode:setContentSize(display.width,display.height)
    csbNode:setAnchorPoint(cc.p(0.5,0.5))
    csbNode:setPosition(display.cx,display.cy)
    self:addChild(csbNode)    
    g_ExternalFun.loadChildrenHandler(self,csbNode)
    g_ExternalFun.adapterScreen(self.mm_bg)
    --左上
    self.PanelLeftTop = self.mm_PanelLeftTop
    --左中
    self.PanelLeftCenter = self.mm_PanelLeftCenter
    --右中
    self.PanelRightCenter = self.mm_PanelRightCenter  
    self.mm_Tips:hide()

    self._nowChannel = GlobalData.payChannelList[1].dwChannelID         --渠道
    self._MoneyModel = 0                    --钱包模式
    
    self._isLoading = false
    ccui.Helper:doLayout(csbNode)

    self.mm_btnBack:onClicked(function() 
        local callback = function()
            if self.quitCallback then
                self.quitCallback()
            end
            self:removeSelf()
        end
        self:EaseHide(callback)
    end,true)

    local skeletonNode = sp.SkeletonAnimation:create("client/res/spine/Recharge/renwu_1.json", "client/res/spine/Recharge/renwu_1.atlas", 1)
    skeletonNode:addAnimation(0, "ruchang", false)    
    self.mm_NodeAvatar:addChild(skeletonNode)
    skeletonNode:registerSpineEventHandler( function( event )
        if event.animation == "ruchang" then
            skeletonNode:addAnimation(0, "daiji", true)  
        end
    end, sp.EventType.ANIMATION_COMPLETE)   
    skeletonNode:setMix("ruchang","daiji",0.2)            --动画过渡

    local skeletonNode = sp.SkeletonAnimation:create("client/res/spine/Recharge/shagncheng_2.json", "client/res/spine/Recharge/shagncheng_2.atlas", 1)
    skeletonNode:addAnimation(0, "daiji", true)    
    self.mm_spineBackGround:addChild(skeletonNode)

    for i = 1,10 do
        local item = self["mm_item"..i]
        item:setOpacity(0)
    end
    --礼包中心
   -- local pAction = g_ExternalFun.loadTimeLine("Lobby/Entry/NodeGift.csb")
    -- local pSpine = self.mm_NodeGift:getChildByName("spine_1") 
    -- self.NodeGiftPercentBg = self.mm_NodeGift:getChildByName("wordBg")
    -- self.NodeGiftPercentBg:hide()
    -- self.NodeGiftPercent = self.NodeGiftPercentBg:getChildByName("libaorukou_6_3"):getChildByName("word_1")
    
    -- local pSpineEffect = sp.SkeletonAnimation:create("spine/lingbaotubiao.json","spine/lingbaotubiao.atlas", 1)
    -- pSpineEffect:addTo(pSpine)
    -- pSpineEffect:setPosition(0, 0)
    -- pSpineEffect:setAnimation(0, "daiji", true)
    -- pAction:gotoFrameAndPlay(0, true)
    -- self.mm_NodeGift:runAction(pAction)
    -- self.mm_NodeGift:getChildByName("Button_1"):onClicked(function()          
    --     self:EaseHide(function()
    --         if self.quitCallback then
    --             self.quitCallback()
    --             local pData = {
    --                 ShowType = 1,--展示礼包类型：1.首充 2.每日 3.一次性
    --             }
    --             G_event:NotifyEvent(G_eventDef.UI_SHOW_GIFT_CENTER,pData)
    --         end
    --         self:removeSelf()
    --     end)
    -- end)
    -- self.mm_NodeGift:setVisible(GlobalData.GiftEnable)

    self:EaseShow()   
        
    G_event:AddNotifyEventTwo(self,G_eventDef.NET_PRODUCTS_STATE_RESULT,handler(self,self.onProductsStateResult))   --同步商品表状态结果
    -- G_event:AddNotifyEventTwo(self,G_eventDef.NET_PAY_URL_RESULT,handler(self,self.onPayUrlResult))                  --支付URL返回
    G_event:AddNotifyEventTwo(self,G_eventDef.EVENT_HALL_BET_SCORE_DATA,handler(self,self.onGetRechargeScoreResult))   --当日购买额返回监听
    G_event:AddNotifyEvent(G_eventDef.NET_GET_PRODUCT_EXTEND_FLAG,handler(self,self.onGetProductExtendFlagResult))   --获取商城商品扩展标识
    G_event:AddNotifyEvent(G_eventDef.CMD_MB_PlacePayOrderResult,handler(self,self.onPlacePayOrderResult))   --下单结果
    G_event:AddNotifyEventTwo(self,G_eventDef.NET_PRODUCTS_RESULT,handler(self,self.ProductsResult))     --完成商品列表拉取事件
    

    --请求当日购买状态
    local pType = 1--2
    -- if ylAll.ProjectSelect and ylAll.ProjectSelect==2 then
    --     pType = 1
    -- end
    showNetLoading(nil,3)  
    self:setSelectPanel()
end

--缓入
function RechargeLayer:EaseShow(callback)
    local pCostTime = 0.3
    local pDeltaTime = 0.08    
    --左中
    local pSize = self.PanelLeftCenter:getContentSize()
    self.PanelLeftCenter:setPositionX(-pSize.width)
    TweenLite.to(self.PanelLeftCenter,pCostTime,{ x=0,ease = Cubic.easeInOut,onComplete =callback})
    --右中
    --self.PanelRightCenter:setPositionX(display.width+2560/2)    
   -- TweenLite.to(self.PanelRightCenter,pCostTime/2,{ x=781,ease = Cubic.easeInOut,onComplete =callback})
end

--缓出
function RechargeLayer:EaseHide(callback)    
    local pCostTime = 0.3
    local pDeltaTime = 0.08    
   
    --左中
    local pSize = self.PanelLeftCenter:getContentSize()
    TweenLite.to(self.PanelLeftCenter,pCostTime,{ x=-pSize.width,ease = Cubic.easeInOut,onComplete =callback})
    for i = 1,10 do
        local item = self["mm_item"..i]
        local initPosition = cc.p(item:getPosition())
        local delayTime = (math.ceil(i / 2) - 1) * (2/30)
        local array = {
            cc.DelayTime:create(delayTime),
            cc.Spawn:create(
                cc.FadeOut:create(1/5),
                cc.EaseQuinticActionOut:create(cc.MoveTo:create(1/5,cc.p(initPosition.x + 1560,initPosition.y)))
            )
        }
        item:runAction(cc.Sequence:create(array))    
    end
    --右中
   -- TweenLite.to(self.PanelRightCenter,pCostTime,{ x=display.cx+2560,ease = Cubic.easeInOut,onComplete =callback})    
    --表皮
   -- TweenLite.to(self.PanelPre,pCostTime,{ x=display.cx+2560,ease = Cubic.easeInOut,onComplete =callback})    
end

--商品列表返回
function RechargeLayer:ProductsResult()
    G_ServerMgr:C2S_GetBetScore(1)
    --获取商城商品扩展标识
    G_ServerMgr:C2S_GetProductExtendFlag(self._nowChannel)
end

function RechargeLayer:onGetRechargeScoreResult(pData)
    self.TodayRecharge = pData.TodayRechargeScore > 0
end

function RechargeLayer:onGetProductExtendFlagResult(pData)
    dump(pData)
    local configData = self:getShopList() 
    if #configData <= 0 then
        return
    end
    --0表示 没有角标，为1表示有
    for i = 1,10 do
        local item = self["mm_item"..i]
        local Image_hot = item:getChildByName("Image_hot")
        Image_hot:hide()
        local extraGain = item:getChildByName("extraGain")
        extraGain:hide()
        local extraText = extraGain:getChildByName("extraText")
        extraText:setScale(1.1)
        local size = extraGain:getContentSize()
        local pItem = self.ListData.ProductInfos[i]
        local dwProductID = pItem.dwProductID
        if pData and pData.lsItems then
            local dwExtendFlag = pData.lsItems[dwProductID] or 0 --为0表示 没有角标，为1表示有
            if dwExtendFlag == 1 then
                Image_hot:setVisible(true)
            end
        end
        for m,p in pairs(configData) do
            if p and p.dwProductID == dwProductID then
                local byAttachType = p.byAttachType
                local lAttachValue = p.lAttachValue
                if tonumber(lAttachValue) ~= 0 then
                    extraGain:show()
                    if byAttachType == 1 then               --定值
                        local formatStr = g_format:formatNumber(lAttachValue,g_format.fType.abbreviation,g_format.currencyType.GOLD)
                        extraText:setString("+"..formatStr)
                    elseif byAttachType == 2 then           --百分比
                        lAttachValue = p.dwPrice*lAttachValue/100
                        -- if (lAttachValue % 100) ~= 0 then               --不能被100整除
                        --     local formatStr = g_format:formatNumber(lAttachValue,g_format.fType.abbreviation,g_format.currencyType.GOLD)
                        --     extraText:setString("+"..formatStr)
                        -- else
                        --     extraText:setString("+"..(lAttachValue / 100))
                        -- end
                        local formatStr = g_format:formatNumber(lAttachValue,g_format.fType.abbreviation,g_format.currencyType.GOLD)
                        extraText:setString("+"..formatStr)
                    end
                    local textSize = extraText:getContentSize()
                    if textSize.width > (size.width - 60) then
                        extraText:setScale((size.width - 60)/textSize.width)
                    end
                end
                break
            end
        end
    end
end

function RechargeLayer:onProductsStateResult()
    dismissNetLoading()
    local configData = self:getShopList() 
    if configData == nil then 
        print("获取商城商品信息异常")
        self.mm_noDataText:show()
        return 
    end

    if #configData <= 0 then
        self.mm_noDataText:show()
    else
        self.mm_noDataText:hide()
    end
    
    local goldTable = {}
    for i=1,10 do
        if configData[i] then
            goldTable[i] = {}
            goldTable[i].index = i
            goldTable[i].gold = configData[i].lAwardValue
            goldTable[i].price = configData[i].dwPrice
        end
    end
    -- table.sort(goldTable,function(a,b)
    --     return a.gold < b.gold
    -- end)

    local imageTable = {}
    for i=1,10 do
        if goldTable[i] then
            imageTable[goldTable[i].index] = "client/res/recharge/GUI2/xsc_jb"..i..".png"
        end
        local item = self["mm_item"..i]
        item:hide()
    end

    for i = 1,10 do
        if goldTable[i] then
            local item = self["mm_item"..i]
            item:show()
            local txtCoin_1 = item:getChildByName("txtCoin_1")
            local btnPay = item:getChildByName("btnPay")
            local txtMoney_1 = btnPay:getChildByName("txtMoney_1")
            local Image_gold_1 = item:getChildByName("Image_gold_1")
            local btnPay_1 = item:getChildByName("btnPay_1")
            txtMoney_1:setScale(1)
            txtCoin_1:setString(g_format:formatNumber(goldTable[i].gold,g_format.fType.abbreviation,g_format.currencyType.GOLD))
            local formatStr = string.format("R$ %.2f",goldTable[i].price/100)
            formatStr = string.gsub(formatStr,"%.",",")
            txtMoney_1:setString(formatStr)
            btnPay_1:setTag(goldTable[i].index)
            btnPay_1:onClickEnd(function() self:onGoodBuyClick(btnPay_1) end,true)
            btnPay:setTag(goldTable[i].index)
            btnPay:onClickEnd(function() self:onGoodBuyClick(btnPay_1) end,true)
            Image_gold_1:ignoreContentAdaptWithSize(true)
            Image_gold_1:loadTexture(imageTable[i],1)
            local initPosition = cc.p(item:getPosition())
            item:setPositionX(initPosition.x + 1560)
            item:setOpacity(0)
            local delayTime = (math.ceil(i / 2) - 1) * (2/30)
            local array = {
                cc.DelayTime:create(delayTime),
                cc.Spawn:create(
                    cc.FadeIn:create(1/5),
                    cc.EaseQuinticActionOut:create(cc.MoveTo:create(1/5,initPosition))
                )
            }
            item:runAction(cc.Sequence:create(array))
        end
    end

    local pValue = 0
    for i, v in ipairs(GlobalData.ProductInfos) do
        if v.byActive and v.szProductTypeName ~= "shop" then
            for i2, v2 in ipairs(v.ProductInfos) do
                if v2.byAttachType == 2 then
                    local pC = nil
                    if i==3 then
                        if GlobalData.ProductOnceState[i2] then
                            pC = v2
                        end
                    else
                        pC = v2
                    end
                    if pC and pC.lAttachValue > pValue then
                        pValue = pC.lAttachValue
                    end                    
                end
            end
        end
    end
    -- if pValue == 0 then
    --     self.NodeGiftPercentBg:hide()
    --     self.NodeGiftPercent:setString("")
    -- else
    --     self.NodeGiftPercentBg:show()
    --     self.NodeGiftPercent:setString("+"..pValue.."%")
    -- end
end

function RechargeLayer:getShopList()
    for k,v in pairs(GlobalData.ProductInfos) do
        if v.szProductTypeName == "shop" then
            self.ListData = v
            return v.ProductInfos
        end
    end
    return nil
end

function RechargeLayer:isTodayFirstThreshold()
    --判断系统消息显示是否当天第一次
    local pKey = "TodayFirstThreshold_"..GlobalUserItem.dwUserID
    local pLastThresholdTime = cc.UserDefault:getInstance():getIntegerForKey(pKey,0)
    local pDate = os.date("*t",pLastThresholdTime)
    local pToday = os.date("*t",os.time())
    --判定是否跨天
    if pToday.year ~= pDate.year or pToday.month ~= pDate.month or pToday.day ~= pDate.day then
        cc.UserDefault:getInstance():setIntegerForKey(pKey,os.time())
        cc.UserDefault:getInstance():flush()
        return true
    else
        return false
    end
end

function RechargeLayer:onGoodBuyClick(target)        
    local pIndex = target:getTag()   
    local pItem = self.ListData.ProductInfos[pIndex]

    local pValue = pItem.lAwardValue
    if pItem.byAttachType == 1 then
        --附加定值
        pValue = pValue + pItem.lAttachValue
    elseif pItem.byAttachType == 2 then
        --附加百分比
        pValue = pValue*(1 + pItem.lAttachValue)
    end    
    local imagePath = "client/res/recharge/GUI2/xsc_jb"..pIndex..".png"

    --订单记录
    ylAll.firstData = {}
    ylAll.firstData.isopen = true
    ylAll.firstData.bankMoney = GlobalUserItem.lUserInsure
    ylAll.firstData.curPayMoney = pValue
    ylAll.firstData.imagePath = imagePath
    ylAll.firstData.dwProductID = pItem.dwProductID
    ylAll.firstData.dwPrice = pItem.dwPrice
    local params = {
        productId = pItem.dwProductID,
        price = pItem.dwPrice,
        name = encodeURI(GlobalUserItem.szNickName),
    }
    local pExtends = {
        WalletType = "",--钱包类型
        WalletNumber= pWalletNumber,--钱包号码
        WalletHolder= "",--钱包持有人
        IDNumber="",
        TokenApp= GlobalData.AppToken,--Adjust 应用token
        TokenCZ= GlobalData.RevenueToken,--充值事件
        TokenSC= GlobalData.FirstRevenueToken,--首充事件
        TokenTX= "",--提现事件
        TokenCTC= GlobalData.DWDifferenceToken,--充提差事件
        Currency= "BRL",--货币类型
        DevType= "gps_adid",
        DevID= GlobalData.GoogleADID,
        PayChannelID = self._nowChannel,
        MoneyModel = self._MoneyModel
    }
    dump(pExtends)
    local pResult = ""
    local isFirst = true
    for k, v in pairs(pExtends) do
        if v and string.len(v)>0 then
            if isFirst then
                isFirst = false
                pResult = pResult..k.."="..v
            else
                pResult = pResult.."&"..k.."="..v
            end
        end
    end
    print("pExtends = ",pResult)
    params.extends = pResult --extends:超级扩展字段。
    G_ServerMgr:C2S_CMD_MB_PlacePayOrder(params)
    self:showNetLoading()    
    EventPost:addCommond(EventPost.eventType.CLICK,"点击商城商品",pItem.dwProductID)
end

function RechargeLayer:onPlacePayOrderResult(pResult)
    if pResult and pResult.code and pResult.code == 0 then 
        dump(pResult)       
        ylAll.firstData.OrderNo = pResult.orderNo
        --拉单完成，跳转之前，上报充值点击
        g_MultiPlatform:getInstance():threeLogEvent("ad_purchase_click")
        if pResult.timestamp and pResult.orderNo and pResult.qrCode then
            self:showRechargeQrCodeLayer(pResult.timestamp,pResult.orderNo,pResult.qrCode,ylAll.firstData.dwPrice)
        elseif pResult.pay_url then
            OSUtil.openURL(pResult.pay_url)
        end
    else
        local pString = "An exception occurred during recharge, please try again!"
        pString = (pResult and pResult.msg) and pResult.msg or pString
        showToast(pString)
    end
end

-- function RechargeLayer:onGoodBuyClick(target)    
--     print("clickGood os.time() = ",os.time())
--     local pIndex = target:getTag()   
--     local pItem = self.ListData.ProductInfos[pIndex]

--     local pValue = pItem.lAwardValue
--     if pItem.byAttachType == 1 then
--         --附加定值
--         pValue = pValue + pItem.lAttachValue
--     elseif pItem.byAttachType == 2 then
--         --附加百分比
--         pValue = pValue*(1 + pItem.lAttachValue)
--     end
--     self.PayUrl = GlobalData.PayURL
--     local imagePath = "client/res/recharge/GUI2/xsc_jb"..pIndex..".png"

--     local params = {}
--     params.price = pItem.dwPrice
--     params.userId = GlobalUserItem.dwUserID
--     params.productId = pItem.dwProductID
--     params.name = encodeURI(GlobalUserItem.szNickName)
--     params.EventToken = GlobalData.RevenueToken
--     params.EventTokenFirstPay = GlobalData.FirstRevenueToken
--     params.AppToken = GlobalData.AppToken 
--     params.DevType = "gps_adid"
--     params.DevID = GlobalData.GoogleADID
--     params.Currency = "BRL"
--     params.mode = 0
--     dump(params,"=========url")
--     local callback = function(ok,jsonData) 
--         if ok then
--             if jsonData.code == 0 then
--                 print("response os.time() = ",os.time())
--                 dump(jsonData)             
--                 ylAll.firstData = {}
--                 ylAll.firstData.isopen = true
--                 ylAll.firstData.bankMoney = GlobalUserItem.lUserInsure
--                 ylAll.firstData.curPayMoney = pValue
--                 ylAll.firstData.imagePath = imagePath
--                 ylAll.firstData.OrderNo = jsonData.result.orderNo
--                 ylAll.firstData.dwProductID = pItem.dwProductID
--                 --拉单完成，跳转之前，上报充值点击
--                 g_MultiPlatform:getInstance():threeLogEvent("ad_purchase_click")
--                 if jsonData.result.qrCode == ""  then
--                     local scene = cc.Director:getInstance():getRunningScene()
--                     local RechargeQrCodeLayer = scene:getChildByName("RechargeQrCodeLayer")
--                     if RechargeQrCodeLayer then
--                         RechargeQrCodeLayer:removeFromParent()
--                     end                    
--                     OSUtil.openURL(jsonData.result.payUrl)
--                 else
--                     self:showRechargeQrCodeLayer(jsonData.result.timestamp,jsonData.result.orderNo,jsonData.result.qrCode,pItem.dwPrice)
--                 end
--             else
--                 showToast("System error:result content error! (Code:"..jsonData.code.."-Msg:"..jsonData.msg..")")
--             end
--         else
--             showToast(jsonData or "System error happen!")
--         end
--     end
--     g_ExternalFun.onHttpJsonTable(self.PayUrl,"POST",cjson.encode(params),callback)
--     self:showNetLoading()
--     EventPost:addCommond(EventPost.eventType.CLICK,"点击商城商品",pItem.dwProductID)          --点击礼包      --点击礼包 
-- end



--展示最终界面
function RechargeLayer:showRechargeQrCodeLayer(timestamp,orderNo,qrCode,price)
    local scene = cc.Director:getInstance():getRunningScene()
    local RechargeQrCodeLayer = scene:getChildByName("RechargeQrCodeLayer")
    if RechargeQrCodeLayer then
        RechargeQrCodeLayer:doDisplay(timestamp,orderNo,qrCode,price)
    else
        G_event:NotifyEvent(G_eventDef.UI_OPEN_RECHARGECODE,{
            timestamp = timestamp,
            orderNo = orderNo,
            qrCode = qrCode,
            price = price
        })
    end
end

--展示加载界面
function RechargeLayer:showNetLoading()
    local scene = cc.Director:getInstance():getRunningScene()
    local RechargeQrCodeLayer = scene:getChildByName("RechargeQrCodeLayer")
    if RechargeQrCodeLayer then
        return
    end
    G_event:NotifyEvent(G_eventDef.UI_OPEN_RECHARGECODE)
end

function RechargeLayer:setSelectPanel()
    local channelList = GlobalData.payChannelList
    if #channelList <= 1 then
        self.mm_selectPanel:hide()
        G_ServerMgr:C2S_GetProductInfos(self._nowChannel)
        return
    end
    local width = #channelList * 313
    self.mm_selectPanel:setContentSize(cc.size(width + 34,113))
    self.mm_selectListView:setContentSize(cc.size(width,80))
    self.mm_selectListView:setPositionX((width + 34)/2)
    self.mm_selectListView:setScrollBarEnabled(false)
    local selectBtn1 = self.mm_selectPanel:getChildByName("selectBtn1")
    local selectBtn2 = self.mm_selectPanel:getChildByName("selectBtn2")
    local selectBtn3 = self.mm_selectPanel:getChildByName("selectBtn3")
    selectBtn1:hide()
    selectBtn2:hide()
    selectBtn3:hide()
    self.selectBtnList = {}
    for k = 1,#channelList do
        local cloneBtn = nil
        if k == 1 then
            cloneBtn = selectBtn1:clone()
        elseif k == #channelList  then
            cloneBtn = selectBtn2:clone()
        else
            cloneBtn = selectBtn3:clone()
        end 
        table.insert(self.selectBtnList,cloneBtn)
        cloneBtn:show()
        cloneBtn._data = channelList[k]
        local text = cloneBtn:getChildByName("text")
        text:setString(channelList[k].szChannelName)
        self.mm_selectListView:pushBackCustomItem(cloneBtn)
        cloneBtn:onClicked(function() 
            self:selectTopIndex(k)
        end)
    end
    self:selectTopIndex(1)
end

function RechargeLayer:selectTopIndex(index)
    local data = nil
    for k = 1,#self.selectBtnList do
        local btn = self.selectBtnList[k]
        if k == index then
            btn:setEnabled(false)
            btn:setTouchEnabled(false)
            data = btn._data
        else
            btn:setEnabled(true)
            btn:setTouchEnabled(true)
        end
        
    end
    local dwChannelID = data.dwChannelID
    self._nowChannel = dwChannelID
    G_ServerMgr:C2S_GetProductInfos(dwChannelID)
end

return RechargeLayer