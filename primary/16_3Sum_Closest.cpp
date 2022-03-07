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
time: 2022-02-25 21:25:12
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int threeSumClosest(std::vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());
        int nSize = nums.size();
        int best = 1e7;

        // 根据差值的绝对值来更新答案
        auto update = [&](int cur) {
            if (std::abs(cur - target) < std::abs(best - target)) {
                best = cur;
            }
        };

        for (int first = 0; first < nSize; ++first) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }

            int second = first + 1;
            int third = nSize - 1;

            while (second < third) {
                int sum = nums[first] + nums[second] + nums[third];
                if (sum == target) {
                    return target;
                }

                update(sum);

                if (sum > target) {
                    int thirdPrev = third - 1;
                    while (thirdPrev > second && nums[thirdPrev] == nums[third]) {
                        --thirdPrev;
                    }
                    third = thirdPrev;
                } else {
                    int secondNext = second + 1;
                    while (secondNext < third && nums[secondNext] == nums[second]) {
                        ++secondNext;
                    }
                    second = secondNext;
                }
            }
        }

        return best;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{-1, 2, 1, -4};
    int target = 1;

    std::cout << leetcode_cpp::Solution().threeSumClosest(nums, target) << std::endl;

    return 0;
}