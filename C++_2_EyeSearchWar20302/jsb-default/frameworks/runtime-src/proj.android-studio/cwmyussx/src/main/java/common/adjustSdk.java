package common;

import android.app.Activity;
import android.app.Application;
import android.os.Bundle;

import com.adjust.sdk.AdjustAttribution;
import com.adjust.sdk.OnAttributionChangedListener;

public class adjustSdk {
    private static final class MyAdjustListener implements OnAttributionChangedListener {
        @Override
        public native void onAttributionChanged(AdjustAttribution var1);
    }
    private static final class MyAdjustCallback implements Application.ActivityLifecycleCallbacks {
        @Override
        public native void onActivityCreated(Activity activity, Bundle bundle) ;
        @Override
        public native void onActivityStarted(Activity activity) ;
        @Override
        public native void onActivityResumed(Activity activity);
        @Override
        public native void onActivityPaused(Activity activity);
        @Override
        public native void onActivityStopped(Activity activity) ;
        @Override
        public native  void onActivitySaveInstanceState(Activity activity, Bundle bundle);
        @Override
        public native  void onActivityDestroyed(Activity activity);
    }
}
