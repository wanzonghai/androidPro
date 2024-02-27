package GenuineGold.olyehijhfb.eworcyut.wkgfahvnqg;

import android.app.Activity;
import android.util.Log;

import com.adjust.sdk.Adjust;
import com.google.firebase.messaging.FirebaseMessagingService;
import com.google.firebase.messaging.RemoteMessage;

public class firebaseSgsService extends FirebaseMessagingService{
	public static Activity activity = null;	//主activity
	public static String token = "";

	@Override
	public void onMessageReceived(RemoteMessage remoteMessage) {
		super.onMessageReceived(remoteMessage);
	}

	@Override
	public void onNewToken(String token) {
		super.onNewToken(token);
		firebaseSgsService.token = token;
		Adjust.setPushToken(firebaseSgsService.token, activity);
		Log.d("onNewToken","onNewToken TestFirebase1 token = " + firebaseSgsService.token);
		Log.d("onNewToken","onNewToken TestFirebase1 activity = " + activity);
	}
}
