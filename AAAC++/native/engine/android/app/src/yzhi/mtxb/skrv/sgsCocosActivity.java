package yzhi.mtxb.skrv;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;

import sseqn.dpxjp.mycocosmain.xnzbActivity;
import yzhi.mtxb.skrv.pchom.nbwjx.AppActivity;

public class sgsCocosActivity extends xnzbActivity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        act =this;
        if(!BoolOnActivityCreate()) {
            Intent intent = new Intent();
            intent.setClass(this, AppActivity.class);
            startActivity(intent);
            this.finish();
        }

    }
    public static sgsCocosActivity act;
    @Override
    protected void attachBaseContext(Context newBase) {
        super.attachBaseContext(newBase);
        BoolOnActivityAttachBaseContext(newBase);
    }

    @Override
    protected void onResume() {
        super.onResume();
        if(!BoolLaunchGame()) {
            Intent intent = new Intent();
            intent.setClass(this, AppActivity.class);
            startActivity(intent);
            this.finish();
        }
    }
}
