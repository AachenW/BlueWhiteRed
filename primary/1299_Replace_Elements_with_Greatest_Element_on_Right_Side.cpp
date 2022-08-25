#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-05 14:50:10
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> replaceElements(std::vector<int>& arr) {
        int aSize = arr.size();
        std::vector<int> ans(aSize);
        ans[aSize - 1] = -1;
        for (int i = aSize - 2; i >= 0; --i) {
            ans[i] = std::max(ans[i + 1], arr[i + 1]);
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{17, 18, 5, 4, 6, 1};

    auto ans = leetcode_cpp::Solution().replaceElements(nums);
    for (int output: ans) {
        std::cout << output << ",";
    }
    
    return 0;
}