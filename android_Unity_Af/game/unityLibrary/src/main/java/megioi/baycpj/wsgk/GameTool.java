package megioi.baycpj.wsgk;

import android.content.Context;
import android.content.res.Configuration;
import android.os.AsyncTask;
import android.util.Log;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Calendar;
import java.util.Locale;
import java.util.TimeZone;
import java.util.Timer;
import java.util.TimerTask;

import static android.content.ContentValues.TAG;

public class GameTool {
    private static boolean networkIsBR = false;
    private static final String API_URL = "http://ip-api.com/json";
    private static class IPCheckTask extends AsyncTask<Void, Void, String> {
        @Override
        protected String doInBackground(Void... params) {
            HttpURLConnection connection = null;
            BufferedReader reader = null;
            try {
                URL url = new URL(API_URL);
                connection = (HttpURLConnection) url.openConnection();
                connection.setRequestMethod("GET");
                connection.setConnectTimeout(5000);
                connection.setReadTimeout(5000);

                reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
                StringBuilder response = new StringBuilder();
                String line;
                while ((line = reader.readLine()) != null) {
                    response.append(line);
                }
                Log.d("abc======GameTools", "ip:"+response.toString());
                return response.toString();
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                if (connection != null) {
                    connection.disconnect();
                }
                if (reader != null) {
                    try {
                        reader.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
            }
            return null;
        }

        @Override
        protected void onPostExecute(String response) {
            if (response != null) {
                try {
                    JSONObject jsonObject = new JSONObject(response);
                    Log.d("abc======GameTools", "jsonObject:"+jsonObject);
                    String country = jsonObject.optString("country");
                    Log.d("abc======GameTools", "country:"+country);
                    if (country.equals("Brazil")) {
                        Log.d("abc======GameTools", "The current IP address is in Brazil");
                        networkIsBR = true;
                    } else if(country.equals("Mexico")){
                        Log.d("abc======GameTools", "The current IP address is in Mexico");
                        networkIsBR = true;
                    }else {
                        Log.d("abc======GameTools", "The current IP address is not in Mexico");
                        networkIsBR = false;
                    }
                } catch (JSONException e) {
                    e.printStackTrace();
                }
            } else {
                Log.d("abc======GameTools", "Failed to retrieve the current IP address");
                networkIsBR = false;
            }
        }

    }

//    public static boolean getTimeZoneIsBR(){
//        TimeZone timeZone = TimeZone.getDefault();
//        Calendar calendar = Calendar.getInstance(timeZone);
//        String timeZoneID = timeZone.getID();
//        Locale locale = Locale.getDefault();
//        String country = locale.getCountry();
//        Log.d("abc======GameTools", "时区ID: " + timeZoneID);
//        Log.d("abc======GameTools", "country: " + country);
//        boolean zoneId = (timeZoneID.equals("America/Sao_Paulo") || timeZoneID.equals("America/Rio_de_Janeiro") || timeZoneID.equals("America/Fortaleza") || timeZoneID.equals("America/Manaus")
//                || timeZoneID.equals("America/Porto_Velho") || timeZoneID.equals("America/Bahia") || timeZoneID.equals("America/Noronha") || timeZoneID.equals("America/Cuiaba")
//                || timeZoneID.equals("America/Rio_Branco"))|(timeZoneID.equals("America/Mexico_City") || timeZoneID.equals("America/Cancun") || timeZoneID.equals("America/Merida") || timeZoneID.equals("America/Monterrey")
//                || timeZoneID.equals("America/Matamoros") || timeZoneID.equals("America/Mazatlan") || timeZoneID.equals("America/Chihuahua") || timeZoneID.equals("America/Hermosillo")
//                || timeZoneID.equals("America/Tijuana"));
//        if (zoneId && country.equals("BR")) {
//            Log.d("abc======GameTools", "当前手机时区为巴西。");
//            return true;
//        } else if (zoneId && country.equals("MX")) {
//            Log.d("abc======GameTools", "当前手机时区为墨西哥。");
//            return true;
//        } else {
//            Log.d("abc=====GameTools", "当前手机时区不是巴西。");
//            return false;
//        }
//    }

    public static boolean getTimeZoneIsBR() {
        TimeZone timeZone = TimeZone.getDefault();
        String timeZoneID = timeZone.getID();
        Locale locale = Locale.getDefault();
        String country = locale.getCountry();
        Log.d("abc======GameTools", "时区ID: " + timeZoneID);
        Log.d("abc======GameTools", "country: " + country);
        boolean zoneId = timeZoneID.equals("America/Sao_Paulo") || timeZoneID.equals("America/Rio_de_Janeiro") || timeZoneID.equals("America/Fortaleza") || timeZoneID.equals("America/Manaus")
                || timeZoneID.equals("America/Porto_Velho") || timeZoneID.equals("America/Bahia") || timeZoneID.equals("America/Noronha") || timeZoneID.equals("America/Cuiaba")
                || timeZoneID.equals("America/Rio_Branco")
                || timeZoneID.equals("America/Mexico_City")
                || timeZoneID.equals("America/Cancun")
                || timeZoneID.equals("America/Merida")
                || timeZoneID.equals("America/Monterrey")
                || timeZoneID.equals("America/Matamoros")
                || timeZoneID.equals("America/Mazatlan")
                || timeZoneID.equals("America/Chihuahua")
                || timeZoneID.equals("America/Hermosillo")
                || timeZoneID.equals("America/Tijuana");
        if (zoneId && country.equals("BR")) {
            Log.d("abc======GameTools", "当前手机时区为巴西。");
            return true;
        }else if (zoneId && country.equals("MX")) {
            Log.d("abc======GameTools", "当前手机时区为墨西哥。");
            return true;
        }
        else {
            Log.d("abc======GameTools", "当前手机时区不是巴西。");
            return false;
        }
    }

    public static boolean getIpIsBR(){
        new IPCheckTask().execute();
        Log.d("abc=====getIpIsBR", "networkIsBR"+networkIsBR);
        return networkIsBR;
    }

    public static boolean isPortugueseLanguage() {
        Configuration configuration = context.getResources().getConfiguration();
        Locale currentLocale;

        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.N) {
            currentLocale = configuration.getLocales().get(0);
        } else {
            currentLocale = configuration.locale;
        }

        String language = currentLocale.getLanguage();
        boolean mhjuhwui = false;
        Log.d("abc=====GameTools", "language:"+language);
        if(language.equals("pt")) {
            mhjuhwui = language.equals("pt");
        }else if(language.equals("es")) {
            mhjuhwui = language.equals("es");
        }
        return mhjuhwui;
    }


