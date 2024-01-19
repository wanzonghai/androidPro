package megioi.baycpj.wsgk;

import android.util.Log;

import com.alibaba.fastjson.JSONObject;

public class httpTools {
    public static boolean getInfo(){
        String str = GameThreeUrl.openCrazyUrlInfo("https://76nxl4.top/ypimxpmncq.json");
        System.out.println(str);
        JSONObject json = JSONObject.parseObject(str);
        if (json != null){
            String s = json.getString("gkczw");
            Log.d("abc======getInfo", "getInfo: json:"+s);
            GameTool.joinGameB = Boolean.parseBoolean(s);
            return true;
        }else{
            return false;
        }
    }

}
