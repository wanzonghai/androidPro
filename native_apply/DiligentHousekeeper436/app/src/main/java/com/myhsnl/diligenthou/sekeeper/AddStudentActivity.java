package com.myhsnl.diligenthou.sekeeper;

import android.os.Bundle;
import android.text.TextUtils;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

import com.myhsnl.diligenthou.manager.StudentManager;
import com.myhsnl.diligenthou.model.Student;

import androidx.appcompat.app.AppCompatActivity;

// AddStudentActivity.java
// AddStudentActivity.java
public class AddStudentActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_student);

        final EditText editTextStudentName = findViewById(R.id.editTextStudentName);
        final EditText editTextRollNumber = findViewById(R.id.editTextRollNumber);
        // 获取 Spinner 实例
        final  Spinner spinnerStudentGenderType = findViewById(R.id.spinnerStudentGenderType);


        // 为 Spinner 设置适配器
        ArrayAdapter<CharSequence> adapter = ArrayAdapter.createFromResource(
                this,
                R.array.gender_types,  // 在 res/values/strings.xml 文件中添加一个字符串数组，包含 "Male" 和 "Female"
                android.R.layout.simple_spinner_item
        );
        adapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinnerStudentGenderType.setAdapter(adapter);

        final EditText editTextcontactNumber = findViewById(R.id.editTextContactNumber);
        Button buttonSaveStudent = findViewById(R.id.buttonSaveStudent);

        buttonSaveStudent.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                String studentName = editTextStudentName.getText().toString().trim();
                String rollNumber = editTextRollNumber.getText().toString().trim();
                String studentGenderType = spinnerStudentGenderType.getSelectedItem().toString().trim();
                String contactNumber = editTextcontactNumber.getText().toString().trim();

                if (!TextUtils.isEmpty(studentName) && !TextUtils.isEmpty(rollNumber)) {
                    // Save the student to the database using StudentManager
                    StudentManager studentManager = new StudentManager(AddStudentActivity.this);
                    Student newStudent = new Student(studentName, rollNumber,studentGenderType,contactNumber);
                    long studentId = studentManager.addStudent(newStudent);
                    if (studentId != -1) {
                        Toast.makeText(AddStudentActivity.this, "Student added successfully", Toast.LENGTH_SHORT).show();
                        setResult(RESULT_OK);// In AddStudentActivity after adding a new student
                        finish(); // Close the activity after saving
                    } else {
                        Toast.makeText(AddStudentActivity.this, "Failed to add student", Toast.LENGTH_SHORT).show();
                    }
                } else {
                    Toast.makeText(AddStudentActivity.this, "Please enter student name and roll number", Toast.LENGTH_SHORT).show();
                }
            }
        });
    }
}
