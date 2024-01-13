package uqto.flvx.qihut.npxehlibrary;

import android.app.Application;
import android.content.Context;
import android.util.Log;

public class tqijussms extends Application {

    static {
        //与CmakeLists.txt
        System.loadLibrary("wwesrbro");
    }
    private native boolean evljruekf(Context ctx);
    private native boolean swael();
    public native static void ffeaagz(String setValue);
    protected  boolean xjekdzgjwd(Context ctx){
        return  evljruekf(ctx);
    }
    protected  boolean gwjjujda(){
        return  swael();
    }
    protected static void lvhikf(String setValue){
        ffeaagz(setValue);
    }
    @Override
    public void onCreate() {
        super.onCreate();
        Log.d("baseAppLication", "onCreate: 1");
    }

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        Log.d("baseAppLication", "attachBaseContext: 1");
    }
}
