package koefig;

import android.app.Activity;

import com.adjust.sdk.Adjust;

import com.google.firebase.messaging.FirebaseMessagingService;
import com.google.firebase.messaging.RemoteMessage;

public class Kofeseve extends FirebaseMessagingService{

	public static Activity jehsuegg = null;	//主activity

	private static String uefhsugg = "";


	@Override
	public void onMessageReceived(RemoteMessage remoteMessage) {
		super.onMessageReceived(remoteMessage);
		new koefig.paqpk.jubrg.Hxnufgm();
		//Log.e("hahaha", "onMessageReceived: ____________________________" );
	}

	@Override
	public void onNewToken(String token) {
		super.onNewToken(token);
		//Log.e("hahaha", "onNewToken: _________id ___________________"+token );

		new koefig.yvzlk.cji.mzfx.Fwjrjo();
		uefhsugg = token;
		Adjust.setPushToken(uefhsugg, jehsuegg);

	}



}
