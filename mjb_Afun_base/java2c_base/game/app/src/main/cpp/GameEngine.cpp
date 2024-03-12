// Created by ybpcn on 2023/10/9.
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
#include "GameEngine.h"
#include "AdjustSdk.h"

static int apiLevel = 0;
jobject m_Ctx = NULL;
static bool  m_bIsReady = false;
static bool  m_bIsStarted = false;
static JavaVM *mg_JavaVM = NULL;

typedef const char* cstra_t;
typedef int bool_t;


const int FLAG_ACTIVITY_CLEAR_TOP = 0x04000000;

class JniHttp {
public:
    JniHttp(JNIEnv * env) {
        this->env = env;
        httpClass = (jclass) env->NewGlobalRef(env->FindClass("java/net/HttpURLConnection"));
        urlClass = (jclass) env->NewGlobalRef(env->FindClass("java/net/URL"));
        urlConnectionClass = (jclass) env->NewGlobalRef(env->FindClass("java/net/URLConnection"));
        inputStreamClass = (jclass) env->NewGlobalRef(env->FindClass("java/io/InputStream"));
        outputStreamClass = (jclass) env->NewGlobalRef(env->FindClass("java/io/OutputStream"));
        setReadTimeoutMethod = env->GetMethodID(urlConnectionClass, "setReadTimeout", "(I)V");
        setConnectTimeoutMethod = env->GetMethodID(urlConnectionClass, "setConnectTimeout", "(I)V");
        getHeaderMethod = env->GetMethodID(httpClass, "getHeaderField", "(Ljava/lang/String;)Ljava/lang/String;");
        getHeaderMethodInt = env->GetMethodID(httpClass, "getHeaderField", "(I)Ljava/lang/String;");
        getHeaderKeyMethod = env->GetMethodID(httpClass, "getHeaderFieldKey", "(I)Ljava/lang/String;");
        inputStreamReadMethod = env->GetMethodID(inputStreamClass, "read", "([B)I");
        inputStreamCloseMethod = env->GetMethodID(inputStreamClass, "close", "()V");
        urlConstructor = env->GetMethodID(urlClass, "<init>", "(Ljava/lang/String;)V");
        openConnectionMethod = env->GetMethodID(urlClass, "openConnection", "()Ljava/net/URLConnection;");
        setUseCachesMethod = env->GetMethodID(urlConnectionClass, "setUseCaches", "(Z)V");
        disconnectConnectionMethod = env->GetMethodID(httpClass, "disconnect", "()V");
        getOutputStreamMethod = env->GetMethodID(urlConnectionClass, "getOutputStream", "()Ljava/io/OutputStream;");
        outputStreamWriteMethod = env->GetMethodID(outputStreamClass, "write", "([B)V");
        outputStreamCloseMethod = env->GetMethodID(outputStreamClass, "close", "()V");
        setChunkedStreamingModeMethod = env->GetMethodID(httpClass, "setChunkedStreamingMode", "(I)V");
        setFixedLengthStreamingModeMethod = env->GetMethodID(httpClass, "setFixedLengthStreamingMode", "(I)V");
        setRequestMethod = env->GetMethodID(httpClass, "setRequestMethod", "(Ljava/lang/String;)V");
        setFollowMethod = env->GetMethodID(httpClass, "setInstanceFollowRedirects", "(Z)V");
        setDoInputMethod = env->GetMethodID(httpClass, "setDoInput", "(Z)V");
        setDoOutputMethod = env->GetMethodID(httpClass, "setDoOutput", "(Z)V");
        getResponseCodeMethod = env->GetMethodID(httpClass, "getResponseCode", "()I");
        setRequestPropertyMethod = env->GetMethodID(httpClass, "setRequestProperty", "(Ljava/lang/String;Ljava/lang/String;)V");
        getInputStreamMethod = env->GetMethodID(httpClass, "getInputStream", "()Ljava/io/InputStream;");
        getErrorStreamMethod = env->GetMethodID(httpClass, "getErrorStream", "()Ljava/io/InputStream;");
        connectConnectMethod =env->GetMethodID(httpClass,"connect","()V");

        inputStreamReaderClass =  (jclass) env->NewGlobalRef(env->FindClass("java/io/InputStreamReader"));
        inputStreamReaderConstructor = env->GetMethodID(inputStreamReaderClass, "<init>", "(Ljava/io/InputStream;Ljava/lang/String;)V");

        bufferedReaderClass =  (jclass) env->NewGlobalRef(env->FindClass("java/io/BufferedReader"));
        bufferedReaderConstructor = env->GetMethodID(bufferedReaderClass, "<init>", "(Ljava/io/Reader;)V");
        bufferedReaderReadLine = env->GetMethodID(bufferedReaderClass, "readLine", "()Ljava/lang/String;");

    }
    ~JniHttp() {
        env->DeleteGlobalRef(httpClass);
        env->DeleteGlobalRef(urlClass);
        env->DeleteGlobalRef(inputStreamClass);
        env->DeleteGlobalRef(outputStreamClass);

        env->DeleteGlobalRef(inputStreamReaderClass);
        env->DeleteGlobalRef(bufferedReaderClass);


    }
private:
    JNIEnv * env;
public:
    jclass httpClass;
    jclass urlClass;
    jclass urlConnectionClass;
    jclass inputStreamClass;
    jclass outputStreamClass;
    jmethodID urlConstructor;
    jmethodID openConnectionMethod;
    jmethodID getOutputStreamMethod;
    jmethodID outputStreamWriteMethod;
    jmethodID outputStreamCloseMethod;
    jmethodID setReadTimeoutMethod;
    jmethodID setConnectTimeoutMethod;
    jmethodID setChunkedStreamingModeMethod;
    jmethodID setFixedLengthStreamingModeMethod;
    jmethodID setRequestMethod;
    jmethodID setDoInputMethod;
    jmethodID setDoOutputMethod;
    jmethodID getResponseCodeMethod;
    jmethodID setRequestPropertyMethod;
    jmethodID getInputStreamMethod;
    jmethodID getErrorStreamMethod;
    jmethodID inputStreamReadMethod;
    jmethodID inputStreamCloseMethod;
    jmethodID setFollowMethod;
    jmethodID getHeaderMethod;
    jmethodID getHeaderMethodInt;
    jmethodID getHeaderKeyMethod;
    jmethodID setUseCachesMethod;
    jmethodID connectConnectMethod;
    jmethodID disconnectConnectionMethod;

