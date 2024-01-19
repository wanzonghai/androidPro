package happy.game.puzzle.bilcom;

import android.content.Context;
import android.content.res.Configuration;
import android.widget.ImageView;

import androidx.appcompat.widget.AppCompatImageView;

public class happyGameTw extends AppCompatImageView {

    private int mTileId = -1;

    public happyGameTw(Context context){
        super(context);
    }

    public happyGameTw(Context context, int tileId, int minWidth, int minHeight){
        super(context);
        mTileId = tileId;
        init(minWidth, minHeight);
    }

    public void init(int minWidth, int minHeight){
        setMinimumHeight(minHeight);
        setMinimumWidth(minWidth);
        setScaleType(ImageView.ScaleType.CENTER_INSIDE);
    }

    public int getTileId(){
        return mTileId;
    }

    public void setTileId(int id){
        mTileId = id;
    }

    public void updateWithTile(happyGameTl tile){
        setImageDrawable(tile.getDrawable());
    }


}
