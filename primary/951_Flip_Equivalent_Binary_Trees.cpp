#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"

/*
@
projetc: leetcode
time: 2022-05-04 14:22:16 
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2) {
        if (root1 == root2) return true;
        if (nullptr == root1 || nullptr == root2 || root1->val != root2->val) return false;

        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) ||
                flipEquiv(root1->right, root2->left) && flipEquiv(root1->left, root2->right));

    }
};
}
