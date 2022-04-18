#include <bits/stdc++.h>
#include "../lib/ListNode.h"

/*
@
LeetCode
time: 2022-03-31 16:57:37
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    void deleteNode(ListNode* node) {
        if (nullptr == node) {
            return;
        }

        node->val = node->next->val;
        node->next = node->next->next;
        return;
    }
};
}