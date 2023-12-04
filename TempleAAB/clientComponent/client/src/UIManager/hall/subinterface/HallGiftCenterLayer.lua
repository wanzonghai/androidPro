---------------------------------------------------
--Desc:礼包中心界面
--Date:2022-09-26 15:28:47
--Author:A*
---------------------------------------------------
local EventPost = appdf.req(appdf.CLIENT_SRC.."Tools.EventPost")
local HallGiftCenterLayer = class("HallGiftCenterLayer",function(args)
    local HallGiftCenterLayer =  display.newLayer()
    return HallGiftCenterLayer
end)

HallGiftCenterLayer.GiftTypeConfig = {
    {"first",false},--首充礼包
    {"daily",false},--每日礼包
    {"once",false},--一次性礼包
}

HallGiftCenterLayer.GiftTypePosConfig = {
    cc.p(-54,550),
    cc.p(-44,416),
    cc.p(-34,283),
}

HallGiftCenterLayer.PrePath = "client/res/Gift/"

HallGiftCenterLayer.GiftTipsConfig = {
    "Após realizar qualquer recarga, esta modalidade de presentes desaparece permanentemente.",    
    "Após realizar qualquer recarga, esta modalidade de presentes desaparece hoje.",
    "Cada pacote de presente só pode ser comprado uma vez.",
}

HallGiftCenterLayer.GiftItemCoinPos = {
    {cc.p(185,355),cc.p(190,345),cc.p(170,370)},
    {cc.p(180,355),cc.p(175,360),cc.p(175,360)},
    {cc.p(180,355),cc.p(175,350),cc.p(175,360)},
}

function HallGiftCenterLayer:onExit()    
    -- G_event:RemoveNotifyEventTwo(self,G_eventDef.NET_PRODUCTS_STATE_RESULT)
    -- G_event:RemoveNotifyEventTwo(G_eventDef.NET_GET_PRODUCT_ACTIVE_STATE_RESULT)    
    -- G_event:RemoveNotifyEventTwo(self,G_eventDef.NET_PAY_URL_RESULT)
    --查询充值信息
    G_ServerMgr:C2S_GetLastPayInfo()
    G_event:RemoveNotifyEvent(G_eventDef.RECHARGEBENEFIT)
    G_event:RemoveNotifyEvent(G_eventDef.RECHARGEBENEFIT_INFO)
end

