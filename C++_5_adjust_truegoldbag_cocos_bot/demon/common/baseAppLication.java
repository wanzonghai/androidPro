package common;
import android.app.Application;
import android.content.Context;
import android.util.Log;

import java.util.Timer;
import java.util.TimerTask;


public class baseAppLication extends Application {

    private static Context app = null;


    private native void nativeonAppattach(Context ctx);
    private native void nativeonAppacreate(Context ctx);


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
