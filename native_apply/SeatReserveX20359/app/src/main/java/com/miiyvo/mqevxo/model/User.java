package com.miiyvo.mqevxo.model;

import java.io.Serializable;

public class User implements Serializable {
    private int userId;
    private String username;
    private String password; // 实际中应该使用哈希存储
    private String email;
    private String role;

    private int age;
    private String contact;
    private String department;

    // 构造函数

    // 用于登录的构造函数
    public User() {
    }

    // 构造函数
    public User(int userId, String username, String password, String email, String role) {
        this.userId = userId;
        this.username = username;
        this.password = password; // 防止引用泄露
        this.email = email;
        this.role = role;
    }


    // Getter 和 Setter 方法
    public int getUserId() {
        return userId;
    }

    public void setUserId(int userId) {
        this.userId = userId;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password; // 防止引用泄露
    }

    public void setPassword(String password) {
        // 实际中应该使用哈希存储密码
        this.password = password;;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getRole() {
        return role;
    }

    public void setRole(String role) {
        this.role = role;
    }

    public int getAge() {
        return age;
    }
    public void setAge(int age) {
        this.age= age;
    }
    public String getContact() {
        return contact;
    }
    public void setContact(String contact) {
        this.contact= contact;
    }
    public String getDepartment() {
        return department;
    }
    public void setDepartment(String department) {
        this.department= department;
    }

    // toString 方法，方便调试
    @Override
    public String toString() {
        return "User{" +
                "userId=" + userId +
                ", username='" + username + '\'' +
                ", password='" + password + '\'' +
                ", email='" + email + '\'' +
                ", role='" + role + '\'' +
                '}';
    }
}
