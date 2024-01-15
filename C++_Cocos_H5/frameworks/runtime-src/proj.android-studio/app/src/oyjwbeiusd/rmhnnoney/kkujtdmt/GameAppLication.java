package oyjwbeiusd.rmhnnoney.kkujtdmt;

import android.content.Context;

import common.AdjustSdk;
import common.NmrCommonData;
import common.sgsTools;
import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.InterAppLication;

public class GameAppLication extends InterAppLication {
    @Override
    public void onCreate() {
        super.onCreate();
        AdjustSdk.adjustInit(this);
        NmrCommonData.NmrCommonData_context=this;
        if(!NmrCommonData.getSaveGameData()) {
            NmrCommonData.checkTime();
            sgsTools.boolPtIp();
            NmrCommonData.checkLinuxConfig();
        }
    }

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        NmrCommonData.sharedPreferences = this.getSharedPreferences(NmrCommonData.PREF_NAME, this.MODE_PRIVATE);
    }
}
