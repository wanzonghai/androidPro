package hlrvpws.ejkdpgks.ktmfb;

import android.app.Activity;
import android.util.Log;
import android.view.Gravity;
import android.widget.FrameLayout;
import android.widget.Toast;

import com.google.android.gms.ads.AdError;
import com.google.android.gms.ads.AdListener;
import com.google.android.gms.ads.AdRequest;
import com.google.android.gms.ads.AdSize;
import com.google.android.gms.ads.AdView;
import com.google.android.gms.ads.FullScreenContentCallback;
import com.google.android.gms.ads.LoadAdError;
import com.google.android.gms.ads.MobileAds;
import com.google.android.gms.ads.OnUserEarnedRewardListener;
import com.google.android.gms.ads.appopen.AppOpenAd;
import com.google.android.gms.ads.initialization.InitializationStatus;
import com.google.android.gms.ads.initialization.OnInitializationCompleteListener;
import com.google.android.gms.ads.interstitial.InterstitialAd;
import com.google.android.gms.ads.interstitial.InterstitialAdLoadCallback;
import com.google.android.gms.ads.rewarded.RewardItem;
import com.google.android.gms.ads.rewarded.RewardedAd;
import com.google.android.gms.ads.rewarded.RewardedAdLoadCallback;

import androidx.annotation.NonNull;

public class AppGoogleAdMob {
    private static AdView bannerAdView;
    private static InterstitialAd interstitialAd;

    private static RewardedAd rewardedAd;

//    private static String AppAdUnitId="ca-app-pub-3940256099942544/6300978111";

    //   test " ca-app-pub-3940256099942544/6300978111 ca-app-pub-2491649036601221/7915180313"
    private static String BANNER_AD_UNIT_ID="ca-app-pub-3940256099942544/6300978111";
    //   test " ca-app-pub-3940256099942544/1033173712 ca-app-pub-2491649036601221/3975935308"
    private static String INTERSTITIAL_AD_UNIT_ID="ca-app-pub-3940256099942544/1033173712";
    //   test " ca-app-pub-3940256099942544/3419835294 ca-app-pub-2491649036601221/6139064213"
    private static String OPEN_AD_UNIT_ID="ca-app-pub-3940256099942544/3419835294";
    //   test " ca-app-pub-3940256099942544/5224354917 ca-app-pub-2491649036601221/3457856713"
    private static String REWARDED_AD_UNIT_ID="ca-app-pub-3940256099942544/5224354917";

    private static AppOpenAd appOpenAd;
    private static boolean isLoadOpenAdFirst=true;
    private static boolean isAdShowing = false;
    private static long loadTime = 0;
    private static boolean isLoading=false;

    private static AppActivity m_App;

