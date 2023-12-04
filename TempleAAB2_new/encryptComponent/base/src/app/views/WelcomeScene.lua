---------------------------------------------------
--Desc:WelcomeScene 欢迎界面 fixed
--Date:2023-11-09 16:12:28
--Author:A*
---------------------------------------------------
StringUtil = {}
function StringUtil.isStringValid(str)
    return str and str ~= "";
end

local WelcomeScene = class("WelcomeScene", cc.load("mvc").ViewBase)
require("base.src.I18n")
require("base.src.app.models.ylAll")

local ClientUpdate  = require("base.src.app.controllers.ClientUpdate")
local QueryDialog   = require("base.src.app.views.layer.other.QueryDialog")

local scheduler     = cc.Director:getInstance():getScheduler()
g_FrameSize         = cc.Director:getInstance():getOpenGLView():getFrameSize()
g_TargetPlatform    = cc.Application:getInstance():getTargetPlatform()

--渠道
G_CHANNEL_ID = ""
--客户端IP
G_CLIENT_IP = "127.0.0.1"

g_offsetX = 0
First_Run = true
local m_frameCache = nil

local luaoc
local BRIDGE_CLASS_IOS
if g_TargetPlatform == cc.PLATFORM_OS_IPHONE or g_TargetPlatform == cc.PLATFORM_OS_IPAD then
    luaoc = require "cocos.cocos2d.luaoc"
    BRIDGE_CLASS_IOS = "AppController"
end
local luaj
local BRIDGE_CLASS_ANDROID
if g_TargetPlatform == cc.PLATFORM_OS_ANDROID then
    luaj = require "cocos.cocos2d.luaj"
    BRIDGE_CLASS_ANDROID = "org/cocos2dx/lua/AppActivity"
end

--本地持久化文件
function WelcomeScene:LocalizationFile(pJson,pFile)
    if pJson and type(pJson) == "table" then
        pJson = cjson.encode(pJson)
    end
    local hfile = io.open(pFile, "w+")
    hfile:write(pJson)
    hfile:close()
end

function IpString2dw( str )
	local num = 0
	if str and type(str)=="string" then        
        local p1,p2,p3 = string.find(str,":")
        if p1 then
            str = "127.0.0.2"
        end
		local o1,o2,o3,o4 = str:match("(%d+)%.(%d+)%.(%d+)%.(%d+)" )
		num = 2^24*o4 + 2^16*o3 + 2^8*o2 + o1
	end
    return num
end

local _callersArr = {}
local configResList = {}

--启动界面
function WelcomeScene:onCreate()
    --设定偏移量，设配旧款游戏（勿动）
    local scaleY = g_FrameSize.height / appdf.HEIGHT
    local acWidth = math.floor(g_FrameSize.width / scaleY)
    if acWidth > appdf.WIDTH then
        g_offsetX = (acWidth - appdf.WIDTH)/2
    end
	
    --非首次进入欢迎界面则打开登录界面
    if not First_Run then
        collectgarbage("collect")
        local logonLayer = appdf.req(appdf.CLIENT_SRC.."UIManager.login.LogonScene").new(self,true)        
        self:addChild(logonLayer,1)
        return
    end
    First_Run = false
    
    local csbNode = cc.CSLoader:createNode("welcomeLayer.csb")
    local content = csbNode:getChildByName("content")
    csbNode:setContentSize(display.width,display.height)    
    csbNode:setAnchorPoint(cc.p(0.5,0.5))
    csbNode:setPosition(display.cx,display.cy)

    self.Background = content:getChildByName("Background")    
    self.Tips = content:getChildByName("Tips") 
    self.PanelTips = content:getChildByName("PanelTips")
    if display.width  > 2560 then
        self.Background:setScale(display.width/2560)
    end 
    
    self.sliderBG = self.PanelTips:getChildByName("sliderBG")
    self.sliderLine = self.sliderBG:getChildByName("sliderLine")
    self.sliderHead = self.sliderLine:getChildByName("light")
    -- self.sliderWidth = self.sliderLine:getContentSize().width    
    self.txtDownDesc = self.PanelTips:getChildByName("txtDown")
    self.txtShow = self.PanelTips:getChildByName("txtShow")
    self.txtShow:setString("Checando atualização")
    self.txtPercent = self.PanelTips:getChildByName("txtPercent")    
    self:updateBar(0)
    ccui.Helper:doLayout(csbNode)
    self:addChild(csbNode)
    
    --1.1获取渠道名称,附加判定(官方包,网红包),附加设定远端Json配置(项目切换文件，Adjust配置文件)
    self:getChannelName()
    --1.2获取机器码
    self:getMachineID()
    --2.检测项目切换
    self:CheckProjectSwitch()
end

