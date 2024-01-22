package com.miiyvo.mqevxo.database;

import android.content.Context;
import android.content.SharedPreferences;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.util.Log;

import com.miiyvo.mqevxo.model.Seat;

import java.util.ArrayList;
import java.util.List;

public class DatabaseHelper extends SQLiteOpenHelper {

    private static final String DATABASE_NAME = "SeatReservationDatabase";
    private static final int DATABASE_VERSION = 1;

    private static final String PREFS_NAME = "MyPrefsFile";
    private static final String DATABASE_CREATED = "database_created";
    private Context context;
    public DatabaseHelper(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
        this.context = context;
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        // 创建 Seats 表
        String createSeatsTable = "CREATE TABLE IF NOT EXISTS Seats (" +
                "id INTEGER PRIMARY KEY AUTOINCREMENT," +
                "seat_number TEXT UNIQUE," +
                "is_available INTEGER DEFAULT 1);";
        db.execSQL(createSeatsTable);

        // 创建 Users 表
        String createUsersTable = "CREATE TABLE IF NOT EXISTS Users (" +
                "id INTEGER PRIMARY KEY AUTOINCREMENT," +
                "username TEXT UNIQUE," +
                "password TEXT," +
                "email TEXT," +
                "role TEXT);";
        db.execSQL(createUsersTable);

        // 创建 Bookings 表
        String createBookingsTable = "CREATE TABLE IF NOT EXISTS Bookings (" +
                "id INTEGER PRIMARY KEY AUTOINCREMENT," +
                "user_id INTEGER," +
                "seat_id INTEGER," +
                "booking_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP," +
                "is_checked_in INTEGER DEFAULT 0," +
                "FOREIGN KEY(user_id) REFERENCES Users(id)," +
                "FOREIGN KEY(seat_id) REFERENCES Seats(id));";
        db.execSQL(createBookingsTable);
    }
    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        // 在数据库版本更新时的操作
    }
}
