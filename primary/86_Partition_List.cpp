#include <bits/stdc++.h>
#include "../lib/ListNode.h"

/*
@
project: leetcode
time: 2022-03-24 11:20:32
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (nullptr == head) {
            return nullptr;
        }

        ListNode* small = new ListNode(0);
        ListNode* smallHead = small;
        ListNode* large = new ListNode(0);
        ListNode* largeHead = large;
        while (head != nullptr) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        large->next = nullptr;
        small->next = largeHead->next;
        return smallHead->next;
    }
};
}