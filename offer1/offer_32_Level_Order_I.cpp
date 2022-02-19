#include <vector>
#include <iostream>
#include <deque>
#include "../lib/BinaryTree.h"
/*
@
LeetCode 剑指offer
time: 2022-02-02 20:49:13
author: edinw
@
*/

/*
**  从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> levelOrder(TreeNode* root) {
        if (nullptr == root) {
            return std::vector<int>();
        }

        std::deque<TreeNode*> queue;
        std::vector<int> ans;
        queue.emplace_back(root);
        while (!queue.empty()) {
            TreeNode *node = queue.front();
            queue.pop_front();
            ans.emplace_back(node->val);

            if (nullptr != node->left) {
                queue.emplace_back(node->left);
            }
            if (nullptr != node->right) {
                queue.emplace_back(node->right);
            }
        }
        return ans;
    }
};
}