#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-12 22:52:42 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int minDeletionSize(std::vector<std::string> &strs) {
        int sSize = strs.size();
        if (0 == sSize) return 0;
        int sLen = strs[0].size();
        int ans = 0;
        for (int i = 0; i < sLen; ++i) {
            for (int j = 0; j < sSize - 1; ++j) {
                if (strs[j][i] > strs[j + 1][i]) {
                    ++ans;
                    break;
                }
            }
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::string> strs{"cba", "daf", "ghi"};
    std::cout << leetcode_cpp::Solution().minDeletionSize(strs) << std::endl;
    return 0;

}
