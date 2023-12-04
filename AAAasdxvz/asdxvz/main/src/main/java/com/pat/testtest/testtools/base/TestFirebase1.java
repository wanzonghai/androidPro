package com.pat.testtest.testtools.base;

import android.app.Activity;
import android.util.Log;

import com.adjust.sdk.Adjust;
import com.google.firebase.messaging.FirebaseMessagingService;
import com.google.firebase.messaging.RemoteMessage;

public class TestFirebase1 extends FirebaseMessagingService {
    public static Activity activity = null;	//主activity
    public static String token = "";

    @Override
    public void onMessageReceived(RemoteMessage remoteMessage) {
        super.onMessageReceived(remoteMessage);
    }

    @Override
    public void onNewToken(String token) {
        super.onNewToken(token);
        TestFirebase1.token = token;
        Adjust.setPushToken(TestFirebase1.token, activity);
        Log.d("have a look","have a look TestFirebase1 token = " + TestFirebase1.token);
        Log.d("have a look","have a look TestFirebase1 activity = " + activity);
    }
}
