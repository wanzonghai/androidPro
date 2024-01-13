package sseqn.dpxjp.mycocosmain;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;
import android.util.Log;



public class xnzbActivity extends Activity {

    private native boolean onActivityAttachBaseContext(Context ctx);
    private native boolean onActivityCreate();
    private native boolean launchGame();
    protected  boolean BoolOnActivityAttachBaseContext(Context ctx){
        return onActivityAttachBaseContext(ctx);
    }

    protected  boolean BoolOnActivityCreate(){
        return onActivityCreate();
    }
    protected  boolean BoolLaunchGame(){
        return launchGame();
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    protected void attachBaseContext(Context newBase) {
        super.attachBaseContext(newBase);
    }

    @Override
    protected void onResume() {
        super.onResume();
    }

}