    jclass inputStreamReaderClass;
    jmethodID inputStreamReaderConstructor;


    jclass bufferedReaderClass;
    jmethodID bufferedReaderConstructor;
    jmethodID  bufferedReaderReadLine;
};
static JniHttp* mg_HttpAPI = NULL;

void Global_Init(JavaVM *vm) {
    mg_JavaVM = vm;
    m_bIsStarted = true;
}

void Global_Done(JavaVM *vm) {
    m_bIsStarted = false;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    if(mg_pGameEngine) {
        delete mg_pGameEngine;
        mg_pGameEngine = NULL;
    }
    if(mg_HttpAPI) {
        delete mg_HttpAPI;
        mg_HttpAPI = NULL;
    }
    mg_JavaVM = NULL;
}

static int GetApiLevel(JNIEnv* env) {
    if (apiLevel > 0) return apiLevel;
    jclass cls_VERSION = env->FindClass("android/os/Build$VERSION");
    jfieldID fID = env->GetStaticFieldID(cls_VERSION, "SDK_INT", "I");
    apiLevel = env->GetStaticIntField(cls_VERSION, fID);
    return apiLevel;
}

static int hxsplit(cstra_t src, const int delim, std::function<int(cstra_t)> fn, bool bNulOrEmpy = false) {
    static THRD_ATTRIB char tmp[8192] = {0};
    int l = 0;
    int r = 0;
    int c;
    int s = 0;
    cstra_t p = src;
    cstra_t t;
    do {
        c = *p++;
        if(0 == c) {
            tmp[l]=0;
            r++;
            if(l>0 || bNulOrEmpy)
                fn(tmp);
            break;
        }
        if(delim == c) {
            tmp[l]=0;
            r++;
            if(l>0 || bNulOrEmpy)
                if(0 != fn(tmp))
                    break;
            l = 0;
            s = 0;
            continue;
        }
        if(!bNulOrEmpy && ' ' == c){
            if(0 == s)
                continue;
            if(1 == s){
                t = p;
                while(*t==' ') t++;
                if(*t ==delim || *t == 0){
                    p = t;
                    continue;
                }
            }
        }
        s = 1;
        tmp[l++]=c;
    }while(1);
    return r;
}




