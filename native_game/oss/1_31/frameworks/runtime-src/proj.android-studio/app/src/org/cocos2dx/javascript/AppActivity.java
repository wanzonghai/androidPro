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
package org.cocos2dx.javascript;

import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxGLSurfaceView;

import android.os.Bundle;

import android.content.Context;
import android.content.Intent;
import android.content.res.Configuration;

import java.util.UUID;


import com.casualpoker.six.R;
import org.cocos2dx.lib.Cocos2dxJavascriptJavaBridge;

import JNI.JniHelper;

import android.content.BroadcastReceiver;
import android.content.ClipData;
import android.content.ClipData.Item;
import android.content.ClipDescription;
import android.content.ClipboardManager;
import android.content.ClipboardManager.OnPrimaryClipChangedListener;
import android.content.IntentFilter;
import android.content.pm.ActivityInfo;
import android.content.pm.PackageManager;
import android.location.LocationManager;
import android.net.ConnectivityManager;
import android.net.NetworkInfo.State;
import android.net.Uri;

import android.net.wifi.WifiInfo;
import android.net.wifi.WifiManager;
import android.os.Build;
import android.os.Handler;
import android.os.Message;
import android.text.TextUtils;
import android.util.Log;
import android.view.WindowManager;
import android.webkit.ValueCallback;
import android.webkit.WebView;
import android.widget.ImageView;
import android.view.View;




public class AppActivity extends Cocos2dxActivity {
	
	public JniHelper jniHelper;
	public WebView mWebView;
	static Context mContext;
	 
	private MyReceiver networkBroadcast;
	private LocationManager locationManager;
	protected static Handler mUIHandler;
	private static ImageView mWelcome = null;

	
	private ValueCallback<Uri> mUploadMessage;
	public ValueCallback<Uri[]> uploadMessage;
	public static final int REQUEST_SELECT_FILE = 100;
	private final static int FILECHOOSER_RESULTCODE = 2;

	public final static int REQUEST_IMAGE_CAPTURE = 1;

	//splash
 	protected ImageView createLaunchImage() 
 	{
         mWelcome = new ImageView(this);
         this.getWindow().getDecorView().setBackground(null);  
         mWelcome.setImageResource(R.mipmap.splash);
         mWelcome.setScaleType(ImageView.ScaleType.CENTER_CROP);
         return mWelcome;
     };
	
	@Override
    protected void onCreate(Bundle savedInstanceState) {
    	super.onCreate(savedInstanceState);
        
        mUIHandler = new Handler();

        addContentView(createLaunchImage(),
        new WindowManager.LayoutParams(
        WindowManager.LayoutParams.FLAG_FULLSCREEN,
        WindowManager.LayoutParams.FLAG_FULLSCREEN));
        
        jniHelper = new JniHelper(this);

        mContext = this;
        JniHelper.m_mac = getDeviceId();
        
      //keep screen on
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        //网络状态
        networkBroadcast = new MyReceiver();
        IntentFilter filter = new IntentFilter(ConnectivityManager.CONNECTIVITY_ACTION);  
        this.registerReceiver(networkBroadcast, filter); 
       
        //Battery
		IntentFilter intentFilter = new IntentFilter(Intent.ACTION_BATTERY_CHANGED);
		GetBattery batteryReceiver = new GetBattery();
		this.registerReceiver(batteryReceiver, intentFilter);

		//wifi
		IntentFilter wifiintentFilter = new IntentFilter(WifiManager.RSSI_CHANGED_ACTION);
		WifiChangeBroadcastReceiver wifiChange = new WifiChangeBroadcastReceiver();
		this.registerReceiver(wifiChange, wifiintentFilter);

		//text
		testClipboard();

		//version name
		getVerName(this);
        SDKWrapper.getInstance().init(this);
        //初始化AppsFlyer SDK
        AppsFlyerSDK.getInstance().initSdk(this);


    }
	
    public void removeLaunchImage() {
    	
        mUIHandler.post(new Runnable() {
            @Override
            public void run() {
                if (mWelcome != null) {
                    mWelcome.setVisibility(View.GONE);
                }
            }
        });
    }

