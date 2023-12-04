local BaseLayer = appdf.req(appdf.CLIENT_SRC.."UIManager.BaseLayer")
local VipHelpMoney = class("VipHelpMoney",BaseLayer)


function VipHelpMoney:onExit()
    VipHelpMoney.super.onExit(self)
    G_event:RemoveNotifyEvent(G_eventDef.CMD_MB_AlmzTakeRewardResult)  
end

function VipHelpMoney:ctor(args)
    --提前加载合图
    local parent = (args and args.parent) and args.parent or cc.Director:getInstance():getRunningScene()
    parent:addChild(self,ZORDER.POPUP)    
    self:loadLayer("VIP/VipHelpMoney.csb") 
    ccui.Helper:doLayout(self._rootNode)
    self._args = args[1]
    self._vipHelperConfigData = args[2]
   self:init()
   ShowCommonLayerAction(self.bg,self.content)
end

function VipHelpMoney:init()
    self:initView()
    self:initListener()
    self:doDisplay()
end

function VipHelpMoney:initView()
    self.bg = self:getChildByName("bg")
    self.content = self:getChildByName("content")
    self.btnClose = self:getChildByName("btnClose")
    self.leftText = self:getChildByName("textLeftNode")
    self.rightText = self:getChildByName("textRightNode")
    self.receBerBtn = self:getChildByName("receBerBtn")
    self.btnLast = self:getChildByName("btnLast")
    self.toDayLoseText = self:getChildByName("toDayLoseText")
    self.yestodayText = self:getChildByName("yestodayText")
    self.btnHelp = self:getChildByName("btnHelp")
    self.yestodaySign = self:getChildByName("yestodaySign")
    self.todaySign = self:getChildByName("todaySign")
    self.scrollView = self:getChildByName("scrollView")
    self.vipBiLiText1 = self:getChildByName("vipBiLiText1")
    self.vipBiLiText2 = self:getChildByName("vipBiLiText2")
    self.vipBiLiBtn1 = self:getChildByName("vipBiLiBtn1")
    self.vipBiLiBtn2 = self:getChildByName("vipBiLiBtn2")
    self.scrollView:setScrollBarEnabled(false)
    self.todaySign:hide()
    self.yestodaySign:hide()
    self.receBerBtn:setEnabled(false)
    self.receBerBtn:setTouchEnabled(false)
    local vipBiLiText1 = self:getCountTextByNode("client/res/VIP/VipHelpMoney/lb_sc3_%s.png")
    self.vipBiLiText1:addChild(vipBiLiText1)
    self._vipBiLiText1 = vipBiLiText1
    vipBiLiText1:setString("0b")
    local vipBiLiText2 = self:getCountTextByNode("client/res/VIP/VipHelpMoney/lb_sc3_%s.png")
    self.vipBiLiText2:addChild(vipBiLiText2)
    self._vipBiLiText2 = vipBiLiText2
    vipBiLiText2:setString("0b")
end

function VipHelpMoney:initListener()
    self.btnClose:addTouchEventListener(handler(self,self.onTouch))
    self.receBerBtn:addTouchEventListener(handler(self,self.onTouch))
    self.btnHelp:addTouchEventListener(handler(self,self.onTouch))
    self.vipBiLiBtn1:addTouchEventListener(handler(self,self.onTouch))
    self.vipBiLiBtn2:addTouchEventListener(handler(self,self.onTouch))
    G_event:AddNotifyEvent(G_eventDef.CMD_MB_AlmzTakeRewardResult,handler(self,self.rewardResult))
end

function VipHelpMoney:onTouch(sender,eventType)
    if eventType == ccui.TouchEventType.ended then
        local name = sender:getName()
        if name == "btnClose" then
            self:close()
        elseif name == "receBerBtn" then
            showNetLoading()
            G_ServerMgr:AlmzTakeReward()            --点击领取
            self.receBerBtn:setEnabled(false)
            self.receBerBtn:setTouchEnabled(false)
        elseif name == "btnHelp" or "vipBiLiBtn1" or "vipBiLiBtn2" then               --点击查看vip救援金和vip之间的关系
            G_event:NotifyEvent(G_eventDef.UI_SHOW_VipHelperMoneyConfig,self._vipHelperConfigData)
        end
    end
end

function VipHelpMoney:doDisplay()
    -- self.leftText = self:getCountTextByNode("client/res/VIP/VipHelpMoney/vip_jyjj_lanzi_%s.png")
    -- self.leftText:setScale(0.9)
    -- self.textLeftNode:addChild(self.leftText)
    -- self.rightText = self:getCountTextByNode("client/res/VIP/VipHelpMoney/vip_jyjj_huangzi_%s.png")
    -- self.textRightNode:addChild(self.rightText)
    -- self.rightText:setScale(0.9)
    self:setVipInfo()
end

