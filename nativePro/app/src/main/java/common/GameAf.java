package common;

import android.app.Activity;
import android.app.Application;
import android.util.Log;
import android.webkit.JavascriptInterface;

import com.adjust.sdk.Adjust;
import com.alibaba.fastjson.JSONObject;
import com.appsflyer.AppsFlyerConversionListener;
import com.appsflyer.AppsFlyerLib;


import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class GameAf {
    public static Application _app = null;
    public static String m_status = "";

    protected static String af_key="bnkyPfbqtHyY7puNsuYjHh";
    public static void slotInit(Application app){
        _app = app;
        AppsFlyerConversionListener __listener = new AppsFlyerConversionListener() {
            @Override
            public void onConversionDataSuccess(Map<String, Object> conversionData) {
                for (String attrName : conversionData.keySet()) {
                    if(null != conversionData.get(attrName) && "" != conversionData.get(attrName)){
                        if(attrName.equals("af_status")){
                            m_status = (String)conversionData.get(attrName);
                        }
                        Log.d("af", "af_status: "+ m_status);
                    }
                }
            }
            @Override
            public void onConversionDataFail(String errorMessage) {
                Log.d("af", "af_status error: "+ errorMessage);
            }
            @Override
            public void onAppOpenAttribution(Map<String, String> conversionData) {

            }
            @Override
            public void onAttributionFailure(String errorMessage) {
            }
        };

        AppsFlyerLib.getInstance().init(af_key, __listener, _app);

        AppsFlyerLib.getInstance().start(_app);
    }

    public static String getAFId(){
        return AppsFlyerLib.getInstance().getAppsFlyerUID(_app);
    }

    public static String getSlotState(){
        return m_status;
    }

    @JavascriptInterface
    public void oakravuc(String data) {
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
            AppsFlyerLib.getInstance().logEvent(_app, eventType, m_data);
        }
    }

    @JavascriptInterface
    public String getAppsFlyerUID() {
        return getAFId();
    }

}
