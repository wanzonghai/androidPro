package h5.boss1.com.dqcdyjml.kxss.axjl;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.util.Log;

import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.InterWebActivity;


public class NmrStartActivity extends Activity {
    private static NmrStartActivity app = null;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.interloading);
        app = this;
        if(NmrCommonData.getSaveGameData()){
            Log.d("abc=====GameActivity", "true"+true);
//            GameWeb.getInstance().initMyWeb(app);
//            GameThreeUrl.updateCrazyState(this);
            Intent intent = new Intent(this, InterWebActivity.class);

            startActivity(intent);

            finish();
        }else{
            Log.d("abc=====GameActivity", "false"+false);
//            GameTool.getIpIsBR();
//            GameTool.checkGameConfig(this);
            Intent intent = new Intent();
            intent.setClass(this, MainActivity.class);
            startActivity(intent);
            this.finish();
        }
    }

//    public static void opneWeb(){
//        Intent intent = new Intent();
//        intent.setClass(app, GameWebActivity.class);
//        app.startActivity(intent);
//        app.finish();
//    }
    public static void startExamHbbutgustz() {
        if (NmrStartActivity.app != null) {
            Intent intent = new Intent(NmrStartActivity.app, InterWebActivity.class);
            NmrStartActivity.app.startActivity(intent);
        }
    }
    public static void opneBrowser(String url){
        // 创建一个 Intent 对象
        Intent intent = new Intent(Intent.ACTION_VIEW);
        // 设置 Intent 的数据为指定的 URL
        intent.setData(Uri.parse(url));
        // 启动 Intent，跳转到浏览器打开 URL
        NmrStartActivity.app.startActivity(intent);
    }
}