--1.1 获取渠道名称
function WelcomeScene:getChannelName()    
    if CHANNEL_OPEN then
        local func = "getChannelId"
        if FunctionName and FunctionName["getChannelId"] and FunctionName["getChannelId"]~="" then
            func = FunctionName["getChannelId"]
        end
        if device.platform == "android" then
            local sigs = "()Ljava/lang/String;"    
            local ok,ret = luaj.callStaticMethod(BridgeClassName.BRIDGE_CLASS_ACTIVITY,func,{},sigs)
            if ok then
                G_CHANNEL_ID = ret
            end
        elseif device.platform == "ios" then
            local ok,ret = luaoc.callStaticMethod(BRIDGE_CLASS_IOS,func)
            if ok then
                G_CHANNEL_ID = ret
            end
        end
    end

    if G_CHANNEL_ID == "10001"      --PresenteSlots 官方包
    or G_CHANNEL_ID == "30001"      --TeenpattiGame 官方包
    or G_CHANNEL_ID == "40001"      --FrenzyWins    官方包
    or G_CHANNEL_ID == "50001"      --Dream3Patti   官方包
    or G_CHANNEL_ID == "WH" then    --四个项目       新版网红包通用
        self.isOfficial     = true
        self.FileAllocation = "Allocation/Official.json"                --项目切换配置文件
        self.FileAdjust     = "Adjust/Official.json"                    --Adjust配置文件
    else
        self.isOfficial     = false
        self.FileAllocation = "Allocation/"..G_CHANNEL_ID..".json"  --项目切换配置文件
        self.FileAdjust     = "Adjust/"..G_CHANNEL_ID..".json"      --Adjust配置文件
    end
end

--1.2 获取机器码
function WelcomeScene:getMachineID()
    self.MachineID = ""
    local result = "MNADIndj1983749jdnahNNHJ"
    if g_TargetPlatform == cc.PLATFORM_OS_WINDOWS then
        result = CCGetWinMac()
    elseif g_TargetPlatform == cc.PLATFORM_OS_ANDROID then        
        local sigs = "()Ljava/lang/String;"
        local func = "getUUID"
        if FunctionName and FunctionName["getUUID"] and FunctionName["getUUID"]~="" then
            func = FunctionName["getUUID"]
        end
        local ok,ret = luaj.callStaticMethod(BridgeClassName.BRIDGE_CLASS_ACTIVITY,func,{},sigs)
        result = ok and ret or result
    elseif g_TargetPlatform == cc.PLATFORM_OS_IPHONE or targetPlatform == cc.PLATFORM_OS_IPAD then
        local ok,ret = luaoc.callStaticMethod(BRIDGE_CLASS_IOS,"getUUID")
        result = ok and ret or result
    end
    self.MachineID = md5(result)
end

--2.1 检测项目切换
function WelcomeScene:CheckProjectSwitch()
    if PROJECT_SWITCH_SUPPORT then
        --支持项目切换功能,则优先切换基础包展示内容
        local pAllocationYet  = cc.UserDefault:getInstance():getBoolForKey("AllocationYet",false)            
        if pAllocationYet then
            --已经拉取过一次项目分配   
            --处理项目切换
            self:DealProjectSwitch()
            --检测热更配置
            self:RequestProjectConfig()
        else
            --暂未拉取过项目分配            
            local AllocationFileUri = ylAll.Request_HttpUrl..self.FileAllocation.."?timestamp="..os.time()
            appdf.onHttpJsonTable(AllocationFileUri,"GET","",function(jsondata,response)
                cc.UserDefault:getInstance():setBoolForKey("AllocationYet",true)
                cc.UserDefault:getInstance():setStringForKey("AllocationJson",response)
                cc.UserDefault:getInstance():flush()
                if response and response~="" then
                    --处理项目切换
                    self:DealProjectSwitch()
                end                        
                --检测热更配置
                self:RequestProjectConfig()            
            end)
        end        
    else
        --不支持项目切换功能 或者渠道名称无法获取
        --检测热更配置
        self:RequestProjectConfig()
    end    
end

--2.2 处理项目切换
function WelcomeScene:DealProjectSwitch()
    local pAllocationJson = cc.UserDefault:getInstance():getStringForKey("AllocationJson","")
    if pAllocationJson and pAllocationJson~="" then
        local pAlloactionInfo = cjson.decode(pAllocationJson)
        for k, v in pairs(pAlloactionInfo) do
            ylAll[k] = v
            if k=="ProjectSwitch" then
                self:RefreshLayer(v)
            end
        end
    end
end

--2.3 根据项目切换刷新界面
function WelcomeScene:RefreshLayer(pProjectSwitch)
    local pProjectName = {
        "PresenteSlots",
        "TeenpattiGame",
        "FrenzyWins",
        "Dream3Patti",
    }
    local pName = pProjectName[pProjectSwitch]
    if pName then
        self.Background:loadTexture("base/res/welcome/Bg_"..pName..".jpg",ccui.TextureResType.localType)
        self.Tips:loadTexture("base/res/welcome/Tips_"..pName..".png",ccui.TextureResType.localType)
    end    
end

--3.1 检测热更配置
function WelcomeScene:RequestProjectConfig()    
    local pURL = ylAll.Request_HttpUrl.."brazil_Config.json".."?timestamp="..os.time()
    local pDst = device.writablePath.."brazil_Config.json"
    appdf.onHttpJsonTable(pURL,"GET","",function(jsondata,response)
        if jsondata then
            --本地持久化文件
            self:LocalizationFile(jsondata,pDst)
            self:ResponseProjectConfig(jsondata)            
        else
            local dst = device.writablePath
            
            if cc.FileUtils:getInstance():isFileExist(pDst) then
                local pContent = cc.FileUtils:getInstance():getStringFromFile(pDst)
                self:ResponseProjectConfig(cjson.decode(pContent))
                return 
            end
            self:QuitTips()
        end            
    end)
