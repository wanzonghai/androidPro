package com.cocos.game;
import android.app.Activity;
import android.content.Context;
import android.util.Log;
import android.view.ViewGroup;
import android.webkit.JavascriptInterface;
import android.webkit.WebSettings;
import android.webkit.WebView;
import android.webkit.WebViewClient;

import com.alibaba.fastjson.JSONObject;
import com.appsflyer.AppsFlyerLib;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class ManagerActivity {
    public static native WebView initWebview(Context context);
    private static Activity activity;
    public static void openWeb(Activity context) {
        activity = context;
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                initWebview(context);
            }
        });
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
            AppsFlyerLib.getInstance().logEvent(activity, eventType, m_data);
        }
    }
}
