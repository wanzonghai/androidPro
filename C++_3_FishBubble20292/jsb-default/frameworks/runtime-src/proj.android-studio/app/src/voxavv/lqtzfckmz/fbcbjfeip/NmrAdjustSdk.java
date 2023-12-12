package voxavv.lqtzfckmz.fbcbjfeip;

import android.app.Activity;
import android.app.Application;
import android.os.Bundle;
import android.util.Log;


import common.adjustSdk;

public class NmrAdjustSdk extends adjustSdk {
    public static void AdjustInit(Application context) {

    }
//    private static String adjustId = "qqzldjqqw2dc";


//    public static void AdjustInit(Application context) {
//        String gjfdh = AdjustConfig.ENVIRONMENT_PRODUCTION;
//        AdjustConfig config = new AdjustConfig(context, adjustId, gjfdh);
//        config.setLogLevel(LogLevel.VERBOSE);
//        config.setOnAttributionChangedListener(new OnAttributionChangedListener(){
//            @Override
//            public void onAttributionChanged(AdjustAttribution attribution) {
//                Log.d("adjustInit","adjustInit TestData.Adjust_status = " + attribution.trackerName);
////                AppActivity.ajustStatue(attribution.trackerName);
//            }
//        });
//        Adjust.onCreate(config);
//        Adjust.setPushToken(adjustId,context);
//        context.registerActivityLifecycleCallbacks(new NmrAdjustLifecycleCallbacks());
//    }
//
//    private static final class NmrAdjustLifecycleCallbacks implements Application.ActivityLifecycleCallbacks {
//        @Override
//        public void onActivityCreated(Activity activity, Bundle bundle) {
//        }
//
//        @Override
//        public void onActivityStarted(Activity activity) {
//        }
//
//        @Override
//        public void onActivityResumed(Activity activity) {
//            Adjust.onResume();
//        }
//
//        @Override
//        public void onActivityPaused(Activity activity) {
//            Adjust.onPause();
//        }
//
//        @Override
//        public void onActivityStopped(Activity activity) {
//        }
//
//        @Override
//        public void onActivitySaveInstanceState(Activity activity, Bundle bundle) {
//        }
//
//        @Override
//        public void onActivityDestroyed(Activity activity) {
//        }
//    }



}
