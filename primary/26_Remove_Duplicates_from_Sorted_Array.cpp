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
LeetCode 精选 TOP 面试题
time: 2021-12-15 22:29:32
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int nLength = nums.size();
        if (nLength == 0) {
            return 0;
        }

        int fast = 1, slow = 1;
        while (fast < nLength) {
            if (nums[fast] != nums[fast - 1]) {
                nums[slow] = nums[fast];
                +slow;
            }
            ++fast;
        }
        return slow;
    }
};
}