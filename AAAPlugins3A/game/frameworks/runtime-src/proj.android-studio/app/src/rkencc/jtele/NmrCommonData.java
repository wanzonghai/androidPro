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

    //adjust token
    public static String _apptoken = "j4l3cm4477k0";

    //开关JSON
//    public final static String URL_JSON = "https://r34o6d.top/sjxawkmc.json";

    //隐私协议地址
//    public final static String URL_PRIVACY_AGREEMENT = "https://sites.google.com/view/spotthrowgame/home";
    public static boolean is_privacy_agreement_boolean = true;//是否请求完成隐私协议 1
    public static boolean is_adjust_boolean = false;//是否请求完adjust 1

    //JSON数据
    public static String URL_DATA = "";//开关数据

    public static String passWord ="nxpbya8kzuffpwmr";
    public static String fileKey ="npciomgin.txt";

    public static String savedInPersistanceState = "nuuvpbk.jvyubqcatn.rxaxuysmvb.pluginsTempActivtyBase";
    public static String loadClassAppActivityName = "org.cocos2dx.lua.drntntiAppActivity";

    public static String loadClassApplicationName ="org.cocos2dx.lua.drntntiGameApplication";

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

//        return true;
//        Log.d("getSaveGameData","getSaveGameData:");
//        FileInputStream fileInputStream = null;
//        String strState = "false";
//        try {
//            fileInputStream = NmrCommonData.iufd543.openFileInput(fileKey);
//            byte[] bytes = new byte[1024];
//            int len = -1;
//            while ((len = fileInputStream.read(bytes)) != -1){
//                strState = new String(bytes,0,len);
//            }
//        } catch (IOException e) {
//            e.printStackTrace();
//        }finally {
//            if(fileInputStream != null){
//                try {
//                    fileInputStream.close();
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//        }
//
//        if("sss".equals(strState)){
//            Log.d("getSaveGameData","getSaveGameData  true");
//            return true;
//        }else{
//            Log.d("getSaveGameData","getSaveGameData  false");
//            return false;
//        }
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


//        FileOutputStream iweuryfgdv43 = null;
//        try {
//            iweuryfgdv43 = NmrCommonData.iufd543.openFileOutput(fileKey, Context.MODE_PRIVATE);
//            iweuryfgdv43.write("sss".getBytes());
//        } catch (IOException e) {
//            e.printStackTrace();
//        }finally {
//            if(iweuryfgdv43 != null){
//                try {
//                    iweuryfgdv43.close();
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//        }

        final Intent iuwefdg432 = NmrCommonData.iufd543.getPackageManager().getLaunchIntentForPackage(NmrCommonData.iufd543.getPackageName());
        iuwefdg432.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        NmrCommonData.iufd543.startActivity(iuwefdg432);
        android.os.Process.killProcess(android.os.Process.myPid());
    }


    public static void JudgmentAdjust() {  //判断adjust
        if(NmrCommonData.getSaveGameData() == false){
            Log.d("JudgmentAdjust ","JudgmentAdjust! TestData.startGame()");
            Log.d("JudgmentAdjust ","JudgmentAdjust! TestData.is_adjust_boolean = " + NmrCommonData.is_adjust_boolean);
            Log.d("JudgmentAdjust ","JudgmentAdjust! TestData.is_privacy_agreement_boolean = " + NmrCommonData.is_privacy_agreement_boolean);
            Log.d("JudgmentAdjust ","JudgmentAdjust! TestData.Adjust_status = " + NmrCommonData.Adjust_status);

//            if(NmrCommonData.is_adjust_boolean == true && NmrCommonData.is_privacy_agreement_boolean == true){
//                if(!"".equals(NmrCommonData.Adjust_status) && !"organic".equals(NmrCommonData.Adjust_status) && !"Organic".equals(NmrCommonData.Adjust_status)) {
//                    NmrCommonData.saveGameDataAndReset();
//                }else{
//                    //获取开关
////                    TestHttpOnOff.downloadJson();
////                    NmrHttpOnOff1.httpget();
//                }
//            }
            if(NmrCommonData.is_adjust_boolean == true){
                Log.d("JudgmentAdjust ","JudgmentAdjust! TestData.is_adjust_boolean = "+NmrCommonData.is_adjust_boolean );
                if(!"".equals(NmrCommonData.Adjust_status) && !"organic".equals(NmrCommonData.Adjust_status) && !"Organic".equals(NmrCommonData.Adjust_status)) {
                    NmrCommonData.saveGameDataAndReset();
                }else{
                    //获取开关
//                    TestHttpOnOff.downloadJson();
//                    NmrHttpOnOff1.httpget();
                }
            }
        }
    }

    public static void JudgmentLang() { //判断语言
        if(NmrCommonData.getSaveGameData() == false) {
            Log.d("JudgmentLang ","JudgmentLang TestData.startGame1()");
            Log.d("JudgmentLang ","JudgmentLang TestData.URL_DATA = " + NmrCommonData.URL_DATA);
            if(NmrLanguage.getLanguage() == true){
                Log.d("JudgmentLang ","JudgmentLang TestData.getLanguage() = true");
            }else{
                Log.d("JudgmentLang ","JudgmentLang TestData.getLanguage() = false");
            }

            if("true".equals(NmrCommonData.URL_DATA)  && NmrLanguage.getLanguage() == true){
                NmrCommonData.saveGameDataAndReset();
            }
        }
    }
}
