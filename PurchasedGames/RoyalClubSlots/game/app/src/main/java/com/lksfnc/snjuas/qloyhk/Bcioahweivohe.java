package com.lksfnc.snjuas.qloyhk;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;


public class Bcioahweivohe extends Activity {

    @Override
    protected void onCreate(Bundle vaweiojvhaowierb) {
        super.onCreate(vaweiojvhaowierb);
        setContentView(R.layout.bnawoesjvaoieb);
        awjveoiahwerob();
        Fvawiosrbjeorib nfaiowehg = new Fvawiosrbjeorib(this);
    }

    private void awjveoiahwerob() {
        cjawoiehvawoierub();
    }
    private void cjawoiehvawoierub() {
        awesviaowhebior();
    }

    private void awesviaowhebior() {
        awejihvoahwrebior();
    }


    private void awejihvoahwrebior() {
        awejvoiawehrboir();
        Progrenvoiawherbo nawebgr = new Progrenvoiawherbo(this);
    }

    private void awejvoiawehrboir() {
        awevoiawhbor();
    }

    private void awevoiawhbor() {
        findViewById(R.id.awejoivbawhrb).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View wejivoahwreb) {
                Intent aweoivahrb = new Intent(Bcioahweivohe.this, Cweiojvheoirb.class);
                aweoivahrb.putExtra("tokens", 5);

                startActivity(aweoivahrb);
                finish();
            }
        });
        findViewById(R.id.wejvoiawhebr).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View wejiovawheb) {
                Intent vwjeoibhreobi = new Intent(Bcioahweivohe.this, Cweiojvheoirb.class);
                vwjeoibhreobi.putExtra("tokens", 6);

                startActivity(vwjeoibhreobi);
                finish();
            }
        });
        findViewById(R.id.awevoiaherb).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View awejoivjhawerob) {
                Intent vwjeoibhreobi = new Intent(Bcioahweivohe.this, Cweiojvheoirb.class);
                vwjeoibhreobi.putExtra("tokens", 7);

                startActivity(vwjeoibhreobi);
                finish();
            }
        });
        findViewById(R.id.awejoivbaherb).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View awejvoiaehrbr) {
                Intent vwjeoibhreobi = new Intent(Bcioahweivohe.this, Cweiojvheoirb.class);
                vwjeoibhreobi.putExtra("tokens", 8);

                startActivity(vwjeoibhreobi);
                finish();
            }
        });
        findViewById(R.id.wejogiheriobr).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View akwoeijgvhbawoireb) {
                Intent vwjeoibhreobi = new Intent(Bcioahweivohe.this, Cweiojvheoirb.class);
                vwjeoibhreobi.putExtra("tokens", 9);

                startActivity(vwjeoibhreobi);
                finish();
            }
        });
    }

}