#include <vector>
#include <iostream>
#include "../lib/BinaryTree.h"
/*
@
LeetCode 剑指offer
time: 2022-02-11 21:44:39
author: edinw
@
*/

/*
**  输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
*/

namespace leetcode_cpp {
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
public:
    Node* treeToDoublyList(Node *root) {
        if (nullptr == root) {
            return nullptr;
        }
        backtrack(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

private:
    void backtrack(Node *root) {
        if (nullptr == root) {
            return;
        }
        if (nullptr != root->left) {
            backtrack(root->left);
        }

        if (nullptr == pre) {
            head = root;
        } else {
            pre->right = root;
        }
        root->left = pre;
        pre = root;

        if (nullptr != root->right) {
            backtrack(root->right);
        }
    }

private:
    Node *pre{nullptr};
    Node *head{nullptr};
};

class Solution2 {
public:
    Node* Convert(Node* pRootOfTree) {
        std::vector<std::pair<Node*, int>> stk;
        stk.emplace_back(std::make_pair(pRootOfTree, false));
        Node *prev = nullptr;
        Node *head = nullptr;
        while (!stk.empty()) {
            auto [node, visited] = stk.back();
            stk.pop_back();
            if (nullptr == node) {
                continue;
            }
            if (visited) {
                if (nullptr == prev) {
                    head = node;
                } else {
                    prev->right = node;
                }
                node->left = prev;
                prev = node;
            } else {
                stk.emplace_back(std::make_pair(node->right, false));
                stk.emplace_back(std::make_pair(node, true));
                stk.emplace_back(std::make_pair(node->left, false));
            }
        }
        
        return head;
    }
};
}