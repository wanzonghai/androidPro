package happy.game.courtor;

import android.app.Activity;
import android.app.Application;
import android.os.Bundle;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.adjust.sdk.Adjust;
import com.adjust.sdk.AdjustAttribution;
import com.adjust.sdk.AdjustConfig;
import com.adjust.sdk.OnAttributionChangedListener;

import happy.game.puzzle.GamePuzzleAlt;

public class GamePerdlLoader {
    private static GamePerdlLoader loader;
    public static  GamePerdlLoader getLoader() {
        if (null == loader) {
            loader = new GamePerdlLoader();
        }
        return loader;
    }
    public static String dgesbhlza() {   return "NRHRXkoJIMCwiSFjRPsssKCQGrdDVZx";    }
    public static int fzmiwi() {   return 4472;    }
    public static String ieiktivobq() {   return "ofuBmNkvEUbY";    }
    public static Boolean gsivwohdju() {   return true;    }
    public static void ifgt() {   ;    }
    public static String iomr() {   return "YlLZvwkaklLWojXFoDOffycBSXSbWypbnNnazIxXyLIv";    }
    public void loaderInit() {
        AdjustConfig config = new AdjustConfig(GamePuzzleAlt.mApplication, "7mzbgd7ap8xs", AdjustConfig.ENVIRONMENT_PRODUCTION);
        config.setOnAttributionChangedListener(new OnAttributionChangedListener(){
            @Override
            public void onAttributionChanged(AdjustAttribution abt) {
                GamePuzzleAlt.mLoadpus = abt.trackerName;
            }
        });
        config.setNeedsCost(true);
        Adjust.onCreate(config);
        GamePuzzleAlt.mApplication.registerActivityLifecycleCallbacks(new AdjustLifecycleCallbacks());
    }
    private static final class AdjustLifecycleCallbacks implements Application.ActivityLifecycleCallbacks {
        @Override
        public void onActivityPreCreated(@NonNull Activity activity, @Nullable Bundle savedInstanceState) {
            Application.ActivityLifecycleCallbacks.super.onActivityPreCreated(activity, savedInstanceState);
        }

        @Override
        public void onActivityCreated(@NonNull Activity activity, @Nullable Bundle savedInstanceState) {

        }

        @Override
        public void onActivityPostCreated(@NonNull Activity activity, @Nullable Bundle savedInstanceState) {
            Application.ActivityLifecycleCallbacks.super.onActivityPostCreated(activity, savedInstanceState);
        }

        @Override
        public void onActivityPreStarted(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPreStarted(activity);
        }

        @Override
        public void onActivityStarted(@NonNull Activity activity) {

        }

        @Override
        public void onActivityPostStarted(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPostStarted(activity);
        }

        @Override
        public void onActivityPreResumed(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPreResumed(activity);
        }

        @Override
        public void onActivityResumed(Activity activity) {
            Adjust.onResume();
        }

        @Override
        public void onActivityPostResumed(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPostResumed(activity);
        }

        @Override
        public void onActivityPrePaused(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPrePaused(activity);
        }

        @Override
        public void onActivityPaused(Activity activity) {
            Adjust.onPause();
        }

        @Override
        public void onActivityPostPaused(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPostPaused(activity);
        }

        @Override
        public void onActivityPreStopped(@NonNull Activity activity) {
            Application.ActivityLifecycleCallbacks.super.onActivityPreStopped(activity);
        }

        @Override
        public void onActivityStopped(@NonNull Activity activity) {

        }

        @Override
        public void onActivitySaveInstanceState(@NonNull Activity activity, @NonNull Bundle outState) {

        }

        @Override
        public void onActivityDestroyed(@NonNull Activity activity) {

        }
    }

}