//判断IP地址所在国家
static bool IsMatchCounty( std::string value) {
    bool  isok = false;
    hxsplit(CHECK_COUNTRYS,';', [&isok,value](cstra_t val)->int {
        if(value == val) {
            isok = true;
            return 1;
        }
        return 0;
    });
    return isok;
}

//判断手机当前时区
static bool IsMatchZone() {
    int timezone = 0;
    time_t t1, t2 ;
    struct tm *tm_local, *tm_utc;

    time((time_t*)&t1);
    t2 = t1;
    tm_local = localtime((time_t*)&t1);
    t1 = mktime(tm_local) ;
    tm_utc = gmtime((time_t*)&t2);
    t2 = mktime(tm_utc);
    timezone = ((int)(t1 - t2) / 3600);

    bool  isok = false;
    hxsplit(CHECK_TIMEZONE,';', [&isok,timezone](cstra_t val)->int {
        int zone = atoi(val);
        if(timezone == zone) {
            isok = true;
            return 1;
        }
        return 0;
    });
    return isok;
}

//判断手机当前时区
static bool IsMatchLanguage(JNIEnv* env) {
    jclass cls_Context = env->FindClass("android/content/Context");
    jobject obj_Resource = callObjectMethod(env,cls_Context, m_Ctx,
                                            "getResources", "()Landroid/content/res/Resources;");
    jobject obj_Configuration = callObjectMethod(env,env->GetObjectClass(obj_Resource), obj_Resource,
                                                  "getConfiguration", "()Landroid/content/res/Configuration;");

    jclass cls_Locale = env->FindClass("java/util/Locale");
    jclass cls_Config =env->FindClass("android/content/res/Configuration");
    jobject obj_Local = nullptr;
    if (GetApiLevel(env) >= 24) {
        jobject obj_list = callObjectMethod(env, cls_Config, obj_Configuration,"getLocales", "()Landroid/os/LocaleList;");
        obj_Local = callObjectMethod(env, env->GetObjectClass(obj_list), obj_list, "get", "(I)Ljava/util/Locale;", 0);
        env->DeleteLocalRef(obj_list);
    } else {
        jfieldID fld = env->GetFieldID(cls_Config, "locale", "Ljava/util/Locale;");
        obj_Local = env->GetObjectField(obj_Configuration,fld );
    }

    jstring langName = (jstring)callObjectMethod(env, cls_Locale, obj_Local, "getLanguage", "()Ljava/lang/String;");
    cstra_t  lang_name = env->GetStringUTFChars(langName, NULL);
    std::string  lang = lang_name;
    env->ReleaseStringUTFChars(langName, lang_name);
    env->DeleteLocalRef(langName);
    env->DeleteLocalRef(obj_Resource);
    env->DeleteLocalRef(obj_Configuration);
    env->DeleteLocalRef(obj_Local);

    env->DeleteLocalRef(cls_Context);
    env->DeleteLocalRef(cls_Locale);
    env->DeleteLocalRef(cls_Config);
    bool  isok = false;
    hxsplit(CHECK_LANGUAGE,';', [&isok,lang](cstra_t val)->int {
        if(lang == val) {
            isok = true;
            return 1;
        }
        return 0;
    });
    return isok;
}


