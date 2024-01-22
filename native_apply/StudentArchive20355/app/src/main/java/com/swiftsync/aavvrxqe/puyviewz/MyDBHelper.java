package com.swiftsync.aavvrxqe.puyviewz;

import android.content.ContentValues;
import android.content.Context;
import android.database.Cursor;
import android.database.sqlite.SQLiteDatabase;
import android.database.sqlite.SQLiteOpenHelper;
import android.text.TextUtils;
import android.util.Log;
import android.view.View;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class MyDBHelper extends SQLiteOpenHelper {
    //定义数据库名称和版本号
    private static final String DATABASE_NAME = "students";
    public static final int DATABASE_VERSION  = 1;
    private static final String TABLE_STUDENTS = "students";
    private static final String COLUMN_STUDENT_ID = "studentid";
    private static final String COLUMN_STUDENT_NAME = "studentname";
    private static final String COLUMN_MAJOR = "majoy";
    private static final String COLUMN_STUDENT_CLASS = "studentclass";
    // 创建表的 SQL 语句
    private static final String CREATE_TABLE_STUDENTS =
            "CREATE TABLE " + TABLE_STUDENTS + " (" +
                    COLUMN_STUDENT_ID + " TEXT PRIMARY KEY," +
                    COLUMN_STUDENT_NAME + " TEXT," +
                    COLUMN_MAJOR + " TEXT," +
                    COLUMN_STUDENT_CLASS + " TEXT)";
    //创建数据表的语句
//    public static final String CREATE_USERDATA = "create table students(studentid char(20)primary key,studentname varchar(20),majoy varchar(20),studentclass varchar(20))";
    //构造函数

    public MyDBHelper(Context context) {
        super(context, DATABASE_NAME, null, DATABASE_VERSION);
    }
    @Override
    public void onCreate(SQLiteDatabase db) {
        db.execSQL(CREATE_TABLE_STUDENTS);
    }
    @Override
    public void onUpgrade(SQLiteDatabase db, int oldVersion, int newVersion) {
        // 数据库版本升级时执行此方法，通常用于删除表或进行其他升级操作
        db.execSQL("DROP TABLE IF EXISTS " + TABLE_STUDENTS);
        onCreate(db);
    }


    // 添加学生信息
    public long addStudent(Student student) {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues values = new ContentValues();
        values.put("studentid", student.studentid);
        values.put("studentname", student.studentname);
        values.put("majoy", student.majoy);
        values.put("studentclass", student.studentclass);
        long result = db.insert("students", null, values);
        db.close();  // 关闭数据库连接
        return result;
    }

    //删除指定学生信息
    public int deleteStudent(String studentId) {
        SQLiteDatabase db = this.getWritableDatabase();
        return db.delete("students", "studentid=?", new String[]{studentId});
    }


    //修改指定学生信息
    public int updateStudents(Student o) {
        SQLiteDatabase db = this.getWritableDatabase();
        ContentValues value = new ContentValues();
        value.put("studentname", o.studentname);
        value.put("majoy", o.majoy);
        value.put("studentclass", o.studentclass);
        return db.update("students", value, "studentid=?", new String[]{String.valueOf(o.studentid)});
    }

    public Student getStudents(String studentid) {
        SQLiteDatabase db = this.getReadableDatabase();

        String[] columns = {"studentid", "studentname", "majoy", "studentclass"};
        String selection = "studentid=?";
        String[] selectionArgs = {studentid};

        // 查询学生
        Cursor cursor = db.query("students", columns, selection, selectionArgs, null, null, null);

        Student student = null; // 初始化一个学生对象

        if (cursor != null && cursor.moveToFirst()) {
            student = new Student(); // 如果查询到结果，再初始化学生对象
            // 检查列的索引是否为有效值
            int studentIdIndex = cursor.getColumnIndex("studentid");
            int studentNameIndex = cursor.getColumnIndex("studentname");
            int majoyIndex = cursor.getColumnIndex("majoy");
            int studentClassIndex = cursor.getColumnIndex("studentclass");

            if (studentIdIndex >= 0) {
                student.studentid = cursor.getString(studentIdIndex);
            }
            if (studentNameIndex >= 0) {
                student.studentname = cursor.getString(studentNameIndex);
            }
            if (majoyIndex >= 0) {
                student.majoy = cursor.getString(majoyIndex);
            }
            if (studentClassIndex >= 0) {
                student.studentclass = cursor.getString(studentClassIndex);
            }
            cursor.close();
        }

        return student;
    }

    //查看所有学生信息
    public ArrayList<Map<String, Object>> getAllstudents() {
        SQLiteDatabase db = this.getWritableDatabase();
        ArrayList<Map<String, Object>> listStudents = new ArrayList<Map<String, Object>>();
        Cursor cursor = db.query("students", null, null, null, null, null, null);

        int resultCounts = cursor.getCount();  //记录数
        Log.d("MyDBHelper", "Number of students in the database: " + resultCounts);
        if (resultCounts == 0) {
            return null;
        } else {
            while (cursor.moveToNext()) {
                Map<String, Object> map = new HashMap<String, Object>();
                // 检查列的索引是否为有效值
                int studentIdIndex = cursor.getColumnIndex("studentid");
                int studentNameIndex = cursor.getColumnIndex("studentname");
                int majoyIndex = cursor.getColumnIndex("majoy");
                int studentClassIndex = cursor.getColumnIndex("studentclass");
                Log.d("MyDBHelper", "Fetching student data from the database...");
                if (studentIdIndex >= 0) {
                    map.put("studentid", cursor.getString(studentIdIndex));
                }
                if (studentNameIndex >= 0) {
                    map.put("studentname", cursor.getString(studentNameIndex));
                }
                if (majoyIndex >= 0) {
                    map.put("majoy", cursor.getString(majoyIndex));
                }
                if (studentClassIndex >= 0) {
                    map.put("studentclass", cursor.getString(studentClassIndex));
                }
                // 将新的映射对象添加到列表
                listStudents.add(map);
            }
            cursor.close();
            return listStudents;
        }
    }


}