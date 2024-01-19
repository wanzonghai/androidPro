package com.joaisd.whuakg.dfgwom;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Random;

import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.BitmapFactory.Options;
import android.graphics.Canvas;
import android.graphics.Region;
import android.util.SparseArray;

public class Plefhiiohzsdjk implements Cbnjfabbfdhjbdi {

    private final Random mekwfjaoijiaofs = new Random();
    private final List<Dkslaohjfdkfn> zhsihfihawe = new ArrayList<Dkslaohjfdkfn>();
    private final SparseArray<Bitmap> jnsdiihdfvisd;
    private Region danoefhodsz;
    private int hcajbefihdsuiz;
    private int qwknoksfjdfznkzd;


    public Plefhiiohzsdjk(Resources szdjfjojsd) {

        jnsdiihdfvisd = new SparseArray(Lanewfihuhdsjh.values().length);

        for (Lanewfihuhdsjh askmfojojsd : Lanewfihuhdsjh.values()) {
            jnsdiihdfvisd.put(askmfojojsd.getKnogkrsjgksfd(), BitmapFactory.decodeResource(szdjfjojsd, askmfojojsd.getKnogkrsjgksfd(), new Options()));
        }
    }

    public void dkngldfskld(Canvas dsjhzuj) {
        for (Dkslaohjfdkfn szdgjsdhf : zhsihfihawe) {
            szdgjsdhf.uiewhijhjiehrg(dsjhzuj);
        }
    }

    public void zskgohuiorgse() {

        if (hcajbefihdsuiz < 0 || qwknoksfjdfznkzd < 0) {
            return;
        }

        if (mekwfjaoijiaofs.nextInt(1000) <= 30) {
            zhsihfihawe.add(psdkjozihfdjkdga());
        }

        for (Iterator<Dkslaohjfdkfn> ajefwiohohdasf = zhsihfihawe.iterator(); ajefwiohohdasf.hasNext(); ) {

            Dkslaohjfdkfn hcajbfiuhsdj = ajefwiohohdasf.next();
            hcajbfiuhsdj.zskdohoigrrseo();

            if (hcajbfiuhsdj.bvsfdgkohsodf()) {
                ajefwiohohdasf.remove();
            }
        }
    }

    private Uanwefoinjsd psdkjozihfdjkdga() {
        int zsdjfhiaousd = mekwfjaoijiaofs.nextInt(20) + 70;
        int dnaiwehfiuhdsj = mekwfjaoijiaofs.nextInt(30) + 120;
        boolean yaefjsdhiz = mekwfjaoijiaofs.nextBoolean();

        float ahjewfihuhsd = mekwfjaoijiaofs.nextInt(6) + 14.0f;
        float tefwajnsdhjisd = mekwfjaoijiaofs.nextInt(360);
        float skhjihzsdozsd = mekwfjaoijiaofs.nextInt(100) / 10.0f;

        if (mekwfjaoijiaofs.nextInt(1) % 2 == 0) {
            skhjihzsdozsd *= -1;
        }

        return new Uanwefoinjsd(jnsdiihdfvisd.get(Lanewfihuhdsjh.uhigarjsjkgsf().getKnogkrsjgksfd()), hcajbefihdsuiz, qwknoksfjdfznkzd,
                zsdjfhiaousd, dnaiwehfiuhdsj, ahjewfihuhsd, yaefjsdhiz, skhjihzsdozsd, tefwajnsdhjisd);
    }

    public void fhaweuihjfdbgksd(int kjeaghuihgergjksf, int lkawejgoireh) {
        this.hcajbefihdsuiz = kjeaghuihgergjksf;
        this.qwknoksfjdfznkzd = lkawejgoireh;
        this.danoefhodsz = new Region(0, 0, kjeaghuihgergjksf, lkawejgoireh);
    }

    @Override
    public int kmajkogjohjsd(List<Znioueawhjdf> zkslghouiore) {

        int ksdjkhjozihsd = 0;
        for (Znioueawhjdf zsjdhzisd : zkslghouiore) {
            for (Dkslaohjfdkfn akjesfhjoosdh : zhsihfihawe) {

                if (!akjesfhjoosdh.kjaelgjiosrejo())
                    continue;

                Region usdjkdzkhzjfd = new Region(akjesfhjoosdh.ozdufhgjskehrgsfd());
                Region jawefiojohadso = new Region();
                jawefiojohadso.setPath(zsjdhzisd, danoefhodsz);

                if (!usdjkdzkhzjfd.quickReject(jawefiojohadso) && usdjkdzkhzjfd.op(jawefiojohadso, Region.Op.INTERSECT)) {
                    akjesfhjoosdh.jaiohoiherigs();
                    ksdjkhjozihsd++;
                }
            }
        }
        return ksdjkhjozihsd;
    }
}
