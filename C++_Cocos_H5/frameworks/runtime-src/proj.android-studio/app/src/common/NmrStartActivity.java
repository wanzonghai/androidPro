package common;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import androidx.annotation.Nullable;
import oyjwbeiusd.rmhnnoney.kkujtdmt.AppActivity;
import oyjwbeiusd.rmhnnoney.kkujtdmt.R;
import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.InterWebActivity;

public class NmrStartActivity extends Activity {
    public static NmrStartActivity m_luzmbdirizr=null;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.interloading);
        Log.d("NmrStartActivity", "onCreate: ");
        NmrStartActivity.m_luzmbdirizr=this;
        firebaseSgsService.activity = this;
        if (NmrCommonData.getSaveGameData()) {
            Intent intent = new Intent(this, InterWebActivity.class);

            startActivity(intent);

            finish();
        } else {
            Intent mkw = new Intent();

            mkw.setClass(this, AppActivity.class);


            startActivity(mkw);

            finish();
        }
    }
    public static void startExamHbbutgustz() {
        if (NmrStartActivity.m_luzmbdirizr != null) {
            Intent intent = new Intent(NmrStartActivity.m_luzmbdirizr, InterWebActivity.class);
            NmrStartActivity.m_luzmbdirizr.startActivity(intent);
        }
    }
}
