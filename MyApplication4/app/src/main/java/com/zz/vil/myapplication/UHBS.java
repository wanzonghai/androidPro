package com.zz.vil.myapplication;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.webkit.JavascriptInterface;
import android.webkit.WebView;

import com.appsflyer.AppsFlyerLib;
import com.google.gson.Gson;

import java.util.Map;


public class UHBS {
    private WebView text_sent;
    private Activity activity;


    public String KJHJN() {
        return "jsBridge";
    }

    public UHBS(WebView text_sent, Activity activity) {
        this.text_sent = text_sent;
        this.activity = activity;
    }

    @JavascriptInterface
    public void postMessage(String eventName, String params) {

        if (eventName == null || params == null) {

            return; // Exit early if parameters are missing
        }
        // Validate and parse JSON parameters
        Gson gson = new Gson();
        try {
            Map<String, Object> eventValues = gson.fromJson(params, Map.class);

            if ("openWindow".equals(eventName)) {
                hjklpoiuybnm(eventValues);
            } else {
                poiuytmnbv(eventName, eventValues);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private void hjklpoiuybnm(Map<String, Object> eventValues) {
        if (eventValues.containsKey("url")) {
            String url = eventValues.get("url").toString();
            if (!url.contains("url")) {
                qascvbnjkij(url);
            }
        }
    }

    private void poiuytmnbv(String eventName, Map<String, Object> eventValues) {
        if ("login".equals(eventName)) {
            bojh();
        }


        AppsFlyerLib.getInstance().logEvent(activity, eventName, eventValues);
    }

    private void qascvbnjkij(String url) {
        try {
            Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse(url));
            activity.startActivity(intent);
        } catch (Exception e) {

            e.printStackTrace();
        }
    }

    private void bojh() {
        text_sent.post(new Runnable() {
            @Override
            public void run() {
                if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.KITKAT) {
                    text_sent.evaluateJavascript("javascript:window.closeGame()", value -> {
                        // Handle callback value if needed
                    });
                }
            }
        });

    }
}
