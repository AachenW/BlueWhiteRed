#include <string>
#include <vector>
#include <iostream>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-08 21:15:43
author: edinw
@
*/

/*
注意：本题与主站 97 题相同： https://leetcode-cn.com/problems/interleaving-string/

给定三个字符串 s1、s2、s3，请判断 s3 能不能由 s1 和 s2 交织（交错） 组成。
*/

namespace leetcode_cpp {
class Solution {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int n = s1.size(), m = s2.size(), t = s3.size();
        
        // 定义 f(i, j) 表示 s1的前i个元素和s2的前j个元素是否能交错组成s3的前i+j个元素
        auto f = std::vector<std::vector<int>> (n + 1, std::vector<int> (m + 1, false));

        if (n + m != t) {
            return false;
        }

        // initialization
        f[0][0] = true;
        
        // states transfer
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return f[n][m];
    }
};

class Solution2 {
public:
    bool isInterleave(std::string s1, std::string s2, std::string s3) {
        int n = s1.size(), m = s2.size(), t = s3.size();

        // 因为这里数组 f 的第 i 行只和第i - 1行相关，所以我们可以用滚动数组优化这个动态规划，这样空间复杂度可以变成 O(m)
        auto dp = std::vector<int> (m + 1, false);

        if (n + m != t) {
            return false;
        }

        // initialization
        dp[0] = true;

        // states transfer
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    dp[j] &= (s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    dp[j] |= (dp[j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return dp[m];
    }
};
}

int main (int argc, char **argv) {
    std::string s1 {"aabcc"}, s2 {"dbbca"}, s3 {"aadbbcbcac"};
    std::cout << std::boolalpha << leetcode_cpp::Solution2().isInterleave(s1, s2, s3) << std::noboolalpha << std::endl;
    return 0;
}
