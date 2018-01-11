//
// c语言:共用体 枚举
//
#include <jni.h>
#include <android/log.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


#define TAG "myDemo-jni" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

//定义共用体
union MyUnion {
    int x;
    int y;
    double z;
};

JNIEXPORT
jstring
JNICALL
Java_com_ndk_use_NdkC_ndkc05(JNIEnv *env, jclass type) {
    //*********************************知识点：union 联合体（共用体）*****************************

    /*
     * union定义：
     *      共用体是一种特殊的数据类型，允许您在相同的内存位置存储不同的数据类型。
     *      您可以定义一个带有多成员的共用体，但是任何时候只能有一个成员带有值。
     *      共用体提供了一种使用相同的内存位置的有效方式。
     * */


    union MyUnion myUnion;
    LOGW("union=%d", myUnion.x);//union=-1266793216
    myUnion.x = 1;
    myUnion.y = 2;//最后一个赋值有效（因为使用相同的内存位置）
    LOGW("union=%d,%d", myUnion.x, myUnion.y);//union=2,2

    return (*env)->NewStringUTF(env, "Hello from JNI!");
}

