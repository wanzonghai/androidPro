package happy;

import android.app.PendingIntent;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

import java.util.Calendar;
import java.util.Date;
import java.util.List;

public class OnHappyRc extends BroadcastReceiver {

    @Override
    public void onReceive(Context context, Intent received_intent) {
        Log.d("========onReceive", "========== getNotificationChannel");
        if (Intent.ACTION_BOOT_COMPLETED.equals(received_intent.getAction())) {
            List<Intent> saved_notifications = MyHappy.loadNotificationIntents(context);

            for (Intent data_intent : saved_notifications) {
                long fireTime = data_intent.getLongExtra("fireTime", 0L);
                Date currentDate = Calendar.getInstance().getTime();
                Date fireTimeDate = new Date(fireTime);

                int id = data_intent.getIntExtra("id", -1);
                boolean isRepeatable = data_intent.getLongExtra("repeatInterval", 0L) > 0;

                if (fireTimeDate.after(currentDate) || isRepeatable) {
                    Intent openAppIntent = MyHappy.buildOpenAppIntent(data_intent, context, MyNotificationUtilities.getOpenAppActivity(context, true));

                    PendingIntent pendingIntent = MyHappy.getActivityPendingIntent(context, id, openAppIntent, 0);
                    Intent intent = MyHappy.buildNotificationIntent(context, data_intent, pendingIntent);

                    PendingIntent broadcast = MyHappy.getBroadcastPendingIntent(context, id, intent, PendingIntent.FLAG_UPDATE_CURRENT);
                    MyHappy.scheduleNotificationIntentAlarm(context, intent, broadcast);
                } else {
                    MyHappy.deleteExpiredNotificationIntent(context, Integer.toString(id));
                }
            }
        }
    }
}
