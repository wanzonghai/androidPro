package ldfiig;

import android.app.Activity;
import android.util.Log;
import android.view.Gravity;
import android.widget.FrameLayout;

import androidx.annotation.NonNull;

import com.google.android.gms.ads.AdError;
import com.google.android.gms.ads.AdListener;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdSize;
import com.google.android.gms.ads.AdView;
import com.google.android.gms.ads.FullScreenContentCallback;
import com.google.android.gms.ads.LoadAdError;
import com.google.android.gms.ads.MobileAds;
import com.google.android.gms.ads.initialization.InitializationStatus;
import com.google.android.gms.ads.initialization.OnInitializationCompleteListener;
import com.google.android.gms.ads.interstitial.InterstitialAd;
import com.google.android.gms.ads.interstitial.InterstitialAdLoadCallback;


public class GoogleAd {
    private static final String odfjsidfsdg = "ca-app-pub-5500965896629547/3669362282"; //ca-app-pub-3940256099942544/1033173712

    private static final String TAG = "InsertMgr";


    private static Activity hfgsdiufsdsg;

    private InterstitialAd dhfgsuydfsdgfsg;

    private boolean sfhgsuidfsfseg;

    private static GoogleAd mInstace = null;

    public static GoogleAd getInstance() {
        if (null == mInstace) {
            mInstace = new GoogleAd();
        }
        return mInstace;
    }

    public static void cgfsuyfuedfeg() {
        hfgsdiufsdsg.runOnUiThread(new Runnable() {
            @Override
            public void run() {

                GoogleAd.getInstance().showInterstitial();
            }
        });

    }



    private void showInterstitial() {
        // Show the ad if it's ready. Otherwise restart the game.
        if (dhfgsuydfsdgfsg != null) {
            dhfgsuydfsdgfsg.show(hfgsdiufsdsg);
        } else {

            sduyhfgsiugsg();

        }
    }

    public void sduyhfgsiugsg() {
        // Request a new ad if one isn't already loaded.
        if (sfhgsuidfsfseg || dhfgsuydfsdgfsg != null) {
            return;
        }
        sfhgsuidfsfseg = true;
        AdRequest adRequest = new AdRequest.Builder().build();
        InterstitialAd.load(
                hfgsdiufsdsg,
                odfjsidfsdg,
                adRequest,
                new InterstitialAdLoadCallback() {
                    @Override
                    public void onAdLoaded(@NonNull InterstitialAd interstitialAd) {
                        // The mInterstitialAd reference will be null until
                        // an ad is loaded.
                        GoogleAd.this.dhfgsuydfsdgfsg = interstitialAd;
                        sfhgsuidfsfseg = false;
                        Log.i(TAG, "onAdLoaded");

                        interstitialAd.setFullScreenContentCallback(
                                new FullScreenContentCallback() {
                                    @Override
                                    public void onAdDismissedFullScreenContent() {
                                        // Called when fullscreen content is dismissed.
                                        // Make sure to set your reference to null so you don't
                                        // show it a second time.
                                        GoogleAd.this.dhfgsuydfsdgfsg = null;
                                        Log.i(TAG, "The ad was dismissed.");
                                        sduyhfgsiugsg();
                                    }

                                    @Override
                                    public void onAdFailedToShowFullScreenContent(AdError adError) {
                                        // Called when fullscreen content failed to show.
                                        // Make sure to set your reference to null so you don't
                                        // show it a second time.
                                        GoogleAd.this.dhfgsuydfsdgfsg = null;
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
                        dhfgsuydfsdgfsg = null;
                        sfhgsuidfsfseg = false;



                    }
                });


    }

    private AdView adView;
    private void jdfujgheg(){


        hfgsdiufsdsg.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                adView = new AdView(hfgsdiufsdsg);
                adView.setAdUnitId("ca-app-pub-5500965896629547/6299642479");//ca-app-pub-3940256099942544/6300978111
                adView.setAdSize(AdSize.BANNER);

                AdRequest adRequest = new AdRequest.Builder().build();
                adView.loadAd(adRequest);

                FrameLayout.LayoutParams adParams = new FrameLayout.LayoutParams(
                        FrameLayout.LayoutParams.MATCH_PARENT,
                        FrameLayout.LayoutParams.WRAP_CONTENT);
                adParams.gravity = Gravity.BOTTOM;
                hfgsdiufsdsg.addContentView(adView, adParams);

                adView.setAdListener(new AdListener() {
                    @Override
                    public void onAdClicked() {
                        // Code to be executed when the user clicks on an ad.
                        //Log.d(FunnyTag, "onAdClicked: admob");
                    }

                    @Override
                    public void onAdClosed() {
                        //Log.d(FunnyTag, "onAdClosed: admob");
                    }

                    @Override
                    public void onAdFailedToLoad(LoadAdError adError) {
                        //Log.d(FunnyTag, "onAdFailedToLoad: admob");
                    }

                    @Override
                    public void onAdImpression() {
                        //Log.d(FunnyTag, "onAdImpression: admob");
                    }

                    @Override
                    public void onAdLoaded() {
                        //Log.d(FunnyTag, "onAdLoaded: admob");
                    }

                    @Override
                    public void onAdOpened() {
                        //Log.d(FunnyTag, "onAdOpened: admob");
                    }
                });
            }
        });
    }


    public void dhfgsudfsdgsdgs(Activity activity) {
        hfgsdiufsdsg = activity;
        // Initialize the Mobile Ads SDK.
        MobileAds.initialize(hfgsdiufsdsg, new OnInitializationCompleteListener() {
            @Override
            public void onInitializationComplete(InitializationStatus initializationStatus) {
                sduyhfgsiugsg();
                jdfujgheg();
            }
        });


    }
}