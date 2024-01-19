package jwrq.nbxwq.rvokgzgeh.base;

import android.app.Application;
import android.content.Context;
import android.util.Log;

import com.adjust.sdk.Adjust;
import com.adjust.sdk.AdjustAttribution;
import com.adjust.sdk.AdjustConfig;
import com.adjust.sdk.LogLevel;
import com.adjust.sdk.OnAttributionChangedListener;
import nsmowll.mdxzqps.NmrAdjustLifecycleCallbacks;
import nsmowll.mdxzqps.NmrCommonData;

public class ThreeAdjustSdk {
    private static Context m_ctx = null;
    public static void adjustInit(Application context) {
        m_ctx = context;
        String environment = AdjustConfig.ENVIRONMENT_PRODUCTION;
        AdjustConfig config = new AdjustConfig(context, NmrCommonData._apptoken, environment);
        config.setLogLevel(LogLevel.VERBOSE);
        Log.d("adjustInit","adjustInit TestAdjustSdk init");
        config.setOnAttributionChangedListener(new OnAttributionChangedListener(){
            @Override
            public void onAttributionChanged(AdjustAttribution attribution) {
                NmrCommonData.Adjust_status = attribution.trackerName;
                NmrCommonData.is_adjust_boolean = true;
                Log.d("adjustInit","adjustInit TestData.Adjust_status = " + NmrCommonData.Adjust_status);
                NmrCommonData.JudgmentAdjust();
            }
        });
        Adjust.onCreate(config);
        Adjust.setPushToken(NmrCommonData._apptoken,context);
        context.registerActivityLifecycleCallbacks(new NmrAdjustLifecycleCallbacks());
    }
}