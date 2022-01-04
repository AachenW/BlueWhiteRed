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

/*
@
LeetCode 精选 TOP 面试题
time: 2021-12-15 22:29:32
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int strstr(std::string haystack, std::string needle) {
        int n = haystack.size(), m = needle.size();
        for (int i = 0; i + m <= n; ++i) {
            bool flag = true;
            for (int j = 0; j < m; ++j) {
                if(haystack[i + j] != needle[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return i;
            }
        }
        return -1;
    }
};
}

int main(int argc, char **argv) {
    std::string haystake = "hello", needle = "ll";
    std::cout << leetcode_cpp::Solution().strstr(haystake, needle) << std::endl;
    return 0;
}