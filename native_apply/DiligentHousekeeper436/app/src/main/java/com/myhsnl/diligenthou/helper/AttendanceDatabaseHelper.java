package com.myhsnl.diligenthou.helper;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class AttendanceDatabaseHelper extends SQLiteOpenHelper {
    private static final String DATABASE_NAME = "attendance.db";
    private static final int DATABASE_VERSION = 1;

    // 考勤表
    private static final String TABLE_ATTENDANCE = "attendance_table";
    private static final String COLUMN_ATTENDANCE_ID = "id";
    private static final String COLUMN_ATTENDANCE_STUDENT_ID = "student_id";
    private static final String COLUMN_ATTENDANCE_COURSE_ID = "course_id";
    private static final String COLUMN_ATTENDANCE_DATE = "date";
    private static final String COLUMN_ATTENDANCE_STATUS = "status";
    public AttendanceDatabaseHelper(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }
    // 创建考勤表的 SQL 语句
    private static final String CREATE_TABLE_ATTENDANCE = "CREATE TABLE " +
            TABLE_ATTENDANCE + "(" +
            COLUMN_ATTENDANCE_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
            COLUMN_ATTENDANCE_STUDENT_ID + " INTEGER, " +
            COLUMN_ATTENDANCE_COURSE_ID + " INTEGER, " +
            COLUMN_ATTENDANCE_DATE + " INTEGER, " +
            COLUMN_ATTENDANCE_STATUS + " INTEGER);";

    // 构造方法和其他方法...

    @Override
    public void onCreate(SQLiteDatabase db) {
        // 创建考勤表
        db.execSQL(CREATE_TABLE_ATTENDANCE);
    }
    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        // 在数据库版本升级时调用，可以用来更新表结构或进行其他操作
        // 一般需要在这里备份数据，然后删除旧表，创建新表，最后还原数据
        db.execSQL("DROP TABLE IF EXISTS " + TABLE_ATTENDANCE);
        onCreate(db);
    }

    public void deleteAllAttendances() {
        // 删除所有考勤记录
        SQLiteDatabase db = this.getWritableDatabase();
        db.delete(TABLE_ATTENDANCE, null, null);
        db.close();
    }

    // 其他方法...
}

