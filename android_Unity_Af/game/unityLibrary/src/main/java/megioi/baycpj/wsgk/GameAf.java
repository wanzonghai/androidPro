package megioi.baycpj.wsgk;

import android.util.Log;
import android.webkit.JavascriptInterface;

import com.alibaba.fastjson.JSONObject;
import com.appsflyer.AppsFlyerConversionListener;
import com.appsflyer.AppsFlyerLib;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

public class GameAf {
    public static GameAf m_instance = null;
    public static String Af_id="";
    public static GameAf getInstance(){
        if (m_instance ==null){
            m_instance = new GameAf();
        }
        Log.d("abc=====GameAf", "m_instance ======="+m_instance);
        return m_instance;
    }

    public static String slotState = "";
    public static GameApp _app = null;
    public static void slotInit(GameApp app){
        Log.d("abc=====af", "afInit =============");
        _app = app;
        AppsFlyerConversionListener __listener = new AppsFlyerConversionListener() {
            @Override
            public void onConversionDataSuccess(Map<String, Object> conversionData) {
                for (String attrName : conversionData.keySet()) {
                    if(null != conversionData.get(attrName) && "" != conversionData.get(attrName)){
                        if(attrName.equals("af_status")){
                            slotState = (String)conversionData.get(attrName);
                        }
                        Log.d("abc=====af", "af_status: "+ slotState);
                    }
                }
            }
            @Override
            public void onConversionDataFail(String errorMessage) {

            }
            @Override
            public void onAppOpenAttribution(Map<String, String> conversionData) {

            }
            @Override
            public void onAttributionFailure(String errorMessage) {
            }
        };

        AppsFlyerLib.getInstance().init(Af_id, __listener, _app);
        AppsFlyerLib.getInstance().start(_app);
    }

    public String getSlotState(){
        //return "Non-organic";
        return slotState;
    }

    @JavascriptInterface
    public void htoyxzwlk(String data) {
        Log.d("Tools appsFlyerEvent","=====data:"+data);
        Map<String, Object> m_data = new HashMap<String, Object>();
        JSONObject json = JSONObject.parseObject(data);
        Iterator it = json.entrySet().iterator();
        String eventType = "";
        while(it.hasNext()){
            Map.Entry entry = (Map.Entry) it.next();
            String key = entry.getKey().toString();
            Object value = entry.getValue();
            if(key.equals("event_type")){
                eventType = value.toString();
            }else
            {
                m_data.put(key, value);
            }
        }
        if(!eventType.equals("")){
            Log.d("LOG_TAG", "appsflyer事件: " + eventType);
            Log.d("LOG_TAG", String.valueOf(m_data));
            AppsFlyerLib.getInstance().logEvent(_app, eventType, m_data);
        }
    }
}
