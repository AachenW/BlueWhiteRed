#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"

/*
@
projetc: leetcode
time: 2022-04-20 14:14:37 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::string> binaryTreePaths(TreeNode *root) {
        std::vector<std::string> ans;
        std::string path {""};

        std::function<void(TreeNode*, std::string)> dfs = [&] (TreeNode *node, std::string path) {
            if (nullptr == node) {
                return;
            }

            path += std::to_string(node->val);
            if (nullptr == node->left && nullptr == node->right) {
                ans.emplace_back(path);
                return;
            }
            path += "->";
            dfs(node->left, path);
            dfs(node->right, path);
        };

        dfs(root, path);

        return ans;
    }
};
}

