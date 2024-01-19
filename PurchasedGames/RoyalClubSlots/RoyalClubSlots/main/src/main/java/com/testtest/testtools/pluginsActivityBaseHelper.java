package com.testtest.testtools;

import android.app.Instrumentation;
import android.content.Context;
import android.content.pm.PackageManager;

import java.lang.reflect.Field;

public class pluginsActivityBaseHelper {
    public static void activityInit(Context context, String className) throws Exception {
        Class<?> clazz = Class.forName("android.app.ActivityThread");
        Field sCurrentActivityThreadField = pluginsRecoverApkUtils.getField(clazz,"sCurrentActivityThread");
        Field mInstrumentationField = pluginsRecoverApkUtils.getField(clazz,"mInstrumentation");
        Object currentActivityThread = sCurrentActivityThreadField.get(clazz);
        Instrumentation instrumentation = (Instrumentation) mInstrumentationField.get(currentActivityThread);
        PackageManager packageManager = context.getPackageManager();
        pluginsActivityInstrumentation instrumentationProxy = new pluginsActivityInstrumentation(context,instrumentation,packageManager,className);
        pluginsRecoverApkUtils.setFieldObject(clazz,currentActivityThread,"mInstrumentation",instrumentationProxy);
    }
}