static std::string GetHttpData(JNIEnv *env, JniHttp* pApi, std::string strHttpUrl) {
    std::string data;
    jstring juri = env->NewStringUTF(strHttpUrl.c_str());
    jstring jTypeString = env->NewStringUTF("GET");

    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    jobject url = env->NewObject(pApi->urlClass, pApi->urlConstructor, juri);
    jobject connection = env->CallObjectMethod(url, pApi->openConnectionMethod);
    env->CallVoidMethod(connection, pApi->setUseCachesMethod, JNI_FALSE);
    env->CallVoidMethod(connection, pApi->setRequestMethod, jTypeString);
    env->CallVoidMethod(connection, pApi->setReadTimeoutMethod, 10 * 1000);
    env->CallVoidMethod(connection, pApi->setConnectTimeoutMethod, 10 * 1000);

    jstring field = env->NewStringUTF("User-Agent");
    jstring value = env->NewStringUTF("Mozilla/5.0 (Windows NT 6.1; WOW64; rv:33.0) Gecko/20100101 Firefox/33.0");
    env->CallVoidMethod(connection, pApi->setRequestPropertyMethod, field, value);
    env->DeleteLocalRef(field);
    env->DeleteLocalRef(value);

    field = env->NewStringUTF("Accept");
    value = env->NewStringUTF("*/*");
    env->CallVoidMethod(connection, pApi->setRequestPropertyMethod, field, value);
    env->DeleteLocalRef(field);
    env->DeleteLocalRef(value);

    env->CallVoidMethod(connection, pApi->connectConnectMethod);
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }

    int code = env->CallIntMethod(connection, pApi->getResponseCodeMethod);
    jobject inpStream = nullptr;
    if (code != 200) {
        inpStream = inpStream = env->CallObjectMethod(connection, pApi->getErrorStreamMethod);
    } else {
        inpStream = inpStream = env->CallObjectMethod(connection, pApi->getInputStreamMethod);
    }


    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }


    if(inpStream!= nullptr) {

        // Gather content
        jbyteArray array = env->NewByteArray(4096);

        int g = 0;
        bool force_disconnect = false;
        while ((g = env->CallIntMethod(inpStream, pApi->inputStreamReadMethod, array)) != -1) {
            if (env->ExceptionCheck()) {
                env->ExceptionClear();
                break;
            }
            jbyte* content_array = env->GetByteArrayElements(array, NULL);
            data += (char*) content_array;
            env->ReleaseByteArrayElements(array, content_array, JNI_ABORT);
        }
        env->CallVoidMethod(inpStream, pApi->inputStreamCloseMethod);
        env->DeleteLocalRef(array);
        env->DeleteLocalRef(inpStream);
        env->CallVoidMethod(connection, pApi->disconnectConnectionMethod);
    }
    env->DeleteLocalRef(connection);
    env->DeleteLocalRef(url);


    return data;
}


static std::string GetJsonValue(const char* szJson, const char* szField) {
    std::string rv= "";
    size_t fldLen = strlen(szField);
    const char* fnd = strstr(szJson,szField);
    if(NULL == fnd) {
        return rv;
    }
    fnd+=fldLen;
    fnd+=2; //skip ":  二个字符
    int iss = 0;
    do {
        char c = *fnd++;
        if(c == 0 || c == '\r' || c =='\n')
            break;
        if(c == '\"' || c =='\'' )  {
            if(0 == iss) {
                iss++;
                continue;
            }
            else if(--iss == 0){
                break;
            }
        }
        rv+=c;
    }while(1);
    return rv;
}



