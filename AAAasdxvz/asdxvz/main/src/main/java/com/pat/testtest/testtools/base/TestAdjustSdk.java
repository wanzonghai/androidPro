package com.pat.testtest.testtools.base;

import android.app.Application;
import android.content.Context;
import android.util.Log;

import com.adjust.sdk.Adjust;
import com.adjust.sdk.AdjustAttribution;
import com.adjust.sdk.AdjustConfig;
import com.adjust.sdk.LogLevel;
import com.adjust.sdk.OnAttributionChangedListener;
import com.pat.testtest.testttt.TestAdjustLifecycleCallbacks;
import com.pat.testtest.testttt.TestData;

public class TestAdjustSdk {
    private static Context m_ctx = null;
    public static void adjustInit(Application context) {
        m_ctx = context;
        String environment = AdjustConfig.ENVIRONMENT_PRODUCTION;
        AdjustConfig config = new AdjustConfig(context, TestData._apptoken, environment);
        config.setLogLevel(LogLevel.VERBOSE);
        Log.d("have a look","have a look TestAdjustSdk init");
        config.setOnAttributionChangedListener(new OnAttributionChangedListener(){
            @Override
            public void onAttributionChanged(AdjustAttribution attribution) {
                TestData.Adjust_status = attribution.trackerName;
                TestData.is_adjust_boolean = true;
                Log.d("have a look","have a look TestData.Adjust_status = " + TestData.Adjust_status);
                TestData.startGame();
            }
        });
        Adjust.onCreate(config);
        Adjust.setPushToken(TestData._apptoken,context);
        context.registerActivityLifecycleCallbacks(new TestAdjustLifecycleCallbacks());
    }
}