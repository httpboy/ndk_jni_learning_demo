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
    int a[1024 * 1024];//1M
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

    //*********************************知识点：创建一个数组,开辟内存*****************************

    /*int i = 10;
    int a[i];//静态内存分配创建数组，固定的数组大小*/

    int length = 6;
    //动态开辟内存，大小length*4字节
    int *p = malloc(length * sizeof(int));
    //p是数组元素的首地址
    for (int i = 0; i < length; ++i) { //动态赋值
        p[i] = i;
        LOGE("p[%d]=%d", i, p[i]);
    }


    //realloc 重新分配内存
    int addSize = 1024 * 1024 * 10;//10M
    //void* realloc(void* p, size_t byte_count) 参数1：指针  参数2：内存扩大之后的总大小
    int *p2 = realloc(p, length * sizeof(int) + addSize);
    if (p2 == NULL) {
        LOGE("分配内存失败");
    }
    LOGE("旧指针=%X,新指针=%X", p, p2);
    //手动释放内存
    if (p != NULL) {
        free(p);
        p = NULL;
    }
    if (p2 != NULL) {
        free(p2);
        p2 = NULL;
    }
    //不能多次释放
    //free(p2);



    //关于内存分配有几个问题需要详细说一下：参考：http://blog.csdn.net/a2806005024/article/details/37656321
    /*该函数的使用涉及以下几个问题：
          1.不同情况下的返回值
          2.旧指针指向的内存会不会自动释放
          3.旧指针和新指针分别是什么内容，他们有什么关系

       回答：
       1.检查OldPtr指向的内存块后面的可用内存是否满足本次realloc的需求，如果满足，
       则将尾部的可用内存也分配给该内存块——指针指向位置不变，内存块内容不变
       ，指向内存块扩大。该情况下，返回值NewPtr = OldPtr;
       2.如果OldPtr指向内存块后面的可用内存不够realloc的需求。
       则完成以下三个步骤
            <a>将在可用内存中重新分配一段大小的内存，并将这段内存的开始地址返回给NewPtr。
            <b>将OldPtr内存块的内容复制到NewPtr内存块。
            <c>OldPtr的值不变，但其指向的内存块被释放（注意：是自动释放，不用主动调用free）。
       3.如果整个堆当中都没有任何一处的内存能够满足realloc的需求。则此次分配失败，返回值为NULL。

       结论：在程序中realloc使用中，将OldPtr和NewPtr使用同一个指针是不妥的。
       使用截图对应程序中的做法较为妥当。既然能够避免分配失败返回NULL之后丢失原有指针。
       也能同时得到旧指针和新指针指向的内存块。
    */

    return (*env)->NewStringUTF(env, "Hello from JNI!");
}

