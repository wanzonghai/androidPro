package com.myhsnl.diligenthou.manager;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.util.Log;

import com.myhsnl.diligenthou.daoR.AttendanceStatus;
import com.myhsnl.diligenthou.helper.DatabaseHelper;
import com.myhsnl.diligenthou.model.Attendance;
import com.myhsnl.diligenthou.model.Student;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class StudentManager {

    private DatabaseHelper dbHelper;

    public StudentManager(Context context) {
        dbHelper = new DatabaseHelper(context);
    }

    public List<Student> getAllStudents() {
        List<Student> studentList = new ArrayList<>();
        SQLiteDatabase db = dbHelper.getReadableDatabase();

        Cursor cursor = db.query(DatabaseHelper.TABLE_STUDENTS, null,
                null, null, null, null, null);

        if (cursor != null && cursor.moveToFirst()) {
            do {
                Student student = new Student();
                int idIndex = cursor.getColumnIndex(DatabaseHelper.COLUMN_STUDENT_ID);
                int naIndex = cursor.getColumnIndex(DatabaseHelper.COLUMN_STUDENT_NAME);
                int rollNumberIndex = cursor.getColumnIndex(DatabaseHelper.COLUMN_STUDENT_ROLL_NUMBER);
                student.setId(cursor.getLong(idIndex));
                student.setName(cursor.getString(naIndex));
                student.setRollNumber(cursor.getString(rollNumberIndex));
                studentList.add(student);
            } while (cursor.moveToNext());
        }

        if (cursor != null) {
            cursor.close();
        }

        db.close();

        return studentList;
    }


    public long addStudent(Student student) {
        SQLiteDatabase db = dbHelper.getWritableDatabase();

        ContentValues values = new ContentValues();
        values.put(DatabaseHelper.COLUMN_STUDENT_NAME, student.getName());
        values.put(DatabaseHelper.COLUMN_STUDENT_ROLL_NUMBER, student.getRollNumber());

        long studentId = db.insert(DatabaseHelper.TABLE_STUDENTS, null, values);
        db.close();

        return studentId;
    }

    public void deleteStudent(long studentId) {
        SQLiteDatabase db = dbHelper.getWritableDatabase();
        db.delete(DatabaseHelper.TABLE_STUDENTS, DatabaseHelper.COLUMN_STUDENT_ID + " = ?",
                new String[]{String.valueOf(studentId)});
        db.close();
    }

    public void updateStudent(Student student) {
        SQLiteDatabase db = dbHelper.getWritableDatabase();

        ContentValues values = new ContentValues();
        values.put(DatabaseHelper.COLUMN_STUDENT_NAME, student.getName());
        values.put(DatabaseHelper.COLUMN_STUDENT_ROLL_NUMBER, student.getRollNumber());

        db.update(DatabaseHelper.TABLE_STUDENTS, values, DatabaseHelper.COLUMN_STUDENT_ID + " = ?",
                new String[]{String.valueOf(student.getId())});

        // 更新学生考勤信息
        updateAttendanceData(db, student);
        db.close();
    }

    public Student getStudent(long studentId) {
        SQLiteDatabase db = dbHelper.getReadableDatabase();

        Cursor cursor = db.query(DatabaseHelper.TABLE_STUDENTS, null,
                DatabaseHelper.COLUMN_STUDENT_ID + " = ?",
                new String[]{String.valueOf(studentId)}, null, null, null);

        Student student = null;

        if (cursor != null && cursor.moveToFirst()) {
            student = new Student();
            int idIndex=cursor.getColumnIndex(DatabaseHelper.COLUMN_STUDENT_ID);
            int naIndex=cursor.getColumnIndex(DatabaseHelper.COLUMN_STUDENT_NAME);
            int rollNumberIndex=cursor.getColumnIndex(DatabaseHelper.COLUMN_STUDENT_ROLL_NUMBER);
            student.setId(cursor.getLong(idIndex));
            student.setName(cursor.getString(naIndex));
            student.setRollNumber(cursor.getString(rollNumberIndex));
            // 加载考勤记录
            loadAttendancesForStudent(db, student);
        }

        if (cursor != null) {
            cursor.close();
        }

        db.close();

        return student;
    }


    public List<Student> getAllStudentsSortedByRollNumber() {
        SQLiteDatabase db = dbHelper.getReadableDatabase();
        List<Student> students = new ArrayList<>();

        String[] projection = {
                DatabaseHelper.COLUMN_STUDENT_ID,
                DatabaseHelper.COLUMN_STUDENT_NAME,
                DatabaseHelper.COLUMN_STUDENT_ROLL_NUMBER,
                DatabaseHelper.COLUMN_STUDENT_GENDER_TYPE,
                DatabaseHelper.COLUMN_STUDENT_CONTACT_NUMBER
        };

        Cursor cursor = db.query(
                DatabaseHelper.TABLE_STUDENTS,
                projection,
                null,
                null,
                null,
                null,
                DatabaseHelper.COLUMN_STUDENT_ROLL_NUMBER
        );

        if (cursor != null) {
            if (cursor.moveToFirst()) {
                do {
                    Student student = new Student();
                    int idIndex = cursor.getColumnIndex(DatabaseHelper.COLUMN_STUDENT_ID);
                    int nameIndex = cursor.getColumnIndex(DatabaseHelper.COLUMN_STUDENT_NAME);
                    int rollNumberIndex = cursor.getColumnIndex(DatabaseHelper.COLUMN_STUDENT_ROLL_NUMBER);
                    int genderTypeIndex = cursor.getColumnIndex(DatabaseHelper.COLUMN_STUDENT_GENDER_TYPE);
                    int contactIndex = cursor.getColumnIndex(DatabaseHelper.COLUMN_STUDENT_CONTACT_NUMBER);
                    student.setId(cursor.getLong(idIndex));
                    student.setName(cursor.getString(nameIndex));
                    student.setRollNumber(cursor.getString(rollNumberIndex));
                    student.setGenderType(cursor.getString(genderTypeIndex));
                    student.setContactNumber(cursor.getString(contactIndex));
                    students.add(student);
                } while (cursor.moveToNext());
            }
            cursor.close();
        }

        return students;
    }

    // 关闭数据库连接
    public void closeDatabase() {
        dbHelper.close();
    }

    private void updateAttendanceData(SQLiteDatabase db, Student student) {
        Log.d("updateAttendanceData", "updateAttendanceData: "+student);
        // 删除该学生之前的所有考勤记录
        db.delete(DatabaseHelper.TABLE_ATTENDANCE, DatabaseHelper.COLUMN_STUDENT_ID + " = ?",
                new String[]{String.valueOf(student.getId())});

        // 插入新的考勤记录
        for (Attendance attendance : student.getAttendances()) {
            ContentValues attendanceValues = new ContentValues();
            attendanceValues.put(DatabaseHelper.COLUMN_ATTENDANCE_STUDENT_ID, student.getId());
            attendanceValues.put(DatabaseHelper.COLUMN_ATTENDANCE_DATE, attendance.getDate().getTime());
            attendanceValues.put(DatabaseHelper.COLUMN_ATTENDANCE_STATUS, attendance.getStatus().toString());

            db.insert(DatabaseHelper.TABLE_ATTENDANCE, null, attendanceValues);
        }
    }
    private void loadAttendancesForStudent(SQLiteDatabase db, Student student) {
        Cursor cursor = db.query(DatabaseHelper.TABLE_ATTENDANCE, null,
                DatabaseHelper.COLUMN_ATTENDANCE_STUDENT_ID + " = ?",
                new String[]{String.valueOf(student.getId())}, null, null, null);

        if (cursor != null && cursor.moveToFirst()) {
            List<Attendance> attendances = new ArrayList<>();
            do {
                Attendance attendance = new Attendance();
                // 从 cursor 中提取考勤记录信息并设置到 Attendance 对象中
                int idIndex=cursor.getColumnIndex(DatabaseHelper.COLUMN_ATTENDANCE_ID);
                int dateIndex=cursor.getColumnIndex(DatabaseHelper.COLUMN_ATTENDANCE_DATE);
                int statusIndex=cursor.getColumnIndex(DatabaseHelper.COLUMN_ATTENDANCE_STATUS);
                attendance.setId(cursor.getLong(idIndex));
                  attendance.setDate(new Date(cursor.getLong(dateIndex)));
                  attendance.setStatus(AttendanceStatus.valueOf(cursor.getString(statusIndex)));
                attendances.add(attendance);
            } while (cursor.moveToNext());

            student.setAttendances(attendances);
        }

        if (cursor != null) {
            cursor.close();
        }
    }
}
