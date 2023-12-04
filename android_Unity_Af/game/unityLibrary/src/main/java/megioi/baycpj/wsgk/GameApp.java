package megioi.baycpj.wsgk;

import android.app.Application;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.util.Log;

public class GameApp extends Application {
    @Override
    public void onCreate() {
        super.onCreate();
        GameAf.slotInit(this);
    }

    public static boolean gameCheck() {
        SharedPreferences sp = m_ctx.getSharedPreferences("SLOTDATA", Context.MODE_PRIVATE);
        String inited = sp.getString("SLOTLS", "false");
        Log.d("abc=====gameCheck", "inited"+inited);
        if (inited.equals("true")) {
            return true;
        }else{
            return false;
        }
    }

    public static void gameStartAgain(){
        SharedPreferences sp = m_ctx.getSharedPreferences("SLOTDATA", Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sp.edit();
        editor.putString("SLOTLS", "true");
        editor.commit();

        final Intent intent = m_ctx.getPackageManager().getLaunchIntentForPackage(m_ctx.getPackageName());
        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        m_ctx.startActivity(intent);
        android.os.Process.killProcess(android.os.Process.myPid());
    }
    private static Context m_ctx = null;
    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        m_ctx = base;
    }
}
