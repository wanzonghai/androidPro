package com.miiyvo.mqevxo.seatreservex;

import android.os.Bundle;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.GridLayout;
import android.widget.ImageView;
import android.widget.ListView;
import android.widget.Spinner;
import android.widget.TextView;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.recyclerview.widget.GridLayoutManager;
import androidx.recyclerview.widget.LinearLayoutManager;
import androidx.recyclerview.widget.RecyclerView;

import com.miiyvo.mqevxo.adapter.FloorAdapter;
import com.miiyvo.mqevxo.adapter.SeatAdapter;
import com.miiyvo.mqevxo.model.Floor;
import com.miiyvo.mqevxo.model.Seat;

import java.util.ArrayList;
import java.util.List;

public class ViewSeatActivity extends AppCompatActivity {


    private RecyclerView seatRecyclerView;

    private List<Floor> floors;  // 声明楼层列表
    private List<Seat> seats;  // 声明座位列表

    private SeatAdapter seatAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_view_seat);

        // 初始化控件
        // 在 ViewSeatActivity.java 中

        // 获取楼层选择 Spinner 或其他控件
        Spinner floorSpinner = findViewById(R.id.floorSpinner);
        seatRecyclerView = findViewById(R.id.seatRecyclerView);

        // 获取从 MainActivity 传递过来的楼层和座位数据
        floors = getIntent().getParcelableArrayListExtra("floors");
        seats = getIntent().getParcelableArrayListExtra("seats");


        // 设置楼层 ListView 的适配器
        // 设置楼层选择下拉列表的适配器
        ArrayAdapter<Floor> floorAdapter = new ArrayAdapter<>(this, android.R.layout.simple_spinner_item, floors);
        floorAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        floorSpinner.setAdapter(floorAdapter);

        // 设置座位 ListView 的适配器
        // 例如，创建一个 custom_list_item.xml 布局
        // 在这个布局中，你可以使用 ImageView 显示图标，TextView 显示 ID
        seatAdapter = new SeatAdapter(seats);
        GridLayoutManager seatLayoutManager = new GridLayoutManager (this,6);
        seatRecyclerView.setAdapter(seatAdapter);
        seatRecyclerView.setLayoutManager(seatLayoutManager);



        // 在这里手动调用一次 filterSeatsByFloor，传入 null 表示用户未选择楼层
        List<Seat> filteredSeats = filterSeatsByFloor(null);

        // 更新 SeatAdapter 中的数据
        seatAdapter.setSeats(filteredSeats);
        seatAdapter.notifyDataSetChanged();

        // 在楼层选择的监听器中
        floorSpinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
            @Override
            public void onItemSelected(AdapterView<?> parentView, View selectedItemView, int position, long id) {
                // 获取选中的楼层
                Floor selectedFloor = (Floor) parentView.getItemAtPosition(position);
                Log.d("ViewSeatActivity", "Selected Floor: " + selectedFloor);

                // 根据选中的楼层筛选座位数据
                List<Seat> filteredSeats = filterSeatsByFloor(selectedFloor);

                // 更新 SeatAdapter 中的数据
                seatAdapter.setSeats(filteredSeats);
                seatAdapter.notifyDataSetChanged();
            }

            @Override
            public void onNothingSelected(AdapterView<?> parentView) {
                // 处理未选择楼层的情况，如果有需要的话
            }

        });

        // 设置座位列表的点击事件监听器
        seatAdapter.setOnItemClickListener(new SeatAdapter.OnItemClickListener() {
            @Override
            public void onItemClick(View view, int position) {
                Seat selectedSeat = seats.get(position);
                // 处理座位的选中状态，更新数据等
                selectedSeat.setAvailable(!selectedSeat.isAvailable()); // toggle seat availability
                seatAdapter.notifyItemChanged(position); // notify adapter about the change in this particular item
            }
        });
    }
    // 过滤座位数据的方法
    private List<Seat> filterSeatsByFloor(Floor selectedFloor) {
        List<Seat> filteredSeats = new ArrayList<>();


        if (selectedFloor == null) {
            // 用户未选择楼层，显示第一层的座位
            for (Seat seat : seats) {
                int floorFromSeatNumber = seat.getFloorFromSeatNumber();
                if (floorFromSeatNumber == 1) {
                    filteredSeats.add(seat);
                }
            }
        } else {
            // 根据选中的楼层筛选相应的座位数据
            for (Seat seat : seats) {
                if (seat.getFloorFromSeatNumber() == selectedFloor.getFloorId()) {
                    filteredSeats.add(seat);
                }
            }
        }

        return filteredSeats;
    }

}
