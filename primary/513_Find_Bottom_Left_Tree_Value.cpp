#include <vector>
#include <iostream>
#include <deque>
#include "limits.h"
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-15 21:25:11
author: edinw
@
*/

/*
注意：本题与主站 513 题相同： https://leetcode-cn.com/problems/find-bottom-left-tree-value/

给定一个二叉树的 根节点 root，请找出该二叉树的 最底层 最左边 节点的值。

假设二叉树中至少有一个节点。
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

namespace leetcode_cpp {
class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        std::deque<TreeNode*> queue;
        queue.emplace_back(root);
        int bottomLeft = 0;
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; +i) {
                TreeNode *node = queue.front();
                queue.pop_front();
                if (0 == i) {
                    bottomLeft = node->val;
                }
                if (nullptr != node->left) {
                    queue.emplace_back(node->left);
                }
                if (nullptr != node->right) {
                    queue.emplace_back(node->right);
                }
            }
        }
        return bottomLeft;
    }
};
}
