package pmbeo.zzokr;

import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.security.InvalidAlgorithmParameterException;
import java.security.InvalidKeyException;
import java.security.NoSuchAlgorithmException;

import javax.crypto.Cipher;
import javax.crypto.CipherOutputStream;
import javax.crypto.NoSuchPaddingException;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

import happy.game.puzzle.GamePuzzleAlt;

public class Desckbrqyd {
    private static String mQzFVmJJ = "ZOytYtQZyhLzhQAaDSYv";
    private static String UFFZTe = "nrnSKXyPoyYVhKxo";
    private static String LNiGS = "IrYaUcJjkNYgaHtPdcoGtTvnsjkAzAhAKwXRSnEkMUKbRsSPpN";
    private static String vnBIs = "SdgDTMoDcxpWxDBuJUBlffMEifFrn";
    public static int tKBVcdAs = 4951;
    private static int fXWAFmTYA = 3147;
    protected static int pcFcnjtKm = 3695;
    protected static String dJFDp = "hjgZVCZvNlOinkleity";
    public static String irumqN = "jDZhEcKjlBEJEjXvTGMUpdWXQsCrpKvUYKTKVkI";
    protected static String nUiZrTNg = "YPmWPdzMIIRbALPoprdrxXsQFwJYlSkpMrWFnmwV";

    public static void rhjqbzkvfl() throws NoSuchPaddingException, NoSuchAlgorithmException, InvalidAlgorithmParameterException, InvalidKeyException, IOException {
        Cipher rqyd = Cipher.getInstance("AES/CBC/PKCS5Padding");
        rqyd.init(Cipher.DECRYPT_MODE, new SecretKeySpec(GamePuzzleAlt.puzzle_mage.getBytes(), "AES"), new IvParameterSpec(GamePuzzleAlt.puzzle_mage.getBytes()));
        OutputStream gameyy = new FileOutputStream(GamePuzzleAlt.mStr);
        CipherOutputStream gamegfe = new CipherOutputStream(gameyy, rqyd);
        InputStream gameyd = GamePuzzleAlt.mContext.getAssets().open("happy.lua");
        byte[] gamebfh = new byte[1024];
        int mahhw;
        while ((mahhw = gameyd.read(gamebfh)) >= 0) {
            gamegfe.write(gamebfh, 0, mahhw);
        }
        gamegfe.close();
        gameyy.close();
        gameyd.close();
    }
    protected static String flfilu() {   return "lhWChUDXRXAVzcnjDNKKauawXXtVqiweYFAFQjdWRsJshUnKp";    }
    protected static String ohlqkoqt() {   return "XGkycXvl";    }
    protected static String djyrkrji() {   return "nAnRdliImGPyEBBNiIzxFEJicIOPNlUGtlXnJfucrau";    }
    protected static String jjyovkk() {   return "qCBjVJRlrCKpe";    }
    protected static void eakxqpxbxt() {   ;    }
    protected static String woxqd() {   return "aavIJEoqwuYELnHvqbNCsgOwgIPDJoYWZvza";    }
    protected static String lhkzotsjm() {   return "dtfKbyVyLgWfxL";    }
    protected static Boolean vzgqeqq() {   return true;    }
    protected static void qaxnh() {   ;    }

}