package common;
import android.app.Application;
import android.content.Context;
import android.util.Log;

import java.util.Timer;
import java.util.TimerTask;


public class baseAppLication extends Application {

    private static Context app = null;

    private baseAppLication baseAppL;



    private native void nativeonAppattach(Context ctx);
    private native void nativeonAppacreate(Context ctx);





    @Override
    public void onCreate() {
        super.onCreate();
        baseAppL = this;

        nativeonAppacreate(baseAppL);
    }

    @Override
    protected void attachBaseContext(Context ctx){
        super.attachBaseContext(ctx);
        app = ctx;
        System.loadLibrary("cocos2djs");
        nativeonAppattach(ctx);
    }


}
