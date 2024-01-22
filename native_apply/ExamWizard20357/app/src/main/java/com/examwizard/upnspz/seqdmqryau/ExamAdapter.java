package com.examwizard.upnspz.seqdmqryau;
import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import java.util.List;

public class ExamAdapter extends ArrayAdapter<Exam> {

    public ExamAdapter(Context context, List<Exam> exams) {
        super(context, 0, exams);
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent) {
        // Get the data item for this position
        Exam exam = getItem(position);

        // Check if an existing view is being reused, otherwise inflate the view
        if (convertView == null) {
            convertView = LayoutInflater.from(getContext()).inflate(R.layout.exam_item, parent, false);
        }

        // Lookup view for data population
        TextView tvName = convertView.findViewById(R.id.tvExamName);
        TextView tvDateLabel = convertView.findViewById(R.id.tvExamDateLabel);
        TextView tvDate = convertView.findViewById(R.id.tvExamDate);
        TextView tvTimeLabel = convertView.findViewById(R.id.tvExamTimeLabel);
        TextView tvTime = convertView.findViewById(R.id.tvExamTime);

        // Populate the data into the template view using the data object
        tvName.setText(exam.getName());
        tvDateLabel.setText("Date: ");
        tvDate.setText(exam.getDate());
        tvTimeLabel.setText("Time: ");
        tvTime.setText(exam.getTime());
        // Return the completed view to render on screen
        return convertView;
    }
}
