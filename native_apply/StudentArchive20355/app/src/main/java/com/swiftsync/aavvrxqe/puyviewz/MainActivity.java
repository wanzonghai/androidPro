package com.swiftsync.aavvrxqe.puyviewz;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.util.ArrayList;
import java.util.Map;


public class MainActivity extends AppCompatActivity  {

    private MyDBHelper myDBHelper; // 声明数据库帮助类
    private EditText etStudentid, etStudentname, etMajoy, etStudentclass;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        myDBHelper = new MyDBHelper(this); // 初始化数据库帮助类

        etStudentid = findViewById(R.id.etStudentid);
        etStudentname = findViewById(R.id.etStudentname);
        etMajoy = findViewById(R.id.etMajoy);
        etStudentclass = findViewById(R.id.etStudentclass);

        Button addStudentButton = findViewById(R.id.addStudentButton);
        Button deleteStudentButton = findViewById(R.id.deleteStudentButton);
        Button updateStudentButton = findViewById(R.id.updateStudentButton);
        Button viewAllStudentsButton = findViewById(R.id.viewAllStudentsButton);
        Button backButton= findViewById(R.id.backButton);
        // 添加学生按钮点击监听器
        addStudentButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 在这里执行添加学生的操作
                // 你可能需要打开一个新的Activity或者弹出一个对话框来输入学生信息
                // 在这里执行添加学生的操作
                String studentid = etStudentid.getText().toString().trim();
                String studentname = etStudentname.getText().toString().trim();
                String majoy = etMajoy.getText().toString().trim();
                String studentclass = etStudentclass.getText().toString();

                // 检验信息是否正确
                if (TextUtils.isEmpty(studentid) || TextUtils.isEmpty(studentname) ||
                        TextUtils.isEmpty(majoy) || TextUtils.isEmpty(studentclass)) {
                    Toast.makeText(MainActivity.this, "Please fill in the complete information", Toast.LENGTH_SHORT).show();
                    return;
                }

                // 添加学生信息
                Student student = new Student();
                student.studentid = studentid;
                student.studentname = studentname;
                student.majoy = majoy;
                student.studentclass = studentclass;

                // 执行数据库帮助类中的添加学生方法
                long result = myDBHelper.addStudent(student);

                if (result > 0) {
                    Toast.makeText(MainActivity.this, "successfully added", Toast.LENGTH_SHORT).show();
                } else {
                    Toast.makeText(MainActivity.this, "addition failed", Toast.LENGTH_SHORT).show();
                }

