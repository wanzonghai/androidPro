package com.ozacmaonv.goddess.wardrobe;

import android.content.Context;

import androidx.room.Database;
import androidx.room.Room;
import androidx.room.RoomDatabase;

@Database(entities = {ClothingEntity.class}, version = 1, exportSchema = false)
public abstract class ClothingDatabase extends RoomDatabase {

    private static ClothingDatabase instance;

    public abstract ClothingDao clothingDao();

    public static synchronized ClothingDatabase getInstance(Context context) {
        if (instance == null) {
            instance = Room.databaseBuilder(
                    context.getApplicationContext(),
                    ClothingDatabase.class,
                    "clothing_database"
            ).fallbackToDestructiveMigration().build();
        }
        return instance;
    }
}
