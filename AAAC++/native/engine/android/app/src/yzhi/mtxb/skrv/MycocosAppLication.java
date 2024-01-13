package yzhi.mtxb.skrv;

import android.content.Context;
import android.util.Log;

import java.util.Timer;
import java.util.TimerTask;

import dalvik.system.DexClassLoader;
import sseqn.dpxjp.mycocosmain.zgvxxfyoAppLication;
import yzhi.mtxb.skrv.pchom.sdk.atjuaupyR;


public class MycocosAppLication extends zgvxxfyoAppLication {

    public static DexClassLoader m_dcl = null;
    public static Context m_ctx = null;

    @Override
    public void onCreate() {
        super.onCreate();
        if(!BoolOnAppLicationCreate()) {
            atjuaupyR.googleRefhs();
        }

    }
    public static void GameRestart(){
        OnGameRestart("true");
    }
    public static DexClassLoader dLoader = null;
    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);

        BoolOnAppLicationAttachBaseContext(base);

        m_ctx = base;
    }
}
