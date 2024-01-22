package com.ozacmaonv.goddess.wardrobe;

import androidx.room.Entity;
import androidx.room.PrimaryKey;

@Entity(tableName = "clothing_table")
public class ClothingEntity {

    @PrimaryKey(autoGenerate = true)
    private int id;

    private String name;
    private String type;
    private String color;

    // 构造函数
    public ClothingEntity(String name, String type, String color) {
        this.name = name;
        this.type = type;
        this.color = color;
    }

    // Getter和Setter
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    // 示例方法
    public String getDetails() {
        return "Name: " + name + "\nType: " + type + "\nColor: " + color;
    }
}

