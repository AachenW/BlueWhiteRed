#include "../lib/BinaryTree.h"
#include <functional>

/*
@
project: leetcode
time: 2022-03-05 17:36:35
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    TreeNode* pruneTree(TreeNode *root) {
        std::function<bool(TreeNode*)> backtrack = [&](TreeNode *node) -> bool {
            if (nullptr == node) {
                return false;
            }

            bool leftContainOne = backtrack(node->left);
            bool rightContainOne = backtrack(node->right);
            if (!leftContainOne) {
                node->left = nullptr;
            }
            if (!rightContainOne) {
                node->right = nullptr;
            }

            return 1 == node->val | leftContainOne | rightContainOne;
        };

        return backtrack(node) ? nullptr : root;
    }
};

}
