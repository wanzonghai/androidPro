package GameUI;

import android.animation.Animator;
import android.animation.AnimatorSet;
import android.animation.ObjectAnimator;
import android.app.Activity;
import android.content.DialogInterface;
import android.content.Intent;

import android.os.Bundle;
import android.os.CountDownTimer;
import android.view.View;

import android.view.animation.DecelerateInterpolator;

import android.widget.Button;
import android.widget.GridLayout;
import android.widget.TextView;
import android.widget.Toast;

import com.opwfhu.sljfiuwer.R;

import java.util.Random;

import androidx.appcompat.app.AlertDialog;

public class SpeedClickGameActivity extends Activity {

    private Button clickButton;
    private TextView scoreTextView;
    private TextView timerTextView;
    private Button startButton;
    private Button [] buttons;

    private GridLayout gridLayout;
    private CountDownTimer gameTimer;
    private static final long MAX_GAME_DURATION = 60000; // 游戏持续时间上限：60秒
    private long currentGameDuration; // 当前游戏持续时间

    private boolean isStartGame =false;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.speed_click_game_layout);

        clickButton = findViewById(R.id.clickButton);
        scoreTextView = findViewById(R.id.scoreTextView);
        timerTextView= findViewById(R.id.timerTextView);
        startButton = findViewById(R.id.startButton);
        gridLayout=findViewById(R.id.gridLayout);

        startButton.setVisibility(View.VISIBLE);
        buttons = new Button[]{
                findViewById(R.id.shareButton),
                findViewById(R.id.backButton),
                findViewById(R.id.helpButton)
        };
        clickButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                handleButtonClick();
            }
        });

        startButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                startGame();
            }
        });

        for (int i = 0; i < buttons.length; i++) {
            final int buttonIndex = i;
            buttons[i].setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View v) {
                    handleButtonClick2(buttonIndex);
                }
            });
        }
        moveMonsterRandomly();
        breatheAnimation();
    }

    private void startGame() {
        GameData.Score = 0;
        updateScoreDisplay();
        // 隐藏开始按钮
        startButton.setVisibility(View.GONE);
        isStartGame=true;
        // 随机生成当前游戏持续时间
        currentGameDuration = getRandomGameDuration();
        updateTimerDisplay();
        gameTimer = new CountDownTimer(currentGameDuration, 1000) {
            @Override
            public void onTick(long millisUntilFinished) {
                // 更新显示剩余时间的UI（例如，在界面上显示一个倒计时文本）
                currentGameDuration = millisUntilFinished;
                updateTimerDisplay();
            }

            @Override
            public void onFinish() {
                endGame();
            }
        }.start();

    }
    private void updateTimerDisplay() {
        long seconds = currentGameDuration / 1000;
        long minutes = seconds / 60;
        seconds = seconds % 60;
        timerTextView.setText("Timer: " + String.format("%02d:%02d", minutes, seconds));
    }

    private long getRandomGameDuration() {
        Random random = new Random();
        return random.nextInt((int) MAX_GAME_DURATION) + 10000; // 生成一个介于10秒到60秒之间的随机时间
    }
    private void handleButtonClick() {
        if(!isStartGame) {
            runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    Toast.makeText(SpeedClickGameActivity.this, "Please click Start game !", Toast.LENGTH_SHORT).show();
                }
            });
            return;
        }
        GameData.Score++;
        updateScoreDisplay();
    }

    private void updateScoreDisplay() {
        scoreTextView.setText("Score: " + GameData.Score);
    }

    private void endGame() {
        gameTimer.cancel();
//        Toast.makeText(this, "Game Over! Your final score: " + GameData.Score, Toast.LENGTH_SHORT).show();

        // 显示开始按钮
        startButton.setVisibility(View.VISIBLE);

        if (GameData.Score >= 100) {
            quickCatvfdhgdtre();
        } else {
            quickCatfvdgtrgtgfh();
        }
    }


    private void quickCatvfdhgdtre() {

        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                startActivity(new Intent(SpeedClickGameActivity.this, CatQuickGameVictory.class));
                finish();
            }
        });
    }

    private void quickCatfvdgtrgtgfh() {

        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                startActivity(new Intent(SpeedClickGameActivity.this, CatQuickGameLose.class));
                finish();
            }
        });
    }
    private void handleButtonClick2(int buttonIndex) {
        if (buttonIndex == 1) {
            onBackButtonClick();
        } else {
            if (buttonIndex == 2) {
                onHelpButtonClick();
            } else {
                onShareButtonClick();
            }
        }

    }
    public void onBackButtonClick() {
        // 返回按钮的点击事件
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("Confirm Exit");
        builder.setMessage("Are you sure you want to exit the game?");
        builder.setPositiveButton("Yes", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                startActivity(new Intent(SpeedClickGameActivity.this, CatQuickStartGame.class));
                finish();
            }
        });
        builder.setNegativeButton("No", new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                // 用户选择不退出，继续游戏
            }
        });
        builder.show();
    }

    public void onShareButtonClick() {
        // 分享按钮的点击事件
        Intent shareIntent = new Intent(Intent.ACTION_SEND);
        shareIntent.setType("text/plain");
        String shareMessage = "I scored " + GameData.Score + " points in the game!";
        shareIntent.putExtra(Intent.EXTRA_TEXT, shareMessage);
        startActivity(Intent.createChooser(shareIntent, "Share to"));
    }

    public void onHelpButtonClick() {
        // 帮助按钮的点击事件
        // 创建一个对话框构建器
        AlertDialog.Builder builder = new AlertDialog.Builder(this);
        builder.setTitle("Game help");
        // 添加显示游戏说明的逻辑，可以通过 Intent 打开一个说明页面
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

        builder.create().show();
    }

    private void moveMonsterRandomly() {
        Random random = new Random();

        int gridLayoutWidth = gridLayout.getWidth();
        int gridLayoutHeight = gridLayout.getHeight();
        int clickButtonWidth = clickButton.getWidth();
        int clickButtonHeight = clickButton.getHeight();

        int minX = 0;
        int maxX = gridLayoutWidth - clickButtonWidth;
        int minY = 0;
        int maxY = gridLayoutHeight - clickButtonHeight;

        int newX = Math.max(minX, Math.min(random.nextInt(maxX + 1), maxX));
        int newY = Math.max(minY, Math.min(random.nextInt(maxY + 1), maxY));

        ObjectAnimator moveX = ObjectAnimator.ofFloat(clickButton, "translationX", newX);
        ObjectAnimator moveY = ObjectAnimator.ofFloat(clickButton, "translationY", newY);

        moveX.setInterpolator(new DecelerateInterpolator());
        moveY.setInterpolator(new DecelerateInterpolator());

        moveX.setDuration(2000);
        moveY.setDuration(2000);

        AnimatorSet moveAnimatorSet = new AnimatorSet();
        moveAnimatorSet.playTogether(moveX, moveY);
        moveAnimatorSet.start();

        moveAnimatorSet.addListener(new Animator.AnimatorListener() {
            @Override
            public void onAnimationStart(Animator animation) {
            }

            @Override
            public void onAnimationEnd(Animator animation) {
                moveMonsterRandomly();
            }

            @Override
            public void onAnimationCancel(Animator animation) {
            }

            @Override
            public void onAnimationRepeat(Animator animation) {
            }
        });
    }
    private void breatheAnimation() {
        ObjectAnimator scaleXAnimator = ObjectAnimator.ofFloat(clickButton, "scaleX", 1.0f, 1.2f, 1.0f);
        ObjectAnimator scaleYAnimator = ObjectAnimator.ofFloat(clickButton, "scaleY", 1.0f, 1.2f, 1.0f);

        AnimatorSet breathAnimatorSet = new AnimatorSet();
        breathAnimatorSet.playTogether(scaleXAnimator, scaleYAnimator);
        breathAnimatorSet.setDuration(1500);

        // Set repeat mode and count on each individual ObjectAnimator
        scaleXAnimator.setRepeatMode(ObjectAnimator.REVERSE);
        scaleYAnimator.setRepeatMode(ObjectAnimator.REVERSE);
        scaleXAnimator.setRepeatCount(ObjectAnimator.INFINITE);
        scaleYAnimator.setRepeatCount(ObjectAnimator.INFINITE);

        breathAnimatorSet.start();
    }

}
