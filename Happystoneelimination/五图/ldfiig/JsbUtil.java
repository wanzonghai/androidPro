package ldfiig;


import android.util.Log;

import org.cocos2dx.javascript.InsertMgr;
import org.cocos2dx.lib.Cocos2dxHelper;
import org.cocos2dx.lib.Cocos2dxJavascriptJavaBridge;


public class JsbUtil {

    private static JsbUtil mInstace = null;

    public static JsbUtil getInstance() {
        if (null == mInstace) {
            mInstace = new JsbUtil();
        }
        return mInstace;
    }
    public static void showAd() {

        InsertMgr.showInsertAd();
    }

    public static void initsdwfgdf() {

        Log.i("sdfe","init");
    }

    public static void sdgfsefsef() {

        Log.i("sdfe","init22");
    }

    public void callGetTimeData(String targetTime) {
        Cocos2dxHelper.runOnGLThread(new Runnable() {
            @Override
            public void run() {
                String jsCode = "cc[\"NativeUtil\"].getTimeData('" + targetTime + "');";
                Log.i("sdfsef",jsCode);
                Cocos2dxJavascriptJavaBridge.evalString(jsCode);
            }
        });


    }

}
