#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-08-24 20:30:56 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2) {
        int nSize1 = nums1.size();
        std::vector<int> ans(nSize1, -1);
        if (0 == nSize1) return ans;

        int nSize2 = nums2.size();
        std::vector<int> monoStack;
        std::unordered_map<int, int> umap;

        for (int i = nSize2 - 1; i >= 0; --i) {
            int num = nums2[i];
            while (!monoStack.empty() && num >= nums2[monoStack.back()]) {
                monoStack.pop_back();
            }
            umap[num] = monoStack.empty() ? -1 : nums2[monoStack.back()];
            monoStack.emplace_back(i);
        }

        std::vector<int> res(nSize1);
        for (int i = 0; i < nSize1; ++i) {
            res[i] = umap[nums1[i]];
        }

        return res;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums1{4, 1, 2};
    std::vector<int> nums2{1, 3, 4, 2};
    auto ans = leetcode_cpp::Solution().nextGreaterElement(nums1, nums2);
    for (const int elem: ans) {
        std::cout << elem << ",";
    }
    std::cout << std::endl;
    return 0;
}

