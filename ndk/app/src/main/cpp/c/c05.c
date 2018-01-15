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

//定义枚举（列举所有的情况）: 限定取值范围
enum Day {
    Monday = 0,
    Tuesday = 1,
    Wednesday = 2,
    Thursday,
    Friday,
    Saturday,
    Sunday
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



    //*********************************知识点：枚举 *****************************
    //参考   https://www.cnblogs.com/JCSU/articles/1299051.html

    //使用枚举类型声明变量同时对枚举型变量赋值
    enum Day enumDay = Sunday;
    LOGW("enumDay=%X,星期%d", &enumDay, enumDay + 1);//enumDay=BEEECC38,星期7

    return (*env)->NewStringUTF(env, "Hello from JNI!");
}

