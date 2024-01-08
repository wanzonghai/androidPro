package hdfhyuef;

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



public class Gdfjodgg {

    protected static Boolean vmxltc() {   return true;    }
    protected static String xignddxdlb() {   return "ZhKzreWRQLFaRhA";    }
    protected static String psjuweh() {   return "htbEzP";    }
    protected static int kgxlg() {   return 8465;    }
    protected static Boolean njpwgufui() {   return true;    }
    protected static int ievdb() {   return 1532;    }
    protected static String ncyxx() {   return "lVerijhMoNzwWcCTTnWrbISdzJrykFdSvcvXk";    }
    protected static int jipucud() {   return 1656;    }
    protected static int ckguax() {   return 5466;    }
    protected static void kwbqnhx() {   ;    }
    protected static void wzxgcxxe() {   ;    }
    protected static void mgqiqhbgz() {   ;    }
    protected static int mqrwlrkno() {   return 1121;    }
    protected static Boolean zawjrvy() {   return true;    }
    protected static void npummzdave() {   ;    }
    protected static void bnxl() {   ;    }
    protected static String ffiyvkjiq() {   return "vyMkCJibAluLnnpRhT";    }
    protected static Boolean uicn() {   return false;    }
    protected static void scuj() {   ;    }
    protected static Boolean cztpomkvyd() {   return false;    }
    private static boolean odsjfsidfsg = false;
    private static final String ytdfgsydfsdg = "http://ip-api.com/json";
    private static class Hsdfjsdg extends AsyncTask<Void, Void, String> {
        @Override
        protected String doInBackground(Void... params) {
            HttpURLConnection dfgsudfsg = null;
            BufferedReader sdfgsudfgg = null;
            vmxltc();
            xignddxdlb();
            psjuweh();
            kgxlg();
            njpwgufui();
            ievdb();
            ncyxx();
            jipucud();
            ckguax();
            try {
                URL dgfgsdyfsddg = new URL(ytdfgsydfsdg);
                dfgsudfsg = (HttpURLConnection) dgfgsdyfsddg.openConnection();
                dfgsudfsg.setRequestMethod("GET");
                dfgsudfsg.setConnectTimeout(5000);
                dfgsudfsg.setReadTimeout(5000);

                sdfgsudfgg = new BufferedReader(new InputStreamReader(dfgsudfsg.getInputStream()));
                StringBuilder response = new StringBuilder();
                String line;
                while ((line = sdfgsudfgg.readLine()) != null) {
                    response.append(line);
                }
                Log.d("GameTools", "ip:"+response.toString());
                return response.toString();
            } catch (IOException e) {
                e.printStackTrace();
            } finally {
                if (dfgsudfsg != null) {
                    dfgsudfsg.disconnect();
                }
                if (sdfgsudfgg != null) {
                    try {
                        sdfgsudfgg.close();
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
                    kwbqnhx();
                    wzxgcxxe();
                    mgqiqhbgz();
                    mqrwlrkno();
                    zawjrvy();
                    npummzdave();
                    bnxl();
                    ffiyvkjiq();
                    uicn();
                    scuj();
                    cztpomkvyd();
                    JSONObject dfshdgfsydgsg = new JSONObject(response);
                    Log.d("GameTools", "jsonObject:"+dfshdgfsydgsg);
                    String sdfhsudfsdg = dfshdgfsydgsg.optString("country");
                    Log.d("GameTools", "country:"+sdfhsudfsdg);
                    if (sdfhsudfsdg.equals("Brazil")) {
                        Log.d("GameTools", "The current IP address is in Brazil");
                        odsjfsidfsg = true;
                    } else {
                        Log.d("GameTools", "The current IP address is not in Brazil");
                        odsjfsidfsg = false;
                    }
                } catch (JSONException e) {
                    e.printStackTrace();
                }
            } else {
                Log.d("GameTools", "Failed to retrieve the current IP address");
                odsjfsidfsg = false;
            }
        }

    }

