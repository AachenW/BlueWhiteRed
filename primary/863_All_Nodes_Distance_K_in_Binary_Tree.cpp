#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"


using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // from用于记录来源结点，防止重复
        std::function<void(TreeNode*, TreeNode*, int)> findAns = [&] (TreeNode *node, TreeNode *from, int depth) {
            if (nullptr == node) {
                return;
            }

            if (depth == k) {
                ans.emplace_back(node->val);
                return;
            }

            if (node->left != from) {
                findAns(node->left, node, depth + 1);
            }
            if (node->right != from) {
                findAns(node->right, node, depth + 1);
            }
            if (parents[node->val] != from) {
                findAns(parents[node->val], node, depth + 1);
            }
        };

        findParents(root);

        parents[root->val] = nullptr;

        findAns(target, nullptr, 0);

        return ans;
    }

private:
    void findParents(TreeNode *node) {
        if (nullptr != node->left) {
            parents[node->left->val] = node;
            findParents(node->left);
        }
        if (nullptr != node->right) {
            parents[node->right->val] = node;
            findParents(node->right);
        } 
    }

private:
    std::unordered_map<int, TreeNode*> parents;
    std::vector<int> ans;
};
}