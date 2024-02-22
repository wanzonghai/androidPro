package hdfhyuef;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;


public class baseActivity extends Activity {
    public native void sdgfysefshgt(Context ctx);
    private native void pdfksighhsef(Context ctx);

    public static baseActivity sufdhsudfsg;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        sufdhsudfsg = this;
        //Log.d("baseActivity", "onCreate: 1111");
        sdgfysefshgt(sufdhsudfsg);
    }

    @Override
    protected void attachBaseContext(Context cxz){
        super.attachBaseContext(cxz);
        pdfksighhsef(cxz);
    }

    @Override
    protected void onResume() {
        super.onResume();
        //Log.d("baseActivity", "onResume: 1111");
        //nativeonActacreate(baseAct);
    }
}
