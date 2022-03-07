#include <string>
#include <vector>
#include <iostream>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-24 10:41:26
author: edinw
@
*/


/*
**  本题与主站 746 题相同： https://leetcode-cn.com/problems/min-cost-climbing-stairs/
**  数组的每个下标作为一个阶梯，第 i 个阶梯对应着一个非负数的体力花费值 cost[i]（下标从 0 开始）。
**  每当爬上一个阶梯都要花费对应的体力值，一旦支付了相应的体力值，就可以选择向上爬一个阶梯或者爬两个阶梯。
**  请找出达到楼层顶部的最低花费。在开始时，你可以选择从下标为 0 或 1 的元素作为初始阶梯。
*/

namespace leetcode_cpp {
class Solution {
public:
    int minCostClimbingStairs(std::vector<int> &cost) {
        typedef decltype(cost.size()) sz;
        sz cLength = cost.size();
        int prev = 0, curr = 0;
        for (sz i = 2; i < cLength + 1; ++i) {
            int next = std::min(curr + cost[i - 1], prev + cost[i - 2]);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> cost {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    std::cout << leetcode_cpp::Solution().minCostClimbingStairs(cost) << std::endl;
    return 0;
}