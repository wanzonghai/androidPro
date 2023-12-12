package com.miiyvo.mqevxo.seatreservex;

import android.content.Intent;
import android.content.SharedPreferences;
import android.database.sqlite.SQLiteDatabase;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;

import com.miiyvo.mqevxo.database.DatabaseHelper;
import com.miiyvo.mqevxo.database.UserManager;
import com.miiyvo.mqevxo.model.User;

import androidx.appcompat.app.AppCompatActivity;

public class EditProfileActivity extends AppCompatActivity {

    private EditText editUsername;
    private EditText editAge;
    private EditText editContact;
    private EditText editEmail;
    private EditText editDepartment;
    private Button saveChangesButton;

    private User currentUser; // 假设有一个 User 类，包含获取用户信息的方法
    private UserManager userManager; // 添加一个UserManager成员变量

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit_profile);

        editUsername = findViewById(R.id.editUsername);
        editAge = findViewById(R.id.editAge);
        editContact = findViewById(R.id.editContact);
        editEmail = findViewById(R.id.editEmail);
        editDepartment = findViewById(R.id.editDepartment);
        saveChangesButton = findViewById(R.id.saveChangesButton);
        // 获取当前用户信息
        // 创建 UserManager 实例
        // 获取传递的 currentUser
        Intent intent = getIntent();
        currentUser = (User) intent.getSerializableExtra("currentUser");
        saveChangesButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 获取用户输入的信息
                if (currentUser != null) {
                    // 获取用户输入的信息
                    String username = editUsername.getText().toString();
                    int age = Integer.parseInt(editAge.getText().toString());
                    String contact = editContact.getText().toString();
                    String email = editEmail.getText().toString();
                    String department = editDepartment.getText().toString();

                    // 更新用户信息
                    currentUser.setUsername(username);
                    currentUser.setAge(age);
                    currentUser.setContact(contact);
                    currentUser.setEmail(email);
                    currentUser.setDepartment(department);

                    Intent returnIntent = new Intent();
                    returnIntent.putExtra("updatedUser", currentUser);
                    setResult(RESULT_OK, returnIntent);
                    finish();
                } else {
                    // 处理 currentUser 为空的情况
                }
            }
        });
    }
}
