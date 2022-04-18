#include <vector>
#include <iostream>
#include <deque>
#include "../lib/BinaryTree.h"
/*
@
LeetCode 剑指offer
time: 2022-03-15 20:56:05
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (nullptr == root) {
            return {};
        }

        std::deque<TreeNode*> que;
        que.emplace_back(root);
        std::vector<int> tmp;
        std::vector<std::vector<int>> ans;
        int level = 0;

        while (!que.empty()) {
            int qSize = que.size();
            for (int i = 0; i < qSize; ++i) {
                TreeNode *node = que.front();
                que.pop_front();
                tmp.emplace_back(node->val);
                if (nullptr != node->left) {
                    que.emplace_back(node->left);
                }
                if (nullptr != node->right) {
                    que.emplace_back(node->right);
                }
            }
            if (level & 1) {
                std::reverse(tmp.begin(), tmp.end());
            }
            ans.emplace_back(tmp);
            tmp.clear();
            ++level;
        }

        return ans;
    }
};
}
