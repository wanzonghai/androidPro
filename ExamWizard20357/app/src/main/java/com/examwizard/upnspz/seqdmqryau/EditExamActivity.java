package com.examwizard.upnspz.seqdmqryau;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Toast;

import java.io.File;

import androidx.appcompat.app.AppCompatActivity;

public class EditExamActivity extends AppCompatActivity {

    private long examId;
    private EditText editTextExamName;
    private EditText editTextExamDate;
    private EditText editTextExamTime;

    private ExamDataSource dataSource;

    private FileHelper fileHelper; // 添加 FileHelper 成员变量
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit_exam);

        // Get the exam ID from the intent
        Intent intent = getIntent();
        examId = intent.getLongExtra("EXAM_ID", -1);

        // Initialize UI elements
        editTextExamName = findViewById(R.id.editTextExamName);
        editTextExamDate = findViewById(R.id.editTextExamDate);
        editTextExamTime = findViewById(R.id.editTextExamTime);
        Button btnSaveExam = findViewById(R.id.btnSaveExam);

        // 创建 FileHelper 对象
        fileHelper = new FileHelper(this);
        // 获取当前用户的数据库文件
        File userDatabaseFile = fileHelper.getUserDatabaseFile();
        dataSource = new ExamDataSource(this,userDatabaseFile);
        dataSource.open();
        // Load exam details and populate the UI
        loadExamDetails();

        // Set up the save button click listener
        btnSaveExam.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                saveExam();
            }
        });
    }

    private void loadExamDetails() {
        // Load exam details based on the examId and populate the UI
        // You need to implement this method based on your data retrieval logic
        Exam exam = dataSource.getExamById(examId);
        if (exam != null) {
            editTextExamName.setText(exam.getName());
            editTextExamDate.setText(exam.getDate());
            editTextExamTime.setText(exam.getTime());
        }
    }

    private void saveExam() {
        // 获取更新后的考试信息
        String updatedName = editTextExamName.getText().toString().trim();
        String updatedDate = editTextExamDate.getText().toString().trim();
        String updatedTime = editTextExamTime.getText().toString().trim();
        // 检查输入是否有效
        if (updatedName.isEmpty() || updatedDate.isEmpty() || updatedTime.isEmpty()) {
            Toast.makeText(this, "Please fill in all fields", Toast.LENGTH_SHORT).show();
            return;
        }
        // 更新考试信息
        int rowsUpdated = dataSource.updateExam(examId, updatedName, updatedDate, updatedTime);

        if (rowsUpdated > 0) {
            // 更新成功
            // 在这里调用主界面的更新方法
            // 更新成功，设置结果码和包含考试信息的 Intent
            Intent resultIntent = new Intent();
            resultIntent.putExtra("UPDATED_EXAM_NAME", updatedName);
            resultIntent.putExtra("UPDATED_EXAM_DATE", updatedDate);
            resultIntent.putExtra("UPDATED_EXAM_TIME", updatedTime);
            setResult(RESULT_OK, resultIntent);
            updateMainActivity();
            // 可以关闭当前 Activity 或者执行其他操作
            finish();
        } else {
            // 更新失败，可以进行适当的处理，比如显示错误信息
            Toast.makeText(this, "Failed to update exam", Toast.LENGTH_SHORT).show();
        }
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        dataSource.close();
    }
    // 添加一个方法用于更新主界面
    private void updateMainActivity() {

        // 在这里执行更新主界面的操作
        // 这可能涉及到重新加载数据等操作，根据你的代码结构来实现
        // 你可能需要在 MainActivity 中提供一个方法用于更新数据，然后在这里调用该方法
    }


}
