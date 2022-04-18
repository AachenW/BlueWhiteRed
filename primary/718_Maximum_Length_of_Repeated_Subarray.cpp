#include <vector>
#include <iostream>

/*
@
Leetcode
time: 2022-03-16 22:22:37
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int findLength(std::vector<int> &nums1, std::vector<int> &nums2) {
        int nSize1 = nums1.size(), nSize2 = nums2.size();
        // 长度为i，末尾项为A[i-1]的子数组，与长度为j，末尾项为B[j-1]的子数组，二者的最大公共后缀子数组长度
        std::vector<std::vector<int>> dp(nSize1 + 1, std::vector<int>(nSize2 + 1, 0));

        int ans = 0;
        for (int i = 1; i <= nSize1; ++i) {
            for (int j = 1; j <= nSize2; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                ans = std::max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums1{1, 2, 3, 2, 1};
    std::vector<int> nums2{3, 2, 1, 4, 7};

    std::cout << leetcode_cpp::Solution().findLength(nums1, nums2) << std::endl;

    return 0;
}