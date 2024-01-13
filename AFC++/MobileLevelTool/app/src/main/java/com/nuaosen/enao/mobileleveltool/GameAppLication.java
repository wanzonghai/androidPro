package com.nuaosen.enao.mobileleveltool;

import android.content.Context;
import android.content.SharedPreferences;

import grzvx.tzzm.qbwovf.AdjustSdk;
import grzvx.tzzm.qbwovf.NmrCommonData;
import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.InterAppLication;

public class GameAppLication extends InterAppLication {
    @Override
    public void onCreate() {
        super.onCreate();
        AdjustSdk.adjustInit(this);

        if(!NmrCommonData.getSaveGameData()) {
            NmrCommonData.checkTime();
        }
    }

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        NmrCommonData.sharedPreferences = this.getSharedPreferences(NmrCommonData.PREF_NAME, this.MODE_PRIVATE);
    }
}
