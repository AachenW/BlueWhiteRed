#include <iostream>
#include <vector>
#include <algorithm>
/*
@
LeetCode 热题 HOT 100
time: 2022-02-03 22:54:23
author: edinw
@
*/

/*
**  Given an integer array nums, return the length of the longest strictly increasing subsequence.
**
**  A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. 
**      For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].
*/

namespace leetcode_cpp {
class Solution {
public:
    int lengthOfLIS(std::vector<int> &nums) {
        int nLen = nums.size();
        if (0 == nLen) {
            return 0;
        }
        // initialization, 定义 dp[i] 为考虑前 i 个元素，以第 i 个数字结尾的最长上升子序列的长度，注意dp[i]必须被选中
        std::vector<int> dp(nLen, 1);

        // states transfer function: dp[i] = max(dp[j]) + 1, 其中0 <= j < i且nums[j] < nums[i]
        for (int i = 1; i < nLen; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
        }
        // 整个数组的最长上升子序列即所有 dp[i] 中的最大值
        return *std::max_element(dp.begin(), dp.end());
    }
};

class Solution {
public:
    int lengthOfLIS(std::vector<int> &nums) {
        // 每个元素 tails[k] 的值代表 长度为 k+1 的子序列尾部元素的值。
        int len = 1, nSize = (int)nums.size();
        if (0 == nSize) {
            return 0;
        }

        std::vector<int> d(nSize + 1, 0);
        d[len] = nums[0];

        for (int i = 1; i < nSize; ++i) {
            if (nums[i] > d[len]) {
                d[++len] = nums[i];
            } else {
                int lo = 1, hi = len, pos = 0;  // 如果找不到说明所有的数都比 nums[i] 大，此时要更新 d[1]，所以这里将 pos 设为 0
                // 在 d[1…len]中找满足 d[i−1] < nums[j] < d[i] 的下标 i，并更新 d[i] = nums[j]
                while (lo <= hi) {
                    int mid = (lo + hi) >> 1;
                    if (d[mid] < nums[i]) {
                        pos = mid;
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
                d[pos + 1] = nums[i];
            }
        }
        return len;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {0,1,0,3,2,3};
    std::cout << leetcode_cpp::Solution().lengthOfLIS(nums) << std::endl;
    return 0;
} 