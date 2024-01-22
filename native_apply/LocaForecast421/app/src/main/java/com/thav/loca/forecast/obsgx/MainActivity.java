package com.thav.loca.forecast.obsgx;

import androidx.annotation.NonNull;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import android.Manifest;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.drawable.Drawable;
import android.location.Address;
import android.location.Geocoder;
import android.location.Location;
import android.location.LocationManager;
import android.os.AsyncTask;
import android.os.Bundle;
import android.os.Handler;
import android.provider.Settings;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import com.google.android.gms.common.api.Status;
import com.google.android.libraries.places.api.model.Place;
import com.google.android.libraries.places.widget.Autocomplete;
import com.google.android.libraries.places.widget.AutocompleteActivity;
import com.google.android.libraries.places.widget.model.AutocompleteActivityMode;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.Arrays;
import java.util.List;
import java.util.Locale;

public class MainActivity extends AppCompatActivity {

    private static final int REQUEST_LOCATION_PERMISSION = 1;
    private TextView weatherTextView;
    private ImageView backgroundImageView;

    ImageView weatherIconImageView;
    private TextView locationTextView; // Assuming you have a TextView for displaying the selected location
    private TextView detailedWeatherTextView;

    private String key_open_weather = "1cfd75a7551ab7283f3fa6c91ebb8859";

    private boolean isCancelled = false;
    private FetchWeatherTask fetchWeatherTask;  // 添加这一行

