#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"

/*
@
project: leetcode
time: 2022-03-31 10:31:57
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        TreeNode *prev = nullptr;
        int ans = INT_MAX;

        std::function<void(TreeNode*)> inorder = [&] (TreeNode *root) {
            if (nullptr == root) {
                return;
            }

            inorder(root->left);

            if (nullptr != prev) {
                ans = std::min(ans, std::abs(root->val - prev->val));
            }
            prev = root;

            inorder(root->right);
        };

        inorder(root);

        return ans;
    }
};
}