end

function WelcomeScene:ResponseProjectConfig(jsondata) 
    self.jsondata = jsondata  
    self:RequestIP()
    self:JudgeConfigStatus()
end

function WelcomeScene:RequestIP()
    if G_CLIENT_IP~="127.0.0.1" then
        --如果已经存在 合法IP
        if self and not tolua.isnull(self) then
            self:ResponseIP(G_CLIENT_IP)
        end
    else
        --不存在IP，或者IP非法
        local ipUrl = self.jsondata["getIpUrl"] or "http://clientapi.nskbmddy.com/ip"        
        ipUrl = ipUrl.."?timestamp="..os.time()
        appdf.onHttpJsonTable(ipUrl,"GET","",
            function(json,response)
                print("response = ",response)
                if self and not tolua.isnull(self) then
                    self:ResponseIP(response)
                end
            end,
            cc.XMLHTTPREQUEST_RESPONSE_STRING
        )
    end
end

function WelcomeScene:ResponseIP(pResponse)
    local ip
    if pResponse then
        ip = appdf.IPV6ToIPV4(pResponse)
    end
    if ip and ip~="127.0.0.1" then
        G_CLIENT_IP = ip
        if self and not tolua.isnull(self) then
            self:InitNetwork()
        end
    else        
        if self and not tolua.isnull(self) then
            self:RequestIP()
        end
    end
end

function WelcomeScene:InitNetwork()
    local machined = self:getMachineId()
    print("machined = ",machined)
    print("ip = ",G_CLIENT_IP)
    CCipHerInit(machined,G_CLIENT_IP)

    local newServerListCDN = {}
    local bHaveServerCDN = false
    local ipMaxCountCDN = tonumber(self.jsondata["IpMaxCountCDN2"]) or 10
    for i=1,ipMaxCountCDN do  --最多配10个域名列表 
        if not self.jsondata["ServerListCDN2"] then break end
        local id = self.jsondata["ServerListCDN2"][ string.format("id%d",i)]
        local ip = self.jsondata["ServerListCDN2"][ string.format("ip%d",i)]
        if id and ip then
            table.insert(newServerListCDN,{id=id,ip=ip})
            bHaveServerCDN = true
        end
    end
    if not ylAll.LocalTest and bHaveServerCDN == true then
        ylAll.LOGONSERVER_LIST = newServerListCDN
    end
    for i,v in pairs(ylAll.LOGONSERVER_LIST) do
        CCInitTesterServer(v.id,v.ip) 
    end
    
    --网络数据
    local netDelayData = {}
    local netDelayData = self.jsondata["networkData"]
    for i=1,7 do
        if not netDelayData then 
            break 
        end
        local _value = netDelayData[tostring(i)]
        table.insert(netDelayData,_value or 0)
    end
    ylAll.NormalNetDelay = netDelayData
    if #netDelayData > 0 then
        CCSetNetworkDelayTime(netDelayData[1],netDelayData[2],netDelayData[3],netDelayData[4],netDelayData[5],netDelayData[6],netDelayData[7])
    end
    local ipDw = IpString2dw(MyIP)
    local addr = {}
    addr[1],addr[2],addr[3],addr[4],addr[5],addr[6],addr[7],addr[8],addr[9],addr[10],addr[11],addr[12],addr[13],addr[14] = CCHxcipherIpEncode(ipDw)
    ylAll.ipAddr = addr
    InitNetworkOver = true
end

function WelcomeScene:JudgeConfigStatus()
    if self.jsondata.ServerStatus and self.jsondata.ServerStatus ~=0 then
        if self.jsondata.ServerStatus == 1 or IS_WHITE_LIST then 
            local pConfig = self.jsondata.NoticeConfig
            local pContent = string.format(pConfig.msg1,pConfig.timeStart,pConfig.timeEnd)
            local pTitle = pConfig.title
            local pSignature = string.format(pConfig.signature,self.jsondata.apk_name)
            self.NoticeDialog = QueryDialog:create("",function(bConfirm)
                if self.schedulerID then
                    scheduler:unscheduleScriptEntry(self.schedulerID)
                    self.schedulerID = nil
                end
                if bConfirm == true then                    	
                    self:DealConfig()
                end					                   
            end)
            self.NoticeDialog:showTXTTitle(pTitle)
            self.NoticeDialog:showTXTContent(pContent)
            self.NoticeDialog:showTXTSignature(pSignature)
            self:addChild(self.NoticeDialog)
                      
            self.schedulerID = scheduler:scheduleScriptFunc( function()
                if self.schedulerID then
                    scheduler:unscheduleScriptEntry(self.schedulerID)
                    self.schedulerID = nil
                end
                self:DealConfig()
            end , 5, false)
        elseif self.jsondata.ServerStatus == 2 then
            self.PanelTips:hide()
            local pConfig = self.jsondata.NoticeConfig
            local pContent = string.format(pConfig.msg2,pConfig.timeEnd)
            local pTitle = pConfig.title
            local pSignature = string.format(pConfig.signature,self.jsondata.apk_name)
            self.NoticeDialog = QueryDialog:create("",function(bConfirm)
                os.exit(0)
            end)
            self.NoticeDialog:showTXTTitle(pTitle)
            self.NoticeDialog:showTXTContent(pContent)
            self.NoticeDialog:showTXTSignature(pSignature)
            self:addChild(self.NoticeDialog)            
        end
    else
        self:DealConfig()
    end
