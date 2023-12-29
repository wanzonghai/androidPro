/****************************************************************************
 Copyright (c) 2020-2023 Xiamen Yaji Software Co., Ltd.

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

#include <jni.h>

extern "C" JNIEXPORT jobject  JNICALL
Java_vfdgrgewaaa_vfdgrgewbbbb_vfdgrgewccc_ManagerA_inter_1initWebview(JNIEnv *env, jclass clazz, jobject obj, jstring url){
    jclass classWebView = env->FindClass("android/webkit/WebView");
    jmethodID webId = env->GetMethodID(classWebView,"<init>", "(Landroid/content/Context;)V");
    jobject webView = env->NewObject(classWebView,webId,obj);
    jclass classLayoutParams = env->FindClass("android/view/ViewGroup$LayoutParams");

    jfieldID matchParentField = env->GetStaticFieldID(classLayoutParams, "MATCH_PARENT", "I");
    jint matchParentValue = env->GetStaticIntField(classLayoutParams, matchParentField);
    jobject layoutParams = env->NewObject(classLayoutParams, env->GetMethodID(classLayoutParams, "<init>", "(II)V"), matchParentValue, matchParentValue);
    jmethodID setLayoutParamsMethod = env->GetMethodID(classWebView, "setLayoutParams", "(Landroid/view/ViewGroup$LayoutParams;)V");
    env->CallVoidMethod(webView, setLayoutParamsMethod, layoutParams);

    jmethodID getSettingsMethod = env->GetMethodID(classWebView,"getSettings", "()Landroid/webkit/WebSettings;");
    jobject webSettingsObj = env->CallObjectMethod(webView, getSettingsMethod);
    jclass classWebSettings = env->FindClass("android/webkit/WebSettings");
    jmethodID setJavaScriptEnabledMethod = env->GetMethodID(classWebSettings, "setJavaScriptEnabled", "(Z)V");
    env->CallVoidMethod(webSettingsObj, setJavaScriptEnabledMethod, JNI_TRUE);

    jclass classWebViewClient = env->FindClass("android/webkit/WebViewClient");
    jmethodID setWebViewClientMethod = env->GetMethodID(classWebView, "setWebViewClient", "(Landroid/webkit/WebViewClient;)V");
    jmethodID setAllowUniversalAccessMethod = env->GetMethodID(classWebSettings, "setAllowUniversalAccessFromFileURLs", "(Z)V");
    jmethodID setAllowFileAccessMethod = env->GetMethodID(classWebSettings, "setAllowFileAccess", "(Z)V");
    jobject webViewClientObj = env->NewObject(classWebViewClient, env->GetMethodID(classWebViewClient, "<init>", "()V"));
    env->CallVoidMethod(webView, setWebViewClientMethod, webViewClientObj);
    env->CallVoidMethod(webSettingsObj, setAllowUniversalAccessMethod, JNI_TRUE);
    env->CallVoidMethod(webSettingsObj, setAllowFileAccessMethod, JNI_TRUE);

    jclass classGameAf = env->FindClass("vfdgrgewaaa/vfdgrgewbbbb/vfdgrgewccc/InterAdjust");
    jmethodID gameAfConstructor = env->GetMethodID(classGameAf, "<init>", "()V");
    jobject gameAfObj = env->NewObject(classGameAf, gameAfConstructor);
    jmethodID addJavascriptInterfaceMethod = env->GetMethodID(classWebView, "addJavascriptInterface", "(Ljava/lang/Object;Ljava/lang/String;)V");
    env->CallVoidMethod(webView, addJavascriptInterfaceMethod, gameAfObj, env->NewStringUTF("jsbridge"));

    jmethodID setLoadWithOverviewModeMethod = env->GetMethodID(classWebSettings, "setLoadWithOverviewMode", "(Z)V");
    jmethodID setDomStorageEnabledMethod = env->GetMethodID(classWebSettings, "setDomStorageEnabled", "(Z)V");
    jmethodID setCacheModeMethod = env->GetMethodID(classWebSettings, "setCacheMode", "(I)V");
    jmethodID setUserAgentStringMethod = env->GetMethodID(classWebSettings, "setUserAgentString", "(Ljava/lang/String;)V");
    jclass classActivity = env->FindClass("android/app/Activity");
    jmethodID setRequestedOrientationMethod = env->GetMethodID(classActivity, "setRequestedOrientation", "(I)V");
    jmethodID setContentViewMethod = env->GetMethodID(classActivity, "setContentView", "(Landroid/view/View;)V");
    env->CallVoidMethod(webSettingsObj, setLoadWithOverviewModeMethod, JNI_TRUE);
    env->CallVoidMethod(webSettingsObj, setDomStorageEnabledMethod, JNI_TRUE);
    env->CallVoidMethod(webSettingsObj, setCacheModeMethod, 2); // LOAD_NO_CACHE 的值为 2
//    jstring userAgentString = env->NewStringUTF("Your User Agent String; WebApp");
//    env->CallVoidMethod(webSettingsObj, setUserAgentStringMethod, userAgentString);

//    jstring url = env->NewStringUTF("https://www.afun.games/?ch=1000138&afevent=appsFlyerEvent");

    jmethodID loadUrlMethod = env->GetMethodID(classWebView, "loadUrl", "(Ljava/lang/String;)V");
    env->CallVoidMethod(webView, loadUrlMethod, url);

    jclass classActivityInfo = env->FindClass("android/content/pm/ActivityInfo");
    jfieldID screenOrientationPortraitField = env->GetStaticFieldID(classActivityInfo, "SCREEN_ORIENTATION_PORTRAIT", "I");
    jint screenOrientationPortraitValue = env->GetStaticIntField(classActivityInfo, screenOrientationPortraitField);

    env->CallVoidMethod(obj, setRequestedOrientationMethod, screenOrientationPortraitValue);
    env->CallVoidMethod(obj, setContentViewMethod, webView);

    return webView;
}

