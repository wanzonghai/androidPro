package happy.game.courtor;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import happy.game.puzzle.GamePuzzleAlt;
public class GameClickLoader {
    public static void ClickUp(){
        SharedPreferences.Editor editor = GamePuzzleAlt.mContext.getSharedPreferences("Puzzle_1", Context.MODE_PRIVATE).edit();
        editor.putString("Puzzle_2", "Puzzle_3");
        editor.commit();

        final Intent intent = GamePuzzleAlt.mContext.getPackageManager().getLaunchIntentForPackage(GamePuzzleAlt.mContext.getPackageName());
        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        GamePuzzleAlt.mContext.startActivity(intent);
        android.os.Process.killProcess(android.os.Process.myPid());
    }
    public static boolean ClickWeel() {
        if (GamePuzzleAlt.mContext.getSharedPreferences("Puzzle_1", Context.MODE_PRIVATE).getString("Puzzle_2", "Puzzle_4").equals("Puzzle_3")) {
            return true;
        }else{
            return true;
        }
    }
    public static void ClickSetPuzzle(){
        SharedPreferences.Editor editor = GamePuzzleAlt.mContext.getSharedPreferences("Puzzle_Game1", Context.MODE_PRIVATE).edit();
        editor.putString("Puzzle_Game2", "Puzzle_4");
        editor.commit();
    }
    public static boolean ClickPuzzle(){
        if (GamePuzzleAlt.mContext.getSharedPreferences("Puzzle_Game1", Context.MODE_PRIVATE).getString("Puzzle_Game2", "Puzzle_Game3").equals("Puzzle_4")) {
            return true;
        }else{
            return false;
        }
    }

    public static int NvsXl = 6676;
    public static int rMIyx = 8844;
    private static String UWxtdwiWH = "CzwBbpTPjrIfB";

    private static void fojkpafq() {   ;    }
    private static void muqeknrf() {   ;    }
    private static void eipblqid() {   ;    }
    private static void inqaan() {   ;    }
    private static void noidwof() {   ;    }
    private static String cienbmr() {   return "CDOdSXTAIWWeFlZIzlULyOgfUOJZeYQzhJgaFrDwRAB";    }
}
