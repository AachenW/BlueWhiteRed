#include <vector>
#include <iostream>
#include <algorithm>

/*
@
LeetCode
time: 2022-02-08 22:16:09
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int findDuplicate(std::vector<int> &nums) {
        int nLen = nums.size();
        int lo = 1, hi = nLen - 1, ans = -1;
        while (lo <= hi) {
            int mid = (lo + hi) >> 1;
            // cnt 表示 nums 数组中小于等于 mid 的数有多少个
            int cnt = 0;
            for (int i = 0; i < nLen; ++i) {
                cnt += nums[i] <= mid;
            }
            // 假设我们重复的数是 target，那么 [1,target−1]里的所有数满足 cnt[i]≤i，[target,n] 里的所有数满足 cnt[i]>i
            if (cnt <= mid) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
                ans = mid;
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    int findDuplicate(std::vector<int> &nums) {
        if (nums.size() > 1) {
            int slow = nums[0], fast = nums[nums[0]];
            while (slow != fast) {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;
            while (fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }

            return slow;
        }
        return -1;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1,1};
    std::cout << leetcode_cpp::Solution().findDuplicate(nums) << std::endl;
    return 0;
}