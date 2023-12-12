package com.miiyvo.mqevxo.seatreservex;

import android.content.Intent;
import android.content.SharedPreferences;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.os.Handler;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import com.miiyvo.mqevxo.database.DatabaseHelper;
import com.miiyvo.mqevxo.database.UserManager;

import androidx.appcompat.app.AppCompatActivity;

public class RegisterActivity extends AppCompatActivity {

    private EditText editTextNewUsername;
    private EditText editTextNewPassword;
    private EditText editTextConfirmPassword;
    private Button buttonRegister;

    private SQLiteDatabase database;
    private UserManager userManager;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_register);

        editTextNewUsername = findViewById(R.id.editTextNewUsername);
        editTextNewPassword = findViewById(R.id.editTextNewPassword);
        editTextConfirmPassword = findViewById(R.id.editTextConfirmPassword);
        buttonRegister = findViewById(R.id.buttonRegister);

        // 初始化数据库和 UserManager
//        database = openOrCreateDatabase("LocalDatabase", MODE_PRIVATE, null);
        DatabaseHelper dbHelper = new DatabaseHelper(this);
        database = dbHelper.getWritableDatabase();
        userManager = new UserManager(database);

        userManager = new UserManager(database);

        buttonRegister.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 获取新用户输入的用户名、密码和确认密码
                String newUsername = editTextNewUsername.getText().toString();
                String newPassword = editTextNewPassword.getText().toString();
                String confirmPassword = editTextConfirmPassword.getText().toString();

                // 校验密码
                if (isValidPassword(newPassword, confirmPassword)) {
                    // 密码校验通过，执行注册逻辑
                    // 保存用户信息到本地数据库
                    userManager.saveUser(newUsername, newPassword);

                    // 在本地数据库中保存新用户的账号信息
                    saveUserToLocalDatabase(newUsername, newPassword);

//                    // 在全局数据库中创建用户个人数据库（假设使用用户名作为数据库名称）
//                    createPersonalDatabase(newUsername);

                    // 注册成功后，返回登录界面
                    Intent intent = new Intent(RegisterActivity.this, LoginActivity.class);
                    startActivity(intent);
                    Handler handler = new Handler();
                    handler.postDelayed(new Runnable() {
                        @Override
                        public void run() {
                            finish(); // 关闭当前注册界面
                        }
                    }, 100); // 100毫秒的延迟，你可以根据实际需要调整这个值
                } else {
                    // 密码校验失败，显示错误提示
                    Toast.makeText(RegisterActivity.this, "Passwords do not match", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    // 在本地数据库中保存新用户的账号信息（示例中使用 SharedPreferences）
    private void saveUserToLocalDatabase(String username, String password) {
        SharedPreferences preferences = getSharedPreferences("user_data", MODE_PRIVATE);
        SharedPreferences.Editor editor = preferences.edit();
        editor.putString(username, password);
        editor.apply(); // 使用 apply() 方法而不是 commit()
    }

//    // 在全局数据库中创建用户个人数据库（假设使用用户名作为数据库名称）
//    private void createPersonalDatabase(String username) {
//        // 在全局数据库中创建一个数据库，用于保存用户的个性化设置等信息
//        GlobalDatabaseHelper dbHelper = new GlobalDatabaseHelper(this);
//        dbHelper.createUserDatabase(username);
//    }

    // 校验密码是否匹配
    private boolean isValidPassword(String password, String confirmPassword) {
        return password.equals(confirmPassword);
    }
}