end

function WelcomeScene:DealConfig()    
    self:initClientInit()
    self:PerLoadingLogonRes(handler(self,self.StepNext))    
end

function WelcomeScene:StepNext()	
    --拉取文件服务器上相应项目的Adjust配置    
    if G_CHANNEL_ID then
        local AdjustJson = G_CHANNEL_ID == "" and "Official.json" or G_CHANNEL_ID..".json"
        local AdjustJsonUri = ylAll.Request_HttpUrl.."Adjust/"..AdjustJson.."?timestamp="..os.time()
        appdf.onHttpJsonTable(AdjustJsonUri,"GET","",function(jsondata,response)       
            if jsondata then
                for k, v in pairs(jsondata) do
                    ADLogEventName[k] = v
                end
                self:StepOver()
            else
                self:StepOver()
            end            
        end)
    else
        self:StepOver()
    end
end

function WelcomeScene:StepOver()
    -- 资源同步队列
	self.m_tabUpdateQueue = {}
    self:LoadResComplete()
end

function WelcomeScene:initClientInit()
    require("clientcore.ClientCoreConfig")
    ClientCoreConfig.includeTween = true
    ClientCoreConfig.includeCcs = true
    ClientCoreConfig.setup(self)
    require("app.ClientInit").setup(self)
    appdf.req("base.src.app.models.Functions")
end

--提前加载 大厅资源 
function WelcomeScene:PerLoadingLogonRes(callback)
    self._processAllTotal = #configResList + #_callersArr
    self._processTotal = #configResList
	self._processIndex = 1
    self._picCachedSps = {}
    self._processComplete = callback
    self._processTimer = scheduler:scheduleScriptFunc(handler(self,self.doLoadTexture), 0, false)
end

function WelcomeScene:doLoadTexture()
    if self._processTotal < self._processIndex then
        if self._processAllTotal < self._processIndex then
		    if self._processTimer ~= nil then
		       scheduler:unscheduleScriptEntry(self._processTimer)
		       self._processTimer = nil
		    end
		    self:applyFunction(self._processComplete)
		    self._processComplete = nil
        else
            self:onCallLuaScript()
        end
    else
   		local onAnyscComplete = nil
		local vo = configResList[self._processIndex]    
        local url = nil
       if vo.type == "plist" then
            onAnyscComplete = function()--__emptyFunction;--一定要带上空函数，否则display.loadImage不用异步加载
               m_frameCache:addSpriteFrames(vo.url .. ".plist")
            end
            url = vo.url..".png"
       elseif vo.type == "png" or vo.type == "jpg" then
            onAnyscComplete = function()--__emptyFunction;--一定要带上空函数，否则display.loadImage不用异步加载
            end
            url = vo.url.."."..vo.type
       end
       display.loadImage(url, onAnyscComplete)
       self._processIndex = self._processIndex + 1
       self:showLoadingPercent(self._processIndex)
    end 
end
function WelcomeScene:showLoadingPercent(index) 
    local per = index / self._processAllTotal *100
    if per >100 then per = 100 end
    self:updateBar(per)
end

function WelcomeScene:onCallLuaScript()
    local callVo = _callersArr[self._processIndex-self._processTotal];
    local t = os.clock();
    callVo.func(callVo.scope);
    self._processIndex = self._processIndex + 1;
    self:showLoadingPercent(self._processIndex)
end

function WelcomeScene:LoadResComplete()
	--无版本信息或不对应 解压自带ZIP
    local nVersion = tonumber(self:getApp()._version:getVersion())    
    local nResversion = tonumber(self:getApp()._version:getResVersion())
    local nBaseZipVersion = tonumber(self:getApp()._version:getZipVersion("base"))
    local nClientZipVersion = tonumber(self:getApp()._version:getZipVersion("client"))    
	if nil == nResversion then
        if HOTFIX_UPGRADATION  then
            self:prepareInit()
        else
            self:onUnZipBase()
        end
	else
        self:NewEnterGame(self.jsondata)
	end       
end

--解压自带ZIP
function WelcomeScene:onUnZipBase()
	local this = self
    if self._unZip == nil then --大厅解压
		-- 状态提示
		self._unZip = 0
		--解压
		local dst = device.writablePath
        local filePath = cc.FileUtils:getInstance():fullPathForFilename("client.zip")
        print("filePath = ",filePath)
		unZipAsync(filePath,dst,function(result)
				this:onUnZipBase()
                self:getApp()._version:setZipVersion(1 ,"client")
                self:getApp()._version:setZipVersion(1 ,"base")
			end)
	elseif self._unZip == 0 then --默认游戏解压
		self._unZip = 1
		--解压
		local dst = device.writablePath
        local filePath = cc.FileUtils:getInstance():fullPathForFilename("game.zip")
		unZipAsync(filePath,dst,function(result)
				this:onUnZipBase()
			end)
	else 			-- 解压完成
		self._unZip = nil
		--更新本地版本号
        self:getApp()._version:setVersion(VERSION_INIT_ZIP_BASE or 1)
		self:getApp()._version:setResVersion(VERSION_INIT_ZIP_CLIENT or 1)
        self:getApp()._version:setZipVersion(VERSION_INIT_ZIP_BASE or 1 ,"base")
        self:getApp()._version:setZipVersion(VERSION_INIT_ZIP_CLIENT or 1 ,"client")
        self:NewEnterGame(self.jsondata)
		return	
	end
