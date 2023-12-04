ylAll = ylAll or {}
ylAll.WIDTH								    = 1920
ylAll.HEIGHT								= 1080
ylAll.MAX_INT                               = 2 ^ 15
ylAll.DEVICE_TYPE							= 0x10
--设备类型
ylAll.DEVICE_TYPE_LIST = {}
ylAll.DEVICE_TYPE_LIST[cc.PLATFORM_OS_WINDOWS] 	= 0x00
ylAll.DEVICE_TYPE_LIST[cc.PLATFORM_OS_ANDROID] 	= 0x11
ylAll.DEVICE_TYPE_LIST[cc.PLATFORM_OS_IPHONE] 	= 0x31
ylAll.DEVICE_TYPE_LIST[cc.PLATFORM_OS_IPAD] 	= 0x41

ylAll.QuitLayer                             = nil   --全局退游提示框
ylAll.touchTime                             = 0.5   --触摸最小间隔
ylAll.SERVER_UPDATE_DATA                    = {}        --zip版本号
ylAll.ipAddr                                = {}    
ylAll.NormalNetDelay                        = {}        --网络配置相关
ylAll.UPDATE_OPEN                           = true      --开启更新
ylAll.LOGONSERVER_LIST                      = {}        --ip

local Localization   = cc.UserDefault:getInstance()
local ServerLocal = Localization:getStringForKey("ServerUrl","")
--热更地址配置
ylAll.HotfixUrl = {
    {
        "http://172.17.18.61/TrucoClube/1Local",             --巴西金币项目(Truco Clube) A*本地
        "http://172.17.18.241:888/Brazil/",                  --巴西金币项目(Truco Clube) 内网(230)
        "https://down.happyday66.com/brazil_res/",           --巴西金币项目(Truco Clube) 外网(平行服)
        "http://down.9oeh2.com/brazil_res/",                 --巴西金币项目(Truco Clube) 外网(正式服)
    },
    {
        "http://172.17.18.61/PresenteSlots/1Local/",         --巴西真金项目(Truco King) A*本地
        "http://172.17.18.241:888/Component/",               --巴西真金项目(Truco King) 内网(230)
        "http://down2.gngqyxxk.com/brazil_res/",             --巴西真金项目(Truco King) 外网(平行服)
        "http://zjdown.easygameapi.com/brazil_res/",         --巴西真金项目(Truco King) 外网(正式服)
    },
}

--服务器地址配置
ylAll.ServerUrl = {
    {
        ServerLocal~="" and ServerLocal or "115@172.17.18.230:2701|1",                      --巴西金币项目(Truco Clube) 开发服
        "116@172.17.18.241:2701|1",                                                         --巴西金币项目(Truco Clube) 内网(230)
        "117@8.212.53.120:2701|1",                                                          --巴西金币项目(Truco Clube) 外网(平行服)--8.218.73.66
        "10@152.32.197.243:2701|1",                                                         --巴西金币项目(Truco Clube) 外网(正式服)
    },
    {
        ServerLocal~="" and ServerLocal or "215@172.17.18.241:2701|4",                       --巴西真金项目(Truco King) 开发服 暂未提供
        "216@172.17.18.241:2701|4",                                                          --巴西真金项目(Truco King) 内网   暂未提供 
        "217@8.217.77.235:2701|4",                                                           --巴西真金项目(Truco King) 外网(平行服)
        "20@zj-pro.kh423n.com:2701|4",                                                       --巴西真金项目(Truco King) 外网(正式服)
    },
}

local Localization   = cc.UserDefault:getInstance()
ylAll.LocalTest      = Localization:getBoolForKey("LocalTest",false)         --测试选择
ylAll.ProjectSelect  = ylAll.LocalTest and Localization:getIntegerForKey("ProjectSelect",2) or 2      --项目选择 (1:巴西金币项目(Truco Clube),2:巴西真金项目(Truco King))
ylAll.HotfixSelect   = ylAll.LocalTest and Localization:getIntegerForKey("HotfixSelect", 4) or 4      --热更选择 (1-4 四个环境选择,上线需要切换为4)
ylAll.ServerSelect   = ylAll.LocalTest and Localization:getIntegerForKey("ServerSelect", 4) or 4      --服务器选择 (1-4 四个环境选择,上线需要切换为4)

ylAll.Request_HttpUrl = ylAll.HotfixUrl[ylAll.ProjectSelect][ylAll.HotfixSelect]
local pServerUrl = ylAll.ServerUrl[ylAll.ProjectSelect][ylAll.ServerSelect]
local pArray = string.split(pServerUrl,"@")
ylAll.LOGONSERVER_LIST = {{id= pArray[1],ip= pArray[2]}}