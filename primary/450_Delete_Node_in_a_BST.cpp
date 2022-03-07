#include <vector>
#include <iostream>
#include "../lib/BinaryTree.h"
/*
@
project: leetcode
time: 2022-02-24 19:21:31
author: edinw
@
*/

/*
**  Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of 
**      the BST.
**
**  Basically, the deletion can be divided into two stages:
**      1. Search for a node to remove.
**      2. If the node is found, delete the node.
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    TreeNode *deleteNode(TreeNode *root, int key) {
        if (nullptr == root) {
            return nullptr;
        }

        if (root->val < key) {
            root->right = deleteNode(root->right, key);
        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else {
            if (nullptr == root->left && nullptr == root->right) {
                return nullptr;
            } else if (nullptr == root->left) {
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            } else {
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
        }

        return root;
    }

private:
    int successor(TreeNode *root) {
        root = root->right;
        while (nullptr != root->left) {
            root = root->left;
        }
        return root->val;
    }

    int predecessor(TreeNode *root) {
        root = root->left;
        while (nullptr != root->right) {
            root = root->right;
        }
        return root->val;
    }
};
}