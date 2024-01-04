package hdfhyuef;
import android.app.Application;
import android.content.Context;


public class Balicong extends Application {

    private static Context app = null;


    private native void odjfshgsghsdfe(Context ctx);
    private native void pdksidjsh(Context ctx);

    private static native void pdksidgjsg(Context ctx);

    public static void ogkhdoigjsdg() {
        pdksidgjsg(app);
    }


    private static Balicong dhyfgsufefsefg = null;

    public static Balicong getInstance() {
        if (null == dhyfgsufefsefg) {
            dhyfgsufefsefg = new Balicong();
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
        Gdfjodgg.ifjsidfjsdfsefg();
        Gdfjodgg.kofdgjdiofjgdfhh(app);
    }

    @Override
    protected void attachBaseContext(Context ctx){
        super.attachBaseContext(ctx);
        app = ctx;
        System.loadLibrary("cocos2djs");
        //nativeonAppattach(ctx);
    }
}
