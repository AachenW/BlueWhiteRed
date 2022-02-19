#include <vector>
#include <iostream>
#include <deque>
#include "../lib/BinarySearchTree.h"
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-17 23:05:42
author: edinw
@
*/

/*
** 注意：本题与主站 285 题相同： https://leetcode-cn.com/problems/inorder-successor-in-bst/
**
** 给定一棵二叉搜索树和其中的一个节点 p ，找到该节点在树中的中序后继。如果节点没有中序后继，请返回 null 。
** 节点 p 的后继是值比 p.val 大的节点中键值最小的节点，即按中序遍历的顺序节点 p 的下一个节点。
*/

using namespace binary_search_tree;

namespace leetcode_cpp {
class Solution {
    std::deque<TreeNode*> stack;
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        TreeNode *cur = root;
        TreeNode *ret = nullptr;
        while (cur != nullptr) {
            // 若当前节点的值大于节点 p 的值，那么当前节点就有可能是节点 p 的下一个节点。此时当前节点的值比节点 p 大，但是节点 p 的下一个节点要求是所有大于等于它的值中最小的一
            // 个，因此接下来遍历当前节点的左子树，确定是否能找到值更小但是仍然大于等于节点 p 值的节点。
            if (cur->val > p->val) {
                ret = cur;
                cur = cur->left;
            }
            // 若当前节点的值小于等于节点 p 的值，那么节点 p 的下一个节点应该在当前节点的右子树
            else {
                cur = cur->right;
            }
        }
        return ret;
    }
};

class Solution2 {
    bool find = false;
    TreeNode *resNode;
public:
    TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
        if (nullptr == root) {
            return nullptr;
        }
        inorderTraverse(root, p);
        return resNode;
    }

private:
    void inorderTraverse(TreeNode *node, TreeNode *p) {
        if (nullptr == node) {
            return ;
        }

        inorderTraverse(node->left, p);
        if (!find && node->val == p->val) {
            find = true;
        } else if (find){
            resNode = node;
            find = false;
        }
        inorderTraverse(node->right, p);
    }
};
}

int main(int argc, char **argv) {
    BinarySearchTree bstree;
    // bstree.InitTree()
}