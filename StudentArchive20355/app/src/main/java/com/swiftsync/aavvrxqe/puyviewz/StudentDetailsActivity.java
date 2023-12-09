package com.swiftsync.aavvrxqe.puyviewz;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.RelativeLayout;
import android.widget.TextView;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

import androidx.appcompat.app.AppCompatActivity;

public class StudentDetailsActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_student_details);


        // 获取传递过来的学生信息
        ArrayList<Student> students = getIntent().getParcelableArrayListExtra("students");

        // 使用ListView作为父布局
        ListView listView = findViewById(R.id.listView);

        // 创建ArrayList用于存储学生信息
        ArrayList<String> studentInfoList = new ArrayList<>();

        // 在界面上显示学生信息
        if (students != null && !students.isEmpty()) {
            Collections.sort(students, new Comparator<Student>() {
                @Override
                public int compare(Student student1, Student student2) {
                    return student1.compareTo(student2);
                }
            });




            // 使用自定义适配器将学生信息绑定到ListView
            StudentAdapter adapter = new StudentAdapter(this, students);
            listView.setAdapter(adapter);
        }

        // 返回按钮点击监听器
        Button backButton = findViewById(R.id.backButton);
        backButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 点击返回按钮，关闭当前Activity
                finish();
            }
        });
    }
}