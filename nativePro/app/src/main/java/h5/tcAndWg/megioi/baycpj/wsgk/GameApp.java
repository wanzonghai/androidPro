package h5.tcAndWg.megioi.baycpj.wsgk;

import android.app.Application;
import android.content.ContentResolver;
import android.content.Context;
import android.provider.Settings;
import android.util.Log;

public class GameApp extends Application {

    @Override
    public void onCreate() {
        super.onCreate();
//        if(isUsbDebuggingEnabled(this))return;
        GameAf.slotInit(this);
    }
    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        NmrCommonData.iufd543 = base;
    }

    public static boolean isUsbDebuggingEnabled(Context context) {
        ContentResolver contentResolver = context.getContentResolver();
        boolean usbDebuggingEnabled = Settings.Secure.getInt(contentResolver, Settings.Secure.ADB_ENABLED, 0) > 0;
        Log.d("isUsbDebuggingEnabled", "USB Debug enable ?: "+usbDebuggingEnabled);
        return usbDebuggingEnabled;
    }


    public static boolean isDeveloperModeEnabled(Context context) {
        // 通过 Settings.Secure 获取开发者模式的状态
        int developerMode = Settings.Secure.getInt(
                context.getContentResolver(),
                Settings.Global.DEVELOPMENT_SETTINGS_ENABLED, 0
        );
        Log.d("isDeveloperModeEnabled", "isDeveloperModeEnabled: "+developerMode);
        return developerMode > 0;
    }

}
