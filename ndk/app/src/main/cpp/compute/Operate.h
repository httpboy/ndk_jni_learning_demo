
#include <string.h>
#include <jni.h>

//C 实现的 加法
int addFun(int x, int y);

//C 实现的 减法
int subFun(int x, int y);

//用函数指针实现--加减
int compute(int (*p)(int, int), int a, int b);

//返回最小数的地址
int *getMinPointer(int numbers[], int len);