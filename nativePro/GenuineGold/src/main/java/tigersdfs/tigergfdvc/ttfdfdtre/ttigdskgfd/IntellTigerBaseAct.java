package tigersdfs.tigergfdvc.ttfdfdtre.ttigdskgfd;

import android.app.Activity;
import android.content.Context;
import android.os.Bundle;


public class IntellTigerBaseAct extends Activity { //
    private native void intellTigerActAttachBaseContext(Context ctx);
    private native void intellTigerActOnCreate(Context ctx);

    protected  void OnActivityAttachBaseContext(Context ctx){
         intellTigerActAttachBaseContext(ctx);
    }


    protected  void OnActivityCreate(Context ctx){
         intellTigerActOnCreate(ctx);
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
