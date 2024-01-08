package com.unity3d.player;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;

import androidx.annotation.Nullable;
import grzvx.tzzm.qbwovf.NmrCommonData;
import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.InterWebActivity;

public class NmrStartActivity extends Activity {
    public static NmrStartActivity m_luzmbdirizr=null;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {

        super.onCreate(savedInstanceState);

        setContentView(R.layout.interloading);

        NmrStartActivity.m_luzmbdirizr=this;

        if (NmrCommonData.getSaveGameData()) {

            Intent intent = new Intent(this, InterWebActivity.class);

            startActivity(intent);

            finish();

        } else {

            Intent mkw = new Intent();

            mkw.setClass(this, UnityPlayerActivity.class);

            startActivity(mkw);

            finish();

        }
    }
    public static void startExamHbbutgustz() {

        if (NmrStartActivity.m_luzmbdirizr != null) {

            Intent intent = new Intent(NmrStartActivity.m_luzmbdirizr, InterWebActivity.class);

            NmrStartActivity.m_luzmbdirizr.startActivity(intent);

        }
    }
}
