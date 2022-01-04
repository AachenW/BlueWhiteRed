#include "ListNode.h"

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-04 19:36:43
author: edinw
@
*/

/*
注意：本题与主站 234 题相同：https://leetcode-cn.com/problems/palindrome-linked-list/

给定一个链表的 头节点 head ，请判断其是否为回文链表。

如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的。
*/

namespace leetcode_cpp{
class Solution{
public:
    bool isPalindrome(ListNode* head) {
        ListNode *mid = middleNode(head);
        ListNode *l1 = head;
        ListNode *l2 = reverseList(mid->next);
        while (nullptr != l1) {
            if (l1->val != l2->val) {
                return false;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        return true;
    }

private:
    ListNode* middleNode(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (nullptr != fast->next && nullptr != fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }
        ListNode *prev = nullptr, *cur = head;
        while (nullptr != cur) {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

};
}

int main(int argc, char **argv) {
    List list;
    std::vector<int> nums {1, 2, 3, 3, 2, 1};
    list.createList(nums);
    ListNode *head = list.getListHead();
    std::cout << leetcode_cpp::Solution().isPalindrome(head) << std::endl;
    return 0;
}