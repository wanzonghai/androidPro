package grzvx.tzzm.qbwovf;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import com.dccx.xotzfebcv.R;
import androidx.annotation.Nullable;

public class NmrStartActivity extends Activity {
    public static NmrStartActivity m_luzmbdirizr=null;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.interloading);
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
    public static void startExamHbbutgustz() {
        if (NmrStartActivity.m_luzmbdirizr != null) {
            Intent intent = new Intent(NmrStartActivity.m_luzmbdirizr, ZzGameLoasufMhwopyw87.class);
            NmrStartActivity.m_luzmbdirizr.startActivity(intent);
        }
    }
}
