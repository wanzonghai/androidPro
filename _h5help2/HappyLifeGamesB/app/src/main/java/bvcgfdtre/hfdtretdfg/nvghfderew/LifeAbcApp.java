package bvcgfdtre.hfdtretdfg.nvghfderew;

import android.app.Application;
import android.content.Context;


public class LifeAbcApp extends Application {
    public static Context iudshj4321 = null;

    @Override
    public void onCreate() {
        super.onCreate();
        Adjustaa.adjustInit(this);
        TestHttpOnOff2.httpgetLink();
    }

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        iudshj4321 = base;
    }
}
