package com.example.administrator.ndk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

import com.ndk.use.JniUtils;
import com.ndk.use.NdkC01;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        //调用jni中的方法
        tv.setText(JniUtils.stringFromJNI());
        testNdk();

    }

    private void testNdk() {
        //String s = NdkC01.ndkc01();
        //String s = NdkC01.ndkc02();
        String s = NdkC01.ndkc03();
    }
}
