package com.example.administrator.ndk;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;

import com.example.administrator.ndk.utils.StringUtils;
import com.ndk.use.NdkJni;

import java.util.concurrent.TimeUnit;

public class MainActivityJni extends AppCompatActivity implements View.OnClickListener {

    private Button mBtnJni03;
    private TextView mTvShow;
    private Button mBtnJni03_btn_jni_03_set_static_value;
    private Button mBtnJni03_btn_jni_03_set_no_static_method;
    private Button mBtnJni03_btn_jni_03_set_static_method;
    private Button mBtnJni03_btn_jni_03_set_ConstructorP_method;
    private Button mBtnJni03_btn_jni_03_HandString;
    private Button mBtnJni03_btn_jni_03_HandIntArray;
    private Button mBtnJni03_btn_jni_03_JniReturnIntArray;
    private Button mBtnJni03_btn_jni_03_Jni_Reference;
    private Button mBtnJni03_btn_jni_03_Jni_get_Reference;
    private Button mBtnJni03_btn_jni_03_Jni_env;
    private Button mBtnJni03_btn_jni_03_Jni_exeception;
    private Button mBtnJni03_btn_jni_03_Jni_throwexeception;

    public static void lanchActivity(Activity activity) {
        Intent intent = new Intent(activity, MainActivityJni.class);
        activity.startActivity(intent);
    }

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
        mBtnJni03_btn_jni_03_set_ConstructorP_method = (Button) findViewById(R.id.btn_jni_03_set_ConstructorP_method);
        mBtnJni03_btn_jni_03_HandString = (Button) findViewById(R.id.btn_jni_03_handle_string);
        mBtnJni03_btn_jni_03_HandIntArray = (Button) findViewById(R.id.btn_jni_03_handle_intArray);
        mBtnJni03_btn_jni_03_JniReturnIntArray = (Button) findViewById(R.id.btn_jni_03_jni_return_array);
        mBtnJni03_btn_jni_03_Jni_Reference = (Button) findViewById(R.id.btn_jni_03_jni_reference);
        mBtnJni03_btn_jni_03_Jni_get_Reference = (Button) findViewById(R.id.btn_jni_03_jni_get_reference);
        mBtnJni03_btn_jni_03_Jni_env = (Button) findViewById(R.id.btn_jni_03_jni_env);
        mBtnJni03_btn_jni_03_Jni_exeception = (Button) findViewById(R.id.btn_jni_03_jni_exeception);
        mBtnJni03_btn_jni_03_Jni_throwexeception = (Button) findViewById(R.id.btn_jni_03_jni_Throwexeception);

        mBtnJni03.setOnClickListener(this);
        mBtnJni03_btn_jni_03_set_static_value.setOnClickListener(this);
        mBtnJni03_btn_jni_03_set_no_static_method.setOnClickListener(this);
        mBtnJni03_btn_jni_03_set_static_method.setOnClickListener(this);
        mBtnJni03_btn_jni_03_set_ConstructorP_method.setOnClickListener(this);
        mBtnJni03_btn_jni_03_HandString.setOnClickListener(this);
        mBtnJni03_btn_jni_03_HandIntArray.setOnClickListener(this);
        mBtnJni03_btn_jni_03_JniReturnIntArray.setOnClickListener(this);
        mBtnJni03_btn_jni_03_Jni_Reference.setOnClickListener(this);
        mBtnJni03_btn_jni_03_Jni_get_Reference.setOnClickListener(this);
        mBtnJni03_btn_jni_03_Jni_get_Reference.setOnClickListener(this);
        mBtnJni03_btn_jni_03_Jni_env.setOnClickListener(this);
        mBtnJni03_btn_jni_03_Jni_exeception.setOnClickListener(this);
        mBtnJni03_btn_jni_03_Jni_throwexeception.setOnClickListener(this);
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
                mTvShow.setText("noStaticKeyValue修改前=0\n修改后=" + ndkJni.noStaticKeyValue);
            }
            break;
            case R.id.btn_jni_03_set_static_value://c访问java静态成员变量
            {
                new NdkJni().ndkJni03SetValue();
                mTvShow.setText("StaticKeyValue修改前=陈博易\n修改后=" + NdkJni.staticKeyValue);
            }
            break;
            case R.id.btn_jni_03_set_no_static_method://c访问java静态方法
            {
                NdkJni ndkJni = new NdkJni();
                ndkJni.ndkJni03SetMethod();
                mTvShow.setText("StaticKeyValue修改前=陈博易\n修改后=" + ndkJni.getMethod());
            }
            break;
            case R.id.btn_jni_03_set_static_method://c访问java非静态方法
            {
                NdkJni ndkJni = new NdkJni();
                ndkJni.ndkJni03SetStaticMethod();
                mTvShow.setText("StaticKeyValue修改前=陈博易\n修改后=" + NdkJni.staticMethod);
            }
            break;
            case R.id.btn_jni_03_set_ConstructorP_method://c访问java自定义类(计算面积)
            {
                NdkJni ndkJni = new NdkJni();
                int i = ndkJni.ndkJni03CallConstructorMethod();
                mTvShow.setText("面积=" + i);

            }
            break;
            case R.id.btn_jni_03_handle_string://jni层处理java层传入的String
            {
                String handString = NdkJni.ndkJni03HandString("走向全栈工程师");
                mTvShow.setText("传入String=走向全栈工程师\n返回String=" + handString);

            }
            break;
            case R.id.btn_jni_03_handle_intArray://jni层处理java层传入的int[]进行排序算法
            {
                int[] numbers = new int[]{5, 9, 1, 3, 7, 8};
                NdkJni.ndkJni03HandIntArray(numbers);
                mTvShow.setText("排序前：{5, 9, 1, 3, 7, 8}\n" +
                        "排序后" + StringUtils.intArraysToString(numbers));

            }
            break;
            case R.id.btn_jni_03_jni_return_array://jni层创建一个数组,并且调用jni层方法进行排序
            {
                int[] jni03ReturnIntArray = NdkJni.ndkJni03ReturnIntArray(10);
                NdkJni.ndkJni03HandIntArray(jni03ReturnIntArray);
                mTvShow.setText("jni层创建一个随机数组" + StringUtils.intArraysToString(jni03ReturnIntArray));

            }
            break;
            case R.id.btn_jni_03_jni_reference://jni层创建引用（全局、局部）
            {
                NdkJni.ndkJni03ReReference();
            }
            break;
            case R.id.btn_jni_03_jni_get_reference://jni层获取引用（全局、局部）
            {
                String ndkJni03GetReReference = NdkJni.ndkJni03GetReReference();
                mTvShow.setText(ndkJni03GetReReference);

            }

            break;
            case R.id.btn_jni_03_jni_exeception://jni层产生异常，jni层自行处理native异常
            {
                NdkJni ndkJni = new NdkJni();
                String ndkEnv = ndkJni.exeception();
                mTvShow.setText(ndkEnv + "并且修改了method的字符串：" + ndkJni.getMethod());

            }
            break;
            case R.id.btn_jni_03_jni_Throwexeception://jni层产生异常，java层处理native异常
            {
                try {
                    NdkJni ndkJni = new NdkJni();
                    ndkJni.throwexeception();
                } catch (Exception e) {
                    e.printStackTrace();
                    //W/System.err:     at com.ndk.use.NdkJni.throwexeception(Native Method)
                    //W/System.err:     at com.example.administrator.ndk.MainActivityJni.onClick(MainActivityJni.java:174)
                } finally {
                    Log.d("jni", "finally");
                }

            }
            break;
            default:
                break;
        }
    }
}
