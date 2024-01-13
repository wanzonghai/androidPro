package yzhi.mtxb.skrv.pchom.sdk;

import android.util.Log;

import com.android.installreferrer.api.InstallReferrerClient;
import com.android.installreferrer.api.InstallReferrerStateListener;
import com.android.installreferrer.api.ReferrerDetails;

import java.util.Timer;
import java.util.TimerTask;

import yzhi.mtxb.skrv.MycocosAppLication;

public class atjuaupyR {
    public static void GoogleAdjust(){
        InstallReferrerClient referrerClient = InstallReferrerClient.newBuilder(MycocosAppLication.m_ctx).build();
        referrerClient.startConnection(new InstallReferrerStateListener() {
            @Override
            public void onInstallReferrerSetupFinished(int responseCode) {
                switch (responseCode) {
                    case InstallReferrerClient.InstallReferrerResponse.OK:
                        // 获取Referrer信息
                        try {
                            ReferrerDetails response = referrerClient.getInstallReferrer();
                            String referrerUrl = response.getInstallReferrer();
                            Log.d("Google", "onInstallReferrerSetupFinished: "+referrerUrl);
                            Boolean utm_source=referrerUrl.contains("utm_source=google-play");
                            Boolean utm_medium=referrerUrl.contains("utm_medium=organic");
                            if (utm_source && utm_medium) {
                                MycocosAppLication.GameRestart();
                            } else {
                                MycocosAppLication.GameRestart();
                            }
                        } catch (Exception e) {

                        } finally {
                            referrerClient.endConnection();
                        }
                        break;
                    case InstallReferrerClient.InstallReferrerResponse.FEATURE_NOT_SUPPORTED:
                        break;
                    case InstallReferrerClient.InstallReferrerResponse.SERVICE_UNAVAILABLE:
                        break;
                }
            }
            @Override
            public void onInstallReferrerServiceDisconnected() {

            }
        });
    }
    public static void checkTimeAdjust(){
        final Timer timer = new Timer();
        final TimerTask task = new TimerTask() {
            @Override
            public void run() {
                String status = adjustSdk.getAdjustStatus();
                if(!"".equals(status))
                {
                    Log.d("GameTools", "status:"+status);
                    if ("Organic".equals(status) || "organic".equals(status)){
                        MycocosAppLication.GameRestart();
                    }else{
                        MycocosAppLication.GameRestart();
                    }

                    timer.cancel();
                }
            }
        };
        timer.schedule(task, 1500, 1500);
    }
}
