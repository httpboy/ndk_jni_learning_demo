//
// jni:理解JNIEnv *env(c语言)
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


JNIEXPORT
jstring
JNICALL
Java_com_ndk_use_NdkJni_exeception(JNIEnv *env, jclass j_class) {

    //*********************************知识点：Java层捕捉native异常 *****************************
    jfieldID fid = (*env)->GetFieldID(env, j_class, "method", "Ljava/lang/String666;");
    //检测是否发生Java异常
    jthrowable exception = (*env)->ExceptionOccurred(env);
    if (exception != NULL) {
        LOGE("jni发生异常");
        //jni清空异常信息
        //(*env)->ExceptionClear(env);
    }

    return (*env)->NewStringUTF(env, "Java层捕捉native异常");


}
