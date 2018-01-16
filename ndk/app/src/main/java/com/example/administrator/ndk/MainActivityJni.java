package com.example.administrator.ndk;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.ndk.use.NdkJni;

public class MainActivityJni extends AppCompatActivity implements View.OnClickListener {

    private Button mBtnJni03;
    private TextView mTvShow;
    private Button mBtnJni03_btn_jni_03_set_static_value;
    private Button mBtnJni03_btn_jni_03_set_no_static_method;
    private Button mBtnJni03_btn_jni_03_set_static_method;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main_jni);
        // Example of a call to a native method
        initView();
        //调用jni中的方法
        testNdkJni();

    }

    private void initView() {
        mTvShow = findViewById(R.id.sample_text);
        mBtnJni03 = (Button) findViewById(R.id.btn_jni_03);
        mBtnJni03_btn_jni_03_set_static_value = (Button) findViewById(R.id.btn_jni_03_set_static_value);
        mBtnJni03_btn_jni_03_set_no_static_method = (Button) findViewById(R.id.btn_jni_03_set_no_static_method);
        mBtnJni03_btn_jni_03_set_static_method = (Button) findViewById(R.id.btn_jni_03_set_static_method);
        mBtnJni03.setOnClickListener(this);
        mBtnJni03_btn_jni_03_set_static_value.setOnClickListener(this);
        mBtnJni03_btn_jni_03_set_no_static_method.setOnClickListener(this);
        mBtnJni03_btn_jni_03_set_static_method.setOnClickListener(this);
    }

    private void testNdkJni() {
        //String s = NdkJni.ndkJni01();
        //String s = NdkJni.ndkJni02();
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_jni_03://c访问java非静态成员变量
            {
                NdkJni ndkJni = new NdkJni();
                ndkJni.ndkJni03();
                mTvShow.setText("noStaticKeyValue修改前=0，修改后=" + ndkJni.noStaticKeyValue);
            }
            break;
            case R.id.btn_jni_03_set_static_value://c访问java静态成员变量
            {
                new NdkJni().ndkJni03SetValue();
                mTvShow.setText("StaticKeyValue修改前=陈博易，修改后=" + NdkJni.staticKeyValue);
            }
            break;
            case R.id.btn_jni_03_set_no_static_method://c访问java静态方法
            {
                NdkJni ndkJni = new NdkJni();
                ndkJni.ndkJni03SetMethod();
                mTvShow.setText("StaticKeyValue修改前=陈博易，修改后=" + ndkJni.getMethod());
            }
            break;
            case R.id.btn_jni_03_set_static_method://c访问java非静态方法
            {
                NdkJni ndkJni = new NdkJni();
                ndkJni.ndkJni03SetStaticMethod();
                mTvShow.setText("StaticKeyValue修改前=陈博易，修改后=" + NdkJni.staticMethod);
            }
            break;
            default:
                break;
        }
    }
}
