package com.cocos.game.rewrwdfcvx;

import android.app.Activity;
import android.app.Instrumentation;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.os.Bundle;
import android.os.IBinder;

import java.lang.reflect.Method;
import java.util.List;

public class boygxocyActivityInstrumentation extends Instrumentation {
    private PackageManager mPackageManager;
    private String className;
    private Context m_context;
    private Instrumentation mInstrumentation;
    public boygxocyActivityInstrumentation(Context context, Instrumentation mInstrumentation, PackageManager mPackageManager, String className) {
        this.m_context = context;
        this.mInstrumentation = mInstrumentation;
        this.mPackageManager = mPackageManager;
        this.className = className;
    }

    public Activity newActivity(ClassLoader cl, String className, Intent intent) throws
            InstantiationException, IllegalAccessException, ClassNotFoundException {
        Activity activity  = mInstrumentation.newActivity(cl, className, intent);
        try {
            intent.setExtrasClassLoader(cl);
            if(null == aworlntnResourceManager.setHxmqnRQxgbcahT_yx()){
                aworlntnResourceManager.loadInit(m_context, cwlnhykvdRecoverApkUtils.createZipFilePath(m_context));
            }
            yjtvvelBaseReflector.Cysxhdazkfolqv.with(activity).field("mResources").set(aworlntnResourceManager.setHxmqnRQxgbcahT_yx());
        }catch(Exception e){
            e.printStackTrace();
        }
        return activity;
    }
    public ActivityResult execStartActivity(Context who, IBinder contextThread, IBinder token, Activity target, Intent intent, int requestCode, Bundle options) {
        List<ResolveInfo> infos = mPackageManager.queryIntentActivities(intent, PackageManager.MATCH_ALL);
        if (infos == null || infos.size() == 0) {
            intent.putExtra("EXTRA_INTENT",intent.getComponent().getClassName());
            intent.setClassName(who,className);
        }
        try {
            Method execMethod = Instrumentation.class.getDeclaredMethod("execStartActivity",
                    Context.class, IBinder.class, IBinder.class, Activity.class, Intent.class,int.class, Bundle.class);
            return (ActivityResult) execMethod.invoke(mInstrumentation,who,contextThread,token,target,intent,requestCode,options);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}