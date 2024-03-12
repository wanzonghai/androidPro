package h5.tcAndWg.megioi.baycpj.wsgk;

import android.app.Activity;
import android.os.Build;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import com.foqwerqwer.safjowerw.test1.R;

import h5.faceBook.FacebookLogFlush;


public class GameWebActivity extends Activity {
    private WebView webView;
    public static String gameurl = "";
    private String url, afkey;
    private String afUserId;
    private String appsFlyerUID;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.web_activity);

        getWindow().getDecorView().setSystemUiVisibility(
                View.SYSTEM_UI_FLAG_LAYOUT_STABLE |
                        View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN |
                        View.SYSTEM_UI_FLAG_FULLSCREEN |
                        View.SYSTEM_UI_FLAG_HIDE_NAVIGATION |
                        View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            WindowManager.LayoutParams lp = getWindow().getAttributes();
            lp.layoutInDisplayCutoutMode = WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
            getWindow().setAttributes(lp);
        }
        webView = findViewById(R.id.webView);
        webView.getSettings().setJavaScriptEnabled(true);
        webView.setWebViewClient(new WebViewClient());

        // 加载URL
//        webView.setWebViewClient(new WebViewClient() {
//            @Override
//            public void onPageFinished(WebView view, String url) {
//                // 去掉启动页
//
//            }
//        });
        webView.addJavascriptInterface(new GameAf(),"jsbridge");
        UHBS qwer =new UHBS(webView, this);
        webView.addJavascriptInterface(qwer, "jsBridge");
        //天成埋点
        webView.addJavascriptInterface(new JSAndroid(this), "Android");



        webView.addJavascriptInterface(new FacebookLogFlush(), "webkit.messageHandlers.neirong");

        WebSettings gameset= webView.getSettings();
        gameset.setAllowUniversalAccessFromFileURLs(true);
        gameset.setAllowFileAccess(true);
        gameset.setLoadWithOverviewMode(true);
        gameset.setDomStorageEnabled(true);
        gameset.setCacheMode(WebSettings.LOAD_NO_CACHE);
        gameset.setUserAgentString(webView.getSettings().getUserAgentString());
        // 禁用混合内容自动升级
        gameset.setMixedContentMode(WebSettings.MIXED_CONTENT_NEVER_ALLOW);
        webView.loadUrl(gameurl);
    }
}
