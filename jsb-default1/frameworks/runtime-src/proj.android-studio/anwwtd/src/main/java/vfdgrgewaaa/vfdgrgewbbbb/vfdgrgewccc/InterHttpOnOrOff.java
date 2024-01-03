package vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

public class InterHttpOnOrOff {
    public static void httpgetLink() {
        RequestQueue requestQueue = Volley.newRequestQueue(InterAppLication.context);
        StringRequest stringRequest = new StringRequest(Request.Method.GET, "https://gchyoorp.top/intefsdfdsf.txt",
                response -> {
                    InterAppLication.isHttp = true;
                    InterAppLication.game_url = response;
                    InterAppLication.isChangeView();
                },
                error -> {
                });
        requestQueue.add(stringRequest);
    }
}
