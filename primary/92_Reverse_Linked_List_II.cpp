#include <iostream>
#include "../lib/ListNode.h"
#include <algorithm>
#include <vector>
#include "limits.h"
#include <functional>
/*
@
projetc: leetcode HOT 100
time: 2022-02-26 14:53:46
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    ListNode* reverseBetween(ListNode *head, int left, int right) {
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *prev = dummyNode, *rightNode = dummyNode;
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        for (int i = 0; i < right; ++i) {
            rightNode = rightNode->next;
        }

        ListNode *leftNode = prev->next;
        ListNode *curr = rightNode->next;
        prev->next = nullptr;
        rightNode->next = nullptr;

        reverseLinkedList(leftNode);

        prev->next = rightNode;
        leftNode->next = curr;

        return dummyNode->next;

    }

private:
    void reverseLinkedList(ListNode *head) {
        // 也可以使用递归反转一个链表
        ListNode *pre = nullptr;
        ListNode *cur = head;

        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }
};
}