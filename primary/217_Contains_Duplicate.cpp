#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-05 16:47:48
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> s;
        for (int x: nums) {
            if (s.find(x) != s.end()) {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1, 2, 3, 1};
    std::cout << std::boolalpha << leetcode_cpp::Solution().containsDuplicate(nums) << std::endl;
    return 0;
}