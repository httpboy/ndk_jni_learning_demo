package com.ndk.use;

/**
 * 本地方法使用辅助类
 * Create by: 陈博易
 * Date: 2018/1/1
 * time:  12:25
 * Email: 495057454@qq.com
 * 请关注微信公众号：陈博易
 */
public class HelloJni {
    // Used to load the 'native-lib' library on application startup.
    //在应用开启的时候就加载native-lib
    static {
        System.loadLibrary("native-lib");
    }
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    //本地方法在java类中的声明，具体实现在'native-lib' native library
    public static native String stringFromJNI();
}
