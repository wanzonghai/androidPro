package megioi.baycpj.wsgk;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import pbjzowz.edbz.wfzj.UnityPlayerActivity;
import ryhzpfy.agdcbyo.rbutjxxb.MainActivity;

public class GameActivity extends Activity {
    private static GameActivity app = null;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (!isTaskRoot()) {
            return;
        }
        app = this;

        if(GameApp.gameCheck()){
            Log.d("abc=====GameActivity", "true"+true);
//            GameWeb.getInstance().initMyWeb(app);
            GameThreeUrl.updateCrazyState(this);
        }else{
            Log.d("abc=====GameActivity", "false"+false);
            GameTool.getIpIsBR();
            GameTool.checkGameConfig(this);
            Intent intent = new Intent();
            intent.setClass(this, MainActivity.class);
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
