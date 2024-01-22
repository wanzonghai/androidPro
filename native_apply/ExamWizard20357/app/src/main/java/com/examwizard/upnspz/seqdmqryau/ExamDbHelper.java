package com.examwizard.upnspz.seqdmqryau;

import android.content.Context;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;

import java.io.File;

public class ExamDbHelper extends SQLiteOpenHelper {

    private static final String DATABASE_NAME = "exam.db";
    private static final int DATABASE_VERSION = 1;

    // Table and columns
    public static final String TABLE_EXAMS = "exams";
    public static final String COLUMN_ID = "_id";
    public static final String COLUMN_NAME = "name";
    public static final String COLUMN_DATE = "date";
    public static final String COLUMN_TIME = "time";

    private final File databaseFile;
    // Create table query
    private static final String DATABASE_CREATE = "create table "
            + TABLE_EXAMS + "(" + COLUMN_ID
            + " integer primary key autoincrement, " + COLUMN_NAME
            + " text not null, " + COLUMN_DATE
            + " text not null, " + COLUMN_TIME
            + " text not null);";

    public ExamDbHelper(Context context, File databaseFile) {
        super(context, databaseFile.getAbsolutePath(), null, DATABASE_VERSION);
        this.databaseFile = databaseFile;
    }

    @Override
    public void onCreate(SQLiteDatabase database) {
        database.execSQL(DATABASE_CREATE);
    }

    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        // Handle database upgrades if needed
    }
}
