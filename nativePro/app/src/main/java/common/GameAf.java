package common;

import android.app.Activity;
import android.app.Application;
import android.content.Intent;
import android.net.Uri;
import android.text.TextUtils;
import android.util.Log;
import android.webkit.JavascriptInterface;
import android.widget.Toast;

import com.adjust.sdk.Adjust;
import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import com.appsflyer.AFInAppEventParameterName;
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
    public static void event(Activity context, String name, String data) {
        Map<String, Object> eventValue = new HashMap<String, Object>();
        if ("openWindow".equals(name)) {
            Log.d("openWindow", "======data: "+data);
            if (data.equals("undefined")){
                return;
            }
            String _url = "";
            Map maps = (Map) JSON.parse(data);
            for (Object map : maps.entrySet()) {
                String key = ((Map.Entry) map).getKey().toString();
                if ("url".equals(key)) {
                    Log.d("openWindow", "======url: "+((Map.Entry) map).getValue().toString());
                    _url = ((Map.Entry) map).getValue().toString();
                } else if ("currency".equals(key)) {
                    eventValue.put(AFInAppEventParameterName.CURRENCY, ((Map.Entry) map).getValue());
                }
            }
            Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse(_url));
            context.startActivity(intent);
        } else if ("firstrecharge".equals(name) || "recharge".equals(name)) {
            try {
                Map maps = (Map) JSON.parse(data);
                for (Object map : maps.entrySet()) {
                    String key = ((Map.Entry) map).getKey().toString();
                    if ("amount".equals(key)) {
                        eventValue.put(AFInAppEventParameterName.REVENUE, ((Map.Entry) map).getValue());
                    } else if ("currency".equals(key)) {
                        eventValue.put(AFInAppEventParameterName.CURRENCY, ((Map.Entry) map).getValue());
                    }
                }
            } catch (Exception e) {

            }
        }else if ("openURL".equals(name)){
            Log.d("openURL", "event: ===================openURL");
            Log.d("openURL", "event: ===================data"+data);
            Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse(data));
            context.startActivity(intent);
        } else if ("withdrawOrderSuccess".equals(name)) {
            try {
                Map maps = (Map) JSON.parse(data);
                for (Object map : maps.entrySet()) {
                    String key = ((Map.Entry) map).getKey().toString();
                    if ("amount".equals(key)) {
                        float revenue = 0;
                        String value = ((Map.Entry) map).getValue().toString();
                        if (!TextUtils.isEmpty(value)) {
                            revenue = Float.valueOf(value);
                            revenue = -revenue;
                        }
                        eventValue.put(AFInAppEventParameterName.REVENUE, revenue);

                    } else if ("currency".equals(key)) {
                        eventValue.put(AFInAppEventParameterName.CURRENCY, ((Map.Entry) map).getValue());
                    }
                }
            } catch (Exception e) {

            }
        } else {
            eventValue.put(name, data);
        }
        AppsFlyerLib.getInstance().logEvent(context, name, eventValue);
        Toast.makeText(context, name, Toast.LENGTH_SHORT).show();
    }
    @JavascriptInterface
    public String getAppsFlyerUID() {
        return getAFId();
    }

}
