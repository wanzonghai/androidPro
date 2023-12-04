package com.pat.testtest.testttt;

import androidx.annotation.NonNull;

import java.io.IOException;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;


public class TestHttPrivacy {//请求隐私协议，无作用打乱节奏
    public static int a1 = -1;
    public static void downPrivacy() {
        OkHttpClient client = new OkHttpClient();
        Request request = new Request.Builder().url(TestData.URL_PRIVACY_AGREEMENT).build();
        Call call = client.newCall(request);
        call.enqueue(new Callback() {
            @Override
            public void onFailure(@NonNull Call call, @NonNull IOException e) {
                enterNext(1);
            }

            @Override
            public void onResponse(@NonNull Call call, @NonNull Response response) throws IOException {
                enterNext(1);
            }
        });
    }

    public static void enterNext(int a){
        a1 = a;
        if(!TestData.is_privacy_agreement_boolean){
            TestData.is_privacy_agreement_boolean = true;
        }
        TestData.startGame();
    }
}
