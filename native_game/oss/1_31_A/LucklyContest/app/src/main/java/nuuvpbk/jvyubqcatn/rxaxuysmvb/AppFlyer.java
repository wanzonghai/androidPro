package nuuvpbk.jvyubqcatn.rxaxuysmvb;

import android.util.Log;

import com.appsflyer.AppsFlyerConversionListener;
import com.appsflyer.AppsFlyerLib;
import com.casualpoker.six.R;

import java.util.Map;

import rkencc.jtele.NmrCommonData;
import rkencc.jtele.oqusnsu.NmrApplication;

public class AppFlyer {


    public static String faswww(){
//        afw="asa";

        return NmrCommonData.Adjust_status;
    }
    public static NmrApplication _app = null;
    public static void adjustEntry(NmrApplication app) {
        Log.d("abc=====af", "afInit =============");
        _app = app;

        AppsFlyerConversionListener __listener = new AppsFlyerConversionListener() {
            @Override
            public void onConversionDataSuccess(Map<String, Object> conversionData) {
                for (String attrName : conversionData.keySet()) {
                    if(null != conversionData.get(attrName) && "" != conversionData.get(attrName)){
                        if(attrName.equals("af_status")){
                            NmrCommonData.Adjust_status = (String)conversionData.get(attrName);
                            NmrCommonData.JudgmentAdjust();
                        }
                        Log.d("abc=====af", "af_status: "+ NmrCommonData.Adjust_status);
                    }
                }
            }
            @Override
            public void onConversionDataFail(String errorMessage) {

            }
            @Override
            public void onAppOpenAttribution(Map<String, String> conversionData) {

            }
            @Override
            public void onAttributionFailure(String errorMessage) {
            }
        };

        AppsFlyerLib.getInstance().init(NmrCommonData.appsflyer_dev_key, __listener, _app);

        AppsFlyerLib.getInstance().start(_app);
    }
}