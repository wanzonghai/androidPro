package com.myhsnl.diligenthou.model;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

public class Student implements Serializable {
    private long id;
    private String name;
    private String rollNumber;

    private String genderType;

    private String contactNumber;

    private List<Attendance> attendances;



    public Student() {
        // Empty constructor
    }

    public Student(String name, String rollNumber,String genderType,String contactNumber) {
        this.name = name;
        this.rollNumber = rollNumber;
        this.genderType = genderType;
        this.contactNumber = contactNumber;

    }

    public List<Attendance> getAttendances() {
        return attendances;
    }

    public void setAttendances(List<Attendance> attendances) {
        this.attendances = attendances;
    }

    // Getter and setter methods for 'id'
    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    // Getter and setter methods for 'name'
    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    // Getter and setter methods for 'rollNumber'
    public String getRollNumber() {
        return rollNumber;
    }

    public void setRollNumber(String rollNumber) {
        this.rollNumber = rollNumber;
    }

    public String getGenderType() {
        return genderType;
    }

    public void setGenderType(String genderType) {
        this.genderType = genderType;
    }

    public String getContactNumber() {
        return contactNumber;
    }

    public void setContactNumber(String contactNumber) {
        this.contactNumber = contactNumber;
    }

    // 添加一个方法用于将新的考勤记录添加到学生的考勤列表中
    // 添加考勤记录到学生的考勤列表
    public void addAttendance(Attendance attendance) {
        if (attendances == null) {
            attendances = new ArrayList<>();
        }
        attendances.add(attendance);
    }

    // Additional methods and properties...

    @Override
    public String toString() {
        return "Student{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", rollNumber='" + rollNumber + '\'' +
                ", genderType='" + genderType + '\'' +
                ", contactNumber='" + contactNumber + '\'' +
                '}';
    }
}
