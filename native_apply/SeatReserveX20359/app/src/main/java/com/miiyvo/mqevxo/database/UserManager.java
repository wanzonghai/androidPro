package com.miiyvo.mqevxo.database;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;

import com.miiyvo.mqevxo.model.User;

import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class UserManager {

    private SQLiteDatabase database;

    public UserManager(SQLiteDatabase database) {
        this.database = database;
    }

    // 保存或更新用户信息到本地数据库
    public void saveUser(String username, String password) {
        ContentValues values = new ContentValues();
        values.put("username", username);
        values.put("password", password);

        // 插入用户信息到 Users 表，如果已存在则更新
        database.insertWithOnConflict("Users", null, values, SQLiteDatabase.CONFLICT_REPLACE);
    }

    // 验证用户信息
    public boolean isValidUser(String username, String password) {

        Cursor cursor = database.rawQuery("SELECT * FROM Users WHERE username = ? AND password = ?",
                new String[]{username, password});

        boolean isValid = cursor.getCount() > 0;

        cursor.close();

        return isValid;
    }

    public void addUser(String username, String password, String email, String role) {
        ContentValues values = new ContentValues();
        values.put("username", username);
        values.put("password", hashPassword(password)); // 使用哈希处理密码
        values.put("email", email);
        values.put("role", role);

        long result = database.insert("Users", null, values);

        if (result == -1) {
            Log.e("UserManager", "Failed to add user");
            // 处理添加用户失败的情况，例如显示错误消息
        } else {
            Log.d("UserManager", "User added successfully");
        }
    }


    // 获取用户信息
    public User getUserByUsername(String username) {
        User user = null;

        Cursor cursor = database.rawQuery("SELECT * FROM Users WHERE username = ?", new String[]{username});
        try {
            if (cursor.moveToFirst()) {
                int userIdIndex = cursor.getColumnIndex("user_id");
                int usernameIndex = cursor.getColumnIndex("username");
                int passwordIndex = cursor.getColumnIndex("password");

                if (userIdIndex >= 0 && usernameIndex >= 0 && passwordIndex >= 0) {
                    cursor.getInt(userIdIndex);
                    cursor.getString(usernameIndex);
                    cursor.getString(passwordIndex);
                    // 添加其他字段的获取，根据实际表结构
                } else {
                    // 处理索引无效的情况
                }
            }
        } finally {
            cursor.close();
        }

        return user;
    }
    // 哈希处理密码的方法
    private String hashPassword(String password) {
        try {
            MessageDigest md = MessageDigest.getInstance("SHA-256");
            byte[] hashedBytes = md.digest(password.getBytes());

            // 将字节数组转换为十六进制字符串
            StringBuilder stringBuilder = new StringBuilder();
            for (byte b : hashedBytes) {
                stringBuilder.append(Integer.toString((b & 0xff) + 0x100, 16).substring(1));
            }

            return stringBuilder.toString();
        } catch (NoSuchAlgorithmException e) {
            // 处理算法不支持的异常
            e.printStackTrace();
            return password; // 返回原始密码以避免登录失败
        }
    }

    // 从数据库中获取用户信息
    public User getUserFromDatabase(String username) {
        User user = null;

        Cursor cursor = database.rawQuery("SELECT * FROM Users WHERE username = ?", new String[]{username});
        try {
            if (cursor.moveToFirst()) {
                int userId= -1;
                String fetchedUsername = null;
                String password = null;
                String email = null;
                String role = null;
                int userIdIndex=cursor.getColumnIndex("user_id");
                int usernameIndex = cursor.getColumnIndex("username");
                int passwordIndex = cursor.getColumnIndex("password");
                int emailIndex = cursor.getColumnIndex("email");
                int roleIndex = cursor.getColumnIndex("role");
                if(userIdIndex!= -1){
                    userId = cursor.getInt(userIdIndex);
                }
                if (usernameIndex != -1) {
                    fetchedUsername = cursor.getString(usernameIndex);
                }

                if (passwordIndex != -1) {
                    password = cursor.getString(passwordIndex);
                }

                if (emailIndex != -1) {
                    email = cursor.getString(emailIndex);
                }

                if (roleIndex != -1) {
                    role = cursor.getString(roleIndex);
                }

                // 移除这些无效的获取字段
                // int age = cursor.getInt(cursor.getColumnIndex("age"));
                // String contact = cursor.getString(cursor.getColumnIndex("contact"));
                // String department = cursor.getString(cursor.getColumnIndex("department"));

                user = new User(userId, fetchedUsername, password, email, role);
                // 移除设置这些无效字段的语句
                // user.setAge(age);
                // user.setContact(contact);
                // user.setDepartment(department);
            }
        } finally {
            cursor.close();
        }


        return user;
    }
    // ...
}
