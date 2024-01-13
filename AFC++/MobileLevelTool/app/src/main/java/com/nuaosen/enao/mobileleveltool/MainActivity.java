package com.nuaosen.enao.mobileleveltool;

import androidx.appcompat.app.AppCompatActivity;

import android.hardware.Sensor;
import android.hardware.SensorEvent;
import android.hardware.SensorEventListener;
import android.hardware.SensorManager;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener, SensorEventListener {

    private Button btn_hold,btn_reset;
    private ImageView btn_back;
    private ImageView ball_x,ball_y,ball,bg_ball;
    private SensorManager sensorManager;
    private final float[] accelerometerReading = new float[3];
    private final float[] magnetometerReading = new float[3];

    private final float[] rotationMatrix = new float[9];
    private final float[] orientationAngles = new float[3];
    private final String TAG = "[MobileLevelTool]";
    private int radius = 0;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        sensorManager= (SensorManager) getSystemService(SENSOR_SERVICE);

        setContentView(R.layout.activity_main);
        initView();
    }
    void initView(){
//        btn_adjust=findViewById(R.id.btn_adjust);
        btn_back=findViewById(R.id.btn_back);
        btn_hold=findViewById(R.id.btn_hold);
        btn_reset=findViewById(R.id.btn_reset);
//        btn_adjust.setOnClickListener(this);
        btn_back.setOnClickListener(this);
        btn_hold.setOnClickListener(this);
        btn_reset.setOnClickListener(this);
        ball_x=findViewById(R.id.ball_x);
        ball_y=findViewById(R.id.ball_y);
        ball=findViewById(R.id.ball);
        bg_ball=findViewById(R.id.bg_ball);
    }
    @Override
    protected void onResume() {
        super.onResume();

        Sensor accelerometer = sensorManager.getDefaultSensor(Sensor.TYPE_ACCELEROMETER);
        if (accelerometer != null) {
            sensorManager.registerListener(this, accelerometer,
                    SensorManager.SENSOR_DELAY_NORMAL, SensorManager.SENSOR_DELAY_UI);
        }
        Sensor magneticField = sensorManager.getDefaultSensor(Sensor.TYPE_MAGNETIC_FIELD);
        if (magneticField != null) {
            sensorManager.registerListener(this, magneticField,
                    SensorManager.SENSOR_DELAY_NORMAL, SensorManager.SENSOR_DELAY_UI);
        }

    }

    @Override
    protected void onPause() {
        super.onPause();
        // Don't receive any more updates from either sensor.
        sensorManager.unregisterListener(this);
    }
    @Override
    public void onClick(View v) {
        if(v.getId()==R.id.btn_back){
            finish();
        }
        if(v.getId()==R.id.btn_hold){
            isHold =false;
        }
        if(v.getId()==R.id.btn_reset){
            ball_x.setTranslationX(0);
            ball_y.setTranslationY(0);
            speed =0.1f;
            isHold = true;
            ball.setTranslationY(0);
            ball.setTranslationX(0);
        }
    }

    @Override
    public void onSensorChanged(SensorEvent event) {
        if (event.sensor.getType() == Sensor.TYPE_ACCELEROMETER) {
            System.arraycopy(event.values, 0, accelerometerReading,
                    0, accelerometerReading.length);
        } else if (event.sensor.getType() == Sensor.TYPE_MAGNETIC_FIELD) {
            System.arraycopy(event.values, 0, magnetometerReading,
                    0, magnetometerReading.length);
        }
        updateOrientationAngles();
    }
    private boolean isHold = true;
    public void updateOrientationAngles() {
        // Update rotation matrix, which is needed to update orientation angles.
        SensorManager.getRotationMatrix(rotationMatrix, null,
                accelerometerReading, magnetometerReading);
        // "mRotationMatrix" now has up-to-date information.
        SensorManager.getOrientation(rotationMatrix, orientationAngles);
        //Log.d(TAG, "updateOrientationAngles: "+orientationAngles[0]+" "+orientationAngles[1]+" "+orientationAngles[2]);
        // "mOrientationAngles" now has up-to-date information.
        if(isHold)
            setAngle(orientationAngles[2],orientationAngles[1]);
    }
    @Override
    public void onAccuracyChanged(Sensor sensor, int i) {

    }
    private float speed =0.1f;
    void setAngle(float angleX,float angleY){
        radius =((bg_ball.getWidth()-ball.getWidth())/2);
        //Log.d(TAG, "setAngle: "+(int)(Math.toDegrees(angleX))+" "+(int)(Math.toDegrees(angleY))+" "+radius);
        float delX = speed*(int)(Math.toDegrees(angleX));
        float delY = -(speed*(int)(Math.toDegrees(angleY)));
        if(Math.abs(delY)<radius&&Math.abs(delX)<radius){
            ball.setTranslationY(delY);
            ball.setTranslationX(delX);
            ball_x.setTranslationX(delX);
            ball_y.setTranslationY(delY);
        }else {
            speed=0f;
        }
        speed+=0.1;
    }
    private float[] convertCoordinate(double rollAngle, double pitchAngle, double radius){
        double scale = radius / Math.toRadians(90);

        //以圆心为原点，使用弧度表示坐标
        double x0 = -(rollAngle * scale);
        double y0 = -(pitchAngle * scale);

        //使用屏幕坐标表示气泡点
        double x = ball.getX() - x0;
        double y = ball.getY() - y0;

        return new float[]{(float)x, (float)y};
    }
}