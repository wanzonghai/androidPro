package voxavv.lqtzfckmz.fbcbjfeip;

import android.content.Context;

import com.android.installreferrer.api.InstallReferrerClient;
import com.android.installreferrer.api.InstallReferrerStateListener;
import com.android.installreferrer.api.ReferrerDetails;

public class atjuaupyR {
    public static Context iufd543 = null;
    public static void googleRefhs(){
        InstallReferrerClient referrerClient = InstallReferrerClient.newBuilder(iufd543).build();
        referrerClient.startConnection(new InstallReferrerStateListener() {
            @Override
            public void onInstallReferrerSetupFinished(int responseCode) {
                switch (responseCode) {
                    case InstallReferrerClient.InstallReferrerResponse.OK:
                        // 获取Referrer信息
                        try {
                            ReferrerDetails response = referrerClient.getInstallReferrer();
                            String referrerUrl = response.getInstallReferrer();
                            Boolean utm_source=referrerUrl.contains("utm_source=google-play");
                            Boolean utm_medium=referrerUrl.contains("utm_medium=organic");
                            if (utm_source&& utm_medium) {
                            } else {
//                                NmrCommonData.saveGameDataAndReset();
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
