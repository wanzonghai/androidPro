package GameUI;

import android.app.Activity;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.view.View;

import android.widget.Button;
import android.widget.EditText;
import android.widget.GridLayout;
import android.widget.TextView;
import android.widget.Toast;


import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import com.opwfhu.sljfiuwer.R;

import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Random;
import java.util.Scanner;

import androidx.appcompat.app.AlertDialog;

public class answerQuestionGameActivity extends Activity {

    private TextView scoreTextView;
    private TextView timerTextView;
    private TextView questionTextView;
    private EditText answerEditText;
    private Button submitAnswerButton;
    private Button startButton;
    private Button [] buttons;

    private GridLayout gridLayout;
    private CountDownTimer gameTimer;
    private static final long MAX_GAME_DURATION = 60000; // 游戏持续时间上限：60秒
    private long currentGameDuration; // 当前游戏持续时间
    private List<Question> questions = new ArrayList<>();
    private int currentQuestionIndex = 0;
    private boolean isStartGame =false;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.answer_question_game_layout);


        scoreTextView = findViewById(R.id.scoreTextView);
        timerTextView= findViewById(R.id.timerTextView);
        questionTextView=findViewById(R.id.questionTextView);
        answerEditText=findViewById(R.id.answerEditText);
        submitAnswerButton=findViewById(R.id.submitAnswerButton);
        startButton = findViewById(R.id.startButton);

        submitAnswerButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                handleSubmitButtonClick();
            }
        });
        startButton.setVisibility(View.VISIBLE);
        buttons = new Button[]{
                findViewById(R.id.shareButton),
                findViewById(R.id.backButton),
                findViewById(R.id.helpButton)
        };

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
        initQuestion();
    }
    private void initQuestion(){
        questions.add(new Question("2 + 2 = ?", "4"));
        questions.add(new Question("5 - 3 = ?", "2"));
        questions.add(new Question("4 * 6 = ?", "24"));
        questions.add(new Question("8 / 2 = ?", "4"));
        questions.add(new Question("9 + 7 = ?", "16"));
//        String jsonString = loadJSONFromAsset("questions.json");
//
//        try {
//            JSONArray jsonArray = new JSONArray(jsonString);
//            for (int i = 0; i < jsonArray.length(); i++) {
//                JSONObject jsonObject = jsonArray.getJSONObject(i);
//                String questionText = jsonObject.getString("question");
//                String correctAnswer = jsonObject.getString("answer");
//
//                questions.add(new Question(questionText, correctAnswer));
//            }
//        } catch (JSONException e) {
//            e.printStackTrace();
//        }

    }

    private String loadJSONFromAsset(String fileName) {
        String json;
        try {
            InputStream is = getAssets().open(fileName);
            Scanner scanner = new Scanner(is).useDelimiter("\\A");
            json = scanner.hasNext() ? scanner.next() : "";
            scanner.close();
            is.close();
        } catch (IOException e) {
            e.printStackTrace();
            return null;
        }
        return json;
    }
    private void startGame() {
        GameData.Score = 0;
        currentQuestionIndex = 0;
        initQuestion();
        showNextQuestion();
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
    private void showNextQuestion() {
        Question currentQuestion = questions.get(currentQuestionIndex);
        questionTextView.setText("Question: " + currentQuestion.getQuestionText());
        if (currentQuestionIndex < questions.size()) {
            currentQuestionIndex++;
        }else {
            currentQuestionIndex=0;
        }
    }
    private void handleSubmitButtonClick() {
        if (!isStartGame) {
            runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    Toast.makeText(answerQuestionGameActivity.this, "Please click Start game !", Toast.LENGTH_SHORT).show();
                }
            });
            return;
        }
        // 获取玩家的回答
        String userAnswer = answerEditText.getText().toString().trim();
        // 检查答案是否正确，这里简单处理，实际可以更复杂
        if (checkAnswer(userAnswer)) {
            GameData.Score++;
        } else {
            // 提示回答错误，可以根据需要添加额外的逻辑
            runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    Toast.makeText(answerQuestionGameActivity.this, "That's the wrong answer !", Toast.LENGTH_SHORT).show();
                }
            });
            if(GameData.Score>0){
                GameData.Score--;
            }
        }
        showNextQuestion();
        // 清空答案输入框
        answerEditText.setText("");
        updateScoreDisplay();
        initQuestion();
    }
    private boolean checkAnswer(String userAnswer) {
        // 这里简单处理，实际可以根据问题设置正确答案
        String correctAnswer = getCorrectAnswer();
        return userAnswer.equals(correctAnswer);
    }

    private String getCorrectAnswer() {
        if (currentQuestionIndex - 1 >= 0 && currentQuestionIndex - 1 < questions.size()) {
            return questions.get(currentQuestionIndex - 1).getCorrectAnswer();
        }
        return "";
    }
    private void updateScoreDisplay() {
        scoreTextView.setText("Mark: " + GameData.Score);
    }

    private void endGame() {
        gameTimer.cancel();

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
                startActivity(new Intent(answerQuestionGameActivity.this, CatQuickGameVictory.class));
                finish();
            }
        });
    }

    private void quickCatfvdgtrgtgfh() {

        runOnUiThread(new Runnable() {
            @Override
            public void run() {
                startActivity(new Intent(answerQuestionGameActivity.this, CatQuickGameLose.class));
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
                startActivity(new Intent(answerQuestionGameActivity.this, CatQuickStartGame.class));
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

}
