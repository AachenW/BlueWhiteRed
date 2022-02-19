#include <iostream>
#include <vector>
#include <deque>
#include "../lib/ListNode.h"

/*
@
projetc: leetcode
time: 2022-01-16 19:45:58
author: edinw
@
*/

/*
给定两个以 升序排列 的整数数组 nums1 和 nums2 , 以及一个整数 k 。

定义一对值 (u,v)，其中第一个元素来自 nums1，第二个元素来自 nums2 。

请找到和最小的 k 个数对 (u1,v1),  (u2,v2)  ...  (uk,vk) 。
*/

namespace leetcode_cpp {
class Solution {
    std::vector<int> arr;
public:
    Solution(ListNode* head) {
        while (head) {
            arr.emplace_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

class Solution2 {
    ListNode *head;
public:
    Solution2(ListNode *head) {
        this->head = head;
    }

    int getRandom() {
        int i = 1, ans = 0;
        for (auto node = head; node; node = node->next, ++i) {
            if (rand() % i == 0) {
                ans = node->val;
            }
        }
        return ans;
    }
};
}