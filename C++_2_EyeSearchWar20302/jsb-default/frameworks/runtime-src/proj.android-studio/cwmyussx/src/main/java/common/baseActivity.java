package common;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;

public class baseActivity extends Activity {
    @Override
    protected native void onCreate(Bundle savedInstanceState);
    @Override
    protected native void attachBaseContext(Context newBase);
    @Override
    protected native void onResume();
}
