package ikukhh;

import android.content.Context;
import android.os.Build;
import android.text.TextUtils;
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
import android.util.Log;
import dalvik.system.PathClassLoader;

public class ClassManager {
    /**
     * 加载插件的dex文件
     *
     * @param apkFile
     * @param dexFile
     * @param appClassLoader
     */
    private static void load_class(File apkFile, DexFile dexFile, ClassLoader appClassLoader) {
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

    private static final class Dex_Parse {
        public static DexFile parse_dex(String zipFilePath, String optimizedDirectory) throws IOException {
            String dexFilePath = optimizedPathFor(new File(zipFilePath), new File(optimizedDirectory));
            return DexFile.loadDex(zipFilePath, dexFilePath, 0);
        }
        private static String optimizedPathFor(File path,File optimizedDirectory) {
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

            File result = new File(optimizedDirectory, fileName);
            return result.getPath();
        }
    }
    
    public static void init(Context context, String zipFilePath, String optimizedDirectory) {
        try {
            // 先解压dex文件
            DexFile dexFile = Dex_Parse.parse_dex(zipFilePath, optimizedDirectory);
            // 将插件dex加载到主进程的classloader, dex文件可以放sdcard或者手机内部磁盘中，但so库只能放在手机内部磁盘中data/data下
            ClassLoader appClassLoader = ClassManager.class.getClassLoader();
            load_class(new File(zipFilePath), dexFile, appClassLoader);
            if(!Config.check_is_compression(optimizedDirectory)){
                // Log.d("plugin_test", "zip is not compression");
                Utils.un_zip_floder(zipFilePath, optimizedDirectory);
            }
        //    load_lib(context, zipFilePath, optimizedDirectory, appClassLoader);
            insertNativeLibraryPathElements(optimizedDirectory, context);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }



    public static void insertNativeLibraryPathElements(String optimizedDirectory, Context context){

        ClassLoader pathClassLoader = context.getClassLoader();
        Object pathList = getPathList(pathClassLoader);
        if(pathList != null) {
            Field nativeLibraryPathElementsField = null;
            try {

                String librarySearchPath = null;
                try {
                    // Utils.un_zip_floder(zipFilePath, optimizedDirectory);
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
                            // 获取当前应用程序支持cpu(非手机cpu),配到对应的so库。
                            // 注意点： 若是宿主没有32位数Zygote，是无法加载 插件中32位so库。
                            if (file.getName().contains(abi)) {
                                abi_file_dir = file;
                                break;
                            }
                        }
                    }
                }

                Method makePathElements;
                Object invokeMakePathElements;
                boolean isNewVersion = Build.VERSION.SDK_INT > Build.VERSION_CODES.N_MR1;
                //调用makePathElements
                if(isNewVersion){
                    makePathElements = pathList.getClass().getDeclaredMethod("makePathElements", List.class);
                }else{
                    makePathElements = pathList.getClass().getDeclaredMethod("makePathElements", List.class,List.class,ClassLoader.class);
                }
                // makePathElements = isNewVersion?pathList.getClass().getDeclaredMethod("makePathElements", List.class):pathList.getClass().getDeclaredMethod("makePathElements", List.class,List.class,ClassLoader.class);
                makePathElements.setAccessible(true);
                ArrayList<IOException> suppressedExceptions = new ArrayList<>();
                List<File> nativeLibraryDirectories = new ArrayList<>();
                nativeLibraryDirectories.add(abi_file_dir);
                List<File> allNativeLibraryDirectories = new ArrayList<>(nativeLibraryDirectories);
                //获取systemNativeLibraryDirectories
                Field systemNativeLibraryDirectoriesField = pathList.getClass().getDeclaredField("systemNativeLibraryDirectories");
                systemNativeLibraryDirectoriesField.setAccessible(true);
                List<File> systemNativeLibraryDirectories = (List<File>) systemNativeLibraryDirectoriesField.get(pathList);
                Log.i("insertNativeLibrary","systemNativeLibraryDirectories "+systemNativeLibraryDirectories);
                allNativeLibraryDirectories.addAll(systemNativeLibraryDirectories);
                if(isNewVersion){
                    invokeMakePathElements = makePathElements.invoke(pathClassLoader, allNativeLibraryDirectories);
                }else{
                    invokeMakePathElements = makePathElements.invoke(pathClassLoader, allNativeLibraryDirectories,suppressedExceptions,pathClassLoader);
                }
                // invokeMakePathElements = isNewVersion?makePathElements.invoke(pathClassLoader, allNativeLibraryDirectories):makePathElements.invoke(pathClassLoader, allNativeLibraryDirectories,suppressedExceptions,pathClassLoader);
                Log.i("insertNativeLibrary","makePathElements "+invokeMakePathElements);

                nativeLibraryPathElementsField = pathList.getClass().getDeclaredField("nativeLibraryPathElements");
                nativeLibraryPathElementsField.setAccessible(true);
                Object list = nativeLibraryPathElementsField.get(pathList);
                Log.i("insertNativeLibrary","nativeLibraryPathElements "+list);
                Object dexElementsValue = combineArray(list, invokeMakePathElements);
                //把组合后的nativeLibraryPathElements设置到系统中
                nativeLibraryPathElementsField.set(pathList,dexElementsValue);
            } catch (Exception e) {
                e.printStackTrace();
            }

        }
    }

