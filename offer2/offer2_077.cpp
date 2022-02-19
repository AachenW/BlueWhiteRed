#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "../lib/ListNode.h"
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-26 20:39:29
author: edinw
@
*/

/*
**  注意：本题与主站 148 题相同：https://leetcode-cn.com/problems/sort-list/
** 
**  Given the head of a linked list, return the list after sorting it in ascending order.
*/

namespace leetcode_cpp {
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }


        ListNode* head1 = head;
        ListNode* head2 = split(head);

        head1 = sortList(head1);
        head2 = sortList(head2);

        return merge(head1, head2);
    }

private:
    ListNode* split(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while (nullptr != fast && nullptr != fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *mid = slow->next;
        slow->next = nullptr;
        return mid;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;
        while (nullptr != head1 && nullptr != head2) {
            if (head1->val < head2->val) {
                cur->next = head1;
                head1 = head1->next;
            } else {
                cur->next = head2;
                head2 = head2->next;
            }
            cur = cur->next;
        }
        cur->next = (nullptr == head1) ? head2 : head1;

        ListNode* ret = dummy->next;
        delete dummy;
        dummy = nullptr;
        return ret;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{4, 2, 1, 3};
    List *list = new List();
    list->createList(nums);
    ListNode *head = list->getListHead();
    list->travelList();
    head = leetcode_cpp::Solution().sortList(head);
    list->setListHead(head);
    list->travelList();
    list->clearList();
    delete list; 
}