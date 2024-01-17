package game;

import android.app.Activity;
import android.os.Bundle;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import gfd.erwrew.mnja.R;


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
        webView.addJavascriptInterface(new GameAf(),"jsbridge");
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
