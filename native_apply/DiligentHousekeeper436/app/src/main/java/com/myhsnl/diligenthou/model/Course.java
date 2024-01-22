package com.myhsnl.diligenthou.model;

public class Course {
    private long id;
    private String courseName;
    private long teacherId;

    public Course() {
        // 默认的空构造方法
    }

    public Course(String courseName, long teacherId) {
        this.courseName = courseName;
        this.teacherId = teacherId;
    }

    // Getter 和 Setter 方法

    public long getId() {
        return id;
    }

    public void setId(long id) {
        this.id = id;
    }

    public String getCourseName() {
        return courseName;
    }

    public void setCourseName(String courseName) {
        this.courseName = courseName;
    }

    public long getTeacherId() {
        return teacherId;
    }

    public void setTeacherId(long teacherId) {
        this.teacherId = teacherId;
    }
}
