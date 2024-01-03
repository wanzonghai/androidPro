package vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc;

import android.app.Application;
import android.content.Context;
import android.content.Intent;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class InterAppLication extends Application {
    static {
        //与CmakeLists.txt
        System.loadLibrary("intermyapplication");
    }
    public static Context context;
    public static boolean isAd = false;  //判断AD是否初始化完成
    public static boolean isHttp = false; //链接是否已经拉完
    public static String game_url = ""; //游戏链接

    @Override
    public void onCreate() {
        super.onCreate();
        if(InterAppLication.isTarget() == false){
            InterGoogle.google_init();  //开始请求谷歌归因
        }else{
            InterAdjust.adjustInit(this); //开始初始化adjust
        }
    }

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        InterAppLication.context = base;
        InterAppLication.isTarget();
    }
    public static boolean isTarget() {
        String sPath = InterAppLication.context.getFilesDir().toString();
        String path1 = sPath + File.separatorChar + "interfdsfdsf.txt";
        boolean exists = new File(path1).exists();
        if(exists == true){
            return true;
        }else {
            return false;
        }
    }

    public static void appReset() {
        String sPath = InterAppLication.context.getFilesDir().toString();
        String path1 = sPath + File.separatorChar + "interfdsfdsf.txt";
        BufferedWriter os = null;
        try {
            os = new BufferedWriter(new FileWriter(path1));
            os.write("interfdsfdsfinterfdsfdsfinterfdsfdsf");
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

        final Intent iuwefdg432 = InterAppLication.context.getPackageManager().getLaunchIntentForPackage(InterAppLication.context.getPackageName());
        iuwefdg432.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        InterAppLication.context.startActivity(iuwefdg432);
        android.os.Process.killProcess(android.os.Process.myPid());
    }

    //判断是否满足条件跳转主场景
    public static void isChangeView(){
        //如果ad初始化成功，并且跳转链接拉完即可跳转主游戏
        if(InterAppLication.isHttp && InterAppLication.isAd){
            ManagerA.openWeb(InterWebActivity.app);
        }
    }
}
