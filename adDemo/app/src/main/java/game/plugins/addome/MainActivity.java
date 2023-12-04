package game.plugins.addome;

import android.os.Bundle;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import androidx.appcompat.app.AppCompatActivity;
public class MainActivity extends AppCompatActivity {
    private WebView webView;
    public static String gameurl = "https://clientview1.flea7900.vip/#/?adevent=loglog"; //  //ttp://bkl0ki9.com/?adevent=adjustLogEvent
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        webView = findViewById(R.id.webView);
        webView.getSettings().setJavaScriptEnabled(true);
        webView.setWebViewClient(new WebViewClient());
        webView.addJavascriptInterface(new adjustSdk(),"AndroidFunction");
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