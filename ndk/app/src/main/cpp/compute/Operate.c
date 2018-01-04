#include "Operate.h"

/**
 * C 实现的 加法
 */
int addFun(int x, int y) {
    return x + y;
}

/**
 * C 实现的 减法
 */
int subFun(int x, int y) {
    return x - y;
}

/**
 * 用函数指针实现--加减
 */
int compute(int (*fun)(int, int), int m, int n) {
    return fun(m, n);
}

/**
 * 返回最小数的地址
 */
int *getMinPointer(int numbers[], int len) {
    int min = numbers[0];
    for (int i = 0; i < len; ++i) {
        if (numbers[i] < min) {
            min = numbers[i];
        }
    }
    return &min;
}