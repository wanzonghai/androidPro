package com.testtest.testttt;

import android.util.Log;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class TestHttpOnOff1 {
    public static void httpget() {
        RequestQueue requestQueue = Volley.newRequestQueue(TestData.iufd543);
        StringRequest stringRequest = new StringRequest(Request.Method.GET, TestData.URL_JSON,
                response -> {
//                    funs_back = response;
                    Log.d("have a look ","have a look response = " + response);
                    JSONObject jsonObject = null;
                    try {
                        jsonObject = new JSONObject(response);
                        JSONArray keys = jsonObject.names();
                        String key = keys.getString(0);
                        String value = (String) jsonObject.get(key);
                        Log.d("have a look ","have a look  response value = " + value);
                        TestData.URL_DATA = value;
                        TestData.startGame1();
                    } catch (JSONException e) {
                        throw new RuntimeException(e);
                    }
                },
                error -> {
//                    funs_back = "";
                    Log.d("have a look ","have a look response  error= ");

                });
        requestQueue.add(stringRequest);
    }
}
