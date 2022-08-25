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
LeetCode 剑指offerⅡ
time: 2021-12-20 21:45:42
author: edinw
@
*/

namespace leetcode_cpp {
class Solution{
public:
    std::string addBinary(std::string a, std::string b) {
        std::string ans;
        std::reverse(a.begin(), a.end());
        std::reverse(b.begin(), b.end());

        int n = std::max(a.size(), b.size());
        int carry = 0;
        for (size_t i = 0; i < n; ++i) {
            carry += i < a.size() ? (a.at(i) == '1') : 0;
            carry += i < b.size() ? (b.at(i) == '1') : 0;
            ans.push_back((carry % 2) ? '1' : '0');
            carry /= 2;
        }

        if (carry) {
            ans.push_back('1');
        }
        std::reverse(ans.begin(), ans.end());

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string a = "1010", b = "1011"; 
    std::cout << leetcode_cpp::Solution().addBinary(a, b) << std::endl;
    return 0;
}
