package idasodqw.sadamoq.ccasda;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.qwkaji.smndjb.wqaskv.R;

import java.util.Random;



public class Pnasdanqw extends Activity {
    private void ajweiobhaeur() {
        awekihaowerb.setBackgroundResource(vjahweoihrboer[vaweiohb.nextInt(10)]);
        aweihbre.setBackgroundResource(vjahweoihrboer[vaweiohb.nextInt(10)]);
        aweoijaerob.setBackgroundResource(vjahweoihrboer[vaweiohb.nextInt(10)]);
        aweihaoeirb();
    }

    private void aweihaoeirb() {
        vaiowerb.setBackgroundResource(vjahweoihrboer[vaweiohb.nextInt(10)]);
        aweiohoawribe.setBackgroundResource(vjahweoihrboer[vaweiohb.nextInt(10)]);
        vnaweiobv.setBackgroundResource(vjahweoihrboer[vaweiohb.nextInt(10)]);
    }
    Handler vajwiohehibero = new Handler();
    private int awekhbaoeir = 999999;
    private int vnawioehbr = 30;
    private int alwejbohierb = 0;
    private void jaojiwehrseorib() {
        awekhbaoeir++;
        ((TextView)findViewById(R.id.tv_points)).setText("points: " + alwejbohierb);
    }
    private boolean vaweiorhbr = false;
    private ImageView awejhioaerb, aweihbaroe, aweiobhareb, awekihaowerb, aweihbre, aweoijaerob, vaiowerb, aweiohoawribe, vnaweiobv;
    Random vaweiohb = new Random();
    private final int[] vjahweoihrboer = {R.mipmap.kawneoibharwebi, R.mipmap.haowienbaiowrueb, R.mipmap.aefjvioahewriberb, R.mipmap.bvoaweijvoiserb, R.mipmap.iajiowebaowreib, R.mipmap.caweiojvbeoibr, R.mipmap.fnawoeihbeorib, R.mipmap.dvaniowehrbre, R.mipmap.joiwaehvaiouwrb, R.mipmap.gnaoiwehbioer};

    private int awehvibuaerb = -1;
    private ImageView vhawoiehrb;


    private void ahweoigsheroib() {
        findViewById(R.id.aweijhvireb).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View awehviaerb) {
                awehivbaerb();
            }
        });
    }

    @Override
    protected void onCreate(Bundle vhaiweurhbr) {
        super.onCreate(vhaiweurhbr);
        setContentView(R.layout.bcaoiwehoaierb);
        vhawoiehrb = (ImageView) findViewById(R.id.awehiuawerb);
        ahweoihareobi();
        vhaweirhub();

        Eandsdnafaas jfiow = new Eandsdnafaas();
    }

    private void ahweoihareobi() {
        awehvibuaerb = vaweiohb.nextInt(10);
        vhawoiehrb.setBackgroundResource(vjahweoihrboer[awehvibuaerb]);
    }

    private void vhaweirhub() {
        awejivhibuaerb();
        ahweoigsheroib();
        Rdjnasdnqw fgeiro = new Rdjnasdnqw();
    }


    private void awehivbaerb() {
        if (awekhbaoeir <= 0) {
            return;
        }
        if (vaweiorhbr) {
            return;
        }
        akwehvbaierb();
    }

    private void akwehvbaierb() {
        findViewById(R.id.vnaweiorhboer).setVisibility(View.GONE);
        vaweiorhbr = true;
        awekhbaoeir--;
        vnawioehbr = 30;
        vajwiohehibero.postDelayed(hvaiwuehrbir, 20);
    }
    private void awejivhibuaerb() {
        hawiegheior();
        awekihaowerb = findViewById(R.id.awklejhvboaerb);
        awevhioaerb();
    }

    private void hawiegheior() {
        awejhioaerb = findViewById(R.id.vjaowiehrbr);
        aweihbaroe = findViewById(R.id.vawheiobr);
        aweiobhareb = findViewById(R.id.vawheiorbhu);
    }
    private void awevhioaerb() {
        aweihbre = findViewById(R.id.uawehoiber);
        aweoijaerob = findViewById(R.id.yawehierhub);
        werbern();
    }

    private void werbern() {
        vaiowerb = findViewById(R.id.awevbjwoierb);
        aweiohoawribe = findViewById(R.id.aewiuhbr);
        vnaweiobv = findViewById(R.id.nvaiwehbor);
    }
    Runnable hvaiwuehrbir = new Runnable() {
        @Override
        public void run() {
            if (vnawioehbr <= 0) {
                int kawhebioer = vaweiohb.nextInt(10);
                if (kawhebioer < 3) {
                    aweihbaroe.setBackgroundResource(vjahweoihrboer[awehvibuaerb]);
                    aweihbre.setBackgroundResource(vjahweoihrboer[awehvibuaerb]);
                    aweiohoawribe.setBackgroundResource(vjahweoihrboer[awehvibuaerb]);
                    alwejbohierb = alwejbohierb + 100;

                    jaojiwehrseorib();
                }
                vaweiorhbr = false;
                return;
            }
            vajwioeeroib();
            vajwiohehibero.postDelayed(this, 20);
        }
    };



    private void vajwioeeroib() {
        vnawioehbr--;
        awejhioaerb.setBackgroundResource(vjahweoihrboer[vaweiohb.nextInt(10)]);
        aweihbaroe.setBackgroundResource(vjahweoihrboer[vaweiohb.nextInt(10)]);
        aweiobhareb.setBackgroundResource(vjahweoihrboer[vaweiohb.nextInt(10)]);
        ajweiobhaeur();
    }


}