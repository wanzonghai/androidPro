package com.lsnosw.yewvhj.uhfawe;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.widget.ImageView;
import android.widget.TextView;

import java.util.Random;

public class Dbawiefuaiuh extends AppCompatActivity{
    private int[] zsdhiuhsdiufs = {
            R.drawable.sduhjhfeaw, R.drawable.gcabewfjiiawe, R.drawable.qknklweafhoiha, R.drawable.ygfejbfdsjjsd,
            R.drawable.ndioawhofihaw, R.drawable.dshfabjehfia, R.drawable.cnoiahweofuhaw, R.drawable.bcwanjesdjbijs,
            R.drawable.mcnajewfhiuhasd, R.drawable.dyghabefisa, R.drawable.dnkkosihdoihas, R.drawable.ewkfijaiohas
    };
    private TextView njifhihaids;
    private TextView jeiofhawhfsfdu;
    private ImageView dshghsd;
    private ImageView dshkjhsdks;
    private Random bckadmkljsd = new Random();
    private ImageView jediohaeoihf, sduhhkjsd, dsbahigsfd;
    private int[] sduzhjkhsdds = new int[3];
    private int sjndhjhsiud;
    private int uahefjkahfha = 10;
    private int sdhzhduis;

    @Override
    protected void onCreate(Bundle haeiufhiafus) {
        super.onCreate(haeiufhiafus);
        setContentView(R.layout.dshkjbzsdiszd);
        uihaskjdhhjjs();
    }

    private void uihaskjdhhjjs() {
        njifhihaids = findViewById(R.id.sdjhijhzsdis);
        jeiofhawhfsfdu = findViewById(R.id.uheawfiufasi);
        dshghsd = findViewById(R.id.jidohaofieha);
        dshkjhsdks = findViewById(R.id.sduhiuhsfuisw);
        jediohaeoihf = findViewById(R.id.wabefuiaa);
        sduhhkjsd = findViewById(R.id.mcnafejohhs);
        dsbahigsfd = findViewById(R.id.sdhkjshifuhs);
        sdhzhduis = bckadmkljsd.nextInt(zsdhiuhsdiufs.length);
        dshkjhsdks.setImageResource(zsdhiuhsdiufs[sdhzhduis]);
        dshghsd.setOnClickListener(sdzjjhzsdji -> {
            dshghsd.setEnabled(false);
            uahefjkahfha--;
            jeiofhawhfsfdu.setText(""+ uahefjkahfha);
            sduigkjbhdkhdz.start();
        });
    }
    private CountDownTimer sduigkjbhdkhdz = new CountDownTimer(1500, 100) {
        @Override
        public void onTick(long sdhjihdi) {
            sduzhjkhsdds[0]= bckadmkljsd.nextInt(zsdhiuhsdiufs.length);
            sduzhjkhsdds[1]= bckadmkljsd.nextInt(zsdhiuhsdiufs.length);
            sduzhjkhsdds[2]= bckadmkljsd.nextInt(zsdhiuhsdiufs.length);
            jediohaeoihf.setImageResource(zsdhiuhsdiufs[sduzhjkhsdds[0]]);
            sduhhkjsd.setImageResource(zsdhiuhsdiufs[sduzhjkhsdds[1]]);
            dsbahigsfd.setImageResource(zsdhiuhsdiufs[sduzhjkhsdds[2]]);
        }

        @Override
        public void onFinish() {
            dshghsd.setEnabled(true);
            if (sdhzhduis == sduzhjkhsdds[0]) {
                sjndhjhsiud += 20;
            } else if (sdhzhduis == sduzhjkhsdds[1]) {
                sjndhjhsiud += 10;
            } else if (sdhzhduis == sduzhjkhsdds[2]) {
                sjndhjhsiud += 5;
            }
            njifhihaids.setText(""+ sjndhjhsiud);
            if (uahefjkahfha == 0) {
                sdnjohdiufhfusisdo("You earned a total of " + sjndhjhsiud + " points");
            } else {
                sdhzhduis = bckadmkljsd.nextInt(zsdhiuhsdiufs.length);
                dshkjhsdks.setImageResource(zsdhiuhsdiufs[sdhzhduis]);
            }
        }
    };

    private void sdnjohdiufhfusisdo(String dshzhsdziuhs) {
        new AlertDialog.Builder(this).setTitle(dshzhsdziuhs).setPositiveButton("end", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface ebwghguigasdui, int sdghigdsi) {
                startActivity(new Intent(Dbawiefuaiuh.this, Jnoafiewhuhsd.class));
                finish();
            }
        }).show();
    }
}