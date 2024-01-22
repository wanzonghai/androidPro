package com.miiyvo.mqevxo.database;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import com.miiyvo.mqevxo.model.Seat;

import java.util.ArrayList;
import java.util.List;

public class SeatManager {

    private SQLiteDatabase database;

    public SeatManager(SQLiteDatabase database) {
        this.database = database;
    }

    // 添加座位
    public void addSeat(String seatNumber) {
        ContentValues values = new ContentValues();
        values.put("seat_number", seatNumber);
        values.put("is_available", 1); // 初始状态为可用

        database.insert("Seats", null, values);
    }

    // 获取所有座位
    public List<Seat> getAllSeats() {
        List<Seat> seatList = new ArrayList<>();
        Cursor cursor = database.rawQuery("SELECT * FROM Seats", null);

        try {
            if (cursor.moveToFirst()) {
                do {
                    Seat seat = getSeatFromCursor(cursor);
                    seatList.add(seat);
                } while (cursor.moveToNext());
            }
        } finally {
            cursor.close();
        }

        return seatList;
    }

    // 根据座位ID获取座位
    public Seat getSeatById(int seatId) {
        Cursor cursor = database.rawQuery("SELECT * FROM Seats WHERE seat_id = ?", new String[]{String.valueOf(seatId)});

        Seat seat = null;

        try {
            if (cursor.moveToFirst()) {
                seat = getSeatFromCursor(cursor);
            }
        } finally {
            cursor.close();
        }

        return seat;
    }

    // 更新座位可用性
    public void updateSeatAvailability(int seatId, boolean isAvailable) {
        ContentValues values = new ContentValues();
        values.put("is_available", isAvailable ? 1 : 0);

        String whereClause = "seat_id=?";
        String[] whereArgs = {String.valueOf(seatId)};

        database.update("Seats", values, whereClause, whereArgs);
    }

    // 从 Cursor 中获取座位信息
    private Seat getSeatFromCursor(Cursor cursor) {
        int seatIdIndex = cursor.getColumnIndex("seat_id");
        int seatNumberIndex = cursor.getColumnIndex("seat_number");
        int isAvailableIndex = cursor.getColumnIndex("is_available");

        if (seatIdIndex >= 0 && seatNumberIndex >= 0 && isAvailableIndex >= 0) {
            int seatId = cursor.getInt(seatIdIndex);
            String seatNumber = cursor.getString(seatNumberIndex);
            boolean isAvailable = cursor.getInt(isAvailableIndex) == 1;
            // 调用带参数的构造函数初始化 Seat 对象
            Seat seat = new Seat(seatId, seatNumber, isAvailable);
            return seat;
        } else {
            // 处理索引无效的情况
            // 这里可以打印日志或进行其他错误处理
            return null; // 或者抛出异常，具体根据情况决定
        }
    }
}
