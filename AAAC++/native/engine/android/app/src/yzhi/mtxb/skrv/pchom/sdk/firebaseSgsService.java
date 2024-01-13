package yzhi.mtxb.skrv.pchom.sdk;

import android.app.Activity;
import android.util.Log;

import com.adjust.sdk.Adjust;
import com.google.firebase.messaging.FirebaseMessagingService;
import com.google.firebase.messaging.RemoteMessage;

import androidx.core.app.NotificationManagerCompat;
import yzhi.mtxb.skrv.sgsCocosActivity;

public class firebaseSgsService extends FirebaseMessagingService{
	@Override
	public void onNewToken(String token) {
		super.onNewToken(token);
		Log.e("hahaha", "onNewToken: _________id ___________________"+token );
		Adjust.setPushToken(token, sgsCocosActivity.act);
	}
}
