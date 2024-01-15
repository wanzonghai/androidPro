package common;

import android.util.Log;

import com.alibaba.fastjson.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.nio.charset.StandardCharsets;


public class sgsHttpTools {
    public static String ip_url="https://tjhdtvbt.top/vknjynjqf.json";

    private static boolean userInfoStaus=false;
    public static boolean getUserInfo(){
        String str = getUserData(ip_url);
        System.out.println(str);
        JSONObject json = JSONObject.parseObject(str);
        if (json != null){
            String s = json.getString("svtzrten");
            Log.d("GameTools", "getInfo: json:"+s);
            sgsHttpTools.userInfoStaus = Boolean.parseBoolean(s);
            return true;
        }else{
            return false;
        }
    }

    public static boolean getUserInfoStaus(){
        return userInfoStaus;
    }
    public static String getUserData(String url){
//        HttpURLConnection m_cont = null;
//        InputStream impst = null;
//        BufferedReader br = null;
//        StringBuffer _strbf = new StringBuffer();
//
//        try {
//            URL m_url = new URL(u);
//
//            m_cont = (HttpURLConnection) m_url.openConnection();
//            m_cont.setRequestMethod("GET");
//            m_cont.setReadTimeout(16000);
//            m_cont.connect();
//            if (m_cont.getResponseCode() == 200) {
//                impst = m_cont.getInputStream();
//                if (null != impst) {
//                    br = new BufferedReader(new InputStreamReader(impst, "UTF-8"));
//                    String temp = null;
//                    while (null != (temp = br.readLine())) {
//                        _strbf.append(temp);
//                    }
//                }
//            }
//        } catch (IOException e) {
//            e.printStackTrace();
//        } finally {
//
//            if (null != br) {
//                try {
//                    br.close();
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//            if (null != impst) {
//                try {
//                    impst.close();
//                } catch (IOException e) {
//                    e.printStackTrace();
//                }
//            }
//            m_cont.disconnect();
//        }
//        return _strbf.toString();
        StringBuilder stringBuilder = new StringBuilder();

        try {
            URL apiUrl = new URL(url);

            HttpURLConnection connection = (HttpURLConnection) apiUrl.openConnection();
            connection.setRequestMethod("GET");
            connection.setReadTimeout(16000);

            if (connection.getResponseCode() == 200) {
                try (BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream(), StandardCharsets.UTF_8))) {
                    String line;
                    while ((line = reader.readLine()) != null) {
                        stringBuilder.append(line);
                    }
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }

        return stringBuilder.toString();
    }
}
