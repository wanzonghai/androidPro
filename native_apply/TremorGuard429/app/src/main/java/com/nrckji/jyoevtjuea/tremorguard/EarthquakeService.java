package com.nrckji.jyoevtjuea.tremorguard;

import retrofit2.Call;
import retrofit2.http.GET;

public interface EarthquakeService {
    @GET("earthquakes/feed/v1.0/summary/all_hour.geojson")
    Call<EarthquakeResponse> getEarthquakes();
}

