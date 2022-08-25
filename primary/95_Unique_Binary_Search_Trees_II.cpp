#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"
/*
@
projetc: leetcode
time: 2022-05-04 12:25:26 
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public: 
    std::vector<TreeNode*> generateTrees(int n) {
        if (0 == n) return {};

        std::function<std::vector<TreeNode*>(int, int)> dfs = [&] (int start, int end) -> std::vector<TreeNode*> {
            if (start > end) return {nullptr};

            std::vector<TreeNode*> allTrees;
            // 枚举可行的根节点
            for (int i = start; i <= end; ++i) {
                // 获得所有可行的左子树集合
                std::vector<TreeNode*> leftTrees = dfs(start, i - 1);
                // 获得所有可行的右子树集合
                std::vector<TreeNode*> rightTrees = dfs(i + 1, end);
                // 从左子树集合中选出一棵左子树，从右子树集合中选出一棵右子树，拼接到根节点上
                for (auto &&left: leftTrees) {
                    for (auto &&right: rightTrees) {
                        TreeNode *currTree = new TreeNode(i);
                        currTree->left = left;
                        currTree->right = right;
                        allTree.emplace_back(currTree);
                    }
                }
            }

            return allTrees;
        };

        return dfs(1, n);
    }
};
}
