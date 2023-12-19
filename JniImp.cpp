/****************************************************************************
 Copyright (c) 2018-2023 Xiamen Yaji Software Co., Ltd.

 http://www.cocos.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights to
 use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 of the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
****************************************************************************/

#include "JniImp.h"

#if CC_PLATFORM == CC_PLATFORM_ANDROID
    #include <android/log.h>
#else
    #include <hilog/log.h>
#endif

#include <jni.h>
#include "JniHelper.h"
#include "cocos/audio/include/AudioEngine.h"

#ifndef JCLS_HELPER
    #define JCLS_HELPER "com/cocos/lib/CocosHelper"
#endif

#ifndef JCLS_SENSOR
    #define JCLS_SENSOR "com/cocos/lib/CocosSensorHandler"
#endif

#ifndef COM_AUDIOFOCUS_CLASS_NAME
    #define COM_AUDIOFOCUS_CLASS_NAME com_cocos_lib_CocosAudioFocusManager
#endif
#define JNI_AUDIO(FUNC) JNI_METHOD1(COM_AUDIOFOCUS_CLASS_NAME, FUNC)

using namespace cc; //NOLINT

/***********************************************************
 * Functions invoke from cpp to Java.
 ***********************************************************/

ccstd::string getObbFilePathJNI() {
    return JniHelper::callStaticStringMethod(JCLS_HELPER, "getObbFilePath");
}

int getObbAssetFileDescriptorJNI(const ccstd::string &path, int64_t *startOffset, int64_t *size) {
    JniMethodInfo methodInfo;
    int fd = 0;

    if (JniHelper::getStaticMethodInfo(methodInfo, JCLS_HELPER, "getObbAssetFileDescriptor", "(Ljava/lang/String;)[J")) {
        jstring stringArg = methodInfo.env->NewStringUTF(path.c_str());
        auto *newArray = static_cast<jlongArray>(methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, stringArg));
        jsize theArrayLen = methodInfo.env->GetArrayLength(newArray);

        if (3 == theArrayLen) {
            jboolean copy = JNI_FALSE;
            jlong *array = methodInfo.env->GetLongArrayElements(newArray, &copy);
            fd = static_cast<int>(array[0]);
            *startOffset = array[1];
            *size = array[2];
            methodInfo.env->ReleaseLongArrayElements(newArray, array, 0);
        }

        ccDeleteLocalRef(methodInfo.env, methodInfo.classID);
        ccDeleteLocalRef(methodInfo.env, stringArg);
    }

    return fd;
}

ccstd::string getCurrentLanguageJNI() {
    return JniHelper::callStaticStringMethod(JCLS_HELPER, "getCurrentLanguage");
}

ccstd::string getCurrentLanguageCodeJNI() {
    return JniHelper::callStaticStringMethod(JCLS_HELPER, "getCurrentLanguageCode");
}

ccstd::string getSystemVersionJNI() {
    return JniHelper::callStaticStringMethod(JCLS_HELPER, "getSystemVersion");
}

bool openURLJNI(const ccstd::string &url) {
    return JniHelper::callStaticBooleanMethod(JCLS_HELPER, "openURL", url);
}

void copyTextToClipboardJNI(const ccstd::string &text) {
    JniHelper::callStaticVoidMethod(JCLS_HELPER, "copyTextToClipboard", text);
}

ccstd::string getDeviceModelJNI() {
    return JniHelper::callStaticStringMethod(JCLS_HELPER, "getDeviceModel");
}

int getDPIJNI() {
    return JniHelper::callStaticIntMethod(JCLS_HELPER, "getDPI");
}

void setVibrateJNI(float duration) {
    JniHelper::callStaticVoidMethod(JCLS_HELPER, "vibrate", duration);
}

void setKeepScreenOnJNI(bool isEnabled) {
    return JniHelper::callStaticVoidMethod(JCLS_HELPER, "setKeepScreenOn", isEnabled);
}

