//'MyActivity' class is showing Intro image.

package com.example.MyApp2;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.widget.ImageView;

public class MyActivity extends Activity {

    ImageView introImg;
    CountDownTimer Ctimer;

    /**
     * Called when the activity is first created.
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        introImg=(ImageView)findViewById(R.id.introImg);
        Ctimer=new CountDownTimer(5000, 1000)
        {
            @Override
            public void onTick(long millisUntilFinished)
            {

            }

            @Override
            public void onFinish()
            {
                Intent intent=new Intent(MyActivity.this, SecondActivity.class);
                startActivity(intent);
            }
        };

        Ctimer.start();
    }
}
