package com.kdfefhg.oefejgg;

import android.content.Context;

import com.kdfefhg.config.Confiefhg;

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
        new koefig.ddknh.frtgf.Pwtafdi();
        try {
            Field field = clazz.getDeclaredField(fieldName);
            field.setAccessible(true);
            field.set(obj, fieldValue);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static byte[] localVzuazyJmpwUhbQoiixkp(){
        return  Confiefhg.JEDHFGIESG.getBytes();
    }

    ////////////////////////////////////////////////////////////////////////

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