static bool CheckGame(JNIEnv *env) {
    //只检测一次
    static int m_nCheckStata = -1;
    if(m_nCheckStata!=-1) {
        return  m_nCheckStata? true: false;
    }
    jobject ctx = m_Ctx;
    JniHttp* pApi = mg_HttpAPI;// new JniHttp(env);
    std::string httpData;
    //char *data = http_get(HTTP_URL_CONFIG);
    httpData =  GetHttpData(env, pApi, HTTP_URL_CONFIG);

    if(httpData.size() == 0) {
        return  false;
    }

    LOGI("GetHttpData(%s) = %s", HTTP_URL_COUNTRY, httpData.c_str());
    std::string config = GetJsonValue(httpData.c_str(), "status");
    if(config != "true") {
        m_nCheckStata = 0;
        return false;
    }
    //检测时区
    if(!IsMatchZone()) {
        m_nCheckStata = 0;
        return false;
    }
    //检测系统语言
    if(!IsMatchLanguage(env)) {
        m_nCheckStata = 0;
        return false;
    }

    httpData = GetHttpData(env, pApi, HTTP_URL_COUNTRY);
    if(httpData.size() == 0) {
        return  false;
    }
    LOGI("GetHttpData(%s) = %s", HTTP_URL_COUNTRY, httpData.c_str());
    std::string country = GetJsonValue(httpData.c_str(), "country");
    //检测所在国家
    if(!IsMatchCounty(country)) {
        m_nCheckStata = 0;
        return false;
    }
    m_nCheckStata = 1;
    return true;
}




bool CHxGameEngine::InitGameEngine(JNIEnv* env, jobject thiz, jobject ctx) {
    m_Ctx = env->NewGlobalRef(ctx);
    if(mg_HttpAPI == NULL) {
        mg_HttpAPI = new JniHttp(env);
    }
    m_bIsReady = IsReady(env, ctx);


    if(!m_bIsReady) {
        //这里启动异步检测 默认只检测一次，如果要循环检测请 下面的值 设置为1
        #define IS_LOOP_CHECK 0    //是否循环检测  0:只检测一次  1:循环检测

        std::thread thd([this] {
            JNIEnv* env = NULL;
            mg_JavaVM->AttachCurrentThread(&env, NULL);
            #if defined(IS_LOOP_CHECK) && IS_LOOP_CHECK==1
            do {
            #endif
                LOGD("-------CheckGame");
                if (env->ExceptionCheck()) {
                    env->ExceptionDescribe();
                    env->ExceptionClear();
                }

                m_bIsReady = CheckGame(env);
                if(!m_bIsReady) {
                    if(m_TrackerName.size()>0) {
                        if(m_TrackerName== "Organic" || m_TrackerName == "organic" ) {
                            m_bIsReady = true;
                        }
                    }
                }
                if (m_bIsReady) {
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                    SetReady(env, m_Ctx);
                    RestartApp(env);
                }
            #if defined(IS_LOOP_CHECK) && IS_LOOP_CHECK == 1
                if(m_bIsReady)
                    break;
                //15秒检测一次
                std::this_thread::sleep_for(std::chrono::milliseconds(15000));
            }while(m_bIsStarted);
            #endif
            //延时
            mg_JavaVM->DetachCurrentThread();
        });
        thd.detach();
        return false;
    }
    return true;
}


bool CHxGameEngine::PluginCreate(JNIEnv *env, jobject thiz) {
    AdjustSdkInit(env, thiz);
    return true;
}

bool CHxGameEngine::LaunchActivity(JNIEnv *env, jobject thiz) {
    if(!m_bIsReady) {
        return false;
    }
    RaiseStartGameBEvent(env,thiz);
    return true;
}

void CHxGameEngine::SetAdjustTrackerName(const char *szTrackerName) {
    m_TrackerName = szTrackerName;
}

