#include <iostream>
#include "../lib/BinaryTree.h"
#include "limits.h"
#include <functional>

/*
@
LeetCode 剑指offerⅡ
time: 2022-03-06 19:28:38
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int ret = INT_MIN;

        std::function<int(TreeNode*)> backtrack = [&](TreeNode *root) {
            if (nullptr == root) {
                return 0;
            }

            int left = std::max(0, backtrack(root->left));
            int right = std::max(0, backtrack(root->right));
            ret = std::max(left + right + root->val, ret);
            return std::max(left, right) + root->val;
        };

        backtrack(root);

        return ret;
    }
};
}
