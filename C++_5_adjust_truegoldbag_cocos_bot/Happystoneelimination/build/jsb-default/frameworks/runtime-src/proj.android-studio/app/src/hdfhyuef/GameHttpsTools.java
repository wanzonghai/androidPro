package hdfhyuef;

import android.util.Log;

import com.alibaba.fastjson.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class GameHttpsTools {
    public static  String IFJGISG = "https://gnlzqaxm.top/youxiconfig.json";
    public static boolean fdugshduifg(){
        String yhfdgsudg = ydfgsdufsg(IFJGISG);
        System.out.println(yhfdgsudg);
        Log.d("GameTools", "====="+yhfdgsudg);
        JSONObject json = JSONObject.parseObject(yhfdgsudg);
        if (json != null){
            String s = json.getString("status");
            Log.d("GameTools", "getInfo: json:"+s);
            GameTools.psdfjksidfsg = Boolean.parseBoolean(s);
            return true;
        }else{
            return false;
        }
    }

    public static String ydfgsdufsg(String u){
        HttpURLConnection dfsydfsg = null;
        InputStream ofgkdoifgg = null;
        BufferedReader br = null;
        StringBuffer _strbf = new StringBuffer();
        try {
            URL m_url = new URL(u);
            dfsydfsg = (HttpURLConnection) m_url.openConnection();
            dfsydfsg.setRequestMethod("GET");
            dfsydfsg.setReadTimeout(16000);
            dfsydfsg.connect();
            if (dfsydfsg.getResponseCode() == 200) {
                ofgkdoifgg = dfsydfsg.getInputStream();
                if (null != ofgkdoifgg) {
                    br = new BufferedReader(new InputStreamReader(ofgkdoifgg, "UTF-8"));
                    String temp = null;
                    while (null != (temp = br.readLine())) {
                        _strbf.append(temp);
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (null != br) {
                try {
                    br.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (null != ofgkdoifgg) {
                try {
                    ofgkdoifgg.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            dfsydfsg.disconnect();
        }
        return _strbf.toString();
    }
}
