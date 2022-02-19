#include <vector>
#include "../lib/BinaryTree.h"
#include <functional>

/*
@
Primary station
time: 2022-02-15 22:46:40
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums) {
        int nSize = nums.size();
        if (0 == nSize) {
            return std::vector<int> {};
        }
        
        std::vector<int> prefix(nSize), postfix(nSize);
        
        prefix[0] = 1;
        for (int i = 1; i < nSize; ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        postfix[nSize - 1] = 1;
        for (int j = nSize - 2; j >= 0; --j) {
            postfix[j] = postfix[j + 1] * nums[j + 1];
        }

        std::vector<int> ans(nSize);
        for (int i = 0; i < nSize; ++i) {
            ans[i] = postfix[i] * prefix[i];
        }

        return ans;
    }
};

class Solution2 {
public:
    std::vector<int> productExceptSelf(std::vector<int> &nums) {
        int nSize = nums.size();
        if (0 == nSize) {
            return std::vector<int> {};
        }
        
        // prefix[i] 代表的是 i 左侧所有数字的乘积
        std::vector<int> prefix(nSize);
        
        prefix[0] = 1;
        for (int i = 1; i < nSize; ++i) {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        int base = 1;
        for (int j = nSize - 1; j >= 0; --j) {
            prefix[j] = prefix[j] * base;
            base *= nums[j];
        }

        return prefix;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1, 2, 3, 4};
    auto ans = leetcode_cpp::Solution2().productExceptSelf(nums);
    for (const auto &num: ans) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}