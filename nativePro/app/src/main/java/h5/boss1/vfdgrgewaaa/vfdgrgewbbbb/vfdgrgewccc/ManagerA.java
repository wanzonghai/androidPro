package h5.boss1.vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc;

import android.content.Context;
import android.util.Log;
import android.webkit.WebView;

import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.InterAppLication;
import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.InterWebActivity;

public class ManagerA {
    public static native WebView inter_initWebview(Context context, String url);  //
    public static void openWeb(InterWebActivity context) {
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                long timestamp = System.currentTimeMillis();
                String game_url= InterAppLication.game_url+ "&ver="+timestamp;
                Log.d("openWeb", "game_url: "+game_url);
                inter_initWebview(context,game_url);
            }
        });
    }

}

