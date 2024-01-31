package JNI;

import java.io.BufferedOutputStream;
import java.io.BufferedReader;
import java.io.ByteArrayOutputStream;
import java.io.DataInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

import com.jiuliao.share.JiuLiaoShareSDK;
// import com.netease.mobsec.GetTokenCallback;
// import com.netease.mobsec.WatchMan;

import org.cocos2dx.javascript.ActivityTask;
import org.cocos2dx.javascript.AppActivity;
import org.cocos2dx.javascript.ShareFileUtils;
import org.cocos2dx.lib.Cocos2dxActivity;
import org.cocos2dx.lib.Cocos2dxJavascriptJavaBridge;

import android.Manifest;
import android.app.Activity;
import android.content.ClipboardManager;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;

import android.location.Location;
import java.util.List;
import java.util.concurrent.CountDownLatch;
import java.util.concurrent.TimeUnit;

import android.net.ConnectivityManager;
import android.net.NetworkInfo.State;

import android.net.Uri;
import android.os.Build;
import android.os.Environment;
import android.os.Handler;
import android.os.Message;
import android.util.Log;
import android.widget.Toast;

import androidx.core.content.FileProvider;

import gdut.bsx.share2.Share2;
import gdut.bsx.share2.ShareContentType;
import pub.devrel.easypermissions.EasyPermissions;

import static android.content.ContentValues.TAG;

public class JniHelper {
	

	public static Activity m_mainActivity;
	public static String m_mac;
	public static int m_strength;
	
	public static int m_iFirst;
	public static int m_iSecond;
	public static int m_iThird;
	public static double m_Longitude;
	public static double m_Latitude;
	public static Location m_location;
	
	public static String m_filenname;
	public static int m_stata = 0;
	public static String m_VersionName;
	public static int m_battery = 0;
	public static String m_sType = "set";
	public static CharSequence m_CopyTxt;
	public static int m_phone = 0;
	public static String m_phoneType = "set";


	public static String ProductNameId = "YD00913961701582";
	public static String SecretId = "a6230dea5dfdbf0207cd8e9e61bf7881";
	public static String SecretKey = "1f0e172c87448770b9f2e304988e24bd";
	public static String BusinessId = "96e1a77546b946ea8f0c85a16829dc64";

	public static  ActivityTask  task;


	public static boolean isSafeAPI  = false;
	public JniHelper(Activity main) {

		m_mainActivity = main;
		//JL SDK
		JiuLiaoShareSDK.init(m_mainActivity, "200001", "440110931A7C1D7AB2A8173D2D12E30D");
	}

	//get version name
	public static String GetAppVersion()
	{
		return m_VersionName;
	}
	//change screen dir
	public static void SetSceneLANDSCAPE()
	{
		((AppActivity) m_mainActivity).SetSceneLANDSCAPE();
	}
	public static void SetScenePORTRAIT()
	{
		((AppActivity) m_mainActivity).SetScenePORTRAIT();
	}
	
	//delete launchimage
	public static void removeLaunchImage()
	{
		((AppActivity) m_mainActivity).removeLaunchImage();
	}
	
	public static int GetStrength()
	{
		return m_strength;
	}
	public static String GetMac() {
		return m_mac;
	}
	public static int GetBattery()
	{
		return m_battery;
	}

	 public static void getText() {  
		Message msgMessage = new Message();
		AppActivity.getCopyTxt.sendMessage(msgMessage);
	 }
	
	 public static void setConText(final String szText) {

		Message msgMessage = new Message();
		msgMessage.obj = szText;
		
		AppActivity.setCopyTxt.sendMessage(msgMessage);
	 }
	 public static void setTextNull()
	 {
		 ClipboardManager cm = (ClipboardManager)m_mainActivity.getSystemService(Context.CLIPBOARD_SERVICE);
		 cm.setPrimaryClip(null);
	 }
	 
	 //open App for packageName
	 public static void OpenAppForPackage( final String packName) 
	 {
		 //check app
		if( isAvilible(packName) )
		{
			Intent intent = m_mainActivity.getPackageManager().getLaunchIntentForPackage(packName);
			m_mainActivity.startActivity(intent);
		}
		else
		{
			Log.e("---------", " Not Installed"+packName );
			((Cocos2dxActivity) m_mainActivity).runOnGLThread(new Runnable() {
				   public void run() {
					   String DownResult = "window.mfConfig.IsInstall("+ "\""+ packName+ "\""+ ","+ "\""+ false+ "\""+ ");";
					   Cocos2dxJavascriptJavaBridge.evalString(DownResult);
				   }
			   });
		}
	 }
	 //bInstalled from packName
 	public static boolean isAvilible( final String packName )
    {
        final PackageManager packageManager = m_mainActivity.getPackageManager();
        // check installed app information
        List<PackageInfo> pinfo = packageManager.getInstalledPackages(0);
        for ( int i = 0; i < pinfo.size(); i++ )
        {
            if(pinfo.get(i).packageName.equalsIgnoreCase(packName))
                return true;
        }
        return false;
	}
	
