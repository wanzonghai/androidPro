package com.joaisd.whuakg.dfgwom;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Executors;
import java.util.concurrent.ScheduledExecutorService;
import java.util.concurrent.ScheduledFuture;
import java.util.concurrent.TimeUnit;

import android.graphics.Bitmap;
import android.graphics.BlurMaskFilter;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.SurfaceHolder;

import androidx.collection.SparseArrayCompat;

public class Jnuaiwehfjdzbg implements Runnable {

    private final Paint ouihagjkdf = new Paint();
    private final SurfaceHolder jcwacncdasjkhz;
    private final Fwquherjnisdxjh kjaewokjgohsd;
    private final Cbnjfabbfdhjbdi soiehfuhurek;
    private final ScheduledExecutorService zkjdfoghsiughs = Executors.newScheduledThreadPool(1);
    private final Paint ajwehoihiuh = new Paint();
    private final Paint naewohiusdfg = new Paint();


    private volatile ScheduledFuture<?> nfeaiohsdavioasd;

    private int ajnrgohoisgd = 0;
    private int diyguuysga = 0;
    private int bciuagfiuaw = 0;
    private Bitmap jkwefioauhsuf;
    private boolean ysafugaywfe = false;
    private SparseArrayCompat<Znioueawhjdf> jawehihiuasd;

    public Jnuaiwehfjdzbg(SurfaceHolder jcwacncdasjkhz, Cbnjfabbfdhjbdi cbnjfabbfdhjbdi, Bitmap sjdhohiaiuhg, Fwquherjnisdxjh fwquherjnisdxjh) {
        this.jcwacncdasjkhz = jcwacncdasjkhz;
        this.soiehfuhurek = cbnjfabbfdhjbdi;
        this.kjaewokjgohsd = fwquherjnisdxjh;
        this.jkwefioauhsuf = sjdhohiaiuhg;
    }

    public void ydaykjdohzjd() {
        ysafugaywfe = false;
    }

    public void bcasbjsdkhzjd(int zhuigdhiser, int akjegkohois) {
        this.ajnrgohoisgd = zhuigdhiser;
        ysafugaywfe = true;
        soiehfuhurek.fhaweuihjfdbgksd(zhuigdhiser, akjegkohois);
    }

    public void lakcopjajsdosd(int yugefhjaihds, int qjhuihughhs) {
        this.ajnrgohoisgd = yugefhjaihds;
        this.bciuagfiuaw = qjhuihughhs;
        this.ysafugaywfe = true;
        this.soiehfuhurek.fhaweuihjfdbgksd(yugefhjaihds, qjhuihughhs);
        this.nfeaiohsdavioasd = zkjdfoghsiughs.scheduleAtFixedRate(this, 0, 10, TimeUnit.MILLISECONDS);

        this.ouihagjkdf.setColor(Color.parseColor("#0e932e"));
        this.ouihagjkdf.setAntiAlias(true);
        this.ouihagjkdf.setTextSize(58.0f);

        this.ajwehoihiuh.setAntiAlias(true);
        this.ajwehoihiuh.setColor(Color.YELLOW);
        this.ajwehoihiuh.setStyle(Paint.Style.STROKE);
        this.ajwehoihiuh.setStrokeJoin(Paint.Join.ROUND);
        this.ajwehoihiuh.setStrokeWidth(5.0f);

        this.naewohiusdfg.set(this.ajwehoihiuh);
        this.naewohiusdfg.setMaskFilter(new BlurMaskFilter(9.0f, BlurMaskFilter.Blur.NORMAL));
    }

    @Override
    public void run() {
        Canvas najweojhuisd = null;
        if (ysafugaywfe) {
            try {
                soiehfuhurek.zskgohuiorgse();
                if (jawehihiuasd != null && jawehihiuasd.size() > 0) {
                    List<Znioueawhjdf> nuewihfuihuier = new ArrayList<Znioueawhjdf>();
                    for (int kioaewgoiha = 0; kioaewgoiha < jawehihiuasd.size(); kioaewgoiha++) {
                        nuewihfuihuier.add(jawehihiuasd.valueAt(kioaewgoiha));
                    }
                    diyguuysga += soiehfuhurek.kmajkogjohjsd(nuewihfuihuier);
                    kjaewokjgohsd.koiogejrisjegs(diyguuysga);
                }

                najweojhuisd = jcwacncdasjkhz.lockCanvas();
                if (najweojhuisd != null) {
                    synchronized (jcwacncdasjkhz) {
                        najweojhuisd.drawBitmap(jkwefioauhsuf, 0,0, null);
                        soiehfuhurek.dkngldfskld(najweojhuisd);
                        najweojhuisd.drawText("Score: " + diyguuysga, ajnrgohoisgd - 360, 100, ouihagjkdf);

                        if (jawehihiuasd != null) {
                            for (int uisgiherg = 0; uisgiherg < jawehihiuasd.size(); uisgiherg++) {
                                najweojhuisd.drawPath(jawehihiuasd.valueAt(uisgiherg), naewohiusdfg);
                                najweojhuisd.drawPath(jawehihiuasd.valueAt(uisgiherg), ajwehoihiuh);

                                if (jawehihiuasd.valueAt(uisgiherg).akemfkljoafsdjoasd() + 500 < System.currentTimeMillis()) {
                                    jawehihiuasd.removeAt(uisgiherg);
                                }
                            }
                        }
                    }
                }
            } catch (Exception kjagkoho) {
            } finally {
                if (najweojhuisd != null) {
                    jcwacncdasjkhz.unlockCanvasAndPost(najweojhuisd);
                }
            }
        }

    }

    public void kaweoifjioahdsui(SparseArrayCompat<Znioueawhjdf> bcawejbijasdj) {
        this.jawehihiuasd = bcawejbijasdj;
    }
}