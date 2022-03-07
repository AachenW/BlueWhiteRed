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
}