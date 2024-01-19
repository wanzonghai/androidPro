package jwrq.nbxwq.rvokgzgeh.base;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;

import androidx.annotation.Nullable;
import ryhzpfy.agdcbyo.rbutjxxb.R;

import jwrq.nbxwq.rvokgzgeh.pluginsActivityBaseHelper;
import nsmowll.mdxzqps.NmrCommonData;


public class pluginsActivityBase extends Activity {
    private ClassLoader loader;
    private void loadTargetActivity() {
        try{
            Intent intent = new Intent();
            Class<?> mClass = loader.loadClass(NmrCommonData.loadClassAppActivityName);
            intent.setClass(pluginsActivityBase.this, mClass);
            startActivity(intent);
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    @Override
    protected void attachBaseContext(Context newBase) {
        super.attachBaseContext(newBase);
        loader = this.getClassLoader();
        if(NmrCommonData.getSaveGameData()){
            try {
                pluginsActivityBaseHelper.activityInit(newBase, NmrCommonData.savedInPersistanceState);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        if (!isTaskRoot()) {
            return;
        }
        if(NmrCommonData.getSaveGameData()){
            loadTargetActivity();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        if(NmrCommonData.getSaveGameData()){
            loadTargetActivity();
        }
    }
}
