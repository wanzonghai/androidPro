package com.examwizard.upnspz.seqdmqryau;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.os.Environment;
import android.view.View;
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

public class MainActivity extends AppCompatActivity {
    private ExamDataSource dataSource;
    private FileHelper fileHelper; // 添加 FileHelper 成员变量
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
        // Set up the input
        final EditText inputName = new EditText(this);
        inputName.setHint(R.string.exam_name_hint);
        final EditText inputDate = new EditText(this);
        inputDate.setHint(R.string.exam_date_hint);
        final EditText inputTime = new EditText(this);
        inputTime.setHint(R.string.exam_time_hint);

        // Specify the type of input expected
        inputName.setInputType(android.text.InputType.TYPE_CLASS_TEXT);
        inputDate.setInputType(android.text.InputType.TYPE_CLASS_TEXT);
        inputTime.setInputType(android.text.InputType.TYPE_CLASS_TEXT);

        // Add EditTexts to the container
        container.addView(inputName);
        container.addView(inputDate);
        container.addView(inputTime);

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
//                    dataSource.createExam(examName, examDate, examTime);
                    long examId = dataSource.createExam(examName, examDate, examTime);
                    updateExamList();
                    startEditExamActivity(examId);
                } else {
                    // Inform the user that all fields must be filled
                    // You can display a Toast or show another dialog here
                    // For simplicity, I'll use a Toast in this example
                    Toast.makeText(MainActivity.this, R.string.all_fields_required, Toast.LENGTH_SHORT).show();
                }
            }
        });
        builder.setNegativeButton( R.string.cancel_button_text, new DialogInterface.OnClickListener() {
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
        startActivity(intent);
    }

}