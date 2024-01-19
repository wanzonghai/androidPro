package happy.game.puzzle.bilcom;

import android.app.Activity;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.Drawable;
import android.os.Handler;
import android.os.Message;
import android.os.Bundle;
import android.view.Gravity;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TableLayout;
import android.widget.TableRow;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Random;
import java.util.Timer;
import java.util.TimerTask;

public class happyGameAct extends Activity {

    private static final int DEFAULT_BOARD_SIZE = 4;
    private static int TILE_IMAGE_ID = R.drawable.icon_strawberry;

    private happyGameTe mGameState = happyGameTe.NONE;
    private int mPuzzleBoardSize = DEFAULT_BOARD_SIZE;     // n x n
    private happyGameRd mPuzzleGameBoard;
    private happyGameTl puzzleGameTile;
    private happyGameTw[][] mPuzzleTileViews;

    private TextView mScoreTextView;
    private Button mNewGameButton;
    private EditText levelEditText;
    private TextView timeTextView;
    private TableLayout tableLayout;
    private TextView stepTextView;

    private int time;
    private int step;
    private Timer timer = new Timer();
    private TimerTask timerTask = new TimerTask() {
        @Override
        public void run() {

        }
    };

    private int[][] dir = {
            {0, 1},
            {1, 0},
            {0, -1},
            {-1, 0}
    };

    private final View.OnClickListener mNewGameButtonOnClickListener = new View.OnClickListener(){
        @Override
        public void onClick(View view){
            setLevel();
        }
    };

    private final View.OnClickListener mGameTileOnClickListener = new View.OnClickListener(){
        @Override
        public void onClick(View view){
            if(mGameState != happyGameTe.PLAYING){
                return;
            }

            happyGameTw puzzleGameTileView = (happyGameTw)view;
            int id = puzzleGameTileView.getTileId();
            int row = id / mPuzzleBoardSize;
            int col = id % mPuzzleBoardSize;
            puzzleGameTile = mPuzzleGameBoard.getTile(row, col);

            for(int i = 0; i< 4; i++){
                int nextRow = row + dir[i][0];
                int nextCol = col + dir[i][1];
                if(mPuzzleGameBoard.isWithinBounds(nextRow, nextCol)){
                    if(mPuzzleGameBoard.getTile(nextRow,nextCol).isEmpty()){
                        mPuzzleGameBoard.swapTiles(row, col, nextRow, nextCol);
                        mPuzzleTileViews[row][col].updateWithTile(mPuzzleGameBoard.getTile(row, col));
                        mPuzzleTileViews[nextRow][nextCol].updateWithTile(mPuzzleGameBoard.getTile(nextRow, nextCol));
                        stepTextView.setText(String.valueOf(++step));
                        break;
                    }

                }
            }

            refreshGameBoardView();
            updateGameState();

            upDateScore();
        }
    };


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        mScoreTextView = (TextView)findViewById(R.id.text_score);
        tableLayout = (TableLayout)findViewById(R.id.tableLayout);
        mNewGameButton = (Button)findViewById(R.id.newGameBtn);
        levelEditText = (EditText)findViewById(R.id.LevelEditText);
        timeTextView = (TextView)findViewById(R.id.timeTextView);
        stepTextView = (TextView)findViewById(R.id.stepTextView);

