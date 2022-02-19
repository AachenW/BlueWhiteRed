#include <vector>
#include <iostream>
#include <deque>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-16 20:03:13
author: edinw
@
*/

/*
** 注意：本题与主站 129 题相同： https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
**
** 给定一个二叉树的根节点 root ，树中每个节点都存放有一个 0 到 9 之间的数字。
** 每条从根节点到叶节点的路径都代表一个数字：
**      例如，从根节点到叶节点的路径 1 -> 2 -> 3 表示数字 123 。
** 计算从根节点到叶节点生成的 所有数字之和 。
** 叶节点 是指没有子节点的节点。
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
    int sumNumbers(TreeNode *root) {
        return backtrack(root, 0);
    }

private:
    int backtrack(TreeNode *node, int prevSum) {
        if (nullptr == node) {
            return;
        }
        int sum = prevSum * 10 + node->val;
        if (nullptr == node->left && nullptr == node->right) {
            return sum;
        } else {
            return backtrack(node->left, sum) + backtrack(node->right, sum);
        }
    }
};

class Solution2 {
public:
    int sumNumbers(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        std::deque<TreeNode*> nodeQueue;
        std::deque<int> sumQueue;
        nodeQueue.emplace_back(root);
        sumQueue.emplace_back(root->val);
        int sumTotal = 0;
        while (!nodeQueue.empty()) {
            TreeNode *node = nodeQueue.front();
            nodeQueue.pop_front();
            int sum = sumQueue.front();
            sumQueue.pop_front();
            if (nullptr == node->left && nullptr == node->right) {
                sumTotal += sum;
                continue;
            }
            if (nullptr != node->left) {
                nodeQueue.emplace_back(node->left);
                sumQueue.emplace_back(sum * 10 + node->left->val); 
            }
            if (nullptr != node->right) {
                nodeQueue.emplace_back(node->right);
                sumQueue.emplace_back(sum * 10 + node->right->val);
            }
        }

        return sumTotal;
    }
};
}
