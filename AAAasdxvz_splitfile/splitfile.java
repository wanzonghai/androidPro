import java.io.DataOutputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.security.Key;
import java.security.SecureRandom;
import java.util.zip.ZipEntry;
import java.util.zip.ZipInputStream;
import java.util.zip.ZipOutputStream;
import javax.crypto.Cipher;
import javax.crypto.CipherInputStream;
import javax.crypto.CipherOutputStream;
import javax.crypto.KeyGenerator;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.io.BufferedWriter;
import java.io.OutputStreamWriter;

import java.util.Random;

//aes encrypy
import javax.crypto.Cipher;
import javax.crypto.CipherInputStream;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

public class splitfile
{
    private static String packFile = "";
    private static String outFile = "";
    private static String tempDatafile = "";

    private static String[] suffixList = {".png", ".mp3", ".jpg",".json"};
    private static String[] lettersList = {"0", "1", "2", "3","4","5","6","7","8","9","a","b","c","d","e","f"};

    //aes
    private static final String KEY_ALGORITHM = "AES";
    private static final String DEFAULT_CIPHER_ALGORITHM = "AES/CBC/PKCS5Padding";
    private static final String iv = "1234567812345678";
    private static String encryptPwd = "";
    private static String inFile = "";
    private static String encryptFile = "";

    private static Random randobj;

    public static void main(String[] args) {
        try {
            String randseed = "16543215";
            if(args.length > 0){
                System.out.println("java args[0]" + args[0]);
                System.out.println("java args[1]" + args[1]);
                System.out.println("java args[2]" + args[2]);
                System.out.println("java args[3]" + args[3]);
                packFile = args[0];
                outFile = args[1];
                encryptPwd = args[2];
                randseed = args[3];
            }

            tempDatafile = packFile + ".dat";

            randobj = new Random(Integer.parseInt(randseed));
            splitOutFile();
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public static String getNewName(){
        // # 8-4-4-4-12
        String fileName = "";
        int lenj = 8;
        for (int i = 0; i < lenj; i ++) {
            int cindex = (int)(randobj.nextDouble() * lettersList.length);
            fileName += lettersList[cindex];
        }

        fileName += '-';
        lenj = 4; 
        for (int i = 0; i < lenj; i ++) {
            int cindex = (int)(randobj.nextDouble() * lettersList.length);
            fileName += lettersList[cindex];
        }

        fileName += '-';
        lenj = 4;
        for (int i = 0; i < lenj; i ++) {
            int cindex = (int)(randobj.nextDouble() * lettersList.length);
            fileName += lettersList[cindex];
        }

        fileName += '-';
        lenj = 4; 
        for (int i = 0; i < lenj; i ++) {
            int cindex = (int)(randobj.nextDouble() * lettersList.length);
            fileName += lettersList[cindex];
        }

        fileName += '-';
        lenj = 12; 
        for (int i = 0; i < lenj; i ++) {
            int cindex = (int)(randobj.nextDouble() * lettersList.length);
            fileName += lettersList[cindex];
        }

        int fixindex = (int)(randobj.nextDouble() * suffixList.length);
        String suffix = suffixList[fixindex];
        return fileName + suffix;
    }

    public static boolean deleteDir(File srcDir) {
        File[] files = srcDir.listFiles();
        if (files == null || files.length == 0) {
            return srcDir.delete();
        }

        for (File file : files) {
            if (file.isDirectory()) {
                deleteDir(file);
            } else {
                file.delete();
            }
        }
        return srcDir.delete();
    }



    public static void splitOutFile() throws Exception{
        File srcFile = new File(packFile);
        if (!srcFile.exists()) {
            return;
        }

        long tfilelen = srcFile.length();
        System.out.println("tfilelen:" + tfilelen);


        File newfilepath = new File(outFile);
        if (newfilepath.exists()) {
            deleteDir(newfilepath);
        }
        newfilepath.mkdirs();

        OutputStream outtxtfile = new FileOutputStream(packFile + ".txt");

        InputStream is = new FileInputStream(srcFile);

        int donelen = 0;
        String outrootfile = outFile;

        while(true){
            int newlen = (int)(1000 + randobj.nextDouble()* 500000);
            // System.out.println("newlen:" + newlen);
            String newfile = getNewName();
            String subpath = "assets/" + newfile.substring(0,2) + "/";

            outtxtfile.write("\"".getBytes());
            outtxtfile.write(subpath.getBytes());
            outtxtfile.write(newfile.getBytes());
            outtxtfile.write("\",\n".getBytes());

            System.out.println("newfile:" + newfile);

            File subfilepath = new File(outrootfile + subpath);
            if (!subfilepath.exists()) {
                subfilepath.mkdirs();
            }
            

            String subfile = outrootfile + subpath + newfile;

            OutputStream out = new FileOutputStream(tempDatafile);
            byte[] buffer = new byte[1024];
            int r = 0;
            int curlen = 0;
            while ((r = is.read(buffer)) > 0) {
                curlen += r;
                out.write(buffer, 0, r);
                if ( curlen >= newlen ) {
                    break;
                }
            }

            out.close();
            System.out.println("curlen:" + curlen);

            //aes
            encryptAES(tempDatafile, subfile, encryptPwd);

            donelen += curlen;
            if ( donelen >= tfilelen ) {
                break;
            }

        }

        is.close();
        outtxtfile.close();
    }

    public static void encryptAES(String file, String destFile, String password){
        try {
            Cipher cipher = Cipher.getInstance(DEFAULT_CIPHER_ALGORITHM);
            SecretKeySpec keyspec = new SecretKeySpec(password.getBytes(), KEY_ALGORITHM);
            IvParameterSpec ivspec = new IvParameterSpec(iv.getBytes());
            cipher.init(Cipher.ENCRYPT_MODE, keyspec, ivspec);

            InputStream is = new FileInputStream(file);
            OutputStream out = new FileOutputStream(destFile);
            CipherInputStream cis = new CipherInputStream(is, cipher);
            byte[] buffer = new byte[1024];
            int r;
            while ((r = cis.read(buffer)) > 0) {
                out.write(buffer, 0, r);
            }
            cis.close();
            is.close();
            out.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