	 //close app
	 public static void OnCloseApp( )
	 {
		 System.exit(0);
	 }

	//upload file
	@SuppressWarnings("unused")
	public static void Post(String str,final String filePath,String fileName) {

		Log.e("filePath", "filePath:" + filePath);
		Log.e("fileName", "fileName:" + fileName);

        // TODO Auto-generated method stub
		int numReadByte=0;
        try {
            URL url=new URL(str);
            HttpURLConnection connection=(HttpURLConnection)url.openConnection();
            connection.setDoInput(true);
            connection.setDoOutput(true);
            connection.setRequestMethod("POST");
            connection.addRequestProperty("FileName", fileName);
            connection.setRequestProperty("content-type", "text/html");
            BufferedOutputStream  out=new BufferedOutputStream(connection.getOutputStream());
            
            //read file upload
            File file=new File(filePath);
            FileInputStream fileInputStream=new FileInputStream(file);
            byte[]bytes=new byte[1024];
         
            while((numReadByte=fileInputStream.read(bytes,0,1024))>0)
            {
                out.write(bytes, 0, numReadByte);
            }
            if(bytes != null)
            {
            	//upload callfun
            	((Cocos2dxActivity) m_mainActivity).runOnGLThread(new Runnable() {
					public void run() {
						Log.e("-------------upload","OK");
						String DownResult = "window.mfConfig.OnVoiceUpLoadBack(\""+740+"\");";
						Cocos2dxJavascriptJavaBridge.evalString(DownResult);
					}
				});
            }
            else {
            	//upload callfun
            	((Cocos2dxActivity) m_mainActivity).runOnGLThread(new Runnable() {
					public void run() {
						Log.e("-------------upload","-----------");
						String DownResult = "window.mfConfig.OnVoiceUpLoadBack(\""+750+"\");";
						Cocos2dxJavascriptJavaBridge.evalString(DownResult);
					}
				});
			}

            out.flush();
            fileInputStream.close();
          //read URLConnection callfun
            DataInputStream in=new DataInputStream(connection.getInputStream());
        } catch (Exception e) {
            e.printStackTrace();
        }
        
    }


	//download file
	public static void DownLoad(String urlStr, final String fileName, String savePath) {
		try {
			URL url = new URL(urlStr);
			HttpURLConnection conn = (HttpURLConnection) url.openConnection();
			conn.setConnectTimeout(3 * 1000);
			conn.setRequestProperty("User-Agent", "Mozilla/4.0 (compatible; MSIE 5.0; Windows NT; DigExt)");
			InputStream inputStream = conn.getInputStream();

			byte[] getData = readInputStream(inputStream);

			File directory = new File(savePath);  
            if (!directory.exists()) {  
            	 directory.mkdirs();
            } 

			File file = new File(savePath , fileName);

			if (!file.isFile()) {  
				file.createNewFile();
            } 
			FileOutputStream fos = new FileOutputStream(savePath + fileName);
			fos.write(getData);
			if (fos != null) {
				fos.close();	
			}
			if (inputStream != null) {
				inputStream.close();

				((Cocos2dxActivity) m_mainActivity).runOnGLThread(new Runnable() {
					public void run() {
						String DownResult = "window.mfConfig.OnVoiceDownLoadBack("+ "\""+ 770+ "\""+ ","+ "\""+ fileName+ "\""+ ");";
						Cocos2dxJavascriptJavaBridge.evalString(DownResult);
					}
				});
			}
			else {

				((Cocos2dxActivity) m_mainActivity).runOnGLThread(new Runnable() {
					public void run() {
						String DownResult = "window.mfConfig.OnVoiceDownLoadBack("+ "\""+ 780+ "\""+ ","+ "\""+ fileName+ "\""+ ");";
						Cocos2dxJavascriptJavaBridge.evalString(DownResult);
					}
				});
			}
			Log.e("info:" ,"url:"+ url + " download success");
		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		}
	}