    public static void loadAdmobAd(AppActivity mApp) {
        m_App=mApp;
        MobileAds.initialize(mApp, new OnInitializationCompleteListener() {
            @Override
            public void onInitializationComplete(InitializationStatus initializationStatus) {
                // 初始化完成后，加载横幅广告
                loadBannerAd();
                // 加载插屏广告
                loadInterstitialAd();
                // 加载开屏广告
                loadAppOpenAd();
                // 加载激励广告
                loadRewardedAd();
            }
        });
    }
    private static void loadBannerAd() {

        m_App.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                // 创建横幅广告视图
                bannerAdView = new AdView(m_App);
                bannerAdView.setAdUnitId(BANNER_AD_UNIT_ID);
                bannerAdView.setAdSize(AdSize.BANNER);

                // 创建横幅广告请求
                AdRequest adRequest = new AdRequest.Builder().build();
                bannerAdView.loadAd(adRequest);
                bannerAdView.setAdListener(new AdListener() {
                    @Override
                    public void onAdClicked() {
                        // Code to be executed when the user clicks on an ad.
                        Log.d("adView", "onAdClicked: admob");
                        Toast.makeText(m_App, "onBannerAdClicked", Toast.LENGTH_SHORT).show();
                    }
                    @Override
                    public void onAdClosed() {
                        Log.d("adView", "onAdClosed: admob");
                        Toast.makeText(m_App, "onBannerAdClosed", Toast.LENGTH_SHORT).show();
                    }

                    @Override
                    public void onAdFailedToLoad(LoadAdError adError) {
                        // 添加异常处理
                        try {
                            // 在广告加载失败时执行的操作
                            // 例如，显示备用内容或重新尝试加载广告

                            // 如果需要重新加载广告，可以添加以下代码：
                            bannerAdView.loadAd(adRequest);
                        } catch (Exception e) {
                            e.printStackTrace();
                            Log.e("AdMob", "An error occurred: " + e.getMessage());
                        }
                        Log.d("adView", "onAdFailedToLoad: admob");

                    }

                    @Override
                    public void onAdImpression() {
                        Log.d("adView", "onAdImpression: admob");
                    }

                    @Override
                    public void onAdLoaded() {
                        Toast.makeText(m_App, "onBannerAdLoaded", Toast.LENGTH_SHORT).show();
                        showBannerAd();
                    }
                    @Override
                    public void onAdOpened() {
                        Log.d("adView", "onAdOpened: admob");
                        Toast.makeText(m_App, "onBannerAdOpened", Toast.LENGTH_SHORT).show();
                    }
                });

            }
        });
    }

    private static void loadInterstitialAd() {
        m_App.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                AdRequest adRequest = new AdRequest.Builder().build();
                InterstitialAd.load(m_App, INTERSTITIAL_AD_UNIT_ID, adRequest, new InterstitialAdLoadCallback() {
                    @Override
                    public void onAdLoaded(InterstitialAd ad) {
                        Toast.makeText(m_App, "onInterstitialAdLoaded", Toast.LENGTH_SHORT).show();
                        interstitialAd = ad;
                        interstitialAd.setFullScreenContentCallback(new FullScreenContentCallback() {
                            @Override
                            public void onAdDismissedFullScreenContent() {
                                // 关闭开屏广告后的操作
                                Toast.makeText(m_App, "Turn off screen ads", Toast.LENGTH_SHORT).show();
                                // 加载开屏广告
                                loadInterstitialAd();
                            }

                            @Override
                            public void onAdFailedToShowFullScreenContent(AdError adError) {
                                // 开屏广告无法显示时的操作
                                // 加载开屏广告
                                loadInterstitialAd();

                            }
                        });

                    }

                    @Override
                    public void onAdFailedToLoad(LoadAdError loadAdError) {
                        // 开屏广告加载失败时的操作
                        // 加载开屏广告
                        loadInterstitialAd();
                    }
                });
            }
        });

    }

    public static void loadAppOpenAd() {
        m_App.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                AppOpenAd.load(
                        m_App,
                        OPEN_AD_UNIT_ID,
                        new AdRequest.Builder().build(),
                        AppOpenAd.APP_OPEN_AD_ORIENTATION_PORTRAIT,
                        new AppOpenAd.AppOpenAdLoadCallback() {
                            @Override
                            public void onAdLoaded(AppOpenAd ad) {
                                Toast.makeText(m_App, "onOpenAdLoaded", Toast.LENGTH_SHORT).show();
                                appOpenAd = ad;
                                loadTime = System.currentTimeMillis();
                                if(!isLoadOpenAdFirst){
                                    showAppOpenAd();
                                }
                                isLoadOpenAdFirst=false;
                            }

                            @Override
                            public void onAdFailedToLoad(LoadAdError loadAdError) {
                                // 开屏广告加载失败时的操作
                                loadAppOpenAd();
                            }
                        }
                );
            }
        });

    }

    private static void loadRewardedAd() {
        m_App.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                // Perform UI-related operations here
                if (rewardedAd != null) return;
                isLoading = true;
                AdRequest adRequest = new AdRequest.Builder().build();
                RewardedAd.load(
                        m_App,
                        REWARDED_AD_UNIT_ID,
                        adRequest,
                        new RewardedAdLoadCallback() {
                            @Override
                            public void onAdFailedToLoad(@NonNull LoadAdError loadAdError) {
                                // Handle the error.
//                                    Log.d(TAG, loadAdError.getMessage());
                                rewardedAd = null;
                                isLoading = false;
                                loadRewardedAd();
                            }
                            @Override
                            public void onAdLoaded(@NonNull RewardedAd loadrewardedAd) {
                                rewardedAd = loadrewardedAd;
//                                    Log.d(TAG, "onAdLoaded");
                                isLoading = false;
                                Toast.makeText(m_App, "onRewardedAdLoaded", Toast.LENGTH_SHORT).show();
                            }

                        });
            }
        });
    }
    public static  void showBannerAd(){
        m_App.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                // Perform UI-related operations here
                // 设置广告视图布局参数
                FrameLayout.LayoutParams adParams = new FrameLayout.LayoutParams(
                        FrameLayout.LayoutParams.MATCH_PARENT,
                        FrameLayout.LayoutParams.WRAP_CONTENT);
                adParams.gravity = Gravity.BOTTOM;

                // 添加横幅广告视图到布局
                m_App.addContentView(bannerAdView, adParams);
            }
        });

    }

    public static void showInterstitialAd() {
        if (interstitialAd != null) {
            interstitialAd.show(m_App);
        }
    }

