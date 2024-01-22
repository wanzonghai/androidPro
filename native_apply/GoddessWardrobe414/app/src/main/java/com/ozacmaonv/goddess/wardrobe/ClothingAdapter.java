package com.ozacmaonv.goddess.wardrobe;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

import java.util.List;

public class ClothingAdapter extends RecyclerView.Adapter<ClothingAdapter.ViewHolder> {
    private List<ClothingEntity> clothingList;
    private ClothingViewModel clothingViewModel; // 新增ViewModel成员

    // 修改构造函数，只接受 List<ClothingEntity>

    public ClothingAdapter(List<ClothingEntity> clothingList, ClothingViewModel viewModel) {
        this.clothingList = clothingList;
        this.clothingViewModel = viewModel;
    }
    // 添加设置 ClothingViewModel 的方法
    public void setClothingViewModel(ClothingViewModel viewModel) {
        this.clothingViewModel = viewModel;
    }
    public class ViewHolder extends RecyclerView.ViewHolder {
        public TextView textViewName;
        public TextView textViewType;
        public TextView textViewColor;

        public Button buttonUpdate;

        public ViewHolder(View itemView) {
            super(itemView);
            textViewName = itemView.findViewById(R.id.textViewName);
            textViewType = itemView.findViewById(R.id.textViewType);
            textViewColor = itemView.findViewById(R.id.textViewColor);
            // 初始化更新按钮
            buttonUpdate = itemView.findViewById(R.id.buttonUpdate);
        }
    }

    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        // 创建ViewHolder并关联recyclerview_item.xml布局
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.recyclerview_item, parent, false);
        return new ViewHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        // 绑定数据到ViewHolder
        ClothingEntity clothingItem = clothingList.get(position);
        holder.textViewName.setText(clothingItem.getName());
        holder.textViewType.setText(clothingItem.getType());
        holder.textViewColor.setText(clothingItem.getColor());

        // 设置更新按钮的点击事件
        holder.buttonUpdate.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 用户点击更新按钮时，调用ViewModel的更新方法
                clothingViewModel.updateClothingItem(clothingItem);
                // 添加反馈，显示一个Toast消息
                Toast.makeText(v.getContext(), "Clothing item updated", Toast.LENGTH_SHORT).show();
            }
        });
    }

    @Override
    public int getItemCount() {
        return clothingList.size();
    }
}
