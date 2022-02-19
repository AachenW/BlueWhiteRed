#include <vector>
#include <iostream>
#include <deque>
#include "../lib/BinaryTree.h"
/*
@
LeetCode 剑指offer
time: 2022-02-02 21:02:47
author: edinw
@
*/

/* 
**  Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        if (nullptr == root) {
            return std::vector<std::vector<int>>();
        }

        std::deque<TreeNode*> queue;
        queue.emplace_back(root);
        std::vector<std::vector<int>> ans;
        while (!queue.empty()) {
            std::vector<int> temp;
            int qSize = queue.size();
            for (int i = 0; i < qSize; ++i) {
                TreeNode *node = queue.front();
                queue.pop_front();
                temp.emplace_back(node->val);
                if (nullptr != node->left) {
                    queue.emplace_back(node->left);
                }
                if (nullptr != node->right) {
                    queue.emplace_back(node->right);
                }
            }            
            ans.emplace_back(temp);
            temp.clear();
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    
}