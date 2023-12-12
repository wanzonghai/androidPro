package com.miiyvo.mqevxo.model;

import androidx.fragment.app.Fragment;
import android.os.Bundle;
import android.os.Parcelable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.TextView;

import com.miiyvo.mqevxo.seatreservex.R;

public class SeatFragment extends Fragment {
    private static final String ARG_SEAT = "seat";
    private Seat seat;

    public static SeatFragment newInstance(Seat seat) {
        SeatFragment fragment = new SeatFragment();
        Bundle args = new Bundle();
        args.putParcelable(ARG_SEAT, (Parcelable) seat);
        fragment.setArguments(args);
        return fragment;
    }


    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (getArguments() != null) {
            seat = getArguments().getParcelable(ARG_SEAT);
        }
    }

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View view = inflater.inflate(R.layout.fragment_seat, container, false);
        TextView seatNumberTextView = view.findViewById(R.id.seatNumberTextView);
        if (seat != null) {
            seatNumberTextView.setText(seat.getSeatNumber());
            // TODO: 根据需要显示更多座位信息
        }
        // TODO: 显示更多座位信息
        return view;
    }
}
