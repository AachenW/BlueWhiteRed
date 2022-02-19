#include <iostream>
#include <vector>
#include "limits.h"
/*
@
LeetCode HOT 100
time: 2022-02-03 23:55:19
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxSubArray(std::vector<int> &nums) {
        // initialization
        int maxSum = nums[0];
        int prev = 0;
        // states transfer
        for (const auto &num: nums) {
            /// states transfer function
            prev = std::max(prev + num, num);
            maxSum = std::max(maxSum, prev);
        }
        return maxSum;
    }
};

// 线段树
class Solution2 {
public:
    int maxSubArray(std::vector<int> &nums) {
        return get(nums, 0, nums.size() - 1).mSum;
    }
private:
    struct Status {
        int lSum;   // [l, r]内以l为左端点的最大子段的和
        int rSum;   // [l, r]内以r为右端点的最大子段的和
        int mSum;   // [l, r]内的最大子段和
        int iSum;   // [l, r]的区间和
    };

    Status pushUp(Status l, Status r) {
        int iSum = l.iSum + r.iSum;         // 区间 [l,r] 的 iSum 就等于「左子区间」的 iSum 加上「右子区间」的 iSum
        int lSum = std::max(l.lSum, l.iSum + r.lSum);   // 存在两种可能，它要么等于「左子区间」的 lSum，要么等于「左子区间」的 iSum 加上「右子区间」的 lSum，二者取大。
        int rSum = std::max(r.rSum, l.rSum + r.iSum);   // 同理，它要么等于「右子区间」的 rSum，要么等于「右子区间」的 iSum 加上「左子区间」的 rSum，二者取大
        int mSum = std::max(std::max(l.mSum, r.mSum), l.rSum + r.lSum); // 它可能不跨越m，也就是说[l,r]的mSum可能是「左子区间」的mSum和「右子区间」的mSum 中的一个；它也可能跨越m，可能是「左子区间」的rSum和「右子区间」的lSum 求和。三者取大。
        return (Status){lSum, rSum, mSum, iSum};
    };

    // 查询 a 序列 [l,r] 区间内的最大子段和
    Status get(std::vector<int> &a, int l, int r) {
        if (l == r) {
            return (Status){a[l], a[l], a[l], a[l]};
        }
        int m = (l + r) >> 1;
        Status lSub = get(a, l, m);
        Status rSub = get(a, m + 1, r);
        return pushUp(lSub, rSub);
    }
};
/*
    「方法二」相较于「方法一」来说，时间复杂度相同，但是因为使用了递归，并且维护了四个信息的结构体，运行的时间略长，空间复杂度也不如方法一优秀，而且难以理解。那么这种方法存在的意义是什么呢？

    对于这道题而言，确实是如此的。但是仔细观察「方法二」，它不仅可以解决区间 [0, n-1]，还可以用于解决任意的子区间 [l,r] 的问题。如果我们把 [0, n-1] 分治下去出现的所有子区间的信息都用堆式存储的方式记忆化下来，即建成一颗真正的树之后，我们就可以在 O(logn) 的时间内求到任意区间内的答案，我们甚至可以修改序列中的值，做一些简单的维护，之后仍然可以在O(logn) 的时间内求到任意区间内的答案，对于大规模查询的情况下，这种方法的优势便体现了出来。这棵树就是上文提及的一种神奇的数据结构——线段树。
*/
}

int main(int argc, char **argv) {
    std::vector<int> nums{-2, -1, -3, 4, -1, 2, 1, -5, 4};
    std::cout << leetcode_cpp::Solution2().maxSubArray(nums) << std::endl;
    return 0;
}