end

--升级更新后处理逻辑
function WelcomeScene:prepareInit()
    self:getApp()._version:setVersion(VERSION_INIT_ZIP_BASE or 1)
    self:getApp()._version:setResVersion(VERSION_INIT_ZIP_CLIENT or 1)
    self:getApp()._version:setZipVersion(VERSION_INIT_ZIP_BASE or 1 ,"base")
    self:getApp()._version:setZipVersion(VERSION_INIT_ZIP_CLIENT or 1 ,"client")

    --升级更新不再整体更新base.zip 和client.zip
    --base目录，client目录在生成应用时候加在包体内
    --首次打开应用，将base/res/filemd5List.json,client/res/filemd5List.json 拷贝到可读写目录下。
    --只做单文件对比
    if not createDirectory(device.writablePath.."base/res/") then
        return
    end
    if not createDirectory(device.writablePath.."client/res/") then
        return
    end
    local jsonStr1 = cc.FileUtils:getInstance():getStringFromFile("base/res/filemd5List.json")    
    local hfile = io.open(device.writablePath.."base/res/filemd5List.json", "w+")
    hfile:write(jsonStr1)
    hfile:close()
    
    local jsonStr2 = cc.FileUtils:getInstance():getStringFromFile("client/res/filemd5List.json")    
    local hfile = io.open(device.writablePath.."client/res/filemd5List.json", "w+")
    hfile:write(jsonStr2)
    hfile:close()
    
    self:NewEnterGame(self.jsondata)
end

function WelcomeScene:updateApp()
	if device.platform == "ios" and (type(self._iosUpdateUrl) ~= "string" or self._iosUpdateUrl == "") then
		print("ios update fail, url is nil or empty")
	else
		-- self._updateText:setString("")
        if device.platform == "android" then
            self:upDateBaseApp()
        else
 	        local dialog = QueryDialog:create("Encontre uma nova versão, vá para download! obrigado!",function(bConfirm)
	               if bConfirm == true then                    	
		    			self:upDateBaseApp()
	                end					
		    	end)
            self:addChild(dialog)
        end
		return true
	end				
end

function WelcomeScene:upDateBaseApp()
	if device.platform == "android" then
		local this = self
		local argsJson 
		local url = self:getApp()._updateUrl.."/"..self._gameName..".apk"
	    local sigs = "()Ljava/lang/String;"
   		local ok,ret = luaj.callStaticMethod(BRIDGE_CLASS_ANDROID,"getSDCardDocPath",{},sigs)
   		if ok then
   			local dstpath = ret .. "/update/"
   			local filepath = dstpath .. self._gameName..".apk"
		    if cc.FileUtils:getInstance():isFileExist(filepath) then
		    	cc.FileUtils:getInstance():removeFile(filepath)
		    end
		    if false == cc.FileUtils:getInstance():isDirectoryExist(dstpath) then
		    	cc.FileUtils:getInstance():createDirectory(dstpath)
		    end
            self.sliderLine:setPercent(0)
            self.txtPercent:setString("0%")
            self.txtShow:setString("Atualizando pacote APK, aguarde...")
		    self:updateBar(0)
			downFileAsync(url,self._gameName..".apk",dstpath,function(main,sub)
					--下载回调
					if main == appdf.DOWN_PRO_INFO then --进度信息
						self:updateBar(sub)
					elseif main == appdf.DOWN_COMPELETED then --下载完毕
						self.txtShow:setString("Transferência concluída")
						--安装apk						
						local args = {filepath}
						sigs = "(Ljava/lang/String;)V"
		   				ok,ret = luaj.callStaticMethod(BRIDGE_CLASS_ANDROID, "installClient",args, sigs)
		   				if ok then
		   					os.exit(0)
		   				end
					else
						local dialog = QueryDialog:create("Download falhou,code:".. main .."\n se deve tentar novamente?",function(bReTry)
							if bReTry == true then
								this:upDateBaseApp()
							else
								os.exit(0)
							end
						end)
                        self:addChild(dialog)
					end
				end)
		else
			os.exit(0)
   		end	    
	elseif device.platform == "ios" then
		local luaoc = require "cocos.cocos2d.luaoc"
		local ok,ret  = luaoc.callStaticMethod("AppController","updateBaseClient",{url = self._iosUpdateUrl})
	    if not ok then
	        print("luaoc error:" .. ret)        
	    end
	elseif device.platform == "windows" then
        local pcExe = self:getApp()._updateUrl.."/"..self._gameName..".exe"
        CCOpenWinUrl(pcExe)
    end
end

