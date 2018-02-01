package com.example.administrator.ndk;

import android.app.Activity;
import android.content.Intent;
import android.os.Environment;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import com.ndk.use.HelloJni;
import com.ndk.use.NdkC;

import java.io.File;

public class MainActivityC extends AppCompatActivity {

    private TextView mTvShow;

    public static void lanchActivity(Activity activity) {
        Intent intent = new Intent(activity, MainActivityC.class);
        activity.startActivity(intent);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main_c);
        // Example of a call to a native method
        mTvShow = (TextView) findViewById(R.id.tv_show);
        mTvShow.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
            }
        });
        testNdk();

    }


    private void testNdk() {
        String s = NdkC.ndkc01();
        //String s = NdkC.ndkc02();
        //String s = NdkC.ndkc03();
        //String s = NdkC.ndkc04();
        //String s = NdkC.ndkc05();
        mTvShow.setText(s);

        /*String absolutePath = Environment.getExternalStorageDirectory().getAbsolutePath();
        String s = NdkC.ndkc06(absolutePath + File.separatorChar + "boy.txt");
        Log.d("myDemo-jni", absolutePath + File.separatorChar + "boy.txt");//   /storage/emulated/0/boy.txt
*/
    }
}
