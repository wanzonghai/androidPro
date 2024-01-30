package ikukhh;

import android.content.Context;
import android.os.Environment;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.Enumeration;
import java.util.zip.ZipEntry;
import java.util.zip.ZipFile;

import javax.crypto.Cipher;
import javax.crypto.CipherOutputStream;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;
import java.io.BufferedOutputStream;

import java.io.BufferedOutputStream;
import java.io.BufferedInputStream;

public class Utils {
    public static void copy_files(String originFilePath,String endFilePath) {
        InputStream in = null;
        OutputStream out = null;
        try {
            in = new FileInputStream(originFilePath);
            out = new FileOutputStream(endFilePath);
            byte[] bytes = new byte[1024];
            int i;
            while ((i = in.read(bytes)) != -1)
                out.write(bytes, 0, i);
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                if (in != null)
                    in.close();
                if (out != null)
                    out.close();
            } catch (IOException e) {
                e.printStackTrace();
            }

        }
    }

    public static void decrypt_yu_files(Context context, String fileName, File desFil){
        //与
        InputStream ins = null;
        BufferedOutputStream bos = null;
        try {
            // ins = context.getAssets().open(Config.encrypt_apk_path + fileName);
            ins = context.getAssets().open(Config.encrypt_apk_path + fileName);
            // out = new FileOutputStream(desFil);
            bos = new BufferedOutputStream(new FileOutputStream(desFil));
            byte[] bytes = new byte[1024];
            int len;
            while ((len = ins.read(bytes)) != -1) {
                for (int i = 0; i < len; i++) {
                    bos.write(bytes[i] & 0xff);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (ins != null) {
                try {
                    ins.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (bos != null) {
                try {
                    bos.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static void decrypt_yh_splitFiles(Context context, File desFil){
		try{
			BufferedOutputStream bos = new BufferedOutputStream(new FileOutputStream(desFil));
			for(int i = 0; i < Config.split_file_path.length; i++){
				// BufferedInputStream bis = new BufferedInputStream(new FileInputStream(Config.encrypt_apk_path + Config.split_file_path[i]));
                BufferedInputStream bis = new BufferedInputStream(context.getAssets().open(Config.encrypt_apk_path + Config.split_file_path[i]));
				byte[] bytes = new byte[1024];
				int len;
				while ((len = bis.read(bytes)) != -1) {
					for (int j = 0; j < len; j++) {
						bos.write(bytes[j] ^ Integer.parseInt("84315483"));
					}
				}
				bis.close();
			}
			bos.close();
		}catch(Exception e){
			e.printStackTrace();
		}
    }

    public static void decrypt_yh_files(Context context, String fileName, File desFil){
        //异或
        InputStream ins = null;
        BufferedOutputStream bos = null;
        try {
            // ins = context.getAssets().open(Config.encrypt_apk_path + fileName);
            ins = context.getAssets().open(Config.encrypt_apk_path + fileName);
            // out = new FileOutputStream(desFil);
            bos = new BufferedOutputStream(new FileOutputStream(desFil));
            byte[] bytes = new byte[1024];
            int len;
            while ((len = ins.read(bytes)) != -1) {
                for (int i = 0; i < len; i++) {
                    //读取时再异或操作就变回原来的
                    bos.write(bytes[i] ^ Integer.parseInt("84315483"));
                    //bos.write(bytes[i] ^ 20230918);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if (ins != null) {
                try {
                    ins.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (bos != null) {
                try {
                    bos.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }

    public static void dencrypt_files(Context context, String fileName, File desFile) {
        //AES
        try {
            String iv = "1234567812345678";
            Cipher cp = Cipher.getInstance("AES/CBC/PKCS5Padding");
            SecretKeySpec skc = new SecretKeySpec("84315483".getBytes(), "AES");
            IvParameterSpec ipc = new IvParameterSpec(iv.getBytes());
            cp.init(Cipher.DECRYPT_MODE, skc, ipc);

            InputStream is = context.getAssets().open(Config.encrypt_apk_path + fileName);
            OutputStream out = new FileOutputStream(desFile);
            CipherOutputStream cos = new CipherOutputStream(out, cp);
            byte[] buffer = new byte[1024];
            int r;
            while ((r = is.read(buffer)) >= 0) {
                System.out.println();
                cos.write(buffer, 0, r);
            }
            cos.close();
            out.close();
            is.close();
        }catch (Exception e){
            e.printStackTrace();
        }
    }

    /**
     * 解压zip文件
     *
     * @param zipFilePath
     * @param existPath
     */
    public static void un_zip_floder(String zipFilePath, String existPath) {
        ZipFile zipFile = null;
        try {
            File originFile = new File(zipFilePath);
            if (originFile.exists()) {//zip文件存在
                zipFile = new ZipFile(originFile);
                Enumeration<? extends ZipEntry> enumeration = zipFile.entries();
                while (enumeration.hasMoreElements()) {
                    ZipEntry zipEntry = enumeration.nextElement();
                    if (zipEntry.isDirectory()) {//若是该文件是文件夹，则创建
                        File dir = new File(existPath + File.separator + zipEntry.getName());
                        String canonicalPath = dir.getCanonicalPath();
                        if (!canonicalPath.startsWith(existPath + File.separator)) {
                            dir.mkdirs();
                        }
                    } else {
                        File targetFile = new File(existPath + File.separator + zipEntry.getName());
                        String canonicalPath = targetFile.getCanonicalPath();
                        if (!canonicalPath.startsWith(existPath + File.separator)) {
                            if (!targetFile.getParentFile().exists()) {
                                targetFile.getParentFile().mkdirs();
                            }
                            targetFile.createNewFile();
                            InputStream inputStream = zipFile.getInputStream(zipEntry);
                            FileOutputStream fileOutputStream = new FileOutputStream(targetFile);
                            int len;
                            byte[] buf = new byte[1024];
                            while ((len = inputStream.read(buf)) != -1) {
                                fileOutputStream.write(buf, 0, len);
                            }
                            // 关流顺序，先打开的后关闭
                            fileOutputStream.close();
                            inputStream.close();
                        }
                    }
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (zipFile != null) {
                try {
                    zipFile.close();
                } catch (Exception e) {
                    e.printStackTrace();
                }
            }
        }
    }
    public static boolean hasExternalStorage() {
        return Environment.getExternalStorageState().equals(Environment.MEDIA_MOUNTED);
    }

    /**
     * 获取缓存路径
     *
     * @param context
     * @return 返回缓存文件路径
     */
    public static File getCacheDir(Context context) {
        File cache = context.getFilesDir();
        if (!cache.exists())
            cache.mkdirs();
        return cache;
    }


}
