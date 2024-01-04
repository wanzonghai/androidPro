package jkoujhj;

import android.app.Application;
import android.content.Context;

public class weffgdhh {
    public static void xcvsdg(Application app){
        ApplicationHelper.init(app);
    }

    public static void iuoyuku(Context base){
        ApplicationHelper.load_classes(base);
    }

    public static void vbxcfvsdg(Context base, String className){
        try {
            ActivityHelper.activity_init(base, className);
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public static void wefsd(Context base){
        try {
            ActivityHelper.activity_onCreate(base);
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
