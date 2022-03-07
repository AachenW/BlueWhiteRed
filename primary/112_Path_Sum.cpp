#include <iostream>
#include <vector>
#include "../lib/BinaryTree.h"
#include <unordered_map>
#include <deque>

/*
**  注意：本题与主站 113 题相同：https://leetcode-cn.com/problems/path-sum-ii/
**
**  Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals 
**      targetSum. Each path should be returned as a list of the node values, not node references.
**
**  A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.
*/

using binary_ordinary_tree::TreeNode;

namespace leetcode_cpp {
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (nullptr == root) {
            return false;
        }

        std::deque<TreeNode*> queNode;
        std::deque<int> queVal;
        queNode.emplace_back(root);
        queVal.emplace_back(root->val);

        while (!queNode.empty()) {
            TreeNode *node = queNode.front();
            queNode.pop_front();
            int rec = queVal.front();
            queVal.pop_front();

            if (nullptr == node->left && nullptr == node->right) {
                if (rec == targetSum) {
                    return true;
                }
                continue;
            } else {
                if (nullptr != node->left) {
                    queNode.emplace_back(node->left);
                    queVal.emplace_back(rec + node->left->val);
                }
                if (nullptr != node->right) {
                    queNode.emplace_back(node->right);
                    queVal.emplace_back(rec + node->right->val);
                }
            }
        }

        return false;
    }
};

class Solution2 {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (nullptr == root) {
            return false;
        }
        if (nullptr == root->left && nullptr == root->right) {
            return targetSum == root->val;
        }
        
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};
}