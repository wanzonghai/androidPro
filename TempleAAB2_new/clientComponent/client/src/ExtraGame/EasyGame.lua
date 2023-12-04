--[[
    EasyGame 游戏更新与进入
    1.开发环境本地不保留EasyGame文件
    2.热更配置根据 ylAll.SERVER_UPDATE_DATA.update_url_easy_game 下version.json EasyGame 游戏厂商维护
    3.子游戏 远端存放：ylAll.SERVER_UPDATE_DATA.update_url_easy_game 下 $gameID.zip
    4.子游戏 本地存储：device.writablePath.."EasyGame/" 下
]]

local EasyGame = class("EasyGame")

EasyGame.FixInfo = {
    LocalPath = device.writablePath.."EasyGame/",
    LocalFile = device.writablePath.."EasyGame/local.json",
    RemotePath = ylAll.SERVER_UPDATE_DATA.update_url_easy_game or "",    
}

function EasyGame:LoadVersion()
    --创建文件夹
    if not createDirectory(self.FixInfo.LocalPath) then        
        return
    end
    --本地版本号
    self.LocalVesion = {}
    if cc.FileUtils:getInstance():isFileExist(self.FixInfo.LocalFile) then
        local jsonStr = cc.FileUtils:getInstance():getStringFromFile(self.FixInfo.LocalFile)
        self.LocalVesion = cjson.decode(jsonStr)
    end
    --远端版本号
    self.RemoteVersion = ylAll.SERVER_UPDATE_DATA.easy_game_version    
end

--检查是否需要热更
function EasyGame:CheckFix(pID)
    local result = true
    if self.RemoteVersion[tostring(pID)] then
        result = true
        local pR = self.RemoteVersion[tostring(pID)]
        local pL = self.LocalVesion[tostring(pID)]
        if pR and pL and pR == pL then
            result = false
        end 
    end
    return result      
end

--启动热更
function EasyGame:StartFix(pID)
    
    local fileName = pID..".zip" 
    local savePath = self.FixInfo.LocalPath                     --下载地址
    local downPath = self.FixInfo.RemotePath..fileName          --保存地址
    -- downFileAsync(downPath,fileName,savePath,function(main,sub) 
    --     if main == appdf.DOWN_PRO_INFO then --进度信息
    --         if GlobalData.DownloadListener and not tolua.isnull(GlobalData.DownloadListener) then
    --             GlobalData.DownloadListener:updateProgress(nil,nil,sub)
    --         end
    --     elseif main == appdf.DOWN_COMPELETED then --下载完毕
    --         self:Unzip(pID)
    --     else
    --         if GlobalData.DownloadListener and not tolua.isnull(GlobalData.DownloadListener) then
    --             GlobalData.DownloadListener:updateResult(false,"Download falhou,main:" .. main) --失败信息
    --         else
    --             GlobalData.DownloadGameList[GlobalData.DownloadGameID] = nil
    --             GlobalData.DownloadGameID = nil
    --             GlobalData.DownloadGameInfo = {}
    --         end
    --     end
    -- end)
    appdf.DownloadZip(
        downPath,
        savePath..fileName,
        function(progress)
            if GlobalData.DownloadListener and not tolua.isnull(GlobalData.DownloadListener) then
                GlobalData.DownloadListener:updateProgress(nil,nil,progress)
            end
        end,
        function(success)
            if success then
                self:Unzip(pID)
            else
                if GlobalData.DownloadListener and not tolua.isnull(GlobalData.DownloadListener) then
                    GlobalData.DownloadListener:updateResult(false,"Download falhou") --失败信息
                else
                    if GlobalData.DownloadGameList and GlobalData.DownloadGameID then
                        GlobalData.DownloadGameList[GlobalData.DownloadGameID] = nil
                    end
                    GlobalData.DownloadGameID = nil
                    GlobalData.DownloadGameInfo = {}
                end
            end
        end
    )

    -- Updater:create():Downloader(
    --     downPath,
    --     savePath..fileName,
    --     function(progress)
    --         if GlobalData.DownloadListener and not tolua.isnull(GlobalData.DownloadListener) then
    --             GlobalData.DownloadListener:updateProgress(nil,nil,progress)
    --         end
    --     end,
    --     function(success)
    --         if success then
    --             self:Unzip(pID)
    --         else
    --             if GlobalData.DownloadListener and not tolua.isnull(GlobalData.DownloadListener) then
    --                 GlobalData.DownloadListener:updateResult(false,"Download falhou") --失败信息
    --             else
    --                 if GlobalData.DownloadGameList and GlobalData.DownloadGameID then
    --                     GlobalData.DownloadGameList[GlobalData.DownloadGameID] = nil
    --                 end
    --                 GlobalData.DownloadGameID = nil
    --                 GlobalData.DownloadGameInfo = {}
    --             end
    --         end
    --     end
    -- )
end

