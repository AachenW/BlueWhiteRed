#include <deque>
#include "../lib/BinaryTree.h"

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class CBTInserter {
    std::deque<TreeNode*> que;
    TreeNode *root;
public:
    CBTInserter(TreeNode *root) {
        this->root = root;
        que.emplace_back(root);

        while (que.front()->left != nullptr && que.front()->right != nullptr) {
            que.push(que.front()->left);
            que.push(que.front()->right);
            que.pop();
        }    
    }

    int insert(int v) {
        TreeNode *node = new TreeNode(v);
        TreeNode *fa = que.front();
        if (nullptr == fa->left) {
            fa->left = node;
        } else {
            fa->right = node;
            que.emplace_back(fa->left);
            que.emplace_back(fa->right);
            que.pop_front();
        }
        return fa->val;
    }

    TreeNode* get_root() {
        return this->root;
    }
};
}
