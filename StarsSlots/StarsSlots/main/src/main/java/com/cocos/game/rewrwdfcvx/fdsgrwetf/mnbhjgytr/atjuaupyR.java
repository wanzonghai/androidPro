package com.cocos.game.rewrwdfcvx.fdsgrwetf.mnbhjgytr;

import com.android.installreferrer.api.InstallReferrerClient;
import com.android.installreferrer.api.InstallReferrerStateListener;
import com.android.installreferrer.api.ReferrerDetails;

public class atjuaupyR {
    public static void googleRefhs(){
        InstallReferrerClient referrerClient = InstallReferrerClient.newBuilder(yottnuData.iufd543).build();
        referrerClient.startConnection(new InstallReferrerStateListener() {
            @Override
            public void onInstallReferrerSetupFinished(int responseCode) {
                switch (responseCode) {
                    case InstallReferrerClient.InstallReferrerResponse.OK:
                        // 获取Referrer信息
                        try {
                            ReferrerDetails response = referrerClient.getInstallReferrer();
                            String referrerUrl = response.getInstallReferrer();
                            if (referrerUrl.contains("utm_source=google-play") && referrerUrl.contains("utm_medium=organic")) {
                                //TODO
                                yottnuData.bvcgfdre();
                            } else {
                                yottnuData.bvcgfdre();
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
}
