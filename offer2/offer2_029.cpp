#include "../lib/ListNode.h"

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-04 21:04:48
author: edinw
@
*/

/*
注意：本题与主站 708 题相同： https://leetcode-cn.com/problems/insert-into-a-sorted-circular-linked-list/

给定循环单调非递减列表中的一个点，写一个函数向这个列表中插入一个新元素 insertVal ，使这个列表仍然是循环升序的。

给定的可以是这个列表中任意一个顶点的指针，并不一定是这个列表中最小元素的指针。如果有多个满足条件的插入位置，可以选择任意一个位置插入新的值，插入后整个列表仍然保持有序。如果列表为空（给定的节点是 null），需要创建一个循环有序列表并返回这个节点。否则。请返回原先给定的节点。
*/

namespace leetcode_cpp {
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = nullptr;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};

class Solution {
public:
    /*
    其实就三种情况:
    1. 在中间能够找到一个节点cur，满足cur->val<=val<=cur->next->val，直接插入即可
    2. 找不到，则一定是所有的值都比它小或大，其实都会插入到边界跳跃点，即找到cur，满足val<=cur->next->val<cur->val(比最小的还小）或cur->next->val<cur->val<=val（比最大的还大）
    */
    Node* insert(Node *head, int insertVal) {
        if (nullptr == head) {
            head = new Node(insertVal);
            head->next = head;
            return head;
        }
        auto cur = head;
        while (cur->next != head) { // 当前节点不是尾节点时
            if (cur->next->val < cur->val) {    // 找到cur为当前循环链表内最大的节点
                // 对于比最小的还小和比最大的还大两种情况，都是插入在最大的之后。这两种情况里，cur都是最大的，cur->next是最小的，是循环跳跃点。
                if (cur->next->val >= insertVal) {
                    break;  // 比最小的还小
                } else if (cur->val <= insertVal) {
                    break;  // 比最大的还大
                }
                
            }
            if (cur->val <= insertVal && cur->next->val >= insertVal) {
                break;
            }
            cur = cur->next;
        }
        cur->next = new Node(insertVal, cur->next);
        return head;
    }
};
}