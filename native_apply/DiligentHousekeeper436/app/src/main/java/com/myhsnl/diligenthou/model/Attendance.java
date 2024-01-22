package com.myhsnl.diligenthou.model;

import com.myhsnl.diligenthou.daoR.AttendanceStatus;

import java.io.Serializable;
import java.util.Date;

import java.util.Date;

public class Attendance implements Serializable {
    private long id;
    private long studentId;
    private long courseId; // 新增课程 ID 属性
    private Date date;

    private AttendanceStatus status;

    public Attendance() {
        // Empty constructor
    }

    public Attendance(long studentId, long courseId, Date date, AttendanceStatus status) {
        this.studentId = studentId;
        this.courseId = courseId;
        this.date = date;
        this.status = status;
    }

    // Getter and setter methods for 'id'
    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    // Getter and setter methods for 'studentId'
    public long getStudentId() {
        return studentId;
    }

    public void setStudentId(long studentId) {
        this.studentId = studentId;
    }

    public long getCourseId() {
        return courseId;
    }

    public void setCourseId(long courseId) {
        this.courseId = courseId;
    }


    // Getter and setter methods for 'date'
    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    // Getter and setter methods for 'present'
    public AttendanceStatus getStatus() {
        return status;
    }

    public void setStatus(AttendanceStatus status) {
        this.status = status;
    }

    // Additional methods and properties...

    @Override
    public String toString() {
        return "Attendance{" +
                "id=" + id +
                ", studentId=" + studentId +
                ", courseId=" + courseId +
                ", date=" + date +
                ", status=" + status +
                '}';
    }
}

