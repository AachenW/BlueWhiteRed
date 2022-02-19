#include <iostream>
#include <deque>
#include "BinarySearchTree.h"
#include <unordered_map>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-18 22:27:34
author: edinw
@
*/

/*
**  注意：本题与主站 173 题相同： https://leetcode-cn.com/problems/binary-search-tree-iterator/
** 
**
**  实现一个二叉搜索树迭代器类BSTIterator ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
**      BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点 root 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST 中的数字，且该数字小于 
**          BST中的任何元素。
**      boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false 。
**      int next()将指针向右移动，然后返回指针处的数字。
**  注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回 BST 中的最小元素。
**  可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST 的中序遍历中至少存在一个下一个数字。
*/

using namespace binary_search_tree;

namespace leetcode_cpp {
class BSTIterator {
    TreeNode *resNode;
public:
    BSTIterator(TreeNode *root) {
        TreeNode *dummyNode = new TreeNode(-1);
        resNode = dummyNode;
        inorderTraverse(root);
        resNode = dummyNode;
    }

    TreeNode* inorderTraverse(TreeNode *node) {
        if (nullptr == node) {
            return nullptr;
        }

        TreeNode *left = inorderTraverse(node->left);
        node->left = nullptr;
        resNode->right = left;
        resNode = left;
        TreeNode *right = inorderTraverse(node->right);
        return node;
    }

    int next() {
        resNode = resNode->right;
        return resNode->val;
    }

    bool hasNext() {
        return resNode->right != nullptr;
    }
};
}

int main(int argc, char **argv) {
    BinarySearchTree bst;
    std::vector<int> nums {7, 3, 15, 9, 20};
    bst.InitTree(nums);
    bst.Traversal(1);
    TreeNode *root = bst.GetRoot();
    leetcode_cpp::BSTIterator bSTIterator(root);
    std::cout << bSTIterator.next() << std::endl;    // 返回 3
    std::cout << bSTIterator.next() << std::endl;    // 返回 7
    std::cout << bSTIterator.hasNext() << std::endl; // 返回 True
    std::cout << bSTIterator.next() << std::endl;    // 返回 9
    std::cout << bSTIterator.hasNext() << std::endl; // 返回 True
    std::cout << bSTIterator.next() << std::endl;    // 返回 15
    std::cout << bSTIterator.hasNext() << std::endl; // 返回 True
    std::cout << bSTIterator.next() << std::endl;    // 返回 20
    std::cout << bSTIterator.hasNext() << std::endl; // 返回 False
}