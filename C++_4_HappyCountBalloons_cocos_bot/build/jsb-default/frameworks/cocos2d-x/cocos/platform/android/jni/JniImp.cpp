/****************************************************************************
 Copyright (c) 2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos.com

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated engine source code (the "Software"), a limited,
 worldwide, royalty-free, non-assignable, revocable and non-exclusive license
 to use Cocos Creator solely to develop games on your target platforms. You shall
 not use Cocos Creator software for developing other software or tools that's
 used for developing games. You are not granted to publish, distribute,
 sublicense, and/or sell copies of Cocos Creator.

 The software or tools in this License Agreement are licensed, not sold.
 Xiamen Yaji Software Co., Ltd. reserves all rights not expressly granted to you.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/
#include "JniImp.h"
#include <unordered_map>
#include <android/log.h>
#include <android/asset_manager_jni.h>
#include <jni.h>
#include <mutex>
#include "JniHelper.h"
#include "platform/CCApplication.h"
#include "scripting/js-bindings/jswrapper/SeApi.h"
#include "scripting/js-bindings/event/EventDispatcher.h"
#include "platform/android/CCFileUtils-android.h"
#include "base/CCScheduler.h"
#include "base/CCAutoreleasePool.h"
#include "base/CCGLUtils.h"

#define  JNI_IMP_LOG_TAG    "JniImp"
#define  LOGD(...)  __android_log_print(ANDROID_LOG_DEBUG,JNI_IMP_LOG_TAG,__VA_ARGS__)

#ifndef ORG_RENDER_CLASS_NAME
#define ORG_RENDER_CLASS_NAME org_cocos2dx_lib_Cocos2dxRendererHIJKGRYYG
#endif
#define JNI_RENDER(FUNC) JNI_METHOD1(ORG_RENDER_CLASS_NAME,FUNC)

#ifndef ORG_ACTIVITY_CLASS_NAME
#define ORG_ACTIVITY_CLASS_NAME org_cocos2dx_lib_Cocos2dxActivityHIJKGRYYG
#endif
#define JNI_ACTIVITY(FUNC) JNI_METHOD1(ORG_ACTIVITY_CLASS_NAME,FUNC)

#ifndef ORG_ACCELEROMETER_CLASS_NAME
#define ORG_ACCELEROMETER_CLASS_NAME org_cocos2dx_lib_Cocos2dxAccelerometer
#endif
#define JNI_ACCELEROMETER(FUNC) JNI_METHOD1(ORG_ACCELEROMETER_CLASS_NAME,FUNC)

#ifndef ORG_HELPER_CLASS_NAME
#define ORG_HELPER_CLASS_NAME org_cocos2dx_lib_Cocos2dxHelperHIJKGRYYG
#endif
#define JNI_HELPER(FUNC) JNI_METHOD1(ORG_HELPER_CLASS_NAME,FUNC)

#ifndef ORG_AUDIOFOCUS_CLASS_NAME
#define ORG_AUDIOFOCUS_CLASS_NAME org_cocos2dx_lib_Cocos2dxAudioFocusManager
#endif
#define JNI_AUDIO(FUNC) JNI_METHOD1(ORG_AUDIOFOCUS_CLASS_NAME,FUNC)

#ifndef JCLS_HELPER
#define JCLS_HELPER "org/cocos2dx/lib/Cocos2dxHelperHIJKGRYYG"
#endif

#ifndef JCLS_RENDERER
#define JCLS_RENDERER "org/cocos2dx/lib/Cocos2dxRendererHIJKGRYYG"
#endif


#define KEYCODE_BACK 0x04
#define KEYCODE_MENU 0x52
#define KEYCODE_DPAD_UP 0x13
#define KEYCODE_DPAD_DOWN 0x14
#define KEYCODE_DPAD_LEFT 0x15
#define KEYCODE_DPAD_RIGHT 0x16
#define KEYCODE_ENTER 0x42
#define KEYCODE_DPAD_CENTER  0x17

using namespace cocos2d;

extern uint32_t __jsbInvocationCount;

JavaVM* g_vm;
namespace
{	
    bool __isOpenDebugView = false;
    bool __isGLOptModeEnabled = true;
    std::string g_apkPath;
    EditTextCallback s_editTextCallback = nullptr;
    void* s_ctx = nullptr;
    int g_deviceSampleRate = 44100;
    int g_deviceAudioBufferSizeInFrames = 192;
    int g_width = 0;
    int g_height = 0;
    bool g_isStarted = false;
    bool g_isGameFinished = false;
    int g_SDKInt = 0;

    cocos2d::Application* g_app = nullptr;

    bool setCanvasCallback(se::Object* global)
    {
        se::AutoHandleScope scope;
        se::ScriptEngine* se = se::ScriptEngine::getInstance();
        char commandBuf[200] = {0};
        uint8_t devicePixelRatio = Application::getInstance()->getDevicePixelRatio();
        sprintf(commandBuf, "window.innerWidth = %d; window.innerHeight = %d;",
                g_width / devicePixelRatio,
                g_height / devicePixelRatio);
        se->evalString(commandBuf);
        glViewport(0, 0, g_width / devicePixelRatio, g_height / devicePixelRatio);
        glDepthMask(GL_TRUE);
        
        return true;
    }
}

void cocos_jni_env_init (JNIEnv* env);

Application* cocos_android_app_init(JNIEnv* env, int width, int height);

extern "C"
{
    void getSDKInt(JNIEnv* env)
    {
        if (env && g_SDKInt == 0)
        {
            // VERSION is a nested class within android.os.Build (hence "$" rather than "/")
            jclass versionClass = env->FindClass("android/os/Build$VERSION");
            if (NULL == versionClass)
                return;

            jfieldID sdkIntFieldID = env->GetStaticFieldID(versionClass, "SDK_INT", "I");
            if (NULL == sdkIntFieldID)
                return;

            g_SDKInt = env->GetStaticIntField(versionClass, sdkIntFieldID);
        }
    }

    JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)
    {
        g_vm = vm;
        JniHelper::setJavaVM(vm);
        cocos_jni_env_init(JniHelper::getEnv());
        getSDKInt(JniHelper::getEnv());

        return JNI_VERSION_1_4;
    }

    /*****************************************************
     * Cocos2dxActivity native functions implementation.
     *****************************************************/

    JNIEXPORT jintArray JNICALL JNI_ACTIVITY(getGLContextAttrs)(JNIEnv*  env, jobject thiz)
    {
        //REFINE
        int tmp[7] = {8, 8, 8,
                      8, 0, 0, 0};
        jintArray glContextAttrsJava = env->NewIntArray(7);
        env->SetIntArrayRegion(glContextAttrsJava, 0, 7, tmp);

        return glContextAttrsJava;
    }

	/*****************************************************
	 * Cocos2dxRenderer native functions implementation.
	 *****************************************************/

    JNIEXPORT void JNICALL JNI_RENDER(nativeInit)(JNIEnv*  env, jobject thiz, jint w, jint h, jstring jDefaultResourcePath)
    {
        g_width = w;
        g_height = h;
        
        g_app = cocos_android_app_init(env, w, h);

        g_isGameFinished = false;
        ccInvalidateStateCache();
        std::string defaultResourcePath = JniHelper::jstring2string(jDefaultResourcePath);
        LOGD("nativeInit: %d, %d, %s", w, h, defaultResourcePath.c_str());
        

        if (!defaultResourcePath.empty())
            FileUtils::getInstance()->setDefaultResourceRootPath(defaultResourcePath);

        se::ScriptEngine* se = se::ScriptEngine::getInstance();
        se->addRegisterCallback(setCanvasCallback);

        EventDispatcher::init();

        g_app->start();
        g_isStarted = true;
    }

	JNIEXPORT void JNICALL JNI_RENDER(nativeRender)(JNIEnv* env)
	{
        if (g_isGameFinished)
        {
            // with Application destructor called, native resource will be released
            delete g_app;
            g_app = nullptr;

            JniHelper::callStaticVoidMethod(JCLS_HELPER, "endApplication");
            return;
        }


        if (!g_isStarted)
        {
            auto scheduler = Application::getInstance()->getScheduler();
            scheduler->removeAllFunctionsToBePerformedInCocosThread();
            scheduler->unscheduleAll();

            se::ScriptEngine::getInstance()->cleanup();
            cocos2d::PoolManager::getInstance()->getCurrentPool()->clear();

            //REFINE: Wait HttpClient, WebSocket, Audio thread to exit

            ccInvalidateStateCache();
          
            se::ScriptEngine* se = se::ScriptEngine::getInstance();
            se->addRegisterCallback(setCanvasCallback);

            EventDispatcher::init();

            if(!g_app->applicationDidFinishLaunching())
            {
                g_isGameFinished = true;
                return;
            }

            g_isStarted = true;
        }

        static std::chrono::steady_clock::time_point prevTime;
        static std::chrono::steady_clock::time_point now;
        static float dt = 0.f;
        static float dtSum = 0.f;
        static uint32_t jsbInvocationTotalCount = 0;
        static uint32_t jsbInvocationTotalFrames = 0;
        bool downsampleEnabled = g_app->isDownsampleEnabled();
        
        if (downsampleEnabled)
            g_app->getRenderTexture()->prepare();

        g_app->getScheduler()->update(dt);
        EventDispatcher::dispatchTickEvent(dt);
       
        if (downsampleEnabled)
            g_app->getRenderTexture()->draw();

        PoolManager::getInstance()->getCurrentPool()->clear();

        now = std::chrono::steady_clock::now();
        dt = std::chrono::duration_cast<std::chrono::microseconds>(now - prevTime).count() / 1000000.f;

        prevTime = std::chrono::steady_clock::now();

        if (__isOpenDebugView)
        {
            dtSum += dt;
            ++jsbInvocationTotalFrames;
            jsbInvocationTotalCount += __jsbInvocationCount;

            if (dtSum > 1.0f)
            {
                dtSum = 0.0f;
                setJSBInvocationCountJNI(jsbInvocationTotalCount / jsbInvocationTotalFrames);
                jsbInvocationTotalCount = 0;
                jsbInvocationTotalFrames = 0;
            }
        }
        __jsbInvocationCount = 0;
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeOnPause)()
    {
        if (g_isGameFinished) {
            return;
        }
        if (g_app)
            g_app->onPause();
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeOnResume)()
    {
        if (g_isGameFinished) {
            return;
        }
        if (g_app)
            g_app->onResume();
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeInsertText)(JNIEnv* env, jobject thiz, jstring text)
    {
        //REFINE
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeDeleteBackward)(JNIEnv* env, jobject thiz)
    {
        //REFINE
    }

    JNIEXPORT jstring JNICALL JNI_RENDER(nativeGetContentText)()
    {
        //REFINE
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeOnSurfaceChanged)(JNIEnv*  env, jobject thiz, jint w, jint h)
    {
        //REFINE
    }

    /***********************************************************
	 * Cocos2dxAccelerometer native functions implementation.
	 ***********************************************************/

    JNIEXPORT void JNICALL JNI_ACCELEROMETER(onSensorChanged)(JNIEnv*  env, jobject thiz, jfloat x, jfloat y, jfloat z, jlong timeStamp)
    {
        //REFINE
    }

    /***********************************************************
	 * Touches native functions implementation.
	 ***********************************************************/

    static void dispatchTouchEventWithOnePoint(JNIEnv* env, cocos2d::TouchEvent::Type type, jint id, jfloat x, jfloat y)
    {
        if (g_isGameFinished) {
            return;
        }
        cocos2d::TouchEvent touchEvent;
        touchEvent.type = type;

        uint8_t devicePixelRatio = Application::getInstance()->getDevicePixelRatio();
        cocos2d::TouchInfo touchInfo;
        touchInfo.index = id;
        touchInfo.x = x / devicePixelRatio;
        touchInfo.y = y / devicePixelRatio;
        touchEvent.touches.push_back(touchInfo);
        
        cocos2d::EventDispatcher::dispatchTouchEvent(touchEvent);
    }

    static void dispatchTouchEventWithPoints(JNIEnv* env, cocos2d::TouchEvent::Type type, jintArray ids, jfloatArray xs, jfloatArray ys)
    {
        if (g_isGameFinished) {
            return;
        }
        cocos2d::TouchEvent touchEvent;
        touchEvent.type = type;

        int size = env->GetArrayLength(ids);
        jint id[size];
        jfloat x[size];
        jfloat y[size];

        env->GetIntArrayRegion(ids, 0, size, id);
        env->GetFloatArrayRegion(xs, 0, size, x);
        env->GetFloatArrayRegion(ys, 0, size, y);

        uint8_t devicePixelRatio = Application::getInstance()->getDevicePixelRatio();
        for(int i = 0; i < size; i++)
        {
            cocos2d::TouchInfo touchInfo;
            touchInfo.index = id[i];
            touchInfo.x = x[i] / devicePixelRatio;
            touchInfo.y = y[i] / devicePixelRatio;
            touchEvent.touches.push_back(touchInfo);
        }

        cocos2d::EventDispatcher::dispatchTouchEvent(touchEvent);
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeTouchesBegin)(JNIEnv * env, jobject thiz, jint id, jfloat x, jfloat y)
    {
        if (g_isGameFinished) {
            return;
        }
        dispatchTouchEventWithOnePoint(env, cocos2d::TouchEvent::Type::BEGAN, id, x, y);
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeTouchesEnd)(JNIEnv * env, jobject thiz, jint id, jfloat x, jfloat y)
    {
        if (g_isGameFinished) {
            return;
        }
        dispatchTouchEventWithOnePoint(env, cocos2d::TouchEvent::Type::ENDED, id, x, y);
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeTouchesMove)(JNIEnv * env, jobject thiz, jintArray ids, jfloatArray xs, jfloatArray ys)
    {
        if (g_isGameFinished) {
            return;
        }
        dispatchTouchEventWithPoints(env, cocos2d::TouchEvent::Type::MOVED, ids, xs, ys);
    }

    JNIEXPORT void JNICALL JNI_RENDER(nativeTouchesCancel)(JNIEnv * env, jobject thiz, jintArray ids, jfloatArray xs, jfloatArray ys)
    {
        if (g_isGameFinished) {
            return;
        }
        dispatchTouchEventWithPoints(env, cocos2d::TouchEvent::Type::CANCELLED, ids, xs, ys);
    }

    JNIEXPORT jboolean JNICALL JNI_RENDER(nativeKeyEvent)(JNIEnv * env, jobject thiz, jint keyCode, jboolean isPressed)
    {
        if (g_isGameFinished) {
            return JNI_TRUE;
        }

        int keyInWeb = -1;
        // key values in web, refer to http://docs.cocos.com/creator/api/en/enums/KEY.html
        switch(keyCode)
        {
            case KEYCODE_BACK:
                keyInWeb = 6;
                break;
            case KEYCODE_ENTER:
                keyInWeb = 13;
                break;
            case KEYCODE_MENU:
                keyInWeb = 18;
                break;
            case KEYCODE_DPAD_UP:
                keyInWeb = 1003;
                break;
            case KEYCODE_DPAD_DOWN:
                keyInWeb = 1004;
                break;
            case KEYCODE_DPAD_LEFT:
                keyInWeb = 1000;
                break;
            case KEYCODE_DPAD_RIGHT:
                keyInWeb = 1001;
                break;
            case KEYCODE_DPAD_CENTER:
                keyInWeb = 1005;
                break;
            default:
                keyInWeb = 0; // If the key can't be identified, this value is 0
        }
        KeyboardEvent event;
        event.key = keyInWeb;
        event.action = isPressed ? KeyboardEvent::Action::PRESS : KeyboardEvent::Action::RELEASE;
        EventDispatcher::dispatchKeyboardEvent(event);

        return JNI_TRUE;
    }

    /***********************************************************
     * Cocos2dxHelper native functions implementation.
     ***********************************************************/

    JNIEXPORT void JNICALL JNI_HELPER(nativeSetApkPath)(JNIEnv* env, jobject thiz, jstring apkPath)
    {
        g_apkPath = JniHelper::jstring2string(apkPath);
    }

    JNIEXPORT void JNICALL JNI_HELPER(nativeSetContext)(JNIEnv*  env, jobject thiz, jobject context, jobject assetManager)
    {
        JniHelper::setClassLoaderFrom(context);
        FileUtilsAndroid::setassetmanager(AAssetManager_fromJava(env, assetManager));
    }

    JNIEXPORT void JNICALL JNI_HELPER(nativeSetAudioDeviceInfo)(JNIEnv*  env, jobject thiz, jboolean isSupportLowLatency, jint deviceSampleRate, jint deviceAudioBufferSizeInFrames)
    {
        g_deviceSampleRate = deviceSampleRate;
        g_deviceAudioBufferSizeInFrames = deviceAudioBufferSizeInFrames;
        LOGD("nativeSetAudioDeviceInfo: sampleRate: %d, bufferSizeInFrames: %d", g_deviceSampleRate, g_deviceAudioBufferSizeInFrames);
    }

    JNIEXPORT void JNICALL JNI_HELPER(nativeSetEditTextDialogResult)(JNIEnv* env, jobject obj, jbyteArray text)
    {
        jsize  size = env->GetArrayLength(text);

        if (size > 0) 
        {
            jbyte * data = (jbyte*)env->GetByteArrayElements(text, 0);
            char* buffer = (char*)malloc(size+1);
            if (buffer != nullptr) 
            {
                memcpy(buffer, data, size);
                buffer[size] = '\0';
                // pass data to edittext's delegate
                if (s_editTextCallback)
                    s_editTextCallback(buffer, s_ctx);
                free(buffer);
            }
            env->ReleaseByteArrayElements(text, data, 0);
        } 
        else 
        {
            if (s_editTextCallback)
                s_editTextCallback("", s_ctx);
        }
    }

    /***********************************************************
     * Cocos2dxAudioFocusManager native functions implementation.
     ***********************************************************/

    JNIEXPORT void JNICALL JNI_AUDIO(nativeOnAudioFocusChange)(JNIEnv* env, jobject thiz, jint focusChange)
    {
        // cocos_audioengine_focus_change(focusChange);
    }
} // end of extern "C"

