package com.ndk.use;

/**
 * author: Administrator
 * created on: 2018/1/3 21:19
 * description:
 */
public class NdkC01 {
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
    public static native String ndkc01();

    public static native String ndkc02();

    public static native String ndkc03();

}
