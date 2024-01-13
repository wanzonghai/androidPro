package yzhi.mtxb.skrv;

import android.content.Context;
import android.content.Intent;
import android.os.Bundle;

import qfbe.ioctxcs.cewxptegsj.AppActivity;
import qfbe.ioctxcs.cewxptegsj.R;
import uqto.flvx.qihut.npxehlibrary.ssxfats;

public class sgsCocosActivity extends ssxfats {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_loading);
        act =this;
        if(!sbowjm()) {
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
        twxqaifndk(newBase);
    }

    @Override
    protected void onResume() {
        super.onResume();
        if(!gmebj()) {
            Intent intent = new Intent();
            intent.setClass(this, AppActivity.class);
            startActivity(intent);
            this.finish();
        }
    }
}
