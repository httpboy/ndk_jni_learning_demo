//
// c语言:字符数组存储字符串
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
Java_com_ndk_use_NdkC01_ndkc03(JNIEnv *env, jclass type) {
    //*********************************知识点：创建字符数组存储字符串*****************************

    //参考：http://www.jb51.net/article/37456.htm
    /*
     * C语言规定了一个“字符串结束标志”，以字符'\0'代表。
     *
     * */
    char str1[] = {'A', 'n', 'd', 'r', 'o', 'i', 'd'};
    LOGF("str1=%s", str1);//str1=Android����
    char str2[] = {'A', 'n', 'd', 'r', 'o', 'i', 'd', '\0'};
    LOGF("str2=%s", str2);//str2=Android
    /*  Android明明是7个字符，为什么我要用8呢，你自己换成7试试就知道结果了
     *  因为字符串常量"Android"的最后由系统自动加上一个'\0'，所以就是8了
     * */
    char str3[8] = {'A', 'n', 'd', 'r', 'o', 'i', 'd'};//str3=Android
    LOGF("str3=%s", str3);//str2=Android
    char str4[] = "china";
    LOGF("str4=%s", str4);//str3=china
    //可以修改
    str3[0] = 's';

    //*********************************知识点：字符指针*****************************

    //参考：https://www.cnblogs.com/mjios/archive/2013/03/18/2965750.html
    char *string = "how are you ? Im Ok";
    LOGF("string=%s", string);//string=how are you ? Im Ok

    //修改指针，修改值，竟然报错了，我也才知道，之前我都不知道啊。
    /*  string += 1;//指针指向o这个位置
      *string = "6666";*/
    string += 1;
    LOGF("string=%s", string);//那我打印可以吧，string=ow are you ? Im Ok

    /*  结论：指针变量string指向的是一块字符串常量，正因为是常量，所以它内部的字符是不允许修改的。
     *  char string[] = "how are you ? Im Ok";定义的是一个字符串变量！
     *  char *string = "how are you ? Im Ok";定义的是一个字符串常量！
     * */

    //*********************************知识点：字符串操作函数#include <string.h>*****************************
    //参考:https://www.cnblogs.com/alaigle/archive/2012/05/24/2516062.html


    //strcpy 功能:  把src所指由NULL结束的字符串复制到dest所指的数组中,并且返回dest的字符指针。
    char src[] = "我的微信号公众号是：走向全栈工程师";
    char dest[100];
    LOGF("dest=%X", dest);//dest=BEE4EB94
    char *destPinter = strcpy(dest, src);
    LOGF("destPinter=%X,dest=%s", destPinter, dest);//destPinter=BEE4EB94,dest=我的微信号公众号是：走向全栈工程师


    // strcat 功能: 字符串拼接函数,把src所指字符串的前n个字符添加到dest结尾处(覆盖dest结尾处的'\0')并添加'\0'。

    char *strcatSrc = "，好像很装逼啊";
    strcat(dest, strcatSrc);
    LOGE("dest=%s", dest);//dest=我的微信号公众号是：走向全栈工程师，好像很装逼啊

    // strchr 功能: 查找字符串s中首次出现字符c的位置
    char *src2 = "Im ok ha ha ha";
    char *p = strchr(src2, 'm');
    if (p) {
        LOGE("微信号公众号的索引p[%d]", (p - src2));//微信号公众号的索引p[1]
    } else {
        LOGE("没有找到");//
    }

    // strstr 功能: 从字符串haystack中寻找needle第一次字符串出现的位置（不比较结束符NULL)
    char *p2 = strstr(src2, "ok ha");//微信号公众号的索引p[1]
    if (p2) {
        LOGE("微信号公众号的索引p[%d]", (p2 - src2));//微信号公众号的索引p[3]
    } else {
        LOGE("没有找到");//
    }

    char *p3 = strstr(src2, "ok ha666");//
    LOGE("找不到时p3=%X", p3);//找不到时p3=0


    /*结论，太多了，不说了，举两个例子就好了*/
    return (*env)->NewStringUTF(env, "Hello from JNI!");
}

