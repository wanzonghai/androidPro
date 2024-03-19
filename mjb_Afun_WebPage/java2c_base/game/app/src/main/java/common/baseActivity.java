package common;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Bundle;
import android.os.ParcelFileDescriptor;
import android.util.Log;

import java.lang.reflect.Method;

import mos.game.vam.R;

public class baseActivity extends Activity {
    @Override
    protected native void onCreate(Bundle savedInstanceState);
}
