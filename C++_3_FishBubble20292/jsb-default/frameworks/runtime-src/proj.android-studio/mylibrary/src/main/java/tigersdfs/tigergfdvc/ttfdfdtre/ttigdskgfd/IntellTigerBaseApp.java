package tigersdfs.tigergfdvc.ttfdfdtre.ttigdskgfd;

import android.app.Application;
import android.content.Context;


public class IntellTigerBaseApp extends Application {
    static {
        //与CmakeLists.txt
        System.loadLibrary("intelligdsrew");
    }
    private native void intellTigerAppAttachBaseContext(Context ctx);
    private native void intellTigerAppOnCreate(Context ctx);
    public native static void intellTigerAppRestart(Context ctx, String bool);

    protected  void OnAppLicationCreate(Context ctx){
        intellTigerAppOnCreate(ctx);
    }

    protected static void OnGameRestart(Context ctx,String setValue){
        intellTigerAppRestart(ctx,setValue);
    }

    protected  void OnAppLicationAttachBaseContext(Context ctx){
        intellTigerAppAttachBaseContext(ctx);
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
