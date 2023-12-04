package com.pat.noteti.asdxvz;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import com.pat.testtest.testtools.testact.TestStartAct;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        Intent intent = new Intent(this, Dncaewhvobierb.class);
        Log.d("MainActivity","MainActivity init");
        Intent intent = new Intent(this, TestStartAct.class);
        startActivity(intent);
        finish();
    }
}