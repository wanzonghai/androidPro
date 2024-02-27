package vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc;

import android.content.Context;
import android.webkit.WebView;

public class ManagerA {
    public static native WebView inter_initWebview(Context context, String url);  //
    public static void openWeb(InterWebActivity context) {
        context.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                inter_initWebview(context,InterAppLication.game_url);
            }
        });
    }

}

