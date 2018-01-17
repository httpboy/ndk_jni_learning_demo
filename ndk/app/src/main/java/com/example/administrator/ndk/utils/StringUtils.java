package com.example.administrator.ndk.utils;

/**
 * author: Administrator
 * created on: 2018/1/17 23:01
 * description:
 */
public class StringUtils {

    public static String intArraysToString(int[] numbers) {
        StringBuilder sb = new StringBuilder();
        sb.append("{");
        for (int i = 0; i < numbers.length; i++) {
            if (i == numbers.length-1) {
                sb.append(numbers[i] + "}");
            } else {
                sb.append(numbers[i] + ",");
            }
        }

        return sb.toString();
    }

}
