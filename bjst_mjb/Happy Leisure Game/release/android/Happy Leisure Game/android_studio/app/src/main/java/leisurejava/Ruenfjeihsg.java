package leisurejava;

import android.app.Activity;

public class Ruenfjeihsg implements Ihfuhsefg {

    private String TAG = "RuntimeProxy";
    private Activity mActivity = null;
    public Ruenfjeihsg(Activity mainActivity) {
        mActivity = mainActivity;
    }


    public String getCacheDir()
    {
        String sCache = mActivity.getCacheDir().toString();
        String []vString = sCache.split("/");
        String sNewCache="";
        for( int i = 0; i < vString.length-1; i++ )
        {
            sNewCache += vString[i];
            sNewCache += "/";
        }
        return sNewCache;
    }
    public String getExpansionMainPath()
    {
        //TODO CP自行定制
        return "";
    }
    public String getExpansionPatchPath()
    {
        //TODO CP自行定制
        return "";
    }
    @Override
    public Object laya_get_value(String key) {
        
        String str = null;
        if (key.equalsIgnoreCase("CacheDir")) {
            return getCacheDir();
        }
        else if(key.equalsIgnoreCase("ExpansionMainPath")) {
            return getExpansionMainPath();
        }
        else if(key.equalsIgnoreCase("ExpansionPatchPath")) {
            return getExpansionPatchPath();
        }
        return str;
    }


}
