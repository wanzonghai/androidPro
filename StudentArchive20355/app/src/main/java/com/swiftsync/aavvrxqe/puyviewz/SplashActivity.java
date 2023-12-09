package com.swiftsync.aavvrxqe.puyviewz;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.widget.ProgressBar;

public class SplashActivity extends AppCompatActivity {

    // Splash screen timer
    private static final long SPLASH_TIME_OUT = 1500; // 1.5 seconds
    private ProgressBar progressBar;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_splash);
        // Find the ProgressBar by its ID
        progressBar = findViewById(R.id.progressBar);
        // Use a Handler to delay the opening of the main activity
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                // Start your main activity after the timer expires
                Intent intent = new Intent(SplashActivity.this, MainActivity.class);
                startActivity(intent);

                // Close this activity
                finish();
            }
        }, SPLASH_TIME_OUT);
    }
}
