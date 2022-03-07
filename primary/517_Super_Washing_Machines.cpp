#include <vector>
#include <iostream>
/*
@
LeetCode 
time: 2022-03-06 18:49:14
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int findMinMoves(std::vector<int> &machines) {
        int ans = 0, sum = 0, presum = 0;
        int mSize = machines.size();
        
        for (int i = 0; i < mSize; ++i) {
            sum += machines[i];
        }

        if (sum % mSize) {
            return -1;
        }

        int avg = sum / mSize;

        for (int i = 0; i < mSize; ++i) {
            presum += machines[i];
            // Condition 1. 因为每次只能移动一件衣服，所有对于衣服数量最多的一个洗衣机，最少需要 Max - Avg次转移。
            // Condition 2. 因为每次只能往相邻的洗衣机转移一件衣服，所以假设前 i 个洗衣机的衣服总和为 sum，那么至少需要 |sum - i * Avg| 次转移，才能使 前i个 和 前i个后面 洗衣机中的衣服相等。若 sum - i * Avg>0 则表示 前i个洗衣机的衣服，需要向 前i个洗衣机后面里 转移；，若 sum - i * Avg <= 0 则表示 前i个后面的洗衣机的衣服，需要向 前i个洗衣机里 转移。
            ans = std::max(ans, std::max(machines[i] - avg, std::abs(presum - avg * (i + 1))));
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1, 0, 5};

    std::cout << leetcode_cpp::Solution().findMinMoves(nums) << std::endl;

    return 0;

}
