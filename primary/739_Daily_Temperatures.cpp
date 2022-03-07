#include <vector>
#include <iostream>

/*
@
project: leetcode
time: 2022-03-05 14:46:50
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
        int tSize = temperatures.size();
        std::vector<int> mono_stack;
        std::vector<int> ans(tSize);

        for (int i = 0; i < tSize; ++i) {
            while (!mono_stack.empty() && temperatures[mono_stack.back()] < temperatures[i]) {
                int idx = mono_stack.back();
                mono_stack.pop_back();;
                ans[idx] = i - idx;

            }
            mono_stack.emplace_back(i);
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};

    auto ans = leetcode_cpp::Solution().dailyTemperatures(temperatures);

    for (auto &&output: ans) {
        std::cout << output << ",";
    }
    std::cout << std::endl;

    return 0;
}
