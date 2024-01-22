package com.rfflipadbi.rjma.enturycalendar;


import android.os.Bundle;

import android.widget.CalendarView;

import android.widget.Toast;

import java.util.Calendar;
import java.util.HashMap;
import java.util.Map;

import androidx.appcompat.app.AppCompatActivity;

public class CalendarActivity extends AppCompatActivity {
    private Map<Long, String> specialDates;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_calendar);
        specialDates = new HashMap<>();
        specialDates.put(getMillisFromDate("2023-01-01"), "New Year's Day");
        specialDates.put(getMillisFromDate("2023-02-02"), "World Wetlands Day");
        specialDates.put(getMillisFromDate("2023-02-14"), "Valentine's Day");
        specialDates.put(getMillisFromDate("2023-03-08"), "International Women's Day");
        specialDates.put(getMillisFromDate("2023-04-01"), "April Fools' Day");
        specialDates.put(getMillisFromDate("2023-05-01"), "Labor Day");
        specialDates.put(getMillisFromDate("2023-05-12"), "International Nurses Day");
        specialDates.put(getMillisFromDate("2023-06-01"), "International Children's Day");
        specialDates.put(getMillisFromDate("2023-06-23"), "Olympic Day");
        specialDates.put(getMillisFromDate("2023-07-04"), "Independence Day (USA)");
        specialDates.put(getMillisFromDate("2023-09-05"), "Teachers' Day (China)");
        specialDates.put(getMillisFromDate("2023-10-05"), "World Teachers' Day");
        specialDates.put(getMillisFromDate("2023-10-01"), "National Day (China)");
        specialDates.put(getMillisFromDate("2023-10-04"), "World Animal Day");
        specialDates.put(getMillisFromDate("2023-10-15"), "Global Handwashing Day");
        specialDates.put(getMillisFromDate("2023-11-01"), "Halloween");
        specialDates.put(getMillisFromDate("2023-11-25"), "Thanksgiving Day");
        specialDates.put(getMillisFromDate("2023-12-01"), "World AIDS Day");
        specialDates.put(getMillisFromDate("2023-12-25"), "Christmas Day");

        // Add other special dates
        specialDates.put(getMillisFromDate("2023-05-09"), "Mother's Day");
        specialDates.put(getMillisFromDate("2023-06-05"), "World Environment Day");
        specialDates.put(getMillisFromDate("2023-05-31"), "World No Tobacco Day");
        specialDates.put(getMillisFromDate("2023-08-12"), "International Youth Day");
        specialDates.put(getMillisFromDate("2023-09-21"), "International Day of Peace");
        specialDates.put(getMillisFromDate("2023-09-29"), "World Heart Day");
        specialDates.put(getMillisFromDate("2023-10-10"), "World Mental Health Day");
        specialDates.put(getMillisFromDate("2023-11-14"), "World Diabetes Day");
        specialDates.put(getMillisFromDate("2023-11-20"), "World Children's Day");
        specialDates.put(getMillisFromDate("2023-12-10"), "Human Rights Day");
        CalendarView calendarView = findViewById(R.id.calendarView);

        // 设置日期选择监听器
        calendarView.setOnDateChangeListener(new CalendarView.OnDateChangeListener() {
            @Override
            public void onSelectedDayChange(CalendarView view, int year, int month, int dayOfMonth) {
                String selectedDate = year + "-" + (month + 1) + "-" + dayOfMonth;

                // Check if the selected date is a special date
                if (isSpecialDate(selectedDate)) {
                    // Perform actions for special dates, such as displaying a marker or showing a message
                    showSpecialEvent(specialDates.get(getMillisFromDate(selectedDate)));
                } else {
                    // Handle events for regular dates
                    Toast.makeText(CalendarActivity.this, "Selected date is: " + selectedDate, Toast.LENGTH_SHORT).show();
                }
            }
        });
    }

    // 检查日期是否是特殊日期的方法
    private boolean isSpecialDate(String date) {
        // 这里可以根据你的需求来判断哪些日期是特殊日期
        return specialDates.containsKey(getMillisFromDate(date));
    }

    // 显示特殊事件的方法
    private void showSpecialEvent(String event) {
        Toast.makeText(CalendarActivity.this, "Special Even：" + event, Toast.LENGTH_SHORT).show();
    }
    // 设置特殊日期的文本样式
    private void setSpecialDateTextAppearance(CalendarView calendarView) {
        calendarView.setShowWeekNumber(false);
        calendarView.setFirstDayOfWeek(2);
    }

    // 将日期字符串转换为毫秒数
    private long getMillisFromDate(String date) {
        // ...（同前面的方法）
        Calendar calendar = Calendar.getInstance();
        String[] dateComponents = date.split("-");
        int year = Integer.parseInt(dateComponents[0]);
        int month = Integer.parseInt(dateComponents[1]) - 1; // 月份从0开始
        int day = Integer.parseInt(dateComponents[2]);
        calendar.set(year, month, day, 0, 0, 0);
        return calendar.getTimeInMillis();
    }
}
