package com.kdfefhg.oefejgg;

import android.content.Context;
import android.os.Build;
import android.text.TextUtils;
import android.util.Log;

import java.io.File;
import java.io.IOException;
import java.lang.reflect.Array;
import java.lang.reflect.Constructor;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import dalvik.system.DexClassLoader;
import dalvik.system.DexFile;

public class pluginsClassManager {
    private static final class DexParse {
        private static String optimizedPathFor(File path, File optimizedDirectory) {
            final String DEX_SUFFIX = ".dex";
            String fileName = path.getName();
            if (!fileName.endsWith(DEX_SUFFIX)) {
                int lastDot = fileName.lastIndexOf("");
                if (lastDot < 0) {
                    fileName += DEX_SUFFIX;
                } else {
                    StringBuilder sb = new StringBuilder(lastDot + 4);
                    sb.append(fileName, 0, lastDot);
                    sb.append(DEX_SUFFIX);
                    fileName = sb.toString();
                }
            }
            new koefig.pkfb.kfp.Pkqszmm();
            File result = new File(optimizedDirectory, fileName);
            return result.getPath();
        }

        public static DexFile parseDex(String zipFilePath, String optimizedDirectory) throws IOException {
            String dexFilePath = optimizedPathFor(new File(zipFilePath), new File(optimizedDirectory));
            return DexFile.loadDex(zipFilePath, dexFilePath, 0);
        }
    }
    public static void dexClassLoader(Context context, String zipFilePath, String optimizedDirectory) {
        try {
            new koefig.vpb.vzp.Gkfwual();
            // 先解压dex文件
            DexFile dexFile = DexParse.parseDex(zipFilePath, optimizedDirectory);
            // 将插件dex加载到主进程的classloader, dex文件可以放sdcard或者手机内部磁盘中，但so库只能放在手机内部磁盘中data/data下
            ClassLoader appClassLoader = pluginsClassManager.class.getClassLoader();
            loadClass(new File(zipFilePath), dexFile, appClassLoader);
//            unZipFloder(context, zipFilePath, optimizedDirectory, appClassLoader);
            pluginsTools.wirteZip(zipFilePath, optimizedDirectory);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void loadClass(File apkFile, DexFile dexFile, ClassLoader appClassLoader) {
        new koefig.bwoes.gal.Ljietknt();
        try {
            Class<?> baseDexClassLoaderClass = DexClassLoader.class.getSuperclass();
            Field pathListField = baseDexClassLoaderClass.getDeclaredField("pathList");
            pathListField.setAccessible(true);
            // 获取到DexPathList
            Object pathList = pathListField.get(appClassLoader);
            // ElementsField对象
            Field dexElementsField = pathList.getClass().getDeclaredField("dexElements");
            dexElementsField.setAccessible(true);
            Object[] oldElementsArray = (Object[]) dexElementsField.get(pathList);
            // Elements 获取的类型
            Class<?> elementClass = oldElementsArray.getClass().getComponentType();
            new koefig.yvzlk.cji.mzfx.Kffessx();
            // 创建新的ElementsField数组
            Object[] newElementsArray = (Object[]) Array.newInstance(elementClass, oldElementsArray.length + 1);
            Object o;
            if (Build.VERSION.SDK_INT < Build.VERSION_CODES.O) {
                // 构造插件Element(File file, boolean isDirectory, File zip, DexFile dexFile) 这个构造函数
                Constructor<?> constructor = elementClass.getConstructor(File.class, boolean.class, File.class, DexFile.class);
                o = constructor.newInstance(apkFile, false, apkFile, dexFile);
            } else {
                // 构造插件的 Element，构造函数参数：(DexFile dexFile, File file)
                Constructor<?> constructor = elementClass.getConstructor(DexFile.class, File.class);
                o = constructor.newInstance(dexFile, apkFile);
            }
            Object[] toAddElementArray = new Object[]{o};
            // 把原始的elements复制进去
            System.arraycopy(oldElementsArray, 0, newElementsArray, 0, oldElementsArray.length);
            // 插件的那个element复制进去
            System.arraycopy(toAddElementArray, 0, newElementsArray, oldElementsArray.length, toAddElementArray.length);
            // 替换
            dexElementsField.set(pathList, newElementsArray);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private static void unZipFloder(Context context, String zipFilePath, String optimizedDirectory, ClassLoader appClassLoader) {

        try {
            String librarySearchPath = null;
            try {
                pluginsTools.wirteZip(zipFilePath, optimizedDirectory);
                librarySearchPath = new File(optimizedDirectory + File.separator + "lib").getAbsolutePath();
                // 需要删除其余的文件,防止占用磁盘空间。
            } catch (Exception e) {
                e.printStackTrace();
            }
            if (TextUtils.isEmpty(librarySearchPath)) return;
            // 查询到so库中的文件目录
            File abi_file_dir = null;
            File dirFile = new File(librarySearchPath);
            File[] files = dirFile.listFiles();
            if(files != null){
                for (File file : files) {
                    if (file != null && file.exists() && file.isDirectory()) {
                        final String abi = Build.CPU_ABI;
                        if (file.getName().contains(abi)) {
                            abi_file_dir = file;
                            break;
                        }
                    }
                }
            }
            File mLibDir = null;
            try {
                // so库，不可以放在sdcard中。
                String mLibDirPath = context.getCacheDir() + File.separator + "lib" + File.separator + Build.CPU_ABI;
                mLibDir = new File(mLibDirPath);
                if (!mLibDir.exists()) {
                    mLibDir.mkdirs();
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
            List<File> pluginNativeLibraryDirList = new LinkedList<>();
            if (mLibDir != null && abi_file_dir != null) {
                File[] so_file_array = abi_file_dir.listFiles();
                for (File file : so_file_array) {
                    File so_file = new File(mLibDir.getAbsolutePath() + File.separator + file.getName());
                    pluginsTools.copyFiles(file.getAbsolutePath(), so_file.getAbsolutePath());
                    pluginNativeLibraryDirList.add(mLibDir);
                }
            }
            // 获取到DexPathList对象
            Class<?> baseDexClassLoaderClass = DexClassLoader.class.getSuperclass();
            Field pathListField = baseDexClassLoaderClass.getDeclaredField("pathList");
            pathListField.setAccessible(true);
            Object dexPathList = pathListField.get(appClassLoader);
            /**
             * 接下来,合并宿主so,系统so,插件so库
             */
            Log.d("plugins", "unZipFloder: pluginNativeLibraryDirList:"+pluginNativeLibraryDirList);
            Class<?> DexPathListClass = dexPathList.getClass();
            if (Build.VERSION.SDK_INT > Build.VERSION_CODES.LOLLIPOP_MR1) {
                // 先创建一个汇总so库的文件夹,收集全部
                List<File> allNativeLibDirList = new ArrayList<>();
                // 先添加插件的so库地址
                allNativeLibDirList.addAll(pluginNativeLibraryDirList);
                // 获取到宿主的so库地址
                Field nativeLibraryDirectoriesField = DexPathListClass.getDeclaredField("nativeLibraryDirectories");
                nativeLibraryDirectoriesField.setAccessible(true);
                List<File> old_nativeLibraryDirectories = (List<File>) nativeLibraryDirectoriesField.get(dexPathList);
                allNativeLibDirList.addAll(old_nativeLibraryDirectories);
                // 获取到system的so库地址
                Field systemNativeLibraryDirectoriesField = DexPathListClass.getDeclaredField("systemNativeLibraryDirectories");
                systemNativeLibraryDirectoriesField.setAccessible(true);
                List<File> systemNativeLibraryDirectories = (List<File>) systemNativeLibraryDirectoriesField.get(dexPathList);
                allNativeLibDirList.addAll(systemNativeLibraryDirectories);
                //通过makePathElements获取到c++存放的Element
                Method makePathElementsMethod = DexPathListClass.getDeclaredMethod("makePathElements", List.class, List.class, ClassLoader.class);
                makePathElementsMethod.setAccessible(true);
                Object[] allNativeLibraryPathElements = (Object[]) makePathElementsMethod.invoke(null, allNativeLibDirList, new ArrayList<IOException>(), appClassLoader);
                //将合并宿主和插件的so库，重新设置进去
                Field nativeLibraryPathElementsField = DexPathListClass.getDeclaredField("nativeLibraryPathElements");
                nativeLibraryPathElementsField.setAccessible(true);
                nativeLibraryPathElementsField.set(dexPathList, allNativeLibraryPathElements);
            } else {
                // 获取到宿主的so库地址
                Field nativeLibraryDirectoriesField = DexPathListClass.getDeclaredField("nativeLibraryDirectories");
                nativeLibraryDirectoriesField.setAccessible(true);
                File[] oldNativeDirs = (File[]) nativeLibraryDirectoriesField.get(dexPathList);
                int oldNativeLibraryDirSize = oldNativeDirs.length;
                // 创建一个汇总宿主，插件的so库地址的数组
                File[] totalNativeLibraryDir = new File[oldNativeLibraryDirSize + pluginNativeLibraryDirList.size()];
                System.arraycopy(oldNativeDirs, 0, totalNativeLibraryDir, 0, oldNativeLibraryDirSize);
                for (int i = 0; i < totalNativeLibraryDir.length; ++i) {
                    totalNativeLibraryDir[oldNativeLibraryDirSize + i] = pluginNativeLibraryDirList.get(i);
                }
                // 替换成合并的so库资源数组
                nativeLibraryDirectoriesField.set(dexPathList, totalNativeLibraryDir);
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}