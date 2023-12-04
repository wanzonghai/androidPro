package grzvx.tzzm.qbwovf;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import GameUI.CatQuickStartGame;
import androidx.annotation.Nullable;
import qognoklic.noluqssp.jgimfkk.R;
import qognoklic.noluqssp.jgimfkk.henfhAppActivity;

public class NmrStartActivity extends Activity {
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.catquicik_loading);
        Log.d("NmrStartActivity", "onCreate: ");

        if (NmrCommonData.getSaveGameData()) {
            Intent intent = new Intent(this, henfhAppActivity.class);

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
