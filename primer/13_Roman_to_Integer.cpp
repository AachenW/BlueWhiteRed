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
time: 2021-12-12 22:09:02
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
private:
    std::unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

public:
    int romanToInt(std::string s) {
        int highestNum = 0;
        int sLength = s.size();
        int ans = 0;
        for (int i = sLength - 1; i >= 0; --i) {
            int val = symbolValues[s[i]];
            if (val >= highestNum) {
                ans += val;
                highestNum = val;
            } else {
                ans -= val;
            }
        }
        return ans;
    }
};
}

int main(int argc, char** argv) {
    std::string s {"MCMXCIV"};
    std::cout << leetcode_cpp::Solution().romanToInt(s) << std::endl;
}