#include <vector>
#include <iostream>
#include "ListNode.h"
/*
@
projetc: leetcode
time: 2022-01-03 22:03:16
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    ListNode* middleNode(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
}

int main(int argc, char **argv) {
    List linkNode;
    std::vector<int> nums{1, 2, 3, 4, 5, 6};
    linkNode.createList(nums, 1);
    ListNode *head = linkNode.getListHead();
    head = leetcode_cpp::Solution().middleNode(head->next);
    std::cout << head->val << std::endl;
    linkNode.clearList();
    if (linkNode.ifClear()) {
        std::cout << "link has been cleared!" << std::endl;
    } else {
        std::cout << "link hasn't been cleared, please delete the link avoiding memory leak!" << std::endl;
    }
    return 0;
}