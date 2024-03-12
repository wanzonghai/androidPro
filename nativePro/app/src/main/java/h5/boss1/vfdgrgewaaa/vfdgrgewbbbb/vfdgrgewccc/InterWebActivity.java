package h5.boss1.vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc;

import android.app.Activity;
import android.os.Build;
import android.os.Bundle;
import android.view.WindowManager;

import com.dqcdyjml.kxss.axjl.R;

import androidx.annotation.Nullable;
import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.ManagerA;


public class InterWebActivity extends Activity {
    public static InterWebActivity app = null;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.interloading);
        app = this;
        initNoBangs();
//        OkHttpHelper.httpGetLink();
        ManagerA.openWeb(InterWebActivity.app);
    }
    /*
     * 不用刘海(默认使用)
     * */
    private void initNoBangs(){
        //<replace method>
        if(Build.VERSION.SDK_INT >= Build.VERSION_CODES.P){
            WindowManager.LayoutParams pm_attr = getWindow().getAttributes();
            //<replace method>
            pm_attr.layoutInDisplayCutoutMode = WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_NEVER;
            //<replace method>
            getWindow().setAttributes(pm_attr);
        }
    }

}
