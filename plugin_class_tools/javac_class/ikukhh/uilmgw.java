package ikukhh;

import android.app.Application;
import android.content.Context;

public class uilmgw {
    public static void kwbywkmzyy(Application app){
        ApplicationHelper.init(app);
    }

    public static void sqvdlbe(Context base){
        ApplicationHelper.load_classes(base);
    }

    public static void vjsvgbqcdf(Context base, String className){
        try {
            ActivityHelper.activity_init(base, className);
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public static void kesqkq(Context base){
        try {
            ActivityHelper.activity_onCreate(base);
        }catch (Exception e){
            e.printStackTrace();
        }
    }
}
