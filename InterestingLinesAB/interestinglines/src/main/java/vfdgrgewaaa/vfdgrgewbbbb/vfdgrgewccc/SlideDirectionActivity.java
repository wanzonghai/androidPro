package vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.widget.TextView;


import interkskhfjvcxv.jkiuyuiiuewtyrfd.nvjkshgfsdruewfdsgsd.R;
import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.vvvnnn.DateUtil;
import vfdgrgewaaa.vfdgrgewbbbb.vfdgrgewccc.vvvwwweee.SingleTouchView;

//小游戏
public class SlideDirectionActivity extends Activity {
    public static SlideDirectionActivity slideDirectionActivity;
    private TextView tv_desc; // 声明一个文本视图对象
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        slideDirectionActivity = this;
        setContentView(R.layout.activity_slide_direction);
        tv_desc = findViewById(R.id.tv_desc);
        SingleTouchView stv_gesture = findViewById(R.id.stv_gesture);
        // 设置单点触摸视图的手势飞掠监听器
        stv_gesture.setFlipListener((beginPos, endPos) -> {
            float offsetX = Math.abs(endPos.x - beginPos.x);
            float offsetY = Math.abs(endPos.y - beginPos.y);
            String gesture = "";
            if (offsetX > offsetY) { // 水平方向滑动
                gesture = (endPos.x - beginPos.x > 0) ? "Right" : "Left";
            } else if (offsetX < offsetY) { // 垂直方向滑动
                gesture = (endPos.y - beginPos.y > 0) ? "Down" : "Up";
            } else { // 对角线滑动
                gesture = "Diagonal";
            }
            String desc = String.format("%s This gesture is %s lide", DateUtil.getNowTime(), gesture);
            tv_desc.setText(desc);
        });

        Handler handler = new Handler();
        handler.postDelayed(new Runnable() {
            @Override
            public void run() {

            }
        }, 5000); // 5000毫秒等于5秒
    }
}