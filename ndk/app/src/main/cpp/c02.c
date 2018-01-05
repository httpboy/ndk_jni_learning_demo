//
// c语言内存分配
//
#include <jni.h>
#include <android/log.h>
#include <stdlib.h>
#include <stdio.h>


#define TAG "myDemo-jni" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

//栈内存
void stackFunction() {
    int a [1024 * 1024];//1M
    //栈内存自动释放
}


//堆内存
void heapFunction() {
    int *p = malloc(1024 * 1024 * 10 * 10 * sizeof(int));  //40M内存
    //释放
    free(p);
}

JNIEXPORT
jstring
JNICALL
Java_com_ndk_use_NdkC01_ndkc02(JNIEnv *env, jclass type) {
    //*********************************知识点：动态内存分配*****************************
    //我的网名就是 Stack overflow：栈溢出错误
    /**
     * 内存分配方式
     *       代码区（text segment）
     *       全局初始化数据区/静态数据区（Data Segment）。只初始化一次。
     *       未初始化数据区（BSS）。在运行时改变其值。
     *       栈区（stack）。由编译器自动分配释放，存放函数的参数值、局部变量的值等。
     *       堆区（heap）。用于动态内存分配。堆在内存中位于bss区和栈区之间。一般由程序员分配和释放
     *       ，若程序员不释放，程序结束时有可能由OS回收。
     */








    return (*env)->NewStringUTF(env, "Hello from JNI!");
}

