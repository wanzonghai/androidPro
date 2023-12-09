package com.examwizard.upnspz.seqdmqryau;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Environment;
import android.text.InputType;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ListView;

import java.io.File;
import java.util.List;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.widget.EditText;
import android.widget.Toast;

import com.google.android.material.textfield.TextInputEditText;
import com.google.android.material.textfield.TextInputLayout;

public class MainActivity extends AppCompatActivity {
    private ExamDataSource dataSource;
    private FileHelper fileHelper; // 添加 FileHelper 成员变量

    private static final int EDIT_EXAM_REQUEST = 1; // 可以使用其他任何整数值
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // 创建 FileHelper 对象
        fileHelper = new FileHelper(this);
        // 获取当前用户的数据库文件
        File userDatabaseFile = fileHelper.getUserDatabaseFile();
        dataSource = new ExamDataSource(this,userDatabaseFile);
        dataSource.open();

        Button addExamButton = findViewById(R.id.btnAddExam);
        addExamButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // Handle adding a new exam
                showAddExamDialog();
            }
        });
        Button btnLogout = findViewById(R.id.btnLogout);
        btnLogout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // 在这里执行退出登录的逻辑
                // 可以是清除用户登录状态、跳转到登录页面等
                logout();
            }
        });

        updateExamList();
        setupListViewClickListener(); // 添加这一行
    }

    private void updateExamList() {
        List<Exam> exams = dataSource.getAllExams();

        ExamAdapter adapter = new ExamAdapter(this, exams);
        ListView listView = findViewById(R.id.listViewExams);
        listView.setAdapter(adapter);
    }
    private void setupListViewClickListener() {
        ListView listView = findViewById(R.id.listViewExams);
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                Exam selectedExam = (Exam) parent.getItemAtPosition(position);
                long examId = selectedExam.getId();
                startEditExamActivity(examId);
            }
        });
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        dataSource.close();
    }

    private void showAddExamDialog() {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle(R.string.add_exam_dialog_title);

        // Create a LinearLayout container
        LinearLayout container = new LinearLayout(this);
        container.setOrientation(LinearLayout.VERTICAL);

        // Set up the input using TextInputLayout
        TextInputLayout inputNameLayout = new TextInputLayout(this);
        TextInputEditText inputName = new TextInputEditText(this);
        inputName.setHint(getString(R.string.exam_name_hint));
        inputName.setInputType(InputType.TYPE_CLASS_TEXT);
        inputNameLayout.addView(inputName);
        container.addView(inputNameLayout);

        TextInputLayout inputDateLayout = new TextInputLayout(this);
        TextInputEditText inputDate = new TextInputEditText(this);
        inputDate.setHint(getString(R.string.exam_date_hint));
        inputDate.setInputType(InputType.TYPE_CLASS_TEXT);
        inputDateLayout.addView(inputDate);
        container.addView(inputDateLayout);

        TextInputLayout inputTimeLayout = new TextInputLayout(this);
        TextInputEditText inputTime = new TextInputEditText(this);
        inputTime.setHint(getString(R.string.exam_time_hint));
        inputTime.setInputType(InputType.TYPE_CLASS_TEXT);
        inputTimeLayout.addView(inputTime);
        container.addView(inputTimeLayout);

        // Set margins for the container
        LinearLayout.LayoutParams layoutParams = new LinearLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT,
                ViewGroup.LayoutParams.WRAP_CONTENT
        );
        int margin = getResources().getDimensionPixelSize(R.dimen.dialog_margin);
        layoutParams.setMargins(margin, margin, margin, margin);
        container.setLayoutParams(layoutParams);

        // Set the container as the dialog view
        builder.setView(container);

        // Set up the buttons
        builder.setPositiveButton(R.string.add_button_text, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                String examName = inputName.getText().toString();
                String examDate = inputDate.getText().toString();
                String examTime = inputTime.getText().toString();

                // Check if any of the inputs is empty
                if (!examName.isEmpty() && !examDate.isEmpty() && !examTime.isEmpty()) {
                    // Handle adding a new exam with the entered information
                    long examId = dataSource.createExam(examName, examDate, examTime);
                    updateExamList();
                    startEditExamActivity(examId);
                } else {
                    // Inform the user that all fields must be filled
                    Toast.makeText(MainActivity.this, R.string.all_fields_required, Toast.LENGTH_SHORT).show();
                }
            }
        });

        builder.setNegativeButton(R.string.cancel_button_text, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                dialog.cancel();
            }
        });

        builder.show();
    }

    private void startEditExamActivity(long examId) {
        Intent intent = new Intent(this, EditExamActivity.class);
        intent.putExtra("EXAM_ID", examId);
        startActivityForResult(intent, EDIT_EXAM_REQUEST);
    }

    // 添加退出登录逻辑的方法
    private void logout() {
        // 清除保存的用户名和密码
        SharedPreferences.Editor editor = getSharedPreferences(LoginActivity.PREFS_NAME, Context.MODE_PRIVATE).edit();
        editor.remove(LoginActivity.KEY_USERNAME);
        editor.remove(LoginActivity.KEY_PASSWORD);
        editor.apply();

//        // 获取当前登录的用户名
//        SharedPreferences prefs = getSharedPreferences(LoginActivity.PREFS_NAME, Context.MODE_PRIVATE);
//        String username = prefs.getString(LoginActivity.KEY_USERNAME, "");

//        // 删除用户特定的数据库文件
//        File userDatabaseFile = fileHelper.getUserDatabaseFile(username);
//        if (userDatabaseFile.exists()) {
//            userDatabaseFile.delete();
//        }

        // 跳转到登录页面
        startLoginActivity();
    }

    // 添加跳转到登录页面的方法
    private void startLoginActivity() {
        Intent intent = new Intent(this, LoginActivity.class);
        startActivity(intent);
        finish(); // 关闭当前活动，确保用户无法返回到 MainActivity
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == EDIT_EXAM_REQUEST && resultCode == RESULT_OK) {
            // 检查是否包含更新后的考试信息
            if (data != null && data.hasExtra("UPDATED_EXAM_NAME") &&
                    data.hasExtra("UPDATED_EXAM_DATE") && data.hasExtra("UPDATED_EXAM_TIME")) {
                // 提取更新后的考试信息
                String updatedExamName = data.getStringExtra("UPDATED_EXAM_NAME");
                String updatedExamDate = data.getStringExtra("UPDATED_EXAM_DATE");
                String updatedExamTime = data.getStringExtra("UPDATED_EXAM_TIME");

                // 更新 UI 中相应的考试信息
                updateExamInList(updatedExamName, updatedExamDate, updatedExamTime);
            }
        }
    }

    private void updateExamInList(String updatedExamName, String updatedExamDate, String updatedExamTime) {
        // 根据考试名称查找相应的 Exam 对象
        Exam updatedExam = findExamByName(updatedExamName);

        if (updatedExam != null) {
            // 更新 Exam 对象的信息
            updatedExam.setDate(updatedExamDate);
            updatedExam.setTime(updatedExamTime);

            // 更新 UI 列表
            updateExamList();
        }
    }

    private Exam findExamByName(String examName) {
        // 根据考试名称查找 Exam 对象
        List<Exam> exams = dataSource.getAllExams();
        for (Exam exam : exams) {
            if (exam.getName().equals(examName)) {
                return exam;
            }
        }
        return null;
    }


}