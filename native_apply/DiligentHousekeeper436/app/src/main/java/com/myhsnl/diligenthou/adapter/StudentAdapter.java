package com.myhsnl.diligenthou.adapter;

import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.TextView;

import com.myhsnl.diligenthou.model.Student;
import com.myhsnl.diligenthou.sekeeper.R;

import java.util.List;

import androidx.annotation.NonNull;
import androidx.recyclerview.widget.RecyclerView;

public class StudentAdapter extends RecyclerView.Adapter<StudentAdapter.ViewHolder> {

    private List<Student> studentList;

    private OnItemClickListener listener;

    public StudentAdapter(List<Student> studentList, OnItemClickListener listener) {
        this.studentList = studentList;
        this.listener = listener;
    }
    public interface OnItemClickListener {
        void onItemClick(int position);
        void onEditClick(int position);
        void onDeleteClick(int position);
    }

    public void setOnItemClickListener(OnItemClickListener listener) {
        this.listener = listener;
    }
    @NonNull
    @Override
    public ViewHolder onCreateViewHolder(@NonNull ViewGroup parent, int viewType) {
        View view = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_student, parent, false);
        return new ViewHolder(view, listener);
    }

    @Override
    public void onBindViewHolder(@NonNull ViewHolder holder, int position) {
        Student student = studentList.get(position);

        holder.textViewStudentName.setText(student.getName());
        holder.textViewRollNumber.setText(student.getRollNumber());
    }

    @Override
    public int getItemCount() {
        return studentList.size();
    }

    public static class ViewHolder extends RecyclerView.ViewHolder {
        TextView textViewStudentName;
        TextView textViewRollNumber;

        Button editButton;

        Button deleteButton;

        public ViewHolder(@NonNull View itemView, final OnItemClickListener listener) {
            super(itemView);
            textViewStudentName = itemView.findViewById(R.id.textViewStudentName);
            textViewRollNumber = itemView.findViewById(R.id.textViewRollNumber);
            // 处理编辑按钮点击事件
            editButton = itemView.findViewById(R.id.editButton);
            // 处理删除按钮点击事件
            deleteButton = itemView.findViewById(R.id.deleteButton);
            // 处理点击事件
            itemView.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    int position = getAdapterPosition();
                    if (position != RecyclerView.NO_POSITION && listener != null) {
                        listener.onItemClick(position);
                    }
                }
            });


            editButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    if (listener != null) {
                        int position = getAdapterPosition();
                        if (position != RecyclerView.NO_POSITION&& listener != null) {
                            listener.onEditClick(position);
                        }
                    }
                }
            });


            deleteButton.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    if (listener != null) {
                        int position = getAdapterPosition();
                        if (position != RecyclerView.NO_POSITION && listener != null) {
                            listener.onDeleteClick(position);
                        }
                    }
                }
            });
        }

    }
    // Update data when it changes
    public void updateData(List<Student> newList) {
        studentList = newList;
        notifyDataSetChanged();
    }

    public Student getStudentAtPosition(int position) {
        if (position >= 0 && position < studentList.size()) {
            return studentList.get(position);
        }
        return null;
    }

}
