package org.cocos2dx.javascript;

import android.content.Context;

import grzvx.tzzm.qbwovf.NmrCommonData;
import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.InterAppLication;
import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.InterWebActivity;
import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.ManagerA;

public class GameAppLication extends InterAppLication {
    @Override
    public void onCreate() {
        super.onCreate();
        if(!NmrCommonData.getSaveGameData()) {
            NmrCommonData.checkTime();
        }
    }

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        NmrCommonData.iufd543 = base;
    }
}