function VipHelpMoney:setVipInfo()
    -- local result = {
    --     yesterdayStatus = pData:readbyte(),             --状态 0,未发放；1：已发放(未领取、可领取。需要判断llAlmzScore是否为0) 2：已领取
    --     yesterdayLossScore = pData:readscore(int64):getvalue(), --损失  = 昨日总充值-昨日总提现-昨日用户余额
    --     yesterdayAmlzScore = pData:readscore(int64):getvalue(), --实际的救济金
    --     todayStatus = pData:readbyte(),  -- 0
    --     todayLossScore = pData:readscore(int64):getvalue(),
    --     todayAmlzScore = pData:readscore(int64):getvalue()
    -- }
    local result = self._args
    local yesterdayStatus = result.yesterdayStatus
    self._yesTodayBili = result.yesterdayAmlzScore / result.yesterdayLossScore
    local yesterdayLossScore = result.yesterdayLossScore < 0 and 0 or result.yesterdayLossScore
    local yesterdayAmlzScore = result.yesterdayAmlzScore < 0 and 0 or result.yesterdayAmlzScore
    

    local todayStatus = result.todayStatus
    local todayLossScore = result.todayLossScore < 0 and 0 or result.todayLossScore
    local todayAmlzScore = result.todayAmlzScore < 0 and 0 or result.todayAmlzScore

    self._vipBiLiText1:setString((self:getVipBiliByVipHelperConfig(result.todaycbGrowLevel)/10) .. "b")
    self._vipBiLiText1:setPositionX(-self._vipBiLiText1:getContentSize().width/2)

    self._vipBiLiText2:setString((self:getVipBiliByVipHelperConfig(result.yesterdaycbGrowLevel)/10) .. "b")
    self._vipBiLiText2:setPositionX(-self._vipBiLiText2:getContentSize().width/2)

    local canReceive = false
    --今日
    if todayStatus == 0 then            -- 0,未发放
        
    elseif todayStatus == 1 then        --1：已发放(未领取、可领取。需要判断llAlmzScore是否为0)
        if todayAmlzScore >0 then      --还没领取
            canReceive = true
        end
    elseif todayStatus == 2 then        --2：已领取
        self.todaySign:show()
    end

    --昨日
    if yesterdayStatus == 0 then            -- 0,未发放

    elseif yesterdayStatus == 1 then        --1：已发放(未领取、可领取。需要判断llAlmzScore是否为0)
        if yesterdayAmlzScore > 0 then      --还没领取
            canReceive = true
        end
    elseif yesterdayStatus == 2 then        --2：已领取
        self.yestodaySign:show()
    end 

    todayAmlzScore = g_format:formatNumber(todayAmlzScore,g_format.fType.standard)
    -- todayAmlzScore = string.gsub(tostring(todayAmlzScore), ",", "o")
    -- todayAmlzScore = string.gsub(tostring(todayAmlzScore), "%.", "d")
    self.leftText:setString(todayAmlzScore)

    yesterdayAmlzScore = g_format:formatNumber(yesterdayAmlzScore,g_format.fType.standard)
    -- yesterdayAmlzScore = string.gsub(tostring(yesterdayAmlzScore), ",", "o")
    -- yesterdayAmlzScore = string.gsub(tostring(yesterdayAmlzScore), "%.", "d")
    self.rightText:setString(yesterdayAmlzScore)

    self.toDayLoseText:setString(g_format:formatNumber(todayLossScore,g_format.fType.standard))
    self.yestodayText:setString(g_format:formatNumber(yesterdayLossScore,g_format.fType.standard))
    
    self.receBerBtn:setEnabled(canReceive)
    self.receBerBtn:setTouchEnabled(canReceive)
end

--通过图片数字创建文本
--spriteFrameName图片纹理名
function VipHelpMoney:getCountTextByNode(spriteFrameName)
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

function VipHelpMoney:rewardResult(pData)
    dismissNetLoading()
    local int64 = Integer64:new()
    local dwErrorCode = pData:readdword()
    local llScore = pData:readscore(int64):getvalue()
   
    if dwErrorCode == 1700 then                 --今天已领取过救济金了,无法多次领取
        showToast("Já recebi a ajuda financeira hoje.")
    elseif dwErrorCode == 1701 then             --救济金未发放,请重新打开页面（停着当前窗口过天）
        showToast("Os fundos de resgate não foram liberados, por favor, abra a interface novamente.")
        self:close()
    elseif dwErrorCode == 1702 then             --没有救济金可领取
        showToast("Não há resgate disponível no momento.")
    else
        local imagePath = string.format("client/res/public/%s.png","mrrw_jb_1")
        local goldTxt = llScore
        local path = "client.src.UIManager.hall.subinterface.rewardLayer"
        local data = {}
        data.goldImg = imagePath
        data.goldTxt = g_format:formatNumber(goldTxt,g_format.fType.standard)
        data.type = 1
        local layer = appdf.req(path).new(data)
        G_ServerMgr:AlmzGetUserStatus()
        self._args.yesterdayStatus = 2
        self._args.todayStatus = 2
        self:close()
    end
end

function VipHelpMoney:getVipBiliByVipHelperConfig(vip)
    return self._vipHelperConfigData[vip + 1]
end

return VipHelpMoney