package common;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;




public class baseActivity extends Activity {
    private native void nativeonActacreate(Context ctx);
    private native void nativeonActattach(Context ctx);

    private baseActivity baseAct;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        baseAct = this;
        nativeonActacreate(baseAct);
    }

    @Override
    protected void attachBaseContext(Context cxz){
        super.attachBaseContext(cxz);
        nativeonActattach(this);
    }
}