--解压文件 
function EasyGame:Unzip(pID)
    local filePath = self.FixInfo.LocalPath..pID..".zip"
    local unzipPath = self.FixInfo.LocalPath..pID.."/"
    if not createDirectory(unzipPath) then
        print("创建文件夹".. pID.."失败")
        if GlobalData.DownloadListener and not tolua.isnull(GlobalData.DownloadListener) then
            GlobalData.DownloadListener:updateResult(false,"Unzip falhou,main:" .. "can't create directory!") --失败信息
        else
            if GlobalData.DownloadGameList and GlobalData.DownloadGameID then
                GlobalData.DownloadGameList[GlobalData.DownloadGameID] = nil
            end
            GlobalData.DownloadGameID = nil
            GlobalData.DownloadGameInfo = {}
        end
        return
    end
    unZipAsync(filePath,unzipPath,function(result)
        print("zip解压完成"..result)
        cc.FileUtils:getInstance():removeFile(self.FixInfo.LocalPath..pID..".zip")
        self:SaveFile(pID)  --下载解压完，保存新的配置文件
    end)  
end

--覆盖保存config文件
function EasyGame:SaveFile(pID)
    self.LocalVesion[tostring(pID)] = self.RemoteVersion[tostring(pID)]
    local pContent = cjson.encode(self.LocalVesion)   
    local dir = self.FixInfo.LocalFile
    local hfile = io.open(self.FixInfo.LocalFile, "w+")
    hfile:write(pContent)
    hfile:close()
    if GlobalData.DownloadListener and not tolua.isnull(GlobalData.DownloadListener) then
        GlobalData.DownloadListener:updateResult(true,"") --更新完毕
    else
        if GlobalData.DownloadGameList and GlobalData.DownloadGameID then
            GlobalData.DownloadGameList[GlobalData.DownloadGameID] = nil
        end
        GlobalData.DownloadGameID = nil
        GlobalData.DownloadGameInfo = {}
    end
end

--进入游戏
function EasyGame:EnterGame(pID,pExtraParams,cbGameMode)
    local P1,P2,pRoomID = string.find(pExtraParams,"roomID=(%d+)")    
    local pID = pRoomID or pID
    GlobalUserItem.roomMark = tonumber(pID)*1000+90+1
    local path = ""
    local url = ""    
    path = "file://"..self.FixInfo.LocalPath..tostring(pID).."/" --热更目录
    url = path.."index.html?"..pExtraParams
    -- if IS_WHITE_LIST then
    --     --白名单 EG增加调试参数
    --     url = path.."index.html?"..pExtraParams.."&isdbg=hxdebug"
    -- end

    if OSUtil.isFolderExists(path) then
        print("目录存在："..path)
        if io.exists(url) then
            print("文件存在：："..url)
        end
    end
    if self.webView and not tolua.isnull(self.webView) then
        self.webView:loadURL(url)
        return
    end
    local webView = ccexp.WebView:create()
    webView:setContentSize(cc.size(display.width,display.height))    
    webView:setAnchorPoint(cc.p(0,0))
    webView:setJavascriptInterfaceScheme("lua")
    if webView.setOnJSCallback == nil then
        print("lua 未绑定 setOnJSCallback ,请更新项目引擎代码")
        -- return
    else
        webView:setOnJSCallback(function(sender,url)  
            if url == "lua://Close.api.command" then
                self.webView:removeFromParent()
                self.webView = nil
                G_GameFrame:StandUp()
                G_ServerMgr:C2S_RequestUserGold()
                G_event:NotifyEvent(G_eventDef.UI_EXIT_TABLE)
                self:SetEasyGameStatus(false) 
            end
            if url == "lua://args?" then
                --回传参数
            end
        end)
    end
    
    webView:setScalesPageToFit(true)
    webView:loadURL(url)
    local parent = cc.Director:getInstance():getRunningScene()
    parent:addChild(webView)
    self.webView = webView    
    G_event:NotifyEvent(G_eventDef.UI_GAMEKIND_ONEXIT)
    webView:setOnShouldStartLoading(function(sender,url)
        print("setOnShouldStartLoading url is " , url)
        local target = cc.Application:getInstance():getTargetPlatform()
	    if target == cc.PLATFORM_OS_IPHONE or target == cc.PLATFORM_OS_IPAD then
            if url == "lua://Close.api.command" then
                self.webView:removeFromParent()
                self.webView = nil
                G_GameFrame:StandUp()
                G_ServerMgr:C2S_RequestUserGold()
                G_event:NotifyEvent(G_eventDef.UI_EXIT_TABLE)   
                self:SetEasyGameStatus(false)         
            end
            if url == "lua://args?" then
                --回传参数
            end
        end
        return true
    end)
    webView:setOnDidFinishLoading(function(sender,url)
        print("onWebView1DidFinishLoading url is " , url)
    end)
    webView:setOnDidFailLoading(function(sender,url)
        print("onWebView1DidFailLoading url is " , url)
    end)  
    webView:reload()
    self:SetEasyGameStatus(true)
end

function EasyGame:GetEasyGameStatus()
    return self.EasyGameStatus
end

function EasyGame:SetEasyGameStatus(pStatus)
    self.EasyGameStatus = pStatus
end

return EasyGame