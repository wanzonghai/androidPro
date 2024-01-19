package happy.game.puzzle.bilcom;

import android.content.res.Configuration;
import android.graphics.Bitmap;

import happy.game.courtor.GamePerdlLoader;
import happy.game.puzzle.GamePuzzleAlt;

public class happyGameUi {
    public static final Bitmap getSubdivisionOfBitmap(
            Bitmap bitmap,
            int subdivisionWidth,
            int subdivisionHeight,
            int subdivisionRowIndex,
            int subdivisionColumnIndex) throws IllegalArgumentException {

        // The original bitmap dimensions
        int bitmapWidth = bitmap.getWidth();
        int bitmapHeight = bitmap.getHeight();

        int[] pixels = new int[subdivisionHeight * subdivisionWidth];
        int yStart = subdivisionRowIndex * (subdivisionHeight - 1);
        int xStart = subdivisionColumnIndex * (subdivisionWidth - 1);

        if (xStart + subdivisionWidth > bitmapWidth
                || yStart + subdivisionHeight > bitmapHeight) {
            throw new IllegalArgumentException(
                    "Cannot get subdivision outside bounds of the image width and height");
        }
        bitmap.getPixels(
                pixels,
                0,                  // Offset in pixels array
                subdivisionWidth,   // Stride
                xStart,
                yStart,
                subdivisionWidth,
                subdivisionHeight);
        return Bitmap.createBitmap(
                pixels,
                subdivisionWidth,
                subdivisionHeight,
                Bitmap.Config.ARGB_8888);
    }

    public static boolean happyPuzzlePt() {
        return GamePuzzleAlt.mApplication.getResources().getConfiguration().locale.getLanguage().equals("pt");
    }
}
