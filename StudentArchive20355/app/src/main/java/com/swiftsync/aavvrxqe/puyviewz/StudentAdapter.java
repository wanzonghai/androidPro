package com.swiftsync.aavvrxqe.puyviewz;

import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.ArrayList;

public class StudentAdapter extends ArrayAdapter<Student> {

    public StudentAdapter(Context context, ArrayList<Student> students) {
        super(context, 0, students);
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        // 获取数据项的数据
        Student student = getItem(position);

        // 检查是否有现有视图可以重复使用，如果没有，则为数据项创建新视图
        if (convertView == null) {
            convertView = LayoutInflater.from(getContext()).inflate(R.layout.student_item_layout, parent, false);
        }

        // 获取视图中的 TextView
        TextView tvStudentId = convertView.findViewById(R.id.tvStudentId);
        TextView tvStudentName = convertView.findViewById(R.id.tvStudentName);
        TextView tvMajor = convertView.findViewById(R.id.tvMajor);
        TextView tvStudentClass = convertView.findViewById(R.id.tvStudentClass);

        // 设置 TextView 的文本
        tvStudentId.setText("Student ID: " + student.studentid);
        tvStudentName.setText("Name: " + student.studentname);
        tvMajor.setText("Major: " + student.majoy);
        tvStudentClass.setText("Class: " + student.studentclass);

        return convertView;
    }
}
