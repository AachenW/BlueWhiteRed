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
time: 2021-12-13 22:56:40
author: edinw
@
*/
using namespace std;

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::string> letterCOmbinations(std::string digits) {
        std::vector<std::string> combinations;
        if (digits.empty()) {
            return combinations;    // 递归出口
        }
        std::unordered_map<char, std::string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        std::string combination;
        backtrack(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }

private:
    void backtrack(std::vector<std::string>& combinations, const std::unordered_map<char, std::string>& phoneMap, const string& digits, int index, std::string& combination) {
        if (index == digits.length()) {
            combinations.push_back(combination);
        } else {
            char digit = digits[index];
            const std::string& letters = phoneMap.at(digit);
            for (const char& letter: letters) {
                combination.push_back(letter);
                backtrack(combinations, phoneMap, digits, index + 1, combination);
                combination.pop_back();
            }
        }
    }
};
}

int main(int argc, char** argv) {
    std::string digits = "23";
    std::vector<std::string> ans = leetcode_cpp::Solution().letterCOmbinations(digits);
    for (auto str : ans) {
        std::cout << str << ",";
    }
}