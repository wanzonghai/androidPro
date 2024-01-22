package com.ozacmaonv.goddess.wardrobe;

import androidx.lifecycle.LiveData;
import androidx.room.Dao;
import androidx.room.Delete;
import androidx.room.Insert;
import androidx.room.Query;
import androidx.room.Update;

import java.util.List;

@Dao
public interface ClothingDao {

    @Insert
    void insert(ClothingEntity clothingEntity);

    @Query("SELECT * FROM clothing_table")
    LiveData<List<ClothingEntity>> getAllClothing();

    @Delete
    void delete(ClothingEntity clothingEntity);
    @Update
    void update(ClothingEntity clothingEntity);
}
