
-- 0 - disable debug info, 1 - less debug info, 2 - verbose debug info
DEBUG = 2

-- use framework, will disable all deprecated API, false - use legacy API
CC_USE_FRAMEWORK = true

-- show FPS on screen
CC_SHOW_FPS = false

-- disable create unexpected global variable
CC_DISABLE_GLOBAL = false
--是否开启渠道获取
CHANNEL_OPEN = true
--是否开启通知
NOTIFICATION_OPEN = true
--是否网络优化
NET_OPTIMIZE_OPEN = true
--是否网络二次优化
NET_SECOND_OPTIMIZE_OPEN = true
--是否可以截图保存到相册
CAN_CAPTURE_CAMEAR = true
--是否是白名单
IS_WHITE_LIST = false
--是否支持定时通知
ALARM_NOTIFICATION_OPEN = true
--是否支持横竖版切换
CHANGE_ORIENTATION_OPEN =  true
--更新修改
HOTFIX_UPGRADATION = true
--获取剪贴板内容
GETCLIPBOARDTEXT = true
--支持项目切换
PROJECT_SWITCH_SUPPORT = true
--是否需要强等Adjust Attribution
ADJUST_ATTRIBUTION_FORCE = true

FunctionName = {
    getUUID = "getUUID",
    getHostAdress = "getHostAdress",
    getSDCardDocPath = "getSDCardDocPath",
    pickImg = "pickImg",
    thirdPartyConfig = "thirdPartyConfig",
    SetWxAccessTokenOpenID = "SetWxAccessTokenOpenID",
    thirdLogin = "thirdLogin",
    startShare = "startShare",
    customShare = "customShare",
    shareToTarget = "shareToTarget",
    thirdPartyPay = "thirdPartyPay",
    OpenThirdUrl = "OpenThirdUrl",
    isPlatformInstalled = "isPlatformInstalled",
    jumpTo3rdApp = "jumpTo3rdApp",
    saveImgToSystemGallery = "saveImgToSystemGallery",
    isHaveRecordPermission = "isHaveRecordPermission",
    requestLocation = "requestLocation",
    metersBetweenLocation = "metersBetweenLocation",
    requestContact = "requestContact",
    openBrowser = "openBrowser",
    copyToClipboard = "copyToClipboard",
    GoogleLogin = "GoogleLogin",
    FaceBookLogin = "FaceBookLogin",
    mobShare = "mobShare",
    getChannelId = "getChannelId",
    PushNotification = "PushNotification",
    PushImageNotification = "PushImageNotification",
    SetAlarmNotification = "SetAlarmNotification",
    ChangeOrientation = "ChangeOrientation",
    getClipboardText = "getClipboardText",
    
    getAFID = "getAfId",
    appsFlyerEvent= "appsFlyerEvent",

    adjustLogEvent = "adjustLogEvent",
    getAdjustId = "getAdid",
    getAdjustGoogleAdId = "getGoogleAdid",
    getAdjustKey = "getAdjustKey",
    getAdjustStatus = "getAdjustStatus",
    getAdjustAttribution = "getAdjustAttribution",
    getFireBaseToken = "getFireBaseToken",
}

BridgeClassName = {
    BRIDGE_CLASS_ACTIVITY = "fs/fers/ZzGameLoasufMhwopyw87",
    BRIDGE_CLASS_AF = "truco/three/afsdk/AfSdk",
    BRIDGE_CLASS_ADJUST = "truco/three/adjustsdk/AdjustSdk",
    BRIDGE_CLASS_FIREBASE = "truco/three/firebasesdk/MyFirebaseMessagingService",
}

getThreeDataJson = function()
    if cc.FileUtils:getInstance():isFileExist("base/threeSdkSwitch.json") then
        local josn = cc.FileUtils:getInstance():getStringFromFile("base/threeSdkSwitch.json")
        return cjson.decode(josn)
    else
        return {}
    end
end

ChannelData = function()
    if cc.FileUtils:getInstance():isFileExist("base/ChannelConfig.json") then
        local josn = cc.FileUtils:getInstance():getStringFromFile("base/ChannelConfig.json")
        return cjson.decode(josn)
    else
        return {}
    end
end

AfLogEventName = {
    af_login = "af_login",
    af_revenue = "af_purchase", 
}

ADLogEventName = {
    ad_Token                        ="dtm9kdwbmeww",
    ad_app_open                     ="u2888s",
    ad_click_phone_login            ="mums2t",
    ad_click_google_login           ="z1blst",
    ad_click_guest_login            ="xeglr0",
    ad_phone_login_success          ="3alhln",
    ad_google_login_success         ="5q4ys8",
    ad_guest_login_success          ="lvbllw",
    ad_register                     ="ue1ghz",    
    ad_purchase_click_button        ="la8mnu",
    ad_purchase_click               ="4o0bqx",
    ad_firstRevenue                 ="midwq5",
    ad_revenue                      ="p7p5ey",
    ad_recharge_withdraw_difference ="oe9ktj",
    ad_withdraw_success             ="a3cmox",
}

CC_DESIGN_RESOLUTION = {
    width = 1920,--1136,
    height = 1080,--640,
    autoscale = "FIXED_WIDTH",
	
    callback = function(framesize)
        -- local ratio = framesize.width / framesize.height
        local ratio = framesize.width / framesize.height
        if ratio < 1920 / 1080 then
            -- iPad 768*1024(1536*2048) is 4:3 screen
            return {autoscale = "FIXED_WIDTH"}
        else
            return {autoscale = "FIXED_HEIGHT"}
        end
    end
}

OFFICIAL_LOGIN = true

VERSION_INIT_ZIP_BASE = 2
VERSION_INIT_ZIP_CLIENT = 2