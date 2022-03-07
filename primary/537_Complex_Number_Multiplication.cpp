#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <limits.h>

/*
@
leetcode主站
time: 2022-02-25 20:11:45
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string complexNumberMultiply(std::string num1, std::string num2) {
        auto get = [](std::string &s) {
            auto p = s.find('+');
            std::pair<int, int> ans;
            ans.first = stoi(s.substr(0, p));
            ans.second = stoi(s.substr(p + 1, std::string::npos - p - 1));
            return ans;
        };

        auto a = get(num1), b = get(num2);
        return std::to_string(a.first * b.first - a.second * b.second) + "+"
             + std::to_string(a.first * b.second + a.second * b.first) + "i"; 
    }
};
}

int main(int argc, char **argv) {
    std::string s1{"1+1i"};
    std::string s2{"1+1i"};
    std::cout << leetcode_cpp::Solution().complexNumberMultiply(s1, s2) << std::endl;
    return 0;
}