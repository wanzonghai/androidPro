package com.attery.rhsmwpwa.saver;

import android.app.Notification;
import android.app.NotificationChannel;
import android.app.NotificationManager;
import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.content.IntentFilter;
import android.os.BatteryManager;
import android.os.Build;
import android.os.Bundle;
import android.widget.ProgressBar;
import android.widget.RemoteViews;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.NotificationCompat;

public class MainActivity extends AppCompatActivity {

    private TextView textBatteryStatus;
    private TextView textBatteryLevel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        textBatteryStatus = findViewById(R.id.textBatteryStatus);
        textBatteryLevel = findViewById(R.id.textBatteryLevel);

        // 注册电池状态变化的广播接收器
        IntentFilter filter = new IntentFilter(Intent.ACTION_BATTERY_CHANGED);
        registerReceiver(batteryReceiver, filter);

        // 创建通知通道
        createNotificationChannel();

        // 显示初始通知
        updateNotification(0);
    }

    // 创建广播接收器以接收电池信息
    private BroadcastReceiver batteryReceiver = new BroadcastReceiver() {
        @Override
        public void onReceive(Context context, Intent intent) {
            // 获取电池状态
            int status = intent.getIntExtra(BatteryManager.EXTRA_STATUS, -1);
            String statusText = "Unknown";

            if (status == BatteryManager.BATTERY_STATUS_CHARGING) {
                statusText = "Charging";
            } else if (status == BatteryManager.BATTERY_STATUS_DISCHARGING) {
                statusText = "Discharging";
            } else if (status == BatteryManager.BATTERY_STATUS_FULL) {
                statusText = "Full";
            } else if (status == BatteryManager.BATTERY_STATUS_NOT_CHARGING) {
                statusText = "Not Charging";
            }

            // Update UI
            int level = intent.getIntExtra(BatteryManager.EXTRA_LEVEL, -1);
            int scale = intent.getIntExtra(BatteryManager.EXTRA_SCALE, -1);
            float batteryPct = (level / (float) scale) * 100;
            // Update progress bar
            ProgressBar progressBar = findViewById(R.id.progressBatteryLevel);
            progressBar.setProgress((int) batteryPct);
            // 更新UI
            textBatteryStatus.setText("Battery Status: " + statusText);
            // Update text
            textBatteryLevel.setText("Battery Level: " + batteryPct + "%");
            updateNotification((int)batteryPct);
        }
    };

    private void createNotificationChannel() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O) {
            String channelId = "BatteryChannel";
            CharSequence channelName = "Battery Channel";
            int importance = NotificationManager.IMPORTANCE_LOW;
            NotificationChannel channel = new NotificationChannel(channelId, channelName, importance);

            NotificationManager notificationManager = getSystemService(NotificationManager.class);
            notificationManager.createNotificationChannel(channel);
        }
    }

    private void updateNotification(int batteryLevel) {
        String channelId = "BatteryChannel";

        RemoteViews remoteViews = new RemoteViews(getPackageName(), R.layout.notification_layout);

        remoteViews.setTextViewText(R.id.notificationBatteryStatus, "Battery Status: ");
        remoteViews.setTextViewText(R.id.notificationBatteryLevel, "Battery Level: " + batteryLevel + "%");

        NotificationCompat.Builder builder = new NotificationCompat.Builder(this, channelId)
                .setSmallIcon(R.drawable.ic_notification)
                .setCustomContentView(remoteViews)
                .setOngoing(true)
                .setPriority(NotificationCompat.PRIORITY_HIGH)
                .setTicker("Battery Level: " + batteryLevel + "%");  // This line sets the ticker message
        // 添加以下行来设置通知的优先级
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.JELLY_BEAN) {
            builder.setPriority(NotificationCompat.PRIORITY_HIGH);
        }
        Notification notification = builder.build();

        NotificationManager notificationManager = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);
        notificationManager.notify(1, notification);  // Use a unique notification ID
    }

    @Override
    protected void onDestroy() {
        // 注销广播接收器，避免内存泄漏
        unregisterReceiver(batteryReceiver);
        super.onDestroy();
    }


}
