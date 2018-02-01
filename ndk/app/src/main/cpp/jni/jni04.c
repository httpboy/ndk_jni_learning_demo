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


//给JNINativeInterface_ 结构体指针取别名JNIEnv_
typedef const struct JNINativeInterface_ *JNIEnv_;

//创建一个结构体
struct JNINativeInterface_ {
    //声明指针函数
    char *(*NewStringUTF_)(JNIEnv_ *, char *);
};

//创建一个NewStringUTF_函数
char *NewStringUTF_(JNIEnv_ *env, char *text) {

    return text;

}


JNIEXPORT
jstring
JNICALL
Java_com_ndk_use_NdkJni_ndkJni03Env(JNIEnv *env, jclass j_class) {

    //*********************************知识点：理解JNIEnv *env(c语言) *****************************

    //实例化结构体
    struct JNINativeInterface_ structJNINativeInterface_;
    structJNINativeInterface_.NewStringUTF_ = NewStringUTF_;
    //初始化结构体指针
    JNIEnv_ env_1 = &structJNINativeInterface_;
    //初始化结构体二级指针
    JNIEnv_ *env_2 = &env_1;
    //通过结构体二级指针去调用NewStringUTF_
    char *text = (*env_2)->NewStringUTF_(env_2, "理解JNIEnv *env(c语言)模拟创建JniEnv");

    return (*env)->NewStringUTF(env, text);


}