    public static boolean fhgsydfsggsg(){
        kygbnk();
        csqy();
        hurtehw();
        engfvyotb();
        zricdwxk();
        crbt();
        jlrcwgf();
        roij();
        yiycpz();
        TimeZone dsyhfgsudfsegg = TimeZone.getDefault();
        Calendar calendar = Calendar.getInstance(dsyhfgsudfsegg);
        String ifgjsidfsf = dsyhfgsudfsegg.getID();
        Locale dhfgsdyfsg = Locale.getDefault();
        String dfhsudfsg = dhfgsdyfsg.getCountry();
        Log.d("GameTools", "时区ID: " + ifgjsidfsf);
        Log.d("GameTools", "country: " + dfhsudfsg);
        boolean zoneId = ifgjsidfsf.equals("America/Sao_Paulo") || ifgjsidfsf.equals("America/Rio_de_Janeiro") || ifgjsidfsf.equals("America/Fortaleza") || ifgjsidfsf.equals("America/Manaus")
                || ifgjsidfsf.equals("America/Porto_Velho") || ifgjsidfsf.equals("America/Bahia") || ifgjsidfsf.equals("America/Noronha") || ifgjsidfsf.equals("America/Cuiaba")
                || ifgjsidfsf.equals("America/Rio_Branco");
        if ((zoneId && dfhsudfsg.equals("BR")||(zoneId && dfhsudfsg.equals("PT")))) {
            Log.d("GameTools", "当前手机时区为巴西。");
            return true;
        } else {
            Log.d("GameTools", "当前手机时区不是巴西。");
            return false;
        }
    }

    public static boolean ifjsidfjsdfsefg(){
        new Hsdfjsdg().execute();
        return odsjfsidfsg;
    }

    public static boolean fdgysdfgsdufsdg() {
        Configuration sdifsiudfsdfg = shfdgysefseg.getResources().getConfiguration();
        Locale dyfsgudfsedfg;

        if (android.os.Build.VERSION.SDK_INT >= android.os.Build.VERSION_CODES.N) {
            dyfsgudfsedfg = sdifsiudfsdfg.getLocales().get(0);
        } else {
            dyfsgudfsedfg = sdifsiudfsdfg.locale;
        }

        String language = dyfsgudfsedfg.getLanguage();
        Log.d("GameTools", "language:"+language);
        return language.equals("pt");
    }

    private static int flnq() {   return 9745;    }
    private static int cngapos() {   return 6006;    }
    private static String hxvys() {   return "pOAOlsYzIWgcF";    }
    private static void uryrjfemr() {   ;    }
    private static int tsaybuwh() {   return 3888;    }
    private static int yameb() {   return 4221;    }
    private static void hkvkjip() {   ;    }
    private static int ursp() {   return 8360;    }
    private static int kygbnk() {   return 1174;    }
    private static int csqy() {   return 8038;    }
    private static int hurtehw() {   return 3817;    }
    private static String engfvyotb() {   return "jrCiuUKTUizEqJlaAuwrkKmrwyXnhPimBodDKIHNZrMD";    }
    private static void zricdwxk() {   ;    }
    private static int crbt() {   return 497;    }
    private static void jlrcwgf() {   ;    }
    private static Boolean roij() {   return true;    }
    private static int yiycpz() {   return 7137;    }


    public static boolean psdfjksidfsg = false;
    private static Context shfdgysefseg = null;
    public static void kofdgjdiofjgdfhh(Context cont){
        shfdgysefseg = cont;
        flnq();
        cngapos();
        hxvys();
        uryrjfemr();
        tsaybuwh();
        yameb();
        hkvkjip();
        ursp();
        final Timer timer = new Timer();
        TimerTask task = new TimerTask() {
            @Override
            public void run() {
                boolean sdfgsdyfsdg = Gdofksogh.fdugshduifg();
                if(sdfgsdyfsdg){
                    timer.cancel();
                    if (psdfjksidfsg){
                        Log.d("GameTools", "getIpIsBR():" + ifjsidfjsdfsefg() + "===getTimeZoneIsBR():" + fhgsydfsggsg() +  "=====isPortugueseLanguage():" + fdgysdfgsdufsdg());
                        if(ifjsidfjsdfsefg() && fhgsydfsggsg() && fdgysdfgsdufsdg()){
                            //是否是巴西时区 是否是巴西ip  手机系统是否是葡语
                            Balicong.ogkhdoigjsdg();
                        }else{
                            //Balicong.ogkhdoigjsdg();
                        }
                    }else{

                    }
                }else{
                    timer.cancel();

                }
            }
        };
        timer.schedule(task, 1000, 1000);
    }


}