function HallGiftCenterLayer:ctor(args)
    --提前加载合图
    local spriteFrameCache = cc.SpriteFrameCache:getInstance()
    spriteFrameCache:addSpriteFrames("client/res/Gift/GiftPlist.plist", "client/res/Gift/GiftPlist.png")
    -- dump(args)
    local parent = (args and args.parent) and args.parent or cc.Director:getInstance():getRunningScene()
    self:setName("HallGiftCenterLayer")
    parent:addChild(self,ZORDER.POPUP)    
    local csbNode = g_ExternalFun.loadCSB(self.PrePath.."GiftLayer.csb")
    self.csbNode = csbNode
    self:addChild(csbNode)   
    local pEffectTitle = g_ExternalFun.loadTimeLine(self.PrePath.."GiftLayer.csb")
    pEffectTitle:gotoFrameAndPlay(0, true)
    csbNode:runAction(pEffectTitle)
    g_ExternalFun.loadChildrenHandler(self,csbNode)
    ShowCommonLayerAction(self.mm_bg,self.mm_content)
    self.mm_bg:onClicked(handler(self,self.onClickClose),true)
    self.mm_btnClose:onClicked(handler(self,self.onClickClose),true)
    self.mm_content:setPosition(987.04,507.60)
    --礼包类别按钮
    for i = 1, 3 do
        self["mm_btnType"..i]:setTag(i)
        self["mm_btnType"..i]:onClicked(handler(self,self.onGiftTypeClick),true)
        self["mm_btnType"..i]:hide()
    end
    self.tipsPanel = self.mm_content:getChildByName("tipsPanel")
    self.tipsBtn = self.mm_content:getChildByName("tipsBtn")
    self.tipsPanel:hide()
    self.tipsBtn:onClicked(handler(self,self.onTouchTips))
    self.mm_rightPanel:hide()
    --礼包项 模板
    self.mm_Template:hide()    

    --标题效果
    local pEffectTitleCsb = "EffectTitle.csb"    
    local pEffectTitle = g_ExternalFun.loadTimeLine(self.PrePath..pEffectTitleCsb)
    pEffectTitle:gotoFrameAndPlay(0, true)
    self.mm_EffectTitle:runAction(pEffectTitle)

    local ani  = sp.SkeletonAnimation:createWithJsonFile("client/res/Gift/spine/pangmadeng.json","client/res/Gift/spine/pangmadeng.atlas", 1)        
    ani:addTo(self.mm_rightPanel)
    ani:setAnimation(0,"animation",true)
    --ani:setScale(1.42)
    ani:setPosition(cc.p(279,412))
    
    G_event:AddNotifyEventTwo(self,G_eventDef.NET_GET_PRODUCT_ACTIVE_STATE_RESULT,handler(self,self.onProductActiveStateResult))   --同步一次性礼包状态结果
    G_event:AddNotifyEventTwo(self,G_eventDef.NET_PRODUCTS_STATE_RESULT,handler(self,self.onProductsStateResult))   --同步商品表状态结果
    -- G_event:AddNotifyEventTwo(self,G_eventDef.NET_PAY_URL_RESULT,handler(self,self.onPayUrlResult))                  --支付URL返回
    G_event:AddNotifyEvent(G_eventDef.RECHARGEBENEFIT,handler(self,self.receiveGift))
    G_event:AddNotifyEvent(G_eventDef.RECHARGEBENEFIT_INFO,handler(self,self.setRightPanelInfo))
    G_event:AddNotifyEvent(G_eventDef.CMD_MB_PlacePayOrderResult,handler(self,self.onPlacePayOrderResult))   --下单结果
    self.ShowType = args.ShowType or 1    
    self.NoticeNext = args and args.NoticeNext 
    G_ServerMgr:C2S_GetProductTypeActiveState(true)
    G_ServerMgr:requestRechargeBenefit() 
    
end

--刷新返利列表
function HallGiftCenterLayer:refreshRechargeBenefit()
    G_ServerMgr:requestRechargeBenefit() 
end

function HallGiftCenterLayer:onProductsStateResult()
    for i, v in ipairs(self.GiftTypeConfig) do
        for i2, v2 in ipairs(GlobalData.ProductInfos) do
            if v2 and v2.szProductTypeName and v2.szProductTypeName == v[1] then
                v[2] = v2.byActive                
            end
        end    
    end
    local pIndex = 0
    local pShowType = nil
    for i = 1, 3 do
        if self.GiftTypeConfig[i][2] then
            pIndex = pIndex + 1
            self["mm_btnType"..i]:setPosition(self.GiftTypePosConfig[pIndex])
            if pIndex == 1 then
                pShowType = i
            end
        end
        self["mm_btnType"..i]:setVisible(self.GiftTypeConfig[i][2])
    end
    if not self.GiftTypeConfig[self.ShowType][2] then
       self.ShowType = pShowType 
    end
    self:switchGiftType(self.ShowType)
end

--同步一次性商品列表状态结果
function HallGiftCenterLayer:onProductActiveStateResult()
    dismissNetLoading()
    self:refreshGiftList()
end


function HallGiftCenterLayer:onGiftTypeClick(target)
    local pType = target:getTag()    
    self:switchGiftType(pType)
end

function HallGiftCenterLayer:switchGiftType(pType)
    self.ShowType = pType
    for i = 1, 3 do
        self["mm_btnType"..i]:setEnabled(i~=pType)
    end
    self:refreshExtra()
    if self.ShowType and self.ShowType==3 then
        local pTypeName = self.GiftTypeConfig[self.ShowType][1]
        local pID
        for i, v in ipairs(GlobalData.ProductInfos) do
            if v and v.szProductTypeName and v.szProductTypeName == pTypeName then
                pID = v.dwProductTypeID
                break
            end
        end
        if pID then
            G_ServerMgr:C2S_GetProductActiveState(pID)
            showNetLoading()
        end
    else
        self:refreshGiftList()
    end
end

