#include <vector>
#include <iostream>
#include "../lib/ListNode.h"

/*
@
projetc: leetcode
time: 2022-02-06 20:59:23
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    ListNode* reverseList(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return nullptr;
        }

        ListNode *node = reverseList(head->next);   // 返回未反转部分的尾节点 
        head->next->next = head;                    // head是未反转部分的尾节点， 将head结点添加到已反转链表的尾部
        head->next = nullptr;                       // 断开当前节点与已排序链表尾节点间的连接
        return node;                                // 返回更新后已反转链表的首节点
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }

        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        while (nullptr != curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
}