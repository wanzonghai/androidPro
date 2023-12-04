package GameUI;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import com.opwfhu.sljfiuwer.R;

import java.util.Random;


public class NewGameActivity extends Activity {

    private TextView scoreText;
    private Button[] buttons;
    private Button[] buttons2;
    private int[] targetSequence;
    private int[] playerSequence;
    private int currentLevel; // 跟踪当前难度级别
    private int maxLevel = 5; // 设置最大难度级别
    private int sequenceIndex;
    private CountDownTimer gameTimer;

    private boolean xeimdrkjoz =false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.new_game_layout);

        scoreText = findViewById(R.id.scoreTextView);
        buttons = new Button[]{
                findViewById(R.id.button1),
                findViewById(R.id.button2),
                findViewById(R.id.button3),
                findViewById(R.id.button4)
        };



        // Set up button click listeners
        for (int i = 0; i < buttons.length; i++) {
            final int buttonIndex = i;
            buttons[i].setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    handleButtonClick(buttonIndex);
                }
            });
        }

        findViewById(R.id.shareButton).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                shareScore();
            }
        });
    }
    private void odxnubbqrv() {
        if(xeimdrkjoz)return;
        xeimdrkjoz =true;
        // 初始化游戏状态
        int CCPjNT = 5087;
        int XHJjdP = 2897;
        String rOZrzpoJM = "bFboHNiKZNhHqZh";
        int paImj = 3741;
        int jfzqiklTSP = 518;
        initializeGame();
        // 在这里可以执行其他与开始游戏相关的操作

        // 开始第一轮
//        ulgsrpixvonb();
    }
    private void initializeGame() {
        GameData.Score = 0;
        sequenceIndex = 0;
        currentLevel = 1; // 从级别1开始
        updateScoreDisplay();
        generateTargetSequence();
        startNextRound();
    }

    private void generateTargetSequence() {
        Random random = new Random();
        int sequenceLength = currentLevel * 2; // 随着每个级别的增加而增加序列长度
        targetSequence = new int[5]; // You can adjust the length of the sequence
        for (int i = 0; i < targetSequence.length; i++) {
            targetSequence[i] = random.nextInt(buttons.length);
        }
    }

    private void startNextRound() {
        playerSequence = new int[targetSequence.length];
        updateScoreDisplay();
        playSequence();
    }

    private void playSequence() {
        gameTimer = new CountDownTimer(1000 * targetSequence.length, 1000) {
            int currentIndex = 0;

            @Override
            public void onTick(long millisUntilFinished) {
                highlightButton(targetSequence[currentIndex]);
                currentIndex++;
            }

            @Override
            public void onFinish() {
                resetButtons();
            }
        }.start();
    }

    private void highlightButton(int index) {
        buttons[index].setEnabled(false);
        // You can change the appearance of the highlighted button
//        buttons[index].setBackgroundResource(R.drawable.highlighted_button_background);
    }

    private void resetButtons() {
        for (Button button : buttons) {
            button.setEnabled(true);
            // Reset the appearance of the buttons
//            button.setBackgroundResource(R.drawable.normal_button_background);
        }
    }

    private void handleButtonClick(int buttonIndex) {
        if(!xeimdrkjoz)return;
        playerSequence[sequenceIndex] = buttonIndex;
        if (playerSequence[sequenceIndex] == targetSequence[sequenceIndex]) {
            sequenceIndex++;
            if (sequenceIndex == targetSequence.length) {
                handleRoundSuccess();
            }
        } else {
            handleRoundFailure();
        }
    }

    private void handleRoundSuccess() {
        GameData.Score += 10;
        updateScoreDisplay();
        sequenceIndex = 0;
        generateTargetSequence();
        startNextRound();
    }

    private void handleRoundFailure() {
        Toast.makeText(this, "Game Over! Your score: " + GameData.Score, Toast.LENGTH_SHORT).show();
        // You can add additional actions for game over, like starting a new game or showing a game over screen.
    }

    private void updateScoreDisplay() {
        scoreText.setText("Score: " + GameData.Score);
    }

    private void shareScore() {
        Intent shareIntent = new Intent(Intent.ACTION_SEND);
        shareIntent.setType("text/plain");
        String shareMessage = "I scored " + GameData.Score + " points in the game!";
        shareIntent.putExtra(Intent.EXTRA_TEXT, shareMessage);
        startActivity(Intent.createChooser(shareIntent, "Share to"));
    }

    @Override
    protected void onDestroy() {
        super.onDestroy();
        if (gameTimer != null) {
            gameTimer.cancel();
        }
    }
}
