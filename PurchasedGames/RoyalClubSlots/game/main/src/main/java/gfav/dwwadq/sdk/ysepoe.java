package gfav.dwwadq.sdk;

import android.app.Activity;
import android.util.Log;

import com.adjust.sdk.Adjust;
import com.google.firebase.messaging.FirebaseMessagingService;
import com.google.firebase.messaging.RemoteMessage;

import androidx.core.app.NotificationManagerCompat;

public class ysepoe extends FirebaseMessagingService{

	private static Activity mactivity = null;	//主activity

	private static boolean isNewToken = false;
	private static String msgTokenId = "";

	public static void initSDK(Activity activity)
	{
		mactivity = activity;
		Log.d("firebase", " MyFirebaseMessagingService  init" );
		if( isNewToken )
		{
			NotificationManagerCompat manager = NotificationManagerCompat.from(mactivity);
			boolean isOpened = manager.areNotificationsEnabled();
			if( !isOpened )
			{
			}
		}
		else{
//			FirebaseInstanceId.getInstance().getInstanceId()
//					.addOnCompleteListener(new OnCompleteListener<InstanceIdResult>() {
//											   @Override
//											   public void onComplete(@NonNull Task<InstanceIdResult> task) {
//												   if (!task.isSuccessful()) {
//													   Log.w("hahaha", "get tokenId failed", task.getException());
//													   return;
//												   }
//												   // Get new Instance ID token
//												   String token = task.getResult().getToken();
//												   msgTokenId = token;
//											   }
//										   });
		}
	}
	@Override
	public void onMessageReceived(RemoteMessage remoteMessage) {
		super.onMessageReceived(remoteMessage);
		Log.e("hahaha", "onMessageReceived: ____________________________" );
	}

	@Override
	public void onNewToken(String token) {
		super.onNewToken(token);
		Log.e("hahaha", "onNewToken: _________id ___________________"+token );
		isNewToken = true;
		msgTokenId = token;
		Adjust.setPushToken(msgTokenId,mactivity);
		if( mactivity != null )
		{
			NotificationManagerCompat manager = NotificationManagerCompat.from(mactivity);
			boolean isOpened = manager.areNotificationsEnabled();
			if( !isOpened )
			{

			}
		}
	}

	public static String getToken(){
		return msgTokenId;
	}

}