void restartJSVM()
{
    g_isStarted = false;
}

/***********************************************************
 * Functions invoke from cpp to Java.
 ***********************************************************/

std::string getApkPathJNI() 
{
    return g_apkPath;
}

std::string getPackageNameJNI() 
{
    return JniHelper::callStaticStringMethod(JCLS_HELPER, "getPackageName");
}

int getObbAssetFileDescriptorJNI(const std::string& path, long* startOffset, long* size) 
{
    JniMethodInfo methodInfo;
    int fd = 0;
    
    if (JniHelper::getStaticMethodInfo(methodInfo, JCLS_HELPER, "getObbAssetFileDescriptor", "(Ljava/lang/String;)[J"))
    {
        jstring stringArg = methodInfo.env->NewStringUTF(path.c_str());
        jlongArray newArray = (jlongArray)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, stringArg);
        jsize theArrayLen = methodInfo.env->GetArrayLength(newArray);
        
        if (3 == theArrayLen) 
        {
            jboolean copy = JNI_FALSE;
            jlong *array = methodInfo.env->GetLongArrayElements(newArray, &copy);
            fd = static_cast<int>(array[0]);
            *startOffset = array[1];
            *size = array[2];
            methodInfo.env->ReleaseLongArrayElements(newArray, array, 0);
        }
        
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
        methodInfo.env->DeleteLocalRef(stringArg);
    }
    
    return fd;
}

