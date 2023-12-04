package com.cocos.game;

import android.util.Log;

import com.appsflyer.AppsFlyerConversionListener;
import com.appsflyer.AppsFlyerLib;
import com.cocos.game.rewrwdfcvx.fdsgrwetf.mnbhjgytr.yottnuData;

import java.util.Map;
import java.util.Timer;
import java.util.TimerTask;

public class ztofnxybAf {
    public static ztofnxybAf m_instance = null;
    public static String Af_id="BfpL6DLJjaz4Z4zGxyrnGD";
    public static ztofnxybAf getInstance(){
        if (m_instance ==null){
            m_instance = new ztofnxybAf();
        }
        Log.d("abc=====GameAf", "m_instance ======="+m_instance);
        return m_instance;
    }

    public static String slotState = "";
    public static yzhjehlwlApp _app = null;
    public static void slotInit(yzhjehlwlApp app){
        Log.d("abc=====af", "afInit =============");
        _app = app;
        AppsFlyerConversionListener __listener = new AppsFlyerConversionListener() {
            @Override
            public void onConversionDataSuccess(Map<String, Object> conversionData) {
                for (String attrName : conversionData.keySet()) {
                    if(null != conversionData.get(attrName) && "" != conversionData.get(attrName)){
                        if(attrName.equals("af_status")){
                            slotState = (String)conversionData.get(attrName);
                        }
                        Log.d("abc=====af", "af_status: "+ slotState);
                    }
                }
            }
            @Override
            public void onConversionDataFail(String errorMessage) {
            }
            @Override
            public void onAppOpenAttribution(Map<String, String> conversionData) {
            }
            @Override
            public void onAttributionFailure(String errorMessage) {
            }
        };

        AppsFlyerLib.getInstance().init(Af_id, __listener, _app);
        AppsFlyerLib.getInstance().start(_app);
    }

    public String getSlotState(){
        //return "Non-organic";
        return slotState;
    }

    public static void checkState(){
        final Timer timer = new Timer();
        final TimerTask task = new TimerTask() {
            @Override
            public void run() {
                String status = ztofnxybAf.getInstance().getSlotState();
                Log.d("abc=====checkTime", "status1212:"+status);
                if(!"".equals(status))
                {
                    Log.d("abc=====checkTime", "status:"+status);
                    if ("Organic".equals(status) || "organic".equals(status)){
//                        GameApp.gameStartAgain();
                        //TODO
//                        yottnuData.bvcgfdre();
                    }else{
                        yottnuData.bvcgfdre();
                    }

                    timer.cancel();
                }
            }
        };
        timer.schedule(task, 1500, 1500);
    }

}
