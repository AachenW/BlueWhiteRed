#include <deque>
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
注意：本题与主站 445 题相同：https://leetcode-cn.com/problems/add-two-numbers-ii/

给定两个 非空链表 l1和 l2 来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。

可以假设除了数字 0 之外，这两个数字都不会以零开头。
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        // 利用两个双端队列进行存储
        std::deque<int> dq1, dq2;
        ListNode *p1 = l1, *p2 = l2;
        // 将两个链表的元素存储到队列中
        while (nullptr != p1) {
            dq1.push_back(p1->val);
            p1 = p1->next;
        }
        while (nullptr != p2) {
            dq2.push_back(p2->val);
            p2 = p2->next;
        }
        int carry = 0;
        ListNode *ans = nullptr;
        while (!dq1.empty() || !dq2.empty() || carry != 0) {
            // 当两个链表的节点不相等的时候，补0
            int a = dq1.empty() ? 0 : dq1.back();
            int b = dq2.empty() ? 0 : dq2.back();
            if (!dq1.empty()) {
                dq1.pop_back();
            }
            if (!dq2.empty()) {
                dq2.pop_back();
            }
            // 取和
            int cur = a + b + carry;
            // 取进位
            carry = cur / 10;
            cur = cur % 10;
            // 构造一个新的链表存储节点值
            auto curnode = new ListNode(cur);
            // 这里让链表的指向是相反的，当为倒数第二个节点的，指向第一个节点
            curnode->next = ans;
            // 然后再把这个节点指向第三个节点，循环下去会导致最后ans指向头节点
            ans = curnode;

        }
        return ans;
    }
};
}

int main (int argc, char **argv) {
    std::vector<int> nums1 {7, 2, 4, 3};
    std::vector<int> nums2 {5, 6, 4};
    ListNode *l1 = generate_list(nums1);
    ListNode *l2 = generate_list(nums2);
    auto res = leetcode_cpp::Solution().addTwoNumbers(l1, l2);
    print_list(res);
    return 0;
}