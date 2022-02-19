#include <vector>
#include <iostream>
#include <functional>
#include "../lib/BinaryTree.h"
/*
@
LeetCode 剑指offer
time: 2022-02-16 20:39:32
author: edinw
@
*/

/* 
**  输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果。如果是则返回 true，否则返回 false。假设输入的数组的任意两个数字都互不相同。
*/

namespace leetcode_cpp {
class Solution {
public:
    bool verifyPostorder(std::vector<int> &postorder) {
        int nSize = postorder.size();
        std::function<bool(const std::vector<int>&, int, int)> backtrack = [&](const std::vector<int> &postorder, int i , int j) -> bool {
            if (i >= j || i >= j - 1) {
                return true;
            }
            int left = i;
            while (postorder[left] < postorder[j]) {
                ++left;
            }
            int right = left;
            while (postorder[left] > postorder[j]) {
                ++left;
            }

            return left == j && backtrack(postorder, i, right - 1) && backtrack(postorder, right, j - 1);
        };

        return backtrack(postorder, 0, nSize - 1);
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1,3,2,6,5};
    std::cout << std::boolalpha << leetcode_cpp::Solution().verifyPostorder(nums) << std::endl;
    return 0;
}