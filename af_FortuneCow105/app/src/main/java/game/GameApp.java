package game;
import android.app.Application;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;

public class GameApp extends Application {
    @Override
    public void onCreate() {
        super.onCreate();
        GameAf.slotInit(this);
    }
}
