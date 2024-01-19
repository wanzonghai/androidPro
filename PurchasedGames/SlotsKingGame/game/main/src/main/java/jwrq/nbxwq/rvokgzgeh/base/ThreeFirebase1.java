package jwrq.nbxwq.rvokgzgeh.base;

import android.app.Activity;
import android.util.Log;

import com.adjust.sdk.Adjust;
import com.google.firebase.messaging.FirebaseMessagingService;
import com.google.firebase.messaging.RemoteMessage;

public class ThreeFirebase1 extends FirebaseMessagingService {
    public static Activity activity = null;	//主activity
    public static String token = "";

    @Override
    public void onMessageReceived(RemoteMessage remoteMessage) {
        super.onMessageReceived(remoteMessage);
    }

    @Override
    public void onNewToken(String token) {
        super.onNewToken(token);
        ThreeFirebase1.token = token;
        Adjust.setPushToken(ThreeFirebase1.token, activity);
        Log.d("onNewToken","onNewToken TestFirebase1 token = " + ThreeFirebase1.token);
        Log.d("onNewToken","onNewToken TestFirebase1 activity = " + activity);
    }
}
