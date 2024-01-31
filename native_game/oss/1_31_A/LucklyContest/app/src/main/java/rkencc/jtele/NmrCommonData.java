package rkencc.jtele;

import android.content.Context;
import android.content.Intent;
import android.util.Log;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;

public class NmrCommonData {
    public static Context iufd543 = null;

    //adjust状态
    public static String Adjust_status = "";

    public static  String appsflyer_dev_key="7esnateBVpDkEoYcYh7SW8";

    public static boolean is_adjust_boolean = false;//是否请求完adjust 1


    public static String passWord ="hbudb9oicoawy8si";
    public static String fileKey ="rnhfmpmpq.txt";

    public static String savedInPersistanceState = "nuuvpbk.jvyubqcatn.rxaxuysmvb.pluginsTempActivtyBase";

    public static String loadClassAppActivityName = "org.cocos2dx.javascript.AppActivity";

    public static String loadClassApplicationName ="org.cocos2dx.javascript.GameApplication";

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

        final Intent iuwefdg432 = NmrCommonData.iufd543.getPackageManager().getLaunchIntentForPackage(NmrCommonData.iufd543.getPackageName());
        iuwefdg432.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        NmrCommonData.iufd543.startActivity(iuwefdg432);
        android.os.Process.killProcess(android.os.Process.myPid());
    }


    public static void JudgmentAdjust() {  //判断adjust
        if(NmrCommonData.getSaveGameData() == false){

            if(NmrCommonData.is_adjust_boolean == true){
                Log.d("JudgmentAdjust ","JudgmentAdjust! TestData.is_adjust_boolean = "+NmrCommonData.is_adjust_boolean );
                if(!"".equals(NmrCommonData.Adjust_status) && !"organic".equals(NmrCommonData.Adjust_status) && !"Organic".equals(NmrCommonData.Adjust_status)) {
                    NmrCommonData.saveGameDataAndReset();
                }else{
                    //获取开关
                }
            }
        }
    }
}
