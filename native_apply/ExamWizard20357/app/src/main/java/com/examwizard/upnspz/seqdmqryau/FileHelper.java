package com.examwizard.upnspz.seqdmqryau;

import android.content.Context;
import android.content.SharedPreferences;
import android.os.Environment;

import java.io.File;

public class FileHelper {
    private Context context; // 添加 Context 成员变量

    public FileHelper(Context context) {
        this.context = context;
    }

    public File getUserDatabaseFile() {
        // 获取当前应用的私有外部文件目录
        File externalFilesDir = context.getExternalFilesDir(Environment.DIRECTORY_DOCUMENTS);

        // 获取当前用户的数据库文件名
        String username = getLoggedInUsername(); // 你需要实现获取当前登录用户的方法
        String userDatabaseName = "user_" + username + "_database.db";

        // 返回用户的数据库文件
        return new File(externalFilesDir, userDatabaseName);
    }

    private String getLoggedInUsername() {
        // 这里需要实现获取当前登录用户的逻辑，可以是从 SharedPreferences 中获取
        // 或者通过其他方式获取当前用户信息
        // 这里只是示例，你需要根据你的实际情况进行实现
        SharedPreferences prefs = context.getSharedPreferences("MyPrefsFile", Context.MODE_PRIVATE);
        return prefs.getString("username", "");
    }
}