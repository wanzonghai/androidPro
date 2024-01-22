package com.intelligentrecovery.hyerodpryg;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import android.os.Bundle;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.EditText;
import android.widget.ImageView;
import android.widget.ListView;

import com.intelligentrecovery.hyerodpryg.R;

import androidx.appcompat.app.AppCompatActivity;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class MainActivity extends AppCompatActivity {
    private EditText nameEditText;  // 新的用户名输入框
    private EditText messageEditText;
    private ListView messageListView;
    private ArrayAdapter<String> messageAdapter;

    private String[] questions;
    private String[] answers;

    private String[] keywords;

    private String userName;
    private String aiName;  // 存储 AI 名字

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_input_name);

        nameEditText = findViewById(R.id.nameEditText);  // 绑定新的用户名输入框


        // Get predefined questions and answers
        questions = getResources().getStringArray(R.array.questions_array);
        answers = getResources().getStringArray(R.array.answers_array);
        keywords = getResources().getStringArray(R.array.keywords_array);


    }
    public void startChatting(View view) {
        // Get the user name
        userName = nameEditText.getText().toString().trim();

        // Switch to the chat layout
        setContentView(R.layout.activity_main);

        messageListView = findViewById(R.id.messageListView);
        messageEditText = findViewById(R.id.messageEditText);  // 绑定新的消息输入框
        messageAdapter = new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, new ArrayList<String>());
        messageListView.setAdapter(messageAdapter);

        // Set AI avatar immediately
        ImageView aiAvatarImageView = findViewById(R.id.aiAvatarImageView);
        aiAvatarImageView.setImageResource(R.drawable.ai);

        // Generate a random AI name
        aiName = generateRandomAiName();
    }

    public void sendMessage(View view) {
        String userName = nameEditText.getText().toString().trim();
        String message = messageEditText.getText().toString().trim();
        if (!message.isEmpty()) {
            // Add user message to the list view
            messageAdapter.add(userName + ": " + message);

            // Generate a simple AI response
            String aiResponse = getAiResponse(message);

            // Add AI response to the list view
            messageAdapter.add(aiName + ": " + aiResponse);

            // Set AI avatar
            ImageView aiAvatarImageView = findViewById(R.id.aiAvatarImageView);
            aiAvatarImageView.setImageResource(R.drawable.ai);

            // Clear the input field
            messageEditText.setText("");
        }
    }

    private String getAiResponse(String userMessage) {
        // Iterate through questions and find a match
        for (int i = 0; i < questions.length; i++) {
            String[] questionKeywords = keywords[i].split("\\|");
            for (String keyword : questionKeywords) {
                if (userMessage.contains(keyword.trim())) {
                    // Use equalsIgnoreCase to perform case-insensitive comparison
                    if (userMessage.equalsIgnoreCase(keyword.trim())) {
                        return answers[i];
                    }
                }
            }
        }

        // If no specific keyword is found, provide a generic response
        return "I'm not sure how to respond to that.";
    }
    private String generateRandomAiName() {
        String[] aiNames = {"AI Bot", "ChatMaster", "SmartBot", "TechGenius"};
        Random random = new Random();
        int index = random.nextInt(aiNames.length);
        return aiNames[index];
    }
}