local function split2Tab(str,delim)
	local i,j,k
	local t = {}
	k = 1
	while true do
		i,j = string.find(str,delim,k)
		if i == nil then
			table.insert(t,tonumber(string.sub(str,k)))
			return t
		end
		table.insert(t,tonumber(string.sub(str,k,i - 1)))
		k = j + 1
	end
    return t
end

function WelcomeScene:NewEnterGame(jsondata)
    local this = self
    if jsondata["update_open"] == true then  --游戏更新开关
        ylAll.UPDATE_OPEN = true
    else
        ylAll.UPDATE_OPEN = false
    end
 	--下载地址
 	this:getApp()._updateUrl = jsondata["update_url"]	
    if (g_TargetPlatform == cc.PLATFORM_OS_IPHONE or g_TargetPlatform == cc.PLATFORM_OS_IPAD) then
        this:getApp()._updateUrl = jsondata["update_url_ios"]	
    end		
    this._iosUpdateUrl = jsondata["update_url_ios"]
    this.ApplicationVersion = tonumber(jsondata["application_version"])    
    this._gameName = jsondata["apk_name"]
    local CurApplicationVersion = ""          
    local isUpdateBase = false    
    if g_TargetPlatform == cc.PLATFORM_OS_ANDROID and self.isOfficial then        
        local ok,CurApplicationVersion = luaj.callStaticMethod(BRIDGE_CLASS_ANDROID,"getApplicationVersion",{},"()Ljava/lang/String;")
        print("CurApplicationVersion = ",CurApplicationVersion)
        if this.ApplicationVersion>tonumber(CurApplicationVersion) then
            local dirPath = device.writablePath
            cc.FileUtils:getInstance():removeDirectory(dirPath)  --更新app，先把所有的目录删除
            isUpdateBase = self:updateApp()
        end
    elseif (g_TargetPlatform == cc.PLATFORM_OS_IPHONE or g_TargetPlatform == cc.PLATFORM_OS_IPAD) then        
        local ok,CurApplicationVersion = luaoc.callStaticMethod(BRIDGE_CLASS_IOS,"getApplicationVersion")        
        local ios_new_version = tonumber(jsondata["application_version_ios"]) or 0        
        if ios_new_version>tonumber(CurApplicationVersion) then
           local newPathUrl = jsondata["new_version_path_ios"]        
           local paramtab = {url = newPathUrl}
           local ok,ret = luaoc.callStaticMethod(BRIDGE_CLASS_IOS,"openBrowser", paramtab)
            if not ok then
            local msg = "openBrowser luaoc error:" .. ret
                print(msg)
            else  
            end
        end
    end
    if isUpdateBase == true then return end  

    local baseZip = self:getApp()._version:getZipVersion("base")
    print("local baseZip = ",baseZip)
    print("baseZip = ",jsondata["base_zip"])
    local clientZip = self:getApp()._version:getZipVersion("client")
    print("local clientZip = ",clientZip)
    print("clientZip = ",jsondata["client_zip"])
    local updateBase = false
    local updateClient = false
    ylAll.SERVER_UPDATE_DATA = jsondata
    if  baseZip < jsondata["base_zip"] then
        updateBase = true
        self:getApp()._version:setVersion(1)
        this._newBaseVersion = 1
    end
    if clientZip < jsondata["client_zip"] then
        updateClient = true
        self:getApp()._version:setResVersion(1)
        this._newResVersion = 1
    end
	if updateBase then
		-- 更新配置
	 	local updateConfig = {}
        updateConfig.isBase = true
		updateConfig.isClient = false
        updateConfig.moduleName = "base"
        updateConfig.curModuleVersion = self:getApp()._version:getZipVersion("base")
		updateConfig.newfileurl = this:getApp()._updateUrl.."/base/res/filemd5List.json"
		updateConfig.downurl = this:getApp()._updateUrl .. "/"
		updateConfig.dst = device.writablePath				
		updateConfig.src = device.writablePath.."base/res/filemd5List.json"
		table.insert(self.m_tabUpdateQueue, updateConfig)
	end	
 	this._newBaseVersion = jsondata["base_version"]
    local nNewV1 = self._newBaseVersion
	local nCurV1 = tonumber(self:getApp()._version:getVersion())
    if nNewV1 and nCurV1 and nNewV1 ~= nCurV1 then
		-- 更新配置	
	 	local updateConfig = {}	
        updateConfig.isBase = true   
		updateConfig.isClient = false	
        updateConfig.moduleName = "base"   
        updateConfig.curModuleVersion = self:getApp()._version:getZipVersion("base")   
		updateConfig.newfileurl = this:getApp()._updateUrl.."/base/res/filemd5List.json"	
		updateConfig.downurl = this:getApp()._updateUrl .. "/"	
		updateConfig.dst = device.writablePath					
		updateConfig.src = device.writablePath.."base/res/filemd5List.json"	
		table.insert(self.m_tabUpdateQueue, updateConfig)                	
    end    	        						
	if updateClient then
		-- 更新配置	
	 	local updateConfig = {}	
        updateConfig.isBase = false   
		updateConfig.isClient = true	
        updateConfig.moduleName = "client"   
        updateConfig.curModuleVersion = self:getApp()._version:getZipVersion("client")   
		updateConfig.newfileurl = this:getApp()._updateUrl.."/client/res/filemd5List.json"	
		updateConfig.downurl = this:getApp()._updateUrl .. "/"	
		updateConfig.dst = device.writablePath					
		updateConfig.src = device.writablePath.."client/res/filemd5List.json"	
		table.insert(self.m_tabUpdateQueue, updateConfig)	
	end		
 	this._newResVersion = jsondata["client_version"]
    local nNewV = self._newResVersion
	local nCurV = tonumber(self:getApp()._version:getResVersion())
    local p = cc.FileUtils:getInstance():getWritablePath()
    local status = cc.FileUtils:getInstance():isDirectoryExist(p.."client/src/")
    if not status then
        self:getApp()._version:setResVersion(VERSION_INIT_ZIP_CLIENT or 1)
        nCurV = VERSION_INIT_ZIP_CLIENT or 1
    end
	if nNewV and nCurV and nNewV ~= nCurV then 
 		-- 更新配置	
	 	local updateConfig = {}	
        updateConfig.isBase = false    
		updateConfig.isClient = true 	
        updateConfig.moduleName = "client"    
        updateConfig.curModuleVersion = self:getApp()._version:getZipVersion("client")    
		updateConfig.newfileurl = this:getApp()._updateUrl.."/client/res/filemd5List.json" 	
		updateConfig.downurl = this:getApp()._updateUrl .. "/"	
		updateConfig.dst = device.writablePath						
		updateConfig.src = device.writablePath.."client/res/filemd5List.json"	
		table.insert(self.m_tabUpdateQueue, updateConfig)               	
    end    
 	--游戏列表
 	local rows = jsondata["gamecount"]	
 	this:getApp()._gameList = {}
    for i=1,rows do
 		local gameinfo = {}    
 		gameinfo._KindID = jsondata["game_update_config"][""..i][1]["wKindID"]  
        local szKindName = jsondata["game_update_config"][""..i][1]["szKindName"]
 		gameinfo._KindName = szKindName--string.lower(szKindName)
        local szModuleName = jsondata["game_update_config"][""..i][1]["szModuleName"]   
 		gameinfo._Module = string.gsub(szModuleName, "[.]", "/")    
 		gameinfo._KindVersion = jsondata["game_update_config"][""..i][1]["dwClientVersion"]
 		gameinfo._ServerResVersion = tonumber(jsondata["game_update_config"][""..i][1]["wResVersion"])    
 		gameinfo._Type = gameinfo._Module    
        gameinfo._TypeId = tonumber(jsondata["game_update_config"][""..i][1]["wTypeID"])    
 		--检查本地文件是否存在    
 		local path = device.writablePath .. "game/" .. gameinfo._Module    
 		gameinfo._Active = cc.FileUtils:getInstance():isDirectoryExist(path)    
 		local e = string.find(gameinfo._KindName, "[.]")    
 		if e then    
 			gameinfo._Type = string.sub(gameinfo._KindName,1,e - 1)    
 		end    
 		-- 排序    
        local sortID = jsondata["game_update_config"][""..i][1]["SortID"]
 		gameinfo._SortId = tonumber(sortID) or 0    
 		table.insert(this:getApp()._gameList, gameinfo)    
 	end
 	table.sort( this:getApp()._gameList, function(a, b)
 		return a._SortId > b._SortId
 	end)
    self:onEnterGame()        
