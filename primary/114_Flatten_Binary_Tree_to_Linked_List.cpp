#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include "../lib/BinaryTree.h"

/*
@
LeetCode 热题 HOT 100
time: 2022-01-29 21:30:37
author: edinw
@
*/

/*
**  Given the root of a binary tree, flatten the tree into a "linked list":
**  The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is 
**      always null.
**  The "linked list" should be in the same order as a pre-order traversal of the binary tree.
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    void flatten(TreeNode *root) {
        std::deque<TreeNode*> queue;
        backtrack(root, queue);

        TreeNode *dummyNode = new TreeNode(0);
        TreeNode *prev = dummyNode, *curr = nullptr;
        while (!queue.empty()) {
            curr = queue.front();
            prev->right = curr;
            prev = curr;
            queue.pop_front();
        }
        root = dummyNode->right;
    }
    
private:
    void backtrack(TreeNode *node, std::deque<TreeNode*> &queue) {
        if (nullptr == node ){
            return;
        }
        queue.emplace_back(node);
        backtrack(node->left, queue);
        backtrack(node->right, queue);
    }
};

class Solution2 {
public:
    void flatten(TreeNode *root) {
        if (nullptr == root) {
            return;
        }
        std::vector<TreeNode*> stack;
        stack.emplace_back(root);
        TreeNode *prev = nullptr, *curr = nullptr;
        while (!stack.empty()) {
            curr = stack.back();
            stack.pop_back();
            if (nullptr != prev) {
                prev->left = nullptr;
                prev->right = curr;
            }
            prev = curr;
            if (nullptr != curr->right) {
                stack.emplace_back(curr->right);
            }
            if (nullptr != curr->left) {
                stack.emplace_back(curr->left);
            }
        }
    }
};

class Solution3 {
public:
    void flatten(TreeNode *root) {
        TreeNode *curr = root, *next = nullptr, *predecessor = nullptr;
        while (nullptr != curr) {
            if (nullptr != curr->left) {
                next = curr->left;
                predecessor = next;
                while (nullptr != predecessor->right) {
                    predecessor = predecessor->right;
                }
                predecessor->right = curr->right;
                curr->right = next;
                curr->left = nullptr;
            }
            curr = curr->right;
        }
    }
};
}
