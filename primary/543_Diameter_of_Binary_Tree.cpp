#include "../lib/BinaryTree.h"
#include <functional>

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    int diameterOfBinaryTree(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }

        std::function<int(TreeNode*)> backtrack = [&](TreeNode *root) -> int {
            if (nullptr == root) {
                return 0;
            }

            int leftDepth = backtrack(root->left);
            int rightDepth = backtrack(root->right);
            ans = std::max(ans, leftDepth + rightDepth + 1);
            return std::max(leftDepth, rightDepth) + 1;
        };

        backtrack(root);

        return ans - 1; // 返回直径
    }

private:
    int ans{0};
};
}