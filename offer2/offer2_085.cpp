#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-21 20:42:52
author: edinw
@
*/

/*
// 本题与主站 22 题相同： https://leetcode-cn.com/problems/generate-parentheses/
// 给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
*/
namespace {
class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        if (n <= 0 ) {
            return {};
        }
        std::string str("");
        backtrack(str, n, n);
        return res;
    }

private:
    void backtrack(std::string &str, int left, int right) {
        if (0 == left && 0 == right) {
            res.emplace_back(str);
            return;
        }
        if (left == right) {
            // 剩余左右括号数相等，下一个只能用左括号
            backtrack(str.append("("), left - 1, right);
            str.pop_back();
        } else if (left < right) {
            // 剩余左括号数小于右括号数，下一个可以用左括号也可以用右括号
            if (left > 0) {
                backtrack(str.append("("), left - 1, right);
                str.pop_back();
            }
            backtrack(str.append(")"), left, right - 1);
            str.pop_back();
        }
    }

private:
    std::vector<std::string> res;
};
}