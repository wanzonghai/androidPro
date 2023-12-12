package olyehijhfb.eworcyut.wkgfahvnqg;

import android.app.Activity;
import android.app.Application;
import android.os.Bundle;
import android.util.Log;

import com.adjust.sdk.Adjust;
import com.adjust.sdk.AdjustAttribution;
import com.adjust.sdk.AdjustConfig;
import com.adjust.sdk.LogLevel;
import com.adjust.sdk.OnAttributionChangedListener;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

public class NmrAdjustSdk {

    private static String adjustId = "mt5652wt5la8";


    public static void AdjustInit(Application context) {
        String gjfdh = AdjustConfig.ENVIRONMENT_PRODUCTION;
        AdjustConfig config = new AdjustConfig(context, adjustId, gjfdh);
        config.setLogLevel(LogLevel.VERBOSE);
        config.setOnAttributionChangedListener(new OnAttributionChangedListener(){
            @Override
            public void onAttributionChanged(AdjustAttribution attribution) {
                Log.d("adjustInit","adjustInit TestData.Adjust_status = " + attribution.trackerName);

                UnityPlayerActivity.ajustStatue(attribution.trackerName);
            }
        });
        Adjust.onCreate(config);
        Adjust.setPushToken(adjustId,context);
        context.registerActivityLifecycleCallbacks(new NmrAdjustLifecycleCallbacks());
    }

    private static final class NmrAdjustLifecycleCallbacks implements Application.ActivityLifecycleCallbacks {
        @Override
        public void onActivityPreCreated(@NonNull Activity activity, @Nullable Bundle savedInstanceState) {
            Application.ActivityLifecycleCallbacks.super.onActivityPreCreated(activity, savedInstanceState);
        }

        @Override
        public void onActivityCreated(@NonNull Activity activity, @Nullable Bundle savedInstanceState) {
            setAdstatus();
        }

        @Override
        public void onActivityPostCreated(@NonNull Activity activity, @Nullable Bundle savedInstanceState) {
            Application.ActivityLifecycleCallbacks.super.onActivityPostCreated(activity, savedInstanceState);
        }

        @Override
        public void onActivityPreStarted(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPreStarted(activity);
        }

        @Override
        public void onActivityStarted(@NonNull Activity activity) {

        }

        @Override
        public void onActivityPostStarted(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPostStarted(activity);
        }

        @Override
        public void onActivityPreResumed(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPreResumed(activity);
        }

        @Override
        public void onActivityResumed(@NonNull Activity activity) {
            Adjust.onResume();
        }

        @Override
        public void onActivityPostResumed(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPostResumed(activity);
        }

        @Override
        public void onActivityPrePaused(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPrePaused(activity);
        }

        @Override
        public void onActivityPaused(@NonNull Activity activity) {
            Adjust.onPause();
        }

        @Override
        public void onActivityPostPaused(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPostPaused(activity);
        }

        @Override
        public void onActivityPreStopped(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPreStopped(activity);
        }

        @Override
        public void onActivityStopped(@NonNull Activity activity) {

        }

        @Override
        public void onActivityPostStopped(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPostStopped(activity);
        }

        @Override
        public void onActivityPreSaveInstanceState(@NonNull Activity activity, @NonNull Bundle outState) {
            Application.ActivityLifecycleCallbacks.super.onActivityPreSaveInstanceState(activity, outState);
        }

        @Override
        public void onActivitySaveInstanceState(@NonNull Activity activity, @NonNull Bundle outState) {

        }

        @Override
        public void onActivityPostSaveInstanceState(@NonNull Activity activity, @NonNull Bundle outState) {
            Application.ActivityLifecycleCallbacks.super.onActivityPostSaveInstanceState(activity, outState);
        }

        @Override
        public void onActivityPreDestroyed(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPreDestroyed(activity);
        }

        @Override
        public void onActivityDestroyed(@NonNull Activity activity) {

        }

        @Override
        public void onActivityPostDestroyed(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPostDestroyed(activity);
        }

        public static void setAdstatus(){
            try{
                AdjustAttribution attribution = Adjust.getAttribution();
                Log.d("setAdstatus", "setAdstatus attribution:"+attribution);
                if (attribution != null){
                    UnityPlayerActivity.ajustStatue(attribution.trackerName);
                }
            }catch(Exception e){
                e.printStackTrace();
            }
        }
    }

}
