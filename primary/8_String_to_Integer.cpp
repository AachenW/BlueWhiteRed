#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <numeric>
#include <limits.h>

/*
@
LeetCode 精选 TOP 面试题
time: 2021-12-12 20:44:26
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int myAtoi(std::string s) {
        int ans = 0;
        int i = 0;
        int sLength = s.size();
        int sign = 1;
        while(s[i] == ' ') {
            ++i;
        }
        if(s[i] == '-') {
            sign = -1;
        }
        if(s[i] == '+' || s[i] == '-') {
            ++i;
        }
        while(i < sLength && isdigit(s[i])) {
            int r = s[i] - '0';
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && r > 7)) {
                return sign > 0 ? INT_MAX : INT_MAX;
            }
            ans = ans * 10 + r;
            i++;
        }
        return sign > 0 ? ans : -ans;
    }
};
}

int main(int argc, char** argv) {
    std::string s = "4193 with words";
    std::cout << leetcode_cpp::Solution().myAtoi(s) << std::endl;
}