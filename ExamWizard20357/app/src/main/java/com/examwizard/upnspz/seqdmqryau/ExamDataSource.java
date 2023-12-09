package com.examwizard.upnspz.seqdmqryau;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;

import java.io.File;
import java.util.ArrayList;
import java.util.List;

public class ExamDataSource {

    private SQLiteDatabase database;
    private ExamDbHelper dbHelper;

    public ExamDataSource(Context context, File databaseFile) {
        dbHelper = new ExamDbHelper(context, databaseFile);

    }

    public void open() throws SQLException {
        try {
            database = dbHelper.getWritableDatabase();
        } catch (SQLException e) {
            e.printStackTrace();
            // 处理异常，例如关闭资源或者其他操作
        }
    }

    public void close() {
        dbHelper.close();
    }

    public long createExam(String name, String date, String time) {
        SQLiteDatabase database = dbHelper.getWritableDatabase();

        ContentValues values = new ContentValues();
        values.put(ExamDbHelper.COLUMN_NAME, name);
        values.put(ExamDbHelper.COLUMN_DATE, date);
        values.put(ExamDbHelper.COLUMN_TIME, time);

        long examId = database.insert(ExamDbHelper.TABLE_EXAMS, null, values);

        // 关闭数据库连接
        database.close();

        return examId;
    }

    public List<Exam> getAllExams() {
        List<Exam> exams = new ArrayList<>();
        SQLiteDatabase database = dbHelper.getReadableDatabase();
        Cursor cursor = database.query(ExamDbHelper.TABLE_EXAMS,
                null, null, null, null, null, null);

        try {
            if (cursor != null && cursor.moveToFirst()) {
                do {
                    Exam exam = cursorToExam(cursor);
                    exams.add(exam);
                } while (cursor.moveToNext());
            }
        } finally {
            // 确保在使用完 Cursor 后关闭
            if (cursor != null) {
                cursor.close();
            }
            // 关闭数据库连接
            database.close();
        }

        return exams;
    }

    private Exam cursorToExam(Cursor cursor) {
        Exam exam = new Exam();
        int idIndex = cursor.getColumnIndex(ExamDbHelper.COLUMN_ID);
        int nameIndex = cursor.getColumnIndex(ExamDbHelper.COLUMN_NAME);
        int dateIndex = cursor.getColumnIndex(ExamDbHelper.COLUMN_DATE);
        int timeIndex = cursor.getColumnIndex(ExamDbHelper.COLUMN_TIME);
        if (idIndex != -1) {
            exam.setId(cursor.getLong(idIndex));
        }

        if (nameIndex != -1) {
            exam.setName(cursor.getString(nameIndex));
        }

        if (dateIndex != -1) {
            exam.setDate(cursor.getString(dateIndex));
        }

        if (timeIndex != -1) {
            exam.setTime(cursor.getString(timeIndex));
        }
        return exam;
    }

    public Exam getExamById(long examId) {
        SQLiteDatabase database = dbHelper.getReadableDatabase();

        String[] projection = {
                ExamDbHelper.COLUMN_ID,
                ExamDbHelper.COLUMN_NAME,
                ExamDbHelper.COLUMN_DATE,
                ExamDbHelper.COLUMN_TIME
        };

        String selection = ExamDbHelper.COLUMN_ID + " = ?";
        String[] selectionArgs = { String.valueOf(examId) };

        Cursor cursor = database.query(
                ExamDbHelper.TABLE_EXAMS,
                projection,
                selection,
                selectionArgs,
                null,
                null,
                null
        );

        Exam exam = null;
        if (cursor != null && cursor.moveToFirst()) {
            // 构造 Exam 对象
            exam = new Exam();
            int COLUMN_IDIndex = cursor.getColumnIndex(ExamDbHelper.COLUMN_ID);
            int COLUMN_NAMEIndex = cursor.getColumnIndex(ExamDbHelper.COLUMN_NAME);
            int COLUMN_DATEIndex = cursor.getColumnIndex(ExamDbHelper.COLUMN_DATE);
            int COLUMN_TIMEIndex = cursor.getColumnIndex(ExamDbHelper.COLUMN_TIME);

            exam.setId(cursor.getLong(COLUMN_IDIndex));
            exam.setName(cursor.getString(COLUMN_NAMEIndex));
            exam.setDate(cursor.getString(COLUMN_DATEIndex));
            exam.setTime(cursor.getString(COLUMN_TIMEIndex));

            cursor.close();
        }

        // 关闭数据库连接
        database.close();

        return exam;
    }
    public int updateExam(long examId, String updatedName, String updatedDate, String updatedTime) {
        SQLiteDatabase database = dbHelper.getWritableDatabase();

        ContentValues values = new ContentValues();
        values.put(ExamDbHelper.COLUMN_NAME, updatedName);
        values.put(ExamDbHelper.COLUMN_DATE, updatedDate);
        values.put(ExamDbHelper.COLUMN_TIME, updatedTime);

        String selection = ExamDbHelper.COLUMN_ID + " = ?";
        String[] selectionArgs = { String.valueOf(examId) };

        // 执行更新操作
        int rowsUpdated = database.update(
                ExamDbHelper.TABLE_EXAMS,
                values,
                selection,
                selectionArgs
        );

        // 关闭数据库连接
        database.close();

        return rowsUpdated;
    }

}
