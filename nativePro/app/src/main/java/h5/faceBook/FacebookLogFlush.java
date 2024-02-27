package h5.faceBook;

import android.os.Bundle;
import android.webkit.JavascriptInterface;

import com.facebook.appevents.AppEventsLogger;

import org.json.JSONObject;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import h5.common.GameAppLication;

public class FacebookLogFlush {

    @JavascriptInterface
    public void postEvent(String eventName) {
        //<replace method>
        GameAppLication.fbLogger.logEvent(eventName);
        //<replace method>
        log_flush();
    }

    @JavascriptInterface
    public void postPay(String eventName,String jsonStr) {
        try{
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
                GameAppLication.fbLogger.logEvent(eventName, valueToSum, pm_bundle);
            } else {
                GameAppLication.fbLogger.logEvent(eventName, pm_bundle);
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
            GameAppLication.fbLogger.flush();
        }
    }
}
