#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"
/*
@
project: leetcode
time: 2022-03-20 14:45:44
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    int longestUnivaluePath(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }

        int ans = 0;

        std::function<int(TreeNode *)> backtrack = [&] (TreeNode *root) -> int {
            if (nullptr == root) {
                return 0;
            }

            int left = backtrack(root->left);
            int right = backtrack(root->right);
            int arrowLeft = 0, arrowRight = 0;
            if (nullptr != root->left && root->left->val == root->val) {
                arrowLeft += left + 1;
            }
            if (nullptr != root->right && root->right->val == root->val) {
                arrowRight += right + 1;
            }
            ans = std::max(ans, arrowLeft + arrowRight);
            return std::max(arrowLeft, arrowRight);
        };

        backtrack(root);

        return ans;
    }
};
}