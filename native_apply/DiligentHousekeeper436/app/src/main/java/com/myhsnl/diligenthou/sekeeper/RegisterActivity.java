package com.myhsnl.diligenthou.sekeeper;

import android.content.Intent;
import android.os.Bundle;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.myhsnl.diligenthou.daoR.UserDao;
import com.myhsnl.diligenthou.model.User;

import androidx.appcompat.app.AppCompatActivity;

public class RegisterActivity extends AppCompatActivity {

    private EditText editTextNewUsername, editTextNewPassword, editTextRepeatPassword;
    private Button buttonRegister;
    private UserDao userDao;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        userDao = new UserDao(this);
        userDao.open();

        editTextNewUsername = findViewById(R.id.editTextNewUsername);
        editTextNewPassword = findViewById(R.id.editTextNewPassword);
        editTextRepeatPassword = findViewById(R.id.editTextRepeatPassword);
        buttonRegister = findViewById(R.id.buttonRegister);

        // 初始状态下禁用按钮
        buttonRegister.setEnabled(false);

        // 添加文本变化监听器，以检测输入框内容变化
        editTextNewUsername.addTextChangedListener(textWatcher);
        editTextNewPassword.addTextChangedListener(textWatcher);
        editTextRepeatPassword.addTextChangedListener(textWatcher);

        buttonRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String newUsername = editTextNewUsername.getText().toString().trim();
                String newPassword = editTextNewPassword.getText().toString().trim();
                String repeatPassword = editTextRepeatPassword.getText().toString().trim();

                if (!newPassword.equals(repeatPassword)) {
                    // 密码不一致，给予用户提示
                    Toast.makeText(RegisterActivity.this, "Password is different, please re-enter\n", Toast.LENGTH_SHORT).show();
                    return;
                }
                if (!newUsername.isEmpty() && !newPassword.isEmpty()) {
                    User newUser = new User(newUsername, newPassword);
                    long userId = userDao.addUser(newUser);

                    if (userId != -1) {
                        // 注册成功
                        Toast.makeText(RegisterActivity.this, "registered successfully", Toast.LENGTH_SHORT).show();
                        // 注册成功后，可以在这里跳转到登录界面或其他Activity
                        // 注册成功后，启动登录界面
                        Intent loginIntent = new Intent(RegisterActivity.this, LoginActivity.class);
                        startActivity(loginIntent);
                        finish(); // 结束当前注册界面，防止用户返回到注册界面
                    } else {
                        // 注册失败
                        Toast.makeText(RegisterActivity.this, "fail to register", Toast.LENGTH_SHORT).show();
                    }
                } else {
                    Toast.makeText(RegisterActivity.this, "Please enter your username and password", Toast.LENGTH_SHORT).show();
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
        String newUsername = editTextNewUsername.getText().toString().trim();
        String newPassword = editTextNewPassword.getText().toString().trim();
        String repeatPassword = editTextRepeatPassword.getText().toString().trim();

        // 如果账号和密码都不为空，则启用按钮
        buttonRegister.setEnabled(!newUsername.isEmpty() && !newPassword.isEmpty() && !repeatPassword.isEmpty());
    }

}
