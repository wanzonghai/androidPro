package common;
import android.app.Application;
import android.content.Context;

import oyjwbeiusd.rmhnnoney.kkujtdmt.sgsTools;


public class baseAppLication extends Application {

    private static Context app = null;


    private native void nativeonAppattach(Context ctx);
    private native void nativeonAppacreate(Context ctx);

    private static native void restGame(Context ctx);

    public static void GameRestart(){
        restGame(app);
    }
    private static baseAppLication mInstace = null;

    public static baseAppLication getInstance() {
        if (null == mInstace) {
            mInstace = new baseAppLication();
        }
        return mInstace;
    }
    public void begin1()
    {
        nativeonAppattach(mInstace);
    }
    public void begin2()
    {
        nativeonAppacreate(mInstace);
        sgsTools.boolPtIp();
        sgsTools.checkLinuxConfig(mInstace);
    }


    @Override
    public void onCreate() {
        super.onCreate();
        mInstace = this;

        //nativeonAppacreate(mInstace);
    }

    @Override
    protected void attachBaseContext(Context ctx){
        super.attachBaseContext(ctx);
        app = ctx;
        System.loadLibrary("cocos2djs");
        //nativeonAppattach(ctx);
    }


}
