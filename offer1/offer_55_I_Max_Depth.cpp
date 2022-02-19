#include <vector>
#include <iostream>
#include <algorithm>
#include "../lib/BinaryTree.h"
/*
@
LeetCode 剑指offer
time: 2022-02-14 21:18:21
author: edinw
@
*/

/*
**  注意：本题与主站 104 题相同：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/
**  
**  Given the root of a binary tree, return its maximum depth.
**
**  A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    int maxDepth(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }

        std::function<int(TreeNode*, int)> backtrack = [&](TreeNode *root, int level) -> int{
            if (nullptr == root) {
                return level;
            }
            
            return std::max(backtrack(root->left, level + 1), backtrack(root->right, level + 1));
        };
        

        return backtrack(root, 1);
    }
};

class Solution2 {
public:
    int maxDepth(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        std::deque<TreeNode*> Q;
        Q.emplace_back(root);
        int ans = 0;
        while (!Q.empty()) {
            int sz = Q.size();
            while (sz > 0) {
                TreeNode *node = Q.front();
                Q.pop_front();
                if (nullptr != node->left) {
                    Q.emplace_back(node->left);
                }
                if (nullptr != node->right) {
                    Q.emplace_back(node->right);
                }
                --sz;
            }
            ++ans;
        }

        return ans;
    }
};
}