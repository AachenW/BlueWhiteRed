#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include "../lib/ListNode.h"
/*
@
LeetCode 剑指offer
time: 2022-01-28 22:20:41
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    ListNode* reverseList(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }

        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next = head->next;

        while (nullptr != next) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }
        cur->next = prev;
        return cur;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }

        ListNode *newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }
};
}