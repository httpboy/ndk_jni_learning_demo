//导入头文件，有点类似java中的导包
#include <jni.h>
#include <string>
//C语言方式编译和连接的
extern "C"
//JNI 数据类型 jstring 为 返回值 ,也可以为 void , jint 等等 类型
JNIEXPORT jstring JNICALL
//Java_com_ndk_use_JniUtils_stringFromJNI  Java\包名\类名\方法名
//参数1：JNIEnv类型实际上代表了Java环境，通过这个JNIEnv *env指针，就可以对Java端的代码进行操作
//参数2：jobject表明这个函数是一个实例方法，指向这个实例对象。
//jclass，表明是个静态方法，指向这个类的class
Java_com_ndk_use_HelloJni_stringFromJNI(JNIEnv *env, jclass type) {
    //标准C++库字符串类std::string的用法
    std::string hello = "Hello from C++";
    //jstring rtstr = env->NewStringUTF(hello.c_str());
    //GetStringUTFChars和NewStringUTF都是JNI提供的处理String类型的函数
    return env->NewStringUTF(hello.c_str());
}