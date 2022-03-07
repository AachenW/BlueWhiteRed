#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <numeric>

/*
@
time: 2021-12-12 20:34:35
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int nSize = nums.size();
        int lo = 0, hi = nSize - 1;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        
        return -1;
    }
};
}

int main(int argc, char** argv) {
    std::vector<int> nums {-1, 0, 3, 5, 9, 12};
    int target = 9;
    std::cout << leetcode_cpp::Solution().search(nums, target) << std::endl;

    return 0;
    
}