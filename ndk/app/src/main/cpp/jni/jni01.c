//
// jni:C语言编译执行过程详解、防止文件重复引入
//
#include <jni.h>
#include <android/log.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "A.h"


#define TAG "myDemo-jni" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

//定义一个实现头文件函数的宏函数
void aSayHello() {
    LOGI("aSayHello");

}

//定义一个实现头文件函数的宏函数
void bSayHello() {
    LOGI("bSayHello");
}

JNIEXPORT
jstring
JNICALL
Java_com_ndk_use_NdkJni_ndkJni01(JNIEnv *env, jclass type) {

    //*********************************知识点：C语言编译执行过程详解 *****************************

    //参考： http://blog.csdn.net/xiaofei0859/article/details/50556737

    /*
     * C源代码
            编译---->形成目标代码，目标代码是在目标机器上运行的代码。
            连接---->将目标代码与C函数库相连接，并将源程序所用的库代码与目标代码合并，并形成最终可执行的二进制机器代码（程序）。
            执行----->在特定的机器环境下运行C程序。

       C源程序头文件－－>预编译处理(cpp)－－>编译程序本身－－>优化程序－－>汇编程序－－>链接程序-->可执行文件
     *
     * */


    //*********************************知识点：防止文件重复引入*****************************

    /*
     * A.h   B.h  头文件中有注释
     * */
    aSayHello();//aSayHello
    bSayHello();//bSayHello


    return (*env)->NewStringUTF(env, "Hello from JNI!");
}

