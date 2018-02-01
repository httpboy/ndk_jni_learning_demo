package com.example.administrator.ndk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.ndk.use.NdkJni;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private Button mBtnC;
    private Button mBtnJni;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        initView();
        initListener();

    }

    private void initListener() {
        mBtnC.setOnClickListener(this);
        mBtnJni.setOnClickListener(this);
    }

    private void initView() {
        mBtnC = (Button) findViewById(R.id.btn_c);
        mBtnJni = (Button) findViewById(R.id.btn_jni);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_c://演示c入门
                MainActivityC.lanchActivity(this);
                break;
            case R.id.btn_jni://演示Jni入门
                MainActivityJni.lanchActivity(this);
                break;

            default:
                break;

        }
    }

}
