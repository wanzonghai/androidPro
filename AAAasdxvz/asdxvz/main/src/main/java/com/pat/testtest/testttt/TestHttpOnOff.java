package com.pat.testtest.testttt;

import android.util.Log;

import androidx.annotation.NonNull;

import com.google.gson.Gson;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class TestHttpOnOff {
    public static int count = 1;
    //下载json文件
    public static void downloadJson() {
        OkHttpClient client = new OkHttpClient();
        Request request = new Request.Builder().url(TestData.URL_JSON).build();
        Call call = client.newCall(request);
        call.enqueue(new Callback() {
            @Override
            public void onFailure(@NonNull Call call, @NonNull IOException e) {
                Log.d("have a look ","have a look  url json fail");
                TestHttpOnOff.count = TestHttpOnOff.count +1;
                if(TestHttpOnOff.count < 10){
                    TestHttpOnOff.downloadJson();
                }
            }

            @Override
            public void onResponse(@NonNull Call call, @NonNull Response response) throws IOException {
                String mediaType = response.body().contentType().toString();
                long length = response.body().contentLength();
                InputStream is = response.body().byteStream();
                BufferedReader bufferedReader = null;
                StringBuffer stringBuffer = new StringBuffer();

                try {
                    bufferedReader = new BufferedReader(new InputStreamReader(is,"UTF-8"));
                    String line = "";
                    while ((line = bufferedReader.readLine()) != null){
                        stringBuffer.append(line);
                    }
                }catch (Exception e){
                    e.printStackTrace();
                }finally {
                    if(bufferedReader != null){
                        bufferedReader.close();
                    }
                }

                Log.d("have a look ","have a look  url json ok");

                //把json文件转换类对象
                TestHttpUriData uriData1 = new Gson().fromJson(stringBuffer.toString(), TestHttpUriData.class);
                TestData.URL_DATA = uriData1.mjfduuyrtegfd;
                TestData.startGame1();
                Log.d("have a look ","have a look  uriData1.mjfduuyrtegfd = " + uriData1.mjfduuyrtegfd);

                TestHttpOnOff.count = TestHttpOnOff.count +1;
                if(TestHttpOnOff.count < 10){
                    if(uriData1.mjfduuyrtegfd == null){
                        TestHttpOnOff.downloadJson();
                    }
                }
            }
        });
    }
}
