#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
#include "../lib/ListNode.h"

/*
@
LeetCode 热题 HOT 100
time: 2022-02-03 22:54:23
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return false;
        }
        ListNode *slow = head, *fast = head;
        while (nullptr != fast && nullptr != fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                return true;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool hasCycle(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return false;
        }
        std::unordered_set<ListNode*> visited;
        while (nullptr != head) {
            if (visited.count(head)) {
                return true;
            }
            visited.insert(head);
            head = head->next;
        }
        return false;
    }
};

class Solution3 {
public:
    bool hasCycle(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return false;
        }
        ListNode *dummyNode = new ListNode(-1);
        while (nullptr != head) {
            if (dummyNode == head) {
                return true;
            }
            ListNode *curr = head;
            head = head->next;
            curr->next = dummyNode;
        }
        return false;
    }
};
}