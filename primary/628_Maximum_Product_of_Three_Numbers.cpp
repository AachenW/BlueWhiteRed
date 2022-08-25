#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-04 13:00:07 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maximumProduct(std::vector<int> &nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        for (int num: nums) {
            if (num < min1) {
                min2 = min1;
                min1 = num;
            } else if (num < min2) {
                min2 = num;
            }

            if (num > max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max3 = max2;
                max2 = num;
            } else if (num > max3) {
                max3 = num;
            }
        }

        return std::max(min1 * min2 * max1, max1 * max2 * max3);
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1, 2, 3};

    std::cout << leetcode_cpp::Solution().maximumProduct(nums) << '\n';

    return 0;
}
