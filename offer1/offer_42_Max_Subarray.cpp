#include <vector>
#include <iostream>
/*
@
LeetCode 剑指offer
time: 2022-02-05 20:45:56
author: edinw
@
*/

/*
**  注意：本题与主站 53 题相同：https://leetcode-cn.com/problems/maximum-subarray/
**
**  输入一个整型数组，数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。
**  要求时间复杂度为O(n)。
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxSubArray(std::vector<int> &nums) {
        int maxAns = 0;
        int maxSum = 0;
        for (const auto &num: nums) {
            maxSum = std::max(num, maxSum + num);
            maxAns = std::max(maxAns, maxSum);
        }
        return maxAns;
    }
};

class Solution2 {
struct Status {
    int iSum;
    int lSum;
    int rSum;
    int mSum;
};    
public:
    int maxSubArray(std::vector<int> &nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }

private:
    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;
        int lSum = std::max(l.lSum, l.iSum + r.lSum);
        int rSum = std::max(r.rSum, r.iSum + l.rSum);
        int mSum = std::max(std::max(l.mSum, r.mSum), l.rSum + r.lSum);
        return (Status){iSum, lSum, rSum, mSum};
    }

    Status get(std::vector<int> &nums, int lo, int hi) {
        if (lo == hi) {
            return (Status){nums[lo], nums[lo], nums[lo]};
        }

        int mid = (lo + hi) >> 1;
        Status left = get(nums, lo, mid);
        Status right = get(nums, mid + 1, hi);
        return pushUp(left, right);
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1};
    std::cout << leetcode_cpp::Solution2().maxSubArray(nums) << std::endl;
    return 0;
}