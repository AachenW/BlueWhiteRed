#include <vector>
#include <iostream>

/*
@
LeetCode 剑指offer
time: 2022-01-28 22:43:37
author: edinw
@
*/

/*
**  注意：本题与主站 946 题相同：https://leetcode-cn.com/problems/validate-stack-sequences/
**
**  Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop 
**      operations on an initially empty stack, or false otherwise.
*/

namespace leetcode_cpp {
class Solution {
public:
    bool validateStackSequences(std::vector<int>& pushed, std::vector<int>& popped) {
        std::vector<int> stk;
        int nSize = pushed.size();
        int j = 0;
        for (int num: pushed) {
            stk.emplace_back(num);
            while (!stk.empty() && j < nSize && stk.back() == popped[j]) {
                stk.pop_back();
                ++j;
            }
        }

        return stk.empty();
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> pushed{1, 2, 3, 4, 5};
    std::vector<int> poped{4, 5, 3, 2, 1};
    std::cout << std::boolalpha << leetcode_cpp::Solution().validateStackSequences(pushed, poped) << std::endl;

    return 0;
}