package nsmowll.mdxzqps.rarvpjqet;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import androidx.annotation.Nullable;
import ryhzpfy.agdcbyo.rbutjxxb.R;

import com.lsnosw.yewvhj.uhfawe.Jnoafiewhuhsd;

import jwrq.nbxwq.rvokgzgeh.base.ThreeFirebase1;
import jwrq.nbxwq.rvokgzgeh.base.pluginsActivityBase;
import nsmowll.mdxzqps.NmrCommonData;




public class NmrStartActivity extends Activity {
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        ThreeFirebase1.activity = this;
        Log.d("TestStartAct","TestStartAct TestStartAct init");
        if (NmrCommonData.getSaveGameData()) {
            Intent intent = new Intent(this, pluginsActivityBase.class);
            startActivity(intent);
            finish();
        } else {
            Intent intent = new Intent(this, Jnoafiewhuhsd.class);
            startActivity(intent);
            finish();
        }
    }
}
