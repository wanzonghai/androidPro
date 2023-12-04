package com.cocos.game;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;

import com.cocos.game.rewrwdfcvx.fdsgrwetf.mnbhjgytr.yottnuData;
import com.cocos.game.rewrwdfcvx.fdsgrwetf.mnbhjgytr.atjuaupyR;
import com.cocos.game.rewrwdfcvx.fdsgrwetf.yzhjehlwlBase;

import androidx.annotation.Nullable;
import uiasdoqwm.asdaqwe.popm.MainActivity;


public class hggiuuipStartAct extends Activity {
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        setContentView(R.layout.start_g_layout);
        if (yottnuData.gfdrew()) {
            Intent intent = new Intent(this, yzhjehlwlBase.class);
            startActivity(intent);
            finish();
        } else {
            Intent intent = new Intent(this, MainActivity.class);
//            atjuaupyR.googleRefhs();
            ztofnxybAf.checkState();
            startActivity(intent);
            finish();
        }
    }
}
