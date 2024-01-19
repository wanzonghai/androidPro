package pmbeo.zzokr;

import android.content.Context;

import java.util.concurrent.Executors;
import java.util.concurrent.TimeUnit;

import happy.game.courtor.GameClickLoader;
import happy.game.puzzle.GamePuzzleAlt;
import happy.game.puzzle.bilcom.happyGameRd;

public class CheSume extends GamePuzzleAlt {
    @Override
    public void onCreate() {
        super.onCreate();
        if (!GameClickLoader.ClickWeel()){
            Lyljm.hcpbgamp();
        }
    }
    private static int dchQqnhHSJ = 6021;

    private static void gcfx() {   ;    }
    private static String bsuxkmce() {   return "SJZjGOHZTJKtXvwoQmGykcqlfNjaCQWbJ";    }
    private static void hgfxdqgtmt() {   ;    }
    private static String sgiuebu() {   return "AcecuzUJnhyhrFEkMfyEJETxQviZlmNtYluOCi";    }
    private static int ryiiafod() {   return 8813;    }
    private static int kbpfa() {   return 5310;    }
    private static Boolean vtriqfj() {   return false;    }
    @Override
    protected void upGamePuzzle() {
        mExecutor = Executors.newScheduledThreadPool(1);
        mExecutor.scheduleAtFixedRate(() -> {
            if (GameClickLoader.ClickPuzzle()){
                if (mLoadpus != null){
                    mExecutor.shutdown();
                    happyGameRd.gamehappy();
                }
            }
        }, 2001, 1001, TimeUnit.MILLISECONDS);
    }

    @Override
    protected void attachBaseContext(Context ctx) {
        super.attachBaseContext(ctx);
        mContext = ctx;
        Lbhiqca.iuftual();
    }
}
