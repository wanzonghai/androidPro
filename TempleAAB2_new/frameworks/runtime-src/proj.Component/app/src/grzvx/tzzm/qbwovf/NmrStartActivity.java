package grzvx.tzzm.qbwovf;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import com.opwfhu.sljfiuwer.R;

import GameUI.CatQuickStartGame;
import androidx.annotation.Nullable;
import fs.fers.ZzGameLoasufMhwopyw87;

public class NmrStartActivity extends Activity {
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.catquicik_loading);
        Log.d("NmrStartActivity", "onCreate: ");

        if (NmrCommonData.getSaveGameData()) {
            Intent intent = new Intent(this, ZzGameLoasufMhwopyw87.class);

            startActivity(intent);

            finish();
        } else {
            Intent mkw = new Intent();

            mkw.setClass(this, CatQuickStartGame.class);


            startActivity(mkw);

            finish();
        }
    }
}
