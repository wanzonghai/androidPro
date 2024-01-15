package vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc;

import android.app.Activity;
import android.os.Bundle;

import androidx.annotation.Nullable;
import com.jkpxxmle.mylibrary.R;


public class InterWebActivity extends Activity {
    public static InterWebActivity app = null;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.interloading);
        app = this;

        OkHttpHelper.httpGetLink();
    }

}
