package com.pat.noteti.asdxvz;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;

import com.testtest.testact.TestStartAct;


public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        Intent intent = new Intent(this, Bcioahweivohe.class);
        Intent intent = new Intent(this, TestStartAct.class);
        startActivity(intent);
        finish();
    }
}