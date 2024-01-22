package com.ozacmaonv.goddess.wardrobe;

public class ClothingItem {
    private String name;
    private String type;
    private String color;

    public ClothingItem(String name, String type, String color) {
        this.name = name;
        this.type = type;
        this.color = color;
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
