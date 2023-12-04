package idasodqw.sadamoq.ccasda;

import android.annotation.SuppressLint;
import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Rect;
import android.util.AttributeSet;
import android.widget.ImageView;

import androidx.annotation.Nullable;


@SuppressLint("AppCompatCustomView")
public class Kasduaqw extends ImageView {

    public Kasduaqw(Context context) {
        super(context);
    }

    public Kasduaqw(Context context, @Nullable AttributeSet attrs) {
        super(context, attrs);
    }

    @Override
    protected void onDraw(Canvas awejiovhaerb) {
        super.onDraw(awejiovhaerb);

        Rect rec = awejiovhaerb.getClipBounds();

        rec.top++;

        rec.bottom--;

        rec.left++;

        rec.right--;

        Paint aweioaerb = new Paint();

        aweioaerb.setColor(Color.parseColor("#f2f2f2"));
        //颜色
        aweioaerb.setStyle(Paint.Style.STROKE);
        aweioaerb.setStrokeWidth(2);
        awejiovhaerb.drawRect(rec, aweioaerb);
    }

}
