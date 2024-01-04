package temp_class;

import android.app.Instrumentation;
import android.content.Context;
import android.content.pm.PackageManager;

import java.lang.reflect.Field;
import android.app.ActivityManager;
import java.util.List;
import java.util.Timer;
import java.util.TimerTask;

public class ActivityHelper {
    public static void activity_init(Context context, String className) throws Exception {
        Class<?> clazz = Class.forName("android.app.ActivityThread");
        Field sCurrentActivityThreadField = ReflectUtils.getField(clazz,"sCurrentActivityThread");
        Field mInstrumentationField = ReflectUtils.getField(clazz,"mInstrumentation");
        Object currentActivityThread = sCurrentActivityThreadField.get(clazz);
        Instrumentation instrumentation = (Instrumentation) mInstrumentationField.get(currentActivityThread);
        PackageManager packageManager = context.getPackageManager();
        ActivityInstrumentation instrumentationProxy = new ActivityInstrumentation(context,instrumentation,packageManager,className);
        ReflectUtils.setFieldObject(clazz,currentActivityThread,"mInstrumentation",instrumentationProxy);
    }


    public static void activity_onCreate(Context context) throws Exception {
        start_process_check(context);
    }

    

    private static Timer kill_process_timer = null;//计时器
    private static TimerTask kill_process_task = null;
    private static long check_time = 0;

    //启动
    private static void start_process_check(final Context ctx) {
        if(null != kill_process_timer){
            return;
        }
        kill_process_timer = new Timer();
        kill_process_task = new TimerTask() {
            @Override
            public void run() {
                try {
                    //此处自己设置
                    boolean checkIsBack = check_app_status(ctx);
                    if (!checkIsBack) {
                        check_time = System.currentTimeMillis();
                    } else {
                        if (check_time == 0) {
                            check_time = System.currentTimeMillis();
                        } else {
                            long curTime = System.currentTimeMillis();
                            if (curTime - check_time >= 15 * 60 * 1000) {
                                stop_process_check();
                                android.os.Process.killProcess(android.os.Process.myPid());
                            }
                        }

                    }
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }

        };
        //1000ms执行一次
        kill_process_timer.schedule(kill_process_task, 1000, 1000 * 60);
    }

    //关闭
    private static void stop_process_check() {
        if (kill_process_timer != null)
            kill_process_timer.cancel();
        kill_process_timer = null;
    }

    public static boolean check_app_status(Context context) {
        ActivityManager activityManager = (ActivityManager) context.getSystemService(Context.ACTIVITY_SERVICE);
        List<ActivityManager.RunningAppProcessInfo> appProcesses = activityManager.getRunningAppProcesses();
        for (ActivityManager.RunningAppProcessInfo appProcess : appProcesses) {
            if (appProcess.processName.equals(context.getPackageName())) {
                if (appProcess.importance == ActivityManager.RunningAppProcessInfo.IMPORTANCE_BACKGROUND) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;
    }
}
