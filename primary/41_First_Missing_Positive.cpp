#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

/*
@
LeetCode
time: 2022-02-25 23:35:13
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int firstMissingPositive(std::vector<int>& nums) {
        int nSize = nums.size();

        for (int i = 0; i < nSize; ++i) {
            // 对于遍历到的数 [i]x=nums[i]，如果 x∈[1,N]，我们就知道 xx 应当出现在数组中的 x−1 的位置，因此交换 nums[i] 和 nums[x−1]
            // 注意到上面的方法可能会陷入死循环。如果 nums[i] 恰好与 nums[x−1] 相等，那么就会无限交换下去。此时我们有 nums[i]=x=nums[x−1]，说明 x 已经出现在了正确的位置。因此我们可以跳出循环，开始遍历下一个数。
            while (nums[i] > 0 && nums[i] < nSize && nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[nums[i] - 1], nums[i]);
            }
        }

        for (int i = 0; i < nSize; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nSize + 1;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1, 2, 0};
    
    std::cout << leetcode_cpp::Solution().firstMissingPositive(nums) << std::endl;

    return 0;
}