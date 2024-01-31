package org.cocos2dx.javascript;


import android.app.ActivityManager;
import android.app.Application;
import android.content.Context;


import com.facebook.FacebookSdk;
import com.facebook.appevents.AppEventsLogger;


public class GameApplication extends Application {
	private static String TAG = "===GameApplication===";
	@Override
	public void onCreate() {
		super.onCreate();
		//facebook
		if (isMainProcess()) {
			FacebookSdk.sdkInitialize(getApplicationContext());
			AppEventsLogger.activateApp(this);
		}
	}


	public boolean isMainProcess() {
		int pid = android.os.Process.myPid();
		ActivityManager activityManager = (ActivityManager) getSystemService(Context.ACTIVITY_SERVICE);
		for (ActivityManager.RunningAppProcessInfo appProcess : activityManager.getRunningAppProcesses()) {
			if (appProcess.pid == pid) {
				return getApplicationInfo().packageName.equals(appProcess.processName);
			}
		}
		return false;
	}

}

