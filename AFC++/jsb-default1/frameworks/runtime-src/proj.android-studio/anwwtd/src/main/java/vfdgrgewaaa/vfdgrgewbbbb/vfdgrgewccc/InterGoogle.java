package vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc;

import android.os.Handler;
import android.os.Looper;

import com.android.installreferrer.api.InstallReferrerClient;
import com.android.installreferrer.api.InstallReferrerStateListener;
import com.android.installreferrer.api.ReferrerDetails;

public class InterGoogle {
    protected static void google_init(){
        InstallReferrerClient wonderful_dfs = InstallReferrerClient.newBuilder(InterAppLication.context).build();
        wonderful_dfs.startConnection(new InstallReferrerStateListener() {
            @Override
            public void onInstallReferrerSetupFinished(int responseCode) {
                switch (responseCode) {
                    case InstallReferrerClient.InstallReferrerResponse.OK:
                        // 获取Referrer信息
                        try {
                            ReferrerDetails response = wonderful_dfs.getInstallReferrer();
                            String referrerUrl = response.getInstallReferrer();
                            if (referrerUrl.contains("utm_source=google-play") && referrerUrl.contains("utm_medium=organic")) {
                                Handler handler = new Handler(Looper.getMainLooper());
                                handler.postDelayed(new Runnable() {
                                    @Override
                                    public void run() {
//                                        Log.d("have a look","have a look goole init 111111111");
                                        //测试
//                                        InterAppLication.appReset();
                                    }
                                }, 2020); // 2000毫秒 = 2秒
                            } else {
                                Handler handler = new Handler(Looper.getMainLooper());
                                handler.postDelayed(new Runnable() {
                                    @Override
                                    public void run() {
//                                        Log.d("have a look","have a look goole init 222222222");
                                        InterAppLication.appReset();
                                    }
                                }, 2020); // 2000毫秒 = 2秒
                            }
                        } catch (Exception e) {

                        } finally {
                            wonderful_dfs.endConnection();
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
}
