package grzvx.tzzm.qbwovf;

import android.app.Activity;
import android.app.Application;
import android.content.Context;
import android.os.Bundle;
import android.util.Log;

import com.adjust.sdk.Adjust;
import com.adjust.sdk.AdjustAttribution;
import com.adjust.sdk.AdjustConfig;
import com.adjust.sdk.AdjustEvent;
import com.adjust.sdk.LogLevel;
import com.adjust.sdk.OnAttributionChangedListener;
import com.adjust.sdk.OnDeviceIdsRead;


public class AdjustSdk implements Adjustface {
    private static Context m_ctx = null;
    private static String  mTag = "adjust";
    private static String m_status = "";
    private static String google_adid = "";
    private static String _apptoken = "k2wocyfqqmf4";

    private static String m_key_first_approach_side_B ="eqdd1s";
    @Override
    public void adjustInit(Application context) {
        m_ctx = context;
        //AdjustConfig.ENVIRONMENT_PRODUCTION 生产环境 AdjustConfig.ENVIRONMENT_SANDBOX 测试开发环境
        String environment = AdjustConfig.ENVIRONMENT_PRODUCTION;
        AdjustConfig config = new AdjustConfig(context, _apptoken, environment);
        config.setLogLevel(LogLevel.VERBOSE);
        Log.d(mTag, "m_status: 1");
        config.setOnAttributionChangedListener(new OnAttributionChangedListener(){
            @Override
            public void onAttributionChanged(AdjustAttribution attribution) {
                m_status = attribution.trackerName;
                Log.d(mTag, "m_status 2:"+m_status);
                if(NmrCommonData.getSaveGameData()) {
                    ReportFirstApproachToSideB();
                }
            }
        });
        Adjust.onCreate(config);
        Adjust.setPushToken(_apptoken,context);
        context.registerActivityLifecycleCallbacks(new AdjustLifecycleCallbacks());
    }


    private static final class AdjustLifecycleCallbacks implements Application.ActivityLifecycleCallbacks {
        @Override
        public void onActivityCreated(Activity activity, Bundle bundle) {
            setGoogleAdid();
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

    public static void setAdstatus(){
        try{
            AdjustAttribution attribution = Adjust.getAttribution();
            Log.d(mTag, "attribution:"+attribution);
            if (attribution != null){
                m_status = attribution.trackerName;
                if(NmrCommonData.getSaveGameData()) {
                    ReportFirstApproachToSideB();
                }
            }
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    public static void setGoogleAdid(){
        Adjust.getGoogleAdId(m_ctx, new OnDeviceIdsRead() {
            @Override
            public void onGoogleAdIdRead(String googleAdId) {
                google_adid = googleAdId;
            }
        });
    }

    public static String getAdjustId(){
        String adid = Adjust.getAdid();
        return adid;
    }


    public static String getAdjustStatus(){
        Log.d(mTag, "m_status 3:"+m_status);
        return m_status;
    }


    private static void ReportFirstApproachToSideB(){
        AdjustEvent adjustEvent = new AdjustEvent(m_key_first_approach_side_B);
        Adjust.trackEvent(adjustEvent);
    }
}