end

function WelcomeScene:onEnterGame()
    --升级判断
    local bUpdate = false
    local isWin32 =  (g_TargetPlatform == cc.PLATFORM_OS_WINDOWS)
	if ylAll.UPDATE_OPEN and  not isWin32 then   --update
		bUpdate = self:updateClient()
	else
		self:getApp()._version:setResVersion(self._newResVersion)
	end
    if not bUpdate then
        self:EnterClient()
    end
end

--进入登录界面
function  WelcomeScene:EnterClient()
    if self.isNeedReStart == true then
        self.isNeedReStart = false
        local dialog = QueryDialog:create("A atualização está concluída, reinicie o jogo!",function(bReTry)
   		     os.exit(0)
	    end, true)      
        self:addChild(dialog)     
        return 
    end
    local logonLayer = appdf.req(appdf.CLIENT_SRC.."UIManager.login.LogonScene").new(self)
    self:addChild(logonLayer,1)    
end

function WelcomeScene:QuitTips()
 	local dialog = QueryDialog:create("A solicitação de rede expirou, se deve tentar novamente!",function(bConfirm)
			if bConfirm then
                self:runAction(cc.Sequence:create(cc.DelayTime:create(1),cc.CallFunc:create(function()
                    self:onHandlerWelcomeHttp()
                end)))
            else
                os.exit(0)	
            end				
		end)
    self:addChild(dialog)
end

--升级大厅
function WelcomeScene:updateClient()
	if 0 ~= #self.m_tabUpdateQueue then
		self:goUpdate()
		return true
	end
	return false
end

