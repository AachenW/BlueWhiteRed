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
    std::vector<std::vector<int>> pathSum(TreeNode *root, int target) {
        backtrack(root, target);
        return ans;
    }

private:
    void backtrack(TreeNode *root, int target) {
        if (nullptr == root) {
            return;
        }
        path.emplace_back(root->val);
        target -= root->val;
        if (0 == target && nullptr == root->left && nullptr == root->right) {
            ans.emplace_back(path);
        }
        
        backtrack(root->left, target);
        backtrack(root->right, target);
        path.pop_back();
    }

private:
    std::vector<std::vector<int>> ans;
    std::vector<int> path;
};

class Solution2 {
public:
    std::vector<std::vector<int>> pathSum(TreeNode *root, int target) {
        if (nullptr == root) {
            return ret;
        }

        std::deque<TreeNode*> queueNode;
        std::deque<int> queueSum;
        queueNode.emplace_back(root);
        queueSum.emplace_back(0);

        while (!queueNode.empty()) {
            TreeNode *node = queueNode.front();
            queueNode.pop_front();
            int rec = queueSum.front() + node->val;
            queueSum.pop_front();

            if (nullptr == node->left && nullptr == node->right && rec == target) {
                getPath(node);
            } else {
                if (nullptr != node->left) {
                    queueNode.emplace_back(node->left);
                    queueSum.emplace_back(rec);
                    parent[node->left] = node; 
                }
                if (nullptr != node->right) {
                    queueNode.emplace_back(node->right);
                    queueSum.emplace_back(rec);
                    parent[node->right] = node;
                }
            }
        }

        return ret;
    }

private:
    void getPath(TreeNode *node) {
        std::vector<int> temp;
        while (node != nullptr) {
            temp.emplace_back(node->val);
            node = parent[node];
        }
        std::reverse(temp.begin(), temp.end());
        ret.emplace_back(temp);
    }

private:
    std::vector<std::vector<int>> ret;
    std::unordered_map<TreeNode*, TreeNode*> parent;
};
}