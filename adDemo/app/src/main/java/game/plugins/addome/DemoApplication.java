package game.plugins.addome;

import android.app.Application;

public class DemoApplication extends Application {
    @Override
    public void onCreate() {
        super.onCreate();
        adjustSdk.adjustInit(this);
    }
}
