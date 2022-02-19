#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <numeric>

/*
@
LeetCode 精选 TOP 面试题
time: 2021-12-14 22:29:04
author: edinw
@
*/

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

namespace leetcode_cpp{
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head, *q = head;
        ListNode* k = nullptr;
        while (n--) {
            if ((p->next == nullptr) && (n > 0)) {
                return nullptr;
            }
            p = p->next;
        }

        while(!p->next) {
            k = q;
            p = p->next;
            q = q->next;
        }
        k->next = q->next;
        return head;
    }
};
}

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

int main(int argc, char** argv) {
    std::vector<int> nums {1, 2, 3, 4, 5};
    int target = 2;
    
    ListNode* head = generate_list(nums);

    //print_list(head);
    ListNode* ans = leetcode_cpp::Solution().removeNthFromEnd(head, target);
    print_list(ans);
    
    delete[] head;
}

