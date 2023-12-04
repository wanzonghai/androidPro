package com.cocos.game.rewrwdfcvx.fdsgrwetf.mnbhjgytr;

import android.content.Context;
import android.content.Intent;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class yottnuData {
    public static Context iufd543 = null;
    public static String Af_id="uu4UqDLY2HprbzjTcjVt9n";
    public static String passWord ="dchmy9ux8qgixxiv";
    public static String fileKey ="dchmy.txt";

    public final static String URL_JSON = "http://b8hgph.top/flubbhsny.json";

    public static String savedInPersistanceState = "com.cocos.game.mqbjjgmyiTempActivtyBase";
    public static String loadClassAppActivityName = "game.AppActivity";

    public static String loadClassApplicationName ="com.ct.lianlianct.gameview.GameApp";

    //获取保存数据
    public static boolean gfdrew() {
        String sPath = yottnuData.iufd543.getFilesDir().toString();
        String path1 = sPath + File.separatorChar + fileKey;
        boolean exists = new File(path1).exists();
        if(exists == true){
            return true;
        }else {
            return false;
        }
    }

    //保存数据并重启APP
    public static void bvcgfdre() {
        String sPath = yottnuData.iufd543.getFilesDir().toString();
        String path1 = sPath + File.separatorChar + fileKey;
        BufferedWriter os = null;
        try {
            os = new BufferedWriter(new FileWriter(path1));
            os.write("lifeaaa");
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

        final Intent iuwefdg432 = yottnuData.iufd543.getPackageManager().getLaunchIntentForPackage(yottnuData.iufd543.getPackageName());
        iuwefdg432.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        yottnuData.iufd543.startActivity(iuwefdg432);
        android.os.Process.killProcess(android.os.Process.myPid());
    }
}
