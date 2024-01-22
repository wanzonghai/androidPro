package com.myhsnl.diligenthou.helper;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

public class DatabaseHelper extends SQLiteOpenHelper {

    private static final String DATABASE_NAME = "user.db";
    private static final int DATABASE_VERSION = 1;

    // 用户信息表
    public static final String TABLE_USERS = "users";
    public static final String COLUMN_ID = "id";
    public static final String COLUMN_USERNAME = "username";
    public static final String COLUMN_PASSWORD = "password";

    // 学生信息表
    public static final String TABLE_STUDENTS = "students";
    public static final String COLUMN_STUDENT_ID = "id";
    public static final String COLUMN_STUDENT_NAME = "name";
    public static final String COLUMN_STUDENT_ROLL_NUMBER = "roll_number";

    public static final String COLUMN_STUDENT_GENDER_TYPE = "gender_type";

    public static final String COLUMN_STUDENT_CONTACT_NUMBER = "contact_number";

    public static final String COLUMN_STUDENT_COURSE_ID = "course_id";

    public static final String COLUMN_STUDENT_DATE = "date";

    public static final String COLUMN_STUDENT_STATUS = "status";

    // 考勤记录表
    public static final String TABLE_ATTENDANCE = "attendance";
    public static final String COLUMN_ATTENDANCE_ID = "id";
    public static final String COLUMN_ATTENDANCE_STUDENT_ID = "student_id";
    public static final String COLUMN_ATTENDANCE_DATE = "date";
    public static final String COLUMN_ATTENDANCE_STATUS = "status";

    // 创建用户信息表的 SQL 语句
    private static final String TABLE_CREATE =
            "CREATE TABLE " + TABLE_USERS + " (" +
                    COLUMN_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
                    COLUMN_USERNAME + " TEXT, " +
                    COLUMN_PASSWORD + " TEXT);";

    // 创建学生信息表的 SQL 语句
    private static final String CREATE_TABLE_STUDENTS = "CREATE TABLE " +
            TABLE_STUDENTS + "(" +
            COLUMN_STUDENT_ID + " INTEGER PRIMARY KEY AUTOINCREMENT," +
            COLUMN_STUDENT_NAME + " TEXT," +
            COLUMN_STUDENT_ROLL_NUMBER + " TEXT," +
            COLUMN_STUDENT_GENDER_TYPE + " TEXT," +  // 添加这一行，包含缺失的列
            COLUMN_STUDENT_CONTACT_NUMBER + " TEXT" +
            ")";


    // 创建考勤记录表的 SQL 语句
    private static final String CREATE_TABLE_ATTENDANCE = "CREATE TABLE " +
            TABLE_ATTENDANCE + "(" +
            COLUMN_ATTENDANCE_ID + " INTEGER PRIMARY KEY AUTOINCREMENT, " +
            COLUMN_ATTENDANCE_STUDENT_ID + " INTEGER, " +
            COLUMN_ATTENDANCE_DATE + " INTEGER, " +  // 将日期数据类型更改为 INTEGER
            COLUMN_ATTENDANCE_STATUS + " INTEGER, " +  // 将字段更改为 COLUMN_ATTENDANCE_STATUS
            "FOREIGN KEY(" + COLUMN_ATTENDANCE_STUDENT_ID + ") REFERENCES " +
            TABLE_STUDENTS + "(" + COLUMN_STUDENT_ID + "))";

    public DatabaseHelper(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }

    @Override
    public void onCreate(SQLiteDatabase db) {
        // 创建用户信息表
        db.execSQL(TABLE_CREATE);

        // 创建学生信息表
        db.execSQL(CREATE_TABLE_STUDENTS);

        // 创建考勤记录表
        db.execSQL(CREATE_TABLE_ATTENDANCE);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        db.execSQL("DROP TABLE IF EXISTS " + TABLE_USERS);
        db.execSQL("DROP TABLE IF EXISTS " + TABLE_STUDENTS);
        db.execSQL("DROP TABLE IF EXISTS " + TABLE_ATTENDANCE);
        onCreate(db);
    }
}
