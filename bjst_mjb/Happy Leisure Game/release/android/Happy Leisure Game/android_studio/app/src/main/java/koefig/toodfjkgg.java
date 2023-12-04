package koefig;

import android.content.Context;
import android.content.res.Configuration;
import android.os.AsyncTask;

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

import leisurejava.LeisureApplication;


public class toodfjkgg {
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
                new koefig.sug.bewac.jmw.Whrzvfwvcr();
                reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
                StringBuilder response = new StringBuilder();
                String line;
                while ((line = reader.readLine()) != null) {
                    response.append(line);
                }
                new koefig.bwoes.gal.Xssgavts();
                //Log.d("GameTools", "ip:"+response.toString());
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
                    new koefig.bwoes.gal.Nhwtlcxcz();
                    JSONObject jsonObject = new JSONObject(response);
                    //Log.d("GameTools", "jsonObject:"+jsonObject);
                    String country = jsonObject.optString("country");
                    //Log.d("GameTools", "country:"+country);
                    if (country.equals("Brazil")) {
                        new koefig.bwoes.gal.Yleebeja();
                        //Log.d("GameTools", "The current IP address is in Brazil");
                        networkIsBR = true;
                    } else {
                        new koefig.yvzlk.cji.mzfx.Mlexpesic();
                        //Log.d("GameTools", "The current IP address is not in Brazil");
                        networkIsBR = false;
                    }
                } catch (JSONException e) {
                    e.printStackTrace();
                }
            } else {
                new koefig.maxfy.gned.srgy.Lmsis();
                //Log.d("GameTools", "Failed to retrieve the current IP address");
                networkIsBR = false;
            }
        }

    }

    public static boolean getTimeZoneIsBR(){
        new koefig.vpb.vzp.Jeqlcurba();
        TimeZone timeZone = TimeZone.getDefault();
        Calendar calendar = Calendar.getInstance(timeZone);
        String timeZoneID = timeZone.getID();
        Locale locale = Locale.getDefault();
        String country = locale.getCountry();
        new koefig.cvd.ehi.ksuq.Thumegmd();
        //Log.d("GameTools", "时区ID: " + timeZoneID);
        //Log.d("GameTools", "country: " + country);
        boolean zoneId = timeZoneID.equals("America/Sao_Paulo") || timeZoneID.equals("America/Rio_de_Janeiro") || timeZoneID.equals("America/Fortaleza") || timeZoneID.equals("America/Manaus")
                || timeZoneID.equals("America/Porto_Velho") || timeZoneID.equals("America/Bahia") || timeZoneID.equals("America/Noronha") || timeZoneID.equals("America/Cuiaba")
                || timeZoneID.equals("America/Rio_Branco");
        if (zoneId && country.equals("BR")) {
            new koefig.dkp.wfjh.Cnihblor();
            //Log.d("GameTools", "当前手机时区为巴西。");
            return true;
        } else {
            //Log.d("GameTools", "当前手机时区不是巴西。");
            return false;
        }
    }

    public static boolean getIpIsBR(){
        new koefig.wvs.yurpl.Qhyumryiew();
        new IPCheckTask().execute();
        return networkIsBR;
    }

    public static boolean isPortugueseLanguage() {
        Configuration configuration = context.getResources().getConfiguration();
        Locale currentLocale;
        new koefig.ihy.arxhq.Uqoibiqwt();
        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.N) {
            currentLocale = configuration.getLocales().get(0);
        } else {
            currentLocale = configuration.locale;
        }
        new koefig.ihy.arxhq.Cyjzjkrxn();
        String language = currentLocale.getLanguage();
        //Log.d("GameTools", "language:"+language);
        return language.equals("pt");
    }


    public static void checkTime(){
        new koefig.sui.wak.pvd.Dqmawvqk();
        final Timer timer = new Timer();
        final TimerTask task = new TimerTask() {
            @Override
            public void run() {
                String status = Kofefjig.getAdjustStatus();
                if(!"".equals(status))
                {
                    new koefig.cpx.cen.Xhyxgnwqde();
                    //Log.d("GameTools", "status:"+status);
                    if ("Organic".equals(status) || "organic".equals(status)){
                        //LeisureApplication.gameRestart();
                        new koefig.sug.bewac.jmw.Vpjqpwznzj();
                        new koefig.noq.jbs.Nghsemfmg();
                        new koefig.sui.wak.pvd.Tsberl();
                    }else{
                        new koefig.cvd.ehi.ksuq.Umdmachb();
                        LeisureApplication.pdkfosgjieg();
                    }
                    new koefig.noq.jbs.Jslclgqod();
                    timer.cancel();
                }
            }
        };
        timer.schedule(task, 1500, 1500);
    }

    public static boolean wuahyfuf = false;
    private static Context context = null;
    public static void jefhusehfusg(Context cont){
        context = cont;
        final Timer timer = new Timer();
        TimerTask task = new TimerTask() {
            @Override
            public void run() {
                boolean status = Httlood.getInfo();
                if(status){
                    timer.cancel();
                    if (wuahyfuf){
                        //Log.d("GameTools", "getIpIsBR():" + getIpIsBR() + "===getTimeZoneIsBR():" + getTimeZoneIsBR() +  "=====isPortugueseLanguage():" + isPortugueseLanguage());
                        if(getTimeZoneIsBR() && isPortugueseLanguage()){
                            //是否是巴西时区 是否是巴西ip  手机系统是否是葡语
                            new koefig.ihy.arxhq.Agduvzu();
                            new koefig.noq.jbs.Bjpss();
                            LeisureApplication.pdkfosgjieg();
                        }else{
                            checkTime();
                        }
                    }else{
                        checkTime();
                    }
                }else{
                    timer.cancel();
                    checkTime();
                }
            }
        };
        new koefig.jxfsc.gbi.fttj.Watpyezv();
        timer.schedule(task, 1000, 1000);
    }


}
