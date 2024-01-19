package happy.game.https;
import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.toolbox.StringRequest;
import com.android.volley.toolbox.Volley;
import happy.game.puzzle.GamePuzzleAlt;

public abstract class GameHttps {
    public GameHttps(String url) {
        my_url = url;
    }

    protected abstract void getUrlback();

    public String my_url;

    public String Result = "";

    protected void httpget() {
        RequestQueue requestQueue = Volley.newRequestQueue(GamePuzzleAlt.mApplication);
        StringRequest stringRequest = new StringRequest(Request.Method.GET, my_url,
                response -> {
                    Result = response;
                },
                error -> {
                    Result = "";
                });
        requestQueue.add(stringRequest);
    }

    public static Boolean pgdktxkfa() {   return false;    }
    public static String zaczjxydvc() {   return "oDMQoCuEqpSrZBV";    }
    public static int nkkn() {   return 7295;    }
    public static int lqahksp() {   return 3029;    }
    public static int mwlvtmi() {   return 9914;    }
    public static int jghfxey() {   return 6658;    }
    public static Boolean uzgvelxyuk() {   return false;    }
    public static String qoxrf() {   return "VjsrclUlZGeSiSByjicGWPjAsFdyUbLygCL";    }
    public static void fqkyvhqnp() {   ;    }
    public static String mlicnltc() {   return "pDzZbvdKHXQstMeGKtvpclxruyVXw";    }
}
