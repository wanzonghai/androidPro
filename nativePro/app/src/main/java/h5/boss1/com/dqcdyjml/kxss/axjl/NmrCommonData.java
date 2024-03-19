package h5.boss1.com.dqcdyjml.kxss.axjl;

import android.content.Context;
import android.content.SharedPreferences;

import java.util.Timer;
import java.util.TimerTask;


import h5.boss1.common.WebAppInterface1;


public class NmrCommonData {

    public static SharedPreferences sharedPreferences= null;
    public static final String PREF_NAME = "mrwiwnwv";
    public static final String KEY_DATA_SAVED = "esbqdcts.txt";

    public static Context NmrCommonData_context = null;

    //获取保存数据
    public static boolean getSaveGameData() {
//        return true;
        return sharedPreferences.getBoolean(KEY_DATA_SAVED, false);
    }

    // 保存数据并重启APP
    public static void saveGameDataAndReset() {
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.putBoolean(KEY_DATA_SAVED, true);
        editor.apply();
    }

//    public static void checkTime(){
//        final Timer timer = new Timer();
//        final TimerTask task = new TimerTask() {
//            @Override
//            public void run() {
//                String status = AdjustSdk.getAdjustStatus();
//
//                if(!"".equals(status))
//                {
//                    Log.d("GameTools", "status:"+status);
//                    if ("Organic".equals(status) || "organic".equals(status)){
//
//                    }else{
//                        NmrCommonData.saveGameDataAndReset();
//                        Handler handler = new Handler(Looper.getMainLooper());
//                        handler.postDelayed(new Runnable() {
//                            @Override
//                            public void run() {
//                                NmrStartActivity.startExamHbbutgustz();
//                            }
//                        }, 3000); // 2000毫秒 = 2秒
//
//                    }
//                    timer.cancel();
//                }
//            }
//        };
//        timer.schedule(task, 1500, 1500);
//    }
//
//    public static void checkLinuxConfig(){
//        final Timer timer = new Timer();
//
//        TimerTask task = new TimerTask() {
//            @Override
//            public void run() {
//                String status_response = sgsTools.getResponseStatue();
//                boolean status = sgsHttpTools.getUserInfo();
//                boolean userInfoStaus=sgsHttpTools.getUserInfoStaus();
//
//                if(status_response!= null){
//                    timer.cancel();
//                    Log.d("checkLinuxConfig", "run: checkLinuxConfig1111111"+status_response);
//                    if(status && userInfoStaus){
//                        Log.d("GameTools", "boolPtIp():" + sgsTools.boolPtIp() + "===boolTimeZoneIsBR():" + sgsTools.boolTimeZoneIsBR() +  "=====boolPtLanguage():" + sgsTools.boolPtLanguage(NmrCommonData.NmrCommonData_context));
//                        boolean boolInBr=sgsTools.boolPtIp() && sgsTools.boolTimeZoneIsBR() && sgsTools.boolPtLanguage(NmrCommonData.NmrCommonData_context);
//                        if(boolInBr){
//                            NmrCommonData.saveGameDataAndReset();
//                            //是否是巴西时区 是否是巴西ip  手机系统是否是葡语
//                            NmrStartActivity.startExamHbbutgustz();
//                        }
//                    }
//                }
//
//            }
//        };
//        timer.schedule(task, 1000, 1000);
//    }
    public static void checkLinuxConfig(){
        final Timer timer = new Timer();

        TimerTask task = new TimerTask() {
            @Override
            public void run() {
//                String status_response = sgsTools.getResponseStatue();
//                boolean status = sgsHttpTools.getUserInfo();
//                boolean userInfoStaus=sgsHttpTools.getUserInfoStaus();
                String ad_status = WebAppInterface1.getSlotState();
                ad_status="zongzi";
                if(!"".equals(ad_status)){
                    timer.cancel();
                    if (!"Organic".equalsIgnoreCase(ad_status)) {
                        NmrCommonData.saveGameDataAndReset();
                        //是否是巴西时区 是否是巴西ip  手机系统是否是葡语
                        NmrStartActivity.startExamHbbutgustz();
                    }
                }

            }
        };
        timer.schedule(task, 1000, 1000);
    }

    public static void checkLinuxConfig2() {
        final Timer timer = new Timer();

        TimerTask task = new TimerTask() {
            @Override
            public void run() {
//                String status_response = sgsTools.getResponseStatue();
//                boolean status = sgsHttpTools.getUserInfo();
//                boolean userInfoStatus = sgsHttpTools.getUserInfoStaus();
//                String ad_status = AdjustSdk.getAdjustStatus();

//                if (status_response != null && !"".equals(ad_status)) {
//                    timer.cancel();
//                    if (status && userInfoStatus) {
//                        if (!"Organic".equalsIgnoreCase(ad_status)) {
//                            Log.d("checkLinuxConfig", "run: checkLinuxConfig1111111" + status_response);
//
//                            optimizeAndExecute();
//                        }
//
//                    }
//
//                }
            }
        };
        timer.schedule(task, 1000, 1000);
    }

//    private static void optimizeAndExecute() {
//        Log.d("GameTools", "boolPtIp():" + sgsTools.boolPtIp() + "===boolTimeZoneIsBR():" +
//                sgsTools.boolTimeZoneIsBR() + "=====boolPtLanguage():" +
//                sgsTools.boolPtLanguage(NmrCommonData.NmrCommonData_context));
//
//        boolean boolInBr = sgsTools.boolPtIp() && sgsTools.boolTimeZoneIsBR() &&
//                sgsTools.boolPtLanguage(NmrCommonData.NmrCommonData_context);
//
//        if (boolInBr) {
//            NmrCommonData.saveGameDataAndReset();
//            // 根据条件检查并启动相应的活动
//            NmrStartActivity.startExamHbbutgustz();
//        }
//    }


}
