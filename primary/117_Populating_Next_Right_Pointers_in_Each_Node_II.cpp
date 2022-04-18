#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-03-20 19:52:05
author: edinw
@
*/

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

namespace leetcode_cpp {
class Solution {
public:
    Node* connect(Node* root) {
        if (nullptr == root) {
            return nullptr;
        }

        std::deque<Node*> que;
        que.emplace_back(root);

        while (!que.empty()) {
            int qSize = que.size();
            Node *lastNode = nullptr;
            for (int i = 0; i < qSize; ++i) {
                Node *node = que.front(); que.pop_front();
                if (nullptr != node->left) {
                    que.emplace_back(node->left);
                }
                if (nullptr != node->right) {
                    que.emplace_back(node->right);
                }
                if (0 != i) {
                    lastNode->next = node;
                }
                lastNode = node;
            }
        }

        return root;
    }
};
}
