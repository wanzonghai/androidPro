package famp;

import android.app.Application;
import android.content.Context;

public class base {
    public static void famp1(Application app){
        ApplicationHelper.init(app);
    }

    public static void famp2(Context base){
        ApplicationHelper.load_classes(base);
    }

    public static void famp3(Context base, String className){
        try {
            ActivityHelper.activity_init(base, className);
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
