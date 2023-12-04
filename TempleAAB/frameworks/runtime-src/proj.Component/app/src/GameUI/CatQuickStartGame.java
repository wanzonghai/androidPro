package GameUI;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;

import androidx.annotation.Nullable;
import qognoklic.noluqssp.jgimfkk.R;


public class CatQuickStartGame extends Activity {
    Handler handler;
    Runnable myRunnable;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.catquicik_start_layout);
        findViewById(R.id.catqucik_start).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

//                startActivity(new Intent(CatQuickStartGame.this, CatQuickGameGame.class));//game1
                startActivity(new Intent(CatQuickStartGame.this, LoadingScene.class));//game2
                finish();
            }
        });

//        findViewById(R.id.catqucik_btn).setOnClickListener(new View.OnClickListener() {
//            @Override
//            public void onClick(View v) {
//                if(handler != null){
//                    handler.removeCallbacks(myRunnable);
//                }
//                finishAffinity();
//                finish();
//            }
//        });
    }

}
