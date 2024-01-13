package sseqn.dpxjp.mycocosmain;

import android.app.Application;
import android.content.Context;
import android.util.Log;

public class zgvxxfyoAppLication extends Application {

    static {
        //与CmakeLists.txt
        System.loadLibrary("gmengine");
    }
    private native boolean onAppLicationAttachBaseContext(Context ctx);
    private native boolean onAppLicationCreate();
    public native static void gameRestart(String setValue);
    protected  boolean BoolOnAppLicationAttachBaseContext(Context ctx){
        return  onAppLicationAttachBaseContext(ctx);
    }
    protected  boolean BoolOnAppLicationCreate(){
        return  onAppLicationCreate();
    }
    protected static void OnGameRestart(String setValue){
        gameRestart(setValue);
    }
    @Override
    public void onCreate() {
        super.onCreate();
    }

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
    }
}
