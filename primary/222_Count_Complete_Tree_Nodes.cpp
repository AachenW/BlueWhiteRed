#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    int countNodes(TreeNode* root) {
        std::function<int(TreeNode*)> height = [&] (TreeNode *root) -> int {
            int levels = 0;
            while (root) {
                root = root->left; 
                levels += 1;
            }
            return levels;
        };

        if(root == nullptr) {
            return 0;
        }
        int leftLevels = height(root->left);
        int rightLevels = height(root->right);

        // 子树节点数+根节点数 = (1 << levels);
        if (leftLevels == rightLevels) {    // 左子树深度等于右子树深度, 则左子树是满二叉树
            return countNodes(root->right) + (1 << leftLevels);
        } else {    // 左子树深度大于右子树深度, 则右子树是满二叉树
            return countNodes(root->left) + (1 << rightLevels);
        }
    }
};
}