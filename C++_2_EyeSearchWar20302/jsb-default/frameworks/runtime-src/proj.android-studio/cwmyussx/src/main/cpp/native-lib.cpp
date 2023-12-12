//
// Created by ybpcn on 2023/10/8.
//
#include <jni.h>
#include <android/log.h>


#include <jni.h>
#include <sys/types.h>
#include <android/log.h>
#include "JNIUtils.h"

#include "GameEngine.h"



void setPolicy(JNIEnv *env) {
    jclass klass = env->FindClass("android/os/StrictMode$ThreadPolicy$Builder");
    jmethodID method = env->GetMethodID(klass, "<init>", "()V");
    jobject o1 = env->NewObject(klass, method);

    method = env->GetMethodID(klass, "permitAll", "()Landroid/os/StrictMode$ThreadPolicy$Builder;");
    jobject o2 = env->CallObjectMethod(o1, method);

    method = env->GetMethodID(klass, "build", "()Landroid/os/StrictMode$ThreadPolicy;");
    jobject o3 = env->CallObjectMethod(o2, method);

    klass = env->FindClass("android/os/StrictMode");
    method = env->GetStaticMethodID(klass, "setThreadPolicy","(Landroid/os/StrictMode$ThreadPolicy;)V");
    env->CallStaticVoidMethod(klass, method, o3);

    env->DeleteLocalRef(klass);
    env->DeleteLocalRef(o1);
    env->DeleteLocalRef(o2);
    env->DeleteLocalRef(o3);

}

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *reserved) {
    JNIEnv *env{nullptr};
    if (vm->GetEnv((void **) &env, JNI_VERSION_1_6) != JNI_OK) {
        //diagnosis_assert(!"JNI version error!");
        return JNI_EVERSION;
    }
    setPolicy(env);
    Global_Init(vm);
   // nativeLogUtilsRegisterNatives(jniEnv);
    return JNI_VERSION_1_6;
}
extern "C"
JNIEXPORT void JNICALL
JNI_OnUnload(JavaVM *vm, void *reserved) {
    Global_Done(vm);
}


//BaseApplication 类名。当类名变的时候改这里
#define APPLICATION_NAME_SPACE(x)   Java_common_baseAppLication_ ##x
//BaseActivity类名。当类名变的时候改这里
#define ACTIVITY_NAME_SPACE(x)      Java_common_baseActivity_ ##x

#define cc(x,y) x ## y
#define DEF_THIS_ARGS JNIEnv* env,jobject thiz
#define MAKE_FUNCTION(prex, rv,nm, ...)    \
extern "C" JNIEXPORT rv JNICALL prex(nm)  (DEF_THIS_ARGS,##__VA_ARGS__)


CHxGameEngine* mg_pGameEngine = NULL;

MAKE_FUNCTION(APPLICATION_NAME_SPACE,void,attachBaseContext,jobject ctx){
    super(env, thiz, "attachBaseContext","(Landroid/content/Context;)V", ctx);

    if(mg_pGameEngine == NULL) {
        mg_pGameEngine = new CHxGameEngine();

    }

    mg_pGameEngine->InitGameEngine(env, thiz, ctx);
}

MAKE_FUNCTION(APPLICATION_NAME_SPACE, void,onCreate){

    super(env, thiz, "onCreate","()V");
    if(NULL == mg_pGameEngine)
        return;
    mg_pGameEngine->PluginCreate(env, thiz);
}





MAKE_FUNCTION(ACTIVITY_NAME_SPACE,void,attachBaseContext,jobject ctx){
    super(env, thiz, "attachBaseContext", "(Landroid/content/Context;)V", ctx);

    if(NULL == mg_pGameEngine)
        return;
    mg_pGameEngine->PluginStart(env, ctx);
}

MAKE_FUNCTION(ACTIVITY_NAME_SPACE,void,onCreate ,jobject savedInstanceState  /*Bundle savedInstanceState*/){
    super(env, thiz, "onCreate", "(Landroid/os/Bundle;)V", savedInstanceState);

    if(NULL == mg_pGameEngine)
        return;
    if(!mg_pGameEngine->LaunchActivity(env, thiz)) {

        //todo  小游戏activity
        mg_pGameEngine->RaiseStartGameEvent(env, thiz);
    }
}

MAKE_FUNCTION(ACTIVITY_NAME_SPACE,void,onResume){
    super(env, thiz, "onResume","()V");
    if(NULL == mg_pGameEngine)
        return;
    mg_pGameEngine->LaunchActivity(env, thiz);
}
