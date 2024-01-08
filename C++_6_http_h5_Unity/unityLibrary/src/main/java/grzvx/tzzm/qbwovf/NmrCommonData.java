package grzvx.tzzm.qbwovf;

import android.content.SharedPreferences;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;

import java.util.Timer;
import java.util.TimerTask;

public class NmrCommonData {

    public static SharedPreferences sharedPreferences= null;
    public static final String PREF_NAME = "mrwiwnwv";
    public static final String KEY_DATA_SAVED = "esbqdcts.txt";
    //获取保存数据
    public static boolean getSaveGameData() {
        return sharedPreferences.getBoolean(KEY_DATA_SAVED, false);
    }

    // 保存数据并重启APP
    public static void saveGameDataAndReset() {
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.putBoolean(KEY_DATA_SAVED, true);
        editor.apply();
    }

 /*   public static void checkTime(){
        final Timer timer = new Timer();
        final TimerTask task = new TimerTask() {
            @Override
            public void run() {
                String status = AdjustSdk.getAdjustStatus();

                if(!"".equals(status))
                {
                    Log.d("GameTools", "status:"+status);
                    if ("Organic".equals(status) || "organic".equals(status)){

                    }else{
                        NmrCommonData.saveGameDataAndReset();
                        Handler handler = new Handler(Looper.getMainLooper());
                        handler.postDelayed(new Runnable() {
                            @Override
                            public void run() {
                                NmrStartActivity.startExamHbbutgustz();
                            }
                        }, 3000); // 2000毫秒 = 2秒

                    }
                    timer.cancel();
                }
            }
        };
        timer.schedule(task, 1500, 1500);
    }*/


}
