package com.nrckji.jyoevtjuea.tremorguard;

import java.util.List;

public class EarthquakeResponse {
    private List<Earthquake> features;
    // 构造函数
    public EarthquakeResponse(List<Earthquake> features) {
        this.features = features;
    }
    public List<Earthquake> getFeatures() {
        return features;
    }

    // 设置地震数据
    public void setFeatures(List<Earthquake> features) {
        this.features = features;
    }
}
