#include "../lib/BinaryTree.h"

/*
@
LeetCode 剑指offerⅡ
time: 2022-03-06 20:40:45
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    int findTarget(TreeNode *root, int k) {
        bool find = false;
        std::unordered_set<int> seen;

        std::function<void(TreeNode*)> inorder = [&](TreeNode *root) {
            if (nullptr == root) {
                return;
            }

            inorder(root->left);

            if (seen.count(k - root->val)) {
                find = true;
            } else {
                seen.insert(root->val);
            }

            inorder(root->right);
        };

        inorder(root);

        return find;
    }
};
}
