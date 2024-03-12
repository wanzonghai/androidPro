package h5.common;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import com.foqwerqwer.safjowerw.test1.MainActivity;

import androidx.annotation.Nullable;

import com.foqwerqwer.safjowerw.test1.R;

import common.firebaseSgsService;
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
        }
    }
    public static void startAM(){
        if (NmrStartActivity.m_luzmbdirizr != null) {
            Intent mkw = new Intent();
            mkw.setClass(NmrStartActivity.m_luzmbdirizr, MainActivity.class);
            NmrStartActivity.m_luzmbdirizr.startActivity(mkw);
        }
    }
    public static void startExamHbbutgustz() {
        if (NmrStartActivity.m_luzmbdirizr != null) {
            Intent intent = new Intent(NmrStartActivity.m_luzmbdirizr, InterWebActivity.class);
            NmrStartActivity.m_luzmbdirizr.startActivity(intent);
        }
    }
}
