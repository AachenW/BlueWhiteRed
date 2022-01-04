#include "ListNode.h"

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-02 22:46:58
author: edinw
@
*/

/*
注意：本题与主站 143 题相同：https://leetcode-cn.com/problems/reorder-list/ 

L0 -> L1 -> ... -> Ln-1 -> Ln 将其重新排列后变为
L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 -> ...
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
*/

namespace leetcode_cpp {
class Solution {
public:
    void reorderList(ListNode *head) {
        if (head == nullptr) {
            return;
        }
        std::vector<ListNode *> vec;
        ListNode *node = head;
        while (node != nullptr) {
            vec.emplace_back(node);
            node = node->next;
        }
        int i = 0, j = vec.size() - 1;
        while (i < j) {
            vec[i]->next = vec[j];
            i++;
            if (i == j) {
                break;
            }
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
        return;
    }
};

class Solution2{
public:
    void reorderList(ListNode *head) {
        if (nullptr == head) {
            return;
        }
        ListNode *mid = middleNode(head);
        ListNode *l1 = head;
        ListNode *l2 = mid->next;
        mid->next = nullptr;
        l2 = reverseList(l2);
        mergeList(l1, l2);
    }

private:
    ListNode* middleNode(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next != nullptr && fast->next->next != nullptr) {
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

    void mergeList(ListNode *l1, ListNode *l2) {
        ListNode *l1_temp = nullptr;
        ListNode *l2_temp = nullptr;
        while (l1 != nullptr && l2 != nullptr) {
            l1_temp = l1->next;
            l2_temp = l2->next;

            l1->next = l2;
            l1 = l1_temp;
            l2->next = l1;
            l2 = l2_temp;
        }
    }
};
}

int main(int argc, char **argv) {
    List linkNode;
    std::vector<int> nums{1, 2, 3, 4, 5};
    linkNode.createList(nums, 1);
    ListNode *head = linkNode.getListHead();
    leetcode_cpp::Solution2().reorderList(head);
    linkNode.travelList();
    linkNode.clearList();
    if (linkNode.ifClear()) {
        std::cout << "link has been cleared!" << std::endl;
    } else {
        std::cout << "link hasn't been cleared, please delete the link avoiding memory leak!" << std::endl;
    }
    return 0;
}