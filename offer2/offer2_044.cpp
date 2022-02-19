#include <vector>
#include <iostream>
#include <deque>
#include "limits.h"
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-15 21:25:11
author: edinw
@
*/

/*
注意：本题与主站 515 题相同： https://leetcode-cn.com/problems/find-largest-value-in-each-tree-row/

给定一棵二叉树的根节点 root ，请找出该二叉树中每一层的最大值。
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
    std::vector<int> largestValues(TreeNode* root) {
        if (nullptr == root) {
            return std::vector<int>();
        }

        std::deque<TreeNode*> queue;
        queue.emplace_back(root);
        std::vector<int> maxValVec;
        while (!queue.empty()) {
            int size = queue.size();
            int curMax = INT_MIN;

            for (int i = 0; i < size; ++i) {
                TreeNode *node = queue.front();
                queue.pop_front();
                curMax = std::max(curMax, node->val);    
                if (node->left != nullptr) {
                    queue.emplace_back(node->left);
                }
                if (node->right != nullptr) {
                    queue.emplace_back(node->right);
                }
            }
            maxValVec.emplace_back(curMax);
        }
        return maxValVec;
    }
};
}


int main(int argc, char **argv) {

}