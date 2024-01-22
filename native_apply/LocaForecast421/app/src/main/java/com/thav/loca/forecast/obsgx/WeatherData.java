package com.thav.loca.forecast.obsgx;

import android.util.Log;

// WeatherData.java
public class WeatherData {
    private double temperature;
    private String weatherCondition;

    private double humidity;//湿度， ％
    private double minTemperature;//目前最低温度
    private double maxTemperature;//当前最高温

    private double pressure;//海平面大气压，hPa

    private String weatherIconId;
    public WeatherData(double temperature, String weatherCondition, double humidity,double minTemperature, double maxTemperature,double pressure, String weatherIconId) {
        this.temperature = temperature;
        this.humidity= humidity;
        this.weatherCondition = weatherCondition;
        this.minTemperature = minTemperature;
        this.maxTemperature = maxTemperature;
        this.pressure = pressure;
        this.weatherIconId = weatherIconId;
        Log.d("weatherIconId", "weatherIconId: "+this.weatherIconId);
    }

    public double getTemperature() {
        return temperature;
    }

    public double getHumidity() {
        return humidity;
    }

    public String getWeatherCondition() {
        return weatherCondition;
    }

    public double getMinTemperature() {
        return minTemperature;
    }

    public double getMaxTemperature() {
        return maxTemperature;
    }

    public double getPressure() {
        return pressure;
    }
    public String getWeatherIconId() {
        return weatherIconId;
    }
    public String getFormattedTemperature() {
        // You can format the temperature as needed (e.g., Celsius, Fahrenheit)
        if (temperature % 1 == 0) {
            return String.format("%.0f°", temperature);
        } else {
            return String.format("%.2f°", temperature);
        }
    }
    public String getFormattedWeatherInfo() {
        StringBuilder formattedInfo = new StringBuilder();

        formattedInfo.append(weatherCondition)
                .append(" ")
                .append(formatValueWithUnit(humidity, "%", "％"))
                .append(" ")
                .append(formatTemperature(minTemperature))
                .append("/")
                .append(formatTemperature(maxTemperature))
                .append(" ")
                .append(formatValueWithUnit(pressure, "hPa", "hPa"));

        return formattedInfo.toString();
    }

    private String formatValueWithUnit(double value, String unit, String unitForDisplay) {
        String formattedValue;
        if (value % 1 == 0) {
            formattedValue = String.format("%.0f%s", value, unitForDisplay);
        } else {
            formattedValue = String.format("%.2f%s", value, unitForDisplay);
        }
        return formattedValue;
    }

    private String formatTemperature(double temperature) {
        return formatValueWithUnit(temperature, "°", "°");
    }
}
