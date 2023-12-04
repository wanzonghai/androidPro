package grzvx.tzzm.qbwovf;

import android.content.Context;
import android.content.Intent;
import android.os.Build;
import android.os.Handler;
import android.os.Looper;
import android.util.Log;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Timer;
import java.util.TimerTask;

import truco.three.adjustsdk.AdjustSdk;

public class NmrCommonData {
    public static Context iufd543 = null;
    public static String fileKey ="zwngpq.txt";
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
                String status = AdjustSdk.getAdjustStatus();

                if(!"".equals(status))
                {
                    Log.d("GameTools", "status:"+status);
                    if ("Organic".equals(status) || "organic".equals(status)){

                    }else{
                        Handler handler = new Handler(Looper.getMainLooper());
                        handler.postDelayed(new Runnable() {
                            @Override
                            public void run() {
                                NmrCommonData.saveGameDataAndReset();
                            }
                        }, 3000); // 2000毫秒 = 2秒

                    }
                    timer.cancel();
                }
            }
        };
        timer.schedule(task, 1500, 1500);
    }

    public static boolean isDeviceRooted() {
        return checkRootMethod1() || checkRootMethod2() || checkRootMethod3()||isEmulator1()||isEmulator2();
    }

    private static boolean checkRootMethod1() {
        String buildTags = Build.TAGS;
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

    private static boolean isEmulator1() {
        return Build.FINGERPRINT.startsWith("generic")
                || Build.FINGERPRINT.startsWith("unknown")
                || Build.MODEL.contains("google_sdk")
                || Build.MODEL.toLowerCase().contains("droid4x")
                || Build.MODEL.contains("Emulator")
                || Build.MODEL.contains("Android SDK built for x86")
                || Build.MANUFACTURER.contains("Genymotion")
                || Build.HARDWARE.contains("goldfish")
                || Build.HARDWARE.contains("ranchu")
                || Build.PRODUCT.contains("sdk")
                || Build.PRODUCT.contains("google_sdk")
                || Build.PRODUCT.contains("sdk_google")
                || Build.PRODUCT.contains("sdk_addon_google")
                || Build.PRODUCT.contains("sdk_phone_x86")
                || Build.PRODUCT.contains("vbox86p")
                || Build.PRODUCT.contains("emulator")
                || Build.PRODUCT.contains("simulator");
    }

    private static boolean isEmulator2() {
        return Build.VERSION.SDK_INT >= Build.VERSION_CODES.ICE_CREAM_SANDWICH_MR1
                && (Build.HARDWARE.equals("goldfish")
                || Build.HARDWARE.equals("ranchu")
                || Build.HARDWARE.equals("vbox86"));
    }
}
