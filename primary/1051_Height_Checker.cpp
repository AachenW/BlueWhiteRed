#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-06-13 21:59:33 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int heightChecker(std::vector<int> &heights) {
        int m = *std::max_element(heights.begin(), heights.end());
        std::vector<int> cnt(m + 1);

        for (int h: heights) ++cnt[h];
        
        int ans = 0, idx = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= cnt[i]; ++j) {
                if (heights[idx] != i)
                    ++ans;
                ++idx;
            }
        }

        return ans;
    }  
};
}

int main(int argc, char **argv) {
    std::vector<int> heights {1, 1, 4, 2, 1, 3};
    std::cout << leetcode_cpp::Solution().heightChecker(heights) << std::endl;

    return 0;
}
