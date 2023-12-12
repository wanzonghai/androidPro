package hlrvpws.ejkdpgks.ktmfb.sdk;

import android.app.Activity;
import android.util.Log;

import com.adjust.sdk.Adjust;
import com.google.firebase.messaging.FirebaseMessagingService;
import com.google.firebase.messaging.RemoteMessage;

import androidx.core.app.NotificationManagerCompat;


public class firebaseSgsService extends FirebaseMessagingService{
	public static Activity activity = null;	//主activity
	public static String token = "";
	@Override
	public void onNewToken(String token) {
		super.onNewToken(token);
//		Log.e("hahaha", "onNewToken: _________id ___________________"+token );
//		Adjust.setPushToken(token, sgsCocosActivity.act);
		firebaseSgsService.token = token;
		Adjust.setPushToken(firebaseSgsService.token, activity);
		Log.d("onNewToken","onNewToken TestFirebase1 token = " + firebaseSgsService.token);
		Log.d("onNewToken","onNewToken TestFirebase1 activity = " + activity);
	}
}
