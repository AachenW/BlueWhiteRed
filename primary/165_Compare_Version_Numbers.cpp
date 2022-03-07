#include <vector>
#include <string>
#include <iostream>
#include "../lib/ListNode.h"
#include "limits.h"
/*
@
LeetCode
time: 2022-02-26 21:12:32
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int compareVersion(std::string version1, std::string version2) {
        int sLen1 = version1.length(), sLen2 = version2.length();
        int i = 0, j = 0;

        while (i < sLen1 || j < sLen2) {
            int x = 0;
            for (; i < sLen1 && '.' != version1[i]; ++i) {
                x = x * 10 + version1[i] - 48;
            }
            ++i;
            int y = 0;
            for (; j < sLen2 && '.' != version2[j]; ++j) {
                y = y * 10 + version2[j] - 48;
            }
            ++j;
            if (x != y) {
                return x > y ? 1 : -1;
            }
        }

        return 0;
    }
};
}

int main(int argc, char **argv) {
    std::string version1 {"1.1"}, version2 {"1.001"};
    
    std::cout << leetcode_cpp::Solution().compareVersion(version1, version2) << std::endl;

    return 0;
}