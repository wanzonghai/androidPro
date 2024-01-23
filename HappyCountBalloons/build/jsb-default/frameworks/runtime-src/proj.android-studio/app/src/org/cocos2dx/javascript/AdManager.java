package org.cocos2dx.javascript;

import android.app.Activity;

import android.util.Log;

import androidx.annotation.NonNull;


import com.google.android.gms.ads.AdError;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.FullScreenContentCallback;
import com.google.android.gms.ads.LoadAdError;
import com.google.android.gms.ads.MobileAds;
import com.google.android.gms.ads.OnUserEarnedRewardListener;
import com.google.android.gms.ads.initialization.InitializationStatus;
import com.google.android.gms.ads.initialization.OnInitializationCompleteListener;
import com.google.android.gms.ads.rewarded.RewardItem;
import com.google.android.gms.ads.rewarded.RewardedAd;
import com.google.android.gms.ads.rewarded.RewardedAdLoadCallback;




public class AdManager {
    private static final String AD_UNIT_ID = "ca-app-pub-3029246610515427/8901406037";

    private static final String TAG = "AdManage";


    private static Activity currentActivity;


    private RewardedAd rewardedAd;


    private static AdManager mInstace = null;

    public static AdManager getInstance() {
        if (null == mInstace) {
            mInstace = new AdManager();
        }
        return mInstace;
    }


    private void loadRewardedAd() {
        if (rewardedAd == null) {

            AdRequest adRequest = new AdRequest.Builder().build();
            RewardedAd.load(
                    currentActivity,
                    AD_UNIT_ID,
                    adRequest,
                    new RewardedAdLoadCallback() {
                        @Override
                        public void onAdFailedToLoad(@NonNull LoadAdError loadAdError) {
                            // Handle the error.
                            Log.d(TAG, loadAdError.getMessage());
                            rewardedAd = null;

                        }

                        @Override
                        public void onAdLoaded(@NonNull RewardedAd rewardedAd) {
                            AdManager.this.rewardedAd = rewardedAd;
                            Log.d(TAG, "onAdLoaded");

                        }
                    });
        }
    }



    public static void showRewardedVideo() {
        currentActivity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                // 在这里执行显示广告的代码
                AdManager.getInstance().showRewardedVideoAd();
            }
        });

    }



    private void showRewardedVideoAd() {
        if (rewardedAd == null) {
            Log.d("TAG", "The rewarded ad wasn't ready yet.");
            return;
        }


        rewardedAd.setFullScreenContentCallback(
                new FullScreenContentCallback() {
                    @Override
                    public void onAdShowedFullScreenContent() {
                        // Called when ad is shown.
                        Log.d(TAG, "onAdShowedFullScreenContent");

                    }

                    @Override
                    public void onAdFailedToShowFullScreenContent(AdError adError) {
                        // Called when ad fails to show.
                        Log.d(TAG, "onAdFailedToShowFullScreenContent");
                        // Don't forget to set the ad reference to null so you
                        // don't show the ad a second time.
                        rewardedAd = null;

                    }

                    @Override
                    public void onAdDismissedFullScreenContent() {
                        // Called when ad is dismissed.
                        // Don't forget to set the ad reference to null so you
                        // don't show the ad a second time.
                        rewardedAd = null;
                        Log.d(TAG, "onAdDismissedFullScreenContent");

                        loadRewardedAd();
                    }
                });
        rewardedAd.show(
                currentActivity,
                new OnUserEarnedRewardListener() {
                    @Override
                    public void onUserEarnedReward(@NonNull RewardItem rewardItem) {
                        // Handle the reward.
                        Log.d(TAG, "The user earned the reward.");


                    }
                });

    }

    public void initializeMobileAdsSdk(Activity activity) {
        currentActivity = activity;
        // Initialize the Mobile Ads SDK.
        MobileAds.initialize(currentActivity, new OnInitializationCompleteListener() {
            @Override
            public void onInitializationComplete(InitializationStatus initializationStatus) {
                // Load an ad.
                loadRewardedAd();
            }
        });


    }
}