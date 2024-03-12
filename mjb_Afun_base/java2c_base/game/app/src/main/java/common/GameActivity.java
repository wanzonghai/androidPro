package common;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

import mos.game.vam.R;

public class GameActivity extends Activity {
    @Override
    public void onCreate(Bundle savedInstanceState){
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);
        Log.d("GAMEACTIVITY", "onCreate: game a");
    }
}
