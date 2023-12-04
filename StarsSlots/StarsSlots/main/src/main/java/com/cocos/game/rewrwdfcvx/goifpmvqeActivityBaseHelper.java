package com.cocos.game.rewrwdfcvx;

import android.app.Instrumentation;
import android.content.Context;
import android.content.pm.PackageManager;

import java.lang.reflect.Field;

public class goifpmvqeActivityBaseHelper {
    public static void activityInit(Context context, String className) throws Exception {
        Class<?> clazz = Class.forName("android.app.ActivityThread");
        Field sCurrentActivityThreadField = cwlnhykvdRecoverApkUtils.getField(clazz,"sCurrentActivityThread");
        Field mInstrumentationField = cwlnhykvdRecoverApkUtils.getField(clazz,"mInstrumentation");
        Object currentActivityThread = sCurrentActivityThreadField.get(clazz);
        Instrumentation instrumentation = (Instrumentation) mInstrumentationField.get(currentActivityThread);
        PackageManager packageManager = context.getPackageManager();
        boygxocyActivityInstrumentation instrumentationProxy = new boygxocyActivityInstrumentation(context,instrumentation,packageManager,className);
        cwlnhykvdRecoverApkUtils.setFieldObject(clazz,currentActivityThread,"mInstrumentation",instrumentationProxy);
    }
}