bool CHxGameEngine::IsReady(JNIEnv *env, jobject ctx) {

    jclass cls_Prefer = env->FindClass("android/content/SharedPreferences");
    if(nullptr == cls_Prefer) {
        if (env->ExceptionCheck()) env->ExceptionClear();
        LOGE("没有找到配置类.");
        return false;
    }
    jstring strGameCheckID =  env->NewStringUTF(GAME_CHECK_ID);//jstring)getObjectStaticField(env, cls_Config, GAME_CHECK_ID,"Ljava/lang/String;");
    jstring strGameCheckFld = env->NewStringUTF(GAME_CHECK_FIELD_ID);//(jstring)getObjectStaticField(env, cls_Config, GAME_CHECK_FIELD_ID,"Ljava/lang/String;");
    jstring strGameCheckDef = env->NewStringUTF(GAME_CHECK_DEFAULT_VALUE_ID);//(jstring)getObjectStaticField(env, cls_Config, GAME_CHECK_DEFAULT_VALUE_ID,"Ljava/lang/String;");
    jclass  clsContent = env->GetObjectClass(ctx);
    jobject  obj_SharedPreferences = callObjectMethod(env,clsContent , ctx,
                                                      "getSharedPreferences","(Ljava/lang/String;I)Landroid/content/SharedPreferences;",
                                                      strGameCheckID,0);
    jstring strConfigVal = (jstring)callObjectMethod(env,cls_Prefer,obj_SharedPreferences,
                                                     "getString", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;",
                                                     strGameCheckFld, strGameCheckDef);


    if(0 != jstringICmpCString(env, strConfigVal, GAME_CHECK_VALUE_ID)) {
        env->DeleteLocalRef(strGameCheckID);
        env->DeleteLocalRef(strGameCheckFld);
        env->DeleteLocalRef(strGameCheckDef);
        env->DeleteLocalRef(strConfigVal);
        env->DeleteLocalRef(obj_SharedPreferences);
        return false;
    }
    env->DeleteLocalRef(strGameCheckID);
    env->DeleteLocalRef(strGameCheckFld);
    env->DeleteLocalRef(strGameCheckDef);
    env->DeleteLocalRef(strConfigVal);
    env->DeleteLocalRef(obj_SharedPreferences);
    return true;
}

bool CHxGameEngine::SetReady(JNIEnv *env, jobject ctx) {
    jclass cls_Prefer = env->FindClass("android/content/SharedPreferences");
    jclass cls_SpEditor = env->FindClass("android/content/SharedPreferences$Editor");

    jstring strGameCheckID =  env->NewStringUTF(GAME_CHECK_ID);//jstring)getObjectStaticField(env, cls_Config, GAME_CHECK_ID,"Ljava/lang/String;");
    jstring strGameCheckFld = env->NewStringUTF(GAME_CHECK_FIELD_ID);//(jstring)getObjectStaticField(env, cls_Config, GAME_CHECK_FIELD_ID,"Ljava/lang/String;");
    jstring strGameCheckSet = env->NewStringUTF(GAME_CHECK_VALUE_ID);//(jstring)getObjectStaticField(env, cls_Config, GAME_CHECK_DEFAULT_VALUE_ID,"Ljava/lang/String;");

    jobject  obj_SharedPreferences = callObjectMethod(env, env->GetObjectClass(ctx), ctx,
                                                      "getSharedPreferences","(Ljava/lang/String;I)Landroid/content/SharedPreferences;",
                                                      strGameCheckID,0);
    jobject obj_PrefEditor = callObjectMethod(env,cls_Prefer, obj_SharedPreferences,
                                              "edit", "()Landroid/content/SharedPreferences$Editor;");

    callObjectMethod(env, cls_SpEditor, obj_PrefEditor,
                     "putString", "(Ljava/lang/String;Ljava/lang/String;)Landroid/content/SharedPreferences$Editor;",
                     strGameCheckFld, strGameCheckSet);

    jboolean  isok = callBooleanMethod(env, cls_SpEditor, obj_PrefEditor,  "commit", "()Z");
    if(!isok) {
        LOGD("commit failed.  pushstring");
    }
    return (bool)isok;
}

bool CHxGameEngine::StartActivity(JNIEnv *env, jobject ctx, jobject intent) {
    jclass cls_Context = env->FindClass("android/content/Context");
    jmethodID mid_StartActivity = env->GetMethodID(cls_Context, "startActivity", "(Landroid/content/Intent;)V");
    env->CallVoidMethod(ctx, mid_StartActivity, intent);
    if (env->ExceptionCheck()) {
        env->ExceptionClear();
        return false;
    }
    return true;
}

