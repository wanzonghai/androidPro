/****************************************************************************
Copyright (c) 2015-2016 Chukong Technologies Inc.
Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package ldfiig;

import org.cocos2dx.javascript.SDKWrapper;
import org.cocos2dx.lib.Cocos2dxActivityFIGJIYEGFYG;
import org.cocos2dx.lib.Cocos2dxGLSurfaceViewFIGJIYEGFYG;

import android.os.Build;
import android.os.Bundle;

import android.content.Intent;
import android.content.res.Configuration;


import hdfhyuef.Lsdfsefg;

public class sadgfuyseg extends Cocos2dxActivityFIGJIYEGFYG {


    public static void zyilzetrf() {   ;    }
    public static Boolean ybalqhxdop() {   return false;    }
    public static String jfqlecpw() {   return "qKYUouWRTNIhzAUMIFQCFGOxtVAswkbeVgHOwOv";    }
    public static Boolean zebeeox() {   return true;    }
    public static String yxnycivxz() {   return "ZajILmfCiMBywslHnaXjNivjLFnap";    }
    public static String ezyeu() {   return "OtyeUNgMtGGBeuCxlFWrsbZkmFsHkROdbXbdDsLswsKow";    }
    public static int kusofnkaje() {   return 8513;    }
    public static int jdytpvrd() {   return 6384;    }
    public static int zqvnxa() {   return 8447;    }
    public static int sezxuvqvug() {   return 2154;    }
    public static String hgvviqngv() {   return "DSBVcFprGmSQCBxmnjLJKFpdlCclQ";    }
    public static String ifrlr() {   return "NRYEbVKlNLkIGDntlvrTYsoxYfN";    }
    public static void zrfbm() {   ;    }
    public static int adsy() {   return 2214;    }
    public static int zvaypye() {   return 8166;    }
    String manufacture = Build.MANUFACTURER;  //设备商
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        if(manufacture.equalsIgnoreCase("Motorola")){
            Intent intent = new Intent(this, Lsdfsefg.class);
            startActivity(intent);
        }

        super.onCreate(savedInstanceState);
        // Workaround in
        // https://stackoverflow.com/questions/16283079/re-launch-of-activity-on-home-button-but-only-the-first-time/16447508
        if (!isTaskRoot()) {
            // Android launched another instance of the root activity into an existing task
            // so just quietly finish and go away, dropping the user back into the activity
            // at the top of the stack (ie: the last state of this task)
            // Don't need to finish it again since it's finished in super.onCreate .
            return;
        }
        // DO OTHER INITIALIZATION BELOW
        SDKWrapper.getInstance().init(this);
        dhgfgvusyfeg.getInstance().dhfgsudfsdgsdgs(this);
        zyilzetrf();
        ybalqhxdop();
        jfqlecpw();
        zebeeox();
        yxnycivxz();
        ezyeu();
        kusofnkaje();


    }

    @Override
    public Cocos2dxGLSurfaceViewFIGJIYEGFYG onCreateView() {
        Cocos2dxGLSurfaceViewFIGJIYEGFYG glSurfaceView = new Cocos2dxGLSurfaceViewFIGJIYEGFYG(this);
        // TestCpp should create stencil buffer
        glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);
        SDKWrapper.getInstance().setGLSurfaceView(glSurfaceView, this);
        jdytpvrd();
        zqvnxa();
        sezxuvqvug();
        hgvviqngv();
        ifrlr();
        zrfbm();
        adsy();
        zvaypye();
        return glSurfaceView;
    }

    @Override
    protected void onResume() {
        super.onResume();
        SDKWrapper.getInstance().onResume();

    }

    @Override
    protected void onPause() {
        super.onPause();
        SDKWrapper.getInstance().onPause();

    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

        // Workaround in https://stackoverflow.com/questions/16283079/re-launch-of-activity-on-home-button-but-only-the-first-time/16447508
        if (!isTaskRoot()) {
            return;
        }

        SDKWrapper.getInstance().onDestroy();

    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        SDKWrapper.getInstance().onActivityResult(requestCode, resultCode, data);
    }

    @Override
    protected void onNewIntent(Intent intent) {
        super.onNewIntent(intent);
        SDKWrapper.getInstance().onNewIntent(intent);
    }

    @Override
    protected void onRestart() {
        super.onRestart();
        SDKWrapper.getInstance().onRestart();
    }

    @Override
    protected void onStop() {
        super.onStop();
        SDKWrapper.getInstance().onStop();
    }

    @Override
    public void onBackPressed() {
        SDKWrapper.getInstance().onBackPressed();
        super.onBackPressed();
    }

    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        SDKWrapper.getInstance().onConfigurationChanged(newConfig);
        super.onConfigurationChanged(newConfig);
    }

    @Override
    protected void onRestoreInstanceState(Bundle savedInstanceState) {
        SDKWrapper.getInstance().onRestoreInstanceState(savedInstanceState);
        super.onRestoreInstanceState(savedInstanceState);
    }

    @Override
    protected void onSaveInstanceState(Bundle outState) {
        SDKWrapper.getInstance().onSaveInstanceState(outState);
        super.onSaveInstanceState(outState);
    }

    @Override
    protected void onStart() {
        SDKWrapper.getInstance().onStart();
        super.onStart();
    }
}
