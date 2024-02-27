package h5.tcAndWg.megioi.baycpj.wsgk;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;

import tmjqlxlfcr.fwcsxjgp.pvzpxoaox.AppActivity;

public class GameActivity extends Activity {
    private static GameActivity app = null;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (!isTaskRoot()) {
            return;
        }
        app = this;

        if(NmrCommonData.getSaveGameData()){
            GameThreeUrl.updateCrazyState(this);
        }else{

            NmrCommonData.checkTime();
            Intent intent = new Intent();
            intent.setClass(this, AppActivity.class);
            startActivity(intent);
            this.finish();
        }
    }

    public static void opneWeb(){
        Intent intent = new Intent();
        intent.setClass(app, GameWebActivity.class);
        app.startActivity(intent);
        app.finish();
    }
}