function HallGiftCenterLayer:refreshExtra()
    --标题
    local pTitlePath = string.format(self.PrePath.."GUI/title_%d.png",self.ShowType)        
    local pTitleBg = self.mm_EffectTitle:getChildByName("titleBg")
    local pTitle1 = pTitleBg:getChildByName("titleImage1")
    pTitle1:loadTexture(pTitlePath,ccui.TextureResType.plistType)
    local pTitle2 = pTitleBg:getChildByName("titleImage2")
    pTitle2:loadTexture(pTitlePath,ccui.TextureResType.plistType)
    --顶部彩带
    local pTopCDPath = self.PrePath.."GUI/top_cd_%d.png"
    self.mm_topCD:loadTexture(string.format(pTopCDPath,self.ShowType))    
    --右部彩带
    local pRightCDPath = self.PrePath.."GUI/right_cd_%d.png"
    self.mm_rightCD:loadTexture(string.format(pRightCDPath,self.ShowType),ccui.TextureResType.plistType)
    ccui.Helper:doLayout(self.csbNode)  

    self.mm_bg:setContentSize(display.size)
    --底部文字提示
    -- self.mm_WordTips:setString(self.GiftTipsConfig[self.ShowType])
end

function HallGiftCenterLayer:refreshGiftList()
    -- dump(GlobalData.ProductInfos,"GlobalData.ProductInfos",5)
    self.mm_GiftList:removeAllItems()
    self.mm_GiftList:setScrollBarEnabled(false)
    
    local pListData
    local pTypeName = self.GiftTypeConfig[self.ShowType][1]
    for i, v in ipairs(GlobalData.ProductInfos) do
        if v and v.szProductTypeName and v.szProductTypeName == pTypeName then
            pListData = v
            break
        end
    end   
    local pBgPath = self.PrePath.."GUI/itemBg_"..self.ShowType..".png"
   -- local pDiscountBgPath = self.PrePath.."GUI/saleBg_"..self.ShowType..".png"
    local pCoinPath = "client/res/public/coin_%d_%d.png"  
    for i, v in ipairs(pListData.ProductInfos) do        
        local pItem = self.mm_Template:clone()
        pItem:show()
        --背景图
        pItem:setBackGroundImage(pBgPath,ccui.TextureResType.plistType)  
        --礼包内容图
        local pIconImage = pItem:getChildByName("IconImage")
        pIconImage:loadTexture(string.format(pCoinPath,self.ShowType,i))
        pIconImage:ignoreContentAdaptWithSize(true)
        --原价
        local pAbandonValue = pItem:getChildByName("AbandonValue")
        local pAbandonLine = pItem:getChildByName("AbandonLine")
        pAbandonValue:setString(g_format:formatNumber(v.lAwardValue,g_format.fType.standard,g_format.currencyType.GOLD))        
        pAbandonValue:setVisible(v.lAttachValue>0)
        pAbandonLine:setVisible(v.lAttachValue>0) 
        pAbandonLine:setContentSize(cc.size(pAbandonValue:getContentSize().width*0.6,3))
        --现价
        local pValue = v.lAwardValue
        if v.byAttachType == 1 then
            --附加定值
            pValue = pValue + v.lAttachValue
        elseif v.byAttachType == 2 then
            --附加百分比
            pValue = pValue*(100 + v.lAttachValue)/100
        end
        local pIconValue = pItem:getChildByName("IconValue")
        pIconValue:setString(g_format:formatNumber(pValue,g_format.fType.standard,g_format.currencyType.GOLD))
        --额外
        local pDiscountBg = pItem:getChildByName("DiscountBg")
      --  pDiscountBg:loadTexture(pDiscountBgPath,ccui.TextureResType.plistType)  
        pDiscountBg:setVisible(v.lAttachValue>0) 
        pDiscountBg:setScale(1.4) 
        local bgSize = pDiscountBg:getContentSize()
        local textNode = pDiscountBg:getChildByName("textNode")
        if not textNode then
            textNode = self:getCountTextByNode("client/res/Gift/GUI/lb_gift_%s.png")
            pDiscountBg:addChild(textNode)
            textNode:setName("textNode")
        end
        textNode:setString(string.format("j%sb",v.lAttachValue))
        textNode:setScale(1)
        local size = textNode:getContentSize()
        if size.width > (bgSize.width - 18) then
            textNode:setScale((bgSize.width - 18) / size.width)
            size.width = size.width * (bgSize.width - 18) / size.width
        end
        textNode:setPosition(58.5 - size.width/2,70)
        -- local pDiscountPercent = pDiscountValue:getChildByName("DiscountPercent")
        -- pDiscountPercent:setVisible(v.byAttachType==2)
        -- pDiscountPercent:setPositionX(pDiscountValue:getContentSize().width)
        --购买按钮 
        local pButtonPay = pItem:getChildByName("ButtonPay")
        pButtonPay:setTag(i)
        pButtonPay:onClicked(handler(self,self.onGiftBuyClick),true)
        --按钮金额
        local pPriceValue = pButtonPay:getChildByName("PriceValue")
        local formatStr = string.format("%.2f",v.dwPrice/100)
        formatStr = string.gsub(formatStr,"%.",",")
        pPriceValue:setString(formatStr)
        if self.ShowType==3 then
            local pFlag = GlobalData.ProductOnceState[i]== 1
            local pColor = pFlag and cc.c3b(255,255,255) or cc.c3b(191,191,191)
            pItem:setColor(pColor)
            pButtonPay:setTouchEnabled(pFlag)
            if pFlag then
                self.mm_GiftList:pushBackCustomItem(pItem)
            end
        else
            self.mm_GiftList:pushBackCustomItem(pItem)    
        end
    end
    local pChildren = self.mm_GiftList:getItems()
    local pCount = #pChildren
    
    if pChildren and pCount and pCount>0 then
        if pCount > 3 then
            self.mm_GiftList:setTouchEnabled(true)
            self.mm_LeftTips:show()
            self.mm_RightTips:show()
        else
            self.mm_GiftList:setTouchEnabled(false)
            self.mm_LeftTips:hide()
            self.mm_RightTips:hide()
        end
        pCount = pCount > 3 and 3 or pCount
        self.mm_GiftList:setContentSize(cc.size((pCount*358+(pCount-1)*5),565))
    end 
    self.ListData = pListData
    self.mm_GiftList:show()
