package com.example.administrator.ndk;


/**
 * 给jni中c调用
 * Create by: 陈博易
 * Date: 2018/1/17
 * time:  14:38
 * Email: 495057454@qq.com
 * 微信公众号：走向全栈工程师
 */
public class MyClass {
    private int width;
    private int height;

    public MyClass(int width, int height) {
        this.width = width;
        this.height = height;
    }

    public int getArea() {
        return width * height;
    }

}
