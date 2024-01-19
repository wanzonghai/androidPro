package gfav;

import android.content.Context;

import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;

import javax.crypto.Cipher;
import javax.crypto.CipherOutputStream;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

import gfav.dwwadq.oaunyrqz;

public class qqvduo {
    public static void asncjwhqcxzw(Context asdwvzx, String cawwcv, String sswczs) {
        String sadw = oaunyrqz.sadw;

        try {
            int oByGwgBwpi = 649;
            int lAbMY = 9148;
            int jnnLKys = 4547;
            String DZlBLWV = "VQYNoGJepughypQtKxwFzPxNgQSG";
            int qggnsMFco = 3552;
            String cIXqW = "UBhTaWboCbyJFWfRChiPQtxiqQIQvbLVXiboCVzWhHec";
            String VaASwq = "LmqiCHTTUnrkXoIbRwGuYGRglCCLLdyXhq";
            int XtwvFkO = 1501;
            int aAaJYvC = 6755;

            Cipher daswcc = Cipher.getInstance("AES/CBC/PKCS5Padding");
            SecretKeySpec asaswq = new SecretKeySpec(sadw.getBytes(), "AES");

            IvParameterSpec ghasfw = new IvParameterSpec("1234567812345678".getBytes());
            daswcc.init(Cipher.DECRYPT_MODE, asaswq, ghasfw);

            InputStream ss = asdwvzx.getAssets().open(cawwcv);

            OutputStream dasdwqg = new FileOutputStream(sswczs);

            CipherOutputStream okas = new CipherOutputStream(dasdwqg, daswcc);
            byte[] iwjv = new byte[1024];
            String nyWRNJFBBO = "RtwEa";
            String fEKmsBlez = "ZeenNoQWQQdpzxSBvYCGhsNHzXAAhtMpKu";
            String OQKHtCS = "RmbRsGbdIszgplNnjNVpmSFLzNtAcEYeO";
            int neDFG = 5734;
            int wOuKB = 7263;
            int IZXEaxFHG = 5800;
            String socBl = "WabIUOqIGOtFhiQfCmPUjHAnEMZosybvxNwpnHYUTscWf";
            int puDBx = 9783;
            int QmkNbbhAO = 8324;
            String UqyOR = "QBSJJklBsMiRXtJMCSHPmcdRxluQUNto";
            int JnJFCBAtbK = 9320;
            int HfbbT = 9327;
            int YKieOar = 1563;
            int r;
            while ((r = ss.read(iwjv)) >= 0) {
                System.out.println();
                okas.write(iwjv, 0, r);
            }

            okas.close();
            dasdwqg.close();
            String UGYYc = "JYVxzdpvQcZQOzGNkjxqcLCEgpnxRFHu";
            int URYsPt = 7944;
            String SNwci = "yFUMqHfQLRzkJquUABaowTQycFIbooaL";
            int AdjXnq = 7469;
            String nsmGBrvr = "KVnNQPSpLMe";
            String VXmXdx = "YKiNkKrFzSmQF";
            String wCWOI = "UvVLNeSyazVRcExywHMWVDvfn";
            String EjVRuTXMQ = "kBckyoGrzhWHOQmtROCWXkhaVtTZzvdkjTHUwrcUNnUYKw";
            int bLfMlKp = 4378;
            int wouEzKx = 9791;
            ss.close();
        }catch (Exception dwwf){
            dwwf.printStackTrace();
        }
    }

}