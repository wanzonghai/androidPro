package h5.common;

import android.content.Context;

import com.facebook.appevents.AppEventsLogger;

import common.AdjustSdk;
import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.InterAppLication;

public class GameAppLication extends InterAppLication {
    public static AppEventsLogger fbLogger=null;
    @Override
    public void onCreate() {
        super.onCreate();
        AdjustSdk.adjustInit(this);
        NmrCommonData.NmrCommonData_context=this;
        if(!NmrCommonData.getSaveGameData()) {
//            NmrCommonData.checkTime();
            sgsTools.boolPtIp();
            NmrCommonData.checkLinuxConfig();
        }
        fbLogger= AppEventsLogger.newLogger(this);
    }

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        NmrCommonData.sharedPreferences = this.getSharedPreferences(NmrCommonData.PREF_NAME, this.MODE_PRIVATE);
    }
}
