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
time: 2021-12-12 22:01:40
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int area = std::min(height[l], height[r]) * (r - l);
            ans = std::max(ans, area);
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        return ans;
    }
};
}

int main(int argc, char** argv) {
    std::vector<int> nums {4, 3, 2, 1, 4};
    std::cout << leetcode_cpp::Solution().maxArea(nums) << std::endl;
}