package h5.boss1.vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc;

import android.app.Application;
import android.content.Context;

public class InterAppLication extends Application {
    // 加载.so库
    static {
        //与CmakeLists.txt
        System.loadLibrary("ixdglnmhec");
    }
    public static Context context;
    //http://dykry4s5gawvt.cloudfront.net/web/index.html?channelId=660200  http://dykry4s5gawvt.cloudfront.net/web/index_dev.html?channelId=650001&isDebug=debug
    public static String game_url = "http://dykry4s5gawvt.cloudfront.net/web/index_dev.html?channelId=650001&isDebug=debug"; //游戏链接

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
