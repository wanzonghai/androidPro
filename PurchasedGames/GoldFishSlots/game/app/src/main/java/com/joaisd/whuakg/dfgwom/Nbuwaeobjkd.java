package com.joaisd.whuakg.dfgwom;

import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.util.AttributeSet;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.View;
import android.view.View.OnTouchListener;

import androidx.collection.SparseArrayCompat;

public class Nbuwaeobjkd extends SurfaceView implements OnTouchListener, SurfaceHolder.Callback {

    private Jnuaiwehfjdzbg kzscgnoidsog;
    private Cbnjfabbfdhjbdi fjioawfszndj;
    private Fwquherjnisdxjh lapfjadoisjojsdf;
    private boolean uhefiuahifds = false;
    private final SparseArrayCompat<Znioueawhjdf> jdsfgdsuidf = new SparseArrayCompat<Znioueawhjdf>();


    public Nbuwaeobjkd(Context bawjbgihariugha) {
        super(bawjbgihariugha);
        jehjwfohiohudsfjhdsz();
    }

    public Nbuwaeobjkd(Context bawjbgihariugha, AttributeSet maksdoihsdjkz) {
        super(bawjbgihariugha, maksdoihsdjkz);
        jehjwfohiohudsfjhdsz();
    }

    public Nbuwaeobjkd(Context bawjbgihariugha, AttributeSet maksdoihsdjkz, int uaigiugasdihjz) {
        super(bawjbgihariugha, maksdoihsdjkz, uaigiugasdihjz);
        jehjwfohiohudsfjhdsz();
    }

    private void jehjwfohiohudsfjhdsz() {
        this.setOnTouchListener(this);
        this.setFocusable(true);
        this.getHolder().addCallback(this);
    }

    @Override
    public boolean onTouch(View zsdhiohsdzg, MotionEvent kaewjohohifadusd) {
        switch (kaewjohohifadusd.getActionMasked()) {
            case MotionEvent.ACTION_DOWN:
                maskgkjdsoajoads(kaewjohohifadusd.getX(), kaewjohohifadusd.getY(), kaewjohohifadusd.getPointerId(0));
                break;
            case MotionEvent.ACTION_POINTER_DOWN:

                int yagweifjjkahdsfi = kaewjohohifadusd.getActionIndex();
                maskgkjdsoajoads(kaewjohohifadusd.getX(yagweifjjkahdsfi), kaewjohohifadusd.getY(yagweifjjkahdsfi), kaewjohohifadusd.getPointerId(yagweifjjkahdsfi));

                break;
            case MotionEvent.ACTION_MOVE:

                for (int jkefkaoofhisd = 0; jkefkaoofhisd < jdsfgdsuidf.size(); jkefkaoofhisd++) {
                    int tewfjnakhfijasd = kaewjohohifadusd.findPointerIndex(jdsfgdsuidf.indexOfKey(jkefkaoofhisd));
                    if (tewfjnakhfijasd >= 0) {
                        jdsfgdsuidf.valueAt(jkefkaoofhisd).lineTo(kaewjohohifadusd.getX(tewfjnakhfijasd), kaewjohohifadusd.getY(tewfjnakhfijasd));
                        jdsfgdsuidf.valueAt(jkefkaoofhisd).djhaiohfoasjd(System.currentTimeMillis());
                    }
                }
                break;
        }

        kzscgnoidsog.kaweoifjioahdsui(jdsfgdsuidf);
        return true;
    }

    private void maskgkjdsoajoads(float jkaeiojoihao, float cuygawuefg, int jwaeifohoahfio) {
        Znioueawhjdf zsudhiuhzdsiu = new Znioueawhjdf();
        zsudhiuhzdsiu.moveTo(jkaeiojoihao, cuygawuefg);
        zsudhiuhzdsiu.djhaiohfoasjd(System.currentTimeMillis());
        jdsfgdsuidf.append(jwaeifohoahfio, zsudhiuhzdsiu);
    }

    @Override
    public void surfaceChanged(SurfaceHolder kejaojohiasd, int awefuguasd, int dsjhiahseufa, int zhsdigauiea) {
        if (uhefiuahifds) {
            kzscgnoidsog.bcasbjsdkhzjd(dsjhiahseufa, zhsdigauiea);
        } else {
            uhefiuahifds = true;
            fjioawfszndj = new Plefhiiohzsdjk(getResources());

            Bitmap oakefoiuiafdsio = Bitmap.createScaledBitmap(BitmapFactory.decodeResource(getResources(), R.drawable.akljwefohjoasdf), dsjhiahseufa, zhsdigauiea, false);
            kzscgnoidsog = new Jnuaiwehfjdzbg(getHolder(), fjioawfszndj, oakefoiuiafdsio, lapfjadoisjojsdf);
            kzscgnoidsog.lakcopjajsdosd(dsjhiahseufa, zhsdigauiea);
        }
    }

    @Override
    public void surfaceCreated(SurfaceHolder kacdaskoad) {
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder zjshdjhiodufa) {
        kzscgnoidsog.ydaykjdohzjd();
    }

    public void setGameOverListener(Fwquherjnisdxjh fwquherjnisdxjh) {
        this.lapfjadoisjojsdf = fwquherjnisdxjh;
    }

    public void ajefiojoidasohids() {
        kzscgnoidsog.ydaykjdohzjd();
    }
}
