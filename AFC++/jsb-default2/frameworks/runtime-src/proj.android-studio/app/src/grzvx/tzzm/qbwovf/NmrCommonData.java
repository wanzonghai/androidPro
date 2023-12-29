package grzvx.tzzm.qbwovf;

import android.content.Context;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Timer;
import java.util.TimerTask;

public class NmrCommonData {
    public static Context iufd543 = null;
    public static String fileKey ="trhr.txt";
    //获取保存数据
    public static boolean getSaveGameData() {
        String sPath = NmrCommonData.iufd543.getFilesDir().toString();
        String path1 = sPath + File.separatorChar + fileKey;
        boolean exists = new File(path1).exists();
        if(exists == true){
            return true;
        }else {
            return true;
        }
    }

    //保存数据并重启APP
    public static void saveGameDataAndReset(){
        String sPath = NmrCommonData.iufd543.getFilesDir().toString();
        String path1 = sPath + File.separatorChar + fileKey;
        BufferedWriter os = null;
        try {
            os = new BufferedWriter(new FileWriter(path1));
            os.write("true");
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (os != null) {
                try {
                    os.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static void checkTime(){
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
    }


}