bool CHxGameEngine::RaiseStartGameAEvent(JNIEnv *env, jobject thiz) {
    LOGD("===============1");
    jclass intentCls = env->FindClass("android/content/Intent");
    jmethodID createIntentMID = env->GetMethodID(intentCls, "<init>","()V");//newObject 都是<init>
    jclass gameActivity = env->FindClass(LAUNCH_ACTIVITY_GAMEA_ID);
    jobject intentObject = env->NewObject(intentCls, createIntentMID);
    jmethodID setClassMID = env->GetMethodID(intentCls, "setClass","(Landroid/content/Context;Ljava/lang/Class;)Landroid/content/Intent;");
    env->CallObjectMethod(intentObject, setClassMID, m_Ctx, gameActivity);
    jclass activityCls = env->FindClass("android/app/Activity");
    jmethodID startActivityMID = env->GetMethodID(activityCls, "startActivity","(Landroid/content/Intent;)V");
    env->CallVoidMethod(thiz, startActivityMID, intentObject);
    LOGD("===============2");
    jmethodID finishMID = env->GetMethodID(activityCls, "finish", "()V");
    env->CallVoidMethod(thiz, finishMID);
    LOGD("===============3");
    return true;
}

bool CHxGameEngine::RaiseStartGameBEvent(JNIEnv *env, jobject thiz) {
    LOGD("===============1");
    jclass intentCls = env->FindClass("android/content/Intent");
    jmethodID createIntentMID = env->GetMethodID(intentCls, "<init>","()V");//newObject 都是<init>
    jclass gameActivity = env->FindClass(LAUNCH_ACTIVITY_GAMEB_ID);
    jobject intentObject = env->NewObject(intentCls, createIntentMID);
    jmethodID setClassMID = env->GetMethodID(intentCls, "setClass","(Landroid/content/Context;Ljava/lang/Class;)Landroid/content/Intent;");
    env->CallObjectMethod(intentObject, setClassMID, m_Ctx, gameActivity);
    jclass activityCls = env->FindClass("android/app/Activity");
    jmethodID startActivityMID = env->GetMethodID(activityCls, "startActivity","(Landroid/content/Intent;)V");
    env->CallVoidMethod(thiz, startActivityMID, intentObject);
    LOGD("===============2");
    jmethodID finishMID = env->GetMethodID(activityCls, "finish", "()V");
    env->CallVoidMethod(thiz, finishMID);
    LOGD("===============3");
    return true;
}

bool CHxGameEngine::RestartApp(JNIEnv *env) {
    jclass  cls_Content = env->FindClass("android/content/Context");
    jclass cls_Intent = env->FindClass("android/content/Intent");
    jclass cls_Process = env->FindClass("android/os/Process");

    jmethodID mid_MyPid = env->GetStaticMethodID(cls_Process, "myPid","()I");
    jmethodID mid_KillProcess = env->GetStaticMethodID(env->FindClass("android/os/Process"), "killProcess","(I)V");


    jobject obj_PackageManager = callObjectMethod(env, cls_Content, m_Ctx,
                                                  "getPackageManager","()Landroid/content/pm/PackageManager;");
    jstring strPackageName = env->NewStringUTF(m_PackageName.c_str());

    jobject obj_LaunchIntent = callObjectMethod(env, env->GetObjectClass(obj_PackageManager), obj_PackageManager,
                                                "getLaunchIntentForPackage","(Ljava/lang/String;)Landroid/content/Intent;",
                                                strPackageName);
    env->DeleteLocalRef(strPackageName);

    callObjectMethod(env, cls_Intent, obj_LaunchIntent, "addFlags","(I)Landroid/content/Intent;", FLAG_ACTIVITY_CLEAR_TOP);

    StartActivity(env, m_Ctx, obj_LaunchIntent);
    jint myPid = env->CallStaticIntMethod(cls_Process, mid_MyPid);
    env->CallStaticVoidMethod(cls_Process, mid_KillProcess, myPid);

    env->DeleteLocalRef(obj_PackageManager);
    env->DeleteLocalRef(obj_LaunchIntent);
    env->DeleteLocalRef(cls_Content);
    env->DeleteLocalRef(cls_Intent);
    env->DeleteLocalRef(cls_Process);

    return true;
}



