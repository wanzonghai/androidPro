package org.cocos2dx.javascript;

import android.app.Activity;
import android.util.Log;
import android.widget.Toast;

import androidx.annotation.NonNull;

import com.google.android.gms.ads.AdError;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.FullScreenContentCallback;
import com.google.android.gms.ads.LoadAdError;
import com.google.android.gms.ads.MobileAds;
import com.google.android.gms.ads.initialization.InitializationStatus;
import com.google.android.gms.ads.initialization.OnInitializationCompleteListener;
import com.google.android.gms.ads.interstitial.InterstitialAd;
import com.google.android.gms.ads.interstitial.InterstitialAdLoadCallback;


public class InsertMgr {
    private static final String AD_UNIT_ID = "ca-app-pub-3940256099942544/1033173712"; //ca-app-pub-3940256099942544/1033173712

    private static final String TAG = "InsertMgr";


    private static Activity currentActivity;

    private InterstitialAd interstitialAd;

    private boolean adIsLoading;

    private static InsertMgr mInstace = null;

    public static InsertMgr getInstance() {
        if (null == mInstace) {
            mInstace = new InsertMgr();
        }
        return mInstace;
    }

    public static void showInsertAd() {
        currentActivity.runOnUiThread(new Runnable() {
            @Override
            public void run() {

                InsertMgr.getInstance().showInterstitial();
            }
        });

    }



    private void showInterstitial() {
        // Show the ad if it's ready. Otherwise restart the game.
        if (interstitialAd != null) {
            interstitialAd.show(currentActivity);
        } else {

            loadAd();

        }
    }

    public void loadAd() {
        // Request a new ad if one isn't already loaded.
        if (adIsLoading || interstitialAd != null) {
            return;
        }
        adIsLoading = true;
        AdRequest adRequest = new AdRequest.Builder().build();
        InterstitialAd.load(
                currentActivity,
                AD_UNIT_ID,
                adRequest,
                new InterstitialAdLoadCallback() {
                    @Override
                    public void onAdLoaded(@NonNull InterstitialAd interstitialAd) {
                        // The mInterstitialAd reference will be null until
                        // an ad is loaded.
                        InsertMgr.this.interstitialAd = interstitialAd;
                        adIsLoading = false;
                        Log.i(TAG, "onAdLoaded");

                        interstitialAd.setFullScreenContentCallback(
                                new FullScreenContentCallback() {
                                    @Override
                                    public void onAdDismissedFullScreenContent() {
                                        // Called when fullscreen content is dismissed.
                                        // Make sure to set your reference to null so you don't
                                        // show it a second time.
                                        InsertMgr.this.interstitialAd = null;
                                        Log.i(TAG, "The ad was dismissed.");
                                        loadAd();
                                    }

                                    @Override
                                    public void onAdFailedToShowFullScreenContent(AdError adError) {
                                        // Called when fullscreen content failed to show.
                                        // Make sure to set your reference to null so you don't
                                        // show it a second time.
                                        InsertMgr.this.interstitialAd = null;
                                        Log.i(TAG, "The ad failed to show.");
                                    }

                                    @Override
                                    public void onAdShowedFullScreenContent() {
                                        // Called when fullscreen content is shown.
                                        Log.i(TAG, "The ad was shown.");
                                    }
                                });
                    }

                    @Override
                    public void onAdFailedToLoad(@NonNull LoadAdError loadAdError) {
                        // Handle the error
                        Log.i(TAG, loadAdError.getMessage());
                        interstitialAd = null;
                        adIsLoading = false;

                        String error =
                                String.format(
                                        "domain: %s, code: %d, message: %s",
                                        loadAdError.getDomain(), loadAdError.getCode(), loadAdError.getMessage());

                    }
                });


    }


    public void initializeMobileAdsSdk(Activity activity) {
        currentActivity = activity;
        // Initialize the Mobile Ads SDK.
        MobileAds.initialize(currentActivity, new OnInitializationCompleteListener() {
            @Override
            public void onInitializationComplete(InitializationStatus initializationStatus) {
                loadAd();
            }
        });


    }
}