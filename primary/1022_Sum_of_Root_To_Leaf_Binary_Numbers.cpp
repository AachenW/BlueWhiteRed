#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"

/*
@
project: Leetcode
time: 2022-05-30 19:03:49
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    int sumRootToLeaf(TreeNode *root) {
        std::function<int(TreeNode*, int)> dfs = [&] (TreeNode *root, int curr) -> int {
            if (nullptr == root) return 0;

            curr = (curr << 1) + root->val;

            if (nullptr == root->left && nullptr == root->right) return curr;

            return dfs(root->left, curr) + dfs(root->right, curr);
        };

        return dfs(root, 0);
    }
};
}