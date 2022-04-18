#include "../lib/BinaryTree.h"
#include <deque>

/*
@
project: leetcode
time: 2022-03-17 16:17:49
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    bool isCompleteTree(TreeNode *root) {
        std::deque<TreeNode*> que;
        que.emplace_back(root);

        int flag = 0;
        while (!que.empty()) {
            TreeNode *node = que.front(); que.pop_front();
            if (nullptr == node) {
                flag = 1;
            } else {
                if (flag) {
                    return false;
                } else {
                    que.emplace_back(node->left);
                    que.emplace_back(node->right);
                }
            }
        }

        return true;
    }
};
}