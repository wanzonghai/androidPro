package h5.temps;

import android.app.Activity;
import android.content.ActivityNotFoundException;
import android.content.Context;
import android.content.Intent;
import android.net.Uri;
import android.provider.Browser;
import android.text.TextUtils;
import android.util.Log;
import android.widget.Toast;

import androidx.annotation.NonNull;

import com.alibaba.fastjson.JSON;
import com.appsflyer.AFInAppEventParameterName;
import com.appsflyer.AppsFlyerLib;
import com.appsflyer.attribution.AppsFlyerRequestListener;

import java.util.HashMap;
import java.util.Map;
public class AppsFlyerLibUtil {
    private static final String TAG = "AppsFlyerLibUtil";
    public static void init(Context context) {
        // app flay初始化
        AppsFlyerLib.getInstance().start(context, "hPAY8TDznmANNvueTJefBX", new AppsFlyerRequestListener() {
            @Override
            public void onSuccess() {
                Log.e(TAG, "Launch sent successfully, got 200 response code from server");
            }

            @Override
            public void onError(int i, @NonNull String s) {
                Log.e(TAG, "Launch failed to be sent:\n" + "Error code: " + i + "\n" + "Error description: " + s);
            }
        });
        AppsFlyerLib.getInstance().setDebugLog(true);
    }
    public static void event(Activity context, String name, String data) {
        Map<String, Object> eventValue = new HashMap<String, Object>();
        if ("openWindow".equals(name)) {
            Log.d(TAG, "======data: "+data);
            if (data.equals("undefined")){
                return;
            }
            String _url = "";
            Map maps = (Map) JSON.parse(data);
            for (Object map : maps.entrySet()) {
                String key = ((Map.Entry) map).getKey().toString();
                if ("url".equals(key)) {
                    Log.d(TAG, "======url: "+((Map.Entry) map).getValue().toString());
                    _url = ((Map.Entry) map).getValue().toString();
                } else if ("currency".equals(key)) {
                    eventValue.put(AFInAppEventParameterName.CURRENCY, ((Map.Entry) map).getValue());
                }
            }
            Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse(_url));
            context.startActivity(intent);
        } else if ("firstrecharge".equals(name) || "recharge".equals(name)) {
            try {
                Map maps = (Map) JSON.parse(data);
                for (Object map : maps.entrySet()) {
                    String key = ((Map.Entry) map).getKey().toString();
                    if ("amount".equals(key)) {
                        eventValue.put(AFInAppEventParameterName.REVENUE, ((Map.Entry) map).getValue());
                    } else if ("currency".equals(key)) {
                        eventValue.put(AFInAppEventParameterName.CURRENCY, ((Map.Entry) map).getValue());
                    }
                }
            } catch (Exception e) {

            }
        }else if ("openURL".equals(name)){
            Log.d(TAG, "event: ===================openURL");
            Log.d(TAG, "event: ===================data"+data);
            Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse(data));
            context.startActivity(intent);
        } else if ("withdrawOrderSuccess".equals(name)) {
            try {
                Map maps = (Map) JSON.parse(data);
                for (Object map : maps.entrySet()) {
                    String key = ((Map.Entry) map).getKey().toString();
                    if ("amount".equals(key)) {
                        float revenue = 0;
                        String value = ((Map.Entry) map).getValue().toString();
                        if (!TextUtils.isEmpty(value)) {
                            revenue = Float.valueOf(value);
                            revenue = -revenue;
                        }
                        eventValue.put(AFInAppEventParameterName.REVENUE, revenue);

                    } else if ("currency".equals(key)) {
                        eventValue.put(AFInAppEventParameterName.CURRENCY, ((Map.Entry) map).getValue());
                    }
                }
            } catch (Exception e) {

            }
        } else {
            eventValue.put(name, data);
        }
        AppsFlyerLib.getInstance().logEvent(context, name, eventValue);
        Toast.makeText(context, name, Toast.LENGTH_SHORT).show();
    }
}
