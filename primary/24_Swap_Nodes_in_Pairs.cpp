#include "../lib/ListNode.h"

/*
@
LeetCode
time: 2022-02-25 22:57:34
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    ListNode* swapPairs(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }

        ListNode *newNode = head->next;
        head->next = swapPairs(newNode->next);
        newNode->next = head;

        return newNode;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode *head) {
        ListNode *dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode *curr = dummyHead;
        while (nullptr != curr->next && nullptr != curr->next->next) {
            ListNode *node1 = curr->next;
            ListNode *node2 = curr->next->next;
            curr->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            curr = node1;
        }

        return dummyHead->next;
    }
};
}