package GameUI;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import com.opwfhu.sljfiuwer.R;

import java.util.Random;

import androidx.annotation.Nullable;


public class CatQuickGameGame extends Activity {
    ImageView quickCat_img1;  //
    ImageView quickCat_img2;
    ImageView quickCat_img3;

    ImageView quickCat_img4;
    ImageView quickCat_img5;
    ImageView quickCat_img6;

    ImageView shareBtn;

    TextView scoreText;
    TextView timeText;

    private Handler handler = new Handler();
    private Runnable timerRunnable;
    private int remainingTime;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.catquicik_layout);



        // Set your test devices. Check your logcat output for the hashed device ID to
        // get test ads on a physical device. e.g.
        // "Use RequestConfiguration.Builder().setTestDeviceIds(Arrays.asList("ABCDEF012345"))
        // to get test ads on this device."



        quickCat_img1 = findViewById(R.id.catqucik_img2);
        quickCat_img2 = findViewById(R.id.catqucik_img1);
        quickCat_img3 = findViewById(R.id.catqucik_img3);

        quickCat_img4 = findViewById(R.id.catqucik_btn2);
        quickCat_img5 = findViewById(R.id.catqucik_btn1);
        quickCat_img6 = findViewById(R.id.catqucik_btn3);


        scoreText =findViewById(R.id.scoreTextView);
        timeText = findViewById(R.id.timerTextView);

        quickCat_img4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (quickCat_index1 == -1) {
                    quickCat_img1.setImageResource(quickCatfdhbgbvc(0));
                    quickCat_index1 = 1;
                    quickCatgddre();
                }
            }
        });

        quickCat_img5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (quickCat_index2 == -1) {
                    quickCat_img2.setImageResource(quickCatfdhbgbvc(1));
                    quickCat_index2 = 1;
                    quickCatgddre();
                }
            }
        });

        quickCat_img6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (quickCat_index3 == -1) {
                    quickCat_img3.setImageResource(quickCatfdhbgbvc(2));
                    quickCat_index3 = 1;
                    quickCatgddre();
                }
            }
        });

        findViewById(R.id.catqucik_btn).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {

                startActivity(new Intent(CatQuickGameGame.this, CatQuickStartGame.class));
                finish();
            }
        });

        findViewById(R.id.shareButton).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                    shareScore();
            }
        });

        quickCathtrfghfg(quickCat_numlist1);
        //Initialize the score display
        if (scoreText != null && timeText != null) {
            updateScoreDisplay();
            // 生成随机的总时间（范围为10到60秒）
            int randomTotalTime = new Random().nextInt(51) + 10;
            updateTimerDisplay(randomTotalTime);
            startTimer(randomTotalTime);
        } else {
            Log.e("CatQuickGameGame", "scoreTextView is null");
        }

    }
    private int quickCat_index1 = -1;
    private int quickCat_index2 = -1;
    private int quickCat_index3 = -1;

    public int[] quickCat_numlist1 = {1, 2, 3};


    public void quickCatgddre() {
        if (quickCat_index2 == 1 && quickCat_index1 == 1 && quickCat_index3 == 1) {
            quickCatcfdtregfd();
        }
    }

    private void quickCatcfdtregfd() {
        Handler cleverTiger_dgfdder = new Handler();
        cleverTiger_dgfdder.postDelayed(new Runnable() {
            @Override
            public void run() {
                // 在这里执行你想要延迟执行的操作
                quickCatbvcbfgdr();
                startNextLevel();  // 进入下一关
            }
        }, 2390); // 2000毫秒（2秒）延迟
    }

    @Override
    protected void onPause() {
        super.onPause();

    }

    @Override
    protected void onResume() {
        super.onResume();

    }

    @Override
    protected void onDestroy() {
        super.onDestroy();

    }


    private void quickCatbvcbfgdr() {
        // 在这里实现改变图片背景的操作
        quickCat_img3.setImageResource(R.drawable.r3);
        quickCat_img2.setImageResource(R.drawable.r3);
        quickCat_img1.setImageResource(R.drawable.r3);
        quickCat_index3 = -1;
        quickCat_index2 = -1;
        quickCat_index1 = -1;
        quickCathtrfghfg(quickCat_numlist1);
    }

    public static void quickCathtrfghfg(int[] arr) {
        int quickCatbfdgdfrt = arr.length;
        Random quickCatbvfvccf = new Random();
        for (int i = 0; i < quickCatbfdgdfrt; i++) {
            // 生成一个随机索引，范围在 [i, n)
            int quickCatbgfgfhfg = i + quickCatbvfvccf.nextInt(quickCatbfdgdfrt - i);
            // 交换元素
            int quickCatbgfhtrhfd = arr[i];
            arr[i] = arr[quickCatbgfgfhfg];
            arr[quickCatbgfgfhfg] = quickCatbgfhtrhfd;
        }
    }

    public void quickCatvfdhgdtre() {
        increaseScore();
        startActivity(new Intent(this, CatQuickGameVictory.class));
        finish();
    }

    public void quickCatfvdgtrgtgfh() {
        decreaseScore();
        startActivity(new Intent(this, CatQuickGameLose.class));
        finish();
    }

    public int quickCatfdhbgbvc(int index) {
        final int i = quickCat_numlist1[index];//random.nextInt(max_value - min_value + 1) + min_value;
        Handler cleverTiger_bbvcrfge = new Handler();
        cleverTiger_bbvcrfge.postDelayed(new Runnable() {
            @Override
            public void run() {
                if (i == 3) {
                    quickCatvfdhgdtre();
                } else {
                    quickCatfvdgtrgtgfh();
                }
            }
        }, 2180); // 2000毫秒（2秒）延迟

        Handler quickCatgfdhbgdgfd = new Handler();
        quickCatgfdhbgdgfd.postDelayed(new Runnable() {
            @Override
            public void run() {
                quickCat_img1.setImageResource(quickCatbfggfdf(0));
                quickCat_img2.setImageResource(quickCatbfggfdf(1));
                quickCat_img3.setImageResource(quickCatbfggfdf(2));
            }
        }, 2080); // 2000毫秒（2秒）延迟

        quickCat_img4.setVisibility(View.GONE);
        quickCat_img5.setVisibility(View.GONE);
        quickCat_img6.setVisibility(View.GONE);

        if (i == 1) {
            return R.drawable.r2;
        } else if (i == 2) {
            return R.drawable.r2;
        } else if (i == 3) {
            return R.drawable.r1;
        }
        return R.drawable.r3;
    }


    public int quickCatbfggfdf(int index) {
        int quickCatBFGFDSD = quickCat_numlist1[index];//random.nextInt(max_value - min_value + 1) + min_value;
        if (quickCatBFGFDSD == 1) {
            return R.drawable.r2;
        } else if (quickCatBFGFDSD == 2) {
            return R.drawable.r2;
        } else if (quickCatBFGFDSD == 3) {
            return R.drawable.r1;
        }
        return R.drawable.r3;
    }

    // Call this method to add points when you win
    private void increaseScore() {
        GameData.Score += 10* quickCat_numlist1.length;
        updateScoreDisplay();
    }
    // Call this method on failure to reduce the score
    private void decreaseScore() {
        GameData.Score -= 5;
        if (GameData.Score < 0) {
            GameData.Score = 0;
        }
        updateScoreDisplay();
    }
    // Update the scoring display
    private void updateScoreDisplay() {
        scoreText.setText("" + GameData.Score);
    }

    private void startTimer(int randomTotalTime){
        remainingTime = randomTotalTime;

        timerRunnable = new Runnable() {
            @Override
            public void run() {
                if (remainingTime > 0) {
                    updateTimerDisplay(remainingTime * 1000); // 更新UI显示剩余时间，单位是毫秒
                    remainingTime--;
                    handler.postDelayed(this, 1000); // 1秒后再次执行
                } else {
                    quickCatfvdgtrgtgfh(); // 计时结束时的操作
                }
            }
        };

        handler.post(timerRunnable);
    }
    private void startNextLevel() {
        quickCat_numlist1 = generateNewCatList();  // 生成新的猫咪列表
        quickCathtrfghfg(quickCat_numlist1);
    }

    private int[] generateNewCatList() {
        // 生成新的猫咪列表，可以根据需要调整生成逻辑
        int[] newList = {1, 2, 3};
        quickCathtrfghfg(newList);
        return newList;
    }

    private void updateTimerDisplay(long millisUntilFinished) {
        if (timeText != null) {
            timeText.setText("Time left: " + millisUntilFinished / 1000 + " s");
        }
    }


    private void stopTimer() {
        handler.removeCallbacks(timerRunnable);
    }

    private void shareScore() {
        Intent shareIntent = new Intent(Intent.ACTION_SEND);
        shareIntent.setType("text/plain");
        String shareMessage = "I scored " + GameData.Score + " points in the game !" ;
        shareIntent.putExtra(Intent.EXTRA_TEXT, shareMessage);
        startActivity(Intent.createChooser(shareIntent, "分享到"));

    }

}