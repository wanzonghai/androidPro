package com.miiyvo.mqevxo.model;

import android.os.Parcel;
import android.os.Parcelable;

public class Floor implements Parcelable {
    private int floorId; // 更改类型为 int
    private String floorName;
    // 构造函数和其他属性

    protected Floor(Parcel in) {
        readFromParcel(in);
    }

    public static final Creator<Floor> CREATOR = new Creator<Floor>() {
        @Override
        public Floor createFromParcel(Parcel in) {
            return new Floor(in);
        }

        @Override
        public Floor[] newArray(int size) {
            return new Floor[size];
        }
    };

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeInt(floorId);  // 写入 int 类型
        dest.writeString(floorName);
    }
    // 添加从 Parcel 读取数据的方法
    private void readFromParcel(Parcel in) {
        floorId = in.readInt();
        floorName = in.readString();
    }
    public Floor(int floorId, String floorName) { // 添加构造函数
        this.floorId = floorId;
        this.floorName = floorName;
    }

    public int getFloorId() {
        return floorId;
    }
    public String getFloorName() {
        return floorName;
    }

    @Override
    public String toString() {
        return floorName; // 在下拉框中显示楼层的名称
    }
}