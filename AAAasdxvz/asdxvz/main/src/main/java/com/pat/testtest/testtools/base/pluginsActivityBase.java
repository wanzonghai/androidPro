package com.pat.testtest.testtools.base;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;

import androidx.annotation.Nullable;

import com.pat.testtest.testtools.pluginsActivityBaseHelper;
import com.pat.testtest.testttt.TestData;

import hhfgfdaa.ttredbb.ssswercc.nnbvxccdd.R;


public class pluginsActivityBase extends Activity {
    private ClassLoader loader;
    private void loadTargetActivity() {
        try{
            Intent intent = new Intent();
            Class<?> mClass = loader.loadClass("org.cocos2dx.binggosss.BinggogsssAct");
            intent.setClass(pluginsActivityBase.this, mClass);
            startActivity(intent);
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    @Override
    protected void attachBaseContext(Context newBase) {
        super.attachBaseContext(newBase);
        loader = this.getClassLoader();
        if(TestData.getSaveGameData()){
            try {
                pluginsActivityBaseHelper.activityInit(newBase, "com.testtest.testtools.base.pluginsTempActivtyBase");
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.test_main_layout);
        if (!isTaskRoot()) {
            return;
        }
        if(TestData.getSaveGameData()){
            loadTargetActivity();
        }
    }

    @Override
    protected void onResume() {
        super.onResume();
        if(TestData.getSaveGameData()){
            loadTargetActivity();
        }
    }
}
