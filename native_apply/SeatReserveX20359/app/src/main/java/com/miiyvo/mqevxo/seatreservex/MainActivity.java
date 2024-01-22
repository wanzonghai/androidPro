package com.miiyvo.mqevxo.seatreservex;

import android.content.Intent;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.Spinner;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;

import com.google.android.material.tabs.TabLayout;
import com.google.android.material.tabs.TabLayoutMediator;
import com.miiyvo.mqevxo.adapter.SeatPagerAdapter;
import com.miiyvo.mqevxo.model.Floor;
import com.miiyvo.mqevxo.model.Seat;
import androidx.viewpager2.widget.ViewPager2;
import java.util.ArrayList;
import java.util.List;

public class MainActivity extends AppCompatActivity {

    private Button buttonReserve;
    private Button buttonViewSeat;
    private Button buttonUserInfo;
    private Button buttonLogout;

    //楼层总数
    private int FLOOR_TOTALS = 3;
    //楼层座椅排数
    private int ROW_SEATS = 6;
    //楼层座椅1排总座椅数
    private int COL_SEATS = 6;

    private List<Floor> floors;
    private List<Seat> seats;


    //当前选中的楼层


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // 初始化控件
        buttonReserve = findViewById(R.id.buttonReserve);
        buttonViewSeat = findViewById(R.id.buttonViewSeat);
        buttonUserInfo = findViewById(R.id.buttonUserInfo);
        buttonLogout = findViewById(R.id.buttonLogout);

        // 获取从 MainActivity 传递过来的座位数据

        initializeData();
        // 设置订座按钮点击事件监听器
        buttonReserve.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                reserveSeat();
            }
        });

        // 设置查看座位按钮点击事件监听器
        buttonViewSeat.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 启动查看座位界面，并传递楼层和座位数据
                updateSeatList();
            }
        });

        // 设置个人信息按钮点击事件监听器
        buttonUserInfo.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                showUserInfo();
            }
        });

        // 设置退出登录按钮点击事件监听器
        buttonLogout.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                logout();
            }
        });
    }
    private void initializeData() {
        floors = new ArrayList<>();
        floors.add(new Floor(1,"1st"));
        floors.add(new Floor(2,"2nd"));
        floors.add(new Floor(3,"3nd"));
        // 添加更多楼层...
        seats = new ArrayList<>();
        // 添加座位
        for (int floorIndex = 1; floorIndex <= FLOOR_TOTALS; floorIndex++) {
            for (int rowIndex = 1; rowIndex <= ROW_SEATS; rowIndex++) {
                for (int seatIndex = 1; seatIndex <= COL_SEATS; seatIndex++) {
                    char rowChar = (char) ('A' + rowIndex - 1); // 将行数转换为字母
                    String seatNumber = String.format("%c%d-%d", rowChar, floorIndex, seatIndex);
                    seats.add(new Seat(floorIndex, seatNumber, true));
                }
            }
        }
        // 添加更多座位...
    }

    private void reserveSeat() {
        // 处理订座逻辑
        updateSeatList();
    }

    private void showUserInfo() {
        // 处理个人信息展示逻辑
        Intent intent = new Intent(MainActivity.this, UserProfileActivity.class);
        startActivity(intent);
    }

    private void logout() {
        // 处理退出登录逻辑
        // 处理个人信息展示逻辑
        Intent intent = new Intent(MainActivity.this, LoginActivity.class);
        startActivity(intent);
        finish();
    }

    // 更新座位列表的方法
    private void updateSeatList() {
        Intent intent = new Intent(MainActivity.this, ViewSeatActivity.class);
        intent.putParcelableArrayListExtra("seats", new ArrayList<>(seats));
        intent.putParcelableArrayListExtra("floors", new ArrayList<>(floors)); // 传递所有楼层数据
        startActivity(intent);
    }
}
