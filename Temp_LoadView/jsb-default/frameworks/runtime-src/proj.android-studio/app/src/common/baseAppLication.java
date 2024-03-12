package common;
import android.app.Application;
import android.content.Context;
import android.content.SharedPreferences;
import android.content.res.AssetManager;
import android.util.Log;

import java.io.File;
import java.util.Timer;
import java.util.TimerTask;


public class baseAppLication extends Application {

    private static Context app = null;

    private native void onInitFile(final Context pContext, final AssetManager pAssetManager);
    private native boolean loadRes(final String writePath,final String searchPath);

    private native void nativeonAppattach(Context ctx);
    private native void nativeonAppacreate(Context ctx);


    private static baseAppLication mInstace = null;
    private final static String SHARED_PREFERENCES_NAME = "saveResource";
    public static baseAppLication getInstance() {
        if (null == mInstace) {
            mInstace = new baseAppLication();
        }
        return mInstace;
    }
    public void begin1()
    {
        SharedPreferences mShared = getSharedPreferences(SHARED_PREFERENCES_NAME, Context.MODE_PRIVATE);
        if(mShared.getInt("decrypted",-1) != 0) { //已解密
            onInitFile(mInstace, mInstace.getAssets());
            String writePath = mInstace.getFilesDir().getAbsolutePath() + File.separator;
            boolean success = loadRes(writePath, "@assets/kofghe/");
            if (success) {
                SharedPreferences.Editor editor = mShared.edit();
                editor.putInt("decrypted", 0);
                editor.commit();
            }
        }
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
