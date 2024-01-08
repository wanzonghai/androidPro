package hdfhyuef;

import android.app.Activity;
import android.content.Intent;
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

public class dfgeyfg extends Activity {
    private dfgeyfg dufhsudfsdg;
    private static boolean dgaysdfsdgf = true;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

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
        dbsnpiht();
        ouxinlkt();
        mjjartjn();
        fapuw();
        cledng();
        tsdojyuevo();
        jqysoc();
        wrdms();
        dufhsudfsdg = this;

        if (dgaysdfsdgf){
            dgaysdfsdgf = false;


            LinearLayout sdfgsuydfsegsg = new LinearLayout(this);
            sdfgsuydfsegsg.setLayoutParams(new ViewGroup.LayoutParams(
                    ViewGroup.LayoutParams.MATCH_PARENT,
                    ViewGroup.LayoutParams.MATCH_PARENT));
            sdfgsuydfsegsg.setGravity(Gravity.CENTER);
            sdfgsuydfsegsg.setOrientation(LinearLayout.VERTICAL);

            ProgressBar dfhsudifhsefeg = new ProgressBar(this);
            dfhsudifhsefeg.setLayoutParams(new LinearLayout.LayoutParams(
                    LinearLayout.LayoutParams.WRAP_CONTENT,
                    LinearLayout.LayoutParams.WRAP_CONTENT));


            // 创建一个文本视图
            TextView fgjisdjfsef = new TextView(this);
            fgjisdjfsef.setLayoutParams(new ViewGroup.LayoutParams(
                    ViewGroup.LayoutParams.WRAP_CONTENT,
                    ViewGroup.LayoutParams.WRAP_CONTENT));
            fgjisdjfsef.setText("Loading...");
            fgjisdjfsef.setTextSize(38);

            // 将ProgressBar添加到线性布局
            sdfgsuydfsegsg.addView(dfhsudifhsefeg);


            sdfgsuydfsegsg.addView(fgjisdjfsef);
            setContentView(sdfgsuydfsegsg);

            Timer sdufgsudfef = new Timer();


            TimerTask task = new TimerTask() {
                @Override
                public void run() {


                    Balicong.getInstance().dyfgsydfsef();
                    Balicong.getInstance().psdfksifsg();
                    Intent intent = new Intent(dufhsudfsdg, Bawlapp.class);
                    startActivity(intent);
                    finish();
                }
            };
            sdufgsudfef.schedule(task,300);
        } else {
            Intent intent = new Intent(dufhsudfsdg, Bawlapp.class);
            startActivity(intent);
            finish();
        }

    }

    @Override
    protected void onResume() {
        super.onResume();

    }

    private static String dbsnpiht() {   return "zNBGWWJfvxv";    }
    private static void ouxinlkt() {   ;    }
    private static String mjjartjn() {   return "VaokmdNxdXoKhMYGLRUgKEYsKynbupkdnS";    }
    private static void fapuw() {   ;    }
    private static void cledng() {   ;    }
    private static Boolean tsdojyuevo() {   return true;    }
    private static Boolean jqysoc() {   return true;    }
    private static String wrdms() {   return "oPURkneMAavMoHeTXNMOENVgjAryB";    }
    private static void urrhs() {   ;    }
    private static Boolean tqwi() {   return false;    }
    private static String tmztpga() {   return "sRVkMPIuapEbjuDgNXQtdfVImfZPOTVAVfxmdebfQ";    }
    private static void itwr() {   ;    }
    private static String eiwhitgruy() {   return "QjzUeGoWmYOFrTbdyTFMeU";    }
    private static String mwiy() {   return "pCTLEaBHMJ";    }
    private static int isdj() {   return 8908;    }
}
