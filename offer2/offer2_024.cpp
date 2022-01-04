#include <unordered_set>
#include <iostream>
#include <vector>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-02 22:46:58
author: edinw
@
*/

/*
注意：本题与主站 206 题相同： https://leetcode-cn.com/problems/reverse-linked-list/

给定单链表的头节点 head ，请反转链表，并返回反转后的链表的头节点。
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
    ListNode* reverseList(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }

        ListNode *prev = nullptr, *cur = head;
        while (cur) {
            ListNode *q = cur->next;
            cur->next = prev;
            prev = cur;
            cur = q;
        }
        return prev;
    }
};

class Solution2{
public:
    ListNode* reverseList(ListNode *head) {
        if (nullptr == head || nullptr == head->next) {
            return head;
        }
    
        ListNode *newNode = reverseList(head->next);    // 返回未反转部分的尾节点    
        head->next->next = head;    // head是未反转部分的尾节点
        head->next = nullptr;       // 将head结点添加到已反转链表的尾部
        return newNode;             // 返回更新后已反转链表的尾节点
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1,2,3,4,5};
    ListNode *head = generate_list(nums);
    head = leetcode_cpp::Solution2().reverseList(head);
    print_list(head);
    return 0;
}