package com.miiyvo.mqevxo.model;

import android.os.Parcel;
import android.os.Parcelable;

public class Seat implements Parcelable {
    private int seatId;
    private String seatNumber;
    private boolean isAvailable;
    // Parcelable 的实现

    protected Seat(Parcel in) {
        seatId = in.readInt();
        seatNumber = in.readString();
        isAvailable = in.readByte() != 0;
    }

    public static final Creator<Seat> CREATOR = new Creator<Seat>() {
        @Override
        public Seat createFromParcel(Parcel in) {
            return new Seat(in);
        }

        @Override
        public Seat[] newArray(int size) {
            return new Seat[size];
        }
    };

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeInt(seatId);
        dest.writeString(seatNumber);
        dest.writeByte((byte) (isAvailable ? 1 : 0));
    }

    public Seat(int seatId, String seatNumber, boolean isAvailable) {
        this.seatId = seatId;
        this.seatNumber = seatNumber;
        this.isAvailable = isAvailable;
    }

    // Getter 和 Setter 方法
    public int getSeatId() {
        return seatId;
    }

    public void setSeatId(int seatId) {
        this.seatId = seatId;
    }

    public String getSeatNumber() {
        return seatNumber;
    }

    public void setSeatNumber(String seatNumber) {
        this.seatNumber = seatNumber;
    }

    public boolean isAvailable() {
        return isAvailable;
    }

    public void setAvailable(boolean available) {
        isAvailable = available;
    }

    // 新增一个方法，用于从座位编号中解析楼层信息
    public int getFloorFromSeatNumber() {
        // 假设座位编号的格式是 "AX-Y", 其中 X 表示楼层
        // 你需要根据实际格式修改下面的解析逻辑
        String[] parts = seatNumber.split("-");
        if (parts.length == 2) {
            String floorPart = parts[0].substring(1); // 从第二个字符开始截取楼层信息
            try {
                return Integer.parseInt(floorPart);
            } catch (NumberFormatException e) {
                e.printStackTrace(); // 处理解析异常
            }
        }
        return -1; // 如果解析失败，返回一个标志值
    }

    // toString 方法，方便调试
    @Override
    public String toString() {
        return "Seat{" +
                "seatId=" + seatId +
                ", seatNumber='" + seatNumber + '\'' +
                ", isAvailable=" + isAvailable +
                '}';
    }
}
