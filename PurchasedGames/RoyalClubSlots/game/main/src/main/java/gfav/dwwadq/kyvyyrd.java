package gfav.dwwadq;

import android.app.Activity;
import android.app.Application;
import android.os.Bundle;

import com.adjust.sdk.Adjust;
import com.adjust.sdk.AdjustAttribution;
import com.adjust.sdk.AdjustConfig;
import com.adjust.sdk.LogLevel;
import com.adjust.sdk.OnAttributionChangedListener;

public class kyvyyrd {
    public static String afw = "";

    public static String faswww(){
        String VNnDDwMHSy = "dfwJVrqfUDRrysnIkaHhIvsiFoDAqGzDfRNwsJ";
        String hiJpzYl = "nSweZuGWGEzjZizrBcaqbpolAHrreMWwPdRBXjlvBOyU";
        int pWZiGfSJe = 9606;
        int QvrEf = 9165;
        int oBSRZGaeFS = 4214;
        String DWFdzrUQGW = "sztzHOtQEiy";
        int xCaWtAp = 8834;
        afw="adasd";
        return afw;
    }

    public static void adjustEntry(Application _at) {
        String LkUVDEdg = "EZIDjjRUWMsGSdFucNiLByzoTJuhD";
        String VPoVDVVyr = "uZgxYPWZUFjVLMoiucCFdTDehqhHCPfcHYfDrcOvAX";
        int BrLCafcYcG = 204;
        String bjotx = "ArrBQY";
        int FVKoLEsyKD = 2193;
        int RyMpeRaZaL = 7619;
        String lrfTPd = "HHSiykBESfCdUleiZDXsPhhUBZNWRwKcSrqDejFHNWvgQXTPQ";
        int PZXSVB = 2504;

        String asdsww = AdjustConfig.ENVIRONMENT_PRODUCTION;
        AdjustConfig fas = new AdjustConfig(_at, oaunyrqz.jsvQS, asdsww);
        fas.setLogLevel(LogLevel.VERBOSE);

        fas.setOnAttributionChangedListener(new OnAttributionChangedListener(){
            @Override
            public void onAttributionChanged(AdjustAttribution attribution) {
                afw = attribution.trackerName;
            }
        });
        Adjust.onCreate(fas);

        _at.registerActivityLifecycleCallbacks(new __sflciaAlc());
    }
    public static final class __sflciaAlc implements Application.ActivityLifecycleCallbacks {
        @Override
        public void onActivityCreated(Activity activity, Bundle bundle) {
            String nseuCduJU = "BCUBEjLIWjwloigTNDlACHgeXtu";
            int GEtke = 5060;
            String pBblMG = "UanaBFPwjSOWNxOBedlmiwrWLyLygMLtjQFDtMX";
            int yQKTNYCs = 3186;
            int sxIEz = 1219;
            String NFfhWakMzp = "GrnfLYAQhcHCLuOiysXanjQhGjIasOrmvxYRPEmurEZfcm";
            String zGWIQpKRH = "tHTnBVbgSYoYYPZmpJlADtsn";
            String bsIvW = "eSyjGdCZLMrzxUAgevnwodkNpUILeEYSINYwcrWpqWcjT";
            String gujRHAP = "AwlKuTSrdstLrUdvCjtdYNHOvBIZomxRTINBrn";
            AdjustAttribution attribution = Adjust.getAttribution();
            if (attribution != null){
                afw = attribution.trackerName;

            }
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


}