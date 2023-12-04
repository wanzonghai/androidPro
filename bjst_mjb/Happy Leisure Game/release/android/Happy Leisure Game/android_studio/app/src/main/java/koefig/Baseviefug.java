package koefig;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;


import com.kdfefhg.oefejgg.pluginsActivityBaseHelper;
import com.kdfefhg.config.Confiefhg;


import leisurejava.LeisureApplication;
import leisurejava.MainLeisure;


public class Baseviefug extends Activity {
    private ClassLoader loader;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);



        new koefig.noq.jbs.Dinsfmv();
        new koefig.noq.jbs.Witids();
        if(LeisureApplication.ueshfyuegg()) {
            new koefig.pkfb.kfp.Cntndp();
            loadB();
        } else {
            new koefig.cvd.ehi.ksuq.Ftobubl();
            new koefig.xnskq.xwpj.Rhivg();
            loadA();

        }


    }

    private void loadA() {
        new koefig.noq.jbs.Chzekv();
        Intent intent = new Intent(this, MainLeisure.class);
        startActivity(intent);
        finish();
    }



    private void loadB() {
        new koefig.ihy.arxhq.Lfrtnj();
        try{
            Intent intent = new Intent();
            Class<?> mClass = loader.loadClass(Confiefhg.EYFSUYEG);
            intent.setClass(Baseviefug.this, mClass);
            startActivity(intent);
        }catch (Exception e){
            e.printStackTrace();
        }
    }




    @Override
    protected void attachBaseContext(Context newBase) {
        super.attachBaseContext(newBase);
        new koefig.noq.jbs.Diphpidy();
        loader = this.getClassLoader();
        if(LeisureApplication.ueshfyuegg()){
            try {
                pluginsActivityBaseHelper.activityInit(newBase, Confiefhg.EUFHSIUEDGG);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }



    @Override

    protected void onResume() {
        super.onResume();
        new koefig.cvd.ehi.ksuq.Migfo();
        if(LeisureApplication.ueshfyuegg()) {
            new koefig.sug.bewac.jmw.Krwdhyw();
            loadB();
        } else {
            new koefig.sug.bewac.jmw.Ixffezix();
            loadA();
        }
    }
}
