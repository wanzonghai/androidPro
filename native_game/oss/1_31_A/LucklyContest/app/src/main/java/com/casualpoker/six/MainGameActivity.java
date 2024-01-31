package com.casualpoker.six;

import android.content.Intent;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Random;

import androidx.appcompat.app.AppCompatActivity;


public class MainGameActivity extends AppCompatActivity {

    private int playerScore = 0;
    private int aiScore = 0;
    private int round = 1;

    private TextView textViewPlayerScore,textViewRound;
    private ImageView imageViewPlayerCard1, imageViewAICard1;
    private Button buttonCompare, buttonBack;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main_game);
        // 初始化界面元素
        textViewPlayerScore = findViewById(R.id.textViewPlayerScore);
        textViewRound = findViewById(R.id.textViewRound);
        imageViewPlayerCard1 = findViewById(R.id.imageViewPlayerCard1);

        imageViewAICard1 = findViewById(R.id.imageViewAICard1);

        buttonCompare = findViewById(R.id.buttonCompare);
        buttonBack = findViewById(R.id.buttonBack);

        // 设置比牌按钮点击事件
        buttonCompare.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 模拟玩家与AI对战，判断玩家是否胜利
                if (playerWins()) {
                    playerScore += 100;
                    // 显示胜利提示
                    showToast("Player Win!");
                } else {
                    aiScore += 100;
                    // 显示胜利提示
                    showToast("Robot Win!");
                }

                // 更新轮数
                round++;

                // 更新积分显示
                updateScoreDisplay();

                // 重新发牌，这里需要实现牌的发放逻辑
                dealCards();
            }
        });
        // 设置返回按钮点击事件
        buttonBack.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // 返回到加载界面
                Intent intent = new Intent(MainGameActivity.this, StartActivity.class);
                startActivity(intent);
                finish(); // 关闭当前活动
            }
        });
        // 初始发牌
        dealCards();
    }

    // 模拟玩家与AI对战，判断玩家是否胜利
    private boolean playerWins() {
        // 实现德州扑克的比较逻辑，这里简单模拟玩家胜利
        return true;
    }

    // 更新积分显示
    private void updateScoreDisplay() {
        textViewPlayerScore.setText("Player Mark: " + playerScore);
        textViewRound.setText( "Round: " + round);
    }

    // 模拟重新发牌
    private void dealCards() {
        // 随机生成牌的示例，实际情况可能需要使用真实的扑克牌
        int playerCard1 = getRandomCard();

        int aiCard1 = getRandomCard();


        // 更新界面上的牌
        imageViewPlayerCard1.setImageResource(getCardImageResource(playerCard1));

        imageViewAICard1.setImageResource(getCardImageResource(aiCard1));

        // 这里需要实现重新发牌的逻辑，更新 imageViewPlayerCard1, imageViewPlayerCard2, imageViewAICard1, imageViewAICard2
    }
    // 随机生成牌的示例
    private int getRandomCard() {
        Random random = new Random();
        return random.nextInt(52) + 1; // 假设有 52 张牌
    }

    // 获取牌的图片资源示例，实际情况需要根据你的资源命名规则进行修改
    private int getCardImageResource(int cardNumber) {
        // 这里需要根据实际资源命名规则获取对应的图片资源
        // 假设你的资源名称是 card_1, card_2, ..., card_52
        String resourceName = "card_" + cardNumber;
        return getResources().getIdentifier(resourceName, "drawable", getPackageName());
    }

    // 添加 showToast 方法
    private void showToast(String message) {
        // 使用 Handler 在主线程中显示 Toast
        new Handler(Looper.getMainLooper()).post(new Runnable() {
            @Override
            public void run() {
                Toast.makeText(MainGameActivity.this, message, Toast.LENGTH_SHORT).show();
            }
        });

        // 在1秒后取消 Toast，模拟提示的消失
        new Handler().postDelayed(new Runnable() {
            @Override
            public void run() {
                Toast.makeText(MainGameActivity.this, "", Toast.LENGTH_SHORT).cancel();
            }
        }, 500);
    }
}
