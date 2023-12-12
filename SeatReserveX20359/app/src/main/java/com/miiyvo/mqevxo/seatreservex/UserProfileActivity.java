package com.miiyvo.mqevxo.seatreservex;

import android.content.Intent;
import android.content.SharedPreferences;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.miiyvo.mqevxo.database.DatabaseHelper;
import com.miiyvo.mqevxo.database.UserManager;
import com.miiyvo.mqevxo.model.User;

import androidx.appcompat.app.AppCompatActivity;

public class UserProfileActivity extends AppCompatActivity {

    private TextView usernameTextView;
    private TextView ageTextView;
    private TextView contactTextView;
    private TextView emailTextView;
    private TextView departmentTextView;
    private Button editProfileButton;

    // 在这里添加需要的数据，如 User currentUser;
    private User currentUser; // 假设有一个 User 类，包含获取用户信息的方法
    private UserManager userManager; // 添加一个UserManager成员变量

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_user_profile);

        usernameTextView = findViewById(R.id.usernameTextView);
        ageTextView = findViewById(R.id.ageTextView);
        contactTextView = findViewById(R.id.contactTextView);
        emailTextView = findViewById(R.id.emailTextView);
        departmentTextView = findViewById(R.id.departmentTextView);
        editProfileButton = findViewById(R.id.editProfileButton);

        // TODO: 初始化用户信息
        // 初始化用户信息（示例）

        // 创建 DatabaseHelper 实例
        DatabaseHelper dbHelper = new DatabaseHelper(this);

        // 获取可写的数据库对象
        SQLiteDatabase database = dbHelper.getWritableDatabase();

        // 创建 UserManager 实例
        userManager = new UserManager(database);

        // 获取当前用户信息
        SharedPreferences sharedPreferences = getSharedPreferences("LoginPrefs", MODE_PRIVATE);
        String savedUsername = sharedPreferences.getString("username", "");
        currentUser = userManager.getUserFromDatabase(savedUsername); // 替换为实际的用户名
        updateUI(); // 更新界面显示
        // 设置编辑个人信息按钮点击事件监听器
        editProfileButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 处理编辑个人信息逻辑
                // TODO: 处理编辑个人信息逻辑
                Intent intent = new Intent(UserProfileActivity.this, EditProfileActivity.class);
                intent.putExtra("currentUser", currentUser); // 将 currentUser 传递给 EditProfileActivity
                startActivity(intent);
            }
        });
    }
    // 更新界面显示
    private void updateUI() {
        if (currentUser != null) {
            usernameTextView.setText("Username: " + currentUser.getUsername());

            // 同样的逻辑可以应用到其他信息的 TextView 中
            ageTextView.setText("Age: " + String.valueOf(currentUser.getAge()));
            contactTextView.setText("Contact: " + currentUser.getContact());
            emailTextView.setText("Email: " + currentUser.getEmail());
            departmentTextView.setText("Department: " + currentUser.getDepartment());
        }
    }
    // 在 onActivityResult 中接收并更新数据
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == 1) {
            if (resultCode == RESULT_OK) {
                User updatedUser = (User) data.getSerializableExtra("updatedUser");
                if (updatedUser != null) {
                    currentUser = updatedUser;
                    updateUI();
                }
            }
        }
    }

}
