#include <string>
#include <algorithm>
#include <iostream>
#include "limits.h"
/*
@
projetc: leetcode
time: 2022-01-12 19:23:33
author: edinw
@
*/

/*
给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。

如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，返回 true ；否则，返回 false 。
*/

namespace leetcode_cpp {
class Solution {
public:
    bool increasingTriplet(std::vector<int> &nums) {
        int nLength = nums.size();
        if (3 > nLength) {
            return false;
        }
        auto leftMin = std::vector<int>(nLength, 0);
        auto rightMax = std::vector<int>(nLength, 0);
        leftMin.at(0) = nums.at(0);
        for (int i = 1; i < nLength; ++i) {
            leftMin.at(i) = std::min(leftMin.at(i - 1), nums.at(i));
        }
        rightMax.at(nLength - 1) = nums.at(nLength - 1);
        for (int i = nLength - 2; i >= 0; --i) {
            rightMax.at(i) = std::max(rightMax.at(i + 1), nums.at(i));
        }

        for (int i = 1; i < nLength - 1; ++i) {
            if (leftMin.at(i - 1) < nums.at(i) && nums.at(i) < rightMax.at(i + 1)) {
                return true;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool increasingTriplet(std::vector<int> &nums) {
        int nLength = nums.size();
        if (nLength < 3) {
            return false;
        }
        int first = nums.at(0), second = INT_MAX;
        for (int i = 2; i < nLength; ++i) {
            int num = nums.at(i);
            if (num > second) {
                return true;
            } else if (num > first) {
                second = num;
            } else {
                first = num;
            }
        }
        return false;
    }
};

}


int main(int argc, char **argv) {
    std::vector<int> nums {2,1,5,0,4,6};
    std::cout << leetcode_cpp::Solution2().increasingTriplet(nums) << std::endl;
    return 0;
}