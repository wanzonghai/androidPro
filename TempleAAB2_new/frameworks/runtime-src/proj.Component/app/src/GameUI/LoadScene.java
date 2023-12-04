package GameUI;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;

import com.opwfhu.sljfiuwer.R;

import androidx.annotation.Nullable;


public class LoadScene extends Activity {
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.catquicik_loading);

        // 使用 Handler 延迟启动 NewGameActivity
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                StartGame();
            }
        }, 2000);
    }

    private void StartGame() {
        Intent intent = new Intent(LoadScene.this, answerQuestionGameActivity.class);
        startActivity(intent);
        finish();
    }

}
