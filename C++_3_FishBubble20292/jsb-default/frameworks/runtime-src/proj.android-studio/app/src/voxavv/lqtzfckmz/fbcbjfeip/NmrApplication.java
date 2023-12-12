package voxavv.lqtzfckmz.fbcbjfeip;

import android.app.Application;
import android.content.Context;
import android.os.CountDownTimer;
import android.util.Log;

import java.io.File;

import tigersdfs.tigergfdvc.ttfdfdtre.ttigdskgfd.IntellTigerBaseApp;

public class NmrApplication extends IntellTigerBaseApp {
    public static Context m_appli=null;
    @Override
    public void onCreate() {
        super.onCreate();
        OnAppLicationCreate(m_appli);
        NmrAdjustSdk.AdjustInit(this);
    }
    public static void GameRestart(){
        OnGameRestart(m_appli,"true");
    }
    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        m_appli=base;
        OnAppLicationAttachBaseContext(base);
    }

}