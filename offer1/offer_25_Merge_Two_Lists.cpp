#include <vector>
#include <iostream>
#include <algorithm>
#include "limits.h"
#include "../lib/ListNode.h"

/*
@
LeetCode 剑指offer
time: 2022-02-08 20:55:33
author: edinw
@
*/

/*
**  输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
*/

namespace leetcode_cpp {
class Solution {
public:
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (nullptr == l1 && nullptr == l2) {
            return nullptr;
        }
        if (nullptr == l1) {
            return l2;
        }
        if (nullptr == l2) {
            return l1;
        }
        
        ListNode *dummyNode = new ListNode(-1);
        ListNode *curr = dummyNode;
        while (nullptr != l1 && nullptr != l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }

        curr->next = nullptr == l1 ? l2 : l1;

        return dummyNode->next;
    }
};

class Solution2 {
    ListNode* mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (nullptr == l1) {
            return l2;
        }
        if (nullptr == l2) {
            return l1;
        } 
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
}