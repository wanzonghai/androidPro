package org.cocos2dx.javascript;

import android.app.Activity;
import android.util.Log;


import androidx.annotation.NonNull;

import com.casualpoker.six.R;
import com.appsflyer.AFInAppEventParameterName;
import com.appsflyer.AppsFlyerConversionListener;
import com.appsflyer.AppsFlyerLib;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxJavascriptJavaBridge;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.Arrays;
import java.util.Collection;
import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;
import java.util.Objects;

public class AppsFlyerSDK {
    private static String LOG_TAG = "===AppsFlyerSDK===";
    private static AppsFlyerSDK mInstance = null;
    private static Activity mActivity = null;

    public static AppsFlyerSDK getInstance() {
        if (null == mInstance) {
            mInstance = new AppsFlyerSDK();
        }
        return mInstance;
    }

    /**e
     *  初始化
     */
    public void initSdk(Activity activity) {
        Log.e(LOG_TAG, "initSdk");
        mActivity = activity;
        AppsFlyerLib.getInstance().init(mActivity.getResources().getString(R.string.appsflyer_dev_key), null, mActivity);
        AppsFlyerLib.getInstance().start(mActivity);
        AppsFlyerLib.getInstance().setDebugLog(true);
        AppsFlyerLib.getInstance().registerConversionListener(mActivity, conversionListener);
    }

    AppsFlyerConversionListener conversionListener = new AppsFlyerConversionListener() {
        @Override
        public void onConversionDataSuccess(Map<String, Object> conversionDataMap) {
            for (String attrName : conversionDataMap.keySet())
                Log.e(LOG_TAG, "Conversion attribute: " + attrName + " = " + conversionDataMap.get(attrName));
            String status = Objects.requireNonNull(conversionDataMap.get("af_status")).toString();
            String isFirst = Objects.requireNonNull(conversionDataMap.get("is_first_launch")).toString();
            if (isFirst.equals("true")) {
                if (status.equals("Organic")) {
                    // Business logic for Organic conversion goes here.
                    Log.e(LOG_TAG, "自然量");
                    ((Cocos2dxActivity) mActivity).runOnGLThread(new Runnable() {
                        public void run() {
                            String DownResult = "window.mfConfig.onIsOrganicCallBack(\""+1+"\");";
                            Cocos2dxJavascriptJavaBridge.evalString(DownResult);
                        }
                    });
                } else {
                    // Business logic for Non-organic conversion goes here.
                    Log.e(LOG_TAG, "非自然量");
                    ((Cocos2dxActivity) mActivity).runOnGLThread(new Runnable() {
                        public void run() {
                            String DownResult = "window.mfConfig.onIsOrganicCallBack(\""+0+"\");";
                            Cocos2dxJavascriptJavaBridge.evalString(DownResult);
                        }
                    });
                }
            }

        }

        @Override
        public void onConversionDataFail(String errorMessage) {
            Log.e(LOG_TAG, "error getting conversion data: " + errorMessage);
        }

        @Override
        public void onAppOpenAttribution(Map<String, String> attributionData) {
            // Must be overriden to satisfy the AppsFlyerConversionListener interface.
            // Business logic goes here when UDL is not implemented.
        }

        @Override
        public void onAttributionFailure(String errorMessage) {
            // Must be overriden to satisfy the AppsFlyerConversionListener interface.
            // Business logic goes here when UDL is not implemented.
            Log.e(LOG_TAG, "error onAttributionFailure : " + errorMessage);
        }

    };

    public static void onEvent(String eventId, String eventData) {
        try {
            Log.e(LOG_TAG, "onEvent");
            JSONObject jsonData = new JSONObject(eventData);
            Map<String, Object> eventMap = new HashMap<String, Object>();
            Iterator<String> iterator = jsonData.keys();
            while (iterator.hasNext()) {
                String key = (String) iterator.next();
                Object value = jsonData.get(key);
                eventMap.put(key, value);
            }
            //eventId : AFInAppEventType.ADD_TO_WISHLIST
            Log.e(LOG_TAG, "onEvent eventId = " + eventId + ",eventMap =" + eventMap.toString());
            AppsFlyerLib.getInstance().logEvent(mActivity,
                    eventId, eventMap);
        } catch (JSONException e) {
            e.printStackTrace();
        }
    }
}
