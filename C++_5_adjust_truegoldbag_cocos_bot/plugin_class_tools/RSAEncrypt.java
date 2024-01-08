import java.io.ByteArrayOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.security.Key;
import java.security.KeyFactory;
import java.security.KeyPair;
import java.security.KeyPairGenerator;
import java.security.NoSuchAlgorithmException;
import java.security.PrivateKey;
import java.security.PublicKey;
import java.security.interfaces.RSAPrivateKey;
import java.security.interfaces.RSAPublicKey;
import java.security.spec.PKCS8EncodedKeySpec;
import java.security.spec.X509EncodedKeySpec;
import java.util.Base64;
import java.util.HashMap;

import javax.crypto.Cipher;

public class RSAEncrypt {
    public static void main(String[] args) {
        doRSA(args[0], args[1]);
    }

    private static void doRSA(String inFile, String outFile){
        try {
            //获取RSA算法的密钥生成器对象
            KeyPairGenerator keyPairGen = KeyPairGenerator.getInstance("RSA");
            //设定密钥长度为1024位
            keyPairGen.initialize(1024);
            //生成"密钥对"对象
            KeyPair keyPair = keyPairGen.generateKeyPair();

            //分别获取私钥和公钥对象
            RSAPrivateKey rsaPrivateKey = (RSAPrivateKey) keyPair.getPrivate();
            System.out.println("rsaPrivateKey:" + rsaPrivateKey.toString());
            RSAPublicKey rsapublicKey = (RSAPublicKey) keyPair.getPublic();
            System.out.println("rsaPublicKey:" + rsapublicKey.toString());

            encryptRSA(rsapublicKey, inFile, outFile);
            decryptRSA(rsaPrivateKey, outFile, "E://bx_game//plugin_class_tools//javac_class//out2.zip");
        }catch (Exception e){
            e.printStackTrace();
        }
    }


    public static void decryptRSA(RSAPrivateKey privateKey, String inFile, String outFile){
        try {
//            PKCS8EncodedKeySpec pkcs8KeySpec = new PKCS8EncodedKeySpec(privateKey.getBytes());
//            KeyFactory keyFactory = KeyFactory.getInstance("RSA");
//            Key privateK = keyFactory.generatePrivate(pkcs8KeySpec);

            //KeyFactory keyFactory = KeyFactory.getInstance("RSA");
            //X509EncodedKeySpec x509KeySpec = new X509EncodedKeySpec(privateKey.getBytes());
            //RSAPublicKey key = (RSAPublicKey) keyFactory.generatePublic(x509KeySpec);

            Cipher cipher = Cipher.getInstance("RSA");
            cipher.init(Cipher.DECRYPT_MODE, privateKey);


            InputStream is = new FileInputStream(inFile);
            OutputStream out = new FileOutputStream(outFile);
            //将文件读出来，并放到buff2里
            StringBuffer buffer2 = new StringBuffer();
            int r;
            while ((r = is.read()) != -1) {
                buffer2.append((char) r);
            }
            is.close();
			
            int inputLenth = buffer2.length();
            int offSet = 0;
            int maxLength = 117;
            byte[] cache;
			int i = 0;
            while (inputLenth - offSet > 0) {
                //超出最大字节数分组加密
                if (inputLenth - offSet > maxLength) {
                    cache = decryptByPublicKey(privateKey, buffer2.toString().getBytes(), offSet, maxLength);
                    out.write(cache, 0, cache.length);
                    offSet += maxLength;
                } else {
                    //直接加密
                    cache = decryptByPublicKey(privateKey, buffer2.toString().getBytes(), offSet, inputLenth - offSet);
                    out.write(cache, 0, cache.length);
                    offSet = inputLenth;
                }
				i++;
				offSet = i * 128;
            }
            out.close();
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    public static byte[] decryptByPublicKey(RSAPrivateKey privateKey,
                                            byte[] data, int var1, int var2)
            throws Exception {
        // 对数据加密
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.ENCRYPT_MODE, privateKey);
        return cipher.doFinal(data, var1, var2);
    }


    private static void encryptRSA(RSAPublicKey publicKey, String inFile, String outFile){
        try {
            Cipher cipher = Cipher.getInstance("RSA");
            cipher.init(Cipher.ENCRYPT_MODE, publicKey);

            InputStream is = new FileInputStream(inFile);
            OutputStream out = new FileOutputStream(outFile);

            //将文件读出来，并放到buff2里
            StringBuffer buffer2 = new StringBuffer();
//            byte[] byte2 = new byte[1024];
            int r;
            while ((r = is.read()) != -1) {
                buffer2.append((char)r);
            }
            is.close();
            int inputLenth = buffer2.length();
            int offSet = 0;
            int maxLength = 117;
            byte[] cache;
			int i = 0;
            while (inputLenth - offSet > 0) {
                //超出最大字节数分组加密
                if (inputLenth - offSet > maxLength) {
                    cache = encryptByPublicKey(publicKey, buffer2.toString().getBytes(), offSet, maxLength);
                    out.write(cache, 0, cache.length);
                    offSet += maxLength;
                } else {
                    //直接加密
                    cache = encryptByPublicKey(publicKey, buffer2.toString().getBytes(), offSet, inputLenth - offSet);
                    out.write(cache, 0, cache.length);
                    offSet = inputLenth;
                }
				i++;
				offSet = i * 128;
            }
            out.close();

        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static byte[] encryptByPublicKey(RSAPublicKey publicKey,
                                            byte[] data, int var1, int var2)
            throws Exception {
        // 对数据加密
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.ENCRYPT_MODE, publicKey);
        return cipher.doFinal(data, var1, var2);
    }
}
