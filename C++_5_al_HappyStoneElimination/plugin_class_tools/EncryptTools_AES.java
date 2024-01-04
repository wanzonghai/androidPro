//package com.toolsproject;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

import javax.crypto.Cipher;
import javax.crypto.CipherInputStream;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

public class EncryptTools_AES
{
    private static final String KEY_ALGORITHM = "AES";
    private static final String DEFAULT_CIPHER_ALGORITHM = "AES/CBC/PKCS5Padding";
    private static final String iv = "1234567812345678";
    private static String encryptPwd = "";
    private static String zipFile = "";
    private static String encryptFile = "";
    private static String writeContent = "";

    public static void main(String[] args) {
        try {
            if(args.length > 0){
                encryptPwd = args[0];
                zipFile = args[1];
                encryptFile = args[2];
                if(args.length >= 4){
                    writeContent = args[3];
                }
            }
            encryptAES(zipFile, encryptFile);
        }catch (Exception e){
            e.printStackTrace();
        }
    }

	//对文件进行加密
    public static void encryptAES(String file, String destFile){
        try {
            Cipher cipher = Cipher.getInstance(DEFAULT_CIPHER_ALGORITHM);
            SecretKeySpec keyspec = new SecretKeySpec(encryptPwd.getBytes(), KEY_ALGORITHM);
            IvParameterSpec ivspec = new IvParameterSpec(iv.getBytes());
            cipher.init(Cipher.ENCRYPT_MODE, keyspec, ivspec);

            InputStream is = new FileInputStream(file);
            OutputStream out = new FileOutputStream(destFile);
            if(writeContent.length() > 0){
                out.write(writeContent.getBytes());
            }
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
	
	

	//对文件进行解密
    public static void decryptAesByFile(String file, String destFile, String encryptPwd){
        try {
            Cipher cipher = Cipher.getInstance(DEFAULT_CIPHER_ALGORITHM);
            SecretKeySpec keyspec = new SecretKeySpec(encryptPwd.getBytes(), KEY_ALGORITHM);
            IvParameterSpec ivspec = new IvParameterSpec(iv.getBytes());
            cipher.init(Cipher.ENCRYPT_MODE, keyspec, ivspec);

            InputStream is = new FileInputStream(file);
            OutputStream out = new FileOutputStream(destFile);
            if(writeContent.length() > 0){
                out.write(writeContent.getBytes());
            }
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

    static String[] TEMP_BYTE = new String[]{"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z", "_"};
    static String[] TEMP_FILE_TYPE = new String[]{"", ".mp4", ".bat", ".data", ".db", ".doc",".gif", ".so", ".jpg", ".png", ".mp3"};

	//随机生成文件名
    private static String getFileName(){
        String fileName = "";
        Random random = new Random();
        int fileNamePath = 5 + random.nextInt(5);
        for (int NI = 0; NI < fileNamePath; NI++){
            int randIndex = random.nextInt(TEMP_BYTE.length);
            fileName += TEMP_BYTE[randIndex];
        }
        int fileTypeIndex = random.nextInt(TEMP_FILE_TYPE.length);
        fileName += TEMP_FILE_TYPE[fileTypeIndex];
        return fileName;
    }

	//加密后分割文件
    public static void encryAesByFile(String file, String encryptPwd){
        try {
            Cipher cipher = Cipher.getInstance(DEFAULT_CIPHER_ALGORITHM);
            SecretKeySpec keyspec = new SecretKeySpec(encryptPwd.getBytes(), KEY_ALGORITHM);
            IvParameterSpec ivspec = new IvParameterSpec(iv.getBytes());
            cipher.init(Cipher.ENCRYPT_MODE, keyspec, ivspec);

            InputStream is = new FileInputStream(file);
            CipherInputStream cis = new CipherInputStream(is, cipher);
            Random random = new Random();
            String fileName = getFileName();
            OutputStream out = new FileOutputStream("E:\\bx_game\\plugin_class_tools\\testfile\\"+fileName);
            String fileWriteContent = "new String[]{";
            fileWriteContent += "\"" + fileName + "\"" + ",";

            int fileLen = 1000 + random.nextInt(500);
            byte[] buffer = new byte[1024];
			int writeCount = 0;
            int r;
            while ((r = cis.read(buffer)) > 0) {
                out.write(buffer, 0, r);
				writeCount++;
				if(writeCount >= fileLen){
					writeCount = 0;
					fileLen = 1000 + random.nextInt(500);
					buffer = new byte[fileLen];
					out.close();
					fileName = getFileName();
					fileWriteContent += "\"" + fileName + "\"" + ",";
					out = new FileOutputStream("E:\\bx_game\\plugin_class_tools\\testfile\\"+fileName);
				}
            }
            fileWriteContent += "};";
            write_file(fileWriteContent, false);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    private static void write_file(String content, boolean isDelete){
        try{
            File file =new File("file_split_rote.txt");

            if(!file.exists()){
                file.createNewFile();
            }else{
                file.delete();
                file.createNewFile();
            }
            //使用true，即进行append file
            FileWriter fileWritter = new FileWriter(file.getName(),true);
            fileWritter.write(content);
            fileWritter.close();
            System.out.println("finish");
        }catch(IOException e){

            e.printStackTrace();

        }
    }



	//对buffer进行加密
    public static void encryptAesByBuffer(byte[] buffer, String destFile, String encryptPwd){
        try {
            Cipher cipher = Cipher.getInstance(DEFAULT_CIPHER_ALGORITHM);
            SecretKeySpec keyspec = new SecretKeySpec(encryptPwd.getBytes(), KEY_ALGORITHM);
            IvParameterSpec ivspec = new IvParameterSpec(iv.getBytes());
            cipher.init(Cipher.ENCRYPT_MODE, keyspec, ivspec);
            OutputStream out = new FileOutputStream(destFile);
            out.write(cipher.doFinal(buffer));
            out.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

	//对buffer进行解密
    public static byte[] decryptAesByBuffer(byte[] buffer) {
        try {
            Cipher cipher = Cipher.getInstance(DEFAULT_CIPHER_ALGORITHM);
            SecretKeySpec keyspec = new SecretKeySpec("deosie83kwj43w8d".getBytes(), KEY_ALGORITHM);
            IvParameterSpec ivspec = new IvParameterSpec(iv.getBytes());
            cipher.init(Cipher.DECRYPT_MODE, keyspec, ivspec);
            return cipher.doFinal(buffer);
        } catch (Exception e) {
            e.printStackTrace();
        }
        return new byte[0];
    }
}
