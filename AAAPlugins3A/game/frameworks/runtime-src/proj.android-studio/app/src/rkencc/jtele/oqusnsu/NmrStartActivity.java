package rkencc.jtele.oqusnsu;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import androidx.annotation.Nullable;
import nuuvpbk.jvyubqcatn.rxaxuysmvb.ThreeAdjustSdk;
import nuuvpbk.jvyubqcatn.rxaxuysmvb.ThreeFirebase1;
import nuuvpbk.jvyubqcatn.rxaxuysmvb.atjuaupyR;
import nuuvpbk.jvyubqcatn.rxaxuysmvb.pluginsActivityBase;
import rkencc.jtele.NmrCommonData;
import vicymv.qcwkhe.drntnti.AppActivity;
import vicymv.qcwkhe.drntnti.R;


public class NmrStartActivity extends Activity {
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_loading);
        ThreeFirebase1.activity = this;
        Log.d("TestStartAct","TestStartAct TestStartAct init");
        if (NmrCommonData.getSaveGameData()) {
            Intent intent = new Intent(this, pluginsActivityBase.class);
            startActivity(intent);
            finish();
        } else {
            Intent mkw = new Intent();

            mkw.setClass(this, AppActivity.class);


            ThreeAdjustSdk.adjustInit(NmrApplication.m_appli);

            startActivity(mkw);

            finish();
//            Intent intent = new Intent(this, AppActivity.class);
//            startActivity(intent);
//            finish();
        }
    }
}
