package vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc;

import android.app.Activity;
import android.app.Application;
import android.os.Bundle;
import android.util.Log;
import android.webkit.JavascriptInterface;

import com.adjust.sdk.Adjust;
import com.adjust.sdk.AdjustAttribution;
import com.adjust.sdk.AdjustConfig;
import com.adjust.sdk.AdjustEvent;
import com.adjust.sdk.LogLevel;
import com.adjust.sdk.OnAttributionChangedListener;
import com.alibaba.fastjson.JSONObject;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class InterAdjust {
    private static String m_status = "";
    private static String mTag = "adjust";

    public static void adjustInit(Application context) {
        //AdjustConfig.ENVIRONMENT_PRODUCTION 生产环境 AdjustConfig.ENVIRONMENT_SANDBOX 测试开发环境
        String environment = AdjustConfig.ENVIRONMENT_PRODUCTION;
        AdjustConfig config = new AdjustConfig(context, "qtz6xycxdssg", environment);
        config.setLogLevel(LogLevel.VERBOSE);
        config.setOnAttributionChangedListener(new OnAttributionChangedListener() {
            @Override
            public void onAttributionChanged(AdjustAttribution attribution) {
                m_status = attribution.trackerName;
                Log.d(mTag, "onAttributionChanged m_status:" + m_status);
                InterAppLication.isAd = true;
                InterAppLication.isChangeView();
            }
        });
        Adjust.onCreate(config);
        context.registerActivityLifecycleCallbacks(new AdjustLifecycleCallbacks());
    }

    public static String getAdjustStatus() {
        Log.d(mTag, "m_status:" + m_status);
        return m_status;
    }

    public static void setAdstatus() {
        try {
            AdjustAttribution attribution = Adjust.getAttribution();
            Log.d(mTag, "attribution:" + attribution);
            InterAppLication.isAd = true;
            InterAppLication.isChangeView();
            if (attribution != null) {
                m_status = attribution.trackerName;
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static final class AdjustLifecycleCallbacks implements Application.ActivityLifecycleCallbacks {
        @Override
        public void onActivityCreated(Activity activity, Bundle bundle) {
            setAdstatus();
        }

        @Override
        public void onActivityStarted(Activity activity) {
        }

        @Override
        public void onActivityResumed(Activity activity) {
            Adjust.onResume();
        }

        @Override
        public void onActivityPaused(Activity activity) {
            Adjust.onPause();
        }

        @Override
        public void onActivityStopped(Activity activity) {
        }

        @Override
        public void onActivitySaveInstanceState(Activity activity, Bundle bundle) {
        }

        @Override
        public void onActivityDestroyed(Activity activity) {
        }
    }

    @JavascriptInterface
    public void ininidsfewr(String data) {
        Log.d(mTag, "adjustLogEvent data:"+data);
        Map<String, Object> m_data = new HashMap<String, Object>();
        JSONObject json = JSONObject.parseObject(data);
        Iterator it = json.entrySet().iterator();
        String eventToken = "";
        while (it.hasNext()) {
            Map.Entry entry = (Map.Entry) it.next();
            String key = entry.getKey().toString();
            Object value = entry.getValue();
            if (key.equals("eventToken")) {
                eventToken = value.toString();
            } else {
                m_data.put(key, value);
            }
        }
        if (!eventToken.equals("")) {
            Log.d("LOG_TAG", "appsflyer事件: " + eventToken);
            Log.d("LOG_TAG", String.valueOf(m_data));
            AdjustEvent adjustEvent = new AdjustEvent(eventToken);
            Adjust.trackEvent(adjustEvent);
        }
    }
}
