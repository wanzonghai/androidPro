package com.miiyvo.mqevxo.seatreservex;

import android.content.Intent;
import android.content.SharedPreferences;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.miiyvo.mqevxo.database.DatabaseHelper;
import com.miiyvo.mqevxo.database.SeatManager;
import com.miiyvo.mqevxo.database.UserManager;
import com.miiyvo.mqevxo.model.Seat;

import java.util.ArrayList;
import java.util.List;

import androidx.appcompat.app.AppCompatActivity;

public class LoginActivity extends AppCompatActivity {

    private EditText editTextUsername;
    private EditText editTextPassword;
    private Button buttonLogin;

    private SQLiteDatabase database;
    private UserManager userManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        editTextUsername = findViewById(R.id.editTextUsername);
        editTextPassword = findViewById(R.id.editTextPassword);
        buttonLogin = findViewById(R.id.buttonLogin);

        // 初始化数据库和 UserManager
//        database = openOrCreateDatabase("LocalDatabase", MODE_PRIVATE, null);

        // 创建 DatabaseHelper 对象并获取可写数据库
        DatabaseHelper dbHelper = new DatabaseHelper(this);
        database = dbHelper.getWritableDatabase();

        userManager = new UserManager(database);
        // 加载保存的用户名和密码到 EditText
        loadCredentials();
        // 初始化 SeatManager
        buttonLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 在这里执行登录操作
                String username = editTextUsername.getText().toString();
                String password = editTextPassword.getText().toString();

                // 检查输入是否为空
                if (isEmpty(username) || isEmpty(password)) {
                    showToast("Please enter both username and password");
                } else {
                    // TODO: 在这里处理用户名和密码，执行登录逻辑
                    if (userManager.isValidUser(username, password)) {
                        // 登录成功，可以跳转到其他页面或执行其他操作
                        // 登录成功，保存用户名和密码
                        saveCredentials(username, password);
                        showToast("Login successful");
                        // 示例：跳转到座位预订界面
                        Intent intent = new Intent(LoginActivity.this, MainActivity.class);
                        startActivity(intent);
                        finish(); // 关闭当前登录界面
                    } else {
                        // 登录失败，显示错误提示
                        showToast("Invalid username or password");
                    }
                }
            }
        });
        // 注册按钮点击事件
        Button buttonRegister = findViewById(R.id.buttonRegister);
        buttonRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 处理注册按钮点击事件
                // 启动注册界面
                startActivity(new Intent(LoginActivity.this, RegisterActivity.class));
            }
        });
    }

    // 检查字符串是否为空
    private boolean isEmpty(String text) {
        return text.trim().isEmpty();
    }

    // 显示 Toast 消息
    private void showToast(String message) {
        Toast.makeText(LoginActivity.this, message, Toast.LENGTH_SHORT).show();
    }


    // 保存用户名和密码到 SharedPreferences
    private void saveCredentials(String username, String password) {
        SharedPreferences sharedPreferences = getSharedPreferences("LoginPrefs", MODE_PRIVATE);
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.putString("username", username);
        editor.putString("password", password);
        editor.apply();
    }

    // 从 SharedPreferences 中获取保存的用户名和密码
    private void loadCredentials() {
        SharedPreferences sharedPreferences = getSharedPreferences("LoginPrefs", MODE_PRIVATE);
        String savedUsername = sharedPreferences.getString("username", "");
        String savedPassword = sharedPreferences.getString("password", "");

        editTextUsername.setText(savedUsername);
        editTextPassword.setText(savedPassword);
    }

}
