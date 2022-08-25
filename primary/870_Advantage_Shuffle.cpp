#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-11 14:26:22 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> advantageCount(std::vector<int> &nums1, std::vector<int> &nums2) {
        std::multiset<int> s(nums1.begin(), nums1.end());

        for (int i = 0; i < nums2.size(); ++i) {
            auto it = *s.rbegin() > nums2[i] ? s.upper_bound(nums2[i]) : s.begin();
            nums1[i] = *it;
            s.erase(it);
        }
        return nums1;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums1{2, 7, 11, 15};
    std::vector<int> nums2{1, 10, 4, 11};

    auto ans = leetcode_cpp::Solution().advantageCount(nums1, nums2);
    for (auto &&output : ans) std::cout << output << ",";
    std::cout << std::endl;
    return 0;
}
