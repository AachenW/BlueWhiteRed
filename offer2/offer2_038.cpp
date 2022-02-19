#include <vector>
#include <iostream>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-09 23:05:13
author: edinw
@
*/

/*
注意：本题与主站 739 题相同： https://leetcode-cn.com/problems/daily-temperatures/

请根据每日 气温 列表 temperatures ，重新生成一个列表，要求其对应位置的输出为：要想观测到更高的气温，至少需要等待的天数。如果气温在这之后都不会升高，请在该位置用 0 来代替。
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
        std::vector<int> tempStack;
        std::vector<int> ans;
        int tSize = temperatures.size();
        for (int i = 0; i < tSize; ++i) {
            while (!tempStack.empty()) {
                if (temperatures.at(tempStack.back()) > temperatures.at(i)) {
                    ans.emplace_back(i - tempStack.back());
                    tempStack.pop_back();
                }
            }
            tempStack.emplace_back(i);
        }
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> temperatures{73,74,75,71,69,72,76,73};
    auto ans = leetcode_cpp::Solution().dailyTemperatures(temperatures);
    for (const auto &output: ans) {
        std::cout << output << " ";
    }
    std::cout << std::endl;
    return 0;
}