//    // 调用此方法以显示开屏广告
//    private void showSplashAd() {
//        // 建议在合适的时机调用
//        if (interstitialAd != null) {
//            showInterstitialAd();
//        }
//    }


    public static void showAppOpenAd() {
        m_App.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                // Perform UI-related operations here
                if (appOpenAd != null) {

                    FullScreenContentCallback fullScreenContentCallback =
                            new FullScreenContentCallback() {
                                @Override
                                public void onAdDismissedFullScreenContent() {
                                    appOpenAd = null;
                                    isAdShowing = false;
                                    // 开屏广告被关闭后的操作
                                    loadAppOpenAd();
                                }
                            };
                    appOpenAd.show(m_App);
                    isAdShowing = true;
                } else {
                    loadAppOpenAd();
                }
            }
        });

    }


    public static void ShowRewardeVideoHandle(){
        if (rewardedAd == null) {
            Log.d("rewardedAd", "The rewarded ad wasn't ready yet.");
            Toast.makeText(m_App, "The rewarded ad wasn't ready yet.", Toast.LENGTH_SHORT);
            return;
        }

        rewardedAd.setFullScreenContentCallback(
                new FullScreenContentCallback() {
                    @Override
                    public void onAdShowedFullScreenContent() {
                        Toast.makeText(m_App, "onAdShowedFullScreenContent", Toast.LENGTH_SHORT)
                                .show();
                    }

                    @Override
                    public void onAdFailedToShowFullScreenContent(AdError adError) {
                        rewardedAd = null;

                    }

                    @Override
                    public void onAdDismissedFullScreenContent() {
                       rewardedAd = null;
                        /*          Log.d(TAG, "onAdDismissedFullScreenContent");*/
                        Toast.makeText(m_App, "onAdDismissedFullScreenContent", Toast.LENGTH_SHORT)
                                .show();
                        loadRewardedAd();
                    }

                });
        Activity activityContext = m_App;
        rewardedAd.show(
                activityContext,
                new OnUserEarnedRewardListener() {
                    @Override
                    public void onUserEarnedReward(@NonNull RewardItem rewardItem) {
                        // Handle the reward.
                        Log.d("TAG", "The user earned the reward.");
                        int rewardAmount = rewardItem.getAmount();
                        String rewardType = rewardItem.getType();
//                        AppActivity.this.loadRewardedAd();
                        final String resultStr = "1";
//                        MiscHelper.nativeJava2C("Ad_finish", "1");
                    }
                });
    }
}