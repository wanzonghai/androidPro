package com.miiyvo.mqevxo.model;

import java.util.Date;

public class Booking {
    private int bookingId;
    private int userId;
    private int seatId;
    private Date bookingTime;
    private boolean isCheckedIn;

    // 构造函数、getter 和 setter 方法
    public Booking() {
        // 空的构造函数
    }

    public Booking(int bookingId, int userId, int seatId, Date bookingTime, boolean isCheckedIn) {
        this.bookingId = bookingId;
        this.userId = userId;
        this.seatId = seatId;
        this.bookingTime = bookingTime;
        this.isCheckedIn = isCheckedIn;
    }

    public int getBookingId() {
        return bookingId;
    }

    public void setBookingId(int bookingId) {
        this.bookingId = bookingId;
    }

    public int getUserId() {
        return userId;
    }

    public void setUserId(int userId) {
        this.userId = userId;
    }

    public int getSeatId() {
        return seatId;
    }

    public void setSeatId(int seatId) {
        this.seatId = seatId;
    }

    public Date getBookingTime() {
        return bookingTime;
    }

    public void setBookingTime(Date bookingTime) {
        this.bookingTime = bookingTime;
    }

    public boolean isCheckedIn() {
        return isCheckedIn;
    }

    public void setCheckedIn(boolean checkedIn) {
        isCheckedIn = checkedIn;
    }

    // toString 方法，方便调试
    @Override
    public String toString() {
        return "Booking{" +
                "bookingId=" + bookingId +
                ", userId=" + userId +
                ", seatId=" + seatId +
                ", bookingTime=" + bookingTime +
                ", isCheckedIn=" + isCheckedIn +
                '}';
    }
}