--开始下载
function WelcomeScene:goUpdate( )
	local config = self.m_tabUpdateQueue[1]
	if nil == config then
        --self:EnterClient()
        self:resetMain()
	else
        self.sliderLine:setPercent(0)
        self.txtPercent:setString("0%")
        if config.isBase == true then
            self.txtShow:setString("Os recursos principais do programa estão sendo atualizados, aguarde...")
        elseif config.isClient == true then
            self.txtShow:setString("Atualizando recursos do lobby, aguarde...")
        else
            self.txtShow:setString("Atualizando o jogo, por favor aguarde...")
        end
        local moduleVersion = self:getApp()._version:getZipVersion(config.moduleName)
        -- dump(config)
		ClientUpdate:create(config.newfileurl, config.dst, config.src, config.downurl,config.moduleName,moduleVersion)
			:upDateClient(self)
	end	
end

--下载进度
function WelcomeScene:updateProgress(sub, msg, mainpersent)
	self:updateBar( math.floor(mainpersent))
    self.txtDownDesc:setString("Downloading...")
end

function WelcomeScene:upDateSuccessToUnzip(fileName,dst,moduleName,version)
    self.txtShow:setString("Descompactando, por favor aguarde")
    unZipAsync(cc.FileUtils:getInstance():fullPathForFilename(fileName),dst,function(result)
    		cc.FileUtils:getInstance():removeFile(fileName)
            version = version or 0
            self:getApp()._version:setZipVersion(version,moduleName)
            self:updateResult(true,"",true)
    	end)
end

--下载结果
function WelcomeScene:updateResult(result,msg,isZip)
	local this = self
	if result == true then
	    local config = self.m_tabUpdateQueue[1]
	    if nil ~= config then
            if true == config.isBase then
                self.isNeedReStart = true
            end
            if true == config.isBase and isZip ~= true then
                   --更新本地大厅版本
	    		self:getApp()._version:setVersion(self._newBaseVersion)
	    	elseif true == config.isClient and isZip ~= true then
	    		--更新本地大厅版本
	    		self:getApp()._version:setResVersion(self._newResVersion)
	    	end
            table.remove(self.m_tabUpdateQueue, 1)
	    	self:goUpdate()
	    else
            self.txtShow:setString("Transferência concluída")
            --下载完毕，进登录界面之前要重新走一遍main.lua
            this:resetMain()
	    end
	else   
		self:updateBar(0)
        self.txtShow:setString("Download falhou")
		--重试询问
		local dialog = QueryDialog:create(msg.."\n se deve tentar novamente?",function(bReTry)
				if bReTry == true then
					this:goUpdate()
				else
					os.exit(0)
				end
			end)
        self:addChild(dialog)
	end
end

function WelcomeScene:updateBar(percent)
    self.sliderLine:setPercent(percent)
    self.sliderLine:show()
    self.txtPercent:setString( string.format("%d%%", percent))
    self.txtPercent:show()
    self.sliderHead:setPositionX(display.width/100*percent)
end

function WelcomeScene:getMachineId()
    if g_TargetPlatform == cc.PLATFORM_OS_WINDOWS then
        local mac = CCGetWinMac()
        return md5(mac)
    elseif g_TargetPlatform == cc.PLATFORM_OS_ANDROID then        
        local sigs = "()Ljava/lang/String;"
        local func = "getUUID"
        if FunctionName and FunctionName["getUUID"] and FunctionName["getUUID"]~="" then
            func = FunctionName["getUUID"]
        end
        local ok,ret = luaj.callStaticMethod(BridgeClassName.BRIDGE_CLASS_ACTIVITY,func,{},sigs)
        if not ok then
            print("luaj error:" .. ret)
            return md5("MNADIndj1983749jdnahNNHJ")
        else
            print("The ret is:" .. ret)
            return md5(ret)
        end   
    elseif g_TargetPlatform == cc.PLATFORM_OS_IPHONE or targetPlatform == cc.PLATFORM_OS_IPAD then
       local ok,ret = luaoc.callStaticMethod(BRIDGE_CLASS_IOS,"getUUID")
       if not ok then
           print("luaj error:" .. ret)
           return md5("MNADIndj1983749jdnahNNHJ")
       else
           print("The ret is:" .. ret)
           return md5(ret)
       end
    end
end

function WelcomeScene:applyFunction(func, params)
    if func then
        if params then
            func(unpack(params))
        else
            func()
        end
    end
end

function WelcomeScene.pushCaller(tip, func, scope)
    tip = tip or "";
    local vo = { func = func, scope = scope, tip = tip };
    table.insert(_callersArr, vo);
end

--下载完毕，进登录界面之前要重新走一遍main.lua
function WelcomeScene:resetMain()
    cc.Director:getInstance():getTextureCache():removeAllTextures()
    cc.SpriteFrameCache:getInstance():removeSpriteFrames()
    cc.FileUtils:getInstance():purgeCachedEntries()
    cc.Director:getInstance():purgeCachedData()
    if tickMgr then
        tickMgr:stopTick()
    end

    local moduleStr = {"LuaDebugjit","math","string","table","io","debug","_G","coroutine"}
    for k,v in pairs(package.loaded) do
        local isHad = false
        for ks,str in pairs(moduleStr) do
            if k == str then
                isHad = true
                break
            end
        end
        if not isHad then
            package.loaded[k] = nil
        end
    end
    local array = {        
        cc.DelayTime:create(2),
        cc.CallFunc:create(function() 
            require("base.src.main")
        end)
    }
    self:runAction(cc.Sequence:create(array))
   -- require("app.MyApp").new():run(false)
end

return WelcomeScene