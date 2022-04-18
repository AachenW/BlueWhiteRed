#include <vector>
#include <iostream>
#include <unordered_map>

/*
@
LeetCode 剑指offer
time: 2022-01-29 16:19:41
author: edinw
@
*/

/*
**  注意：本题与主站 138 题相同：https://leetcode-cn.com/problems/copy-list-with-random-pointer/
**
**  请实现 copyRandomList 函数，复制一个复杂链表。在复杂链表中，每个节点除了有一个 next 指针指向下一个节点，还有一个 random 指针指向链表中的任意节点或者 null。
*/

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

namespace leetcode_cpp {
class Solution {
    std::unordered_map<Node*, Node*> hashMap;
public:
    Node* copyRandomList(Node* head) {
        if (nullptr == head) {
            return head;
        }
        if (!hashMap.count(head)) {
            Node *headNew = new Node(head->val);
            hashMap[head] = headNew;
            headNew->next = copyRandomList(head->next);
            headNew->random = copyRandomList(head->random);
        }
        return hashMap[head];
    }
};

class Solution2 {
public:
    Node* copyRandomList(Node* head) {
        if (nullptr == head) {
            return head;
        }
        Node *curr = head;
        while (nullptr != curr) {
            Node *node = new Node(curr->val);
            node->next = curr->next;
            curr->next = node;
            curr = node->next;
        }
        curr = head;
        while (nullptr != curr) {
            curr->next->random = (nullptr != curr->random) ? curr->random->next : nullptr;
            curr = curr->next->next;
        }

        curr = head;
        Node *newhead = curr->next;
        while (nullptr != curr) {
            Node *newNode = curr->next;
            curr->next = newNode->next;
            newNode->next = (nullptr != newNode->next) ? newNode->next->next : nullptr;
            curr = curr->next;
        }
        return newhead;
    }
};

class Solution3 {
public:
    Node* copyRandomList(Node* head) {
        std::unordered_map<Node*, Node*> nodeMap;

        Node *node = head;
        while (nullptr != node) {
            nodeMap[node] = new Node(node->val);
            node = node->next;
        }
        node = head;
        while (nullptr != node) {
            nodeMap[node]->next = nodeMap[node->next];
            nodeMap[node]->random = nodeMap[node->random];
            node = node->next;
        }
        return nodeMap[head];
    }
};
}
