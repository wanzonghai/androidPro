//
// Created by billy on 2023/10/13.
//
#include <jni.h>
#include <sys/types.h>
#include <android/log.h>
#include <unistd.h>
#include <fcntl.h>
#include <android/asset_manager_jni.h>
#include <sys/system_properties.h>
#include <thread>
#include <locale.h>

#include <android/looper.h>
#include <unistd.h>


#include "JNIUtils.h"
#include "aes.h"
#include "jni_config.h"
#include "AdjustSdk.h"

#include "GameEngine.h"

const char* adjustKey =  "9f6ffyz5wk5c";
const char* environment = "sandbox"; //"production"  "sandbox"
extern jobject m_Ctx;

//adjustSdk类名 用于注册
#define  ADJUST_Listener_CLASS_NAME         "common/adjustSdk$MyAdjustListener"
#define  ADJUST_Callback_CLASS_NAME         "common/adjustSdk$MyAdjustCallback"


//adjustSdk类名。当类名变的时候改这里
#define ADJUST_Listener_NAME_SPACE(x)       Java_common_adjustSdk_00024MyAdjustListener_ ##x
#define ADJUST_Callback_NAME_SPACE(x)       Java_common_adjustSdk_00024MyAdjustCallback_ ##x


#define cc(x,y) x ## y
#define DEF_THIS_ARGS JNIEnv* env,jobject thiz
#define MAKE_FUNCTION(prex, rv,nm, ...)    \
extern "C" JNIEXPORT rv JNICALL prex(nm)  (DEF_THIS_ARGS,##__VA_ARGS__)

#define GET_FUNCTION(prex,nm) prex(nm)

//实现  MyAdjustListener 类的 JNI 方法
MAKE_FUNCTION(ADJUST_Listener_NAME_SPACE,void,onAttributionChanged,jobject attribution){
    //这里是回调
    // 获取AdjustAttribution类和AdjustAttribution对象的信息
    jclass adjustAttributionClass = env->FindClass("com/adjust/sdk/AdjustAttribution");
    jfieldID attributionField = env->GetFieldID(adjustAttributionClass, "trackerName", "Ljava/lang/String;");
    jstring trackerNameString = (jstring)env->GetObjectField(attribution, attributionField);

    // 调用getTrackerName方法获取trackerName字符串
    const char* trackerName = env->GetStringUTFChars(trackerNameString, NULL);
    LOGI("trackerNameString 1= %s", trackerName);
    mg_pGameEngine->SetAdjustTrackerName(trackerName);
    // 释放资源
    env->ReleaseStringUTFChars(trackerNameString, trackerName);

}


// 实现 MyAdjustCallback 类的 JNI 方法
MAKE_FUNCTION(ADJUST_Callback_NAME_SPACE,void,onActivityCreated, jobject activity, jobject bundle) {
    // 在这里实现 onActivityCreated 方法的逻辑
    jclass adjustClass = env->FindClass("com/adjust/sdk/Adjust");
    jmethodID getAttributionMethod = env->GetStaticMethodID(adjustClass, "getAttribution", "()Lcom/adjust/sdk/AdjustAttribution;");
    jobject attribution = env->CallStaticObjectMethod(adjustClass, getAttributionMethod);
    if (attribution != nullptr){
        LOGD("===========attribution 1= %s", attribution);
        jclass adjustAttributionClass = env->FindClass("com/adjust/sdk/AdjustAttribution");
        jfieldID attributionField = env->GetFieldID(adjustAttributionClass, "trackerName", "Ljava/lang/String;");
        jstring trackerNameString = (jstring)env->GetObjectField(attribution, attributionField);
        const char* trackerName = env->GetStringUTFChars(trackerNameString, NULL);
        LOGI("trackerNameString 2= %s", trackerName);
    }else{
        LOGD("===========attribution 2= %s", attribution);
    }
}

MAKE_FUNCTION(ADJUST_Callback_NAME_SPACE,void,onActivityStarted, jobject activity) {
    // 在这里实现 onActivityStarted 方法的逻辑
}

MAKE_FUNCTION(ADJUST_Callback_NAME_SPACE,void,onActivityResumed, jobject activity) {
    // 在这里实现 onActivityResumed 方法的逻辑
    jclass adjustClass = env->FindClass("com/adjust/sdk/Adjust");
    jmethodID onResumeMethod = env->GetStaticMethodID(adjustClass, "onResume", "()V");
    env->CallStaticVoidMethod(adjustClass, onResumeMethod);
}

MAKE_FUNCTION(ADJUST_Callback_NAME_SPACE,void,onActivityPaused, jobject activity) {
    // 在这里实现 onActivityPaused 方法的逻辑
    jclass adjustClass = env->FindClass("com/adjust/sdk/Adjust");
    jmethodID onPauseMethod = env->GetStaticMethodID(adjustClass, "onPause", "()V");
    env->CallStaticVoidMethod(adjustClass, onPauseMethod);
}

MAKE_FUNCTION(ADJUST_Callback_NAME_SPACE,void,onActivityStopped, jobject activity) {
    // 在这里实现 onActivityStopped 方法的逻辑
}

MAKE_FUNCTION(ADJUST_Callback_NAME_SPACE,void,onActivitySaveInstanceState, jobject activity, jobject bundle) {
    // 在这里实现 onActivitySaveInstanceState 方法的逻辑
}

MAKE_FUNCTION(ADJUST_Callback_NAME_SPACE,void,onActivityDestroyed, jobject activity) {
    // 在这里实现 onActivityDestroyed 方法的逻辑
}

bool AdjustSdkInit(JNIEnv* env, jobject  app) {
    // 获取AdjustConfig类和Adjust类
    jclass cls_AdjustConfig = env->FindClass("com/adjust/sdk/AdjustConfig");
    jclass cls_Adjust = env->FindClass("com/adjust/sdk/Adjust");
    jclass cls_Application = env->FindClass("android/app/Application");


    jstring str_Key = env->NewStringUTF(adjustKey);
    jstring str_Env = env->NewStringUTF(environment);

    // 创建AdjustConfig对象
    jmethodID  mid_NewAdjustConfig = env->GetMethodID(cls_AdjustConfig,
                                                      "<init>",
                                                      "(Landroid/content/Context;Ljava/lang/String;Ljava/lang/String;)V"
    );
    jobject obj_AdjustConfig = env->NewObject(cls_AdjustConfig, mid_NewAdjustConfig, m_Ctx ,str_Key, str_Env );

    // 设置日志级别
    jclass cls_AdjustLog = env->FindClass("com/adjust/sdk/LogLevel");
    jfieldID  fld_VERBOSE = env->GetStaticFieldID(cls_AdjustLog,"VERBOSE", "Lcom/adjust/sdk/LogLevel;");
    jobject obj_LogLevel = env->GetStaticObjectField(cls_AdjustLog, fld_VERBOSE);
    jmethodID mid_setLogLevel = env->GetMethodID(cls_AdjustConfig, "setLogLevel", "(Lcom/adjust/sdk/LogLevel;)V");
    env->CallVoidMethod(obj_AdjustConfig, mid_setLogLevel, obj_LogLevel); //LogLevel.VERBOSE


    // 设置AttributionChangedListener
    jclass cls_Listener = env->FindClass(ADJUST_Listener_CLASS_NAME);
    jmethodID mid_ListenerConstructor = env->GetMethodID(cls_Listener,"<init>", "()V" );
    jobject obj_Listener = env->NewObject(cls_Listener, mid_ListenerConstructor);
    jmethodID mid_SetOnAttributionChangedListener = env->GetMethodID(cls_AdjustConfig,
                                                                     "setOnAttributionChangedListener",
                                                                     "(Lcom/adjust/sdk/OnAttributionChangedListener;)V");
    env->CallVoidMethod(obj_AdjustConfig, mid_SetOnAttributionChangedListener, obj_Listener);

    // 调用Adjust.onCreate(config)
    jmethodID mid_AdjustonCreate = env->GetStaticMethodID(cls_Adjust, "onCreate", "(Lcom/adjust/sdk/AdjustConfig;)V");
    env->CallStaticVoidMethod(cls_Adjust,mid_AdjustonCreate, obj_AdjustConfig);

    // 注册AdjustLifecycleCallbacks
    jmethodID mid_RegisterCallbacks = env->GetMethodID(cls_Application,
                                                       "registerActivityLifecycleCallbacks",
                                                       "(Landroid/app/Application$ActivityLifecycleCallbacks;)V");

    jclass cls_Callbask = env->FindClass(ADJUST_Callback_CLASS_NAME);
    jmethodID mid_NewCallback = env->GetMethodID(cls_Callbask, "<init>", "()V");
    jobject  obj_Callback = env->NewObject(cls_Callbask, mid_NewCallback);

    env->CallVoidMethod(app, mid_RegisterCallbacks, obj_Callback);

//    env->DeleteLocalRef(logLevelInstance);
//    env->DeleteLocalRef(logLevelName);
    env->DeleteLocalRef(obj_LogLevel);
    env->DeleteLocalRef(obj_Listener);
    env->DeleteLocalRef(obj_Callback);
    env->DeleteLocalRef(obj_AdjustConfig);

    env->DeleteLocalRef(str_Key);
    env->DeleteLocalRef(str_Env);
    return true;
}