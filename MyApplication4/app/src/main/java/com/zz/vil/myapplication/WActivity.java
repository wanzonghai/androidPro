package com.zz.vil.myapplication;

import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.Bundle;
import android.util.Log;
import android.view.KeyEvent;
import android.webkit.ConsoleMessage;
import android.webkit.JavascriptInterface;
import android.webkit.WebChromeClient;
import android.webkit.WebResourceError;
import android.webkit.WebResourceRequest;
import android.webkit.WebResourceResponse;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import androidx.appcompat.app.AppCompatActivity;

import com.appsflyer.AppsFlyerLib;
import com.appsflyer.attribution.AppsFlyerRequestListener;
import com.google.gson.Gson;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;

import java.util.HashMap;
import java.util.Map;
import java.util.Objects;

public class WActivity extends AppCompatActivity {

    private WebView coreView;
    private String url, afkey;
    private String afUserId;
    private String appsFlyerUID;

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        if (coreView != null) {
            if ((keyCode == KeyEvent.KEYCODE_BACK) && coreView.canGoBack()) {
                coreView.goBack();
                return true;
            }
        }
        return super.onKeyDown(keyCode, event);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_service);

        initView();
    }

    private void initView() {
        coreView = findViewById(R.id.service_view);
        setSettings(coreView);
        coreView.setWebChromeClient(new myWebChromeClient());
        coreView.setWebViewClient(new myWebViewClient());
        exitView();

    }

    public void setSettings(WebView webView) {
        WebSettings webSettings = webView.getSettings();

        String ua = webView.getSettings().getUserAgentString();
        webView.getSettings().setUserAgentString(ua);

        //巴西

        UHBS qwer =new UHBS(webView, this);
        webView.addJavascriptInterface(qwer, "jsBridge");



        //天成埋点
        webView.addJavascriptInterface(new JSAndroid(this), "Android");


        //设置webview

        WebViewUtil.setSettings(webView);
        String appCacheDir = webView.getContext().getDir("cache", Context.MODE_PRIVATE).getPath();
        webSettings.setDatabasePath(appCacheDir);




    }



  private void exitView() {
      String ur = "";
      if (ur != null) {
          coreView.loadUrl(Objects.requireNonNull(ur));
      }

    }

    public static class myWebChromeClient extends WebChromeClient {
        @Override
        public boolean onConsoleMessage(ConsoleMessage consoleMessage) {

            return super.onConsoleMessage(consoleMessage);
        }
    }

    public static class myWebViewClient extends WebViewClient {
        @Override
        public boolean shouldOverrideUrlLoading(WebView view, String url) {
            // 检查URL是否为外部链接
//            if (url != null && (url.startsWith("http://") || url.startsWith("https://"))) {
//                // 打开外部链接在用户的默认浏览器中
//                Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse(url));
//                view.getContext().startActivity(intent);
//                return true; // 表示已经处理了这个URL
//            }
            // 如果不是外部链接，继续在WebView中加载
            return false;
        }

        @Override
        public void onReceivedError(WebView view, WebResourceRequest request, WebResourceError error) {
            super.onReceivedError(view, request, error);

            Log.e("WebView", "onReceivedError: " + error.getErrorCode() + " " + error.getDescription());
        }

        @Override
        public void onReceivedHttpError(WebView view, WebResourceRequest request, WebResourceResponse errorResponse) {
            super.onReceivedHttpError(view, request, errorResponse);

            Log.e("WebView", "onReceivedHttpError: " + errorResponse.getStatusCode() + " " + errorResponse.getReasonPhrase());
        }
    }
}