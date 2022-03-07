#include <vector>
#include "../lib/BinaryTree.h"
#include <functional>

/*
@
LeetCode 剑指offer
time: 2022-02-15 22:13:36
author: edinw
@
*/

/*
**  注意：本题与主站 236 题相同：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
**
**  Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
**
**  According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has 
**      both p and q as descendants (where we allow a node to be a descendant of itself).”
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *ans {nullptr};
        std::function<bool(TreeNode*, TreeNode*, TreeNode*)> backtrack;
        backtrack = [&] (TreeNode *root, TreeNode *p, TreeNode *q) -> bool {
            if (nullptr == root) {
                return false;
            }
            
            bool leftSubTree = backtrack(root->left, p, q);
            bool rightSubTree = backtrack(root->right, p, q);
            // 左子树和右子树均包含 p 节点或 q 节点
            if ((leftSubTree && rightSubTree) || ((root->val == p->val || root->val == q->val) && (leftSubTree || rightSubTree))) {
                ans = root;
            }
            return leftSubTree || rightSubTree || (root->val == p->val || root->val == q->val);
        };

        backtrack(root, p, q);
        
        return ans;
    }
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 考虑通过递归对二叉树进行后序遍历，当遇到节点 p 或 q 时返回
        if (nullptr == root || p == root || q == root) {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (nullptr == left && nullptr == right) {
            return nullptr; // 当 left 和 right 同时为空 ：说明 root 的左/右子树中都不包含 p,q ，返回 null ；
        }
        // 当 left 为空 ，right 不为空 ：p,q 都不在 root 的左子树中，直接返回 right 。具体可分为两种情况：
        // 1. p,q 其中一个在 root 的 右子树 中，此时 right 指向 p（假设为p ）；
        // 2. p,q 两节点都在 root 的 右子树 中，此时 right 指向 最近公共祖先节点 ；
        if (nullptr == left) {
            return right; 
        }
        if (nullptr == right) {
            return left;
        }
        return root;    // 当 left 和 right 同时不为空 ：说明 p,q 分列在 root 的 异侧 （分别在左/右子树），因此 root 为最近公共祖先，返回 root
    }
};
}