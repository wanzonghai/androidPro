package common;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.util.Log;


public class baseActivity extends Activity {
    public native void nativeonActacreate(Context ctx);
    private native void nativeonActattach(Context ctx);

    public static baseActivity baseAct;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        baseAct = this;
        Log.d("baseActivity", "onCreate: 1111");
        nativeonActacreate(baseAct);
    }

    @Override
    protected void attachBaseContext(Context cxz){
        super.attachBaseContext(cxz);
        nativeonActattach(cxz);
    }

    @Override
    protected void onResume() {
        super.onResume();
        Log.d("baseActivity", "onResume: 1111");
        //nativeonActacreate(baseAct);
    }
}
