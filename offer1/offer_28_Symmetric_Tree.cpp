#include <vector>
#include <iostream>
#include <algorithm>
#include "limits.h"
#include "../lib/BinaryTree.h"

/*
@
LeetCode 剑指offer
time: 2022-02-03 20:05:16
author: edinw
@
*/

/*
**  注意：本题与主站 101 题相同：https://leetcode-cn.com/problems/symmetric-tree/
** 
**  Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (nullptr == root) {
            return true;
        }
        return check(root->left, root->right);
    }

private:
    bool check(TreeNode *node1, TreeNode *node2) {
        if (nullptr == node1 && nullptr == node2) {
            return true;
        }
        if (nullptr == node1 || nullptr == node2) {
            return false;
        }
        return (node1->val == node2->val) && check(node1->left, node2->left) && check(node1->right, node2->right);
    }
};

class Solution2 {
public:
    bool isSymmetric(TreeNode *root) {
        if (nullptr == root) {
            return true;
        }
        return check(root->left, root->right);
    }

private:
    bool check(TreeNode *node1, TreeNode *node2) {
        if (nullptr == node1 && nullptr == node2) {
            return true;
        }
        if (nullptr == node1 || nullptr == node2) {
            return false;
        }
        std::deque<TreeNode*> queue;
        queue.emplace_back(node1);
        queue.emplace_back(node2);
        while (!queue.empty()) {
            node1 = queue.front();
            queue.pop_front();
            node2 = queue.front();
            queue.pop_front();
            if (nullptr == node1 && nullptr == node2) continue;
            if ((nullptr == node1 || nullptr == node2) || (node1->val != node2->val)) return false;
            queue.emplace_front(node1->left);
            queue.emplace_front(node2->right);
            queue.emplace_front(node1->right);
            queue.emplace_front(node2->left);
        }
        return true;
    }
};
}