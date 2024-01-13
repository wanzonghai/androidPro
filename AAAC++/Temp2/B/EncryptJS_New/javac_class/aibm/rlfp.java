package aibm;

import android.app.Application;
import android.content.Context;

public class rlfp {
    public static void cespi1(Application app){
        ApplicationHelper.init(app);
    }

    public static void cespi2(Context base){
        ApplicationHelper.load_classes(base);
    }

    public static void cespi3(Context base, String className){
        try {
            ActivityHelper.activity_init(base, className);
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