end

function HallGiftCenterLayer:onGiftBuyClick(target)    
    print("clickGood os.time() = ",os.time())
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
    self.PayUrl = GlobalData.PayURL
    local imagePath = "client/res/public/coin_"..self.ShowType.."_"..pIndex..".png"
    
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
    if self.ShowType == 1 then                  --首充礼包
        EventPost:addCommond(EventPost.eventType.CLICK,"点击首充礼包"..pIndex,pItem.dwProductID)          --点击礼包
    elseif self.ShowType == 2 then              --每日特惠
        EventPost:addCommond(EventPost.eventType.CLICK,"点击每日特惠"..pIndex,pItem.dwProductID)          --点击礼包
    elseif self.ShowType == 3 then              --一次礼包
        EventPost:addCommond(EventPost.eventType.CLICK,"点击一次礼包"..pIndex,pItem.dwProductID)          --点击礼包
    end
end

function HallGiftCenterLayer:onPlacePayOrderResult(pResult)
    if pResult and pResult.code and pResult.code == 0 then        
        ylAll.firstData.OrderNo = pResult.orderNo
        --拉单完成，跳转之前，上报充值点击
        g_MultiPlatform:getInstance():threeLogEvent("ad_purchase_click")
        if pResult.timestamp and pResult.orderNo and pResult.qrCode then
            self:showRechargeQrCodeLayer(pResult.timestamp,pResult.orderNo,pResult.qrCode,ylAll.firstData.dwPrice)
        elseif pResult.pay_url then
            OSUtil.openURL(pResult.pay_url)
        end
    else
        local pString = "Ocorreu uma exceção durante a recarga, por favor tente novamente!"
        pString = (pResult and pResult.msg) and pResult.msg or pString
        showToast(pString)
    end
end

