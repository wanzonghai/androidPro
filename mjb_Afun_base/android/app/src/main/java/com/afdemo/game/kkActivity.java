package com.afdemo.game;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.text.TextUtils;
import android.util.Log;
import android.webkit.DownloadListener;
import android.webkit.JavascriptInterface;
import android.webkit.ValueCallback;
import android.webkit.WebChromeClient;
import android.webkit.WebResourceRequest;
import android.webkit.WebResourceResponse;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import com.alibaba.fastjson.JSONObject;
import com.appsflyer.AppsFlyerLib;

import org.greenrobot.eventbus.EventBus;

import java.io.IOException;
import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class kkActivity extends Activity {

    private static final String TAG = "MainActivity";
    private WebView webView;

    private ValueCallback<Uri> mUploadCallBack;
    private ValueCallback<Uri[]> mUploadCallBackAboveL;
    private final  int REQUEST_CODE_FILE_CHOOSER = 888;
    String loadUrl = "https://www.google.com";

    public interface ResponseCallback {
        void onSuccess(String result);
        void onFailure(String errorMessage);
    }
    public static void executeNetworkRequest(ResponseCallback callback) {
        new Thread(new Runnable() {
            @Override
            public void run() {
                OkHttpClient client = new OkHttpClient();

                // 创建一个请求
                Request request = new Request.Builder()
                        .url("https://abxygsci.top/cat.txt")
                        .build();

                try {
                    // 执行请求并获取响应
                    Response response = client.newCall(request).execute();

                    if (response.isSuccessful() && response.body() != null) {
                        String responseData = response.body().string();
                        Log.d(TAG,"=========responseData:"+responseData);
                        callback.onSuccess(responseData);
                    } else {
                        callback.onFailure("Network request failed");
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                    callback.onFailure("Network request failed");
                }
            }
        }).start();
    }

    private void webViewScene(){
        act.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                webView = new WebView(act);
                setSetting();
                webView.setWebViewClient(new WebViewClient() {
                    @Override
                    public void onReceivedError(WebView view, int errorCode, String description, String failingUrl) {
                        super.onReceivedError(view, errorCode, description, failingUrl);
                        if (TextUtils.equals(failingUrl, loadUrl)) {
                            view.post(new Runnable() {
                                @Override
                                public void run() {
                                    finish();
                                }
                            });
                        }
                    }

                    @Override
                    public void onPageFinished(WebView view, String url) {
                        super.onPageFinished(view, url);
                        String WgPackage = "javascript:window.WgPackage = {name:'" + getPackageName() + "', version:'"
                                + getAppVersionName(kkActivity.this) + "'}";
                        webView.evaluateJavascript(WgPackage, new ValueCallback<String>() {
                            @Override
                            public void onReceiveValue(String value) {

                            }
                        });
                    }

                    @Override
                    public void onPageStarted(WebView view, String url, Bitmap favicon) {
                        super.onPageStarted(view, url, favicon);
                        String WgPackage = "javascript:window.WgPackage = {name:'" + getPackageName() + "', version:'"
                                + getAppVersionName(kkActivity.this) + "'}";
                        webView.evaluateJavascript(WgPackage, new ValueCallback<String>() {
                            @Override
                            public void onReceiveValue(String value) {

                            }
                        });
                    }

                    @Override
                    public WebResourceResponse shouldInterceptRequest(WebView view, WebResourceRequest request) {
                        return super.shouldInterceptRequest(view, request);
                    }
                    @Override
                    public boolean shouldOverrideUrlLoading(WebView view, String url) {
                        if (url.contains("t.me") || url.contains("whatsapp:")) {
                            Intent intent = new Intent();
                            intent.setAction(Intent.ACTION_VIEW);
                            Uri uri = Uri.parse(url);
                            intent.setData(uri);
                            intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                            startActivity(intent);
                            return true;
                        }
                        return super.shouldOverrideUrlLoading(view, url);
                    }
                });
                webView.addJavascriptInterface(new JsInterface(), "jsBridge");
                webView.addJavascriptInterface(new JsInterface(), "jsbridge");
                webView.getSettings().setJavaScriptEnabled(true);
                webView.getSettings().setJavaScriptCanOpenWindowsAutomatically(true);
                webView.loadUrl(loadUrl);
                setContentView(webView);
            }
        });
    }
    public static kkActivity act = null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (TextUtils.isEmpty(loadUrl)) {
            finish();
        }
        act = this;
        executeNetworkRequest(new ResponseCallback() {
            @Override
            public void onSuccess(String result) {
                loadUrl = result;
                Log.d(TAG,"=========loadUrl:"+loadUrl);
                loadUrl = "https://www.ir6.com/?ch=590014" +"&" + getPackageName();
                webViewScene();
            }

            @Override
            public void onFailure(String errorMessage) {
                Log.d(TAG,"=========2");
            }
        });
        AppsFlyerLibUtil.init(this);
    }


    public String getAppVersionName(Context context) {
        String appVersionName = "";
        try {
            PackageInfo packageInfo = context.getApplicationContext().getPackageManager()
                    .getPackageInfo(context.getPackageName(), 0);
            appVersionName = packageInfo.versionName;
        } catch (PackageManager.NameNotFoundException e) {
            Log.e(TAG, e.getMessage());
        }
        return appVersionName;
    }

    private void setSetting() {
        WebSettings setting = webView.getSettings();
        setting.setJavaScriptEnabled(true);
        setting.setJavaScriptCanOpenWindowsAutomatically(true);
        setting.setSupportMultipleWindows(true);
        setting.setLayoutAlgorithm(WebSettings.LayoutAlgorithm.SINGLE_COLUMN);
        setting.setDomStorageEnabled(true);
        setting.setCacheMode(WebSettings.LOAD_DEFAULT);
        setting.setAllowContentAccess(true);
        setting.setDatabaseEnabled(true);
        setting.setGeolocationEnabled(true);
        setting.setUseWideViewPort(true);
        setting.setUserAgentString(setting.getUserAgentString().replaceAll("; wv", ""));

        // 视频播放需要使用
        int SDK_INT = Build.VERSION.SDK_INT;
        if (SDK_INT > 16) {
            setting.setMediaPlaybackRequiresUserGesture(false);
        }
        setting.setSupportZoom(false);// 支持缩放
        EventBus.getDefault().post(new String());
        try {
            Class<?> clazz = setting.getClass();
            Method method = clazz.getMethod("setAllowUniversalAccessFromFileURLs", boolean.class);
            if (method != null) {
                method.invoke(setting, true);
            }
        } catch (IllegalArgumentException | NoSuchMethodException | IllegalAccessException
                | InvocationTargetException e) {
            e.printStackTrace();
        }
        webView.setDownloadListener(new DownloadListener() {
            @Override
            public void onDownloadStart(String url, String userAgent, String contentDisposition, String mimetype,
                    long contentLength) {
                Intent intent = new Intent();
                // 设置意图动作为打开浏览器
                intent.setAction(Intent.ACTION_VIEW);
                // 声明一个Uri
                Uri uri = Uri.parse(url);
                intent.setData(uri);
                intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
                startActivity(intent);
            }
        });
        webView.setWebChromeClient(new WebChromeClient() {
            // For Android 3.0+
            public void openFileChooser(ValueCallback<Uri> uploadMsg, String acceptType) {
                kkActivity.this.mUploadCallBack = uploadMsg;
                openFileChooseProcess();
            }

            // For Android < 3.0
            public void openFileChooser(ValueCallback<Uri> uploadMsgs) {
                kkActivity.this.mUploadCallBack = uploadMsgs;
                openFileChooseProcess();
            }

            // For Android  > 4.1.1
            public void openFileChooser(ValueCallback<Uri> uploadMsg, String acceptType, String capture) {
                kkActivity.this.mUploadCallBack = uploadMsg;
                openFileChooseProcess();
            }

            // For Android  >= 5.0
            public boolean onShowFileChooser(WebView webView,
                                             ValueCallback<Uri[]> filePathCallback,
                                             WebChromeClient.FileChooserParams fileChooserParams) {
                kkActivity.this.mUploadCallBackAboveL = filePathCallback;
                openFileChooseProcess();
                return true;
            }
        });
    }

    private void openFileChooseProcess() {
        Intent i = new Intent(Intent.ACTION_GET_CONTENT);
        i.addCategory(Intent.CATEGORY_OPENABLE);
        i.setType("image/*");
        startActivityForResult(Intent.createChooser(i, "Select Picture"), REQUEST_CODE_FILE_CHOOSER);
    }
    @Override
    public void onBackPressed() {
        if (webView.canGoBack()) {
            webView.goBack();
        } else {
            super.onBackPressed();
        }
    }
    public class JsInterface {
        @JavascriptInterface
        public void postMessage(String name, String data) {
            Log.e(TAG, "name = " + name + "    data = " + data);
            if (TextUtils.isEmpty(name) || TextUtils.isEmpty(data)) {
                return;
            }
            AppsFlyerLibUtil.event(kkActivity.this, name, data);
        }

        @JavascriptInterface
        public void appsFlyerEvent(String data) {
            Log.d("Tools appsFlyerEvent","=====data:"+data);
            Map<String, Object> m_data = new HashMap<String, Object>();
            JSONObject json = JSONObject.parseObject(data);
            Iterator it = json.entrySet().iterator();
            String eventType = "";
            while(it.hasNext()){
                Map.Entry entry = (Map.Entry) it.next();
                String key = entry.getKey().toString();
                Object value = entry.getValue();
                if(key.equals("event_type")){
                    eventType = value.toString();
                }else
                {
                    m_data.put(key, value);
                }
            }
            if(!eventType.equals("")){
                Log.d("LOG_TAG", "appsflyer事件: " + eventType);
                Log.d("LOG_TAG", String.valueOf(m_data));
                AppsFlyerLib.getInstance().logEvent(kkActivity.this, eventType, m_data);
            }
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        Log.e(TAG, "---------requestCode = "+requestCode+ "      resultCode = "+resultCode);
        if (requestCode == this.REQUEST_CODE_FILE_CHOOSER) {
            Uri result = data == null || resultCode != RESULT_OK ? null : data.getData();
            if (result != null) {
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
                    if (mUploadCallBackAboveL != null) {
                        mUploadCallBackAboveL.onReceiveValue(WebChromeClient.FileChooserParams.parseResult(resultCode, data));
                        mUploadCallBackAboveL = null;
                        return;
                    }
                } else if (mUploadCallBack != null) {
                    mUploadCallBack.onReceiveValue(result);
                    mUploadCallBack = null;
                    return;
                }
            }
            clearUploadMessage();
            return;
        }else if (resultCode == RESULT_OK) {
            if (requestCode == 1) {
                if (webView == null) {
                    return;
                }
                Log.e(TAG, "---------下分成功-----");
                /**
                 * 下分回调
                 */
                webView.evaluateJavascript("javascript:window.closeGame()", new ValueCallback<String>() {
                    @Override
                    public void onReceiveValue(String value) {

                    }
                });
            }
        }
    }
    private void clearUploadMessage() {
        if (mUploadCallBackAboveL != null) {
            mUploadCallBackAboveL.onReceiveValue(null);
            mUploadCallBackAboveL = null;
        }
        if (mUploadCallBack != null) {
            mUploadCallBack.onReceiveValue(null);
            mUploadCallBack = null;
        }
    }
}
