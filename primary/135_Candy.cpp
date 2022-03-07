#include <vector>
#include <iostream>
#include <unordered_map>

/*
@
LeetCode
time: 2022-02-28 20:31:42
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int candy(std::vector<int> &ratings) {
        int nSize = ratings.size();
        std::vector<int> left(nSize, 1);
        std::vector<int> right(nSize, 1);

        for (int i = 1; i < nSize; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }
        int count = left[nSize - 1];
        for (int i = nSize - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
            count += std::max(left[i], right[i]);
        }

        return count;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1,2,2};

    std::cout << leetcode_cpp::Solution().candy(nums) << std::endl;
    
    return 0;
}