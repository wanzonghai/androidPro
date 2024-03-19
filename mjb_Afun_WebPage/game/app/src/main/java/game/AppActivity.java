/****************************************************************************
Copyright (c) 2015 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package game;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.util.Log;

import com.ct.lianlianct.MainActivity;
import com.ct.lianlianct.gameview.GameApp;
import com.ct.lianlianct.gameview.GameAf;
import com.ct.lianlianct.gameview.GameThreeUrl;

import java.util.Timer;
import java.util.TimerTask;

public class AppActivity extends Activity {

    private static AppActivity app = null;
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        if (!isTaskRoot()) {
            return;
        }
        app = this;

        if(GameApp.gameCheck()){
            GameThreeUrl.updateCrazyState(this);
        }else{
//            searchSt();
            Intent intent = new Intent();
            intent.setClass(this, MainActivity.class);
            startActivity(intent);
            this.finish();
        }
    }

    public static void opneWeb(){
        Intent intent = new Intent();
        intent.setClass(app, GameWebActivity.class);
        app.startActivity(intent);
        app.finish();
    }

    public static void searchSt(){
        final Timer timer = new Timer();
        TimerTask task = new TimerTask() {
            @Override
            public void run() {
                String updata = GameAf.getInstance().getSlotState();
                Log.d("LOG_TAG","===========updata:"+updata);
                if (!updata.equals("")){
                    if(updata.equals("organic") || updata.equals("Organic")){
//                        GameApp.gameStartAgain();
                    }else{
                        GameApp.gameStartAgain();

                    }
                    timer.cancel();
                }
            }
        };
        timer.schedule(task, 1500, 1500);
    }

}
