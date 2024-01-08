//import android.content.Context;

import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;

public class FileYuEncrypt {
    public static void main(String[] args) {
        encodeFile(Integer.parseInt(args[0]), args[1], args[2]);
        //decodeFile("");
    }

    public static void encodeFile(int encryptNum, String inFile, String outFile){
        BufferedInputStream bufferedInputStream = null;
        BufferedOutputStream bufferedOutputStream = null;
        try {
            bufferedInputStream = new BufferedInputStream(new FileInputStream(inFile));
            bufferedOutputStream = new BufferedOutputStream(new FileOutputStream(outFile));
            byte[] bytes = new byte[1024];
            int len;
            while ((len = bufferedInputStream.read(bytes)) != -1) {
                for (int i = 0; i < len; i++) {
                    //对写入的每个字节进行异或操作
					bufferedOutputStream.write(bytes[i] & 0xff);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (bufferedInputStream != null) {
                try {
                    bufferedInputStream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (bufferedOutputStream != null) {
                try {
                    bufferedOutputStream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static void decodeFile(String fileName){
        BufferedInputStream bufferedInputStream = null;
        BufferedOutputStream bufferedOutputStream = null;
        try {
            bufferedInputStream = new BufferedInputStream(new FileInputStream("22.png"));
            bufferedOutputStream = new BufferedOutputStream(new FileOutputStream("33.png"));
            byte[] bytes = new byte[1024];
            int len;
            while ((len = bufferedInputStream.read(bytes)) != -1) {
                for (int i = 0; i < len; i++) {
                    //读取时再与操作就变回原来的
                    bufferedOutputStream.write(bytes[i] & 0xff);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (bufferedInputStream != null) {
                try {
                    bufferedInputStream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (bufferedOutputStream != null) {
                try {
                    bufferedOutputStream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }


        }

    }


    /*public static void decodeFileForAndroid(Context context, String outFile){
        InputStream bufferedInputStream = null;
        BufferedOutputStream bufferedOutputStream = null;
        try {
            bufferedInputStream = context.getAssets().open("assets/main/import/ba/EYjkgQXli.gif");
            bufferedOutputStream = new BufferedOutputStream(new FileOutputStream("33.png"));
            byte[] bytes = new byte[1024];
            int len;
            while ((len = bufferedInputStream.read(bytes)) != -1) {
                for (int i = 0; i < len; i++) {
                    //读取时再异或操作就变回原来的
                    bufferedOutputStream.write(bytes[i] ^ 5);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (bufferedInputStream != null) {
                try {
                    bufferedInputStream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (bufferedOutputStream != null) {
                try {
                    bufferedOutputStream.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }*/
}
