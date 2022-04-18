#include <bits/stdc++.h>

/*
@
LeetCode 剑指offerII
time: 2022-03-04 22:46:54
author: edinw
@
*/

class Node {
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

namespace leetcode_cpp {
class Solution {
public:
    Node* flatten(Node *head) {
        Node *ans = nullptr;
        std::function<void(Node*)> backtrack = [&] (Node *node) -> Node* {
            if (nullptr == node) {
                return;
            }

            Node *next = node->next;
            node->prev = ans;
            if (nullptr != ans) {
                ans->next = node;
            }
            
            ans = node;
            if (nullptr != node->child) {
                backtrack(node->child);
                node->child = nullptr;
            }
            if (nullptr != node->next) {
                backtrack(node->next);
            }

        };
        
        backtrack(head);

        return ans;
    }
};
}

