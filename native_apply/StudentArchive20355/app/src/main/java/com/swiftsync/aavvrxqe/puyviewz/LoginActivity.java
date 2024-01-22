package com.swiftsync.aavvrxqe.puyviewz;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.util.UUID;

import androidx.appcompat.app.AppCompatActivity;

// LoginActivity.java
public class LoginActivity extends AppCompatActivity {
//    EditText usernameEditText,passwordEditText;
    private SharedPreferences sharedPreferences;
    private static final String PREF_NAME = "login_pref";
    private static final String KEY_TOKEN = "token";
    private static final String KEY_IS_LOGGED_IN = "is_logged_in";
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

//        usernameEditText = findViewById(R.id.usernameEditText);
//        passwordEditText = findViewById(R.id.passwordEditText);
        Button loginButton = findViewById(R.id.loginButton);

        sharedPreferences = getSharedPreferences(PREF_NAME, MODE_PRIVATE);

        // 检查是否已经登录
        if (isLoggedIn()) {
            // 如果已经登录，直接跳转到主界面
            startActivity(new Intent(LoginActivity.this, SplashActivity.class));
            finish(); // 关闭当前登录界面
        }else {
            // If not logged in, simulate a first-time successful login
            simulateFirstTimeLogin();
        }
        loginButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 获取输入的用户名和密码
//                String username = usernameEditText.getText().toString().trim();
//                String password = passwordEditText.getText().toString().trim();
//                // 保存用户输入的账号和密码
//                saveLoginCredentials(username, password);
                startActivity(new Intent(LoginActivity.this, SplashActivity.class));
                finish(); // 关闭当前登录界面
            }
        });
    }
    private void authenticateUser(final String username, final String password) {
        // 在这里进行与服务器的通信和身份验证
        // 这里使用异步任务仅作为示例，实际应用中可能使用 Retrofit 或其他库进行网络通信
        new AsyncTask<Void, Void, String>() {
            @Override
            protected String doInBackground(Void... voids) {
                // 模拟与服务器的通信和身份验证
                // 在实际应用中，这里应该使用安全的协议和身份验证机制
                if (performServerAuthentication(username, password)) {
                    // 如果身份验证成功，生成并返回一个模拟的令牌
                    return generateAuthToken();
                }
                return null;
            }

            @Override
            protected void onPostExecute(String authToken) {
                if (authToken != null) {
                    // 登录成功，保存令牌和登录状态
                    saveLoginState(authToken);

                    // 启动主界面或其他操作
                    startActivity(new Intent(LoginActivity.this, SplashActivity.class));
                    finish(); // 关闭当前登录界面
                } else {
                    Toast.makeText(LoginActivity.this, "Login failed because the user name or password is incorrect", Toast.LENGTH_SHORT).show();
                }
            }
        }.execute();
    }

    private boolean performServerAuthentication(String username, String password) {
        // 在这里进行与服务器的身份验证
        // 这里仅作为演示，实际应用中应该使用安全的身份验证机制
        // 返回 true 表示验证成功，false 表示验证失败
        return "admin".equals(username) && "admin123".equals(password);
    }

    private String generateAuthToken() {
        // 模拟生成一个随机的令牌
        return UUID.randomUUID().toString();
    }

    private void saveLoginState(String authToken) {
        SharedPreferences.Editor editor = sharedPreferences.edit();
        editor.putString(KEY_TOKEN, authToken);
        editor.putBoolean(KEY_IS_LOGGED_IN, true);
        editor.apply();
    }

    private boolean isLoggedIn() {
        return sharedPreferences.getBoolean(KEY_IS_LOGGED_IN, false);
    }

    private void simulateFirstTimeLogin() {
        // Simulate a first-time successful login
        // In a real-world scenario, you might use a more secure method for authentication
//        String username = usernameEditText.getText().toString().trim();
//        String password = passwordEditText.getText().toString().trim();
//        authenticateUser(username, password);
    }
}
