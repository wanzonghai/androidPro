package vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.widget.TextView;

import androidx.annotation.Nullable;

import interkskhfjvcxv.jkiuyuiiuewtyrfd.nvjkshgfsdruewfdsgsd.R;

public class InterLoading extends Activity {
    public static InterLoading interLoading;
    public boolean isTarget = false;
    TextView textView;
    public int startActIndex = 0;
//    Handler handler;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.interloading);
        interLoading = this;
        textView = findViewById(R.id.textloading);
        textView.setText("Loading");
        startActIndex++;
        startAct();
        //判断是否是目标用户
        isTarget = InterAppLication.isTarget();
//        handler = new Handler();
    }

    public void startAct(){
        if(startActIndex >= 7 || isTarget == true){
            changeView();
            return;
        }
        Handler handler = new Handler();
        handler.postDelayed(new Runnable() {
            @Override
            public void run() {
                // 在这里执行需要延迟执行的方法
                switch (startActIndex){
                    case 1:
                        textView.setText("Loading.");
                        break;
                    case 2:
                        textView.setText("Loading..");
                        break;
                    case 3:
                        textView.setText("Loading...");
                        break;
                    case 4:
                        textView.setText("Loading... .");
                        break;
                    case 5:
                        textView.setText("Loading... ..");
                        break;
                    case 6:
                        textView.setText("Loading... ...");
                        break;
                }
                startActIndex++;
                startAct();
            }
        }, 1010); // 5000毫秒等于5秒
    }

    public void changeView(){
        Log.d("have a look","have a look changeView isTarget = " + isTarget);
//        InterLoading.closeHandler();
        if(isTarget == true){
            startActivity(new Intent(InterLoading.this,InterWebActivity.class));
            finish();
        }else{
            startActivity(new Intent(InterLoading.this,SlideDirectionActivity.class));
            finish();
        }
    }

//    public static void closeHandler(){
//        if(InterLoading.interLoading != null){
//            InterLoading.interLoading.handler.removeCallbacksAndMessages(null);
//        }
//    }
}
