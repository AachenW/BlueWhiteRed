#include <bits/stdc++.h>
#include "../lib/ListNode.h"

namespace leetcode_cpp {
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        if (nullptr == list1 || nullptr == list2) {
            return list1;
        }

        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = list1;
        ListNode *prev = dummyNode;
        ListNode *curr = dummyNode;

        for (int i = 0; i < a; ++i) {
            curr = curr->next;
            if (nullptr == curr) {
                return list1;
            }
        }
        
        ListNode *end = curr;

        for (int i = 0; i <= b - a + 1; ++i) {
            end = end->next;
            if (nullptr == end) {
                return list1;
            }
        }

        ListNode *node = list2;
        while (nullptr != node->next) {
            node = node->next;
        }

        curr->next = list2;
        node->next = end;

        return list1;
    }
};
}