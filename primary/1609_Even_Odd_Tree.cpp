#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#include "BinarySearchTree.h"
/*
@
project: Leetcode
time: 2021-12-25 09:06:16
author: edinw
@
*/

using namespace binary_search_tree;

namespace leetcode_cpp {
class Solution{
public:
    bool isEvenOddTree(TreeNode* root) {
        std::queue<TreeNode*> qu;
        typedef decltype(qu.size()) sz;
        qu.push(root);
        int level = 0;
        while (!qu.empty()) {
            sz size = qu.size();
            int prev = level % 2 == 0 ? INT_MIN : INT_MAX;
            for (sz i = 0; i < size; ++i) {
                TreeNode* node = qu.front();
                qu.pop();
                int value = node->val;
                if (level % 2 == value % 2) {
                    return false;
                }
                if ((level % 2 == 0 && value <= prev) || (level % 2 == 1 && value >= prev)) {
                    return false;
                }
                prev = value;
                if (nullptr != node->left) {
                    qu.push(node->left);
                }
                if (nullptr != node->right) {
                    qu.push(node->right);
                }
            }
            ++level;
        }
        return true;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1, 10, 4, 3,NULL, 7, 9, 12, 8, 6, NULL, NULL, 2};
    BinarySearchTree tree;
    tree.InitTree(nums);
    tree.Traversal(3);
    return 0;
}