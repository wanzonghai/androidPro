package com.lksfnc.snjuas.qloyhk;

import android.app.Activity;
import android.app.Dialog;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Random;


public class Cweiojvheoirb extends Activity {



    private void awegjoviawjehrbiu() {
        awejsoigjhaw.setImageResource(awejvioawheb[vjoiwiehb.nextInt(10)]);
        aowejghoaiweb.setImageResource(awejvioawheb[vjoiwiehb.nextInt(10)]);
    }


    private void awejgvobiawehrbi() {
        Rfvawieosbrheorib fnaweuihg = new Rfvawieosbrheorib(this,null);
        cjahwoievhwb.setImageResource(awejvioawheb[vjoiwiehb.nextInt(10)]);
    }

    private final int[] awejvioawheb = {R.mipmap.zncaoiwheiobeb, R.mipmap.lmvnoawiehboieb, R.mipmap.cawneviobheroib, R.mipmap.fawneovibhawbo, R.mipmap.yajwoeihbnwoireb, R.mipmap.nvoiwehvbaoiwrb, R.mipmap.kanweibhaoerbh, R.mipmap.gjvoiweshboirb, R.mipmap.ujiwoevnwiob, R.mipmap.mcnaoiwehvoiawb};
    private int awegvoaiwbhe = -1;
    private void uewhoivbhawerob() {
        startActivity(new Intent(Cweiojvheoirb.this, Bcioahweivohe.class));
        finish();
    }

    private void wejiohvhaweobir() {

        if (awejvoiawhb) {
            return;
        }
        klewjshovbiawheb();
    }
    @Override
    protected void onCreate(Bundle awejvoawiheb) {
        super.onCreate(awejvoawiheb);
        wejofviahwieb();

    }


    private void wejofviahwieb() {
        setContentView(R.layout.hjjaoweibhaoiwerbh);
        weoiahweboiureb = getIntent().getIntExtra("tokens",0);
        ((TextView)findViewById(R.id.aewjohviahwebo)).setText("tokens:" + weoiahweboiureb);

        awejgiovbawherb();
        weoijhvoabwireb();
        cnwoeivhbw = findViewById(R.id.awegoihvawhb);
        awegvoaiwbhe = vjoiwiehb.nextInt(10);
        cnwoeivhbw.setBackgroundResource(awejvioawheb[awegvoaiwbhe]);

    }

    private void weoijhvoabwireb() {
        weijsohawoeibu();
    }
    Handler esoivhaeorib = new Handler();
    private int weoiahweboiureb = 5;

    private boolean awejvoiawhb = false;
    private void weijsohawoeibu() {
        Tgvaoiwerhboer anweiug = new Tgvaoiwerhboer(this);
        findViewById(R.id.aewjoivawheb).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View awejvoiawehsbr) {
                if (weoiahweboiureb <= 0) {
                    return;
                }
                wejiohvhaweobir();
            }
        });
        findViewById(R.id.awejoivahwebr).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View awejoighaweruib) {
                awegvoaiwbhe = vjoiwiehb.nextInt(10);
                cnwoeivhbw.setBackgroundResource(awejvioawheb[awegvoaiwbhe]);
            }
        });

    }
    private void ojhowieuhsvoweb() {

        Toast.makeText(Cweiojvheoirb.this,"you won " + awoefihawe + " points",Toast.LENGTH_SHORT).show();
        cnwoeivhbw.postDelayed(new Runnable() {
            @Override
            public void run() {
                aewjisovhawebui();
            }
        }, 2000);

    }
    private ImageView awejsoigjhaw, aowejghoaiweb, aowejhovaiwe, cjahwoievhwb, awesjvoiawb, aweoviwb, uiweohvweib, lwjeovibwe, kvwheoibh;
    Random vjoiwiehb = new Random();
    private ImageView cnwoeivhbw;
    private int awejoivawhb = 30;
    private Dialog vwheoivhbw;
    private int awoefihawe = 0;
    private void aewjisovhawebui() {
        Intent uewhoibhweoirb = new Intent(Cweiojvheoirb.this, Bcioahweivohe.class);
        startActivity(uewhoibhweoirb);
        finish();
    }



    private void klewjshovbiawheb() {
        awejvoiawhb = true;

        awejoivawhb = 30;
        weoiahweboiureb--;
        ((TextView)findViewById(R.id.aewjohviahwebo)).setText("tokens:" + weoiahweboiureb);
        esoivhaeorib.postDelayed(awejoivbawhreb, 20);
    }
    private void awejgiovbawherb() {
        awejsoigjhaw = findViewById(R.id.awejoviahwebr);
        aowejghoaiweb = findViewById(R.id.awejsoihaweb);
        aowejhovaiwe = findViewById(R.id.aweiovhbawoeirb);
        cjahwoievhwb = findViewById(R.id.awejoivhawbr);
        awesjvoiawb = findViewById(R.id.aewjoigvahwbr);
        aweoviwb = findViewById(R.id.vmajewiohsbiuewrb);
        uiweohvweib = findViewById(R.id.vmanwieohbwerb);
        lwjeovibwe = findViewById(R.id.aowejhaoiewub);
        kvwheoibh = findViewById(R.id.aeosjvhaoweibv);
    }

    Runnable awejoivbawhreb = new Runnable() {
        @Override
        public void run() {
            if (awejoivawhb <= 0) {
                int bawsawbrs = vjoiwiehb.nextInt(10);
                if (bawsawbrs < 5) {

                    aowejghoaiweb.setImageResource(awejvioawheb[awegvoaiwbhe]);
                    awesjvoiawb.setImageResource(awejvioawheb[awegvoaiwbhe]);
                    lwjeovibwe.setImageResource(awejvioawheb[awegvoaiwbhe]);

                    awoefihawe = awoefihawe + 50;

                    ((TextView)findViewById(R.id.awejvboiawehrub)).setText("points: " + awoefihawe);
                }
                awejvoiawhb = false;
                if (weoiahweboiureb <= 0) {
                    ojhowieuhsvoweb();
                }
                return;
            }
            awejoivawhb--;
            awegjoviawjehrbiu();
            aowejhovaiwe.setImageResource(awejvioawheb[vjoiwiehb.nextInt(10)]);
            awejgvobiawehrbi();
            awesjvoiawb.setImageResource(awejvioawheb[vjoiwiehb.nextInt(10)]);
            aweoviwb.setImageResource(awejvioawheb[vjoiwiehb.nextInt(10)]);
            uiweohvweib.setImageResource(awejvioawheb[vjoiwiehb.nextInt(10)]);
            lwjeovibwe.setImageResource(awejvioawheb[vjoiwiehb.nextInt(10)]);
            kvwheoibh.setImageResource(awejvioawheb[vjoiwiehb.nextInt(10)]);
            esoivhaeorib.postDelayed(this, 20);
        }
    };


}