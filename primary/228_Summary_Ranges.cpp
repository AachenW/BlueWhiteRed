#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-03 23:41:57 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution { 
public:
    std::vector<std::string> summaryRanges(std::vector<int> &nums) {
        std::unordered_map<long long, int> mp;
        int nSize = nums.size();
        long long maxn = LLONG_MIN;
        for (int i = 0; i < nSize; ++i) {
            mp[nums[i]] = i;
            maxn = std::max(maxn, (long long)nums[i]);    
        }

        int start = 0, end = 0;
        std::vector<std::string> ans;

        while (start < nSize) {
            if (mp.end() == mp.find((long long)nums[start] - 1)) {
                std::string tmp;
                long long curr = nums[start];
                long long steak = curr;
                while (steak <= maxn && mp.find(steak) != mp.end()) {
                    ++steak;
                }
                tmp += std::to_string(curr);
                if (steak != curr + 1) tmp += "->" + std::to_string(steak - 1);
                ans.emplace_back(tmp);
                start = mp[steak - 1] + 1;
            }
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{-2147483648,-2147483647,2147483647};
    auto ans = leetcode_cpp::Solution().summaryRanges(nums);
    for (auto &&str: ans) {
        std::cout << str << '\n';
    }

    return 0;
}
