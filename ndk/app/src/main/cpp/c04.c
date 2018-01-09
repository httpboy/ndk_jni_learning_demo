//
// c语言:结构体(用户自定义的数据类型)
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

//创建一个结构体，定义简单的结构体成员
struct People {
    //成员变量
    char name[20];
    int age;
};

//创建一个结构体,定义变量man1 man2
struct Man {
    char name[20];
    int age;
} man1, man2;

//创建一个结构体,定义变量woman1, woman2并且初始化值
struct woman {
    char name[20];
    int age;
} woman1 = {"Android 1.0", 90}, woman2 = {"Android 6.0", 100};

//创建一个匿名结构体,定义变量instance，相当于java中的单例模式
struct {
    char name[20];
    int age;
} instance;


//结构体嵌套，可以理解为java中自定义class中有class
struct Son {
    char *name;
    int age;
};


struct Parent {
    char *name;
    int age;
    struct Son son; //嵌套外部结构体，可以理解为java的非内部类

};
struct Parent2 {
    char *name;
    int age;
    struct Son2 {
        char *name;
        int age;
    } son; //嵌套内部结构体，可以理解为java的内部类

};

JNIEXPORT
jstring
JNICALL
Java_com_ndk_use_NdkC_ndkc04(JNIEnv *env, jclass type) {
    //*********************************知识点：创建一个结构体，定义简单的结构体成员*****************************

    //结构体声明
    struct People people1;
    //结构体成员初始化
    strcpy(people1.name, "Android");
    people1.age = 18;
    LOGI("%s,%d", people1.name, people1.age);//Android,18


    //结构体声明并初始化
    struct People people2 = {"Android 8.0", 20};
    LOGI("%s,%d", people2.name, people2.age);//Android 8.0,20

    //定义一个People类型的结构变量
    struct People people3 = people2;
    people3.age = 666;
    LOGF("%s,%d", people3.name, people3.age);//Android 8.0,666

    //*********************************知识点：创建一个结构体,定义变量man1 man2*****************************

    man1.age = 777;
    strcpy(man1.name, "Android 5.0");
    LOGF("%s,%d", man1.name, man1.age);//Android 5.0,777

    //*********************************知识点：创建一个结构体,定义变量woman1 woman2并且初始化值*****************************

    LOGF("%s,%d", woman1.name, woman1.age);// Android 1.0,90
    LOGF("%s,%d", woman2.name, woman2.age);// Android 6.0,100

    //*********************************知识点：创建一个匿名结构体,定义变量instance，相当于java中的单例模式*****************************

    instance.age = 666666;
    strcpy(instance.name, "单例模式");
    LOGF("%s,%d", instance.name, instance.age);// 单例模式,666666

    //*********************************知识点：结构体嵌套1，可以理解为java中自定义class中有class*****************************

    struct Parent parent = {"parent", 20, {"son", 1}};
    LOGF("parent==%s,%d,son==%s,%d", parent.name, parent.age, parent.son.name,
         parent.son.age);//  parent==parent,20,son==son,1

    //*********************************知识点：结构体嵌套2，可以理解为java中自定义class中有class*****************************

    struct Parent2 parent2;
    parent2.age = 100;
    parent2.name = "父亲";
    parent2.son.name = "孩子";
    parent2.son.age = 14;
    LOGF("parent==%s,%d,son==%s,%d", parent2.name, parent2.age, parent2.son.name,
         parent2.son.age);//parent==父亲,100,son==孩子,14

    //*********************************知识点：结构体与指针*****************************

    struct People people = {"hello", 666};
    LOGF("%s,%d", people.name, people.age);// hello,666
    //定义一个结构体指针
    struct People *pointer = &people;
    LOGF("%s,%d", (*pointer).name, (*pointer).age);// hello,666
    LOGF("%s,%d", pointer->name, pointer->age);//hello,666

    //*********************************知识点：指针与结构体数组*****************************

    struct People people4[] = {{"数组1", 1},
                               {"数组2", 2}};

    //结构体数组遍历1
    //怎么理解：sizeof(people4) / sizeof(struct People)   个数=总重量/没个人多少重量
    for (int i = 0; i < sizeof(people4) / sizeof(struct People); ++i) {
        LOGF("%s,%d", people4[i].name, people4->age);//数组1,1  数组2,1
    }

    //结构体数组遍历2
    struct People *tempPointer = people4;//*tempPointer指向数组首元素地址
    for (; tempPointer < people4 + 2; ++tempPointer) {
        LOGF("%s,%d", tempPointer->name, tempPointer->age);//数组1,1  数组2,1
    }


    //*********************************知识点：结构体的大小（字节对齐）*****************************
    //参考:http://blog.csdn.net/u012807459/article/details/48545141
    /*
     * 结构体大小计算
     *      结构体大小 会涉及到字节对齐(目的是 让计算机快速读写 以空间换取时间)。
     *      即，最后一个成员的偏移量加上最后一个成员的大小再加上末尾的填充字节数。
     * 结构体内偏移规则
     *      1、每个成员的偏移量都必须是当前成员所占内存大小的整数倍如果不是编译器会在成员之间加上填充字节。
            2、当所有成员大小计算完毕后，编译器判断当前结构体大小是否是结构体中最宽的成员变量大小的整数倍
            如果不是会在最后一个成员后做字节填充。
     *
     * */
    struct People people5 = {"hello world", 777};
    LOGF("name=%d,age=%d,结构体大小=%d", sizeof(people5.name), sizeof(people5.age),
         sizeof(struct People));//name=20,age=4,结构体大小=24
    /*结论：
     * 1、遇到第一个成员变量name，该成员偏移量为0，大小为20，符合偏移规则第一条(偏移量都必须是当前成员所占内存大小的整数倍)。
     * 2、遇到第一个成员变量age，该成员偏移量为20，大小为4，符合偏移规则第一条(偏移量都必须是当前成员所占内存大小的整数倍)。
     * */

    //*********************************知识点：结构体与mallloc动态内存分配*****************************

    struct People *p_pointer = malloc(sizeof(struct People) * 10);//24字节*10
    strcpy(p_pointer->name, "malloc");
    p_pointer->age = 100;
    LOGF("%s,%d", p_pointer->name, p_pointer->age);//malloc,100

    p_pointer++;

    p_pointer->age = 102;
    strcpy(p_pointer->name, "malloc2");

    LOGF("p_pointer[1]==%s,%d,p_pointer[2]==%s,%d", p_pointer->name, p_pointer->age,
         p_pointer->name, p_pointer->age);//malloc,100




    return (*env)->NewStringUTF(env, "Hello from JNI!");
}

