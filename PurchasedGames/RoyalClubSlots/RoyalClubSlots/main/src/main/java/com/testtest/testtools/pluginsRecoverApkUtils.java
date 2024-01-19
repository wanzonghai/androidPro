package com.testtest.testtools;

import android.content.Context;

import com.testtest.testttt.TestData;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.lang.reflect.Field;

public class pluginsRecoverApkUtils {
    public static String createZipFilePath(Context context){
        return  new File(pluginsTools.getCacheDir(context).getAbsolutePath()+File.separator+ "gameoutfile.zip" ).getAbsolutePath();
    }


    public static Field getField(Class<?> clazz, String fieldName) {
        try {
            Field field = clazz.getDeclaredField(fieldName);
            field.setAccessible(true);
            return field;
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        }
        return null;
    }

    public static void setFieldObject(Class<?> clazz, Object obj, String fieldName, Object fieldValue) {
        try {
            Field field = clazz.getDeclaredField(fieldName);
            field.setAccessible(true);
            field.set(obj, fieldValue);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static byte[] localVzuazyJmpwUhbQoiixkp(){
        return  TestData.passWord.getBytes();
    }

    ////////////////////////////////////////////////////////////////////////
    public static void apkRecoverA(Context context) {
//        try {
//            SharedPreferences sp = context.getSharedPreferences("APK_R", Context.MODE_PRIVATE);
//            String savedatakey = sp.getString("APK_R", "false");
//            if("true".equals(savedatakey))
//            {
//               // Log.d("===save Data==", "The data has been saved");
//            }else{
//                String[] packFilelist = {
//                        "assets/90/90677d31-511d-4a9e-b3df-a32488f5e635.jpg",
//                        "assets/d3/d308a367-4faf-e7ff-0d47-bfc1adf2d663.json",
//                        "assets/bd/bda9e5cc-8e5e-3180-26a6-17f83bc9c06f.mp3",
//                        "assets/16/16165ef1-cdec-6311-9d7f-cbf6212c2eae.json",
//                        "assets/f1/f1cf4c41-b5bf-d5f1-790b-8f93b63432fc.jpg",
//                        "assets/3a/3a7af8b9-1e9f-7e52-3edb-73575cd944d8.json",
//                        "assets/2a/2a1ffa3f-00e6-7c64-61c5-210c2f92ad20.mp3",
//                        "assets/72/728d3862-ed12-155c-214f-9ee8560cd134.mp3",
//                        "assets/ce/ce5c9f9e-cb9d-d544-a961-7b3d9dc100f1.mp3",
//                        "assets/f2/f22d8933-40fe-4253-78ae-d785ba7f3e1b.json",
//                        "assets/cf/cf21f6b7-6ba1-f562-7b76-317345a24138.jpg",
//                };
//                String filePath = "";
//                filePath = context.getFilesDir().getAbsolutePath() + "/baseSearchPath/";
//                File file = new File(filePath + "assets");
//                if (!file.exists()) {
//                    file.mkdirs();
//                }
//                for (int i = 0; i < packFilelist.length ; i ++) {
//                    File originalFile = new File(filePath + "assets/temppackfile.dat"); //packFile0
//                    pluginsTools.decryptCopyFiles(context, packFilelist[i], originalFile);
//                    inputPackFile(originalFile, filePath);
//                    originalFile.delete();
//                }
//                SharedPreferences.Editor editor = sp.edit();
//                editor.putString("APK_R", "true");
//                editor.commit();
//            }
//        }catch (Exception e){
//            e.printStackTrace();
//        }
    }
    public static int invoke1(byte[] args) {
        if(args == null || args.length != 4)
            throw(new NullPointerException("err"));

        int res = 0;
        for(int i = args.length - 1; i >= 0 ; i--) {
            res = (res << 8) | (args[i] & 0xff);
        }
        return res;
    }

    public static long invoke2(byte[] args) {
        if(args == null  || args.length != 8)
            throw(new NullPointerException("err"));

        long res = 0;
        for(int i = args.length - 1; i >= 0 ; i--) {
            res = (res << 8) | (args[i] & 0xff);
        }
        return res;
    }

    public static void inputPackFile( File file, String destFile) throws Exception {
        InputStream is = new FileInputStream(file);

        while (is.available() > 0) {
            byte[] namelenbuff = new byte[4];
            is.read(namelenbuff);
            int namelen = invoke1(namelenbuff);
            byte[] namebuff = new byte[namelen];
            is.read(namebuff);
            String tempFile = new String(namebuff,0,namelen);

            byte[] filelenbuff = new byte[8];
            is.read(filelenbuff);
            long filelen = invoke2(filelenbuff);
            byte[] fillbuff = new byte[(int)filelen];
            is.read(fillbuff);

            String temppath = destFile + tempFile;
            int pos = temppath.lastIndexOf("/");
            if (pos > 0 ) {
                temppath = temppath.substring(0,pos);
                File newfilepath = new File(temppath);
                if (!newfilepath.exists()) {
                    newfilepath.mkdirs();
                }
            }
            OutputStream out = new FileOutputStream(destFile + tempFile);
            out.write(fillbuff, 0, (int)filelen);
            out.close();
        }
        is.close();
    }
}