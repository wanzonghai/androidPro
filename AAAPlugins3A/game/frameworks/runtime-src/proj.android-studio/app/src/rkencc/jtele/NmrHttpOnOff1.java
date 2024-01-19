//package rkencc.jtele;
//
//import android.util.Log;
//
//import com.android.volley.Request;
//import com.android.volley.RequestQueue;
//import com.android.volley.toolbox.StringRequest;
//import com.android.volley.toolbox.Volley;
//
//import org.json.JSONArray;
//import org.json.JSONException;
//import org.json.JSONObject;
//
//public class NmrHttpOnOff1 {
////    public static void httpget() {
////        RequestQueue requestQueue = Volley.newRequestQueue(NmrCommonData.iufd543);
////        StringRequest stringRequest = new StringRequest(Request.Method.GET, NmrCommonData.URL_JSON,
////                response -> {
//////                    funs_back = response;
////                    Log.d("downloadJson ","downloadJson response = " + response);
////                    JSONObject jsonObject = null;
////                    try {
////                        jsonObject = new JSONObject(response);
////                        JSONArray keys = jsonObject.names();
////                        String key = keys.getString(0);
////                        String value = (String) jsonObject.get(key);
////                        Log.d("downloadJson ","downloadJson  response value = " + value);
////                        NmrCommonData.URL_DATA = value;
////                        NmrCommonData.JudgmentLang();
////                    } catch (JSONException e) {
////                        throw new RuntimeException(e);
////                    }
////                },
////                error -> {
//////                    funs_back = "";
////                    Log.d("downloadJson ","downloadJson response  error= ");
////
////                });
////        requestQueue.add(stringRequest);
////    }
//}
