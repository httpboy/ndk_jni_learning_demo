package com.ndk.use;

/**
 * 演示c语言的本地方法
 * Create by: 陈博易
 * Date: 2018/1/15
 * time:  23:37
 * Email: 495057454@qq.com
 * 请关注微信公众号：走向全栈工程师
 */
public class NdkC {
    //在应用开启的时候就加载native-lib
    static {
        System.loadLibrary("native-lib");
    }

    public static native String ndkc01();

    public static native String ndkc02();

    public static native String ndkc03();

    public static native String ndkc04();

    public static native String ndkc05();

    public static native String ndkc06(String path);

}
