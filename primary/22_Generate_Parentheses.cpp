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
time: 2021-12-15 22:14:00
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        if (n <= 0) {
            return res;
        }
        getParentheis("", n, n);
        return res;
    }

private:
    void getParentheis(std::string str, int left, int right) {
        if (0 == left && 0 == right) {
            res.emplace_back(str);
            return;
        }
        if (left == right) {
            // 剩余左右括号数相等，下一个只能用左括号
            getParentheis(str + "(", left - 1, right);
        } else if (left < right) {
            // 剩余左括号小于右括号，下一个可以用左括号也可以用右括号
            if (left > 0) {
                getParentheis(str + "(" , left - 1, right);
            }
            getParentheis(str + ")", left, right - 1);
        }
    }
    std::vector<std::string> res;
};
}

int main(int argc, char **argv) {
    int target = 3;
    auto ans = leetcode_cpp::Solution().generateParenthesis(target);
    for (const auto &output : ans) {
        std::cout << output << std::endl;
    }
    return 0;
}