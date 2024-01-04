package temp_class;

import android.content.Context;
import android.content.res.AssetManager;
import android.content.res.Resources;
import android.os.Build;

import java.lang.ref.WeakReference;
import java.lang.reflect.Field;
import java.lang.reflect.Method;
import java.util.Map;
import android.app.Application;

public class ResourceManager {
    private static Resources multiResources;

    public static void init(Context context, String apkFilePath) {
        // load_resource(context, apkFilePath);//未成功 
        // mergePluginResources(context, apkFilePath);//在有application的情况下是成功的
        createAssetManager(context, apkFilePath);//重新创建AssetManager，只在插件时传过去
    }

    protected synchronized static void createAssetManager(Context context, String apkFilePath) {
        try{
            //通过反射创建新的AssetManager对象，通过addAssetPath加载插件资源
            AssetManager am = AssetManager.class.newInstance();
            Reflector.with(am).method("addAssetPath", String.class).call(apkFilePath);
            Resources resources = new Resources(am, context.getResources().getDisplayMetrics(), context.getResources().getConfiguration());
            multiResources = resources;
        }catch(Exception e){
            e.printStackTrace();
        }
    }

    private synchronized static void load_resource(Context context, String apkFilePath) {
        try {
            // 先创建AssetManager
            Class<? extends AssetManager> AssetManagerClass = AssetManager.class;
//            AssetManager assetManager = AssetManagerClass.newInstance();
            AssetManager assetManager = context.getAssets();

            // 将插件资源和宿主资源通过 addAssetPath方法添加进去
            Method addAssetPathMethod = AssetManagerClass.getDeclaredMethod("addAssetPath", String.class);
            addAssetPathMethod.setAccessible(true);

            String hostResourcePath = context.getPackageResourcePath();
            addAssetPathMethod.invoke(assetManager, hostResourcePath);
            addAssetPathMethod.invoke(assetManager, apkFilePath);

            // 接下来创建，合并资源后的Resource
            Resources resources = new Resources(assetManager, context.getResources().getDisplayMetrics(), context.getResources().getConfiguration());
            // 替换 ContextImpl 中Resource对象
            Class<?> contextImplClass = context.getClass();
            Field resourcesField1 = contextImplClass.getDeclaredField("mResources");
            resourcesField1.setAccessible(true);
            resourcesField1.set(context, resources);

            // 先获取到LoadApk对象
            Field loadedApkField = contextImplClass.getDeclaredField("mPackageInfo");
            loadedApkField.setAccessible(true);
            Object loadApk = loadedApkField.get(context);

            Class<?> loadApkClass = loadApk.getClass();
            // 替换掉LoadApk中的Resource对象。
            Field resourcesField2 = loadApkClass.getDeclaredField("mResources");
            resourcesField2.setAccessible(true);
            resourcesField2.set(loadApk, resources);

            //获取到ActivityThread
            Class<?> ActivityThreadClass = Class.forName("android.app.ActivityThread");
            Field sCurrentActivityThreadField = ActivityThreadClass.getDeclaredField("sCurrentActivityThread");
            sCurrentActivityThreadField.setAccessible(true);
            Object ActivityThread = sCurrentActivityThreadField.get(null);
            // 获取到ResourceManager对象
            Field ResourcesManagerField = ActivityThreadClass.getDeclaredField("mResourcesManager");
            ResourcesManagerField.setAccessible(true);
            Object resourcesManager = ResourcesManagerField.get(ActivityThread);
            // 替换掉ResourceManager中resource对象
            if (Build.VERSION.SDK_INT < Build.VERSION_CODES.N) {
                Class<?> resourcesManagerClass = resourcesManager.getClass();
                Field mActiveResourcesField = resourcesManagerClass.getDeclaredField("mActiveResources");
                mActiveResourcesField.setAccessible(true);
                Map<Object, WeakReference<Resources>> map = (Map<Object, WeakReference<Resources>>) mActiveResourcesField.get(resourcesManager);
                Object key = map.keySet().iterator().next();
                map.put(key, new WeakReference<>(resources));
            } else {
                // still hook Android N Resources, even though it's unnecessary, then nobody will be strange.
                Class<?> resourcesManagerClass = resourcesManager.getClass();
                Field mResourceImplsField = resourcesManagerClass.getDeclaredField("mResourceImpls");
                mResourceImplsField.setAccessible(true);
                Map map = (Map) mResourceImplsField.get(resourcesManager);
                Object key = map.keySet().iterator().next();
                Field mResourcesImplField = Resources.class.getDeclaredField("mResourcesImpl");
                mResourcesImplField.setAccessible(true);
                Object resourcesImpl = mResourcesImplField.get(resources);

                map.put(key, new WeakReference<>(resourcesImpl));
            }
            multiResources = resources;
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    private synchronized static void mergePluginResources(Application application, String apkFilePath)  {
        try{
            // 创建一个新的 AssetManager 对象
            AssetManager newAssetManagerObj = AssetManager.class.newInstance();
            Method addAssetPath = AssetManager.class.getMethod("addAssetPath", String.class);

            //合并资源
            String hostResourcePath = application.getPackageResourcePath();
            addAssetPath.invoke(newAssetManagerObj, hostResourcePath);
            addAssetPath.invoke(newAssetManagerObj, apkFilePath);


            // 塞入原来宿主的资源
            // addAssetPath.invoke(newAssetManagerObj, application.getBaseContext().getPackageResourcePath());
            // // 塞入插件的资源
            // File optDexFile = application.getBaseContext().getFileStreamPath(apkName);
            // addAssetPath.invoke(newAssetManagerObj, optDexFile.getAbsolutePath());
        
            // ----------------------------------------------
        
            // 创建一个新的 Resources 对象
            Resources newResourcesObj = new Resources(newAssetManagerObj,
                    application.getBaseContext().getResources().getDisplayMetrics(),
                    application.getBaseContext().getResources().getConfiguration());
        
            // ----------------------------------------------
        
            // 获取 ContextImpl 中的 Resources 类型的 mResources 变量，并替换它的值为新的 Resources 对象
            Field resourcesField = application.getBaseContext().getClass().getDeclaredField("mResources");
            resourcesField.setAccessible(true);
            resourcesField.set(application.getBaseContext(), newResourcesObj);
        
            // ----------------------------------------------
        
            // 获取 ContextImpl 中的 LoadedApk 类型的 mPackageInfo 变量
            Field packageInfoField = application.getBaseContext().getClass().getDeclaredField("mPackageInfo");
            packageInfoField.setAccessible(true);
            Object packageInfoObj = packageInfoField.get(application.getBaseContext());
        
            // 获取 mPackageInfo 变量对象中类的 Resources 类型的 mResources 变量，，并替换它的值为新的 Resources 对象
            // 注意：这是最主要的需要替换的，如果不需要支持插件运行时更新，只留这一个就可以了
            Field resourcesField2 = packageInfoObj.getClass().getDeclaredField("mResources");
            resourcesField2.setAccessible(true);
            resourcesField2.set(packageInfoObj, newResourcesObj);
        
            // ----------------------------------------------
        
            // 获取 ContextImpl 中的 Resources.Theme 类型的 mTheme 变量，并至空它
            // 注意：清理mTheme对象，否则通过inflate方式加载资源会报错, 如果是activity动态加载插件，则需要把activity的mTheme对象也设置为null
            Field themeField = application.getBaseContext().getClass().getDeclaredField("mTheme");
            themeField.setAccessible(true);
            themeField.set(application.getBaseContext(), null);
            multiResources = newResourcesObj;
        }catch(Exception e){
            e.printStackTrace();
        }
    }


    public static Resources getLocalResources() {
        return multiResources;
    }
}