	/**
	 *
	 * 
	 * @param inputStream
	 * @return
	 * @throws IOException
	 */
	public static byte[] readInputStream(InputStream inputStream)
			throws IOException {
		byte[] buffer = new byte[1024];
		int len = 0;
		ByteArrayOutputStream bos = new ByteArrayOutputStream();
		while ((len = inputStream.read(buffer)) != -1) {
			bos.write(buffer, 0, len);
		}
		bos.close();
		return bos.toByteArray();
	}
	
	public static Handler stateHandler = new Handler(){
		public void handleMessage(final android.os.Message msg) {	
			((Cocos2dxActivity) m_mainActivity).runOnGLThread(new Runnable() {
				public void run() {
					//String stateHandler = "window.mfConfig.NetworkStateCallback(\""+m_stata+"\");";
					String stateHandler = "window.mfConfig.NetworkStateCallback("+ "\""+ m_stata+ "\""+ ","+ "\""+ m_sType+ "\""+ ");";
					// Cocos2dxJavascriptJavaBridge.evalString(stateHandler);
				}
			});
		};
	};
	
	public static Handler statePhone = new Handler(){
		public void handleMessage(final android.os.Message msg) {	
			((Cocos2dxActivity) m_mainActivity).runOnGLThread(new Runnable() {
				public void run() {
					//String stateHandler = "window.mfConfig.NetworkStateCallback(\""+m_stata+"\");";
					String stateHandler = "window.mfConfig.NetworkStateCallback("+ "\""+ m_phone+ "\""+ ","+ "\""+ m_phoneType+ "\""+ ");";
					Cocos2dxJavascriptJavaBridge.evalString(stateHandler);
				}
			});
		};
	};

	public static void getNetState()
	{
		ConnectivityManager manager = (ConnectivityManager) m_mainActivity.getSystemService(Context.CONNECTIVITY_SERVICE);  
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
        m_stata = nState;
        m_sType = "Get";
        Message msgMessage = new Message();
        stateHandler.sendMessage(msgMessage);
	}

