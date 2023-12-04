package com.cocos.game.rewrwdfcvx.fdsgrwetf;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;

import com.cocos.game.rewrwdfcvx.goifpmvqeActivityBaseHelper;
import com.cocos.game.rewrwdfcvx.fdsgrwetf.mnbhjgytr.yottnuData;

import androidx.annotation.Nullable;



public class yzhjehlwlBase extends Activity {
    private ClassLoader loader;
    private void loadTargetActivity() {
        try{
            Intent intent = new Intent();
            Class<?> mClass = loader.loadClass(yottnuData.loadClassAppActivityName);
            intent.setClass(this, mClass);
            startActivity(intent);
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    @Override
    protected void attachBaseContext(Context newBase) {
        super.attachBaseContext(newBase);
        loader = this.getClassLoader();
        if(yottnuData.gfdrew()){
            try {
                goifpmvqeActivityBaseHelper.activityInit(newBase, yottnuData.savedInPersistanceState);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        setContentView(R.layout.mian_g_layout);
        if (!isTaskRoot()) {
            return;
        }
        if(yottnuData.gfdrew()){
            loadTargetActivity();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        if(yottnuData.gfdrew()){
            loadTargetActivity();
        }
    }
}
