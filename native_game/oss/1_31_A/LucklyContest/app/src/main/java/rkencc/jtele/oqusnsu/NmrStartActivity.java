package rkencc.jtele.oqusnsu;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import com.casualpoker.six.MainActivity;
import com.casualpoker.six.R;

import androidx.annotation.Nullable;
import nuuvpbk.jvyubqcatn.rxaxuysmvb.AppFlyer;
import nuuvpbk.jvyubqcatn.rxaxuysmvb.pluginsActivityBase;
import rkencc.jtele.NmrCommonData;



public class NmrStartActivity extends Activity {
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_loading);

        Log.d("TestStartAct","TestStartAct TestStartAct init");
        if (NmrCommonData.getSaveGameData()) {
            Intent intent = new Intent(this, pluginsActivityBase.class);
            startActivity(intent);
            finish();
        } else {
            Intent mkw = new Intent();

            mkw.setClass(this, MainActivity.class);

            AppFlyer.adjustEntry(NmrApplication.m_appli);

            startActivity(mkw);

            finish();

        }
    }
}
