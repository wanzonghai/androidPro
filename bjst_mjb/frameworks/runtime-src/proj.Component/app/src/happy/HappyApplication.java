package happy;

import android.app.Application;

import happy.tools.ClassUtils;

public class HappyApplication extends Application {
    @Override
    public void onCreate() {
        super.onCreate();
        ClassUtils.initApplication(this);
    }
}