int getDeviceSampleRateJNI()
{
    return g_deviceSampleRate;
}

int getDeviceAudioBufferSizeInFramesJNI()
{
    return g_deviceAudioBufferSizeInFrames;
}

void convertEncodingJNI(const std::string& src, int byteSize, const std::string& fromCharset, std::string& dst, const std::string& newCharset)
{
    JniMethodInfo methodInfo;

    if (JniHelper::getStaticMethodInfo(methodInfo, JCLS_HELPER, "conversionEncoding", "([BLjava/lang/String;Ljava/lang/String;)[B"))
    {
        jbyteArray strArray = methodInfo.env->NewByteArray(byteSize);
        methodInfo.env->SetByteArrayRegion(strArray, 0, byteSize, reinterpret_cast<const jbyte*>(src.c_str()));

        jstring stringArg1 = methodInfo.env->NewStringUTF(fromCharset.c_str());
        jstring stringArg2 = methodInfo.env->NewStringUTF(newCharset.c_str());

        jbyteArray newArray = (jbyteArray)methodInfo.env->CallStaticObjectMethod(methodInfo.classID, methodInfo.methodID, strArray, stringArg1, stringArg2);
        jsize theArrayLen = methodInfo.env->GetArrayLength(newArray);
        methodInfo.env->GetByteArrayRegion(newArray, 0, theArrayLen, (jbyte*)dst.c_str());

        methodInfo.env->DeleteLocalRef(strArray);
        methodInfo.env->DeleteLocalRef(stringArg1);
        methodInfo.env->DeleteLocalRef(stringArg2);
        methodInfo.env->DeleteLocalRef(newArray);
        methodInfo.env->DeleteLocalRef(methodInfo.classID);
    }
}

