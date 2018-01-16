//
// jni:参数介绍、JNI数据类型
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
Java_com_ndk_use_NdkJni_ndkJni02(JNIEnv *env, jclass type) {

    //*********************************知识点：Java_com_ndk_use_NdkJni_ndkJni02 参数介绍 *****************************
    /*
     * JNIEnv *env
     *      JNIEnv 结构体指针
     *      env 结构体二级指针
     *      代表Java运行环境，调用Java中的代码
     * jclass type
     *      jclass 表明是java声明了一个静态方法，指向这个类的class
     *
     * jobject object
     *      jobject 表明是java声明了一个非静态方法，指向这个类的对象
     *
     *
     * */

    //*********************************知识点：JNI数据类型 *****************************


    /**
     * 基本数据类型：
     *      boolean（布尔型）	      jboolean		无符号8个比特
            byte(字节型)	          jbyte		    有符号8个比特
            char(字符型)	          jchar		    无符号16个比特
            short(短整型)	          jshort		有符号16个比特
            int(整型)	              jint		    有符号32个比特
            long(长整型)	          jlong		    有符号64个比特
            float(浮点型)	          jfloat		32个比特
            double(双精度浮点型)	  jdouble		64个比特
            void(空型)	              void		    N/A（不适用）
     *
     *
     * 引用类型：
     *      jobject
     *          jclass
     *          jstring
     *          jarray
     *             jobjectArray
     *             jbooleanArray
     *             jbyteArray
     *             jcharArray
     *             jshortArray
     *             jintArray
     *             jlongArray
     *             jfloatArray
     *             jdoubleArray
     *          jthrowable
     *
     *
     *  jvalue类型：jvalue是一个unio（联合）类型，在C语中为了节约内存，会用联合类型变量来存储声明在联合体中的任意类型数据 。
     *       typedef union jvalue {
                    jboolean z;
                    jbyte    b;
                    jchar    c;
                    jshort   s;
                    jint     i;
                    jlong    j;
                    jfloat   f;
                    jdouble  d;
                    jobject  l;
                                 } jvalue;
     *
     *
     *
     */


    //*********************************知识点：JNI基本数据类型 *****************************


    return (*env)->NewStringUTF(env, "Hello from JNI!");
}

