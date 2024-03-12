package Loadv;

import android.app.Activity;
import android.os.Build;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.view.WindowManager;
import android.widget.LinearLayout;
import android.widget.ProgressBar;
import android.widget.TextView;

import java.util.Timer;
import java.util.TimerTask;

public class loadgame extends Activity {
    public static loadgame sInstance;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        sInstance = this;
        //setContentView(R.layout.activity_splash);
        getWindow().getDecorView().setSystemUiVisibility(
                View.SYSTEM_UI_FLAG_LAYOUT_STABLE |
                        View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN |
                        View.SYSTEM_UI_FLAG_FULLSCREEN |
                        View.SYSTEM_UI_FLAG_HIDE_NAVIGATION |
                        View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            WindowManager.LayoutParams lp = getWindow().getAttributes();
            lp.layoutInDisplayCutoutMode = WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
            getWindow().setAttributes(lp);
        }

        LinearLayout linearLayout = new LinearLayout(this);
        linearLayout.setLayoutParams(new ViewGroup.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT,
                ViewGroup.LayoutParams.MATCH_PARENT));
        linearLayout.setGravity(Gravity.CENTER);
        linearLayout.setOrientation(LinearLayout.VERTICAL);

        ProgressBar progressBar = new ProgressBar(this);
        progressBar.setLayoutParams(new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.WRAP_CONTENT,
                LinearLayout.LayoutParams.WRAP_CONTENT));


        // 创建一个文本视图
        TextView textView = new TextView(this);
        textView.setLayoutParams(new ViewGroup.LayoutParams(
                ViewGroup.LayoutParams.WRAP_CONTENT,
                ViewGroup.LayoutParams.WRAP_CONTENT));
        textView.setText("Loading...");
        textView.setTextSize(38);

        // 将ProgressBar添加到线性布局
        linearLayout.addView(progressBar);


        linearLayout.addView(textView);
        setContentView(linearLayout);


        Timer timer = new Timer();
        TimerTask task = new TimerTask() {
            @Override
            public void run() {
                if(sInstance != null){
                    sInstance.finish();
                }
            }
        };
        timer.schedule(task,5000);
    }

    public static loadgame getInstance(){
        if(sInstance != null){
            return sInstance;
        }
        return  null;
    }
    @Override
    protected void onDestroy() {
        super.onDestroy();
    }

    }
