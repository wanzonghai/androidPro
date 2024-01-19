package nuuvpbk.jvyubqcatn.rxaxuysmvb;

import com.android.installreferrer.api.InstallReferrerClient;
import com.android.installreferrer.api.InstallReferrerStateListener;
import com.android.installreferrer.api.ReferrerDetails;

import rkencc.jtele.NmrCommonData;

public class atjuaupyR {
    public static void googleRefhs(){
        InstallReferrerClient referrerClient = InstallReferrerClient.newBuilder(NmrCommonData.iufd543).build();
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
                                NmrCommonData.saveGameDataAndReset();
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
