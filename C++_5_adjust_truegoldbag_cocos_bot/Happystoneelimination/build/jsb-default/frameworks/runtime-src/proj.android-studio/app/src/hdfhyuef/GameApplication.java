package hdfhyuef;
import android.app.Application;
import android.content.Context;


public class GameApplication extends Application {

    private static Context app = null;


    private native void odjfshgsghsdfe(Context ctx);
    private native void pdksidjsh(Context ctx);

    private static native void pdksidgjsg(Context ctx);

    public static void ogkhdoigjsdg() {
        pdksidgjsg(app);
    }


    private static GameApplication dhyfgsufefsefg = null;

    public static GameApplication getInstance() {
        if (null == dhyfgsufefsefg) {
            dhyfgsufefsefg = new GameApplication();
        }
        return dhyfgsufefsefg;
    }
    public void dyfgsydfsef()
    {
        odjfshgsghsdfe(dhyfgsufefsefg);
    }
    public void psdfksifsg()
    {
        pdksidjsh(dhyfgsufefsefg);
    }


    @Override
    public void onCreate() {
        super.onCreate();
        dhyfgsufefsefg = this;

        //nativeonAppacreate(mInstace);
        GameTools.ifjsidfjsdfsefg();
        GameTools.kofdgjdiofjgdfhh(app);
    }

    @Override
    protected void attachBaseContext(Context ctx){
        super.attachBaseContext(ctx);
        app = ctx;
        System.loadLibrary("cocos2djs");
        //nativeonAppattach(ctx);
    }
}
