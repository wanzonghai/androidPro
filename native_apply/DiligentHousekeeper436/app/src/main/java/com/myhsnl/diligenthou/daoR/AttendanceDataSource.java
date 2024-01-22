package com.myhsnl.diligenthou.daoR;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.SQLException;
import android.database.sqlite.SQLiteDatabase;

import com.myhsnl.diligenthou.helper.AttendanceDatabaseHelper;
import com.myhsnl.diligenthou.model.Attendance;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class AttendanceDataSource {
    private SQLiteDatabase database;
    private AttendanceDatabaseHelper dbHelper;

    // 添加这些字段的定义
    public static final String COLUMN_ATTENDANCE_ID = "id";
    public static final String COLUMN_ATTENDANCE_STUDENT_ID = "student_id";
    public static final String COLUMN_ATTENDANCE_COURSE_ID = "course_id";
    public static final String COLUMN_ATTENDANCE_DATE = "date";
    public static final String COLUMN_ATTENDANCE_STATUS = "status";
    // 添加这个字段的定义
    public static final String TABLE_ATTENDANCE = "attendance";

    public AttendanceDataSource(Context context) {
        dbHelper = new AttendanceDatabaseHelper(context);
    }

    public void open() throws SQLException {
        database = dbHelper.getWritableDatabase();
    }

    public void close() {
        dbHelper.close();
    }

    public long addAttendance(Attendance attendance) {
        ContentValues values = new ContentValues();
        values.put(COLUMN_ATTENDANCE_STUDENT_ID, attendance.getStudentId());
        values.put(COLUMN_ATTENDANCE_COURSE_ID, attendance.getCourseId());
        values.put(COLUMN_ATTENDANCE_DATE, attendance.getDate().getTime());
        values.put(COLUMN_ATTENDANCE_STATUS, attendance.getStatus().ordinal());

        return database.insert(TABLE_ATTENDANCE, null, values);
    }

    public List<Attendance> getAttendancesForCourse(long courseId) {
        List<Attendance> attendances = new ArrayList<>();
        String selection = COLUMN_ATTENDANCE_COURSE_ID + "=?";
        String[] selectionArgs = {String.valueOf(courseId)};
        Cursor cursor = database.query(TABLE_ATTENDANCE, null, selection, selectionArgs, null, null, null);

        if (cursor != null && cursor.moveToFirst()) {
            do {
                Attendance attendance = new Attendance();
                int idIndex=cursor.getColumnIndex(COLUMN_ATTENDANCE_ID);
                int studentIdIndex=cursor.getColumnIndex(COLUMN_ATTENDANCE_STUDENT_ID);
                int courseIdIndex=cursor.getColumnIndex(COLUMN_ATTENDANCE_COURSE_ID);
                int dateIndex=cursor.getColumnIndex(COLUMN_ATTENDANCE_DATE);
                int statusOrdinalIndex=cursor.getColumnIndex(COLUMN_ATTENDANCE_STATUS);
                attendance.setId(cursor.getLong(idIndex));
                attendance.setStudentId(cursor.getLong(studentIdIndex));
                attendance.setCourseId(cursor.getLong(courseIdIndex));
                attendance.setDate(new Date(cursor.getLong(dateIndex)));
                int statusOrdinal = cursor.getInt(statusOrdinalIndex);
                attendance.setStatus(AttendanceStatus.values()[statusOrdinal]);
                attendances.add(attendance);
            } while (cursor.moveToNext());
        }

        if (cursor != null) {
            cursor.close();
        }

        return attendances;
    }

    public List<Attendance> getAttendancesForStudent(long studentId) {
        List<Attendance> attendances = new ArrayList<>();
        String selection = COLUMN_ATTENDANCE_STUDENT_ID + "=?";
        String[] selectionArgs = {String.valueOf(studentId)};
        Cursor cursor = database.query(TABLE_ATTENDANCE, null, selection, selectionArgs, null, null, null);

        if (cursor != null && cursor.moveToFirst()) {
            do {
                Attendance attendance = new Attendance();
                int idIndex = cursor.getColumnIndex(COLUMN_ATTENDANCE_ID);
                int courseIdIndex = cursor.getColumnIndex(COLUMN_ATTENDANCE_COURSE_ID);
                int dateIndex = cursor.getColumnIndex(COLUMN_ATTENDANCE_DATE);
                int statusOrdinalIndex = cursor.getColumnIndex(COLUMN_ATTENDANCE_STATUS);
                attendance.setId(cursor.getLong(idIndex));
                attendance.setCourseId(cursor.getLong(courseIdIndex));
                attendance.setDate(new Date(cursor.getLong(dateIndex)));
                int statusOrdinal = cursor.getInt(statusOrdinalIndex);
                attendance.setStatus(AttendanceStatus.values()[statusOrdinal]);
                attendances.add(attendance);
            } while (cursor.moveToNext());
        }

        if (cursor != null) {
            cursor.close();
        }

        return attendances;
    }
}
