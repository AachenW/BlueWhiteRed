#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot) {
        if (nullptr == root) {
            return 0;
        }

        std::function<int(TreeNode*, TreeNode*)> check = [&] (TreeNode *o, TreeNode *t) -> int {
            if (nullptr == o && nullptr == t) {
                return 1;
            }

            if ((o && nullptr == t) || (nullptr == o && t) || (o->val != t->val)) {
                return 0;
            }

            return check(o->left, t->left) && check(o->right, t->right);
        };

        return check(root, subRoot) || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
}