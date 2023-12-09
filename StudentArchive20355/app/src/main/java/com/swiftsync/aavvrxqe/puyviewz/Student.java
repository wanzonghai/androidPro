package com.swiftsync.aavvrxqe.puyviewz;

import android.os.Parcel;
import android.os.Parcelable;

public class Student implements Parcelable , Comparable<Student> {
    public String studentid;
    public String studentname;
    public String majoy;
    public String studentclass;

    // 默认构造方法
    public Student() {
    }

    // Parcelable 接口的实现
    protected Student(Parcel in) {
        studentid = in.readString();
        studentname = in.readString();
        majoy = in.readString();
        studentclass = in.readString();
    }

    public static final Creator<Student> CREATOR = new Creator<Student>() {
        @Override
        public Student createFromParcel(Parcel in) {
            return new Student(in);
        }

        @Override
        public Student[] newArray(int size) {
            return new Student[size];
        }

    };

    @Override
    public int describeContents() {
        return 0;
    }

    @Override
    public void writeToParcel(Parcel dest, int flags) {
        dest.writeString(studentid);
        dest.writeString(studentname);
        dest.writeString(majoy);
        dest.writeString(studentclass);
    }


    @Override
    public int compareTo(Student otherStudent) {
        // 根据学号进行升序排序
        // 将学号解析为整数，然后进行升序排序
        int thisStudentId = Integer.parseInt(this.studentid);
        int otherStudentId = Integer.parseInt(otherStudent.studentid);
        return Integer.compare(thisStudentId, otherStudentId);
    }

}
