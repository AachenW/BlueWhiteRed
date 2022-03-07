#include <iostream>
#include <vector>
#include <string>
#include "limits.h"
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-24 21:17:40
author: edinw
@
*/

/*
**  注意：本题与主站 528 题相同： https://leetcode-cn.com/problems/random-pick-with-weight/
** 
**  You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.
**  You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The 
**  probability of picking an index i is w[i] / sum(w).
**      ·For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / 
**      (1 + 3) = 0.75 (i.e., 75%).
*/

namespace leetcode_cpp {
class Solution {
    std::vector<int> acc;
public:
    Solution(std::vector<int> &w) {
        acc.resize(w.size(), 0);
        int sum = 0;
        for (int i = 0; i < w.size(); ++i) {
            sum += w[i];
            acc[i] = sum;
        }
    }

    int pickIndex() {
        int rad = rand() % acc.back() + 1;
        int left = 0;
        int right = acc.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (rad <= acc[mid]) {
                if (mid == 0 || rad > acc[mid - 1]) {
                    return mid;
                }
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
}