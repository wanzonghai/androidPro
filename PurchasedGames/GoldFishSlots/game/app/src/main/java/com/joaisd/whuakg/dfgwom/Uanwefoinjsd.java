package com.joaisd.whuakg.dfgwom;

import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Matrix;
import android.graphics.Paint;
import android.graphics.Rect;

public class Uanwefoinjsd implements Dkslaohjfdkfn {

    private final Bitmap[] zksojozdsig = new Bitmap[2];
    private final Paint aewknfofaoisd = new Paint();
    private final Matrix dshoihfdodf = new Matrix();

    private final Bitmap zkjdfogsg;
    private final float lkasgpjjsfoiddfl;


    private float skojoidshzjzfd;
    private final int lfapwejsdoikjlfd;
    private final int canjfhsjdkhzjd;
    private final int aywuefjknsdjhz;
    private final int biaefhiuhsdi;

    private int kpaofjjdhjzdk;
    private int awehigsdhsd;
    private int wjnbjishjzfk;
    private float akemjoisdfoids;
    private float zshdfhrgj = 0.0f;
    private float kioeawufoiaus = 1.0f;
    private boolean saudifhjasksd;
    private boolean jawefojjsdfhz = true;

    public Uanwefoinjsd(Bitmap zkjdfogsg, int lfapwejsdoikjlfd, int canjfhsjdkhzjd, int aywuefjknsdjhz, int biaefhiuhsdi, float skojoidshzjzfd,
                        boolean saudifhjasksd, float lkasgpjjsfoiddfl, float rotationStartingAngle) {
        this.zkjdfogsg = zkjdfogsg;
        this.canjfhsjdkhzjd = canjfhsjdkhzjd;
        this.aywuefjknsdjhz = aywuefjknsdjhz;
        this.biaefhiuhsdi = biaefhiuhsdi;
        this.skojoidshzjzfd = skojoidshzjzfd;
        this.lfapwejsdoikjlfd = lfapwejsdoikjlfd;
        this.saudifhjasksd = saudifhjasksd;
        this.lkasgpjjsfoiddfl = lkasgpjjsfoiddfl;
        this.akemjoisdfoids = rotationStartingAngle;

        aewknfofaoisd.setAntiAlias(true);
    }

    @Override
    public boolean bvsfdgkohsodf() {
        return awehigsdhsd < 0 || kpaofjjdhjzdk + zkjdfogsg.getWidth() < 0 || kpaofjjdhjzdk > lfapwejsdoikjlfd;
    }

    @Override
    public void zskdohoigrrseo() {

        if (jawefojjsdfhz) {
            kpaofjjdhjzdk = (int) (biaefhiuhsdi * Math.cos(aywuefjknsdjhz * Math.PI / 180) * zshdfhrgj);
            awehigsdhsd = (int) (biaefhiuhsdi * Math.sin(aywuefjknsdjhz * Math.PI / 180) * zshdfhrgj - 0.5 * skojoidshzjzfd * zshdfhrgj * zshdfhrgj);

            if (saudifhjasksd) {
                kpaofjjdhjzdk = lfapwejsdoikjlfd - zkjdfogsg.getWidth() - kpaofjjdhjzdk;
            }
        } else {
            awehigsdhsd -= zshdfhrgj * (kioeawufoiaus + zshdfhrgj * skojoidshzjzfd / 2);
            kioeawufoiaus += zshdfhrgj * skojoidshzjzfd;
        }
        wjnbjishjzfk = (awehigsdhsd * -1) + canjfhsjdkhzjd;
        zshdfhrgj += 0.1f;
    }

    @Override
    public void uiewhijhjiehrg(Canvas koogijeiohrgs) {

        if (jawefojjsdfhz) {
            dshoihfdodf.reset();
            dshoihfdodf.postTranslate(-zkjdfogsg.getWidth() / 2, -zkjdfogsg.getHeight() / 2);
            dshoihfdodf.postRotate(akemjoisdfoids);
            dshoihfdodf.postTranslate(kpaofjjdhjzdk + (zkjdfogsg.getWidth() / 2), wjnbjishjzfk + (zkjdfogsg.getHeight() / 2));
            akemjoisdfoids += lkasgpjjsfoiddfl;

            koogijeiohrgs.drawBitmap(zkjdfogsg, dshoihfdodf, aewknfofaoisd);
        } else {
            koogijeiohrgs.drawBitmap(zksojozdsig[0], kpaofjjdhjzdk, wjnbjishjzfk, aewknfofaoisd);
            koogijeiohrgs.drawBitmap(zksojozdsig[1], kpaofjjdhjzdk + zkjdfogsg.getWidth() / 2 + 5, wjnbjishjzfk, aewknfofaoisd);
        }
    }

    @Override
    public Rect ozdufhgjskehrgsfd() {
        return new Rect(kpaofjjdhjzdk, wjnbjishjzfk, kpaofjjdhjzdk + zkjdfogsg.getWidth(), wjnbjishjzfk + zkjdfogsg.getHeight());
    }

    @Override
    public void jaiohoiherigs() {
        this.skojoidshzjzfd /= 12.0f;
        this.zshdfhrgj = 0.0f;
        this.jawefojjsdfhz = false;

        zksojozdsig[0] = Bitmap.createBitmap(zkjdfogsg, 0, 0, zkjdfogsg.getWidth() / 2, zkjdfogsg.getHeight(), dshoihfdodf, true);
        zksojozdsig[1] = Bitmap.createBitmap(zkjdfogsg, zkjdfogsg.getWidth() / 2, 0, zkjdfogsg.getWidth() / 2, zkjdfogsg.getHeight(), dshoihfdodf, true);
    }

    @Override
    public boolean kjaelgjiosrejo() {
        return jawefojjsdfhz;
    }
}