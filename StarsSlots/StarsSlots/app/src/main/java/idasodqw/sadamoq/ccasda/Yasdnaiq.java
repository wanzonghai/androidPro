package idasodqw.sadamoq.ccasda;

import android.app.Activity;
import android.app.Dialog;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;

import com.qwkaji.smndjb.wqaskv.R;

import androidx.recyclerview.widget.RecyclerView;


public class Yasdnaiq extends Activity {
    @Override
    protected void onCreate(Bundle vnawiehbrieurb) {
        super.onCreate(vnawiehbrieurb);
        setContentView(R.layout.aeovibsheriobn);
        findViewById(R.id.vnaweiohvbioeb).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                finish();
            }
        });
        findViewById(R.id.akwejhvbaoierwb).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                haweoiheroibs();
            }
        });

        awenovibaerb();

        Lasdnaq oweig = new Lasdnaq() {
            @Override
            public int awejioberb() {
                return 0;
            }
        };
    }
    private void awenovibaerb() {
        findViewById(R.id.vanweiobr).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View awejvhoierb) {
                awejiovhaerwb();
            }
        });
        Kasduaqw goiwag = new Kasduaqw(this);
    }

    private void awejiovhaerwb() {
        Intent vawjoisehbio = new Intent(Yasdnaiq.this, Pnasdanqw.class);
        startActivity(vawjoisehbio);
        Gasdqnddas hwi3u = new Gasdqnddas() {
            @Override
            public void avwiehrboier(RecyclerView.ViewHolder viewHolder) {

            }

            @Override
            public void vajwioerbher(RecyclerView.ViewHolder viewHolder) {

            }

            @Override
            public void awejiovbaerb(RecyclerView.ViewHolder viewHolder, View view) {

            }
        };
    }
    private void haweoiheroibs() {
        Dialog lawejvboeirb = new Dialog(Yasdnaiq.this);
        lawejvboeirb.requestWindowFeature(Window.FEATURE_NO_TITLE);
        lawejvboeirb.setCanceledOnTouchOutside(false);
        View vwaeiohvoiweb = LayoutInflater.from(Yasdnaiq.this).inflate(R.layout.caweiovhbaeirob, null, false);
        lawejvboeirb.addContentView(vwaeiohvoiweb, new ViewGroup.LayoutParams(ViewGroup.LayoutParams.WRAP_CONTENT, ViewGroup.LayoutParams.WRAP_CONTENT));
        lawejvboeirb.show();
        vwaeiohvoiweb.findViewById(R.id.vnwioesrhboierhbr).setOnClickListener(view1 -> {
            lawejvboeirb.dismiss();
        });
    }



}
