package com.myhsnl.diligenthou.sekeeper;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.Spinner;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;

import com.myhsnl.diligenthou.manager.StudentManager;
import com.myhsnl.diligenthou.model.Student;

public class EditStudentActivity extends AppCompatActivity {

    private EditText editTextEditName, editTextEditRollNumber,editTextContactNumber;
    private Spinner spinnerGender;
    private Button buttonSaveChanges;
    private Student student;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_edit_student);

        // Initialize UI components
        editTextEditName = findViewById(R.id.editTextName);
        editTextEditRollNumber = findViewById(R.id.editTextRollNumber);
        editTextContactNumber= findViewById(R.id.editTextContactNumber);
        buttonSaveChanges = findViewById(R.id.buttonSaveChanges);

        // Get the Spinner instance
        spinnerGender = findViewById(R.id.spinnerTextGender);

        // Set the adapter for the Spinner
        ArrayAdapter<CharSequence> genderAdapter = ArrayAdapter.createFromResource(
                this,
                R.array.gender_types,
                android.R.layout.simple_spinner_item
        );
        genderAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        spinnerGender.setAdapter(genderAdapter);

        // Set the initial value for the Spinner based on the student's gender
        if (student != null) {
            String studentGender = student.getGenderType();
            if (studentGender != null) {
                int genderPosition = genderAdapter.getPosition(studentGender);
                spinnerGender.setSelection(genderPosition);
            }
        }


        // Get the Student object from the intent
        Intent intent = getIntent();
        if (intent != null && intent.hasExtra("student")) {
            student = (Student) intent.getSerializableExtra("student");

            String studentGender = student.getGenderType();
            if (studentGender != null) {
                int genderPosition = genderAdapter.getPosition(studentGender);
                spinnerGender.setSelection(genderPosition);
            }
            // Populate the EditText fields with existing data
            editTextEditName.setText(student.getName());
            editTextEditRollNumber.setText(student.getRollNumber());
            editTextContactNumber.setText(student.getContactNumber());
        }

        // Set a click listener for the Save Changes button
        buttonSaveChanges.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                // Save the changes and update the Student object
                saveChanges();
            }
        });
    }

    private void saveChanges() {
        // Update the Student object with new data


        String newName = editTextEditName.getText().toString().trim();
        String newRollNumber = editTextEditRollNumber.getText().toString().trim();
        String newContactNumbe= editTextContactNumber.getText().toString().trim();
        String studentGenderType = spinnerGender.getSelectedItem().toString().trim();
        if (newName.isEmpty() || newRollNumber.isEmpty()) {
            Toast.makeText(EditStudentActivity.this, "Name and Roll Number cannot be empty", Toast.LENGTH_SHORT).show();
            return;
        }
        student.setName(newName);
        student.setRollNumber(newRollNumber);
        student.setGenderType(studentGenderType);
        student.setContactNumber(newContactNumbe);
        // TODO: Save the changes to your data storage (e.g., database)
        // Save the changes to the database
        StudentManager studentManager = new StudentManager(this);
        studentManager.updateStudent(student);
        Toast.makeText(EditStudentActivity.this, "Modified student information successfully", Toast.LENGTH_SHORT).show();

        // Close the database connection
        studentManager.closeDatabase();

        // Notify the calling activity that changes are saved (optional)
        Intent resultIntent = new Intent();
        resultIntent.putExtra("editedStudent", student);
        setResult(RESULT_OK, resultIntent);


        // Finish the activity
        finish();
    }
}
