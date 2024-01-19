package com.joaisd.whuakg.dfgwom;

import androidx.appcompat.app.AppCompatActivity;

import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.widget.TextView;

public class Whfhjfdjhhigr extends AppCompatActivity implements Fwquherjnisdxjh {
    private Nbuwaeobjkd knaewjfnoijasdiof;
    private TextView awekjfoijafsdio;
    private int fnaiohfjzks = -1;
    @Override
    protected void onCreate(Bundle aweiufkjdzsl) {
        super.onCreate(aweiufkjdzsl);
        setContentView(R.layout.lcmkasfdjoids);
        knaewjfnoijasdiof = findViewById(R.id.kjefoakjadshjfkas);
        awekjfoijafsdio = findViewById(R.id.asjdnijhdsijz);
        knaewjfnoijasdiof.setGameOverListener(this);
        kawenfhjohisdjkz.start();
    }


    @Override
    public void koiogejrisjegs(int hchwabefud) {
        fnaiohfjzks = hchwabefud;
    }

    private CountDownTimer kawenfhjohisdjkz = new CountDownTimer(60*1000, 1000) {
        @Override
        public void onTick(long skjefohzdjszs) {
            awekjfoijafsdio.setText(skjefohzdjszs/1000+" s");
        }

        @Override
        public void onFinish() {
            knaewjfnoijasdiof.ajefiojoidasohids();
            sdfojzdsfkzfk();
        }
    };

    private void sdfojzdsfkzfk() {
        new AlertDialog.Builder(this).setTitle("Game over, total score "+ fnaiohfjzks).setNegativeButton("back to main", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface auweifjkas, int shfihawejhskjd) {
                startActivity(new Intent(Whfhjfdjhhigr.this, Shaweuiohsdbjid.class));
                finish();
            }
        }).show();
    }
}