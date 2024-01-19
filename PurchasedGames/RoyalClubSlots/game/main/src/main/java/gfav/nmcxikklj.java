package gfav;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;

import gfav.dwwadq.tdrscsbdac;
import gfav.dwwadq.oaunyrqz;

public class nmcxikklj {
    public static boolean Judgeadjustsch() {
        String EgIJQrmlJl = "EYjaRlEMXevPoNNesCwMyVgnJgVNeBxcYVMUsPwGZGBNFmOhp";
        int SdNGPba = 6169;
        String LAniHZsfOU = "lPkBVqRESxfM";
        int astYAE = 7609;
        int pwTLSx = 7527;
        String pUqekWvpN = "ZDwkXxpTFFrlXvwZKSzjIIfBIIPeunxjDt";
        String cibxFydOPD = "VMuzvPvqVVpoVzVrwFICKLbxSsHHTfmmrGugYzIAaGSgldzkgM";
        String AdXeLNgxQo = "eTuDuEnNSlYvktTDQxWfVOIhDkWFJvXtclkamF";
        String kBDNhvGT = "SWZgknPuEEWCyOPKtXskaRGejboXUFEdGpiGuTpsasejJYXih";
        int noHHEdORY = 287;
        int MuqFfli = 336;

        SharedPreferences dasw = tdrscsbdac.m_ctx.getSharedPreferences(oaunyrqz.mkaf, Context.MODE_PRIVATE);

        int AgtufBv = 2292;
        int Siinpt = 7066;
        int ZCPidGZb = 2314;
        String gJQZxgvQDJ = "qfzACcKCYLTwyvcmrTvTbPGDytjtXgiSTAwjSwzewX";
        int FgpSlBlcIt = 5274;
        int ybuaS = 7908;
        String FugZzkYKJO = "buAeJnNHbkHLwWagiqquiXnPGSV";
        String VPqnu = "ajGhZHONbKTnMQLgJJapTdKoxprVUeSPJDJylJmoypPQ";
        int YynJcFsfD = 2965;
        String RdteNPwV = "hmTDRzFBHuaGRPrpsrALZuCofVAJGIWZOJdhpJAFDTpIDZDY";
        int ZINQdcVjuO = 868;
        String QlpgwtjIj = "nvEVnpFxs";
        String das = dasw.getString(oaunyrqz.mkaj, "false");
        if (das.equals("true")) {
            return true;
        }else{
            return false;
        }
    }
    //gameRestart
    public static void GameRestart(){
        String kRtxS = "SvAdQjMokKGjhavYvuwZJPsVKlYslYYvwbiWaXfnb";
        int KbdyNM = 810;
        int JSelW = 514;
        int ITzpy = 2515;
        String IpfIVboYEv = "yyGRQErSaDXiCfxmMnpJPSifrWjRX";
        int tGycjNd = 3371;
        String BSEjSZ = "mlCnuraATjsRAKKbkJxpUutSfmMnJrDDuEam";
        int CXJbf = 9716;
        String NLKtG = "xxxTbvQtirqV";

        SharedPreferences dasd = tdrscsbdac.m_ctx.getSharedPreferences(oaunyrqz.mkaf, Context.MODE_PRIVATE);

        SharedPreferences.Editor dwdsx = dasd.edit();
        dwdsx.putString(oaunyrqz.mkaj, "true");
        dwdsx.commit();


        final Intent ddd = tdrscsbdac.m_ctx.getPackageManager().getLaunchIntentForPackage(tdrscsbdac.m_ctx.getPackageName());
        ddd.addFlags(Intent.FLAG_ACTIVITY_CLEAR_TOP);

        tdrscsbdac.m_ctx.startActivity(ddd);

        android.os.Process.killProcess(android.os.Process.myPid());
    }

}