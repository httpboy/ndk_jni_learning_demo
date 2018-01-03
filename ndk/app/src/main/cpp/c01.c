//
// Created by Administrator on 2018/1/3.
//
#include <jni.h>
#include <android/log.h>

#define TAG "myDemo-jni" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

JNIEXPORT
jstring
JNICALL
Java_com_ndk_use_NdkC01_ndkc01(JNIEnv *env, jclass type) {
    //知识点：定义基本数据类型
    char f = 1;
    short b = 2;
    int a = 1;
    long c = 3;
    float d = 23.3;
    double e = 23.300;
    //知识点：基本数据类型所占的字节数//
    // int(%d) short(%d)  long (%ld)  float (%f)  double (%lf) char (%c)
    LOGD("char字节数 = %d", sizeof(char));
    LOGD("short字节数 = %d", sizeof(short));
    LOGD("int字节数 = %d", sizeof(int));
    LOGD("long字节数 = %d", sizeof(long));
    LOGD("float字节数 = %d", sizeof(float));
    LOGD("double字节数 = %d", sizeof(double));

    //知识点：for语句
    int n = 0;
    for (; n < 10; n++) {
        LOGD("%d", n);
    }

    //知识点：指针（16进制表示）
    int i = 520;
    LOGD("i地址=%#X", &i);//&i i变量的地址
    int *p = &i;//创建int类型的指针  int *p
    LOGD("p地址=%#X", p);//p 指向i变量的地址
    LOGD("&p指针地址=%#X", &p);//&p 指针自身地址
    LOGD("p指针指向的地址内容=%d", *p);//*p 指针地址的内容

    //知识点：指针类型和地址的关系（指针有类型  地址没有类型）
    int i2 = 6;
    int *p2 = &i2;
    double d2 = 7;
    p2 = &d2;
    LOGD("d2地址=%#X,p2地址=%#X,p2的内容=%d", &d2, p2, *p2);
    //d2地址 = 0XBEE4EC48, p2地址 = 0XBEE4EC48, p2的内容 = 0
    //用int类型4字节的指针读取8字节的内容是不行的。怎么理解指针类型呢？
    //如果定义了一个int *p类型的指针，就会栈内存以起始位置为&p，大小的int的四字节作为连续的存储空间
    //所以这里用4字节的地址读取8字节的内容肯定是有问题的。

    //如果定义了一个double类型的数据，确用int来接收，会出现什么问题呢
    double d3 = 9;
    LOGD("d3=%d", d3);//d3=3，我曹，这个答案是什么鬼。
    //所以当你传入给printf一个double类型的参数，
    // 却用了%d时，printf会把那个参数当作int型来读取的，
    // 而通常int和double在计算机中的存储方式是不一样的
    // ，于是会得到错误的值。
    return (*env)->NewStringUTF(env, "Hello from JNI!");
}

