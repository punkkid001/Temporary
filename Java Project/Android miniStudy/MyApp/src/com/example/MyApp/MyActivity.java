package com.example.MyApp;

import android.app.Activity;
import android.os.Bundle;
import android.os.CountDownTimer;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import java.util.Random;

public class MyActivity extends Activity implements View.OnClickListener
{
    TextView memText;
    TextView countDown;
    TextView randomText;
    EditText inputText;

    Button startBtn;
    Button quitBtn;

    boolean start;
    CountDownTimer Ctimer;
    String[] arr={"google", "facebook", "twitter", "instagram", "tumblr", "naver", "daumkakao"};
    String str="";
    int value, index;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        init();
    }

    void init()
    {
        memText=(TextView)findViewById(R.id.memText);
        countDown=(TextView)findViewById(R.id.countDown);
        randomText=(TextView)findViewById(R.id.randomText);
        inputText=(EditText)findViewById(R.id.inputText);

        startBtn=(Button)findViewById(R.id.startBtn);
        quitBtn=(Button)findViewById(R.id.quitBtn);

        startBtn.setOnClickListener(this);
        quitBtn.setOnClickListener(this);

        start=false;
        value=4;
        index=0;

        Ctimer= new CountDownTimer(4000, 1000)
        {
            @Override
            public void onTick(long millisUntilFinished)
            {
                countDown.setText("CountDown :"+value);
                value--;
            }

            @Override
            public void onFinish()
            {
                randomText.setText("????");
                memText.setText("Are you Remember?");
                countDown.setText("- Time over -");

                value=4;
            }
        };


    }

    @Override
    public void onClick(View v)
    {
        switch (v.getId())
        {
            case R.id.startBtn:
                if(!start)
                {
                    startBtn.setText("OK");
                    start=true;
                    quiz();
                }

                else
                    checkAnswer();
                break;
            case R.id.quitBtn:
                finish();
                break;
        }
    }

    void quiz()
    {
        Random randomNumber=new Random();
        index=randomNumber.nextInt(7);
        str=arr[index];

        randomText.setText(str);
        Ctimer.start();
    }

    void checkAnswer()
    {
        String answer=inputText.getText().toString();

        if(answer.equals(str))
        {
            Toast toast=Toast.makeText(getApplicationContext(), "Yeah, You got it.", Toast.LENGTH_SHORT);
            toast.show();
        }

        else
        {
            Toast toast=Toast.makeText(getApplicationContext(), "Wrong Answer.", Toast.LENGTH_SHORT);
            toast.show();
        }

        str="";

        inputText.setText("");
        CountDownTimer Ttimer=new CountDownTimer(1000,1000)
        {
            @Override
            public void onTick(long millisUntilFinished)
            {

            }

            @Override
            public void onFinish()
            {
                quiz();
            }
        };

        Ttimer.start();
    }
}
