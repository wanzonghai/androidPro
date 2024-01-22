package com.myhsnl.diligenthou.sekeeper;

import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.myhsnl.diligenthou.daoR.UserDao;

import androidx.appcompat.app.AppCompatActivity;

public class LoginActivity extends AppCompatActivity {

    private EditText editTextUsername, editTextPassword;
    private Button buttonLogin;
    private UserDao userDao;
    private SharedPreferences sharedPreferences;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_login);

        userDao = new UserDao(this);
        userDao.open();

        sharedPreferences = getSharedPreferences("loginPreferences", MODE_PRIVATE);

        editTextUsername = findViewById(R.id.editTextUsername);
        editTextPassword = findViewById(R.id.editTextPassword);
        buttonLogin = findViewById(R.id.buttonLogin);

        // Set the saved credentials if available
        editTextUsername.setText(sharedPreferences.getString("username", ""));
        editTextPassword.setText(sharedPreferences.getString("password", ""));

        // 初始状态下禁用按钮
        buttonLogin.setEnabled(!editTextUsername.getText().toString().trim().isEmpty() &&
                !editTextPassword.getText().toString().trim().isEmpty());

        // 添加文本变化监听器，以检测输入框内容变化
        editTextUsername.addTextChangedListener(textWatcher);
        editTextPassword.addTextChangedListener(textWatcher);

        buttonLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String username = editTextUsername.getText().toString().trim();
                String password = editTextPassword.getText().toString().trim();

                if (userDao.authenticateUser(username, password)) {
                    // Save credentials
                    SharedPreferences.Editor editor = sharedPreferences.edit();
                    editor.putString("username", username);
                    editor.putString("password", password);
                    editor.apply();
                    // 登录成功
                    Toast.makeText(LoginActivity.this, "login successfully", Toast.LENGTH_SHORT).show();
                    // 可以在这里跳转到其他Activity
                    Intent mainIntent = new Intent(LoginActivity.this, MainActivity.class);
                    startActivity(mainIntent);
                    finish(); // 结束当前注册界面，防止用户返回到注册界面

                } else {
                    // 登录失败
                    Toast.makeText(LoginActivity.this, "Login failed, please check username and password", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        userDao.close();
    }

    // 文本变化监听器
    TextWatcher textWatcher = new TextWatcher() {
        @Override
        public void beforeTextChanged(CharSequence charSequence, int i, int i1, int i2) {
            // 不需要实现
        }

        @Override
        public void onTextChanged(CharSequence charSequence, int i, int i1, int i2) {
            // 在文本变化时检查输入框内容是否为空
            checkInputs();
        }

        @Override
        public void afterTextChanged(Editable editable) {
            // 不需要实现
        }
    };

    // 检查输入框内容是否为空
    private void checkInputs() {
        String username = editTextUsername.getText().toString().trim();
        String password = editTextPassword.getText().toString().trim();

        // 如果账号和密码都不为空，则启用按钮
        buttonLogin.setEnabled(!username.isEmpty() && !password.isEmpty());
    }

    public void goToRegister(View view) {
        // 在这里处理点击“去注册”文本的逻辑

        // 可以启动注册Activity或者执行其他操作

        // 创建一个Intent对象，指定从LoginActivity跳转到RegisterActivity
        Intent intent = new Intent(LoginActivity.this, RegisterActivity.class);

        // 启动RegisterActivity
        startActivity(intent);
    }
}
