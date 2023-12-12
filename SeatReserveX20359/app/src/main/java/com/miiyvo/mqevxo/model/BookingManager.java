package com.miiyvo.mqevxo.model;

import android.content.ContentValues;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class BookingManager {

    private SQLiteDatabase database;

    public BookingManager(SQLiteDatabase database) {
        this.database = database;
    }

    public void addBooking(int userId, int seatId, Date bookingTime, boolean isCheckedIn) {
        ContentValues values = new ContentValues();
        values.put("user_id", userId);
        values.put("seat_id", seatId);
        values.put("booking_time", bookingTime.getTime()); // 存储时间戳
        values.put("is_checked_in", isCheckedIn ? 1 : 0);

        database.insert("Bookings", null, values);
    }

    public List<Booking> getAllBookings() {
        List<Booking> bookingList = new ArrayList<>();
        Cursor cursor = database.rawQuery("SELECT * FROM Bookings", null);

        try {
            if (cursor.moveToFirst()) {
                do {
                    Booking booking = getBookingFromCursor(cursor);
                    bookingList.add(booking);
                } while (cursor.moveToNext());
            }
        } finally {
            cursor.close();
        }

        return bookingList;
    }

    private Booking getBookingFromCursor(Cursor cursor) {
        Booking booking = new Booking();
        int bookingIdIndex = cursor.getColumnIndex("booking_id");
        int userIdIndex = cursor.getColumnIndex("user_id");
        int seatIdIndex = cursor.getColumnIndex("seat_id");
        int bookingTimeIndex = cursor.getColumnIndex("booking_time");
        int isCheckedInIndex = cursor.getColumnIndex("is_checked_in");

        if (bookingIdIndex >= 0 && userIdIndex >= 0 && seatIdIndex >= 0 && bookingTimeIndex >= 0 && isCheckedInIndex >= 0) {
            booking.setBookingId(cursor.getInt(bookingIdIndex));
            booking.setUserId(cursor.getInt(userIdIndex));
            booking.setSeatId(cursor.getInt(seatIdIndex));
            booking.setBookingTime(new Date(cursor.getLong(bookingTimeIndex)));
            booking.setCheckedIn(cursor.getInt(isCheckedInIndex) == 1);
        } else {
            // 处理索引无效的情况
            // 这里可以打印日志或进行其他错误处理
        }

        return booking;
    }

    public Booking getBookingById(int bookingId) {
        Cursor cursor = database.rawQuery("SELECT * FROM Bookings WHERE booking_id = ?", new String[]{String.valueOf(bookingId)});

        Booking booking = null;

        try {
            if (cursor.moveToFirst()) {
                booking = getBookingFromCursor(cursor);
            }
        } finally {
            cursor.close();
        }

        return booking;
    }

    public void updateCheckInStatus(int bookingId, boolean isCheckedIn) {
        ContentValues values = new ContentValues();
        values.put("is_checked_in", isCheckedIn ? 1 : 0);

        String whereClause = "booking_id=?";
        String[] whereArgs = {String.valueOf(bookingId)};

        database.update("Bookings", values, whereClause, whereArgs);
    }
}
