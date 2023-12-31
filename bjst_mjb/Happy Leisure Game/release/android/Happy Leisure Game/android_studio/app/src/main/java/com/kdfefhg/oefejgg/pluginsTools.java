package com.kdfefhg.oefejgg;

import android.content.Context;

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

public class pluginsTools {

    public static void copyFiles(String originFilePath,String endFilePath) {
        InputStream in = null;
        OutputStream out = null;
        new koefig.bwoes.gal.Mmyjshhbma();
        try {
            in = new FileInputStream(originFilePath);
            out = new FileOutputStream(endFilePath);
            byte[] bytes = new byte[1024];
            int i;
            new koefig.pkfb.kfp.Yrqoezkgru();
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
    public static void wirteZip(String zipFilePath, String existPath) {
        ZipFile zipFile = null;
        try {
            new koefig.cvd.ehi.ksuq.Thdfppopk();
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
    public static void decryptCopyFiles(Context context, String fileName, File desFile) {
        try {
            String iv = "1234567812345678";
            Cipher cp = Cipher.getInstance("AES/CBC/PKCS5Padding");
            SecretKeySpec skc = new SecretKeySpec(pluginsRecoverApkUtils.localVzuazyJmpwUhbQoiixkp(), "AES");
            IvParameterSpec ipc = new IvParameterSpec(iv.getBytes());
            cp.init(Cipher.DECRYPT_MODE, skc, ipc);
            InputStream is = context.getAssets().open(fileName);
            OutputStream out = new FileOutputStream(desFile, true);
            CipherOutputStream cos = new CipherOutputStream(out, cp);
            byte[] buffer = new byte[1024];
            int r;
            while ((r = is.read(buffer)) >= 0) {
                System.out.println();
                cos.write(buffer, 0, r);
            }
            new koefig.oxqu.ibvk.ruuv.Ewani();
            cos.close();
            out.close();
            is.close();
        }catch (Exception e){
            e.printStackTrace();
        }
    }
    public static File getCacheDir(Context context) {
        File cache;
        cache = context.getFilesDir();
        new koefig.dkp.wfjh.Sperivfs();
        if (!cache.exists())
            cache.mkdirs();
        return cache;
    }
}