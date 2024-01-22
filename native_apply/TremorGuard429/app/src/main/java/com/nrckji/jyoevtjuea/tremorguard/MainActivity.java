package com.nrckji.jyoevtjuea.tremorguard;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.media.AudioManager;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.os.Handler;
import android.os.Vibrator;
import android.text.Html;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;
import java.util.List;

public class MainActivity extends AppCompatActivity {
    private TextView gradeTextView = null;
    private Button stopButton = null; // 新增一个按钮
    private ImageView alertImage= null;
    private ImageView backgroundImage= null;
    private int DELAY_TIME_IN_MILLIS = 2000;

    private boolean alertTriggered = false;

    // 创建一个 Handler 用于控制闪烁效果
    private Handler handler ;

    private Vibrator vibrator;
    private MediaPlayer mediaPlayer;
    private boolean isTest=true;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        gradeTextView = findViewById(R.id.textView);
        gradeTextView.setText("No earthquake warning at the moment.\n (An alarm is issued when an earthquake warning is triggered)");
        // 添加关闭按钮点击事件
        stopButton = findViewById(R.id.stopButton);
        stopButton.setVisibility(View.GONE); // 关闭按钮
        alertImage = findViewById(R.id.alertImage);
        alertImage.setVisibility(View.GONE);
        backgroundImage=findViewById(R.id.backgroundImage);
        handler = new Handler();
        fetchData();
    }

    private void fetchData() {
//        if(isTest){
//            // 模拟地震数据的获取过程（仅用于测试）
//            List<Earthquake> mockEarthquakes = MockEarthquakeData.generateMockData();
//            EarthquakeResponse mockResponse = new EarthquakeResponse(mockEarthquakes);
//            mockResponse.setFeatures(mockEarthquakes);
//
//            // 处理模拟的地震数据
//            handleEarthquakeData(mockResponse);
//            return;
//        }
        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl("https://earthquake.usgs.gov/")
                .addConverterFactory(GsonConverterFactory.create())
                .build();

        EarthquakeService service = retrofit.create(EarthquakeService.class);
        Call<EarthquakeResponse> call = service.getEarthquakes();

        call.enqueue(new Callback<EarthquakeResponse>() {
            @Override
            public void onResponse(Call<EarthquakeResponse> call, Response<EarthquakeResponse> response) {
                if (response.isSuccessful()) {
                    handleEarthquakeData(response.body());
                } else {
                    showErrorMessage();
                }
            }

            @Override
            public void onFailure(Call<EarthquakeResponse> call, Throwable t) {
                showErrorMessage();
                retryFetchData();
            }
        });
    }

    private void handleEarthquakeData(EarthquakeResponse earthquakeResponse) {
        List<Earthquake> earthquakes = earthquakeResponse.getFeatures();

        for (Earthquake earthquake : earthquakes) {
            if (earthquake.getMagnitude() >= 5.0 && !alertTriggered) {
                triggerAlarm(earthquake.getMagnitude());
                alertTriggered = true;
                break;
            }
        }
    }

    private void showErrorMessage() {
        // Show error message to user (e.g., using Toast or updating UI)
        Toast.makeText(MainActivity.this, "Network request failed!", Toast.LENGTH_SHORT).show();
    }

    private void retryFetchData() {
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                fetchData();
            }
        }, DELAY_TIME_IN_MILLIS); // Set delay time
    }

    private void triggerAlarm(double magnitude) {
        AudioManager audioManager = (AudioManager) getSystemService(AUDIO_SERVICE);
        if (audioManager != null) {
            audioManager.adjustVolume(AudioManager.ADJUST_RAISE, AudioManager.FLAG_PLAY_SOUND);
        }

        vibrator = (Vibrator) getSystemService(VIBRATOR_SERVICE);
        if (vibrator != null) {
            long[] pattern = {0, 100, 1000};
            vibrator.vibrate(pattern, 0); // 修改震动为持续震动
        }

        mediaPlayer = MediaPlayer.create(this, R.raw.alarm_sound);
        mediaPlayer.setLooping(true); // 设置音频循环播放
        mediaPlayer.start();

        // 设置警告图标或者显示警告动画
        // warningIconImageView.setVisibility(View.VISIBLE);
        alertImage.setVisibility(View.VISIBLE); // 显示关闭按钮
        startFlashing();

        // 改变界面显示，设置红色警报和显示地震实际等级
        gradeTextView.setText("Earthquake warning occurred! The grades are approximately: " + magnitude+"\n afety tip: Stay calm and move to a safe place. Contact your local emergency services as soon as possible");
        gradeTextView.setTextColor(Color.RED);

        backgroundImage.setImageResource(R.drawable.bg2);

        stopButton.setVisibility(View.VISIBLE); // 显示关闭按钮
        stopButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                stopAlert();
            }
        });
    }
    // 在警报触发时调用，开启闪烁效果
    private void startFlashing() {
        flashingRunnable.run();
    }

    // 在警报关闭时调用，停止闪烁效果
    private void stopFlashing() {
        handler.removeCallbacks(flashingRunnable);
        alertImage.setVisibility(View.GONE); // 关闭警报时隐藏图片
    }
    private void stopAlert() {
        if (vibrator != null) {
            vibrator.cancel(); // 关闭震动
        }
        if (mediaPlayer != null) {
            mediaPlayer.stop(); // 停止播放音频
            mediaPlayer.release(); // 释放资源
        }

        stopButton.setVisibility(View.GONE); // 隐藏关闭按钮
        gradeTextView.setText("No earthquake warning at the moment.\n (An alarm is issued when an earthquake warning is triggered)");
        gradeTextView.setTextColor(Color.GREEN);
        backgroundImage.setImageResource(R.drawable.bg1);
        stopFlashing();
    }
    // 闪烁的 Runnable
    private Runnable flashingRunnable = new Runnable() {
        @Override
        public void run() {
            if (alertImage.getVisibility() == View.VISIBLE) {
                alertImage.setVisibility(View.INVISIBLE);
            } else {
                alertImage.setVisibility(View.VISIBLE);
            }

            // 设置闪烁频率，这里是 500ms
            handler.postDelayed(this, 500);

        }
    };
}
