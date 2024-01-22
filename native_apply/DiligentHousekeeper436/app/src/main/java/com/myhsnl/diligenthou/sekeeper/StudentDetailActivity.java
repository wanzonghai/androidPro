package com.myhsnl.diligenthou.sekeeper;

import android.content.Intent;

import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.myhsnl.diligenthou.daoR.AttendanceStatus;
import com.myhsnl.diligenthou.manager.StudentManager;
import com.myhsnl.diligenthou.model.Attendance;
import com.myhsnl.diligenthou.model.Student;

import java.util.Date;
import java.text.ParseException;
import java.text.SimpleDateFormat;

import androidx.appcompat.app.AppCompatActivity;

public class StudentDetailActivity extends AppCompatActivity {
    private  TextView textViewStudentName,textViewRollNumber,textViewGender,textViewContactNumber,textViewAttendance;

    private Button buttonEditProfile,buttonCheckIn;

    private Student student;  // 在类级别声明 student 变量
    private long courseId=123598;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_student_detail);

        // 获取传递过来的学生对象
        Intent intent = getIntent();
        if (intent != null && intent.hasExtra("student")) {
            student = (Student) intent.getSerializableExtra("student");

         // 在这里显示学生详细信息，可以使用TextView等组件
         textViewStudentName = findViewById(R.id.textViewStudentName);
         textViewRollNumber = findViewById(R.id.textViewRollNumber);
         textViewGender = findViewById(R.id.textViewGender);
         textViewContactNumber = findViewById(R.id.textViewContactNumber);
         textViewAttendance = findViewById(R.id.textViewAttendance);

         buttonEditProfile = findViewById(R.id.buttonEditProfile);

         buttonCheckIn = findViewById(R.id.buttonCheckIn);

        textViewStudentName.setText("Name: " + student.getName());
        textViewRollNumber.setText("Roll Number: " + student.getRollNumber());
        textViewGender.setText("Gender Type: " + student.getGenderType());
        textViewContactNumber.setText("Contact Number: " + student.getContactNumber());
        // 设置编辑个人信息按钮点击事件
        buttonEditProfile.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // 启动编辑个人信息的Activity
                Intent editIntent = new Intent(StudentDetailActivity.this, EditStudentActivity.class);
                editIntent.putExtra("student", student);
                startActivity(editIntent);
            }
        });

            // 设置签到按钮点击事件
            buttonCheckIn.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    // 处理签到逻辑...
                    try {
                        performCheckIn(student);
                    } catch (ParseException e) {
                        throw new RuntimeException(e);
                    }
                }
            });
            // 检查学生是否有考勤记录
            if (student.getAttendances() != null && !student.getAttendances().isEmpty()) {
                // 如果有考勤记录，将其显示在textViewAttendance中
                StringBuilder attendanceText = new StringBuilder("Attendance:\n");
                for (Attendance attendance : student.getAttendances()) {
                    attendanceText.append("- Date: ").append(attendance.getDate()).append(", Status: ").append(attendance.getStatus()).append("\n");
                }
                textViewAttendance.setText(attendanceText.toString());
            } else {
                // 如果没有考勤记录，显示提示信息
                textViewAttendance.setText("No attendance records available.");
            }

            // 加入以下代码，重新查询数据库以获取最新的学生数据
            new AsyncTask<Void, Void, Student>() {
                @Override
                protected Student doInBackground(Void... voids) {
                    StudentManager studentManager = new StudentManager(StudentDetailActivity.this);
                    return studentManager.getStudent(student.getId());
                }

                @Override
                protected void onPostExecute(Student updatedStudent) {
                    // 重新获取最新的学生对象后，更新显示的考勤信息
                    if (updatedStudent != null) {
                        loadUpdatedStudentData(updatedStudent);
                    }
                }
            }.execute();

            // 主动更新一次签到信息
            updateAttendanceInformation(student);
        }
    }
    // 在类中添加一个方法来处理签到逻辑
// 在类中添加一个方法来处理签到逻辑
// 在签到后更新显示的考勤信息
    private void performCheckIn(Student student) throws ParseException {
        // 检查学生在当前课程中是否已经签到过
        if (!hasCheckedInForCourse(student, courseId)) {
            // 使用当前日期
            Date date = new Date();

            // 获取学生的 ID
            long studentId = student.getId();

            // 假设创建一个 Attendance 对象，表示签到成功
            Attendance newAttendance = new Attendance(studentId, courseId, date, AttendanceStatus.PRESENT);
            // 将新的考勤记录添加到学生的考勤列表中
            student.addAttendance(newAttendance);
            // 更新显示的考勤信息
            updateAttendanceInformation(student);
        } else {
            // 提示学生已经签到过
            Toast.makeText(this, "You have already checked in for this course.", Toast.LENGTH_SHORT).show();
        }
    }

    // 检查学生在当前课程中是否已经签到过
    private boolean hasCheckedInForCourse(Student student, long courseId) {
        if (student.getAttendances() != null && !student.getAttendances().isEmpty()) {
            for (Attendance attendance : student.getAttendances()) {
                if (attendance.getCourseId() == courseId) {
                    // 学生在当前课程中已经签到过
                    return true;
                }
            }
        }
        // 学生在当前课程中没有签到过
        return false;
    }
    // 在签到后更新显示的考勤信息
    private void updateAttendanceInformation(Student student) {
        // 检查学生是否有考勤记录
        if (student.getAttendances() != null && !student.getAttendances().isEmpty()) {
            StudentManager studentManager = new StudentManager(StudentDetailActivity.this);
            // 如果有考勤记录，将其显示在textViewAttendance中
            StringBuilder attendanceText = new StringBuilder("Attendance:\n");
            for (Attendance attendance : student.getAttendances()) {
                attendanceText.append("- Date: ").append(attendance.getDate()).append(", Status: ").append(attendance.getStatus()).append("\n");
            }
            // 将学生对象保存到数据库
            saveStudentToDatabase(student, attendanceText.toString());

        } else {
            // 如果没有考勤记录，显示提示信息
            textViewAttendance.setText("No attendance records available.");
        }
    }
    // 保存学生对象到数据库
    private void saveStudentToDatabase(final Student student, final String attendanceTex) {
        // 使用异步任务保存学生到数据库
        new AsyncTask<Void, Void, Void>() {
            @Override
            protected Void doInBackground(Void... voids) {
                StudentManager studentManager = new StudentManager(StudentDetailActivity.this);
                studentManager.updateStudent(student);
                return null;
            }

            @Override
            protected void onPostExecute(Void aVoid) {
                // 保存成功后更新 UI
                updateUIWithAttendance(attendanceTex);
            }
        }.execute();
    }
    // 更新 UI
    private void updateUIWithAttendance(String attendanceText) {
        // 在主线程中更新 UI
        runOnUiThread(new Runnable() {
            @Override
            public void run() {

                textViewAttendance.setText(attendanceText);
            }
        });
    }
    // 重新获取最新的学生对象
    private void loadUpdatedStudentData(Student student) {
        // 在这里重新获取最新的学生对象，包含了数据库中最新的数据
        new AsyncTask<Void, Void, Student>() {
            @Override
            protected Student doInBackground(Void... voids) {
                StudentManager studentManager = new StudentManager(StudentDetailActivity.this);
                return studentManager.getStudent(student.getId());
            }

            @Override
            protected void onPostExecute(Student updatedStudent) {
                // 重新获取最新的学生对象后，更新显示的考勤信息
                if (updatedStudent != null) {
                    // 更新考勤信息
                    updateAttendanceInformation(updatedStudent);
                }
            }
        }.execute();
    }
}