--展示最终界面
function HallGiftCenterLayer:showRechargeQrCodeLayer(timestamp,orderNo,qrCode,price)
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
function HallGiftCenterLayer:showNetLoading()
    local scene = cc.Director:getInstance():getRunningScene()
    local RechargeQrCodeLayer = scene:getChildByName("RechargeQrCodeLayer")
    if RechargeQrCodeLayer then
        return
    end
    G_event:NotifyEvent(G_eventDef.UI_OPEN_RECHARGECODE)
end

function HallGiftCenterLayer:setRightPanelInfo(rechargeBenefitDatas)
    self.rechargeBenefitDatas = rechargeBenefitDatas    
    local pTodayIndex = 1
    self.TodayIndex = pTodayIndex
    local pCCount = #rechargeBenefitDatas.llRebateScores    
    if pCCount<3 then
        for i = 1, math.abs(pCCount-3) do
            pTodayIndex = pTodayIndex + 1
            table.insert(rechargeBenefitDatas.llRebateScores,1,0)
        end
    end
    
    local wCount = rechargeBenefitDatas.wCount 
    if not rechargeBenefitDatas or wCount <= 0 then
        self.mm_rightPanel:hide()
        self.mm_content:setPosition(987.04,507.60)
        return
    end
    self.mm_rightPanel:show()
    self.mm_rightPanel:setOpacity(0)
    self.mm_rightPanel:runAction(cc.FadeIn:create(0.2))
    local llRebateScores = rechargeBenefitDatas.llRebateScores              --奖励列表
    local rightListView = self.mm_rightPanel:getChildByName("rightListView")
    local fntNode = self.mm_rightPanel:getChildByName("fntNode")
    
    self.mm_content:setPosition(887.04,507.60)
    local pChildren = rightListView:getItems()

    -- local sum = 0
    for p = 1,3 do
        local score = llRebateScores[p] 
        local btn = rightListView:getChildByName("btn"..p)
        local fnt_di = btn:getChildByName("Image_fnt_di")
        local fnt = btn:getChildByName("dayGiftNumFnt")
        local gray = btn:getChildByName("Image_di")
        local Image_select = btn:getChildByName("Image_select")
        Image_select:hide()  
        local ani = btn._ani
        btn:onClicked(nil)
        if ani then ani:hide() end
        if score ~= nil then
            fnt:setString(g_format:formatNumber(score,g_format.fType.standard))
            fnt_di:show()
            fnt:show()
            gray:hide()
            if p == pTodayIndex then                     --今天的奖励
                if score == 0 then                   --已经领取
                    fnt_di:hide()
                    fnt:hide()
                    gray:show()  
                else    
                    Image_select:show()                               
                    self:addSpineAnimation(btn)
                    btn:onClicked(function() 
                        G_ServerMgr:receiveRechargeBenefit() 
                    end)
                end
            else                                            --非今天的奖励
                if score == 0 then                   --已经领取
                    fnt_di:hide()
                    fnt:hide()
                    gray:show()  
                else    
                    btn:onClicked(function() 
                        showToast("Por favor, continue a buscá-lo amanhã")          --请第二天继续来领取
                    end)
                end
            end
        else
            fnt_di:hide()
            fnt:hide()
            gray:show()
        end
    end

    -- local sum = 0
    -- for p = 3,1,-1 do
    --     local score = llRebateScores[wCount - sum] 
    --     local btn = rightListView:getChildByName("btn"..p)
    --     local fnt_di = btn:getChildByName("Image_fnt_di")
    --     local fnt = btn:getChildByName("dayGiftNumFnt")
    --     local gray = btn:getChildByName("Image_di")
    --     local Image_select = btn:getChildByName("Image_select")
    --     Image_select:hide()  
    --     local ani = btn._ani
    --     btn:onClicked(nil)
    --     if ani then ani:hide() end
    --     if score ~= nil then
    --         fnt:setString(g_format:formatNumber(score,g_format.fType.standard))
    --         fnt_di:show()
    --         fnt:show()
    --         gray:hide()
    --         if (wCount - sum) == 1 then                     --今天的奖励
    --             if score == 0 then                   --已经领取
    --                 fnt_di:hide()
    --                 fnt:hide()
    --                 gray:show()  
    --             else    
    --                 Image_select:show()                               
    --                 self:addSpineAnimation(btn)
    --                 btn:onClicked(function() 
    --                     G_ServerMgr:receiveRechargeBenefit() 
    --                 end)
    --             end
    --         else                                            --非今天的奖励
    --             btn:onClicked(function() 
    --                 showToast("Por favor, continue a buscá-lo amanhã")          --请第二天继续来领取
    --             end)
    --         end
    --     else
    --         fnt_di:hide()
    --         fnt:hide()
    --         gray:show()
    --     end
    --     sum = sum + 1
    -- end
