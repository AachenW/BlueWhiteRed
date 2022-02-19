#include <vector>
#include <iostream>
#include <algorithm>
#include "limits.h"
#include "../lib/ListNode.h"

/*
@
LeetCode 剑指offer
time: 2022-02-07 22:23:33
author: edinw
@
*/

/*
**  给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
**
**  返回删除后的链表的头节点。
*/

namespace leetcode_cpp {
class Solution {
public:
    ListNode* deleteNode(ListNode *head, int val) {
        if (nullptr == head) {
            return head;
        }
        ListNode *prev = nullptr, *curr = head;
        while (nullptr != curr) {
            if (curr->val == val) {
                break;
            }
            prev = curr;
            curr = curr->next;
        }
        if (nullptr == prev) {
            head = head->next;
        } else {
            prev->next = curr->next;
        }
        return head;
    }
};
}

int main(int argc, char **argv) {
    
}