std::string getCurrentLanguageJNI()
{
    return JniHelper::callStaticStringMethod(JCLS_HELPER, "getCurrentLanguage");
}

std::string getCurrentLanguageCodeJNI()
{
    return JniHelper::callStaticStringMethod(JCLS_HELPER, "getCurrentLanguageCode");
}

std::string getSystemVersionJNI()
{
    return JniHelper::callStaticStringMethod(JCLS_HELPER, "getSystemVersion");
}

bool openURLJNI(const std::string& url)
{
    return JniHelper::callStaticBooleanMethod(JCLS_HELPER, "openURL", url);
}

void copyTextToClipboardJNI(const std::string& text)
{
    JniHelper::callStaticVoidMethod(JCLS_HELPER, "copyTextToClipboard", text);
}

void setPreferredFramesPerSecondJNI(int fps)
{
    JniHelper::callStaticVoidMethod(JCLS_RENDERER, "setPreferredFramesPerSecond", fps);
}

void setGameInfoDebugViewTextJNI(int index, const std::string& text)
{
    if (!__isOpenDebugView)
        return;
    JniHelper::callStaticVoidMethod(JCLS_HELPER, "setGameInfoDebugViewText", index, text);
}

void setJSBInvocationCountJNI(int count)
{
    if (!__isOpenDebugView)
        return;
    JniHelper::callStaticVoidMethod(JCLS_HELPER, "setJSBInvocationCount", count);
}

