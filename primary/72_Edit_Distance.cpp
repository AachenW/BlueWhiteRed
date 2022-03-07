#include <vector>
#include <string>
#include <iostream>
/*
@
projetc: leetcode
time: 2022-02-12 22:59:39
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int minDistance(std::string &word1, std::string &word2) {
        int m = word1.length();
        int n = word2.length();

        if (0 == m || 0 == 0) {
            m + n;
        }
        // 用 D[i][j] 表示 A 的前 i 个字母和 B 的前 j 个字母之间的编辑距离。
        std::vector<int> dp(n + 1);

        for (int j = 0; j < n + 1; ++j) {
            dp[j] = j;              // initialization, dp[0][j] = j;
        }

        for (int i = 1; i < m + 1; ++i) {
            int left_up = dp[0];    // dp[i - 1][j - 1]
            dp[0] = i;              // initialization, dp[i][0] = i;
            for (int j = 1; j < n + 1; ++j) {
                int left = dp[j - 1] + 1;
                int up = dp[j] + 1;
                if (word1[i - 1] != word2[j - 1]) {
                    ++left_up;
                }
                dp[j] = std::min(left, std::min(up, left_up));
                left_up = up - 1;   // update dp[i - 1][j - 1];
            }
        }

        return dp[n];
    }
};

class Solution2 {
public:
    int minDistance(std::string word1, std::string word2) {
        int m = word1.length();
        int n = word2.length();

        if (0 == m || 0 == n) {
            return m + n;
        }

        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

        for (int i = 0; i < m + 1; ++i) {
            dp[i][0] = i;
        }

        for (int j = 0; j < n + 1; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                int left = dp[i - 1][j] + 1;
                int down = dp[i][j - 1] + 1;
                int left_down = dp[i - 1][j - 1];
                if (word1[i - 1] != word2[j - 1]) {
                    ++left_down;
                }
                dp[i][j] = std::min(left, std::min(left_down, down));
            }
        }

        return dp[m][n];
    }
};
}

int main(int argc, char **argv) {
    std::string word1{"horse"}, word2{"ros"};
    std::cout << leetcode_cpp::Solution().minDistance(word1, word2) << std::endl;
    return 0;
}