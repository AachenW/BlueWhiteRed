#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"

/*
@
projetc: leetcode
time: 2022-03-23 15:06:49
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if (nullptr == root) {
            return 0;
        }

        int ans = 0, cnt = 0;
        std::function<void(TreeNode*)> inorder = [&] (TreeNode *root) {
            if (nullptr == root) {
                return;
            }

            inorder(root->left);

            cnt += 1;
            if (cnt == k) {
                ans = root->val;
            }

            inorder(root->right);
        };

        inorder(root);

        return ans;
    }
};
}