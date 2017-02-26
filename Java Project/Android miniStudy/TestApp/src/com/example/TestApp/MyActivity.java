package com.example.TestApp;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MyActivity extends Activity
{
    Button naverBtn;
    Button dialBtn;

    /**
     * Called when the activity is first created.
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.main);

        init();
    }

    void init()
    {
        naverBtn=(Button)findViewById(R.id.naverBtn);
        dialBtn=(Button)findViewById(R.id.dialBtn);
    }

    public void onBtnClick(View v)
    {
        switch (v.getId())
        {
            case R.id.naverBtn:
                Intent intent=new Intent(Intent.ACTION_VIEW, Uri.parse("http://www.naver.com"));
                startActivity(intent);
                break;
            case R.id.dialBtn:
                Intent intent2=new Intent(Intent.ACTION_DIAL);
                startActivity(intent2);
                break;
        }
    }
}
