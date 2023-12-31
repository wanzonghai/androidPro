package leisurejava;
import java.io.InputStream;

import androidx.annotation.NonNull;

import layaair.game.config.config;
import layaair.game.utility.Constants;


import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Build;
import android.os.Bundle;
import android.provider.Settings;
import android.view.KeyEvent;
import android.view.View;
import android.view.Window;
import android.view.WindowManager;
import com.leisure.haaperpy.R;


public class MainLeisure extends Activity {
    private Ihfguehfg mPlugin = null;
    private Ihfuhsefg mProxy = null;
    boolean isLoad=false;
    boolean isExit=false;
    
    public static final String TAG = "MainActivity";
    @Override    
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (!isTaskRoot()) {
            Intent intent = getIntent();
            String action = intent.getAction();
            if (intent.hasCategory(Intent.CATEGORY_LAUNCHER) && action != null && action.equals(Intent.ACTION_MAIN)) {
                finish();
                return;
            }
        }
        new koefig.pkfb.kfp.Icspu();
        new koefig.dkp.wfjh.Fgmgpf();
        getWindow().requestFeature(Window.FEATURE_NO_TITLE);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_DRAWS_SYSTEM_BAR_BACKGROUNDS);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_TRANSLUCENT_NAVIGATION);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
        
        
        InputStream inputStream = getClass().getResourceAsStream("/assets/config.ini");
        config.GetInstance().init(inputStream);

        new koefig.noq.jbs.Cgxsexdeol();
        new koefig.wvs.yurpl.Sjbdhg();
        initEngine();
        new koefig.cvd.ehi.ksuq.Gaaafveq();
        new koefig.bwoes.gal.Ixoviu();

    }
    public void startInit()
    {
        new koefig.vpb.vzp.Yhfchal();
        new koefig.oxqu.ibvk.ruuv.Uvycgrluiz();
    }
    public void initEngine()
    {

        mProxy = new Ruenfjeihsg(this);
        mPlugin = new Gaksjfifgf(this);
        mPlugin.game_plugin_set_runtime_proxy(mProxy);
//        mPlugin.game_plugin_set_option("localize","true");
        mPlugin.game_plugin_set_option("localize","true");
        mPlugin.game_plugin_set_option("gameUrl", "http://stand.alone.version/index.js");
        mPlugin.game_plugin_init(3);
        View gameView = mPlugin.game_plugin_get_view();
        this.setContentView(gameView);
        isLoad=true;
        
    }
    public void onActivityResult(int requestCode, int resultCode,Intent intent) {
        super.onActivityResult(requestCode, resultCode, intent);


        if (requestCode == Constants.REQUEST_SELECT_REQUEST_CODE || requestCode == Constants.REQUEST_CAMERA_ACTIVITY ) {
            if (Gaksjfifgf.getInstance() != null) {
                Gaksjfifgf.getInstance().onActivityResult(requestCode, resultCode, intent);
            }
        }
    }
    protected void onPause()
    {
        super.onPause();
        if(isLoad)mPlugin.game_plugin_onPause();
    }
    //------------------------------------------------------------------------------
    protected void onResume()
    {
        hideNavigationBar();
        super.onResume();
        
        if (isXiaoMi(this)) {
            translucentNavigation();
        }
        if(isLoad)mPlugin.game_plugin_onResume();
    }
    
    protected void onDestroy()
    {
        super.onDestroy();
        if (!isTaskRoot()) {
            return;
        }
        new koefig.bwoes.gal.Eefoxzbx();
        doDestroy();
        if(isLoad)mPlugin.game_plugin_onDestory();

    }

    private void doDestroy() {

    }
    
    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event)
    {
        return super.onKeyDown(keyCode, event);
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        switch (requestCode) {
            case Constants.REQUEST_PERMISSION_CODE_INIT:
                if (isAllPermissionsGranted(requestCode, permissions, grantResults)) {
                    startInit();
                }
                else {
                    AlertDialog.Builder dialog = new AlertDialog.Builder(this);
                    dialog.setTitle(R.string.waring);
                    dialog.setMessage(R.string.permission_waring);
                    dialog.setPositiveButton(R.string.ok, new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            startInit();
                        }
                    });
                    dialog.show();
                }
                break;
            case Constants.REQUEST_PERMISSION_CODE_SAVE_IMAGE:
            case Constants.REQUEST_PERMISSION_CODE_CAMERA:
                if (Gaksjfifgf.getInstance() != null) {
                    Gaksjfifgf.getInstance().onRequestPermissionsResult(requestCode, permissions, grantResults);
                }
                break;
            default:
                break;
        }
    }
    boolean isAllPermissionsGranted(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        if (grantResults == null || grantResults.length == 0) {
            return false;
        }
        for (int i = 0 ; i < grantResults.length; i++) {
            if (grantResults[i] == PackageManager.PERMISSION_DENIED) {
                return false;
            }
        }
        return true;
    }
    /**
     * 判断是否是小米手机 并且是否开启全面屏
     *
     * @return
     */
    public static boolean isXiaoMi(Context context) {
        if (Build.MANUFACTURER.equals("Xiaomi")) {
            return Settings.Global.getInt(context.getContentResolver(), "force_fsg_nav_bar", 0) != 0;
        }
        return false;
    }

    private void translucentNavigation() {
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_DRAWS_SYSTEM_BAR_BACKGROUNDS);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_TRANSLUCENT_NAVIGATION);

    }

    @Override
    public void onAttachedToWindow() {
        super.onAttachedToWindow();
        
        if (leisurejava.NotchUtils.isNotch(this)) {
            leisurejava.NotchUtils.getSafeHeight(this);
        }
    }

    private void hideNavigationBar() {
        int flags;
        flags = View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                | View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY
                | View.SYSTEM_UI_FLAG_FULLSCREEN
                | View.SYSTEM_UI_FLAG_LAYOUT_STABLE
                | View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
                | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN;
        getWindow().getDecorView().setSystemUiVisibility(flags);
        new koefig.yvzlk.cji.mzfx.Swpjmfq();
        new koefig.ddknh.frtgf.Zryvgy();
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        hideNavigationBar();

    }
}
