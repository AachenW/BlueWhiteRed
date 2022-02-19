#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
/*
@
projetc: leetcode
time: 2022-01-19 21:20:36
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool containsNearbyDuplicate(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> hashMap;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int num = nums.at(i);
            if (hashMap.count(num) && i - hashMap.at(num) <= k) {
                return true;
            }
            
            hashMap[num] = i;
        }
        return false;
    }
};

class Solution2 {
    bool containsNearbyDuplicate(std::vector<int> &nums, int k) {
        std::unordered_set<int> hashMap;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > k) {
                hashMap.erase(nums[i - k - 1]);
            }
            if (hashMap.count(nums.at(i))) {
                return true;
            }
            hashMap.emplace(nums.at(i));
        }
        return false;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1,2,3,1,2,3};
    int k = 2;
    std::cout << leetcode_cpp::Solution().containsNearbyDuplicate(nums, k) << std::endl;
    return 0;
}