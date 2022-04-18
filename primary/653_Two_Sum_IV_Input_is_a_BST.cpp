#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
    std::unordered_set<int> hashTable;
public:
    bool findTarget(TreeNode *root, int k) {
        if (nullptr == root) {
            return false;
        }
        if (hashTable.count(k - root->val)) {
            return true;
        }
        hashTable.insert(root->val);

        return findTarget(root->left, k) || findTarget(root->right, k);
    }
};

class Solution2 {
public:
    bool findTarget(TreeNode *root, int k) {
        std::unordered_set<int> hashTable;
        std::deque<TreeNode*> que;
        que.emplace_back(root);

        while (!que.empty()) {
            TreeNode *node = que.front(); que.pop_front();
            if (hashTable.count(k - node->val)) {
                return true;
            }
            hashTable.insert(node->val);
            if (nullptr != node->left) {
                que.emplace_back(node->left);
            }
            if (nullptr != node->right) {
                que.emplace_back(node->right);
            }
        }

        return false;
    }
};
}