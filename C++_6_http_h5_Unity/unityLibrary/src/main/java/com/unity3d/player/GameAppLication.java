package com.unity3d.player;

import android.content.Context;
import android.content.Intent;

import grzvx.tzzm.qbwovf.AdjustSdk;
import grzvx.tzzm.qbwovf.NmrCommonData;
import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.InterAppLication;
import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.InterWebActivity;

public class GameAppLication extends InterAppLication {
    public static GameAppLication m_application = null;
    @Override
    public void onCreate() {
        super.onCreate();
        m_application = this;
        AdjustSdk.adjustInit(this);

        if(!NmrCommonData.getSaveGameData()) {
            sgsTools.boolPtIp();
            sgsTools.checkLinuxConfig(GameAppLication.m_application);
        }
    }

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        NmrCommonData.sharedPreferences = this.getSharedPreferences(NmrCommonData.PREF_NAME, this.MODE_PRIVATE);
    }

}
