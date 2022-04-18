#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
public:
    int findNthDigit(int n) {
        int len = 1;//初始数字长度为1
        int base = 1;//初始范围为1~9
        while(n > (long)len * 9 * base){//如果n不在当前的数字范围内
            n -= len * 9 * base;//减去前面的数字的长度和
            len++;//下一轮计算的数字长度
            base *= 10;//范围为之前的10倍
        }
        int index = n - 1;//剩余的长度为n，这n个字符的编号是从0开始的，而我们要找的就是第n-1个字符
        int start = pow(10, len - 1);//当前范围内的最小值
        int num = start + index / len;//寻找n对应的数字，用n除以数字长度就知道是从start开始的第几个数字了
        int digit = index % len;//寻找n对应的数字的第几位
        return int(num / pow(10, len - digit - 1)) % 10;//取数字num的第digit位
    }
};
}