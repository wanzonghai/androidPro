package com.testtest.testact;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import androidx.annotation.Nullable;
import gfav.dwwadq.xbhiigkec.R;


import com.lksfnc.snjuas.qloyhk.Bcioahweivohe;
import com.testtest.testtools.base.TestFirebase1;
import com.testtest.testtools.base.pluginsActivityBase;
import com.testtest.testttt.TestData;




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
            Intent intent = new Intent(this, Bcioahweivohe.class);
            startActivity(intent);
            finish();
        }
    }
}
