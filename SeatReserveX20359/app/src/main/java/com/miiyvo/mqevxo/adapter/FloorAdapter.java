package com.miiyvo.mqevxo.adapter;

// 在适配器类中，可以使用自定义布局来显示楼层和座位的信息

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.miiyvo.mqevxo.model.Floor;
import com.miiyvo.mqevxo.model.Seat;
import com.miiyvo.mqevxo.seatreservex.R;

import java.util.List;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

public class FloorAdapter extends RecyclerView.Adapter<FloorAdapter.FloorViewHolder> {
    private List<Floor> floors;

    public FloorAdapter(List<Floor> floors) {
        this.floors = floors;
    }

    @NonNull
    @Override
    public FloorViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.custom_floor_item, parent, false);
        return new FloorViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull FloorViewHolder holder, int position) {
        holder.floorTextView.setText(floors.get(position).getFloorName());
    }

    @Override
    public int getItemCount() {
        return floors.size();
    }

    public static class FloorViewHolder extends RecyclerView.ViewHolder {
        public TextView floorTextView;

        public FloorViewHolder(@NonNull View itemView) {
            super(itemView);
            floorTextView = itemView.findViewById(R.id.floorTextView);
        }
    }


}
