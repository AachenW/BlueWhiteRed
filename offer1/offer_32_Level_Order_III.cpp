#include <vector>
#include <iostream>
#include <deque>
#include "../lib/BinaryTree.h"
/*
@
LeetCode 剑指offer
time: 2022-02-02 21:18:40
author: edinw
@
*/

/* 
**  请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> levelOrder(TreeNode *root) {
        std::vector<std::vector<int>> ans;
        if (nullptr == root) {
            return ans;
        }

        std::deque<TreeNode*> queue;
        queue.emplace_back(root);
        int level = -1;
        while (!queue.empty()) {
            ++level;
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
            if (level & 1) {
                std::reverse(temp.begin(), temp.end());
            }
            ans.emplace_back(temp);
            temp.clear();
        }
        return ans;
    }
};
}