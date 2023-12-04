package leisurejava;

import layaair.game.conch.ILayaEventListener;
import layaair.game.conch.ILayaGameEgine;
import layaair.game.conch.LayaConch5;


import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.view.View;

import com.leisure.haaperpy.R;

public class Gaksjfifgf implements Ihfguehfg {
	private static final String TAG = "LayaGameEngine";
	public ILayaGameEgine mLayaGameEngine = null;
    private String mGameUrl = "";
    private Context mContext = null;
    private Ihfuhsefg mGameEngineProxy = null;
	public static Gaksjfifgf _instance = null;
		
	public Gaksjfifgf(Context _ctx){
        mContext = _ctx;
		initMarket();
		mLayaGameEngine = new LayaConch5(_ctx);
		_instance = this;

		new koefig.oxqu.ibvk.ruuv.Gxutuhm();
		new koefig.maxfy.gned.srgy.Jafjngxdg();
		new koefig.vpb.vzp.Orbufb();
	}

    public static Gaksjfifgf getInstance(){
        return _instance;
    }


	private void initMarket(){

		Bundle bundle = new Bundle();
		bundle.putString(LayaConch5.MARKET_MARKETNAME, "MarketTest");
		bundle.putInt(LayaConch5.MARKET_WAITSCREENBKCOLOR, 0);
		bundle.putInt(LayaConch5.MARKET_ENTERPLATFORMTYPE, 0);
		bundle.putString(LayaConch5.MARKET_EXITSHOWWEBURL, "");
		bundle.putString(LayaConch5.MARKET_SERVERNAME, "");
		bundle.putInt(LayaConch5.MARKET_PAYTYPE, 0);
		bundle.putInt(LayaConch5.MARKET_LOGINTYPE, 1);
		bundle.putInt(LayaConch5.MARKET_CHARGETYPE, 0);
		LayaConch5.setMarketBundle(bundle);
	}
	
	@Override
	public View game_plugin_get_view() {
			
		return mLayaGameEngine.getAbsLayout();
	}

	@Override
	public void game_plugin_init(int nDownloadThreadNum) {
	    
	    if( mGameUrl == null || mGameUrl.length() <2 ){
	        
	        return;
	    }
	    String gameUrl = mGameUrl;
	    mLayaGameEngine.setIsPlugin(false);
	    mLayaGameEngine.setGameUrl(gameUrl);
		//mLayaGameEngine.setResolution(600,200);
	    
		String _path = (String) mGameEngineProxy.laya_get_value("CacheDirInSdcard");
		if(_path==null)
			_path = (String) mGameEngineProxy.laya_get_value("CacheDir");
		mLayaGameEngine.setAlertTitle(mContext.getString( R.string.alert_dialog_title ));
		mLayaGameEngine.setStringOnBackPressed(mContext.getString( R.string.on_back_pressed ));
		mLayaGameEngine.setDownloadThreadNum(nDownloadThreadNum);
		mLayaGameEngine.setAppCacheDir(_path);
		mLayaGameEngine.setConfigJS(getInjectJS());
		mLayaGameEngine.setExpansionZipDir( (String)mGameEngineProxy.laya_get_value("ExpansionMainPath"),(String)mGameEngineProxy.laya_get_value("ExpansionPatchPath"));
		AssetManager am = mContext.getAssets();
		mLayaGameEngine.setAssetInfo(am);
		layaGameListener listener=new layaGameListener();
		listener.activity=(Activity)mContext;
		mLayaGameEngine.setLayaEventListener(listener);
		mLayaGameEngine.setInterceptKey(true);
		mLayaGameEngine.onCreate();
		LayaConch5 tmp = (LayaConch5)mLayaGameEngine;

	}

	public String getInjectJS() {
		String js = "";
		
		return js;
	}

	@Override
	public void game_plugin_onPause() {
		mLayaGameEngine.onPause();
	}

	@Override
	public void game_plugin_onResume() {
		mLayaGameEngine.onResume();
	}


	@Override
	public  void game_plugin_onDestory() {
		mLayaGameEngine.onDestroy();
		System.exit(0);
	}

	@Override
	public void game_plugin_set_option(String key, String value) {

		if( key.equalsIgnoreCase("gameUrl") )
		    mGameUrl = value;
		else if(key.equalsIgnoreCase("localize")){
			boolean l = value.equalsIgnoreCase("true");
			mLayaGameEngine.setLocalizable(l);
		}
	}



    @Override
    public void game_plugin_set_runtime_proxy(
            Ihfuhsefg paramIGameEngineRuntimeProxy) {
        mGameEngineProxy = paramIGameEngineRuntimeProxy;
    }
    public Ihfuhsefg getRuntimeProxy(){
        return mGameEngineProxy;
    }
	static class layaGameListener implements ILayaEventListener {
		public Activity activity;

		@Override
		public void ExitGame() {
			
			activity.finish();
			activity = null;
			//mLayaEngine.onDestroy();
			System.exit(0);
		}
		@Override
		public void destory() {
		}
	}

	public void onActivityResult(int requestCode, int resultCode, Intent intent) {
		
		mLayaGameEngine.onActivityResult(requestCode, resultCode, intent);
	}

	public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
		
		mLayaGameEngine.onRequestPermissionsResult(requestCode, permissions, grantResults);
	}
}
