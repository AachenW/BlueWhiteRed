#include "../lib/BinaryTree.h"

/*
@
LeetCode 剑指offerⅡ
time: 2022-03-06 20:19:22
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *curr = root, *ans = nullptr;

        while (nullptr != curr) {
            if (curr->val > p->val) {
                ans = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }

        return ans;
    }
};
}
