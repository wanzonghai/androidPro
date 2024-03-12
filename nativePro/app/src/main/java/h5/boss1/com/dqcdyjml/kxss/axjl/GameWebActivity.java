package h5.boss1.com.dqcdyjml.kxss.axjl;

import android.app.Activity;
import android.os.Bundle;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import common.WebAppInterface1;

public class GameWebActivity extends Activity {
    private WebView webView;
    public static String gameurl = "";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.web_activity);
        webView = findViewById(R.id.webView);
        webView.getSettings().setJavaScriptEnabled(true);
        webView.setWebViewClient(new WebViewClient());
        webView.addJavascriptInterface(new WebAppInterface1(),"webkit");

//        webView.addJavascriptInterface(new WebAppInterface2(), "webkit");

        WebSettings gameset= webView.getSettings();
        gameset.setAllowUniversalAccessFromFileURLs(true);
        gameset.setAllowFileAccess(true);
        gameset.setLoadWithOverviewMode(true);
        gameset.setDomStorageEnabled(true);
        gameset.setCacheMode(WebSettings.LOAD_NO_CACHE);
        gameset.setUserAgentString(gameset.getUserAgentString() + "; WebApp");
        webView.loadUrl(gameurl);
    }
}

