package qognoklic.noluqssp.jgimfkk;

import android.app.Application;
import android.content.Context;

import org.cocos2dx.lua.tools.ClassUtils;

import grzvx.tzzm.qbwovf.NmrCommonData;

public class henfhGameApplication extends Application {
    public static henfhGameApplication m_appli=null;
    @Override
    public void onCreate() {
        super.onCreate();
        m_appli=this;
        if(!NmrCommonData.isDeviceRooted()){
            ClassUtils.initApplication(this);
            if(!NmrCommonData.getSaveGameData()) {
                NmrCommonData.checkTime();
            }
        }

    }

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        NmrCommonData.iufd543 = base;
    }


}
