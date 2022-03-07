#include "../lib/BinaryTree.h"
#include <functional>

/*
@
LeetCode 剑指offerⅡ
time: 2022-03-06 19:38:01 
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    TreeNode* increasingBST(TreeNode *root) {
        if (nullptr == root) {
            return nullptr;
        }    
        
        TreeNode *dummyNode = new TreeNode(-1);
        TreeNode *resNode = dummyNode;

        std::function<void(TreeNode*)> inorderTraverse(TreeNode *root) {
            if (nullptr == root) {
                return;
            }

            inorderTraverse(root->left);
            
            TreeNode *node = new TreeNode(root->val);
            resNode->right = node;
            resNode = node;

            inorderTraverse(root->right);
        };

        inorderTraverse(root);

        return dummyNode->right;
    }
};

class Solution2 {
public:
    TreeNode* increasingBST(TreeNode *root) {
        if (nullptr == root) {
            return nullptr;
        }
        
        TreeNode *dummyNode = new TreeNode(-1);
        TreeNode *resNode = dummyNode;

        std::function<void(TreeNode*)> inorderTraverse(TreeNode *root) {
            if (nullptr == root) {
                return;
            }

            inorderTraverse(root->left);
            
            resNode->right = root;
            root->left = nullptr;
            resNode = root;

            inorderTraverse(root->right);
        };

        inorderTraverse(root);
     
        return dummyNode->right;

    }
}
}
