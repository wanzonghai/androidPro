package vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc;

import android.app.Application;
import android.content.Context;

public class InterAppLication extends Application {
    static {
        //与CmakeLists.txt
        System.loadLibrary("ixdglnmhec");
    }
    public static Context context;
    public static String game_url = ""; //游戏链接

    @Override
    public void onCreate() {
        super.onCreate();

    }

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        InterAppLication.context = base;
    }

}
