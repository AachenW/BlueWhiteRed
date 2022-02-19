#include <iostream>
#include "../lib/BinarySearchTree.h"
#include <algorithm>
#include <vector>
#include "limits.h"
#include <functional>
/*
@
projetc: leetcode HOT 100
time: 2022-02-13 23:57:55
author: edinw
@
*/

using namespace binary_search_tree;

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode *root) {
        std::vector<int> ans;
        if (nullptr == root) {
            return ans;
        }

        std::function<void(TreeNode*)> inorder = [&](TreeNode *root) {
            if (nullptr == root) {
                return;
            }
            if (nullptr != root->left) {
                inorder(root->left);
            }

            ans.emplace_back(root->val);

            if (nullptr != root->right) {
                inorder(root->right);
            }

        };

        inorder(root);

        return ans;
    }
};

class Solution2 {
public:
    std::vector<int> inorderTraversal(TreeNode *root) {
        std::vector<int> ans;
        std::vector<TreeNode*> stk;

        while (nullptr != root || !stk.empty()) {
            while (nullptr != root) {
                stk.emplace_back(root);
                root = root->left;
            }
            root = stk.back();
            stk.pop_back();
            ans.emplace_back(root->val);
            root = root->right;
        }

        return ans;
    }
};
}
