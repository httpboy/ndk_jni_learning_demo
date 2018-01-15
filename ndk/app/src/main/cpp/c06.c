//
// c语言:文件流I/O操作、文件加密解密
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

    /*const char *jstr_filePath = (*env)->GetStringUTFChars(env, filePath, NULL);//string-jstring
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
    //api文档：http://ganquan.info/standard-c/

    /*
     * 如果处理的是二进制文件，则需使用下面的访问模式来取代上面的访问模式：
     * "rb", "wb", "ab", "rb+", "r+b", "wb+", "w+b", "ab+", "a+b"
     * */

    /* const char *jstr_filePath = "/storage/emulated/0/img.jpg";
     const char *jstr_destFilePath = "/storage/emulated/0/img_new.jpg";
     FILE *read_fp = fopen(jstr_filePath, "rb");
     FILE *write_fp = fopen(jstr_destFilePath, "wb");

     char buffer[1024];//缓冲
     int len = 0;//每次读取的长度

     while ((len = fread(buffer, sizeof(char), 1024, read_fp)) != 0) {
         fwrite(buffer, sizeof(char), len, write_fp);//将读到的内容写入文件
     }
     fclose(read_fp);
     fclose(write_fp);*/

    //*********************************知识点：获取文件的大小 *****************************


    /*const char *jstr_filePath = "/storage/emulated/0/img.jpg";
    FILE *fp = fopen(jstr_filePath, "r");
    //SEEK_END:定位到文件末尾，偏移量为0
    fseek(fp, 0, SEEK_END);
    //函数 ftell 用于得到文件位置指针当前位置相对于文件首的偏移字节数
    long fileSize = ftell(fp);
    LOGE("文件大小==%ld", fileSize);//文件大小==33454
    fclose(fp);*/


    //*********************************知识点：文本文件的加密解密 *****************************

    /*
     * 异或加密
     *      1^1=0, 0^1=1，同一个数异或两次还是本身
     *
     *
     *
     * */

    /*const char *jstr_filePath = (*env)->GetStringUTFChars(env, filePath, NULL);//string-jstring
    const char *jstr_destFilePath = "/storage/emulated/0/boy_new.txt";
    //打开文件，允许写入文件
    FILE *before_fp = fopen(jstr_filePath, "r");
    FILE *after_fp = fopen(jstr_destFilePath, "w");

    int ch;
    while ((ch = fgetc(before_fp)) != EOF) {
        fputc(ch ^ 666, after_fp);
    }

    fclose(before_fp);
    fclose(after_fp);
    (*env)->ReleaseStringUTFChars(env, filePath, jstr_filePath);//释放*/


    /*
    * 异或解密
    *      1^1=0, 0^1=1，同一个数异或两次还是本身
    *
    *
    *
    * */


    /*const char *jstr_encrypt_Path = "/storage/emulated/0/boy_new.txt";
    const char *jstr_deEncrypt_Path = "/storage/emulated/0/boy_new_deEncrypt.txt";
    //打开文件，允许写入文件
    FILE *before_fp = fopen(jstr_encrypt_Path, "r");
    FILE *after_fp = fopen(jstr_deEncrypt_Path, "w");

    int ch;
    while ((ch = fgetc(before_fp)) != EOF) {
        fputc(ch ^ 666, after_fp);
    }

    fclose(before_fp);
    fclose(after_fp);*/


//*********************************知识点：二进制文件加密解密 *****************************

    /*
     * 二进制文件异或加密
     *      1^1=0, 0^1=1，同一个数异或两次还是本身
     *
     * 本案例一个一个字符读取并且加密
     *
     *
     *
     * */


    /*const char *before_Path = "/storage/emulated/0/img.jpg";
    const char *encryt_Path = "/storage/emulated/0/img_encrypt.jpg";
    //打开文件，允许写入文件
    FILE *before_fp = fopen(before_Path, "rb");
    FILE *encryt_fp = fopen(encryt_Path, "wb");

    char passwords[] = "rsa";

    int ch;
    int i = 0;
    int pwd_len = strlen(passwords); //密码的长度
    while ((ch = fgetc(before_fp)) != EOF) {
        fputc(ch ^ passwords[i++ % pwd_len], encryt_fp);
    }

    fclose(before_fp);
    fclose(encryt_fp);*/



    /*
   * 二进制文件异或解密
   *      1^1=0, 0^1=1，同一个数异或两次还是本身
   *
   * 本案例一个一个字符读取并且解密
   *
   *
   *
   * */

    const char *encryt_Path = "/storage/emulated/0/img_encrypt.jpg";
    const char *de_encryt_Path = "/storage/emulated/0/img_de_encryt.jpg";
    //打开文件，允许写入文件
    FILE *encryt_fp = fopen(encryt_Path, "rb");
    FILE *de_encryt_fp = fopen(de_encryt_Path, "wb");

    char passwords[] = "rsa";

    int ch;
    int i = 0;
    int pwd_len = strlen(passwords); //密码的长度
    while ((ch = fgetc(encryt_fp)) != EOF) {
        fputc(ch ^ passwords[i++ % pwd_len], de_encryt_fp);
    }

    fclose(encryt_fp);
    fclose(de_encryt_fp);
    return (*env)->NewStringUTF(env, "Hello from JNI!");
}

