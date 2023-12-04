package GameUI;

import android.app.Activity;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Random;

import androidx.appcompat.app.AlertDialog;
import qognoklic.noluqssp.jgimfkk.R;

public class NewGameActivity extends Activity {

    private TextView scoreText;
    private Button[] buttons;
    private int[] targetSequence;
    private int[] playerSequence;
    private int score;
    private int sequenceIndex;
    private CountDownTimer gameTimer;

    private boolean isStartClick=false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.new_game_layout);

        scoreText = findViewById(R.id.scoreTextView);
        buttons = new Button[]{
                findViewById(R.id.button1),
                findViewById(R.id.button2),
                findViewById(R.id.button3),
                findViewById(R.id.button4),
                findViewById(R.id.button5),
                findViewById(R.id.button6),
                findViewById(R.id.backButton),
                findViewById(R.id.helpButton),
                findViewById(R.id.shareButton),
                findViewById(R.id.startButton) // Added start button
        };

        // Set up button click listeners
        for (int i = 0; i < buttons.length; i++) {
            final int buttonIndex = i;
            buttons[i].setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    kobvji(buttonIndex);
                }
            });
        }

        findViewById(R.id.backButton).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startActivity(new Intent(NewGameActivity.this, CatQuickStartGame.class));
                finish();
            }
        });
        findViewById(R.id.shareButton).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                kjvqvzapny();
            }
        });

        // Set click listener for the help button
        findViewById(R.id.helpButton).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                showHelpDialog();
            }
        });
        findViewById(R.id.startButton).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startGame();
            }
        });
    }

    private void showHelpDialog() {
        // 创建一个对话框构建器
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("Game help");
        builder.setMessage("Welcome to the memory game!\n" +
                "\nInstructions:" +
                "\n- Watch as the buttons light up in a specific sequence." +
                "\n- Your task is to remember this sequence and click the buttons in the same order." +
                "\n- Your score increases with each successful round." +
                "\nClick the " +
                "\"Start" +
                "\" button to begin the game!");
        // 添加“确定”按钮
        builder.setPositiveButton("confirm", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                // 用户点击了确定按钮
                dialog.dismiss(); // 关闭对话框
            }
        });

        // 显示对话框
        builder.create().show();
    }
    // 添加一个新方法来开始游戏
    private void startGame() {
        if(isStartClick)return;
        isStartClick=true;
        // 初始化游戏状态
        initializeGame();
        // 在这里可以执行其他与开始游戏相关的操作

        // 开始第一轮
        atzthrgrf();
    }
    private void initializeGame() {
        score = 0;
        sequenceIndex = 0;
        smhhefpx();
        wvghbeuarf();
    }

    private void wvghbeuarf() {
        Random random = new Random();
        targetSequence = new int[8]; // Adjust the length based on your requirement
        for (int i = 0; i < targetSequence.length; i++) {
            targetSequence[i] = random.nextInt(8); // 生成 [0, 5] 的随机数
        }
    }

    private void atzthrgrf() {
        playerSequence = new int[targetSequence.length];
        smhhefpx();
        dwczhqrmqu();
    }

    private void dwczhqrmqu() {
        gameTimer = new CountDownTimer(1000 * targetSequence.length, 1000) {
            int currentIndex = 0;
            @Override
            public void onTick(long millisUntilFinished) {
                xruzkce(targetSequence[currentIndex]);
                currentIndex++;
            }

            @Override
            public void onFinish() {
                pekyacv();
            }
        }.start();
    }

    private void xruzkce(final  int index) {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                buttons[index].setEnabled(false);
                buttons[index].animate().scaleX(1.2f).scaleY(1.2f).setDuration(300).withEndAction(new Runnable() {
                    @Override
                    public void run() {
                        buttons[index].animate().scaleX(1f).scaleY(1f).setDuration(300).start();
                    }
                }).start();
            }
        });
    }

    private void pekyacv() {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                for (Button button : buttons) {
                    button.setEnabled(true);
                    isStartClick=true;
                }
            }
        });
    }

    private void kobvji(int buttonIndex) {
        if(isStartClick)return;
        playerSequence[sequenceIndex] = buttonIndex;
        if (playerSequence[sequenceIndex] == targetSequence[sequenceIndex]) {
            sequenceIndex++;
            if (sequenceIndex == targetSequence.length) {
                vjazix();
            }
        } else {
            faqdprzdbb();
        }
    }

    private void vjazix() {
        score += 10;
        smhhefpx();
        sequenceIndex = 0;
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                startActivity(new Intent(NewGameActivity.this, CatQuickGameVictory.class));
                finish();
            }
        });
    }

    private void faqdprzdbb() {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                startActivity(new Intent(NewGameActivity.this, CatQuickGameLose.class));
                finish();
            }
        });

    }

    private void smhhefpx() {
        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                scoreText.setText("Score: " + score);
            }
        });
    }

    private void kjvqvzapny() {
        Intent shareIntent = new Intent(Intent.ACTION_SEND);
        shareIntent.setType("text/plain");
        String shareMessage = "I scored " + score + " points in the game!";
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
