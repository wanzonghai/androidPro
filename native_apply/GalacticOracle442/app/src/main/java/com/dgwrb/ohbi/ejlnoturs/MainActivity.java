package com.dgwrb.ohbi.ejlnoturs;

import android.animation.AnimatorSet;
import android.animation.ObjectAnimator;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.Spinner;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

public class MainActivity extends AppCompatActivity {

    private Spinner spinnerConstellations;
    private Button buttonGetHoroscope;
    private TextView textViewHoroscope;
    private ImageView imageViewPlanet;
    private boolean isAnimationRunning = false;
    // 在 MainActivity 中添加一个数组来存储星座对应的图片资源
    private static final int[] PLANET_IMAGES = {
            R.drawable.planet1,
            R.drawable.planet2,
            R.drawable.planet3,
            R.drawable.planet4,
            R.drawable.planet5,
            R.drawable.planet6,
            R.drawable.planet7,
            R.drawable.planet8,
            R.drawable.planet9,
            R.drawable.planet10,
            R.drawable.planet11,
            R.drawable.planet12,
            // ... 继续添加其他星座对应的图片资源
    };

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        spinnerConstellations = findViewById(R.id.spinnerConstellations);
        buttonGetHoroscope = findViewById(R.id.buttonGetHoroscope);
        textViewHoroscope = findViewById(R.id.textViewHoroscope);
        imageViewPlanet = findViewById(R.id.imageViewPlanet);

        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(
                this, R.array.constellations, android.R.layout.simple_spinner_item);
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinnerConstellations.setAdapter(adapter);

        spinnerConstellations.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> adapterView, View view, int position, long l) {
                if (!isAnimationRunning) {
                    // 在按钮未点击时，更新星座时启动旋转动画
                    startRotateAnimation();
                }
            }

            @Override
            public void onNothingSelected(AdapterView<?> adapterView) {
                // Do nothing here
            }
        });

        buttonGetHoroscope.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                isAnimationRunning = !isAnimationRunning;
                if (isAnimationRunning) {
                    // 当按钮点击时，停止星球旋转
                    stopRotateAnimation();
                    String selectedConstellation = spinnerConstellations.getSelectedItem().toString();
                    new GetHoroscopeTask().execute(selectedConstellation);
                } else {
                    // 当按钮再次点击时，恢复星球旋转
                    startRotateAnimation();
                }
            }
        });

        // 初始时启动星球旋转动画
        startRotateAnimation();
    }

    private void startRotateAnimation() {
        // 创建一个AnimatorSet来组合多个动画效果
        AnimatorSet animatorSet = new AnimatorSet();

        // 旋转动画
        ObjectAnimator rotateAnimator = ObjectAnimator.ofFloat(imageViewPlanet, "rotation", 0f, 360f);
        rotateAnimator.setDuration(3000);
        rotateAnimator.setRepeatCount(ObjectAnimator.INFINITE);
        rotateAnimator.setInterpolator(null);

        // 伪3D效果的平移动画
        ObjectAnimator translateAnimator = ObjectAnimator.ofFloat(imageViewPlanet, "translationY", 0f, -150f);
        translateAnimator.setDuration(3000);
        translateAnimator.setRepeatCount(ObjectAnimator.INFINITE);
        translateAnimator.setRepeatMode(ObjectAnimator.REVERSE);

        // 伪3D效果的缩放动画
        ObjectAnimator scaleXAnimator = ObjectAnimator.ofFloat(imageViewPlanet, "scaleX", 1f, 0.5f);
        scaleXAnimator.setDuration(3000);
        scaleXAnimator.setRepeatCount(ObjectAnimator.INFINITE);
        scaleXAnimator.setRepeatMode(ObjectAnimator.REVERSE);

        ObjectAnimator scaleYAnimator = ObjectAnimator.ofFloat(imageViewPlanet, "scaleY", 1f, 0.5f);
        scaleYAnimator.setDuration(3000);
        scaleYAnimator.setRepeatCount(ObjectAnimator.INFINITE);
        scaleYAnimator.setRepeatMode(ObjectAnimator.REVERSE);

        // 将所有动画添加到AnimatorSet中
        animatorSet.playTogether(rotateAnimator, translateAnimator, scaleXAnimator, scaleYAnimator);

        // 启动动画
        animatorSet.start();
    }

    private void stopRotateAnimation() {
        // 停止动画
        imageViewPlanet.clearAnimation();
    }

    private class GetHoroscopeTask extends AsyncTask<String, Void, String> {
        @Override
        protected String doInBackground(String... params) {
            // Perform network request to get horoscope for the selected constellation
            // You can use APIs or any other data source to get the horoscope information
            // For simplicity, a dummy message is returned here.
            return "Today is a great day for " + params[0] + "!";
        }

        @Override
        protected void onPostExecute(String result) {
            textViewHoroscope.setText(result);

            // 获取选定的星座在数组中的索引
            int selectedConstellationIndex = spinnerConstellations.getSelectedItemPosition();

            // 切换星球图片资源
            if (selectedConstellationIndex >= 0 && selectedConstellationIndex < PLANET_IMAGES.length) {
                imageViewPlanet.setImageResource(PLANET_IMAGES[selectedConstellationIndex]);
            }
        }
    }
}
