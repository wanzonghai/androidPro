package com.miiyvo.mqevxo.adapter;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.miiyvo.mqevxo.model.Seat;
import com.miiyvo.mqevxo.seatreservex.R;

import java.util.List;

import androidx.annotation.NonNull;
import androidx.core.content.ContextCompat;
import androidx.recyclerview.widget.RecyclerView;

public class SeatAdapter extends RecyclerView.Adapter<SeatAdapter.SeatViewHolder> {
    private List<Seat> seats;
    private OnItemClickListener onItemClickListener; // Listener instance

    public SeatAdapter(List<Seat> seats) {
        this.seats = seats;
    }

    public void setSeats(List<Seat> seats) {
        this.seats = seats;
    }

    @NonNull
    @Override
    public SeatViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.custom_list_item, parent, false);
        return new SeatViewHolder(view);
    }

    // Interface for item click listener
    public interface OnItemClickListener {
        void onItemClick(View view, int position);
    }

    // Method to set the listener
    public void setOnItemClickListener(OnItemClickListener listener) {
        this.onItemClickListener = listener;
    }

    @Override
    public void onBindViewHolder(@NonNull SeatViewHolder holder, int position) {
        Seat seat = seats.get(position);

        // seatNumber 就包含了楼层、列和行的信息，直接显示即可
        holder.idTextView.setText(seat.getSeatNumber());

        // 根据选中状态设置背景和字体颜色
        if (seat.isAvailable()) {
            holder.itemView.setAlpha(1.0f); // 设置座位可用时的状态
            holder.idTextView.setBackgroundResource(R.drawable.y2);
            holder.idTextView.setTextColor(ContextCompat.getColor(holder.itemView.getContext(), android.R.color.white));
        } else {
            holder.itemView.setAlpha(0.5f); // 设置座位不可用时的状态
            holder.idTextView.setBackgroundResource(R.drawable.y1);
            holder.idTextView.setTextColor(ContextCompat.getColor(holder.itemView.getContext(), android.R.color.holo_red_light));
        }
        // 座位项的点击事件
        holder.itemView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                int clickedPosition = holder.getAdapterPosition();
                if (onItemClickListener != null&& clickedPosition != RecyclerView.NO_POSITION) {
                    onItemClickListener.onItemClick(v, clickedPosition); // 触发监听器方法
                }
            }
        });
    }

    @Override
    public int getItemCount() {
        return seats.size();
    }

    // 添加方法用于更新数据
    public void updateData(List<Seat> newSeats) {
        this.seats = newSeats;
        notifyDataSetChanged();
    }

    public static class SeatViewHolder extends RecyclerView.ViewHolder {
        public TextView idTextView;

        public SeatViewHolder(@NonNull View itemView) {
            super(itemView);
            idTextView = itemView.findViewById(R.id.idTextView);
        }
    }
}
