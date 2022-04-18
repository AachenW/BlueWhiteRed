#include <unordered_set>
#include <iostream>
#include <vector>
#include "../lib/ListNode.h"

/*
@
LeetCode
time: 2022-03-16 12:20:45
author: edinw
@
*/

namespace leetcode_cpp {
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        if (nullptr == head || nullptr == head->next || nullptr == head->next->next) {
            return;
        }

        ListNode *mid = findMiddleNode(head);
        mid = reverseList(mid);
        mergeTwoList(head, mid);
        return;
    }

private:
    ListNode* findMiddleNode(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }

        ListNode *slow = head, *fast = head;
        while (nullptr != fast->next && nullptr != fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *next = slow->next;
        slow->next = nullptr;
        return next;
    }

    ListNode *reverseList(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }

        ListNode *prev = nullptr, *curr = head;

        while (nullptr != curr) {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void mergeTwoList(ListNode *p, ListNode *q) {
        ListNode *pNext = nullptr, *qNext = nullptr;
        while (nullptr != p && nullptr != q) {
            pNext = p->next;
            qNext = q->next;
            
            p->next = q;
            p = pNext;
            q->next = p;
            q = qNext;
        }
    }
};
}