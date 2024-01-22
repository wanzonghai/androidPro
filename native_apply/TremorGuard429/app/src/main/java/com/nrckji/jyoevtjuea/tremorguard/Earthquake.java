package com.nrckji.jyoevtjuea.tremorguard;

public class Earthquake {
    private String id;
    private String place;
    private double magnitude;
    private long time;

    public Earthquake() {
        // 默认构造函数
    }

    public Earthquake(String id, String place, double magnitude, long time) {
        this.id = id;
        this.place = place;
        this.magnitude = magnitude;
        this.time = time;
    }

    public String getId() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public String getPlace() {
        return place;
    }

    public void setPlace(String place) {
        this.place = place;
    }

    public double getMagnitude() {
        return magnitude;
    }

    public void setMagnitude(double magnitude) {
        this.magnitude = magnitude;
    }

    public long getTime() {
        return time;
    }

    public void setTime(long time) {
        this.time = time;
    }
}
