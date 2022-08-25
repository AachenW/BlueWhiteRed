#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-08-24 17:45:49 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int minDistance(std::string word1, std::string word2) {
        int wLen1 = word1.length();
        int wLen2 = word2.length();
        
        std::vector<std::vector<int>> dp(wLen1 + 1, std::vector<int>(wLen2 + 1, 0));
        for (int i = 0; i <= wLen1; ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= wLen2; ++j) {
            dp[0][j] = j;
        }

        for (int i = 1; i <= wLen1; ++i) {
            for (int j = 1; j <= wLen2; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = std::min({dp[i - 1][j - 1] + 2, dp[i - 1][j] + 1, dp[i][j - 1] + 1});
                }
            }
        }

        return dp[word1.size()][word2.size()];
    }
};
}


int main(int argc, char **argv) {
    std::string str1 = "sea";
    std::string str2 = "eat";

    std::cout << leetcode_cpp::Solution().minDistance(str1, str2) << std::endl;

    return 0;
}

