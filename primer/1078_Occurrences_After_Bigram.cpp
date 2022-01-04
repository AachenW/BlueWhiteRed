#include <vector>
#include <string>
#include <sstream>
#include <iostream>
/*
@
project: Leetcode
time: 2021-12-26 16:50:15
author: edinw
@
*/

namespace leetcode_cpp {
class Solution{
public:
    std::vector<std::string> findOcurrances(std::string text, std::string first, std::string second) {
        std::vector<std::string> ans, s;
        std::stringstream ss(text);
        for (std::string t; ss >> t; s.emplace_back(std::move(t))) {
            if (s.size() >= 2 && s.back() == second && *next(s.rbegin()) == first) {
                ans.emplace_back(t);
            }
        }
        return ans;
    } 
};
}

int main(int argc, char **argv) {
    std::string text("alice is a good girl she is a good student");
    std::string first("a"), second("good");
    auto ans = leetcode_cpp::Solution().findOcurrances(text, first, second);
    for (auto &output : ans) {
        std::cout << output << " ";
    }
    std::cout << std::endl;
    return 0;
}