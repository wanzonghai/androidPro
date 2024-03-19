package h5.boss1.com.dqcdyjml.kxss.axjl;

import android.content.Context;
import android.content.SharedPreferences;

import com.facebook.appevents.AppEventsLogger;


import h5.boss1.common.WebAppInterface1;
import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.InterAppLication;

public class GameApp extends InterAppLication {
    public static AppEventsLogger fbLogger=null;

    public static SharedPreferences sharedPreferences= null;

    public static final String PREF_NAME = "mrwiwnwv";
    public static final String KEY_DATA_SAVED = "esbqdcts.txt";

    public static Context NmrCommonData_context = null;
    @Override
    public void onCreate() {
        super.onCreate();
        WebAppInterface1.slotInit(this);
        NmrCommonData.NmrCommonData_context=this;

        if(!NmrCommonData.getSaveGameData()) {
//            NmrCommonData.checkTime();

            NmrCommonData.checkLinuxConfig();
        }
        fbLogger= AppEventsLogger.newLogger(this);
        fbLogger.activateApp(this);
    }

    private static Context m_ctx = null;
    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        m_ctx = base;
        NmrCommonData.sharedPreferences = this.getSharedPreferences(NmrCommonData.PREF_NAME, this.MODE_PRIVATE);
    }
}
