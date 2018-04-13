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
Java_com_ndk_use_NdkJni_exeception(JNIEnv *env, jobject j_obj) {

    //*********************************知识点：Java层捕捉native异常 *****************************
    //获取jclass
    jclass j_class = (*env)->GetObjectClass(env, j_obj);
    //获取jfieldID
    jfieldID j_fid = (*env)->GetFieldID(env, j_class, "method", "Ljava/lang/String666;");
    //检测是否发生Java异常
    jthrowable exception = (*env)->ExceptionOccurred(env);
    if (exception != NULL) {
        LOGE("jni发生异常");
        //jni清空异常信息
        (*env)->ExceptionClear(env);
        //异常出现的问题，如何处理
        j_fid = (*env)->GetFieldID(env, j_class, "method", "Ljava/lang/String;");
        //获取java成员变量int值
        jstring j_stirng = (*env)->GetObjectField(env, j_obj, j_fid);
        //jstring--string
        const char *chs = (*env)->GetStringUTFChars(env, j_stirng, NULL);
        LOGI("method==%s", chs);//method==暂时没被访问
        //Set<Type>Field    修改method的值改为:native的异常解决了
        const char *text = "native的异常解决了";
        jstring j_newString = (*env)->NewStringUTF(env, text);
        (*env)->SetObjectField(env, j_obj, j_fid, j_newString);
    }

    return (*env)->NewStringUTF(env, "jni层自行处理native异常");
}


JNIEXPORT
void
JNICALL
Java_com_ndk_use_NdkJni_throwexeception(JNIEnv *env, jobject j_obj) {

    //*********************************知识点：Java层捕捉native异常 *****************************
    //获取jclass
    jclass j_class = (*env)->GetObjectClass(env, j_obj);
    //获取jfieldID
    jfieldID j_fid = (*env)->GetFieldID(env, j_class, "method", "Ljava/lang/String;");
    //获取java成员变量int值
    jstring j_stirng = (*env)->GetObjectField(env, j_obj, j_fid);
    //jstring--string
    const char *chs = (*env)->GetStringUTFChars(env, j_stirng, NULL);
    LOGI("method==%s", chs);//method==暂时没被访问

    //根据获取到的 method来判断是否合法

    /**
     * strcmp
            C/C++函数，比较两个字符串
            设这两个字符串为str1，str2，
            若str1==str2，则返回零；
            若str1 > str2，则返回正数；
            若str1< str2，则返回负数。
     *
     */

    if (strcmp(chs, "全栈工程师") != 0) {
        //认为抛出异常，给Java层处理
        jclass newExcCls = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        (*env)->ThrowNew(env, newExcCls, "method参数不合法");
    }
}