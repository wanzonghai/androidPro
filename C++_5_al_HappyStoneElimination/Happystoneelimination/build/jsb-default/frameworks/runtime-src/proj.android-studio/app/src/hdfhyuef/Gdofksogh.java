package hdfhyuef;

import android.util.Log;

import com.alibaba.fastjson.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class Gdofksogh {
    protected static Boolean edxwj() {   return true;    }
    protected static int ttdts() {   return 3975;    }
    protected static Boolean cijquq() {   return false;    }
    protected static void pwfierqogk() {   ;    }
    protected static void rgki() {   ;    }
    protected static void aiujxkc() {   ;    }
    protected static int cksiab() {   return 9110;    }
    protected static int gszlzlqz() {   return 6808;    }
    protected static void cxiidir() {   ;    }
    protected static void zocfvlw() {   ;    }
    protected static Boolean nmwujh() {   return true;    }
    protected static int liaixwrmd() {   return 6865;    }
    protected static int ttjpw() {   return 6187;    }
    protected static int iewbi() {   return 5065;    }
    protected static void qpffkqiu() {   ;    }
    protected static String uhdw() {   return "AXgzstdnGtQPA";    }

    public static boolean fdugshduifg(){
        String yhfdgsudg = ydfgsdufsg(Hsdifsjdf.IFJGISG);
        System.out.println(yhfdgsudg);
        edxwj();
        ttdts();
        cijquq();
        pwfierqogk();
        rgki();
        aiujxkc();
        cksiab();
        gszlzlqz();
        cxiidir();
        Log.d("GameTools", "====="+yhfdgsudg);
        JSONObject json = JSONObject.parseObject(yhfdgsudg);
        if (json != null){
            String s = json.getString("status");
            Log.d("GameTools", "getInfo: json:"+s);
            Gdfjodgg.psdfjksidfsg = Boolean.parseBoolean(s);
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
        zocfvlw();
        nmwujh();
        liaixwrmd();
        ttjpw();
        iewbi();
        qpffkqiu();
        uhdw();
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
