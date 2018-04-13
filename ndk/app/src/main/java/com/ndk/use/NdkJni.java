package com.ndk.use;

/**
 * author: Administrator
 * created on: 2018/1/16 11:32
 * description:
 */
public class NdkJni {

    public int noStaticKeyValue = 0;
    public static String staticKeyValue = "陈博易";

    private String method = "暂时没被访问";
    public static String staticMethod = "暂时没被访问";


    public void setMethod(String method) {
        this.method = method;
    }

    public static void setStaticMethod(String method) {
        staticMethod = method;
    }

    public String getMethod() {
        return method;
    }

    //在应用开启的时候就加载native-lib
    static {
        System.loadLibrary("native-lib");
    }

    public static native String ndkJni01();

    public static native String ndkJni02();

    public native String ndkJni03();

    public native String ndkJni03SetValue();

    public native String ndkJni03SetMethod();

    public native String ndkJni03SetStaticMethod();

    public native int ndkJni03CallConstructorMethod();

    public static native String ndkJni03HandString(String text);

    public static native void ndkJni03HandIntArray(int[] array);

    public static native int[] ndkJni03ReturnIntArray(int length);

    public static native void ndkJni03ReReference();

    public static native String ndkJni03GetReReference();

    public static native String ndkJni03Env();

    public native String exeception();

    public native void throwexeception();
}
