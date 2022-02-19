#include <vector>
#include <iostream>
#include "../lib/BinaryTree.h"

/*
@
project: leetcode
time: 2022-02-02 23:06:25
author: edinw
@
*/

/*
**  You are given two binary trees root1 and root2.
**  Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not. You need to merge the 
**      two trees into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. 
**      Otherwise, the NOT null node will be used as the node of the new tree.
**  Return the merged tree.
**  Note: The merging process must start from the root nodes of both trees.
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    TreeNode* mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (nullptr == root1) {
            return root2;
        }
        if (nullptr == root2) {
            return root1;
        }

        TreeNode *merged = new TreeNode(root1->val + root2->val);
        merged->left = mergeTrees(root1->left, root2->left);
        merged->right = mergeTrees(root1->right, root2->right);
        return merged;
    }
};

class Solution2 {
public:
    TreeNode* mergeTrees(TreeNode *root1, TreeNode *root2) {
        if (nullptr == root1) {
            return root2;
        }
        if (nullptr == root2) {
            return root1;
        }
        std::deque<TreeNode*> queue, queue1, queue2;
        queue1.emplace_back(root1);
        queue2.emplace_back(root2);
        TreeNode *merged = new TreeNode(root1->val + root2->val);
        queue.emplace_back(merged);

        while (!queue1.empty() || !queue2.empty()) {
            TreeNode *node = queue.front(), *node1 = queue1.front(), *node2 = queue2.front();
            queue.pop_front(); queue1.pop_front(); queue2.pop_front();
            TreeNode *left1 = node1->left, *left2 = node2->left, *right1 = node1->right, *right2 = node2->right;
            if (nullptr != left1 || nullptr != left2)  {
                if (nullptr != left1 && nullptr != left2) {
                    TreeNode *left = new TreeNode(left1->val + left2->val);
                    node->left = left;
                    queue.emplace_back(left);
                    queue1.emplace_back(left1);
                    queue2.emplace_back(left2);
                } else if (nullptr != left1) {
                    node->left = left1;
                } else if (nullptr != left2) {
                    node->left = left2;
                }
            }
            if (nullptr != right1 || nullptr != right2) {
                if (nullptr != right1 && nullptr != right2) {
                    TreeNode *right = new TreeNode(right1->val + right2->val);
                    node->right = right;
                    queue.emplace_back(right);
                    queue1.emplace_back(right1);
                    queue2.emplace_back(right2);
                } else if (nullptr != right1) {
                    node->right = right1;
                } else if (nullptr != right2) {
                    node->right = right2;
                }
            }
        }
        return merged;
    }
};
}