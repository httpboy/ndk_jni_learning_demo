//
// c语言:文件流I/O操作
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
Java_com_ndk_use_NdkC_ndkc06(JNIEnv *env, jclass type, jstring filePath) {

    //*********************************知识点：写入文本文件*****************************

    /*
     * 访问模式 mode
     *      r	打开一个已有的文本文件，允许读取文件。
            w	打开一个文本文件，允许写入文件。如果文件不存在，则会创建一个新文件。在这里，您的程序会从文件的开头写入内容。
            a	打开一个文本文件，以追加模式写入文件。如果文件不存在，则会创建一个新文件。在这里，您的程序会在已有的文件内容中追加内容。
            r+	打开一个文本文件，允许读写文件。
            w+	打开一个文本文件，允许读写文件。如果文件已存在，则文件会被截断为零长度，如果文件不存在，则会创建一个新文件。
            a+	打开一个文本文件，允许读写文件。如果文件不存在，则会创建一个新文件。读取会从文件的开头开始，写入则只能是追加模式。

        如果处理的是二进制文件，则需使用下面的访问模式来取代上面的访问模式：
     *      "rb", "wb", "ab", "rb+", "r+b", "wb+", "w+b", "ab+", "a+b"
     *
     *
     * */

    /* const char *jstr_filePath = (*env)->GetStringUTFChars(env, filePath, NULL);//string-jstring
     LOGE("%s", jstr_filePath);// /storage/emulated/0/boy.txt
     //打开文件，允许写入文件
     FILE *fp = fopen(jstr_filePath, "w");
     char *writeString = "走向全栈工程师";
     fputs(writeString, fp);
     fclose(fp);
     (*env)->ReleaseStringUTFChars(env, filePath, jstr_filePath);//释放*/


    //*********************************知识点：读取文本文件*****************************

    /*const char *jstr_filePath = (*env)->GetStringUTFChars(env, filePath, NULL);
    LOGE("%s", jstr_filePath);//  /storage/emulated/0/boy.txt
    //打开文件，允许读取文件
    FILE *fp = fopen(jstr_filePath, "r");
    if (fp == NULL) {
        LOGE("文件打开失败...");
        return NULL;
    }
    //读取文本内容
    char chs[1024];
    while (fgets(chs, 1024, fp)) {
        LOGE("%s", chs);//走向全栈工程师
    }*/

    //*********************************知识点：文件复制 *****************************

    /*
     * 如果处理的是二进制文件，则需使用下面的访问模式来取代上面的访问模式：
     * "rb", "wb", "ab", "rb+", "r+b", "wb+", "w+b", "ab+", "a+b"
     * */
    const char *jstr_filePath = "/storage/emulated/0/img.jpg";
    const char *jstr_destFilePath = "/storage/emulated/0/img_new.jpg";
    FILE *read_fp = fopen(jstr_filePath, "rb");
    FILE *write_fp = fopen(jstr_destFilePath, "wb");

    int buffer[50];//缓冲
    int len = 0;//每次读取的长度

    while ((len = fread(buffer, sizeof(int), 50, read_fp)) != 0) {
        fwrite(buffer, sizeof(int), len, write_fp);//将读到的内容写入文件
    }
    fclose(read_fp);
    fclose(write_fp);


    return (*env)->NewStringUTF(env, "Hello from JNI!");
}

