package com.ozacmaonv.goddess.wardrobe;

import android.app.Application;

import androidx.room.Room;

public class MyApplication extends Application {

    public static ClothingDatabase clothingDatabase;

    @Override
    public void onCreate() {
        super.onCreate();
        // 初始化数据库
        ClothingDatabase.getInstance(this);
        clothingDatabase = Room.databaseBuilder(
                getApplicationContext(),
                ClothingDatabase.class,
                "clothing_database"
        ).build();
    }
}
