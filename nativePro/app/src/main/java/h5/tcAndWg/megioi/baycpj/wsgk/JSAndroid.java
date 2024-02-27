package h5.tcAndWg.megioi.baycpj.wsgk;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.util.Log;
import android.webkit.JavascriptInterface;

import com.appsflyer.AppsFlyerLib;
import com.google.gson.Gson;
import com.google.gson.reflect.TypeToken;

import java.lang.reflect.Type;
import java.util.Map;

public class JSAndroid {
    private static final String TAG = "window.Android";
    private final Activity activity;

    public JSAndroid(Activity activity) {
        this.activity = activity;
    }

    @JavascriptInterface
    public void openWebView(String url) {
        Log.e(TAG, "call: window.Android.openWebView  ===  " + "url");
        if (!url.contains("pay")) {
            Intent intent = new Intent();
            intent.setAction("android.intent.action.VIEW");
            Uri content_url = Uri.parse(url);
            intent.setData(content_url);
            activity.startActivity(intent);
        }
    }

    @JavascriptInterface
    public void eventTracker(String eventType, String eventValues) {
        Log.e(TAG, "call: window.Android.eventTracker ==== " +eventType +"===eventValues==="+eventValues);
        Gson gson = new Gson();
        Type type = new TypeToken<Map<String, Object>>() {
        }.getType();
        Map<String, Object> map = gson.fromJson(eventValues, type);

        AppsFlyerLib.getInstance().logEvent(activity, eventType, map);
    }
}
