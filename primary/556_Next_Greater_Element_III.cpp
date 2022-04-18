#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-03-23 23:38:34
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int nextGreaterElement(int n) {
        std::string nums = std::to_string(n);
        int nSize = nums.size(), i = nSize - 2;

        // 找到第一个满足nums[i] < nums[i + 1]的数对，则为较小的数尽量靠右
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        if (i < 0) {
            return -1;
        }
        if (i >= 0) {
            int j = nSize - 1;
            // 在区间 [i+1,n) 中从后向前查找第一个元素 j 满足 a[i] < a[j]。这样「较大数」即为 a[j](所以较大的数尽可能的小)。
            while (j >= i && nums[i] >= nums[j]) {
                --j;
            }
            std::swap(nums[i], nums[j]);
        }
        std::reverse(nums.begin() + i + 1, nums.end());

        long long ans = strtoll(nums.c_str(), NULL, 10);

        return ans <= INT_MAX ? (int)ans : -1;
    }
};
}

int main(int argc, char **argv) {
    int n = 21;
    
    std::cout << leetcode_cpp::Solution().nextGreaterElement(n) << std::endl;

    return 0;
}