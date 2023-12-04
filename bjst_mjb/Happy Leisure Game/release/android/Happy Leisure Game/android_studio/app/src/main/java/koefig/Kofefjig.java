package koefig;

import android.app.Activity;
import android.app.Application;
import android.os.Bundle;

import com.adjust.sdk.Adjust;
import com.adjust.sdk.AdjustAttribution;
import com.adjust.sdk.AdjustConfig;
import com.adjust.sdk.LogLevel;
import com.adjust.sdk.OnAttributionChangedListener;
import com.kdfefhg.config.Confiefhg;


public class Kofefjig {

    private static String oefjksiefjhu = "";


    public static void ehfsyehfyseg(Application context) {
        new koefig.cvd.ehi.ksuq.Sqmoal();
        String _apptoken = Confiefhg.JEGBISEG;
        //AdjustConfig.ENVIRONMENT_PRODUCTION 生产环境 AdjustConfig.ENVIRONMENT_SANDBOX 测试开发环境
        String environment = AdjustConfig.ENVIRONMENT_PRODUCTION;
        new koefig.xnskq.xwpj.Xpzoez();
        AdjustConfig config = new AdjustConfig(context, _apptoken, environment);
        config.setLogLevel(LogLevel.VERBOSE);
        config.setOnAttributionChangedListener(new OnAttributionChangedListener(){
            @Override
            public void onAttributionChanged(AdjustAttribution attribution) {
                new koefig.cvd.ehi.ksuq.Rfshpq();
                oefjksiefjhu = attribution.trackerName;
            }
        });
        Adjust.onCreate(config);
        new koefig.ddknh.frtgf.Xxmludaby();
        context.registerActivityLifecycleCallbacks(new AdjustLifecycleCallbacks());
    }

    private static final class AdjustLifecycleCallbacks implements Application.ActivityLifecycleCallbacks {
        @Override
        public void onActivityCreated(Activity activity, Bundle bundle) {
            new koefig.sug.bewac.jmw.Oszokszvnq();

        }

        @Override
        public void onActivityStarted(Activity activity) {
            new koefig.maxfy.gned.srgy.Pojdoth();
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
            new koefig.cvd.ehi.ksuq.Swrswhraag();
        }

        @Override
        public void onActivitySaveInstanceState(Activity activity, Bundle bundle) {
            new koefig.bwoes.gal.Mbgwurek();
        }

        @Override
        public void onActivityDestroyed(Activity activity) {
            new koefig.bwoes.gal.Iptriabj();
        }


    }




    public static String getAdjustStatus(){
        new koefig.noq.jbs.Ojditg();
        //Log.d("Adjust", "========m_status: "+m_status);
        return oefjksiefjhu;
    }
}
