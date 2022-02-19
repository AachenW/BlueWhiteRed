#include <vector>
#include <iostream>
#include <algorithm>
/*
@
LeetCode HOT 100
time: 2022-02-11 22:48:44
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    void nextPermutation(std::vector<int> &nums) {
        int i = nums.size() - 2;
        // 首先从后往前查找第一个顺序对(i, i + 1),满足a[i] < a[i + 1]。这样「较小数」即为 a[i]。此时 [i+1,n) 必然是下降序列
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        // 如果找到了顺序对，那么在区间 [i+1,n) 中从后向前查找第一个元素 j 满足 a[i] < a[j]。这样「较大数」即为 a[j]
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= i && nums[i] >= nums[j]) {
                --j;
            }
            std::swap(nums[i], nums[j]);
        }

        std::reverse(nums.begin() + i + 1, nums.end());
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1,1,5};
    leetcode_cpp::Solution().nextPermutation(nums);
    for (const auto &num: nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}