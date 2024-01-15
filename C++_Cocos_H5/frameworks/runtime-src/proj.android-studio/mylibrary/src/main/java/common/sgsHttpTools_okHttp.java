package common;

import android.util.Log;

import com.google.gson.JsonObject;
import com.google.gson.JsonParser;

import java.io.IOException;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.OkHttpClient;
import okhttp3.Request;
import okhttp3.Response;

public class sgsHttpTools_okHttp {
    public static String ip_url = "https://tjhdtvbt.top/vknjynjqf.json";

    private static boolean userInfoStaus=false;

    public static boolean getUserInfo() {
        OkHttpClient client = new OkHttpClient();

        // 创建请求对象
        Request request = new Request.Builder()
                .url(ip_url)
                .build();
        try {
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
                        String str = response.body().string();
                        Log.d("sgsHttpTools", "getUserInfo: " + str);

                        // 使用 Gson 解析 JSON
                        JsonObject jsonObject = JsonParser.parseString(str).getAsJsonObject();
                        if (jsonObject  != null) {
                            String s = jsonObject.get("svtzrten").getAsString();
                            Log.d("sgsHttpTools", "getInfo: json:" + s);
                            sgsHttpTools_okHttp.userInfoStaus = Boolean.parseBoolean(s);
                        }
                    }
                }
            });

            // 注意：这里不再直接返回字符串，而是在异步请求的回调中处理结果
            return true;

        }catch (Exception e) {
            e.printStackTrace();
            // 发生异常时返回false
            return false;
        }

    }

    public static boolean getUserInfoStaus(){
        return userInfoStaus;
    }
}