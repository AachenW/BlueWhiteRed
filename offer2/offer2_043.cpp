#include <vector>
#include <iostream>
#include <deque>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-14 00:03:44
author: edinw
@
*/

/*
注意：本题与主站 919 题相同： https://leetcode-cn.com/problems/complete-binary-tree-inserter/

完全二叉树是每一层（除最后一层外）都是完全填充（即，节点数达到最大，第 n 层有 2n-1 个节点）的，并且所有的节点都尽可能地集中在左侧。

设计一个用完全二叉树初始化的数据结构 CBTInserter，它支持以下几种操作：
    CBTInserter(TreeNode root) 使用根节点为 root 的给定树初始化该数据结构；
    CBTInserter.insert(int v)  向树中插入一个新节点，节点类型为 TreeNode，值为 v 。使树保持完全二叉树的状态，并返回插入的新节点的父节点的值；
    CBTInserter.get_root() 将返回树的根节点。
*/

/* Definition for a binary tree node. */
typedef struct Node{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}TreeNode;

namespace leetcode_cpp {
class CBTInserter {
    TreeNode *root;
    std::deque<TreeNode*> queue;
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue.emplace_back(root);
        while (nullptr != queue.front()->left && nullptr != queue.front()->right) {
            queue.emplace_back(queue.front()->left);
            queue.emplace_back(queue.front()->right);
            queue.pop_front();
        }
    }
    
    int insert(int v) {
        TreeNode *node = new TreeNode(v);
        TreeNode *fa = queue.front();
        if (nullptr == fa->left) {
            fa->left = node;
        } else {
            fa->right = node;
            queue.emplace_back(fa->left);
            queue.emplace_back(fa->right);
            queue.pop_front();
        }
        return fa->val;
    }
    
    TreeNode* get_root() {
        return this->root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
}