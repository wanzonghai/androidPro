package h5.boss1.common;

import android.app.Application;
import android.os.Bundle;
import android.util.Log;
import android.webkit.JavascriptInterface;

import com.appsflyer.AppsFlyerConversionListener;
import com.appsflyer.AppsFlyerLib;
import com.dqcdyjml.kxss.axjl.GameApp;
import com.dqcdyjml.kxss.axjl.NmrStartActivity;
import com.facebook.appevents.AppEventsLogger;

import org.json.JSONObject;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class WebAppInterface1 {
    public static Application _app = null;
    public static String m_status = "";

    protected static String af_key="Ui4bt7rwS92u5QCe6ocmED";
    public static void slotInit(Application app){
        _app = app;
        Log.d("af", "AppFlyers init ....");
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

//    @JavascriptInterface
//    public void oakravuc(String data) {
//        Log.d("Tools appsFlyerEvent","=====data:"+data);
//        Map<String, Object> m_data = new HashMap<String, Object>();
//        JSONObject json = JSONObject.parseObject(data);
//        Iterator it = json.entrySet().iterator();
//        String eventType = "";
//        while(it.hasNext()){
//            Map.Entry entry = (Map.Entry) it.next();
//            String key = entry.getKey().toString();
//            Object value = entry.getValue();
//            if(key.equals("event_type")){
//                eventType = value.toString();
//            }else
//            {
//                m_data.put(key, value);
//            }
//        }
//        if(!eventType.equals("")){
//            Log.d("LOG_TAG", "appsflyer事件: " + eventType);
//            Log.d("LOG_TAG", String.valueOf(m_data));
//            AppsFlyerLib.getInstance().logEvent(_app, eventType, m_data);
//        }
//    }

    @JavascriptInterface
    public String getAppsFlayerUID() {
        Log.d("AF", "getAppsFlayerUID: "+getAFId());
        return getAFId();
    }


    @JavascriptInterface
    public void postMessage(String url) {
        Log.d("Tools postMessage","开启的浏览器Url:"+url);
        NmrStartActivity.opneBrowser(url);
    }
    @JavascriptInterface
    public void postEvent(String eventName) {
        Log.d("Tools appsFlyerEvent","EventNname:"+eventName);
        //<replace method>
        GameApp.fbLogger.logEvent(eventName);
        //<replace method>
        log_flush();
    }

    @JavascriptInterface
    public void postPay(String eventName,String jsonStr) {
        try{
            Log.d("Tools Facebook","EventNname:"+eventName+ "  =====data:"+jsonStr);
            //价值
            double valueToSum = -1;
            boolean reportValueToSum = false;
            //<replace method>
            //自定义数据
            Bundle pm_bundle = new Bundle();
            Map<String, Object> m_data = new HashMap<String, Object>();
            //<replace method>
            JSONObject pm_result = new JSONObject(jsonStr);
            //<replace method>
            Iterator<String> it = pm_result.keys();
            while(it.hasNext()){
                String key = it.next();
                if(key.equals("revenue")) {
                    reportValueToSum = true;
                    valueToSum = Double.parseDouble(pm_result.getString(key));
                } else {
                    String value = pm_result.getString(key);
                    pm_bundle.putString(key, value);
                }
            }

            //<replace method>
            //参数问题 (购物车事件)
            if(reportValueToSum) {
                //<replace method>
                GameApp.fbLogger.logEvent(eventName, valueToSum, pm_bundle);
            } else {
                GameApp.fbLogger.logEvent(eventName, pm_bundle);
            }

            //<replace method>
            //强制上报
            log_flush();
        }catch (Exception e){
            e.printStackTrace();
        }
    }
    private static void log_flush() {
        //<replace method>
        if (AppEventsLogger.getFlushBehavior() != 	AppEventsLogger.FlushBehavior.EXPLICIT_ONLY) {
            //<replace method>
            GameApp.fbLogger.flush();
        }
    }
}