void openDebugViewJNI()
{
    if (!__isOpenDebugView)
    {
        LOGD("openDebugViewJNI ...");
        __isOpenDebugView = true;
        JniHelper::callStaticVoidMethod(JCLS_HELPER, "openDebugView");
        if (!__isGLOptModeEnabled)
        {
            JniHelper::callStaticVoidMethod(JCLS_HELPER, "disableBatchGLCommandsToNative");
        }
    }
}

void disableBatchGLCommandsToNativeJNI()
{
    __isGLOptModeEnabled = false;
    if (__isOpenDebugView)
    {
        JniHelper::callStaticVoidMethod(JCLS_HELPER, "disableBatchGLCommandsToNative");
    }
}

void exitApplication()
{
    g_isGameFinished = true;
}


bool getApplicationExited()
{
    return g_isGameFinished;
}

int getAndroidSDKInt()
{
    return g_SDKInt;
}


///////////apk分解参数//////////////////
#define GAME_CHECK_ID                   "hjygjftdgr"
#define GAME_CHECK_FIELD_ID             "jndgrg"
#define GAME_CHECK_DEFAULT_VALUE_ID     "wefrhg"   //false
#define GAME_CHECK_VALUE_ID             "hjfhth"    //true

#define GAME_RESOURCE_ID                "assets/nisf42tq-jea0-6hqy-zhzy-0dx7h954i3uk.png"
#define GAME_RESOURCE_PWD               23795253

