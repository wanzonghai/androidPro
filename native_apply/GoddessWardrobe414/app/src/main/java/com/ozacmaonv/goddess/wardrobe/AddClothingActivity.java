package com.ozacmaonv.goddess.wardrobe;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import androidx.appcompat.app.AppCompatActivity;
import androidx.lifecycle.ViewModelProvider;
import com.google.android.material.snackbar.Snackbar;

public class AddClothingActivity extends AppCompatActivity {

    private EditText editTextName;
    private EditText editTextType;
    private EditText editTextColor;
    private ClothingViewModel clothingViewModel;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_add_clothing);

        editTextName = findViewById(R.id.editTextName);
        editTextType = findViewById(R.id.editTextType);
        editTextColor = findViewById(R.id.editTextColor);

        // 获取ClothingViewModel
        clothingViewModel = new ViewModelProvider(this).get(ClothingViewModel.class);

        Button buttonAdd = findViewById(R.id.buttonAdd);
        buttonAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                addClothingItem();
            }
        });
    }

    private void addClothingItem() {
        String name = editTextName.getText().toString().trim();
        String type = editTextType.getText().toString().trim();
        String color = editTextColor.getText().toString().trim();

        if (!name.isEmpty() && !type.isEmpty() && !color.isEmpty()) {
            ClothingEntity newClothingEntity = new ClothingEntity(name, type, color);

            // 使用ViewModel插入数据
            clothingViewModel.insertClothingItem(newClothingEntity);

            // 返回MainActivity
            finish();
        } else {
            // 提示用户输入所有必填字段
            showValidationMessage();
        }
    }

    private void showValidationMessage() {
        Snackbar.make(findViewById(android.R.id.content), "Please enter all required fields", Snackbar.LENGTH_SHORT).show();
    }
}