    //SceneLANDSCAPE PORTRAIT
    public void SetSceneLANDSCAPE() {
    	
    	setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_LANDSCAPE);

    }
    public void SetScenePORTRAIT() {
    	
    	setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);
    }
    @Override
    public Cocos2dxGLSurfaceView onCreateView() {
        Cocos2dxGLSurfaceView glSurfaceView = new Cocos2dxGLSurfaceView(this);
        // TestCpp should create stencil buffer
        glSurfaceView.setEGLConfigChooser(5, 6, 5, 0, 16, 8);

        SDKWrapper.getInstance().setGLSurfaceView(glSurfaceView);

        return glSurfaceView;
    }

    @Override
    protected void onResume() {
    	
    	 //keep screen on
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
        
        super.onResume();
        SDKWrapper.getInstance().onResume();
    }

    @Override
    protected void onPause() {
    	
    	//keep screen off
    	getWindow().clearFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        super.onPause();
        SDKWrapper.getInstance().onPause();
    }

    @Override
    protected void onDestroy() {
    	
        super.onDestroy();
        SDKWrapper.getInstance().onDestroy();
    }


	@Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data)
    {
        super.onActivityResult(requestCode, resultCode, data);
        SDKWrapper.getInstance().onActivityResult(requestCode, resultCode, data);
        
		if (requestCode == FILECHOOSER_RESULTCODE)
        {
    	 //  mUploadMessage = Cocos2dxWebView.getMessage();
    	   Log.e("mUploadMessage", "mUploadMessage:"+mUploadMessage);
            if (null == mUploadMessage)
                return;
   
            Uri result = data == null || resultCode != Cocos2dxActivity.RESULT_OK ? null : data.getData();
            mUploadMessage.onReceiveValue(result);
            mUploadMessage = null;
        }
        else
		{
			((Cocos2dxActivity) JniHelper.m_mainActivity).runOnGLThread(new Runnable() {
				public void run() {
					String getTXT = "window.mfConfig.onShareCallBack();";
					Cocos2dxJavascriptJavaBridge.evalString(getTXT);
				}
			});
					
//			Toast.makeText(getBaseContext(), "Failed to Upload Image", Toast.LENGTH_LONG).show();
		}
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
    	
    	 //keep screen on
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);
        
        SDKWrapper.getInstance().onStart();
        super.onStart();
        
    }
    
    //WIFI change
    public class MyReceiver extends BroadcastReceiver {  
        @SuppressWarnings("static-access")
		@Override  
        public void onReceive(Context context, Intent intent) {  
            // TODO Auto-generated method stub  
            //Toast.makeText(context, intent.getAction(), 1).show();  
            ConnectivityManager manager = (ConnectivityManager) context.getSystemService(Context.CONNECTIVITY_SERVICE);  
            State mobileInfo = manager.getNetworkInfo(ConnectivityManager.TYPE_MOBILE).getState();  
            State wifiInfo = manager.getNetworkInfo(ConnectivityManager.TYPE_WIFI).getState();
            int nState = 0;
          
            if (wifiInfo != null && mobileInfo != null  
                    && State.CONNECTED != wifiInfo  
                    && State.CONNECTED == mobileInfo) 
            {  
            	nState = 606;
            } 
            else if (wifiInfo != null && mobileInfo != null  
                    && State.CONNECTED != wifiInfo  
                    && State.CONNECTED != mobileInfo) 
            {  
            	nState = 607;
            }
  
            else if (wifiInfo != null && State.CONNECTED == wifiInfo) {  
            	nState = 605;
            }
            jniHelper.m_stata = nState;
            jniHelper.m_sType = "Change";
            Message msgMessage = new Message();
            jniHelper.stateHandler.sendMessage(msgMessage); 
        } 
    }


	public static String getDeviceId() {
	//        Log.d(TAG, getDeviceInfo());
        // 因为原先的版本需要获取电话权限，用户反感这个问题
        // 将设备号获取方式修改一下
        String serial = null;

        String m_szDevIDShort = "35" +
                Build.BOARD.length() % 10 + Build.BRAND.length() % 10 +

                Build.CPU_ABI.length() % 10 + Build.DEVICE.length() % 10 +

                Build.DISPLAY.length() % 10 + Build.HOST.length() % 10 +

                Build.ID.length() % 10 + Build.MANUFACTURER.length() % 10 +

                Build.MODEL.length() % 10 + Build.PRODUCT.length() % 10 +

                Build.TAGS.length() % 10 + Build.TYPE.length() % 10 +

                Build.USER.length() % 10; //13 位

        try {
            serial = Build.class.getField("SERIAL").get(null).toString();
            //API>=9 使用serial号
            return new UUID(m_szDevIDShort.hashCode(), serial.hashCode()).toString();
        } catch (Exception exception) {
            //serial需要一个初始化
            serial = String.valueOf(System.currentTimeMillis()); // 随便一个初始化
        }

        //使用硬件信息拼凑出来的15位号码
        return new UUID(m_szDevIDShort.hashCode(), serial.hashCode()).toString();
    }
	
	//Battery
	public class GetBattery extends BroadcastReceiver{
		
		@SuppressWarnings("static-access")
		public void onReceive(Context context, Intent intent) {
			// TODO Auto-generated method stub

			if(Intent.ACTION_BATTERY_CHANGED.equals(intent.getAction())){
				int level = intent.getIntExtra("level", 0);
				int scale = intent.getIntExtra("scale", 100);
				jniHelper.m_battery = (level*100)/scale; 
			}
		}		
	}
	//wifiLevel
	public class WifiChangeBroadcastReceiver extends BroadcastReceiver {  
        private Context mContext;  
        @Override  
        public void onReceive(Context context, Intent intent) {  
            mContext=context;  
            System.out.println("Wifi�����仯");  
            getWifiInfo();  
        }  
          
        @SuppressWarnings("static-access")
		private void getWifiInfo() 
        {  
            WifiManager wifiManager = (WifiManager) mContext.getSystemService(mContext.WIFI_SERVICE);  
            WifiInfo wifiInfo = wifiManager.getConnectionInfo();  
            if (wifiInfo.getBSSID() != null) {
                String ssid = wifiInfo.getSSID();
                int signalLevel = WifiManager.calculateSignalLevel(wifiInfo.getRssi(), 100);
                int speed = wifiInfo.getLinkSpeed();
                String units = WifiInfo.LINK_SPEED_UNITS;
                jniHelper.m_strength = signalLevel;
            }  
       }  
	}
	
	//set text
	public static Handler setCopyTxt = new Handler()
	{
		public void handleMessage(Message msg) {
			ClipboardManager cm = (ClipboardManager) JniHelper.m_mainActivity.getSystemService(Context.CLIPBOARD_SERVICE);
			cm.setPrimaryClip(ClipData.newPlainText(null, (String)msg.obj));

		};
	};

	//get text
	public static Handler getCopyTxt = new Handler()
	{
		 
		public void handleMessage(Message msg) {
			
			 ClipboardManager cmb = (ClipboardManager)JniHelper.m_mainActivity.getSystemService(Context.CLIPBOARD_SERVICE);
		
			 if (cmb.hasPrimaryClip()){
				
				 JniHelper.m_CopyTxt = cmb.getPrimaryClip().getItemAt(0).getText();  // ��ȡ���� 
				 
				 ((Cocos2dxActivity) JniHelper.m_mainActivity).runOnGLThread(new Runnable() {
						public void run() {
							String getTXT = "window.mfConfig.onTextCallBack(\""+ JniHelper.m_CopyTxt + "\");";
							Cocos2dxJavascriptJavaBridge.evalString(getTXT);
						}
					});
				
			 }
			 
		};
	};
	
	 public static void getVerName(Context context) {
	
	        String verName = "";
	        try {
	            verName = context.getPackageManager().
	                    getPackageInfo(context.getPackageName(), 0).versionName;
	        } catch (PackageManager.NameNotFoundException e) {
	            e.printStackTrace();
	        }
	 
	        JniHelper.m_VersionName = verName;
	  };


	
	//listen text change
	 private void testClipboard() {  
	        final ClipboardManager clipboardManager = (ClipboardManager) getSystemService(CLIPBOARD_SERVICE);  
	        clipboardManager.addPrimaryClipChangedListener(new OnPrimaryClipChangedListener() {  
	  
	            @Override  
	            public void onPrimaryClipChanged() {  
	                if (clipboardManager.hasPrimaryClip()) {  
	                    if (clipboardManager.getPrimaryClipDescription().hasMimeType(  
	                            ClipDescription.MIMETYPE_TEXT_PLAIN)) {  
	                        ClipData primaryClip = clipboardManager.getPrimaryClip();  
	                        if (primaryClip != null) {  
	  
	                            final Item item = primaryClip.getItemAt(0);  
	                            if (item != null && !TextUtils.isEmpty(item.getText().toString())) {  
	                            	
	                            	((Cocos2dxActivity) JniHelper.m_mainActivity).runOnGLThread(new Runnable() {
	            						public void run() {
	            							String getTXT = "window.mfConfig.TextListenCallBack(\""+ item.getText().toString() + "\");";
	            							Cocos2dxJavascriptJavaBridge.evalString(getTXT);
	            						}
	            					});
	                            }  
	                        }  
	  
	                    }  
	                } else {  
	  
	                	Log.e(" clip","now clip  is empty");
	                }  
	  
	            }  
	       });  
	 }
}
