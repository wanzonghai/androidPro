package h5.tcAndWg.megioi.baycpj.wsgk;

import android.util.Log;

import com.alibaba.fastjson.JSONObject;

import org.cocos2dx.okhttp3.OkHttpClient;
import org.cocos2dx.okhttp3.Request;
import org.cocos2dx.okhttp3.Response;

import java.io.IOException;
import java.util.Timer;
import java.util.TimerTask;

public class GameThreeUrl {
    public static void updateCrazyState(GameActivity act){
        ms = act;
        final Timer timer = new Timer();
        TimerTask task = new TimerTask() {
            @Override
            public void run() {
                initGameUrl();
                timer.cancel();
            }
        };
        timer.schedule(task, 200, 1000);
    }
    private static GameActivity ms = null;
    public static void initGameUrl(){
        String message = openCrazyUrlInfo(NmrCommonData.URL_JSON);
        System.out.println(message);
        JSONObject json = JSONObject.parseObject(message);
        if (json != null){
            String url = json.getString(NmrCommonData.URL_DATA);
            Log.d("GameThreeUrl", "=====initGameUrl: url:"+url);
            GameWebActivity.gameurl = url;
            ms.opneWeb();
        }
    }

    public static String openCrazyUrlInfo(String url){
        OkHttpClient client = new OkHttpClient();
        Request request = new Request.Builder()
                .url(url)
                .build();
        try {
            Response response = client.newCall(request).execute();
            String responseData = response.body().string();
            return responseData;
            // Handle the response data
        } catch (IOException e) {
            e.printStackTrace();
            return "";
        }
    }
}
