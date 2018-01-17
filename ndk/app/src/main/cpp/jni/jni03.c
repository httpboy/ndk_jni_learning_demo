//
// jni:
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
Java_com_ndk_use_NdkJni_ndkJni03(JNIEnv *env, jobject j_obj) {

    //*********************************知识点：访问java成员变量，并且修改非静态变量值 *****************************

    //获取jclass
    jclass j_class = (*env)->GetObjectClass(env, j_obj);
    //获取jfieldID
    jfieldID j_fid = (*env)->GetFieldID(env, j_class, "noStaticKeyValue", "I");
    //获取java成员变量int值
    jint j_int = (*env)->GetIntField(env, j_obj, j_fid);
    LOGI("noStaticKeyValue==%d", j_int);//noStaticKeyValue==0

    //Set<Type>Field    修改noStaticKeyValue的值改为666
    (*env)->SetIntField(env, j_obj, j_fid, 666);


    return (*env)->NewStringUTF(env, "Hello from JNI!");
}

JNIEXPORT
jstring
JNICALL
Java_com_ndk_use_NdkJni_ndkJni03SetValue(JNIEnv *env, jobject j_obj) {


    //*********************************知识点：访问java成员变量，并且修改静态变量值 *****************************
    //获取jclass
    jclass j_class = (*env)->GetObjectClass(env, j_obj);
    //获取jfieldID
    jfieldID j_fid = (*env)->GetStaticFieldID(env, j_class, "staticKeyValue", "Ljava/lang/String;");
    //获取java成员变量string值
    jstring j_str = (*env)->GetStaticObjectField(env, j_class, j_fid);
    //jstring--string
    const char *chs = (*env)->GetStringUTFChars(env, j_str, NULL);
    LOGI("staticKeyValue==%s", chs);//staticKeyValue==陈博易

    //string-jstring
    const char *text = "走向全栈工程师";
    jstring j_newString = (*env)->NewStringUTF(env, text);
    //Set<Type>Field    修改StaticKeyValue的值改为走向全栈工程师
    (*env)->SetStaticObjectField(env, j_class, j_fid, j_newString);


    (*env)->ReleaseStringUTFChars(env, j_str, chs);
    return (*env)->NewStringUTF(env, "Hello from JNI!");
}

JNIEXPORT
jstring
JNICALL
Java_com_ndk_use_NdkJni_ndkJni03SetMethod(JNIEnv *env, jobject j_obj) {

    //*********************************知识点：访问非静态java方法 *****************************
    //获取jclass
    jclass j_class = (*env)->GetObjectClass(env, j_obj);
    //获取jfieldID
    jmethodID j_mid = (*env)->GetMethodID(env, j_class, "setMethod", "(Ljava/lang/String;)V");
    //string-jstring
    const char *text = "访问非静态java方法";
    jstring j_newString = (*env)->NewStringUTF(env, text);
    (*env)->CallVoidMethod(env, j_obj, j_mid, j_newString);


    return (*env)->NewStringUTF(env, "Hello from JNI!");
}

JNIEXPORT
jstring
JNICALL
Java_com_ndk_use_NdkJni_ndkJni03SetStaticMethod(JNIEnv *env, jobject j_obj) {


    //*********************************知识点：访问静态java方法 *****************************

    //获取jclass
    jclass j_class = (*env)->GetObjectClass(env, j_obj);
    //获取jfieldID
    jmethodID j_mid = (*env)->GetStaticMethodID(env, j_class, "setStaticMethod",
                                                "(Ljava/lang/String;)V");
    //string-jstring
    const char *text = "访问静态java方法";
    jstring j_newString = (*env)->NewStringUTF(env, text);
    (*env)->CallStaticVoidMethod(env, j_class, j_mid, j_newString);

    return (*env)->NewStringUTF(env, "Hello from JNI!");
}

JNIEXPORT
jint
JNICALL
Java_com_ndk_use_NdkJni_ndkJni03CallConstructorMethod(JNIEnv *env, jobject j_obj) {


    //*********************************知识点：访问java构造方法 com.example.administrator.ndk.MyClass *****************************

    //获取jclass
    jclass j_class = (*env)->FindClass(env, "com/example/administrator/ndk/MyClass");
    //找到构造方法jmethodID   public MyClass(int width, int height)
    jmethodID j_constructor_methoid = (*env)->GetMethodID(env, j_class, "<init>", "(II)V");
    //初始化java类构造方法  public MyClass(int width, int height)
    jobject j_myClass_obj = (*env)->NewObject(env, j_class, j_constructor_methoid, 2, 3);


    //找到getArea()  jmethodID
    jmethodID j_getArea_methoid = (*env)->GetMethodID(env, j_class, "getArea", "()I");
    //调用java中的   public int getArea() 获取面积
    jint j_area = (*env)->CallIntMethod(env, j_myClass_obj, j_getArea_methoid);
    LOGI("面积==%d", j_area);//面积==6

    return j_area;
}
