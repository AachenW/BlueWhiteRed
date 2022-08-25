#include <bits/stdc++.h>

/*
@
project: leetcode
time: 2022-06-16 23:27:01
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int findPairs(std::vector<int> &nums, int k) {
        std::unordered_set<int> visited;
        std::unordered_set<int> res;
        for (int num: nums) {
            if (visited.count(num - k)) res.emplace(num - k);
            if (visited.count(num + k)) res.emplace(num);
            visited.emplace(num);
        }
        return res.size();
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{3, 1, 4, 1, 5};
    int k = 2;

    std::cout << leetcode_cpp::Solution().findPairs(nums, k) << std::endl;

    return 0;
}