end

function HallGiftCenterLayer:receiveGift(pData)
    local dwErrorCode = pData.dwErrorCode;
    local llRebateScore = pData.llRebateScore;
    if dwErrorCode == 0 then
        -- G_ServerMgr:requestRechargeBenefit()
    else
        return
    end
    
    local path = "client.src.UIManager.hall.subinterface.rewardLayer"
    local imagePath = string.format("client/res/public/%s.png","mrrw_jb_1")

    local data = {}
    data.goldImg = imagePath
    data.goldTxt = g_format:formatNumber(llRebateScore,g_format.fType.standard)
    data.type = 1
    local layer = appdf.req(path).new(data)
    local rechargeBenefitDatas = self.rechargeBenefitDatas
    if rechargeBenefitDatas and rechargeBenefitDatas.llRebateScores and #rechargeBenefitDatas.llRebateScores > 0 then
        rechargeBenefitDatas.llRebateScores[1] = 0                  --已经领取过
    end
    self:setRightPanelInfo(rechargeBenefitDatas)
end

--点击提示按钮
function HallGiftCenterLayer:onTouchTips()
    if self.tipsPanel:isVisible() then
        self.tipsPanel:hide()
        self:removeTipsListener()
    else
        self.tipsPanel:show()
        self:addTipsListener()
    end
end

function HallGiftCenterLayer:addTipsListener()
    local function onTouchBegan(event,params)
        return true
    end

    local function onTouchEvent(event,params)
        local position = event:getLocation()
        local nodePosition = self.tipsPanel:convertToNodeSpace(position)
        local x = nodePosition.x
        local y = nodePosition.y

        if x < 0 or x > self.tipsPanel:getContentSize().width or y < 0 or y > self.tipsPanel:getContentSize().height then
            self:onTouchTips()
        end
    end
    
    local listener = cc.EventListenerTouchOneByOne:create()
    listener:setSwallowTouches(true)
    listener:registerScriptHandler(onTouchBegan, cc.Handler.EVENT_TOUCH_BEGAN)
    listener:registerScriptHandler(onTouchEvent, cc.Handler.EVENT_TOUCH_ENDED)
    self.listener = listener
    local eventDispatcher =self.tipsPanel:getEventDispatcher()
    eventDispatcher:addEventListenerWithSceneGraphPriority(listener,self.tipsPanel)
end

function HallGiftCenterLayer:removeTipsListener()
    local eventDispatcher = self.tipsPanel:getEventDispatcher()
	eventDispatcher:removeEventListener(self.listener)
end

function HallGiftCenterLayer:addSpineAnimation(parent)
    local ani = parent._ani
    if ani then
        ani:show()
        return
    else
        ani  = sp.SkeletonAnimation:createWithJsonFile("client/res/Gift/spine/xuanzekuan.json","client/res/Gift/spine/xuanzekuan.atlas", 1)        
        ani:addTo(parent)
        ani:setAnimation(0,"animation",true)
        --ani:setScale(1.42)
        ani:setPosition(cc.p(177,95))
    end
    parent._ani = ani
end

function HallGiftCenterLayer:onClickClose()
    DoHideCommonLayerAction(self.mm_bg,self.mm_content,function() 
        if self.NoticeNext then
            G_event:NotifyEvent(G_eventDef.UI_CLIENT_SCENE_NOTICE,{NoticeName="HallGiftCenter"})
        end
        self:removeSelf() 
    end)
end

--通过图片数字创建文本
--spriteFrameName图片纹理名
function HallGiftCenterLayer:getCountTextByNode(spriteFrameName)
    local node = cc.Node:create()
    local curLong = -4           --字体之间的间距
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

return HallGiftCenterLayer