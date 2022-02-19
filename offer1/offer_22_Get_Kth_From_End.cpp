#include <vector>
#include <iostream>
#include "../lib/ListNode.h"

/*
@
LeetCode 剑指offer
time: 2022-02-07 22:32:16
author: edinw
@
*/

/*
**  输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。

**  例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。
*/

namespace leetcode_cpp {
class Solution {
public:
    ListNode* getKthFromEnd(ListNode *head, int k) {
        ListNode *slow = head, *fast = head;

        while (k-- > 0 && nullptr != fast->next) {
            fast = fast->next;
        }
        if (k != 0) {
            return nullptr;
        }
        while (nullptr != fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
}

int main(int argc, char **argv) {
    List *linkList = new List();
    std::vector<int> nums {1, 2, 3, 4, 5};
    linkList->createList(nums);
    ListNode *head = linkList->getListHead();
    int k = 2;
    ListNode *newHead = leetcode_cpp::Solution().getKthFromEnd(head, k);
    linkList->setListHead(newHead);
    linkList->travelList();
    linkList->setListHead(head);
    linkList->clearList();
    return 0;
}