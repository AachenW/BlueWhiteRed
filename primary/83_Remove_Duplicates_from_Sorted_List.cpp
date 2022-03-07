#include <iostream>
#include "../lib/ListNode.h"
/*
@
LeetCode 剑指offer
time: 2022-02-26 17:43:33
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
        if (nullptr == head || nullptr == head->next) {
            return head;
        }
        ListNode *prev = head;
        ListNode *curr = head->next;
        
        while (nullptr != curr) {
            while (prev->val == curr->val) {
                prev->next = curr->next;
                curr = curr->next;
                if (nullptr == curr) {
                    break;
                }
            }
            if (nullptr == curr) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        return head;
    }
};
}