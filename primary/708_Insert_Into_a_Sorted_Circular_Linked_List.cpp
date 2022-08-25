
#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-03-04 23:09:30
author: edinw
@
*/


class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

namespace leetcode_cpp {
class Solution {
public:
    Node* insert(Node *head, int insertVal) {
        std::function<void(Node*)> insertCore = [&](Node *node) {
            Node *cur = head;
            Node *next = cur->next;
            Node *biggestNode = head;
            while (!(cur->val <= node->val && next->val >= node->val) && next != head) {
                cur = next;
                next = next->next;
                if (cur->val >= biggestNode->val) {
                    biggestNode = cur;
                }
            }

            if (cur->val <= node->val && next->val >= node->val) {  // 插入的值介于原链表最大值和最小值之间
                cur->next = node;
                node->next = next;
            } else {    // 插入的值大于链表中原有的最大值，或者小于链表中原有的最小值，则新节点插入原来值的最大值和最小值之间
                node->next = biggestNode->next;
                biggestNode->next = node;
            }
        };
        
        
        Node *node = new Node(insertVal);
        if (nullptr == head) {
            head = node;
            head->next = head;
        } else if (head == head->next) {
            head->next = node;
            node->next = head;
        } else {
            insertCore(node);
        }

        return head;
    
    }
};

class Solution2 {
public:
    Node* insert(Node *head, int insertVal) {
        Node *node = new Node(insertVal);
        if (nullptr == head) {
            node->next = node;
            return node;
        }

        if (head->next == head) {
            head->next = node;
            node->next = head;
            return head;
        }

        Node *curr = head, *next = head->next;
        while (next != head) {
            if (insertVal >= curr->val && insertVal <= next->val) {
                break;
            }
            if (curr->val > next->val) {
                if (insertVal > curr->val || insertVal < next->val) {
                    break;
                }
            }
            curr = curr->next;
            next = next->next;
        }
        curr->next = node;
        node->next = next;
        return head;
    }

};
}