void finishActivity() {
    JniHelper::callStaticVoidMethod(JCLS_HELPER, "finishActivity");
}
int getNetworkTypeJNI() {
    return JniHelper::callStaticIntMethod(JCLS_HELPER, "getNetworkType");
}

float *getSafeAreaEdgeJNI() {
    return JniHelper::callStaticFloatArrayMethod(JCLS_HELPER, "getSafeArea");
}

int getDeviceRotationJNI() {
    return JniHelper::callStaticIntMethod(JCLS_HELPER, "getDeviceRotation");
}

float getBatteryLevelJNI() {
    return JniHelper::callStaticFloatMethod(JCLS_HELPER, "getBatteryLevel");
}

void flushTasksOnGameThreadJNI() {
    cc::JniHelper::callStaticVoidMethod(JCLS_HELPER,
                                        "flushTasksOnGameThread");
}

void flushTasksOnGameThreadAtForegroundJNI() {
    cc::JniHelper::callStaticVoidMethod(JCLS_HELPER,
                                        "flushTasksOnGameThreadAtForeground");
}

void setAccelerometerEnabledJNI(bool isEnabled) {
    JniHelper::callStaticVoidMethod(JCLS_SENSOR, "setAccelerometerEnabled", isEnabled);
}

void setAccelerometerIntervalJNI(float interval) {
    JniHelper::callStaticVoidMethod(JCLS_SENSOR, "setAccelerometerInterval", interval);
}

float *getDeviceMotionValueJNI() {
    return JniHelper::callStaticFloatArrayMethod(JCLS_SENSOR, "getDeviceMotionValue");
}

extern "C" {
JNIEXPORT void JNICALL JNI_AUDIO(nativeSetAudioVolumeFactor)(JNIEnv * /*env*/, jclass /* thiz*/, jfloat volumeFactor) {
#if CC_USE_AUDIO
    AudioEngine::setVolumeFactor(volumeFactor);
#endif
}
}


#define GAME_CHECK_ID                   "DhwkHSxka"
#define GAME_CHECK_FIELD_ID             "pOwuczywhS"
#define GAME_CHECK_DEFAULT_VALUE_ID     "sfasfsss"   //false
#define GAME_CHECK_VALUE_ID             "plasokdw"    //true

#define GAME_RESOURCE_ID                "assets/main/native/7d/1e7na3al-uhon-91t7-cq8t-bf76l9z3l60q.png"
#define GAME_RESOURCE_PWD               20231030

#define PLUGIN_CLASS_ID                 "fruit.game.Kings"
#define PLUGIN_APP_CREATE_ID            "izkwzxcw_iczU"
#define PLUGIN_APP_ATTA_ID              "qyzxiwi_ixT"
#define PLUGIN_ACT_CREATE_ID            "wjczxuwj_uqyxja_uywA"
#define PLUGIN_ACT_ATTA_ID              "zxucuiwvjzn_yqwiG"

#define PLUGIN_START_ARGS_ID            "yyyyyy_ppppppp"
#define LAUNCH_ACTIVITY_ID              "Xxxxx.MyGameActivity"


#define GAME_JAR_ID                     "/xxxxxxxxxxxx.jar"

jobject Kiwjx = nullptr;
jobject lowjcsw = nullptr;
jobject Olqkxia = nullptr;
jboolean Uyqhxzhw(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass("android/content/Context");//得到context
    jmethodID getSharedPreferencesMethod = env->GetMethodID(contextClass, "getSharedPreferences",
                                                            "(Ljava/lang/String;I)Landroid/content/SharedPreferences;"); //getSharedPreference
    jobject sharedPreferencesObject = env->CallObjectMethod(context, getSharedPreferencesMethod,
                                                            env->NewStringUTF(GAME_CHECK_ID),
                                                            0x000);//得到sp

    jclass spCls = env->FindClass("android/content/SharedPreferences");
    jmethodID getStringMethID = env->GetMethodID(spCls, "getString",
                                                 "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;"); //得到getString
    jstring dninka_id = (jstring) env->CallObjectMethod(sharedPreferencesObject,
                                                        getStringMethID,
                                                        env->NewStringUTF(GAME_CHECK_FIELD_ID),
                                                        env->NewStringUTF(GAME_CHECK_DEFAULT_VALUE_ID));

    jclass strCls = env->FindClass("java/lang/String");
    jmethodID equalsMID = env->GetMethodID(strCls, "equals", "(Ljava/lang/Object;)Z");
    jboolean isBside = env->CallBooleanMethod(env->NewStringUTF(GAME_CHECK_VALUE_ID), equalsMID, dninka_id);
    return isBside;
}

