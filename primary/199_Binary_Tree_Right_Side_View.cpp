#include <vector>
#include <iostream>
#include <deque>
#include "limits.h"
#include <unordered_map>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-16 20:03:13
author: edinw
@
*/

/*
注意：本题与主站 199 题相同：https://leetcode-cn.com/problems/binary-tree-right-side-view/

给定一个二叉树的 根节点 root，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
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
    std::vector<int> rightSideView(TreeNode *root) {
        if (nullptr == root) {
            return std::vector<int>{};
        }
        std::deque<TreeNode*> queue;
        queue.emplace_back(root);
        std::vector<int> ans;
        while (!queue.empty()) {
            int size= queue.size();
            for (int i = 0; i < size; ++i) {
                TreeNode *node = queue.front();
                queue.pop_front();
                if (i == size - 1) {
                    ans.emplace_back(node->val);
                }
                if (nullptr != node->left) {
                    queue.emplace_back(node->left);
                }
                if (nullptr != node->right) {
                    queue.emplace_back(node->right);
                }
            }
        }
        return ans;
    }
};

class Solution2 {
public:
    std::vector<int> rightSideView(TreeNode *root) {
        std::unordered_map<int, int> rightMostValueAtDepth;
        int max_depth = -1;

        std::deque<TreeNode*> nodeStack;
        std::deque<int> depthStack;
        nodeStack.emplace_back(root);
        depthStack.emplace_back(0);

        while (!nodeStack.empty()) {
            TreeNode *node = nodeStack.back();
            nodeStack.pop_back();
            int depth = depthStack.back();
            depthStack.pop_back();

            if (nullptr != node) {
                // 维护二叉树的最大深度
                max_depth = std::max(max_depth, depth);

                // 如果不存在对应深度的节点我们才插入
                if (rightMostValueAtDepth.find(max_depth) == rightMostValueAtDepth.end()) {
                    // 当前节点为新一层的第一个节点,即为该层的最右侧节点(根右左的遍历顺序)
                    rightMostValueAtDepth.insert(std::make_pair(depth, node->val));
                }

                nodeStack.emplace_back(node->right);
                depthStack.emplace_back(depth + 1);
                nodeStack.emplace_back(node->left);
                depthStack.emplace_back(depth + 1);
            }
        }

        std::vector<int> rightView;
        for (int depth = 0; depth <= max_depth; ++depth) {
            rightView.emplace_back(rightMostValueAtDepth.at(depth));
        }
        return rightView;
    }
};

class Solution3 {
    std::vector<int> ans;
    int maxDepth = -1;              // 记录目前的最大深度
public:
    std::vector<int> rightSideView(TreeNode *root) {
        if (nullptr == root) {
            return std::vector<int> {};
        }
        backtrack(root, 0);
        return ans;
    }

private:
    void backtrack(TreeNode *node, int depth) {
        if (nullptr == node) {
            return;
        }

        // 当前节点为新一层的第一个节点,即为该层的最右侧节点
        if (depth > maxDepth) {
            ans.emplace_back(node->val);
            maxDepth = depth;
        }
        backtrack(node->right, depth + 1);
        backtrack(node->left, depth + 1);
    }
};
}
