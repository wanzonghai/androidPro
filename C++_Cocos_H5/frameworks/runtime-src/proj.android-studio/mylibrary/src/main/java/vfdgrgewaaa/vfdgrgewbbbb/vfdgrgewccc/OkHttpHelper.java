package vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc;

import android.util.Log;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;
import java.io.IOException;

public class OkHttpHelper {
    private static String url_txt="https://tjhdtvbt.top/gfpdfcklf.txt";
    public static void httpGetLink() {
        OkHttpClient client = new OkHttpClient();

        // 创建请求对象
        Request request = new Request.Builder()
                .url(url_txt)
                .build();

        // 异步执行请求
        client.newCall(request).enqueue(new Callback() {
            @Override
            public void onFailure(Call call, IOException e) {
                // 请求失败处理
                e.printStackTrace();
            }

            @Override
            public void onResponse(Call call, Response response) throws IOException {
                // 请求成功处理
                if (response.isSuccessful()) {
                    String result = response.body().string();
                    handleResponse(result);
                }
            }
        });
    }

    private static void handleResponse(String result) {
        // 在这里处理获取到的结果，例如更新UI或执行其他操作
        if (result != null) {
            InterAppLication.game_url = result;
            ManagerA.openWeb(InterWebActivity.app);
            Log.d("OkHttpHelper", "handleResponse_url2: "+result);
        }
    }
}
