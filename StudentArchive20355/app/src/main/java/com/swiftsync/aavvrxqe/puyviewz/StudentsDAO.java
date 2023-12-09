package com.swiftsync.aavvrxqe.puyviewz;

import android.content.Context;

public class StudentsDAO {
    private MyDBHelper dbHelper;

    public StudentsDAO(Context context) {
        dbHelper = new MyDBHelper(context);
    }

    public void open() {
        dbHelper.getWritableDatabase();
    }

    public void close() {
        dbHelper.close();
    }
}