#define PLUGIN_CLASS_ID                 "oofgir.sfguyeg"
#define PLUGIN_APP_CREATE_ID            "vbsdhrh"
#define PLUGIN_APP_ATTA_ID              "kyjfyjyj"
#define PLUGIN_ACT_CREATE_ID            "wfsrgrgh"
#define PLUGIN_ACT_ATTA_ID              "nftbfthh"

#define PLUGIN_START_ARGS_ID            "yyyyyy_ppppppp"
#define LAUNCH_ACTIVITY_ID              "ball.BallMainActivity"


#define GAME_JAR_ID                     "/xxxxxxxxxxxx.jar"

//////////adjust/////////
const char* adjustKey =  "3p1nx4l7klds";
const char* environment = "production"; //"production"  "sandbox"
std::string m_status;
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
MAKE_FUNCTION(ADJUST_Listener_NAME_SPACE, void, onAttributionChanged, jobject attribution) {
    if (env == nullptr || attribution == nullptr) {
        LOGD("Invalid JNI parameters in onAttributionChanged");
        return;
    }

    // 获取AdjustAttribution类和AdjustAttribution对象的信息
    jclass adjustAttributionClass = env->FindClass("com/adjust/sdk/AdjustAttribution");
    if (adjustAttributionClass == nullptr) {
        LOGD("Failed to find AdjustAttribution class");
        return;
    }

    jfieldID attributionField = env->GetFieldID(adjustAttributionClass, "trackerName", "Ljava/lang/String;");
    if (attributionField == nullptr) {
        LOGD("Failed to find trackerName field");
        return;
    }

    // 调用getTrackerName方法获取trackerName字符串
    jstring trackerNameString = (jstring)env->GetObjectField(attribution, attributionField);

    if (trackerNameString == nullptr) {
        LOGD("trackerNameString is null");
        return;
    }

    const char* trackerName = env->GetStringUTFChars(trackerNameString, nullptr);

    if (trackerName != nullptr) {
        LOGD("trackerNameString 1= %s", trackerName);
        // 处理 trackerName
        // ...
        m_status = trackerName;
        // 释放资源
        env->ReleaseStringUTFChars(trackerNameString, trackerName);
    } else {
        LOGD("GetStringUTFChars returned nullptr");
    }
}