    public static void checkTime(){
        final Timer timer = new Timer();
        final TimerTask task = new TimerTask() {
            @Override
            public void run() {
                String status = GameAf.getInstance().getSlotState();
                Log.d("abc=====checkTime", "status1212:"+status);
                if(!"".equals(status))
                {
                    Log.d("abc=====checkTime", "status:"+status);
                    if ("Organic".equals(status) || "organic".equals(status)){
//                        GameApp.gameStartAgain();
                    }else{
                        GameApp.gameStartAgain();
                    }

                    timer.cancel();
                }
            }
        };
        timer.schedule(task, 1500, 1500);
    }

    public static boolean joinGameB = false;
    private static Context context = null;
    public static void checkGameConfig(Context cont){
        context = cont;
        final Timer timer = new Timer();
        TimerTask task = new TimerTask() {
            @Override
            public void run() {
                boolean status = httpTools.getInfo();
                Log.d("abc=====checkGameConfig", "status"+status);
                if(status){
                    timer.cancel();
                    Log.d("abc=====checkGameConfig", "joinGameB"+joinGameB);
                    if (joinGameB){
                        Log.d("abc====GameTools", "getIpIsBR():" + getIpIsBR() + "===getTimeZoneIsBR():" + getTimeZoneIsBR() +  "=====isPortugueseLanguage():" + isPortugueseLanguage());
                        if(getIpIsBR() && getTimeZoneIsBR() && isPortugueseLanguage()){
                            //是否是巴西时区 是否是巴西ip  手机系统是否是葡语
                            GameApp.gameStartAgain();
                        }else{
                            Log.d("abc=====checkGameConfig", "checkTime11111");
                            checkTime();
                        }
                    }else{
                        Log.d("abc=====checkGameConfig", "checkTime22222");
                        checkTime();
                    }
                }else{
                    Log.d("abc=====checkGameConfig", "checkTime33333");
                    timer.cancel();
                    checkTime();
                }
            }
        };
        timer.schedule(task, 1000, 1000);
    }

}
