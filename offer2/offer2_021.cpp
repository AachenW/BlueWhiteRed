#include <string>
#include <iostream>
#include <vector>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-02 20:51:32
author: edinw
@
*/

/*
注意：本题与主站 19 题相同： https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/
给定一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

void print_list(ListNode* head) {
    while(head != nullptr) {
        std::cout << head->val << std::endl;
        head = head->next;
    }
}

ListNode* generate_list(std::vector<int>& nums) {
    int nLength = nums.size();
    ListNode* head = new ListNode[nLength];
    ListNode* p = head;
    for (int i = 0; i < nLength - 1; i++) {
        (head[i]).val = nums[i];
        head[i].next = &head[i + 1];
    }
    
    head[nLength - 1].val = nums[nLength - 1];
    head[nLength - 1].next = nullptr;
    return head;
}

namespace leetcode_cpp {
class Solution{
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummyNode = new ListNode(0, head);
        ListNode *first = head, *second = dummyNode;
        for (int i = 0; i < n; ++i) {
            first = first->next;
        }
        while (first) {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;
        ListNode *ans = dummyNode->next;
        delete dummyNode;
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1, 2, 3, 4, 5};
    int target = 2;
    ListNode *head = generate_list(nums);
    head = leetcode_cpp::Solution().removeNthFromEnd(head, target);
    print_list(head);
    return 0;
}