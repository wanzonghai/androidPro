package com.myhsnl.diligenthou.sekeeper;

import android.app.AlertDialog;
import android.content.DialogInterface;

import androidx.activity.result.ActivityResultLauncher;
import androidx.activity.result.contract.ActivityResultContracts;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

import com.google.android.material.floatingactionbutton.FloatingActionButton;
import com.myhsnl.diligenthou.adapter.StudentAdapter;
import com.myhsnl.diligenthou.manager.StudentManager;
import com.myhsnl.diligenthou.model.Student;

import java.util.ArrayList;
import java.util.List;


public class MainActivity extends AppCompatActivity {

    private RecyclerView recyclerViewStudents;
    private StudentAdapter studentAdapter;
    private StudentManager studentManager; // 使用 StudentManager 进行数据库操作

    private List<Student> studentList;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // 初始化学生列表
        studentManager = new StudentManager(this);
        // 添加示例学生数据
//        studentList.add(new Student("John Doe", "12345"));
//        studentList.add(new Student("Jane Smith", "67890"));
        // 初始化RecyclerView
        recyclerViewStudents = findViewById(R.id.recyclerViewStudents);
        recyclerViewStudents.setLayoutManager(new LinearLayoutManager(this));


        // 初始化适配器
        studentList = studentManager.getAllStudentsSortedByRollNumber();
        studentAdapter = new StudentAdapter(studentList,new StudentAdapter.OnItemClickListener() {
            @Override
            public void onItemClick(int position) {
                // 处理点击学生列表项查看详细信息的逻辑
                // 可以启动新的Activity显示学生详细信息
                Student student = studentList.get(position);
                Intent intent = new Intent(MainActivity.this, StudentDetailActivity.class);
                intent.putExtra("student", student);
                startActivity(intent);
            }

            @Override
            public void onEditClick(int position) {
                // 处理点击编辑按钮的逻辑
                // 可以启动新的Activity进行学生信息编辑
                Student student = studentList.get(position);
                Intent editIntent = new Intent(MainActivity.this, EditStudentActivity.class);
                editIntent.putExtra("student", student);
                editStudentLauncher.launch(editIntent);
            }

            @Override
            public void onDeleteClick(int position) {
                // 处理点击删除按钮的逻辑
                // 可以弹出确认对话框等
                showDeleteConfirmationDialog(position);
            }
        });
        recyclerViewStudents.setAdapter(studentAdapter);
        generateRandomStudentsAndAddToDatabase();
        // Define a contract for your activity result
        ActivityResultLauncher<Intent> addStudentLauncher = registerForActivityResult(
                new ActivityResultContracts.StartActivityForResult(),
                result -> {
                    if (result.getResultCode() == RESULT_OK) {
                        // Refresh the data when a new student is added
                        studentList = studentManager.getAllStudentsSortedByRollNumber();
                        studentAdapter.updateData(studentList);
                    }
                }
        );
        // FloatingActionButton click listener
        FloatingActionButton fab = findViewById(R.id.fab);
        fab.setOnClickListener(view -> {
            Intent intent = new Intent(MainActivity.this, AddStudentActivity.class);
            addStudentLauncher.launch(intent);
        });
    }
    private final ActivityResultLauncher<Intent> editStudentLauncher = registerForActivityResult(
            new ActivityResultContracts.StartActivityForResult(),
            result -> {
                if (result.getResultCode() == RESULT_OK) {
                    // Get the edited student from the intent
                    Student editedStudent = (Student) result.getData().getSerializableExtra("editedStudent");

                    // Update the studentList with the edited student
                    updateEditedStudent(editedStudent);
                }
            }
    );
    private void showDeleteConfirmationDialog(final int position) {
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("Confirm Delete");
        builder.setMessage("Are you sure you want to delete this student?");
        builder.setPositiveButton("Yes", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialogInterface, int i) {
                // Delete the student and update the RecyclerView
                deleteStudent(position);
            }
        });
        builder.setNegativeButton("No", null);
        builder.show();
    }

    private void deleteStudent(int position) {
        // Implement the logic to delete the student from the list and update the RecyclerView
        Student studentToDelete = studentAdapter.getStudentAtPosition(position);
        if (studentToDelete != null) {
            studentManager.deleteStudent(studentToDelete.getId());
            studentAdapter.updateData(studentManager.getAllStudents());
            studentAdapter.notifyDataSetChanged();
            Toast.makeText(MainActivity.this, "Deleting student information succeeded", Toast.LENGTH_SHORT).show();
        }
    }


    private void updateEditedStudent(Student editedStudent) {
        for (int i = 0; i < studentList.size(); i++) {
            if (studentList.get(i).getId() == editedStudent.getId()) {
                // Update the existing student with editedStudent
                studentList.set(i, editedStudent);

                // Notify the adapter about the data change
                studentAdapter.notifyItemChanged(i);

                // Retrieve the sorted student list
                studentList = studentManager.getAllStudentsSortedByRollNumber();

                // Notify the adapter about the sorted data
                studentAdapter.updateData(studentList);
                studentAdapter.notifyDataSetChanged();
                break;
            }
        }
    }

    //test
    private void generateRandomStudentsAndAddToDatabase() {
        List<Student> randomStudents = StudentGenerator.generateRandomStudents(10);

        for (Student student : randomStudents) {
            long studentId = studentManager.addStudent(student);
            if (studentId != -1) {
                studentList.add(student);
            } else {
                Toast.makeText(MainActivity.this, "Failed to add student", Toast.LENGTH_SHORT).show();
            }
        }

        studentAdapter.updateData(studentList);
        studentAdapter.notifyDataSetChanged();
        Toast.makeText(MainActivity.this, "Random students added to database", Toast.LENGTH_SHORT).show();
    }
}
