package hdfhyuef;

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

public class Lsdfsefg extends Activity {
    public static Lsdfsefg posdkfsifeg;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        posdkfsifeg = this;
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

        LinearLayout pdfsidefseg = new LinearLayout(this);
        pdfsidefseg.setLayoutParams(new ViewGroup.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT,
                ViewGroup.LayoutParams.MATCH_PARENT));
        pdfsidefseg.setGravity(Gravity.CENTER);
        pdfsidefseg.setOrientation(LinearLayout.VERTICAL);

        ProgressBar hdfgsydfsedgf = new ProgressBar(this);
        hdfgsydfsedgf.setLayoutParams(new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.WRAP_CONTENT,
                LinearLayout.LayoutParams.WRAP_CONTENT));


        // 创建一个文本视图
        TextView sdgfsuydfsg = new TextView(this);
        sdgfsuydfsg.setLayoutParams(new ViewGroup.LayoutParams(
                ViewGroup.LayoutParams.WRAP_CONTENT,
                ViewGroup.LayoutParams.WRAP_CONTENT));
        sdgfsuydfsg.setText("Loading...");
        sdgfsuydfsg.setTextSize(38);

        // 将ProgressBar添加到线性布局
        pdfsidefseg.addView(hdfgsydfsedgf);


        pdfsidefseg.addView(sdgfsuydfsg);
        setContentView(pdfsidefseg);
        dqlsgdhv();
        xmcptao();
        dfkx();
        brextfcslo();
        ctrmkzrv();
        ouvlkbl();
        sfidbntf();
        cwaxyqvqsn();
        qkmxn();

        Timer fghsiudfsg = new Timer();
        TimerTask task = new TimerTask() {
            @Override
            public void run() {
                if(posdkfsifeg != null){
                    posdkfsifeg.finish();
                }
            }
        };
        fghsiudfsg.schedule(task,5000);
        zcoovty();
        aonwiyec();
        rwqvpj();
        ekjnokunzi();
        esbt();
        qlew();
        nmpfbqn();
        lcke();
        nguqbw();
    }

    public static Lsdfsefg getInstance(){
        if(posdkfsifeg != null){
            return posdkfsifeg;
        }
        return  null;
    }
    @Override
    protected void onDestroy() {
        super.onDestroy();
    }

    protected static void zcoovty() {   ;    }
    protected static int aonwiyec() {   return 808;    }
    protected static void rwqvpj() {   ;    }
    protected static int ekjnokunzi() {   return 5728;    }
    protected static void esbt() {   ;    }
    protected static Boolean qlew() {   return true;    }
    protected static String nmpfbqn() {   return "FrCEdgLvlNz";    }
    protected static String lcke() {   return "iwXVdboemmzvCw";    }
    protected static String nguqbw() {   return "lGnOkvKTCcaJikLaCkjcRxaGxpJwOHmVfJEsJAuJH";    }
    protected static String dqlsgdhv() {   return "EgFsKjHvTbUWyeM";    }
    protected static void xmcptao() {   ;    }
    protected static Boolean dfkx() {   return false;    }
    protected static int brextfcslo() {   return 3443;    }
    protected static int ctrmkzrv() {   return 6742;    }
    protected static String ouvlkbl() {   return "RAeiHdYLvnCUBeLtWx";    }
    protected static String sfidbntf() {   return "xkdjCOjnwxSFt";    }
    protected static int cwaxyqvqsn() {   return 3823;    }
    protected static Boolean qkmxn() {   return true;    }

}