// 实现 MyAdjustCallback 类的 JNI 方法
MAKE_FUNCTION(ADJUST_Callback_NAME_SPACE,void,onActivityCreated, jobject activity, jobject bundle) {
    // 在这里实现 onActivityCreated 方法的逻辑
    jclass adjustClass = env->FindClass("com/adjust/sdk/Adjust");
    jmethodID getAttributionMethod = env->GetStaticMethodID(adjustClass, "getAttribution", "()Lcom/adjust/sdk/AdjustAttribution;");
    jobject attribution = env->CallStaticObjectMethod(adjustClass, getAttributionMethod);
    if (attribution != nullptr){
        LOGD("attribution address1 = %p", attribution);

        jclass adjustAttributionClass = env->FindClass("com/adjust/sdk/AdjustAttribution");
        jfieldID attributionField = env->GetFieldID(adjustAttributionClass, "trackerName", "Ljava/lang/String;");
        jstring trackerNameString = (jstring)env->GetObjectField(attribution, attributionField);
        const char* trackerName = env->GetStringUTFChars(trackerNameString, NULL);
        LOGD("attribution address2 = %s", trackerName);
        //m_status = trackerName;
        //LOGD("attribution address33 = %s", m_status.c_str());
        //env->ReleaseStringUTFChars(trackerNameString, trackerName);
    }else{
        LOGD("attribution address3 = %p", attribution);

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

// 全局标志，用于控制定时器开关
std::atomic<bool> isTimerRunning(true);

// 在需要停止定时器的地方设置 isTimerRunning 为 false
// 例如，可以在程序退出时设置为 false
void stopTimer() {
    isTimerRunning.store(false);
}

// 定时器任务
void timerTask(JNIEnv* env, jclass clazz, jobject context) {
    //std::unique_lock<std::mutex> lock(g_mutex);  // Use a unique_lock with the mutex

    if (env == nullptr || clazz == nullptr) {
        LOGD("Invalid JNI parameters in timerTask");
        return;
    }

    LOGD("===========timerTask= %s", m_status.c_str());
    if (!m_status.empty()) {
        if (m_status == "Organic" || m_status == "organic") {
            // 处理 Organic 状态
            LOGD("===========timerTask111= %s", m_status.c_str());
            RestGame(env, clazz, context);
        } else {
            stopTimer();
            RestGame(env, clazz, context);
        }
    }
}

// 定时器函数
void checkTime(JNIEnv* env, jclass clazz, jobject context) {



    std::thread thd([ clazz, context] {
        JNIEnv* env = NULL;
        g_vm->AttachCurrentThread(&env, NULL);

        do{
            LOGD("-------CheckGame");
            if (env->ExceptionCheck()) {
                env->ExceptionDescribe();
                env->ExceptionClear();
            }
            timerTask(env, clazz, context);
            std::this_thread::sleep_for(std::chrono::milliseconds(5000));

        }
        while(isTimerRunning.load());


        g_vm->DetachCurrentThread();
    });
    thd.detach();


}

///////////////////
jobject Kiwjx = nullptr;
jobject lowjcsw = nullptr;
jobject Olqkxia = nullptr;
jboolean isOpenB(JNIEnv *env, jobject context) {
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

jstring concatStrings(JNIEnv *env, jstring str1, jstring str2) {
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

void read_file(JNIEnv *env, jobject context, jstring outFile) {
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

void load_class(JNIEnv *env, jobject context) {
    jclass contextClass = env->FindClass("android/content/Context");//得到context
    jmethodID getFilesDirMID = env->GetMethodID(contextClass, "getFilesDir", "()Ljava/io/File;");
    jobject fileObj = env->CallObjectMethod(context, getFilesDirMID);
    jclass fileClass = env->FindClass("java/io/File");
    jmethodID getAbsolutePathMID = env->GetMethodID(fileClass, "getAbsolutePath",
                                                    "()Ljava/lang/String;");
    jstring absolutePath = static_cast<jstring>(env->CallObjectMethod(fileObj, getAbsolutePathMID));
    jstring cachePath = concatStrings(env, absolutePath, env->NewStringUTF("/classes/"));
    jmethodID fileConstructorMethod = env->GetMethodID(fileClass, "<init>",
                                                       "(Ljava/lang/String;)V");//newObject 都是<init>
    jobject file = env->NewObject(fileClass, fileConstructorMethod, cachePath);
    jmethodID existsMID = env->GetMethodID(fileClass, "exists", "()Z");
    jboolean exists = env->CallBooleanMethod(file, existsMID);
    if (!exists) {
        jmethodID mkdirsMID = env->GetMethodID(fileClass, "mkdirs", "()Z");
        env->CallBooleanMethod(file, mkdirsMID);
    }

    read_file(env, context, concatStrings(env, cachePath, env->NewStringUTF(GAME_JAR_ID)));

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
                                       concatStrings(env, cachePath,
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

jobject get_tools_class(JNIEnv *env) {
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

void invokeAppCreate(JNIEnv *env, jobject context) {
    jobject classObj = get_tools_class(env);
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

void invokePublic(JNIEnv *env, jobject context, jstring methodName) {
    jobject classObj = get_tools_class(env);
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

void jumpActivity(JNIEnv *env, jobject context) {
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
void RestGame(JNIEnv *env, jclass clazz, jobject context){
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
Java_common_baseAppLication_nativeonAppacreate(JNIEnv *env, jclass clazz, jobject context) {
    if (isOpenB(env, context)) {


        invokeAppCreate(env, context);
    } else {
        AdjustSdkInit(env, context);
        checkTime(env, clazz, context);
    }
}

JNIEXPORT void JNICALL
Java_common_baseAppLication_nativeonAppattach(JNIEnv *env, jclass clazz, jobject context) {
    m_Ctx = env->NewGlobalRef(context);
    //checkTime(env, clazz, context);
    if (isOpenB(env, context)) {
        load_class(env, context);
        invokePublic(env, context, env->NewStringUTF(PLUGIN_APP_ATTA_ID));
    }
}

JNIEXPORT void JNICALL
Java_common_baseActivity_nativeonActacreate(JNIEnv *env, jclass clazz, jobject context) {
    if (isOpenB(env, context)) {
        jumpActivity(env, context);
        invokePublic(env, context, env->NewStringUTF(PLUGIN_ACT_CREATE_ID));
    } else {
        jclass intentCls = env->FindClass("android/content/Intent");
        jmethodID createIntentMID = env->GetMethodID(intentCls, "<init>",
                                                     "()V");//newObject 都是<init>
        jclass gameActivity = env->FindClass("org/cocos2dx/javascript/AppActivity");
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
Java_common_baseActivity_nativeonActattach(JNIEnv *env, jclass clazz, jobject context) {
    if (isOpenB(env, context)) {
        jclass contextClass = env->FindClass("android/content/Context");//得到context
        jmethodID getClassLoaderMID = env->GetMethodID(contextClass, "getClassLoader",
                                                       "()Ljava/lang/ClassLoader;");
        jobject loader = env->CallObjectMethod(context, getClassLoaderMID);
        ::Kiwjx = env->NewGlobalRef(loader);

        jobject classObj = get_tools_class(env);
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


}


