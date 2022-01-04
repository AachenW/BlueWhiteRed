#include <vector>
#include <iostream>
#include <algorithm>
/*
@
projetc: leetcode
time: 2022-01-02 19:10:27
author: edinw
@
*/

namespace leetcode_cpp {
class Solution{
public:
    int lastRemaining(int n) {
        int head = 1;
        int step = 1;
        bool left = true;
        while (n > 1) {
            //从左边开始移除 or（从右边开始移除，数列总数为奇数）
            if (left || n % 2 != 0) {
                // 修改head,head往前移一个step
                head += step;
            }
            step <<= 1;         // step翻倍
            n >>= 1;            // 总数n缩小
            left = !left;       // 取反移动方向
        }
        return head;
    }
};
}

int main(int argc, char **argv) {
    int n = 9;
    std::cout << leetcode_cpp::Solution().lastRemaining(n) << std::endl;
    return 0;
}