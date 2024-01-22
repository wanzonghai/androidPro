package com.miiyvo.mqevxo.adapter;

import com.miiyvo.mqevxo.model.Seat;
import com.miiyvo.mqevxo.model.SeatFragment;
import com.miiyvo.mqevxo.seatreservex.MainActivity;

import androidx.annotation.NonNull;
import androidx.fragment.app.Fragment;
import androidx.fragment.app.FragmentActivity;
import androidx.viewpager2.adapter.FragmentStateAdapter;

import java.util.List;

public class SeatPagerAdapter extends FragmentStateAdapter  {
    private List<Seat> seats;

    public SeatPagerAdapter(FragmentActivity fragmentActivity, List<Seat> seats) {
        super(fragmentActivity);
        this.seats = seats;
    }
    @Override
    public Fragment createFragment(int position) {
        // 根据位置创建相应的座位Fragment
        // 这里需要根据你的座位数据和逻辑进行实现
        // 可能是 SeatFragment.newInstance(seats.get(position)) 或类似的实现
        // 创建并返回 SeatFragment，你需要根据需要传递相应的 Seat 对象
        return SeatFragment.newInstance(seats.get(position));
    }

    @Override
    public int getItemCount() {
        return seats.size();
    }
}
