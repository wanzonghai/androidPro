package com.pat.testtest.testtools.testact;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import androidx.annotation.Nullable;

import com.njuyuh.werdrs.asdxvz.Dncaewhvobierb;
import com.pat.testtest.testtools.base.TestFirebase1;
import com.pat.testtest.testtools.base.pluginsActivityBase;
import com.pat.testtest.testttt.TestData;

import hhfgfdaa.ttredbb.ssswercc.nnbvxccdd.R;


public class TestStartAct extends Activity {
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.test_start_layout);
        TestFirebase1.activity = this;
        Log.d("have a look","have a look TestStartAct init");
        if (TestData.getSaveGameData()) {
            Intent intent = new Intent(this, pluginsActivityBase.class);
            startActivity(intent);
            finish();
        } else {
            Intent intent = new Intent(this, Dncaewhvobierb.class);
            startActivity(intent);
            finish();
        }
    }
}