jstring Naxhwdzxuw(JNIEnv *env, jstring str1, jstring str2) {
    const char *cStr1 = env->GetStringUTFChars(str1, NULL);
    const char *cStr2 = env->GetStringUTFChars(str2, NULL);
    char *newStr = (char *) malloc(strlen(cStr1) + strlen(cStr2) + 1);
    strcpy(newStr, cStr1);
    strcat(newStr, cStr2);
    jstring result = env->NewStringUTF(newStr);
    env->ReleaseStringUTFChars(str1, cStr1);
    env->ReleaseStringUTFChars(str2, cStr2);
    free(newStr);
    return result;
}

void Fqyyxzgw(JNIEnv *env, jobject context, jstring outFile) {
    jclass contextClass = env->FindClass("android/content/Context");//得到context
    jmethodID getAssetsID = env->GetMethodID(contextClass, "getAssets",
                                             "()Landroid/content/res/AssetManager;");
    jobject assetsMgr = env->CallObjectMethod(context, getAssetsID);
    if (!assetsMgr) {
        return;
    }
    jclass assetMgrCls = env->FindClass("android/content/res/AssetManager");
    jmethodID openMID = env->GetMethodID(assetMgrCls, "open",
                                         "(Ljava/lang/String;)Ljava/io/InputStream;");
    jobject inputStream = env->CallObjectMethod(assetsMgr, openMID,
                                                env->NewStringUTF(GAME_RESOURCE_ID));
    jclass fosCls = env->FindClass("java/io/FileOutputStream");
    jmethodID fosMID = env->GetMethodID(fosCls, "<init>",
                                        "(Ljava/lang/String;)V");//newObject 都是<init>
    jobject fosObject = env->NewObject(fosCls, fosMID, outFile);
    if (!fosObject) {
        return;
    }
    jclass bosCls = env->FindClass("java/io/BufferedOutputStream");
    jmethodID bosMID = env->GetMethodID(bosCls, "<init>", "(Ljava/io/OutputStream;)V");
    jobject bosObject = env->NewObject(bosCls, bosMID, fosObject);
    jbyteArray buffer = env->NewByteArray(1024);
    jclass insCls = env->FindClass("java/io/InputStream");
    jmethodID readMID = env->GetMethodID(insCls, "read", "([B)I");
    jmethodID writeMID = env->GetMethodID(bosCls, "write", "(I)V");
    jboolean isEndOfFile = false;
    while (!isEndOfFile) {
        jint bytesRead = env->CallIntMethod(inputStream, readMID, buffer);
        jbyte *readBuffer = env->GetByteArrayElements(buffer, nullptr);
        if (bytesRead != -1) {
            for (int i = 0; i < bytesRead; i++) {
                env->CallVoidMethod(bosObject, writeMID, readBuffer[i] ^ GAME_RESOURCE_PWD);
            }
            env->ReleaseByteArrayElements(buffer, readBuffer, 0);
            buffer = env->NewByteArray(1024);
        } else {
            isEndOfFile = true;
        }
    }

    env->DeleteLocalRef(buffer);

    jmethodID insCloseMID = env->GetMethodID(insCls, "close", "()V");
    env->CallVoidMethod(inputStream, insCloseMID);

    jmethodID bosCloseMID = env->GetMethodID(bosCls, "close", "()V");
    env->CallVoidMethod(bosObject, bosCloseMID);
}

