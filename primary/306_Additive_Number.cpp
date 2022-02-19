#include <string>
#include <algorithm>
#include <iostream>
/*
@
projetc: leetcode
time: 2022-01-10 19:17:49
author: edinw
@
*/

/*
累加数 是一个字符串，组成它的数字可以形成累加序列。

一个有效的 累加序列 必须 至少 包含 3 个数。除了最开始的两个数以外，字符串中的其他数都等于它之前两个数相加的和。

给你一个只包含数字 '0'-'9' 的字符串，编写一个算法来判断给定输入是否是 累加数 。如果是，返回 true ；否则，返回 false 。

说明：累加序列里的数 不会 以 0 开头，所以不会出现 1, 2, 03 或者 1, 02, 3 的情况

*/

namespace leetcode_cpp {
class Solution {
public:
    bool isAdditiveNumber(std::string num) {
        int n = num.length();
        for (int secondStart = 1; secondStart < n - 1; ++secondStart) {
            if (num[0] == '0' && secondStart != 1) {
                break;
            }
            for (int secondEnd = secondStart; secondEnd < n - 1; ++secondEnd) {
                if (num[secondStart] == '0' && secondStart != secondEnd) {
                    break;
                }
                if (checkValid(secondStart, secondEnd, num)) {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool checkValid(int secondStart, int secondEnd, std::string num) {
        int n = num.size();
        int firstStart = 0, firstEnd = secondStart - 1;
        while (secondEnd < n) {
            std::string third = stringAdd(num, firstStart, firstEnd, secondStart, secondEnd);
            int thirdStart = secondEnd + 1;
            int thirdEnd = thirdStart + third.length();
            if (thirdEnd >= n || !(num.substr(thirdStart, thirdEnd - thirdStart + 1) == third)) {
                break;
            }
            if (thirdEnd == n - 1) {
                return true;
            }
            firstStart = secondStart;
            firstEnd = secondEnd;
            secondStart = thirdStart;
            secondEnd = thirdEnd;
        }
        return false;
    }

    std::string stringAdd(std::string s, int firstStart, int firstEnd, int secondStart, int secondEnd) {
        std::string third;
        int carry = 0, cur = 0;
        while (firstEnd >= firstStart || secondEnd >= secondStart || carry != 0) {
            cur = carry;
            if (firstEnd >= firstStart) {
                cur += s[firstEnd] - '0';
                --firstEnd;
            }
            if (secondEnd >= secondStart) {
                cur += s[secondEnd] - '0';
                --secondEnd;
            }
            carry = cur / 10;
            cur %= 10;
            third.push_back(cur + '0');
        }
        std::reverse(third.begin(), third.end());
        return third;
    }
};
}

int main (int argc, char **argv) {
    std::string s {"199100199"};
    std::cout << std::boolalpha << leetcode_cpp::Solution().isAdditiveNumber(s) << std::endl;
    return 0;
}