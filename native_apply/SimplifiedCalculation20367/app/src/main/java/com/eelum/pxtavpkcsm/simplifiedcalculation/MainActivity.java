package com.eelum.pxtavpkcsm.simplifiedcalculation;

import android.animation.ValueAnimator;
import android.os.Bundle;
import android.view.View;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.view.animation.ScaleAnimation;
import android.widget.Button;
import android.widget.TextView;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Handler;


import net.objecthunter.exp4j.Expression;
import net.objecthunter.exp4j.ExpressionBuilder;

public class MainActivity extends AppCompatActivity {
    private Handler handler;
    private Runnable breathRunnable;
    private TextView editText;
    private TextView resultText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        editText = findViewById(R.id.editText);
        resultText = findViewById(R.id.resultText);
        handler = new Handler();
        breathRunnable = this::animateTextBreath;

        updateEditText("0");
        updateResultText("");
    }

    public void onButtonClick(View view) {
        // 获取点击的按钮上的文本
        Button button = (Button) view;
        String buttonText = button.getText().toString();

        // 获取当前输入框中的文本
        String currentText = editText.getText().toString();
        // 如果当前文本为零或是错误状态，直接替换为新输入的数字
        if (currentText.equals("0") || currentText.equals("Error")) {
            updateEditText(buttonText);
        } else {
            // 否则，将按钮上的文本添加到当前文本末尾
            updateEditText(currentText + buttonText);
        }
        // 添加按下的闪烁效果
        animateButtonPress(view);

        // 实时更新结果文本
        updateResultOnButtonClick();

    }
    private void animateButtonPress(View view) {
        AlphaAnimation alphaAnimation = new AlphaAnimation(1.0f, 0.5f);
        alphaAnimation.setDuration(100);
        alphaAnimation.setRepeatMode(AlphaAnimation.REVERSE);
        alphaAnimation.setRepeatCount(1);
        view.startAnimation(alphaAnimation);
    }
    public void onEqualClick(View view) {
        // 获取当前输入框中的表达式
        String expression = editText.getText().toString();

        try {
            // 计算表达式结果
            double result = evaluateExpression(expression);

            // 显示结果
            updateEditText(String.valueOf(result));
        } catch (Exception e) {
            // 处理错误，例如除零等
            updateEditText("0");
            updateResultText("");
        }
        // 添加按下的闪烁效果
        animateButtonPress(view);
    }

    public void onAllClearClick(View view) {
        // 清空输入框
        //更新editText
        updateEditText("0");
        updateResultText("");
        // 添加按下的闪烁效果
        animateButtonPress(view);
    }

    public void onDeleteClick(View view) {
        // 获取当前输入框中的文本
        String currentText = editText.getText().toString();

        // 删除最后一个字符
        if (currentText.length() > 0) {
            currentText = currentText.substring(0, currentText.length() - 1);
            //更新editText
            updateEditText(currentText);

        }
        // 添加按下的闪烁效果
        animateButtonPress(view);
    }
    public void onPercentageClick(View view) {
        String currentText = editText.getText().toString();
        try {
            double value = Double.parseDouble(currentText);
            value /= 100;
            updateEditText(String.valueOf(value));
        } catch (NumberFormatException e) {
            updateEditText("Error");
        }
        // 添加按下的闪烁效果
        animateButtonPress(view);
    }
    public void onMultiplyClick(View view) {
        handleOperatorClick("*");
        // 添加按下的闪烁效果
        animateButtonPress(view);
    }

    public void onSubtractClick(View view) {
        handleOperatorClick("-");
        // 添加按下的闪烁效果
        animateButtonPress(view);
    }

    public void onAddClick(View view) {
        handleOperatorClick("+");
        // 添加按下的闪烁效果
        animateButtonPress(view);
    }

    public void onDecimalPointClick(View view) {
        String currentText = editText.getText().toString();
        if (!currentText.contains(".")) {
            updateEditText(currentText + ".");
        }
        // 添加按下的闪烁效果
        animateButtonPress(view);
    }

    private void handleOperatorClick(String operator) {
        String currentText = editText.getText().toString();
        if (!currentText.equals("Error")) {
            updateEditText(currentText + operator);
            updateResultText("");  // 在新的计算开始时清除结果文本
        }
    }
    //更新editText
    private void updateEditText(String inputText){
        editText.setText(inputText);
        // 添加呼吸效果
        animateTextBreathPeriodically();
    }
    private void updateResultOnButtonClick() {
        String expression = editText.getText().toString();
        try {
            double result = evaluateExpression(expression);
            updateResultText(String.valueOf(result));
        } catch (Exception e) {
            updateResultText("");
        }
    }
    private void updateResultText(String result) {
        if (!result.isEmpty()) {
            double numericResult = Double.parseDouble(result);
            resultText.setText(String.valueOf(numericResult));  // 将结果转换为字符串
            resultText.startAnimation(getResultTextAnimation());
        } else {
            resultText.setText("");
        }
    }

    private void animateTextBreath() {
        AlphaAnimation alphaAnimation = new AlphaAnimation(1.0f, 0.0f);
        alphaAnimation.setDuration(500);
        alphaAnimation.setRepeatMode(AlphaAnimation.REVERSE);
        alphaAnimation.setRepeatCount(1);

        editText.startAnimation(alphaAnimation);
    }
    // 定期调用呼吸效果
    private void animateTextBreathPeriodically() {
        handler.removeCallbacks(breathRunnable);
        handler.postDelayed(breathRunnable, 1000); // 每隔1秒执行一次
    }
    private Animation getResultTextAnimation() {
        // Customize the animation for the resultText if needed
        AlphaAnimation alphaAnimation = new AlphaAnimation(1.0f, 0.0f);
        alphaAnimation.setDuration(500);
        alphaAnimation.setRepeatMode(AlphaAnimation.REVERSE);
        alphaAnimation.setRepeatCount(1);
        return alphaAnimation;
    }
    private double evaluateExpression(String expression) {
        try {
            Expression e = new ExpressionBuilder(expression)
                    .build();
            return e.evaluate();
        } catch (ArithmeticException ex) {
            // Handle division by zero or other arithmetic errors
            return Double.NaN;
        }
    }
}
