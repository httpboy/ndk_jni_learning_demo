//
// c语言基本数据类型和指针
//
#include <jni.h>
#include <android/log.h>
#include "compute/Operate.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
    //*********************************知识点：定义基本数据类型*****************************
    char f = 1;
    short b = 2;
    int a = 1;
    long c = 3;
    float d = 23.3;
    double e = 23.300;
    //*********************************知识点：基本数据类型所占的字节数*****************************
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

    //*********************************知识点：指针（16进制表示）*****************************
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
    LOGD("d3=%lf", d3);//d3=9.000000这个才对啊。

    //*********************************知识点：空指针*****************************
    int i4 = 9;
    int *p4 = NULL;
    LOGD("p4=%#X", p4);//空指针的默认值为0
    p4 = &i4;
    LOGD("*p4=%d", *p4);//取i4的值


    //*********************************知识点：多级指针（二级指针）*****************************
    int a5 = 50;
    int *p5 = &a5;//p5保存的a的地址
    int **pp5 = &p5;  //定义二级指针：二级指针pp5保存的一级指针p5的地址
    LOGD("a5=%#X,p5=%#X,pp5=%#X", &a5, p5, pp5);//打印地址
    **pp5 = 666;//pp5是指向p5的指针变量，*pp5取指针指向的内容（a5的地址）， ** pp5取a5的地址指向的内容
    LOGD("a5=%d", a5);//改变a5的数值，a5=666

    //*********************************知识点：指针运算*****************************

    int ids[] = {1, 2, 3, 4, 5};//数组在内存中连续存储
    LOGD("int数组的首地址=%#X", ids);//取数组的首地址
    LOGD("int数组的首地址=%#X", &ids);//取数组的首地址
    LOGD("int数组的首地址=%#X", &ids[0]);//取数组的首地址
    int *p6 = ids;
    LOGD("p6=%#X", p6);//p6指针指向的地址
    p6++;
    LOGD("p6=%#X", p6);//p6++  向前移动sizeof(数据类型)个字节，比如：0XBEE4EC40--》0XBEE4EC44
    p6--;
    LOGD("p6=%#X", p6);//p6--  向前移动sizeof(数据类型)个字节，比如：0XBEE4EC44--》0XBEE4EC40

    //*********************************知识点：数组*****************************
    int numbers[3]; // 该定义表示一个整型数组（并没有作初始化），共有3个元素，下标分别为[0]，[1]，[2],
    //类似java中的数组定义：int[] a = new int[3]; //初始化为默认值,int型为0

    LOGD("赋值前打印数组numbers[0]=%d,numbers[1]=%d,numbers[2]=%d", numbers[0], numbers[1],
         numbers[2]);//数组元素的值就是不确定的，尽量对数组进行初始化。

    //高级写法
//    for (int i7 = 0; i7 < 3; i7++) {
//        numbers[i7] = i7;
//        LOGD("赋值后打印数组numbers[%d]=%d", i7, numbers[i7]);//赋值后打印数组
//    }

    //早期版本的写法--利用指针
    int *p7 = numbers;
    int i7 = 0;
    for (; p7 < numbers + 3; p7++) {
        *p7 = i7;
        LOGD("赋值后打印数组numbers[%d]=%d", i7, numbers[i7]);//赋值后打印数组
        i7++;

    }

    //*********************************知识点：函数指针*****************************
    //int 函数返回值类型，*sum_add函数指针的名称，(int, int)函数的参数列表
    int (*sum_add)(int, int) = addFun;//add是自定义函数的地址
    int (*sum_sub)(int, int) = subFun;//add是自定义函数的地址
    LOGD("add自定义函数=%X", addFun);//打印函数名
    LOGD("add自定义函数=%X", &addFun);//打印函数地址：函数名=函数地址
    int sum = sum_add(3, 3);
    LOGD("sum=%d", sum);//
    int sub = sum_sub(3, 3);
    LOGD("sub=%d", sub);//
    //函数指针场景
    LOGD("函数指针add=%d", compute(addFun, 3, 3));//
    LOGD("函数指针sub=%d", compute(subFun, 3, 3));//
    //产生随机数
    srand((unsigned) time(NULL));//srand(seed)用于给rand()函数设定初始种子，有符号整数：int -xx - > +xx
    int randTimes[10];
    for (int i = 0; i < 10; ++i) {
        randTimes[i] = rand() % 100;
        LOGD("打印随机数=%d", randTimes[i] % 100);//打印随机数
    }
    int *pInt = getMinPointer(randTimes, sizeof(randTimes) / sizeof(int));
    LOGD("getMinPointer=%x,%d", pInt, *pInt);//打印随机数
    return (*env)->NewStringUTF(env, "Hello from JNI!");
}