    private  Handler handler=null;
    private static final int AUTOCOMPLETE_REQUEST_CODE = 1001;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        weatherTextView = findViewById(R.id.weatherInfoTextView);
        backgroundImageView = findViewById(R.id.backgroundImageView);
        locationTextView = findViewById(R.id.locationTextView);
        detailedWeatherTextView= findViewById(R.id.detailedWeatherTextView);
        weatherIconImageView = findViewById(R.id.weatherIconImageView);
        handler = new Handler();
        // Check location permission
        if (ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION)
                != PackageManager.PERMISSION_GRANTED) {
            // If no permission, request permission
            ActivityCompat.requestPermissions(this,
                    new String[]{Manifest.permission.ACCESS_FINE_LOCATION},
                    REQUEST_LOCATION_PERMISSION);
        } else {
            // If permission granted, get location and weather information

            handler.postDelayed(new Runnable() {
                @Override
                public void run() {
                    // 在这里请求位置信息
                    getLocationAndWeatherInfo();
                }
            }, 2000); // 2000 毫秒的延迟，可以根据需要调整

        }
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions,
                                           @NonNull int[] grantResults) {
        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
        if (requestCode == REQUEST_LOCATION_PERMISSION) {
            if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                // User granted location permission

                handler.postDelayed(new Runnable() {
                    @Override
                    public void run() {
                        // 在这里请求位置信息
                        getLocationAndWeatherInfo();
                    }
                }, 2000); // 2000 毫秒的延迟，可以根据需要调整
            } else {
                // User denied permission request
                Toast.makeText(this, "Location permission denied. Weather data cannot be fetched.",
                        Toast.LENGTH_SHORT).show();
            }
        }
    }

    private void getLocationAndWeatherInfo() {
        // Get location manager
        LocationManager locationManager = (LocationManager) getSystemService(Context.LOCATION_SERVICE);
        String locationProvider = LocationManager.GPS_PROVIDER;

        if (ActivityCompat.checkSelfPermission(this, Manifest.permission.ACCESS_FINE_LOCATION)
                == PackageManager.PERMISSION_GRANTED) {
            // Check for null values
            if (locationManager != null) {
                if (!locationManager.isProviderEnabled(LocationManager.GPS_PROVIDER)) {
                    // 引导用户打开位置服务
                    Intent intent = new Intent(Settings.ACTION_LOCATION_SOURCE_SETTINGS);
                    startActivity(intent);
                } else {
                    Location lastKnownLocation = locationManager.getLastKnownLocation(locationProvider);

                    if (lastKnownLocation != null) {
                        double latitude = lastKnownLocation.getLatitude();
                        double longitude = lastKnownLocation.getLongitude();

                        // Update locationTextView with the address
                        updateLocationTextView(latitude, longitude);

                        // Fetch and display weather information
                        new FetchWeatherTask().execute(latitude, longitude);

                        // Create and execute FetchWeatherTask
                        fetchWeatherTask = new FetchWeatherTask();
                        fetchWeatherTask.execute(latitude, longitude);
                    } else {
                        Toast.makeText(this, "Location not available. Weather data cannot be fetched.",
                                Toast.LENGTH_SHORT).show();
                    }
                }
            } else {
                Toast.makeText(this, "Location manager is null. Weather data cannot be fetched.",
                        Toast.LENGTH_SHORT).show();
            }
        }
    }

    private void updateLocationTextView(double latitude, double longitude) {
        // Use Geocoder to get address from latitude and longitude
        Geocoder geocoder = new Geocoder(this, Locale.getDefault());
        try {
            List<Address> addresses = geocoder.getFromLocation(latitude, longitude, 1);
            if (addresses != null && addresses.size() > 0) {
                // 获取区级地址
                String subLocality = addresses.get(0).getSubLocality();

                // 检查是否有区级信息，如果没有，则使用城市信息
                String address = (subLocality != null && !subLocality.isEmpty()) ? subLocality : addresses.get(0).getLocality();

                locationTextView.setText(address);
            } else {
                locationTextView.setText("Address not found");
            }
        } catch (IOException e) {
            Log.e("LocationUpdate", "Error getting address", e);
            locationTextView.setText("Error getting address");
        }
    }
    private class FetchWeatherTask extends AsyncTask<Double, Void, WeatherData> {

        @Override
        protected WeatherData doInBackground(Double... params) {
            if (isCancelled) {
                return null; // Task is cancelled
            }
            double latitude = params[0];
            double longitude = params[1];

            String apiUrl = "https://api.openweathermap.org/data/2.5/weather?" +
                    "lat=" + latitude + "&lon=" + longitude +
                    "&appid=" + key_open_weather;

            try {
                URL url = new URL(apiUrl);
                HttpURLConnection connection = (HttpURLConnection) url.openConnection();
                BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
                StringBuilder json = new StringBuilder(1024);
                String tmp;
                while ((tmp = reader.readLine()) != null) {
                    json.append(tmp).append("\n");
                }
                reader.close();

                JSONObject data = new JSONObject(json.toString());


                double temperature = extractDouble(data.getJSONObject("main"), "temp") - 273.15;

                String weatherCondition = extractString(data.getJSONArray("weather").getJSONObject(0), "main");
                String weatherIconId = extractString(data.getJSONArray("weather").getJSONObject(0), "icon");
                double humidity = extractDouble(data.getJSONObject("main"), "humidity");
                double minTemperatureKelvin = extractDouble(data.getJSONObject("main"), "temp_min");
                double maxTemperatureKelvin = extractDouble(data.getJSONObject("main"), "temp_max");
                double seaLevel = extractDouble(data.getJSONObject("main"), "pressure");
                double minTemperatureCelsius = minTemperatureKelvin - 273.15;
                double maxTemperatureCelsius = maxTemperatureKelvin - 273.15;

                return new WeatherData(temperature, weatherCondition,humidity, minTemperatureCelsius, maxTemperatureCelsius,seaLevel ,weatherIconId);
            } catch (IOException | JSONException e) {
                Log.e("WeatherApp", "Error fetching weather data", e);
                return null;
            }
        }
        private double extractDouble(JSONObject jsonObject, String key) throws JSONException {
            if (jsonObject.has(key)) {
                return jsonObject.getDouble(key);
            } else {
                Log.e("WeatherApp", "Key not found: " + key);
                return 0.0; // You may want to handle this case differently based on your requirements
            }
        }

        private String extractString(JSONObject jsonObject, String key) throws JSONException {
            if (jsonObject.has(key)) {
                return jsonObject.getString(key);
            } else {
                Log.e("WeatherApp", "Key not found: " + key);
                return ""; // You may want to handle this case differently based on your requirements
            }
        }
        @Override
        protected void onPostExecute(WeatherData result) {
            super.onPostExecute(result);
            if (result != null) {
                final String temperatureText = result.getFormattedTemperature();
                final String weatherInfo = result.getFormattedWeatherInfo();
                final String weatherIconId = result.getWeatherIconId();

                runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        weatherTextView.setText(temperatureText);
                        detailedWeatherTextView.setText(weatherInfo);
                        setWeatherIcon(weatherIconId);
                        setWeatherBackground(result.getTemperature(),result.getWeatherCondition());
                    }
                });
            } else {
                Toast.makeText(MainActivity.this, "Error fetching weather data", Toast.LENGTH_SHORT).show();
            }
        }
    }
    private int getIconResourceId(String weatherIconId) {
        // Assuming the icon IDs follow a naming convention like "01d" or "02n" where
        // the first two characters represent the weather condition and the last character
        // represents the day ("d") or night ("n")

        String iconName = "ic_" + weatherIconId; // Assuming you have icon resources with names like "ic_01d", "ic_02n", etc.

        // Get the resource ID dynamically using the name
        return getResources().getIdentifier(iconName, "drawable", getPackageName());
    }

    private void setWeatherIcon(String weatherIconId) {
        // 根据天气图标 ID 获取相应的资源 ID
        int iconResourceId = getIconResourceId(weatherIconId);


        // 将资源 ID 设置到 ImageView 中
        weatherIconImageView.setImageResource(iconResourceId);
    }
    private void setWeatherBackground(double temperature, String weatherCondition) {
        Drawable backgroundDrawable;
        if ("Rain".equals(weatherCondition) || "Drizzle".equals(weatherCondition)) {
            backgroundDrawable = getResources().getDrawable(R.drawable.rainy_background);
        } else if ("Snow".equals(weatherCondition)) {
            backgroundDrawable = getResources().getDrawable(R.drawable.cold_background);
        } else if ("Clouds".equals(weatherCondition)) {
            backgroundDrawable = getResources().getDrawable(R.drawable.rainy_background);
        } else {
            // If not a specific condition, use temperature to set background
            if (temperature > 30) {
                backgroundDrawable = getResources().getDrawable(R.drawable.hot_background);
            } else if (temperature > 15) {
                backgroundDrawable = getResources().getDrawable(R.drawable.moderate_background);
            } else {
                backgroundDrawable = getResources().getDrawable(R.drawable.cold_background);
            }
        }

        backgroundImageView.setImageDrawable(backgroundDrawable);
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (requestCode == AUTOCOMPLETE_REQUEST_CODE) {
            if (resultCode == RESULT_OK) {
                Place place = Autocomplete.getPlaceFromIntent(data);
                String selectedLocation = place.getName();

                updateUIWithSelectedLocation(selectedLocation);
            } else if (resultCode == AutocompleteActivity.RESULT_ERROR) {
                Status status = Autocomplete.getStatusFromIntent(data);
                Log.e("PlacePicker", status.getStatusMessage());
            } else if (resultCode == RESULT_CANCELED) {
                // User canceled address selection
            }
        }
    }

    private void updateUIWithSelectedLocation(String selectedLocation) {
        locationTextView.setText(selectedLocation);

        handler.postDelayed(new Runnable() {
            @Override
            public void run() {
                // 在这里请求位置信息
                getLocationAndWeatherInfo();
            }
        }, 2000); // 2000 毫秒的延迟，可以根据需要调整
    }
    @Override
    protected void onDestroy() {
        super.onDestroy();
        if (fetchWeatherTask != null) {
            fetchWeatherTask.cancel(true);
        }
    }
}