                ClearInputField();
            }
        });

        // 删除学生按钮点击监听器
        deleteStudentButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 在这里执行删除学生的操作
                // 你可能需要打开一个新的Activity或者弹出一个对话框来输入要删除的学生信息
                String studentIdToDelete = etStudentid.getText().toString().trim();

                if (!TextUtils.isEmpty(studentIdToDelete)) {
                    // 执行数据库帮助类中的删除学生方法
                    int rowsAffected = myDBHelper.deleteStudent(studentIdToDelete);

                    if (rowsAffected > 0) {
                        Toast.makeText(MainActivity.this, "successfully delete", Toast.LENGTH_SHORT).show();
                    } else {
                        Toast.makeText(MainActivity.this, "Failed to delete because the student ID does not exist", Toast.LENGTH_SHORT).show();
                    }
                } else {
                    Toast.makeText(MainActivity.this, "Please enter the student ID you want to delete", Toast.LENGTH_SHORT).show();
                }
                ClearInputField();
            }
        });

        // 更新学生按钮点击监听器
        updateStudentButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 在这里执行更新学生的操作
                // 你可能需要打开一个新的Activity或者弹出一个对话框来输入要更新的学生信息
                String studentIdToUpdate = etStudentid.getText().toString().trim();
                String updatedStudentName = etStudentname.getText().toString().trim();
                String updatedMajor = etMajoy.getText().toString().trim();
                String updatedStudentClass = etStudentclass.getText().toString().trim();

                if (!TextUtils.isEmpty(studentIdToUpdate)) {
                    // 执行数据库帮助类中的更新学生方法
                    Student updatedStudent = new Student();
                    updatedStudent.studentid = studentIdToUpdate;
                    updatedStudent.studentname = updatedStudentName;
                    updatedStudent.majoy = updatedMajor;
                    updatedStudent.studentclass = updatedStudentClass;

                    int rowsAffected = myDBHelper.updateStudents(updatedStudent);

                    if (rowsAffected > 0) {
                        Toast.makeText(MainActivity.this, "update successfully\n", Toast.LENGTH_SHORT).show();
                    } else {
                        Toast.makeText(MainActivity.this, "Update failed, student ID does not exist", Toast.LENGTH_SHORT).show();
                    }
                } else {
                    Toast.makeText(MainActivity.this, "Please enter the student ID you want to update", Toast.LENGTH_SHORT).show();
                }
                ClearInputField();
            }
        });

        // 查看所有学生按钮点击监听器
        viewAllStudentsButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 在这里执行查看所有学生的操作
                // 你可能需要打开一个新的Activity或者弹出一个对话框来显示所有学生的信息
                ArrayList<Map<String, Object>> allStudents = myDBHelper.getAllstudents();

                if (allStudents != null && !allStudents.isEmpty()) {
                    // 处理查看所有学生的操作，例如显示在一个新的Activity或对话框中
                    ArrayList<Student> studentList = new ArrayList<>();
                    // 这里只是简单地打印所有学生信息
                    // 传递所有学生信息到新的 Activity
                    for (Map<String, Object> studentMap : allStudents) {
                        // 传递学生信息到新的 Activity
                        Student student = new Student();
                        student.studentid = studentMap.get("studentid").toString();
                        student.studentname = studentMap.get("studentname").toString();
                        student.majoy = studentMap.get("majoy").toString();
                        student.studentclass = studentMap.get("studentclass").toString();
                        studentList.add(student);
//                        String studentInfo = "student ID: " + student.get("studentid") +
//                                ", name: " + student.get("studentname") +
//                                ", major: " + student.get("majoy") +
//                                ", class: " + student.get("studentclass");
//                        Toast.makeText(MainActivity.this, studentInfo, Toast.LENGTH_SHORT).show();
                    }
                    // 添加学生到 studentList 中

                    Intent intent = new Intent(MainActivity.this, StudentDetailsActivity.class);
                    intent.putParcelableArrayListExtra("students", studentList);
                    startActivity(intent);

                } else {
                    Toast.makeText(MainActivity.this, "No student information", Toast.LENGTH_SHORT).show();
                }
                ClearInputField();
            }
        });
        // 查询单个学生按钮点击监听器
        Button queryStudentButton = findViewById(R.id.queryStudentButton);
        queryStudentButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 在这里执行查询单个学生的操作
                // 获取学生ID
                String studentId = etStudentid.getText().toString().trim();

                if (!TextUtils.isEmpty(studentId)) {
                    // 执行查询学生的操作
                    Student student = myDBHelper.getStudents(studentId);

                    if (student != null) {
                        // 显示查询结果，你可以根据需要选择显示在TextView、AlertDialog等组件上
                        Intent intent = new Intent(MainActivity.this, StudentDetailsActivity.class);
                        intent.putExtra("student", student); // 直接传递单个学生对象
                        startActivity(intent);
                    } else {
                        Toast.makeText(MainActivity.this, "The student could not be found", Toast.LENGTH_SHORT).show();
                    }
                } else {
                    Toast.makeText(MainActivity.this, "Please enter your student number", Toast.LENGTH_SHORT).show();
                }
                ClearInputField();
            }
        });
        backButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(MainActivity.this, LoginActivity.class));
                finish(); // 关闭当前登录界面
            }
        });
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        myDBHelper.close(); // 在活动销毁时关闭数据库连接
    }

    private void ClearInputField(){
        // 清空输入框
        etStudentid.setText("");
        etStudentname.setText("");
        etMajoy.setText("");
        etStudentclass.setText("");
    }

}