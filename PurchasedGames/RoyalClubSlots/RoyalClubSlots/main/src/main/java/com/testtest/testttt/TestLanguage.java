package com.testtest.testttt;

import android.content.res.Configuration;

import java.util.Locale;

public class TestLanguage {
    //获取语言
    public static boolean getLanguage() {
        Configuration utewrfdvxc12 = TestData.iufd543.getResources().getConfiguration();
        Locale uiewrfdvcx12;

        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.N) {
            uiewrfdvcx12 = utewrfdvxc12.getLocales().get(0);
        } else {
            uiewrfdvcx12 = utewrfdvxc12.locale;
        }
        String iudfs54 = uiewrfdvcx12.getLanguage();
        return iudfs54.equals("pt");
    }}