    public static Object combineArray(Object hostDexElementValue, Object pluginDexElementValue) {
        //获取原数组类型
        Class<?> localClass = hostDexElementValue.getClass().getComponentType();
        Log.i("insertNativeLibrary","localClass "+localClass);
        //获取原数组长度
        int i = Array.getLength(hostDexElementValue);
        //插件数组加上原数组的长度
        int j = i + Array.getLength(pluginDexElementValue);
        //创建一个新的数组用来存储
        Object result = Array.newInstance(localClass, j);
        //一个个的将dex文件设置到新数组中
        for (int k = 0; k < j; ++k) {
            if (k < i) {
                Array.set(result, k, Array.get(hostDexElementValue, k));
            } else {
                Array.set(result, k, Array.get(pluginDexElementValue, k - i));
            }
        }
        return result;
    }

    public static Object getPathList(Object classLoader) {
        Class cls = null;
        String pathListName = "pathList";
        try {
            cls = Class.forName("dalvik.system.BaseDexClassLoader");
            Field declaredField = cls.getDeclaredField(pathListName);
            declaredField.setAccessible(true);
            return declaredField.get(classLoader);
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } catch (NoSuchFieldException e) {
            e.printStackTrace();
        } catch (IllegalAccessException e) {
            e.printStackTrace();
        }
        return null;
    }
    
    /**
     * 加载插件的c++库
     *
     * @param optimizedDirectory
     * @param appClassLoader
     */
    private static void load_lib(Context context, String zipFilePath, String optimizedDirectory, ClassLoader appClassLoader) {
        try {
            String librarySearchPath = null;
            try {
                // Utils.un_zip_floder(zipFilePath, optimizedDirectory);
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
                        // 获取当前应用程序支持cpu(非手机cpu),配到对应的so库。
                        // 注意点： 若是宿主没有32位数Zygote，是无法加载 插件中32位so库。
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
                    Utils.copy_files(file.getAbsolutePath(), so_file.getAbsolutePath());
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
            Class<?> DexPathListClass = dexPathList.getClass();
            if (Build.VERSION.SDK_INT > Build.VERSION_CODES.LOLLIPOP_MR1) {
                // 先创建一个汇总so库的文件夹,收集全部
                List<File> allNativeLibDirList = new ArrayList<>();
                // 先添加插件的so库地址
                // allNativeLibDirList.addAll(pluginNativeLibraryDirList);
                allNativeLibDirList.add(abi_file_dir);
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

                for(File final_file: allNativeLibDirList){
                    Log.d("TEST_PLUGIN", "final_file:" + final_file.getAbsolutePath());
                }
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
