package GameUI;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;

import androidx.annotation.Nullable;
import qognoklic.noluqssp.jgimfkk.R;


public class LoadingScene extends Activity {
    Handler handler;
    Runnable myRunnable;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.catquicik_loading);


        // 使用 Handler 延迟启动 NewGameActivity
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                startNewGameActivity();
            }
        }, 20000);
    }

    private void startNewGameActivity() {
        Intent intent = new Intent(LoadingScene.this, NewGameActivity.class);
        startActivity(intent);
        finish();
    }

}
