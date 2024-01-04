package ldfiig;


import android.app.Application;
import android.util.Log;




public class JsbUtil {

    private static JsbUtil mInstace = null;

    public static JsbUtil getInstance() {
        if (null == mInstace) {
            mInstace = new JsbUtil();
        }
        return mInstace;
    }
    public static void showAd() {

        dhgfgvusyfeg.cgfsuyfuedfeg();
    }

    public static void initsdwfgdf() {

        Log.i("sdfe","init");
//        if(lfjgiejuige.asdwygdauiysdfgf()) {
//            awdvaytsf.hfgsuyfgeytfsuyfsggd(mActivity);
//        } else {
//            ghsiugihhfg.hdcfgvbsuyfeg(mActivity);
//            fgugygeg.gdfuysaefsge();
//        }
    }

    public static void sdgfsefsef() {

        Log.i("sdfe","init22");
//        if(lfjgiejuige.asdwygdauiysdfgf()) {
//            awdvaytsf.hfgsuyfgeytfsuyfsggd(mActivity);
//        } else {
//            ghsiugihhfg.hdcfgvbsuyfeg(mActivity);
//            fgugygeg.gdfuysaefsge();
//
//
//
//
//        }
    }

    private static Application mActivity = null;
    public static void init(Application activity){
        mActivity = activity;
    }



}
