#include <iostream>
#include "../lib/ListNode.h"
/*
@
LeetCode
time: 2022-02-26 18:15:23
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (nullptr == head) {
            return head;
        }

        ListNode *dummyNode = new ListNode(-101, head);
        ListNode *curr = dummyNode;
        
        while (nullptr != curr->next && nullptr != curr->next->next) {
            if (curr->next->val == curr->next->next->val) {
                int x = curr->next->val;
                while (nullptr != curr->next && curr->next->val == x) {
                    curr->next = curr->next->next;
                }
            } else {
                curr = curr->next;
            }
        }

        head = dummyNode->next;
        delete dummyNode;
        dummyNode = nullptr;
        
        return head;
    }
};
}