        int num = (int) (Math.random() * 100 % 4);
        if(num == 0){
            TILE_IMAGE_ID = R.drawable.icon_strawberry;
        }else if (num == 1){
            TILE_IMAGE_ID = R.drawable.icon_apple;
        }else if (num == 2){
            TILE_IMAGE_ID = R.drawable.icon_watermelon;
        }else if (num == 3){
            TILE_IMAGE_ID = R.drawable.icon_pineapple;
        }
        mNewGameButton.setOnClickListener(mNewGameButtonOnClickListener);
        initGames();
        updateGameState();

    }

    private void initGames() {
        mPuzzleGameBoard = new happyGameRd(mPuzzleBoardSize, mPuzzleBoardSize);
        Bitmap fullImageBitmap = BitmapFactory.decodeResource(getResources(), TILE_IMAGE_ID);

        int fullImageWidth = fullImageBitmap.getWidth();
        int fullImageHeight = fullImageBitmap.getHeight();
        int squareImageSize = (fullImageWidth > fullImageHeight) ? fullImageWidth : fullImageHeight;

        fullImageBitmap = Bitmap.createScaledBitmap(
                fullImageBitmap,
                squareImageSize,
                squareImageSize,
                false);

        int singleImageSize = squareImageSize / mPuzzleBoardSize;

        happyGameUi puzzleImageUtil = new happyGameUi();

        for (int i = 0; i < mPuzzleBoardSize; i++){
            for(int j = 0;j< mPuzzleBoardSize; j++){
                Bitmap bm = happyGameUi.getSubdivisionOfBitmap(
                        fullImageBitmap,
                        singleImageSize,
                        singleImageSize,
                        i,
                        j
                );

                Drawable drawable = new BitmapDrawable(getResources(), bm);
                puzzleGameTile = new happyGameTl(i * mPuzzleBoardSize + j, drawable);
                mPuzzleGameBoard.setTile(puzzleGameTile, i, j);
            }
        }

        createPuzzleTileViews(singleImageSize, singleImageSize);
    }

    private void createPuzzleTileViews(int minTileViewWidth, int minTileViewHeight) {
        int rowsCount = mPuzzleGameBoard.getRowsCount();
        int colsCount = mPuzzleGameBoard.getColumnsCount();

        mPuzzleTileViews = new happyGameTw[mPuzzleBoardSize][mPuzzleBoardSize];
        for (int i = 0; i < rowsCount; i++) {
            for (int j = 0; j < colsCount; j++) {
                mPuzzleTileViews[i][j] = new happyGameTw(
                        this,
                        i * mPuzzleBoardSize + j,
                        minTileViewWidth,
                        minTileViewHeight);
                mPuzzleTileViews[i][j].setOnClickListener(mGameTileOnClickListener);
            }
        }

        for(int i = 0; i< mPuzzleBoardSize; i++){
            TableRow tableRow = new TableRow(this);
            TableLayout.LayoutParams layoutParams =
                    new TableLayout.LayoutParams(TableLayout.LayoutParams.MATCH_PARENT, TableLayout.LayoutParams.WRAP_CONTENT);
            layoutParams.gravity = Gravity.CENTER;
            tableRow.setLayoutParams(layoutParams);

            for(int j = 0; j < mPuzzleBoardSize; j++){
                puzzleGameTile = mPuzzleGameBoard.getTile(i, j);
                mPuzzleTileViews[i][j].setImageDrawable(puzzleGameTile.getDrawable());
                TableRow.LayoutParams layoutParams1 = new TableRow.LayoutParams(0);
                layoutParams1.weight = 1;
                mPuzzleTileViews[i][j].setAdjustViewBounds(true);
                layoutParams1.setMargins(1,1,1,1);
                mPuzzleTileViews[i][j].setLayoutParams(layoutParams1);

                tableRow.addView(mPuzzleTileViews[i][j]);
            }
            tableLayout.addView(tableRow);
        }
    }

    private void shufflePuzzleTiles(){
        int x = 0, y = 0;
        for(int i = 0; i < mPuzzleBoardSize; i++){
            for(int j = 0; j < mPuzzleBoardSize; j++){
                if(mPuzzleGameBoard.getTile(i, j).isEmpty()){
                    x = i;
                    y = j;
                }
            }
        }
        int nextx, nexty;
        for(int i = 0; i< 100; i++){
            Random random = new Random();
            int type = random.nextInt(4);
            nextx = x + dir[type][0];
            nexty = y + dir[type][1];

            if(mPuzzleGameBoard.isWithinBounds(nextx, nexty)){
                mPuzzleGameBoard.swapTiles(x, y, nextx, nexty);
                mPuzzleTileViews[x][y].updateWithTile(mPuzzleGameBoard.getTile(x, y));
                mPuzzleTileViews[nextx][nexty].updateWithTile(mPuzzleGameBoard.getTile(nextx,nexty));
                x = nextx;
                y = nexty;
            }
        }
    }

    private void resetEmptyTileLocation(){
        happyGameTl puzzleGameTile = mPuzzleGameBoard.getTile(mPuzzleBoardSize -1, mPuzzleBoardSize -1);
        puzzleGameTile.setIsEmpty(true);
        mPuzzleGameBoard.setTile(puzzleGameTile, mPuzzleBoardSize -1, mPuzzleBoardSize -1);
    }

    private void updateGameState(){
        if(hasWonGame() && mGameState == happyGameTe.PLAYING){
            mGameState = happyGameTe.WON;

            for(int i = 0; i < mPuzzleBoardSize; i++){
                for(int j = 0 ;j < mPuzzleBoardSize; j++){
                    mPuzzleTileViews[i][j].setVisibility(View.VISIBLE);
                }
            }
            Toast.makeText(happyGameAct.this, "You win!", Toast.LENGTH_SHORT).show();
        }
    }

    private void refreshGameBoardView(){
        for(int i =0; i< mPuzzleBoardSize; i++){
            for(int j = 0; j< mPuzzleBoardSize; j++){
                if(mPuzzleGameBoard.getTile(i ,j).isEmpty()){
                    mPuzzleTileViews[i][j].setVisibility(View.INVISIBLE);
                }else{
                    mPuzzleTileViews[i][j].setVisibility(View.VISIBLE);
                }
            }
        }
    }

    private boolean hasWonGame(){
        for(int i = 0; i < mPuzzleBoardSize; i++){
            for(int j = 0; j< mPuzzleBoardSize; j++){
                if(mPuzzleGameBoard.getTile(i, j).getOrderIndex() != (i * mPuzzleBoardSize + j)){
                    return false;
                }
            }
        }
        return true;
    }

    private void upDateScore(){
        mScoreTextView.setText(String.valueOf(mPuzzleBoardSize * step * 10 - time));
    }

    private void startNewGame(){
        if(mGameState != happyGameTe.PLAYING){
            resetEmptyTileLocation();
        }
        shufflePuzzleTiles();
        refreshGameBoardView();
        mGameState = happyGameTe.PLAYING;

        step = 0;
        stepTextView.setText(String.valueOf(step));

        time = 0;
        timeCount();

        upDateScore();

        Toast.makeText(happyGameAct.this, "Game Start!", Toast.LENGTH_SHORT).show();
    }

    private void timeCount(){
        new Thread(new Runnable() {
            @Override
            public void run() {
                while(mGameState == happyGameTe.PLAYING){
                    try{
                        Thread.sleep(1000);    // 1s
                        handler.sendEmptyMessage(1);
                    }catch (InterruptedException e){
                        e.printStackTrace();
                    }
                }
            }
        }).start();
    }
    private Handler handler = new Handler(){
        @Override
        public void handleMessage(Message message) {
            super.handleMessage(message);
            switch (message.what){
                case 1:
                    time++;
                    timeTextView.setText(String.valueOf(time));
                    break;
                default:
                    break;
            }
        }
    };

    private void setLevel(){
        int level = 0;
        if (!"".equals(levelEditText.getText().toString())){
            level = Integer.parseInt(levelEditText.getText().toString());
        }
        if(level < 3 || level > 6){
            Toast toast = Toast.makeText(happyGameAct.this, "level must >=3 and level must <=6!", Toast.LENGTH_SHORT);
            toast.show();
            return;
        }else{
            mPuzzleBoardSize = level;
            tableLayout.removeAllViews();
            mGameState = happyGameTe.NONE;
            initGames();
            updateGameState();
            startNewGame();
        }
    }
}
