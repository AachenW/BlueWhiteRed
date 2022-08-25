#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-04 13:51:15 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int longestSubarray(std::vector<int> &nums) {
        int left = 0, right = 0;
        int nSize = nums.size();
        int ans = 0, cnt = 0;

        while (right < nSize) {
            // 更新窗口内0的个数
            cnt += nums[right] == 0;
            // 当窗口内0的个数超过1个时，则需要收缩左边界来保证窗口内0的个数不超过1
            while (cnt > 1) cnt -= nums[left++] == 0;
            // 当窗口内0的个数小于等于1个时，统计窗口内可被1替换0后的长度
            ans = std::max(ans, right - left + 1);
            ++right;
        }
        
        // 由于窗口长度为替换一个0后最长连续1的长度，因此减掉1后为删除一个0的最长长度了
        return ans - 1;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{0, 1, 1, 1, 0, 1, 1, 0, 1};
    std::cout << leetcode_cpp::Solution().longestSubarray(nums) << '\n';

    return 0;
}