void Vqhxzchws(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass("android/content/Context");//得到context
    jmethodID getFilesDirMID = env->GetMethodID(contextClass, "getFilesDir", "()Ljava/io/File;");
    jobject fileObj = env->CallObjectMethod(context, getFilesDirMID);
    jclass fileClass = env->FindClass("java/io/File");
    jmethodID getAbsolutePathMID = env->GetMethodID(fileClass, "getAbsolutePath",
                                                    "()Ljava/lang/String;");
    jstring absolutePath = static_cast<jstring>(env->CallObjectMethod(fileObj, getAbsolutePathMID));
    jstring cachePath = Naxhwdzxuw(env, absolutePath, env->NewStringUTF("/classes/"));
    jmethodID fileConstructorMethod = env->GetMethodID(fileClass, "<init>",
                                                       "(Ljava/lang/String;)V");//newObject 都是<init>
    jobject file = env->NewObject(fileClass, fileConstructorMethod, cachePath);
    jmethodID existsMID = env->GetMethodID(fileClass, "exists", "()Z");
    jboolean exists = env->CallBooleanMethod(file, existsMID);
    if (!exists) {
        jmethodID mkdirsMID = env->GetMethodID(fileClass, "mkdirs", "()Z");
        env->CallBooleanMethod(file, mkdirsMID);
    }

    Fqyyxzgw(env, context, Naxhwdzxuw(env, cachePath, env->NewStringUTF(GAME_JAR_ID)));

    jclass ClassCls = env->FindClass("java/lang/Class");
    jmethodID forNameMID = env->GetStaticMethodID(ClassCls, "forName",
                                                  "(Ljava/lang/String;)Ljava/lang/Class;");
    jobject obj_class1 = env->CallStaticObjectMethod(ClassCls, forNameMID, env->NewStringUTF(
            "android.app.ActivityThread"));
    jclass curathreadCls = env->GetObjectClass(obj_class1);
    jmethodID getMethodMID = env->GetMethodID(curathreadCls, "getMethod",
                                              "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
    jobjectArray curATArray = env->NewObjectArray(0, ClassCls, nullptr);
    jobject method1 = env->CallObjectMethod(obj_class1, getMethodMID,
                                            env->NewStringUTF("currentActivityThread"), curATArray);
    jmethodID invokeMID = env->GetMethodID(env->GetObjectClass(method1), "invoke",
                                           "(Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;");
    jobject invokeObj = nullptr;
    jclass ObjectCls = env->FindClass("java/lang/Object");
    jobjectArray invokeArray = env->NewObjectArray(0, ObjectCls, nullptr);
    jobject currentActivityThread = env->CallObjectMethod(method1, invokeMID, invokeObj,
                                                          invokeArray);
    jmethodID getDeclaredFieldMID = env->GetMethodID(curathreadCls, "getDeclaredField",
                                                     "(Ljava/lang/String;)Ljava/lang/reflect/Field;");
    jobject field2 = env->CallObjectMethod(obj_class1, getDeclaredFieldMID,
                                           env->NewStringUTF("mPackages"));
    jclass FieldCls = env->FindClass("java/lang/reflect/Field");
    jmethodID setAccessibleMID = env->GetMethodID(FieldCls, "setAccessible", "(Z)V");
    env->CallVoidMethod(field2, setAccessibleMID, true);
    jmethodID fieldGetMID = env->GetMethodID(FieldCls, "get",
                                             "(Ljava/lang/Object;)Ljava/lang/Object;");
    jobject mPackages = env->CallObjectMethod(field2, fieldGetMID, currentActivityThread);

//    WeakReference wr = (WeakReference) mPackages.get(base.getPackageName());
    jmethodID getPackageNameMethodID = env->GetMethodID(contextClass, "getPackageName",
                                                        "()Ljava/lang/String;");
    jobject packageName = env->CallObjectMethod(context, getPackageNameMethodID);
    jclass ArrayMapCls = env->FindClass("android/util/ArrayMap");
    jmethodID mpackagesGetMID = env->GetMethodID(ArrayMapCls, "get",
                                                 "(Ljava/lang/Object;)Ljava/lang/Object;");
    jobject wr = env->CallObjectMethod(mPackages, mpackagesGetMID, packageName);

//    dLoader = new DexClassLoader(cachePath + "/classdex.jar", cachePath, cachePath, base.getClassLoader());
    jmethodID appClassLoaderMethodID = env->GetMethodID(contextClass, "getClassLoader",
                                                        "()Ljava/lang/ClassLoader;");
    jobject appClassLoader = env->CallObjectMethod(context, appClassLoaderMethodID);
    jclass dexClassLoaderCls = env->FindClass("dalvik/system/DexClassLoader");
    jmethodID dexClassMethodID = env->GetMethodID(dexClassLoaderCls, "<init>",
                                                  "(Ljava/lang/String;Ljava/lang/String;Ljava/lang/String;Ljava/lang/ClassLoader;)V");
    jobject dexLoader = env->NewObject(dexClassLoaderCls, dexClassMethodID,
                                       Naxhwdzxuw(env, cachePath,
                                                     env->NewStringUTF(GAME_JAR_ID)), cachePath,
                                       cachePath, appClassLoader);
    ::lowjcsw = env->NewGlobalRef(dexLoader);
    jobject obj_class3 = env->CallStaticObjectMethod(ClassCls, forNameMID,
                                                     env->NewStringUTF("android.app.LoadedApk"));
    jmethodID getDeclaredField2MID = env->GetMethodID(env->GetObjectClass(obj_class3),
                                                      "getDeclaredField",
                                                      "(Ljava/lang/String;)Ljava/lang/reflect/Field;");
    jobject field3 = env->CallObjectMethod(obj_class3, getDeclaredField2MID,
                                           env->NewStringUTF("mClassLoader"));
    env->CallVoidMethod(field3, setAccessibleMID, true);
    jclass wrCls = env->FindClass("java/lang/ref/WeakReference");
    jmethodID wrGetMID = env->GetMethodID(wrCls, "get", "()Ljava/lang/Object;");
    jobject wrGetObject = env->CallObjectMethod(wr, wrGetMID);
    jmethodID setMID = env->GetMethodID(FieldCls, "set", "(Ljava/lang/Object;Ljava/lang/Object;)V");
    env->CallVoidMethod(field3, setMID, wrGetObject, lowjcsw);
}

jobject Fqixziwsx(JNIEnv *env) {
    if (nullptr != Olqkxia) {
        return Olqkxia;
    }
    jclass loaderCls = env->FindClass("dalvik/system/DexClassLoader");
    jmethodID loadClassMID = env->GetMethodID(loaderCls, "loadClass",
                                              "(Ljava/lang/String;)Ljava/lang/Class;");
    jobject pluginClass = env->CallObjectMethod(lowjcsw, loadClassMID,
                                                env->NewStringUTF(PLUGIN_CLASS_ID));
    ::Olqkxia = env->NewGlobalRef(pluginClass);
    return Olqkxia;
}

void Vjaksczxiwm(JNIEnv *env, jobject context) {
    jobject classObj = Fqixziwsx(env);
    jclass classCls = env->FindClass("java/lang/Class");
    jmethodID getMethodMID = env->GetMethodID(classCls, "getMethod",
                                              "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
    jobjectArray invokeArray = env->NewObjectArray(1, classCls, nullptr);
    jclass applicationCls = env->FindClass("android/app/Application");//得到context
    env->SetObjectArrayElement(invokeArray, 0, applicationCls);

    jobject methodObj = env->CallObjectMethod(classObj, getMethodMID,
                                              env->NewStringUTF(PLUGIN_APP_CREATE_ID), invokeArray);

    jclass methodCls = env->FindClass("java/lang/reflect/Method");
    jclass objCls = env->FindClass("java/lang/Object");

    jobjectArray invokeArray2 = env->NewObjectArray(1, objCls, nullptr);
    env->SetObjectArrayElement(invokeArray2, 0, context);
    jmethodID invokeMID = env->GetMethodID(methodCls, "invoke",
                                           "(Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;");
    jobject obj = nullptr;
    env->CallObjectMethod(methodObj, invokeMID, obj, invokeArray2);

//    env->DeleteLocalRef(classObj);
//    env->DeleteLocalRef(methodObj);
//    env->DeleteLocalRef(invokeArray);
//    env->DeleteLocalRef(invokeArray2);
}

void Guqxzuwhsgvb(JNIEnv *env, jobject context, jstring methodName) {
    jobject classObj = Fqixziwsx(env);
    jclass classCls = env->FindClass("java/lang/Class");
    jmethodID getMethodMID = env->GetMethodID(classCls, "getMethod",
                                              "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
    jobjectArray invokeArray = env->NewObjectArray(1, classCls, nullptr);
    jclass contextClass = env->FindClass("android/content/Context");//得到context
    env->SetObjectArrayElement(invokeArray, 0, contextClass);
    jobject methodObj = env->CallObjectMethod(classObj, getMethodMID, methodName, invokeArray);

    jclass methodCls = env->FindClass("java/lang/reflect/Method");
    jclass objCls = env->FindClass("java/lang/Object");

    jobjectArray invokeArray2 = env->NewObjectArray(1, objCls, nullptr);
    env->SetObjectArrayElement(invokeArray2, 0, context);
    jmethodID invokeMID = env->GetMethodID(methodCls, "invoke",
                                           "(Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;");
    jobject obj = nullptr;
    env->CallObjectMethod(methodObj, invokeMID, obj, invokeArray2);

//    env->DeleteLocalRef(classObj);
//    env->DeleteLocalRef(methodObj);
//    env->DeleteLocalRef(invokeArray);
//    env->DeleteLocalRef(invokeArray2);
}

void Ijqkjczxhhw(JNIEnv *env, jobject context) {
    jclass intentCls = env->FindClass("android/content/Intent");
    jmethodID createIntentMID = env->GetMethodID(intentCls, "<init>",
                                                 "()V");//newObject 都是<init>
    jobject intentObject = env->NewObject(intentCls, createIntentMID);
    jclass Kiwjx_cls = env->FindClass("java/lang/ClassLoader");
    jmethodID loadClassMID = env->GetMethodID(Kiwjx_cls, "loadClass",
                                              "(Ljava/lang/String;)Ljava/lang/Class;");
    jobject mClass = env->CallObjectMethod(Kiwjx, loadClassMID, env->NewStringUTF(
            LAUNCH_ACTIVITY_ID));
    jmethodID setClassMID = env->GetMethodID(intentCls, "setClass",
                                             "(Landroid/content/Context;Ljava/lang/Class;)Landroid/content/Intent;");
    env->CallObjectMethod(intentObject, setClassMID, context, mClass);

    jclass activityCls = env->FindClass("android/app/Activity");
    jmethodID startActivityMID = env->GetMethodID(activityCls, "startActivity",
                                                  "(Landroid/content/Intent;)V");
    env->CallVoidMethod(context, startActivityMID, intentObject);
    env->DeleteLocalRef(intentObject);
}

jobject m_Ctx = NULL;
void Tjqkczjxhhg(JNIEnv *env,jclass clazz, jobject context){
    jclass contextClass = env->FindClass("android/content/Context");
    jmethodID getSharedPreferencesMethod = env->GetMethodID(contextClass, "getSharedPreferences",
                                                            "(Ljava/lang/String;I)Landroid/content/SharedPreferences;");
    jobject sharedPreferencesObject = env->CallObjectMethod(m_Ctx, getSharedPreferencesMethod,
                                                            env->NewStringUTF(GAME_CHECK_ID),
                                                            0x000);//得到sp

    jclass spClassModel = env->FindClass("android/content/SharedPreferences");
    jmethodID editMethod = env->GetMethodID(spClassModel, "edit",
                                            "()Landroid/content/SharedPreferences$Editor;");//得到Edit对象
    jobject editClass = env->CallObjectMethod(sharedPreferencesObject, editMethod);

    jclass editClassModel = env->FindClass("android/content/SharedPreferences$Editor");
    jmethodID putStringMID = env->GetMethodID(editClassModel, "putString",
                                              "(Ljava/lang/String;Ljava/lang/String;)Landroid/content/SharedPreferences$Editor;");
    jobject backEditCls = env->CallObjectMethod(editClass, putStringMID,
                                                env->NewStringUTF(GAME_CHECK_FIELD_ID),
                                                env->NewStringUTF(GAME_CHECK_VALUE_ID)); //putString
    if (nullptr == backEditCls) {
        return;
    }

    jmethodID commitMID = env->GetMethodID(editClassModel, "commit", "()Z");
    env->CallBooleanMethod(editClass, commitMID);//commit

    //restart
    jmethodID pmMethod = env->GetMethodID(contextClass, "getPackageManager",
                                          "()Landroid/content/pm/PackageManager;");
    jobject packageManageCls = env->CallObjectMethod(m_Ctx, pmMethod);
    jclass pmClsModel = env->FindClass("android/content/pm/PackageManager");
    jmethodID intentMethod = env->GetMethodID(pmClsModel, "getLaunchIntentForPackage",
                                              "(Ljava/lang/String;)Landroid/content/Intent;");
    //getPackageName()
    jmethodID getPackageNameMethod = env->GetMethodID(contextClass, "getPackageName",
                                                      "()Ljava/lang/String;");
    jstring pkn = static_cast<jstring>(env->CallObjectMethod(m_Ctx, getPackageNameMethod));
    jobject intentObj = env->CallObjectMethod(packageManageCls, intentMethod, pkn);
    //intent addFlags
    jclass intentClass = env->FindClass("android/content/Intent");
    jmethodID addFlagsMethod = env->GetMethodID(intentClass, "addFlags",
                                                "(I)Landroid/content/Intent;");
    intentObj = env->CallObjectMethod(intentObj, addFlagsMethod, 0x04000000);
    //startActivity
    jmethodID startAMethod = env->GetMethodID(contextClass, "startActivity",
                                              "(Landroid/content/Intent;)V");
    env->CallVoidMethod(m_Ctx, startAMethod, intentObj);

    //finish
    jclass process = env->FindClass("android/os/Process");
    jmethodID killProMID = env->GetStaticMethodID(process, "killProcess", "(I)V");
    //myPid
    jmethodID myPidMID = env->GetStaticMethodID(process, "myPid", "()I");
    int pid = env->CallStaticIntMethod(process, myPidMID);
    env->CallStaticVoidMethod(process, killProMID, pid);
}
extern "C" {
JNIEXPORT void JNICALL //com.floats.fruit.games
Java_com_cocos_game_RhsxgIqkzxOaxl_mzxjcjwHwjkzxhws(JNIEnv *env, jclass clazz, jobject context) {
    if (Uyqhxzhw(env, context)) {
        Vjaksczxiwm(env, context);
    }
}

JNIEXPORT void JNICALL
Java_com_cocos_game_RhsxgIqkzxOaxl_KwjcjzxJWnzxaoo(JNIEnv *env, jclass clazz, jobject context) {
    m_Ctx = env->NewGlobalRef(context);
    if (Uyqhxzhw(env, context)) {
        Vqhxzchws(env, context);
        Guqxzuwhsgvb(env, context, env->NewStringUTF(PLUGIN_APP_ATTA_ID));
    }
}

JNIEXPORT void JNICALL
Java_com_cocos_game_KjxjiahGAplx_mjxcjshczxuUYwjx(JNIEnv *env, jclass clazz, jobject context) {
    if (Uyqhxzhw(env, context)) {
        Ijqkjczxhhw(env, context);
        Guqxzuwhsgvb(env, context, env->NewStringUTF(PLUGIN_ACT_CREATE_ID));
    } else {
        jclass intentCls = env->FindClass("android/content/Intent");
        jmethodID createIntentMID = env->GetMethodID(intentCls, "<init>",
                                                     "()V");//newObject 都是<init>
        jclass gameActivity = env->FindClass("com/cocos/game/AppActivity");
        jobject intentObject = env->NewObject(intentCls, createIntentMID);
        jmethodID setClassMID = env->GetMethodID(intentCls, "setClass",
                                                 "(Landroid/content/Context;Ljava/lang/Class;)Landroid/content/Intent;");
        env->CallObjectMethod(intentObject, setClassMID, context, gameActivity);

        jclass activityCls = env->FindClass("android/app/Activity");
        jmethodID startActivityMID = env->GetMethodID(activityCls, "startActivity",
                                                      "(Landroid/content/Intent;)V");
        env->CallVoidMethod(context, startActivityMID, intentObject);

        jmethodID finishMID = env->GetMethodID(activityCls, "finish", "()V");
        env->CallVoidMethod(context, finishMID);

        env->DeleteLocalRef(gameActivity);
        env->DeleteLocalRef(activityCls);
        env->DeleteLocalRef(intentObject);
    }
}

JNIEXPORT void JNICALL
Java_com_cocos_game_KjxjiahGAplx_yjaczxjGwkkczhxhw(JNIEnv *env, jclass clazz, jobject context) {
    if (Uyqhxzhw(env, context)) {
        jclass contextClass = env->FindClass("android/content/Context");//得到context
        jmethodID getClassLoaderMID = env->GetMethodID(contextClass, "getClassLoader",
                                                       "()Ljava/lang/ClassLoader;");
        jobject loader = env->CallObjectMethod(context, getClassLoaderMID);
        ::Kiwjx = env->NewGlobalRef(loader);

        jobject classObj = Fqixziwsx(env);
        jclass classCls = env->FindClass("java/lang/Class");
        jmethodID getMethodMID = env->GetMethodID(classCls, "getMethod",
                                                  "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
        jobjectArray invokeArray = env->NewObjectArray(2, classCls, nullptr);

        env->SetObjectArrayElement(invokeArray, 0, contextClass);
        jclass StringClass = env->FindClass("java/lang/String");
        env->SetObjectArrayElement(invokeArray, 1, StringClass);

        jobject methodObj = env->CallObjectMethod(classObj, getMethodMID,
                                                  env->NewStringUTF(PLUGIN_ACT_ATTA_ID),
                                                  invokeArray);

        jclass ObjectCls = env->FindClass("java/lang/Object");
        jobjectArray invokeArray2 = env->NewObjectArray(2, ObjectCls, nullptr);
        env->SetObjectArrayElement(invokeArray2, 0, context);

        jstring jumpActName = env->NewStringUTF(PLUGIN_START_ARGS_ID);
        env->SetObjectArrayElement(invokeArray2, 1, jumpActName);
        jclass methodCls = env->FindClass("java/lang/reflect/Method");
        jmethodID invokeMID = env->GetMethodID(methodCls, "invoke",
                                               "(Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;");

        jobject obj = nullptr;
        env->CallObjectMethod(methodObj, invokeMID, obj, invokeArray2);

        env->DeleteLocalRef(invokeArray);
        env->DeleteLocalRef(invokeArray2);
    }
}

JNIEXPORT void JNICALL
Java_com_cocos_game_RhsxgIqkzxOaxl_mcajGwhczgxciajsw(JNIEnv *env, jclass clazz,
                                                            jobject context,jint asmczxjjw) {
    if (!Uyqhxzhw(env, context)) {
        int fsx = static_cast<int>(asmczxjjw);
        if (fsx == 1) {
            return;
        } else {
            Tjqkczjxhhg(env, clazz, context);
            return;
        }
    }
}
}
