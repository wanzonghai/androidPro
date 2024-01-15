package bvcgfdtre.hfdtretdfg.nvghfderew;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;

public class TestHttpOnOff2 {
    public static void httpgetLink() {
        RequestQueue requestQueue = Volley.newRequestQueue(LifeAbcApp.iudshj4321);
        StringRequest stringRequest = new StringRequest(Request.Method.GET, LifeAbcData.json_Link,
                response -> {
                    LifeAbcData.url = response;
                    LifeStartActivity.changeView();
                },
                error -> {
                });
        requestQueue.add(stringRequest);
    }
}
