package temp_class;

import android.content.Context;

import java.io.File;

public final class Config {
    public static final String zip_file_name = "apk_zip.zip";
    public static final String application_name="temp_plugin_application_name";
    public static final String ori_zip_file_name = "temp_plugin_apk_name";
    public static final String EXTRA_INTENT = "EXTRA_INTENT";

    public static final String activity_name="app.DhinkaActivity";
    public static final String sub_activity_name="middle.SubActivity";
    public static final String encrypt_apk_path="temp_encrypt_apk_path";
    public static final String encrypt_apk_type="temp_encrypt_apk_type";
    public static final String[] split_file_path = temp_split_path;

    public static String get_zip_file_path(Context context){
        return  new File(Utils.getCacheDir(context).getAbsolutePath()+File.separator+ Config.zip_file_name).getAbsolutePath();
    }

    public static boolean check_is_compression(String rootPath){
        //检查当前是否已经解压过apk
        String filePath = rootPath + File.separator + "AndroidManifest.xml";
        File file = new File(filePath);
        if (file.exists()) {
            //已经解压过
            return true;
        }else{
            return false;
        }
    }

}
