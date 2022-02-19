#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-06 22:09:55
author: edinw
@
*/

/*
注意：本题与主站 873 题相同： https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence/

给定一个严格递增的正整数数组形成序列arr，找到arr中最长的斐波那契式的子序列的长度。如果一个不存在，返回0.
（回想一下，子序列是从原序列arr中派生出来的，它从arr中删掉任意数量的元素（也可以不删），而不改变其余元素的顺序。例如，[3, 5, 8]是[3, 4, 5, 6, 7, 8]的一个子序列）

*/

namespace leetcode_cpp {
class Solution{
public:
    int lenLongestFibSubseq(std::vector<int> &arr) {
        auto n = arr.size();
        if (0 == n) {
            return 0;
        }
        std::unordered_map<int, int> hashMap;
        for (decltype(n)i = 0; i < n; ++i) {
            hashMap.insert(std::make_pair(arr.at(i), i));
        }
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 0));

        // initialization. dp[i][j]：表示以A[i],A[j]结尾的斐波那契数列的最大长度
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = 2;
            }
        }
        int maxlen = 0;

        // states transfer
        for (decltype(n)i = 0; i < n; ++i) {
            for (decltype(n)j = i + 1; j < n; ++j) {
                int diff = arr[j] - arr[i];
                if (hashMap.count(diff)) {
                    int index = hashMap.at(diff);
                    if (index < i) {
                        dp[i][j] = std::max(dp[i][j], dp[index][i] + 1);
                    }
                }
                maxlen = std::max(maxlen, dp[i][j]);
            }
        }

        return maxlen > 2 ? maxlen : 0;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> arr {1,3,7,11,12,14,18};
    std::cout << leetcode_cpp::Solution().lenLongestFibSubseq(arr) << std::endl;
    return 0;
}