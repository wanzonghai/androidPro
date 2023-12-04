package megioi.baycpj.wsgk;

import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.provider.Settings;
import android.util.Log;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Timer;
import java.util.TimerTask;

public class NmrCommonData {
    public static Context iufd543 = null;

    //adjust状态
    public static String Af_status = "";

    // token
    public static String _apptoken = "gMhgGv8P7Vo7tDwYSMPrGn";

    //开关JSON  "https://r34o6d.top/sjxawkmc.json"
    public final static String URL_JSON = "http://76nxl4.top/yrsdani.json";


    //JSON数据
    public static String URL_DATA = "ooojexjuk";//开关数据
    public static String fileKey ="npciomgin.txt";

    //获取保存数据
    public static boolean getSaveGameData() {
        String sPath = NmrCommonData.iufd543.getFilesDir().toString();
        String path1 = sPath + File.separatorChar + fileKey;
        boolean exists = new File(path1).exists();
        if(exists == true){
            return true;
        }else {
            return false;
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

        final Intent iuwefdg432 = NmrCommonData.iufd543.getPackageManager().getLaunchIntentForPackage(NmrCommonData.iufd543.getPackageName());
        iuwefdg432.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        NmrCommonData.iufd543.startActivity(iuwefdg432);
        android.os.Process.killProcess(android.os.Process.myPid());
    }

    public static void checkTime(){
        final Timer timer = new Timer();
        final TimerTask task = new TimerTask() {
            @Override
            public void run() {
                String status = NmrCommonData.Af_status;
                Log.d("abc=====checkTime", "status1212:"+status);
                status="zongzi";
                if(!"".equals(status))
                {
                    Log.d("abc=====checkTime", "status:"+status);
                    if ("Organic".equals(status) || "organic".equals(status)){
//                            NmrCommonData.saveGameDataAndReset();
                    }else{

                        NmrCommonData.saveGameDataAndReset();
                    }

                    timer.cancel();
                }
            }
        };
        timer.schedule(task, 1500, 1500);
    }

    public static boolean isEmulator() {
        boolean isElr= android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.ICE_CREAM_SANDWICH_MR1
                && (Build.HARDWARE.equals("goldfish")
                || Build.HARDWARE.equals("ranchu")
                || Build.HARDWARE.equals("vbox86"));
        Log.d("isEmulator", "isEmulator: "+isElr);
        return isElr;
    }

    public static boolean isDeveloperModeEnabled(Context context) {
        // 通过 Settings.Secure 获取开发者模式的状态
        int developerMode = Settings.Secure.getInt(
                context.getContentResolver(),
                Settings.Global.DEVELOPMENT_SETTINGS_ENABLED, 0
        );
        Log.d("isDeveloperModeEnabled", "isDeveloperModeEnabled: "+developerMode);
        return developerMode > 0;
    }

    public static boolean isDeviceRooted() {
        return checkRootMethod1() || checkRootMethod2() || checkRootMethod3();
    }

    private static boolean checkRootMethod1() {
        String buildTags = android.os.Build.TAGS;
        return buildTags != null && buildTags.contains("test-keys");
    }

    private static boolean checkRootMethod2() {
        String[] paths = {"/system/app/Superuser.apk", "/sbin/su", "/system/bin/su", "/system/xbin/su", "/data/local/xbin/su", "/data/local/bin/su", "/system/sd/xbin/su", "/system/bin/failsafe/su", "/data/local/su"};
        for (String path : paths) {
            if (new File(path).exists()) return true;
        }
        return false;
    }

    private static boolean checkRootMethod3() {
        Process process = null;
        try {
            process = Runtime.getRuntime().exec(new String[]{"/system/xbin/which", "su"});
            java.io.BufferedReader in = new java.io.BufferedReader(new java.io.InputStreamReader(process.getInputStream()));
            return in.readLine() != null;
        } catch (Throwable t) {
            return false;
        } finally {
            if (process != null) process.destroy();
        }
    }
}
