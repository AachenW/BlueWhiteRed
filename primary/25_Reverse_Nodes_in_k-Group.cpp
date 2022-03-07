#include "../lib/ListNode.h"
#include <iostream>
#include <vector>
#include <queue>
/*
@
LeetCode 精选 TOP 面试题
time: 2022-02-18 20:12:45
author: edinw
@
*/

namespace leetcode_cpp
{
class Solution {
public:
    ListNode* reverseKGroup(ListNode *head, int k) {
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode *pre = dummyNode;              // pre 代表待翻转链表的前驱
        ListNode *end = dummyNode;              // end 代表待翻转链表的末尾

        while (nullptr != end->next) {
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k && nullptr != end; ++i) {
                end = end->next;
            }
            if (nullptr == end) {
                break;
            }
            ListNode *start = pre->next;        // 翻转列表的首节点
            ListNode *next = end->next;         // 未翻转部分首节点
            end->next = nullptr;
            pre->next = reverseList(start); // 返回翻转后的头结点
            start->next = next; // start为翻转后的尾节点
            pre = start;
            end = start;
        }

        return dummyNode->next;
    }

private:
    ListNode* reverseList(ListNode *head) {
        ListNode *pre = nullptr, *cur = head;

        while (nullptr != cur) {
            ListNode *node = cur->next;
            cur->next = pre;
            pre = cur;
            cur = node;
        }

        return pre;
    }
};
    
} // namespace leetcode_cpp
