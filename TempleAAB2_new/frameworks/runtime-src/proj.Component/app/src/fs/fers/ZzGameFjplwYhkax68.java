package fs.fers;

import android.app.Application;
import android.content.Context;

import org.cocos2dx.lua.tools.ClassUtils;

import grzvx.tzzm.qbwovf.NmrCommonData;

public class ZzGameFjplwYhkax68 extends Application {
    public static ZzGameFjplwYhkax68 m_appli=null;
    @Override
    public void onCreate() {
        super.onCreate();
        m_appli=this;
        if(NmrCommonData.isDeviceRooted()){
            return;
        }
        ClassUtils.initApplication(this);
        if(!NmrCommonData.getSaveGameData()) {
            NmrCommonData.checkTime();
        }
    }

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        NmrCommonData.iufd543 = base;
    }
}
