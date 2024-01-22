package com.ozacmaonv.goddess.wardrobe;

import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import android.os.Bundle;

import java.util.ArrayList;
import java.util.List;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import androidx.appcompat.app.AppCompatActivity;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentManager;
import androidx.fragment.app.FragmentTransaction;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button buttonShowClothing = findViewById(R.id.buttonShowClothing);
        buttonShowClothing.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                showClothingListFragment();
            }
        });
    }

    private void showClothingListFragment() {
        // 切换到展示界面
        Fragment clothingListFragment = new ClothingListFragment();
        FragmentManager fragmentManager = getSupportFragmentManager();
        FragmentTransaction fragmentTransaction = fragmentManager.beginTransaction();
        fragmentTransaction.replace(android.R.id.content, clothingListFragment);
        fragmentTransaction.addToBackStack(null);
        fragmentTransaction.commit();

        // 隐藏按钮
        Button buttonShowClothing = findViewById(R.id.buttonShowClothing);
        buttonShowClothing.setVisibility(View.GONE);
    }


}
