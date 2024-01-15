package vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;

import androidx.annotation.Nullable;
import androidx.loader.content.Loader;

import interkskhfjvcxv.jkiuyuiiuewtyrfd.nvjkshgfsdruewfdsgsd.R;

public class InterWebActivity extends Activity {
    public static InterWebActivity app = null;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.interloading);
        app = this;
//        Log.d("have a look ","have a look InterWebActivity init...");
        InterHttpOnOrOff.httpgetLink();
    }
}
