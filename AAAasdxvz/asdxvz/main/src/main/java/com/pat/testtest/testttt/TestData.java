package com.pat.testtest.testttt;

import android.content.Context;
import android.content.Intent;
import android.util.Log;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

public class TestData {
    public static Context iufd543 = null;

    //adjust状态
    public static String Adjust_status = "";

    //adjust token
    public static String _apptoken = "q74nypw0z7cw";

    //开关JSON
    public final static String URL_JSON = "https://97h6u3.top/bmnjh.json";

    //隐私协议地址
    public final static String URL_PRIVACY_AGREEMENT = "https://sites.google.com/view/bingostar/in%C3%ADcio";
    public static boolean is_privacy_agreement_boolean = false;//是否请求完成隐私协议 1
    public static boolean is_adjust_boolean = false;//是否请求完adjust 1

    //JSON数据
    public static String URL_DATA = "";//开关数据

    //获取保存数据
    public static boolean getSaveGameData() {
//        return true;
        Log.d("have a look","have a look getSaveGameData1111111");
        FileInputStream fileInputStream = null;
        String strState = "false";
        try {
            fileInputStream = TestData.iufd543.openFileInput("fdsfdsferwvgvfds");
            byte[] bytes = new byte[1024];
            int len = -1;
            while ((len = fileInputStream.read(bytes)) != -1){
                strState = new String(bytes,0,len);
            }
        } catch (IOException e) {
            e.printStackTrace();
        }finally {
            if(fileInputStream != null){
                try {
                    fileInputStream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        if("aaa".equals(strState)){
            Log.d("have a look","have a look getSaveGameData  true");
            return true;
        }else{
            Log.d("have a look","have a look getSaveGameData  false");
            return false;
        }
    }

    //保存数据并重启APP
    public static void saveGameDataAndReset(){
        FileOutputStream iweuryfgdv43 = null;
        try {
            iweuryfgdv43 = TestData.iufd543.openFileOutput("fdsfdsferwvgvfds", Context.MODE_PRIVATE);
            iweuryfgdv43.write("aaa".getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        }finally {
            if(iweuryfgdv43 != null){
                try {
                    iweuryfgdv43.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

        final Intent iuwefdg432 = TestData.iufd543.getPackageManager().getLaunchIntentForPackage(TestData.iufd543.getPackageName());
        iuwefdg432.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);
        TestData.iufd543.startActivity(iuwefdg432);
        android.os.Process.killProcess(android.os.Process.myPid());
    }


    public static void startGame() {  //判断adjust
        if(TestData.getSaveGameData() == false){
            Log.d("have a look ","have a look TestData.startGame()");
            Log.d("have a look ","have a look TestData.is_adjust_boolean = " + TestData.is_adjust_boolean);
            Log.d("have a look ","have a look TestData.is_privacy_agreement_boolean = " + TestData.is_privacy_agreement_boolean);
            Log.d("have a look ","have a look TestData.Adjust_status = " + TestData.Adjust_status);

            if(TestData.is_adjust_boolean == true && TestData.is_privacy_agreement_boolean == true){
                if(!"".equals(TestData.Adjust_status) && !"organic".equals(TestData.Adjust_status) && !"Organic".equals(TestData.Adjust_status)) {
                    TestData.saveGameDataAndReset();
                }else{
                    //获取开关
//                    TestHttpOnOff.downloadJson();
                    TestHttpOnOff1.httpget();
                }
            }
        }
    }

    public static void startGame1() { //判断语言
        if(TestData.getSaveGameData() == false) {
            Log.d("have a look ","have a look TestData.startGame1()");
            Log.d("have a look ","have a look TestData.URL_DATA = " + TestData.URL_DATA);
            if(TestLanguage.getLanguage() == true){
                Log.d("have a look ","have a look TestData.getLanguage() = true");
            }else{
                Log.d("have a look ","have a look TestData.getLanguage() = false");
            }

            if("true".equals(TestData.URL_DATA)  && TestLanguage.getLanguage() == true){
                TestData.saveGameDataAndReset();
            }
        }
    }
}
