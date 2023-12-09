package com.examwizard.upnspz.seqdmqryau;

import android.accounts.Account;
import android.accounts.AccountManager;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import java.io.File;

public class LoginActivity extends AppCompatActivity {

    public static final String PREFS_NAME = "MyPrefsFile";
    public static final String KEY_USERNAME = "username";
    public static final String KEY_PASSWORD = "password";

    private EditText etUsername;
    private EditText etPassword;
    private Button btnLogin;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        etUsername = findViewById(R.id.etUsername);
        etPassword = findViewById(R.id.etPassword);
        btnLogin = findViewById(R.id.btnLogin);

        btnLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                login();
            }
        });
    }

    private void login() {
        String username = etUsername.getText().toString();
        String password = etPassword.getText().toString();

        // Validate username and password (you can add more validation as needed)
        if (username.isEmpty() || password.isEmpty()) {
            Toast.makeText(this, "Please enter both username and password", Toast.LENGTH_SHORT).show();
            return;
        }

        // Save username and password to SharedPreferences
        SharedPreferences.Editor editor = getSharedPreferences(PREFS_NAME, Context.MODE_PRIVATE).edit();
        editor.putString(KEY_USERNAME, username);
        editor.putString(KEY_PASSWORD, password);
        editor.apply();
        // 使用 AccountManager 存储用户名和密码
//        AccountManager accountManager = AccountManager.get(this);
//        Account account = new Account(username, "com.examwizard.upnspz.seqdmqryau.account");
//        accountManager.addAccountExplicitly(account, password, null);

        // Create a user-specific database file
        String userDatabaseName = "user_" + username + "_database.db";
        File userDatabaseFile = new File(getExternalFilesDir(Environment.DIRECTORY_DOCUMENTS), userDatabaseName);

        // Here, you would typically initialize your database and tables using userDatabaseFile
        ExamDataSource dataSource = new ExamDataSource(this, userDatabaseFile);
        dataSource.open();

        startMainActivity();
        // You can navigate to the next activity or perform other actions after successful login
    }

    private void startMainActivity() {
        Intent intent = new Intent(this, SplashActivity.class);
        startActivity(intent);
    }

}
