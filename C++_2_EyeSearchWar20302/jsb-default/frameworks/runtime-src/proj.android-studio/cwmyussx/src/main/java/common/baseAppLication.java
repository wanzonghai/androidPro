package common;
import android.app.Application;
import android.content.Context;

public class baseAppLication extends Application {
    static {
        //与CmakeLists.txt
        System.loadLibrary("gmengine");
    }
    @Override
    public native void onCreate();

    @Override
    protected native void attachBaseContext(Context base);
}
