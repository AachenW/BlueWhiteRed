#include <vector>
#include <iostream>
#include "../lib/ListNode.h"

/*
@
projetc: leetcode
time: 2022-03-16 22:50:16
author: edinw
@
*/

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

namespace leetcode_cpp {
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (nullptr == head || nullptr == head->next) {
            return true;
        }

        ListNode *mid = findMidNode(head);
        ListNode *l1 = head;
        ListNode *l2 = reverseList(mid);

        while (nullptr != l2) {
            if (l1->val != l2->val) {
                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }

private:
    ListNode* findMidNode (ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return nullptr;
        }

        ListNode *slow = head, *fast = head;
        while (nullptr != fast->next && nullptr != fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        ListNode *next = slow->next;
        slow->next = nullptr;
        return next;
    }

    ListNode* reverseList(ListNode *head) {
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
};
}