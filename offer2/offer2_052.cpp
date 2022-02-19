#include <vector>
#include <iostream>
#include <deque>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-17 22:34:32
author: edinw
@
*/

/*
** 注意：本题与主站 897 题相同： https://leetcode-cn.com/problems/increasing-order-search-tree/
**
** 给你一棵二叉搜索树，请 按中序遍历 将其重新排列为一棵递增顺序搜索树，使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

namespace leetcode_cpp {
class Solution {
    TreeNode *resNode;
public:
    TreeNode* increasingBST(TreeNode *root) {
        if (nullptr == root) {
            return nullptr;
        }
        TreeNode *dummyNode = new TreeNode(-1);
        resNode = dummyNode;
        backtrack(root);
    }

private:
    void backtrack(TreeNode *node) {
        if (nullptr == node) {
            return;
        }

        backtrack(node->left);
        
        // 在中序遍历的过程中修改节点指向
        resNode->right = node;
        node->left = nullptr;
        resNode = node;

        backtrack(node->right);
    }
};

class Solution2 {
    TreeNode *resNode;
public:
    TreeNode* increasingBST(TreeNode *root) {
        if (nullptr == root) {
            return nullptr;
        }
        TreeNode *dummyNode = new TreeNode(-1);
        resNode = dummyNode;
        inorderTraverse(root);
        return dummyNode->right;
    }

private:
    void inorderTraverse(TreeNode *node) {
        if (nullptr == node) {
            return;
        }

        inorderTraverse(node->left);

        // 在中序遍历的过程中生成新树
        TreeNode *newNode = new TreeNode(node->val);
        resNode->right = newNode;
        resNode = newNode;

        inorderTraverse(node->right);
    }
};
}
