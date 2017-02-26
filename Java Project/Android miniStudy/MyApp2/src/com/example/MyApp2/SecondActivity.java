//'SecondActivity' is core of program for music player.

package com.example.MyApp2;

import android.app.Activity;
import android.content.ContentResolver;
import android.database.Cursor;
import android.media.MediaPlayer;
import android.os.Bundle;
import android.provider.MediaStore;
import android.view.View;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.ListView;

import java.io.IOException;

public class SecondActivity extends Activity implements AdapterView.OnItemClickListener, AdapterView.OnClickListener
{
    ListView listView;
    MyCursorAdapter adapter;
    Cursor cursor;
    String[] mCursor=
            {
                    MediaStore.Audio.Media._ID,
                    MediaStore.Audio.Media.ARTIST,
                    MediaStore.Audio.Media.TITLE,
                    MediaStore.Audio.Media.DATA
            };
    ContentResolver cr;
    MediaPlayer player;

    Button playBtn;
    Button stopBtn;

    String path;

    /**
     * Called when the activity is first created.
     */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.second);

        init();
    }

    void init()
    {
        listView=(ListView)findViewById(R.id.listView);
        listView.setOnItemClickListener(this);

        playBtn=(Button)findViewById(R.id.playBtn);
        stopBtn=(Button)findViewById(R.id.stopBtn);
        playBtn.setOnClickListener(this);
        stopBtn.setOnClickListener(this);

        cr=getContentResolver();
        cursor=cr.query(MediaStore.Audio.Media.EXTERNAL_CONTENT_URI, mCursor, null, null, null);
        cursor.moveToFirst();

        adapter=new MyCursorAdapter(getApplicationContext(), cursor, false);
        listView.setAdapter(adapter);
    }

    @Override
    public void onClick(View v)
    {
        switch (v.getId())
        {
            case R.id.playBtn:
                if(player==null)
                {
                    player=new MediaPlayer();
                    try {
                        player.setDataSource(path);
                        player.prepare();
                        player.start();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
                break;
            case R.id.stopBtn:
                if(player!=null)
                {
                    player.stop();
                    player.release();
                    player=null;
                }
                break;
        }
    }

    @Override
    public void onItemClick(AdapterView<?> parent, View view, int position, long id)
    {
        if(cursor!=null)
        {
            cursor.moveToPosition(position);
            path=cursor.getString(cursor.getColumnIndex(MediaStore.Audio.Media.DATA));
        }
    }
}