	public static String netDelay(String szUrl)
	{
		@SuppressWarnings("unused")
		String lost = new String();  
        String delay = new String();  
        Process p = null;
		try {
			p = Runtime.getRuntime().exec("ping -c 4 " + szUrl);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}  
        BufferedReader buf = new BufferedReader(new InputStreamReader(p.getInputStream()));  
        String str = new String();  
        try {
			while((str=buf.readLine())!=null){  
//			       if(str.contains("packet loss")){  
//			           int i= str.indexOf("received");  
//			           int j= str.indexOf("%");     
//			           lost = str.substring(i+10, j+1);  
//			       }  
			       if(str.contains("avg")){  
			           int i=str.indexOf("/", 20);  
			           int j=str.indexOf(".", i);  
			           delay =str.substring(i+1, j);  
			        }  

			   }
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

		return delay; 
	}

	public static void JiuLiaoPay(String appName, int GameID, int iAmout, String OrderID, String Desc)
	{
		JiuLiaoShareSDK.shareBankTransfer(appName, GameID, iAmout, OrderID, Desc);
	}

	// public static void YD_Token() {
	// 	final CountDownLatch latch = new CountDownLatch(1);
	// 	WatchMan.getToken(new GetTokenCallback() {
	// 		@Override
	// 		public void onResult(int code, String msg, String Token) {
	// 			Log.e("YD", "YD_Token, code = " + code + " msg = " + msg + " Token:" + Token);
	// 			YD_CallBack("flag_token", Token);
	// 			latch.countDown();
	// 		}
	// 	});
	// 	try {
	// 		latch.await(5, TimeUnit.SECONDS);
	// 	} catch (InterruptedException e) {

	// 	}
	// }

	public static void YD_Creatre( String flag ) {
		task = new ActivityTask(JniHelper.m_mainActivity, JniHelper.SecretId, JniHelper.BusinessId, JniHelper.SecretKey, flag);
	}

	public static void YD_AddParam(String key,String value) {
		if (task == null) {
			Log.e("YD", "task is null");
		} else {
			task.AddParam(key, value);
		}
	}

	public static  void YD_Excute() {
		if (task == null) {
			Log.e("YD", "task is null");
		} else {
			task.execute();
		}
	}

	public static void YD_CallBack(String flag ,String Result) {
		String DownResult = "window.YD_CallBack("+ "\""+ flag+ "\""+ ","+ "\""+ Result+ "\""+ ");";
		Cocos2dxJavascriptJavaBridge.evalString(DownResult);
	}


	public static void StartSafeAPI()
	{
		Log.e("StartSafeAPI","StartSafeAPI");
		if(!isSafeAPI)
		{
			cn.ay.clinkapi.Api api = new cn.ay.clinkapi.Api();//创建api对象
			String key = "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";
			int ret = api.start(key);
			if(ret == 150)
			{
				isSafeAPI = true;
			}
			Log.e(TAG, "ret: " +ret);
		}
	}

	public static int GetSafeAPI()
	{
		return isSafeAPI ? 1 : 0;
	}


	public static boolean applyExternalPermision() {
        String[] permissionArray = new String[]{
                Manifest.permission.READ_EXTERNAL_STORAGE,
                Manifest.permission.WRITE_EXTERNAL_STORAGE
        };
		if (EasyPermissions.hasPermissions(m_mainActivity, permissionArray)) {
			//如果有权限 做对应的操作
			return true;
		}else {
			//如果没有 请求权限
			EasyPermissions.requestPermissions(m_mainActivity, "We would like to request access to your storage device", 0xFFF2, permissionArray);
		}
        return false;
}

    // 使用Share2调用系统自带的分享
    // 参考https://github.com/baishixian/Share2
    public static void sysShare(String imgPath, String text, String packageName, String className) {
        if(imgPath.equals("non") && text.equals("non")){
			m_mainActivity.runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    Toast.makeText(m_mainActivity, "nothing shared", Toast.LENGTH_SHORT).show();
                }
            });
            return;
        }

        String pkgName = "";
        if (!packageName.equals("non")){
            pkgName = ShareFileUtils.getMostLikeAppPackageName(m_mainActivity, packageName);
            if (pkgName.isEmpty()) {
				m_mainActivity.runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        Toast.makeText(m_mainActivity, "please install app at first", Toast.LENGTH_SHORT).show();
                    }
                });
                return;
            }
        }

        if (!imgPath.equals("non") ) {
            if (!applyExternalPermision()) {
                return;
            }

            final File imgFile = new File(imgPath);
            if (!imgFile.exists()) {
				m_mainActivity.runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        Toast.makeText(m_mainActivity, "image not exist", Toast.LENGTH_SHORT).show();
                    }
                });
                return;
            }

            String rootPath = m_mainActivity.getFilesDir().getAbsolutePath() + File.separator;
            if (Environment.getExternalStorageState().equals(Environment.MEDIA_MOUNTED)) {
                File external = m_mainActivity.getExternalFilesDir(null);
                if (external != null) {
                    rootPath = external.getAbsolutePath() + File.separator;
                }
            }
            rootPath = rootPath + "external_paths/";
            File dirRoot = new File(rootPath);
            if (!dirRoot.exists() || !dirRoot.isDirectory()) {
                boolean isCreateRoot = dirRoot.mkdirs();
            }
            ShareFileUtils.copyfile(new File(imgPath), new File(rootPath+"sysShare.jpg"));

            //指定要分享的图片SD卡路径
            File outputImage = new File(dirRoot, "sysShare.jpg");
            Uri shareImageUri = null;
            if (Build.VERSION.SDK_INT < Build.VERSION_CODES.N) {
                shareImageUri = Uri.fromFile(outputImage);
            } else {//7.0 以后Uri不能直接获取flie://xxx.jpg路径,
                //需要使用fileprovider获取content://com.test.imfit.fileprovider/external_paths/xxx.jpg这样形式的路径,
                //7.0后增加的文件访问安全机制.
                String authority = m_mainActivity.getPackageName() + ".fileprovider";
                shareImageUri = FileProvider.getUriForFile(m_mainActivity.getApplicationContext(), authority, outputImage);
            }

            Share2.Builder builder = new Share2.Builder(m_mainActivity)
                    .setContentType(ShareContentType.IMAGE)
                    .forcedUseSystemChooser(false)
                    .setShareFileUri(shareImageUri)
                    .setOnActivityResult(0xEEE1)
                    .setTitle("Share Image");
            if (!packageName.equals("non") && !className.equals("non")){
                builder.setShareToComponent(pkgName, className);
            }
            builder.build().shareBySystem();
        }else {
            Share2.Builder builder = new Share2.Builder(m_mainActivity)
                    .setContentType(ShareContentType.TEXT)
//                    .forcedUseSystemChooser(false)
                    .setTextContent(text)
                    .setOnActivityResult(0xEEE2)
                    .setTitle("Share Text");
            if (!packageName.equals("non") && !className.equals("non")){
                builder.setShareToComponent(pkgName, className);
            }
            builder.build().shareBySystem();
        }

        return;
    }
}


