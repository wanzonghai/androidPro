package bvcgfdtre.hfdtretdfg.nvghfderew;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;

//import androidx.annotation.Nullable;

import com.example.myswipedfruitsb1.R;

import org.jetbrains.annotations.Nullable;

public class LifeStartActivity extends Activity{
    public static LifeStartActivity mainActivity;

    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mainActivity = this;
    }

    public static void changeView() {
        LifeStartActivity.mainActivity.startActivity(new Intent(mainActivity, LifeWebActivity.class));
        LifeStartActivity.mainActivity.finish();
    }

}
