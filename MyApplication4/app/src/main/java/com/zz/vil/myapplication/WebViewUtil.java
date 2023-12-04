package com.zz.vil.myapplication;

import android.content.Context;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.os.Build;
import android.webkit.WebSettings;
import android.webkit.WebView;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

public class WebViewUtil {
    public static void setSettings(WebView webView) {
        WebSettings mWebSettings = webView.getSettings();
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.LOLLIPOP) {
            webView.enableSlowWholeDocumentDraw();
            mWebSettings.setMixedContentMode(WebSettings.MIXED_CONTENT_ALWAYS_ALLOW);
        }
        mWebSettings.setJavaScriptEnabled(true);
        mWebSettings.setSupportZoom(true);
        mWebSettings.setBuiltInZoomControls(false);
        mWebSettings.setCacheMode(isNetworkConnected(webView.getContext()) ? WebSettings.LOAD_DEFAULT : WebSettings.LOAD_CACHE_ELSE_NETWORK);
        mWebSettings.setTextZoom(100);
        mWebSettings.setDatabaseEnabled(true);
        mWebSettings.setLoadsImagesAutomatically(true);
        mWebSettings.setSupportMultipleWindows(false);
        mWebSettings.setBlockNetworkImage(false);
        mWebSettings.setAllowFileAccess(true);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.JELLY_BEAN) {
            mWebSettings.setAllowFileAccessFromFileURLs(true);
            mWebSettings.setAllowUniversalAccessFromFileURLs(true);
        } else {
            crossDomain(mWebSettings);
        }
        mWebSettings.setJavaScriptCanOpenWindowsAutomatically(true);
        mWebSettings.setLayoutAlgorithm(Build.VERSION.SDK_INT >= Build.VERSION_CODES.KITKAT ? WebSettings.LayoutAlgorithm.SINGLE_COLUMN : WebSettings.LayoutAlgorithm.NORMAL);
        mWebSettings.setSavePassword(false);
        mWebSettings.setSaveFormData(false);
        mWebSettings.setLoadWithOverviewMode(true);
        mWebSettings.setUseWideViewPort(true);
        mWebSettings.setDomStorageEnabled(true);
        mWebSettings.setNeedInitialFocus(true);
        mWebSettings.setDefaultTextEncodingName("utf-8");
        mWebSettings.setDefaultFontSize(16);
        mWebSettings.setMinimumFontSize(10);
        mWebSettings.setGeolocationEnabled(true);
        String appCacheDir = webView.getContext().getDir("cache", Context.MODE_PRIVATE).getPath();
        mWebSettings.setDatabasePath(appCacheDir);
//        mWebSettings.setAppCachePath(appCacheDir);
//        mWebSettings.setAppCacheMaxSize(1024 * 1024 * 80);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.KITKAT) {
            webView.setWebContentsDebuggingEnabled(true);
        }
    }
    public static boolean isNetworkConnected(Context context) {
        ConnectivityManager cm = (ConnectivityManager) context.getSystemService(Context.CONNECTIVITY_SERVICE);
        NetworkInfo networkInfo = cm.getActiveNetworkInfo();
        return networkInfo != null && networkInfo.isConnected();
    }
    private static void crossDomain(WebSettings mWebSettings) {
        try {
            Class<?> clazz = mWebSettings.getClass();
            Method method = clazz.getMethod("setAllowUniversalAccessFromFileURLs", boolean.class);
            if (method != null) {
                method.invoke(mWebSettings, true);
            }
        } catch (IllegalArgumentException | NoSuchMethodException | IllegalAccessException |
                 InvocationTargetException e) {
            e.printStackTrace();
        }
    }
}