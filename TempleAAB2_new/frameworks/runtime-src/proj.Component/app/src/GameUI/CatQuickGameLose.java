package GameUI;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;

import com.opwfhu.sljfiuwer.R;

import androidx.annotation.Nullable;
import grzvx.tzzm.qbwovf.NmrStartActivity;


public class CatQuickGameLose extends Activity {
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.catquicik_lose);
        findViewById(R.id.catquick_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(CatQuickGameLose.this, NmrStartActivity.class));
                finish();
            }
        });
    }
}
