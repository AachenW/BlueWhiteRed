#include <vector>
#include <iostream>
#include <algorithm>
#include "../lib/BinaryTree.h"
/*
@
LeetCode 剑指offer
time: 2022-01-31 09:24:39
author: edinw
@
*/

using binary_ordinary_tree::TreeNode;

namespace leetcode_cpp {
class Solution {
public:
    int kthLargest(TreeNode *root, int k) {
        cnt = k;
        backtrack(root);
        return ans;
    }

private:
    void backtrack(TreeNode *root) {
        if (nullptr == root) {
            return;
        }
        backtrack(root->right);
        
        --cnt;
        if (0 == cnt) {
            ans = root->val;
        }
        
        backtrack(root->left);
    }

private:
    int cnt;
    int ans;
};
}