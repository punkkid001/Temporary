package com.example.MyApp2;

import android.content.Context;
import android.database.Cursor;
import android.provider.MediaStore;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.CursorAdapter;
import android.widget.TextView;

/**
 * Created by Jiyoon on 2015-08-29.
 */
public class MyCursorAdapter extends CursorAdapter
{
    public MyCursorAdapter(Context context, Cursor c, boolean autoRequery)
    {
        super(context, c, autoRequery);

    }

    @Override
    public View newView(Context context, Cursor cursor, ViewGroup parent) {
        LayoutInflater inflater=LayoutInflater.from(context);
        View v=inflater.inflate(R.layout.row, parent, false);

        return v;
    }

    @Override
    public void bindView(View view, Context context, Cursor cursor) {
        TextView singer=(TextView)view.findViewById(R.id.singer);
        TextView title=(TextView)view.findViewById(R.id.title);

        singer.setText(cursor.getString(cursor.getColumnIndex(MediaStore.Audio.Media.ARTIST)));
        title.setText(cursor.getString(cursor.getColumnIndex(MediaStore.Audio.Media.TITLE)));
    }
}
