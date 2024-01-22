package com.nrckji.jyoevtjuea.tremorguard;

import java.util.ArrayList;
import java.util.List;

public class MockEarthquakeData {

    public static List<Earthquake> generateMockData() {
        List<Earthquake> earthquakes = new ArrayList<>();

        // 添加模拟的地震数据
        earthquakes.add(new Earthquake("id1", "Location 1", 5.5, System.currentTimeMillis()));
        earthquakes.add(new Earthquake("id2", "Location 2", 6.0, System.currentTimeMillis()));
        // 添加更多地震数据...

        return earthquakes;
    }
}
