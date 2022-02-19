#include "../lib/ListNode.h"

namespace leetcode_cpp {
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (nullptr == head || nullptr == head->next || nullptr == head->next->next) {
            return head;
        }

        ListNode *oddNode = head;               // 奇链表的尾结点
        ListNode *evenNode = head->next;        // 偶链表的尾结点
        ListNode *evenHead = evenNode;          // 偶链表的头结点
        while (nullptr != evenNode && nullptr != evenNode->next) {
            oddNode->next = evenNode->next;
            evenNode->next = oddNode->next->next;
            oddNode = oddNode->next;
            evenNode = evenNode->next;
        }

        oddNode->next = evenHead;
        return head;
    }
};
}