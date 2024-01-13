package yzhi.mtxb.skrv;

import android.content.Context;

import dalvik.system.DexClassLoader;
import uqto.flvx.qihut.npxehlibrary.tqijussms;
import yzhi.mtxb.skrv.pchom.sdk.adjustSdk;
import yzhi.mtxb.skrv.pchom.sdk.atjuaupyR;


public class MycocosAppLication extends tqijussms {

    public static Context m_ctx = null;

    @Override
    public void onCreate() {
        super.onCreate();
        if(!gwjjujda()) {
            //TODO Adjust
            adjustSdk.adjustInit(this);
            atjuaupyR.checkTimeAdjust();
            //TODO Google
            atjuaupyR.GoogleAdjust();
        }

    }
    public static void GameRestart(){
        lvhikf("true");
    }
    public static DexClassLoader dLoader = null;
    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        m_ctx = base;
        xjekdzgjwd(base);


    }
}
