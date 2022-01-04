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
time: 2021-12-15 22:29:32
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

namespace leetcode_cpp {
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *a, ListNode *b) {
        if((!a) || (!b)) return a ? a : b;
        // tail 记录下一个插入位置的前一个位置，aPtr和bPtr来记录a,b未合并部分的第一位
        ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
        while(aPtr && bPtr) {
            if (aPtr->val < bPtr->val) {
                tail->next = aPtr;
                aPtr = aPtr->next;
            } else {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }

    ListNode* mergeKLists_1(std::vector<ListNode*> &lists) {
        ListNode *ans = nullptr;
        decltype(lists.size()) nLength = lists.size();
        for (decltype(nLength) i = 0; i < nLength; ++i) {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }

    ListNode* merge(std::vector<ListNode*> &lists, int l, int r) {
        if (l == r) {
            return lists[l];
        }
        if (l > r) {
            return nullptr;
        }
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
    }

    ListNode* mergeKLists_2(std::vector<ListNode*> &lists) {
        return merge(lists, 0, lists.size() - 1);
    }
};
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

void print_list(ListNode* head) {
    while(head != nullptr) {
        std::cout << head->val << std::endl;
        head = head->next;
    }
}

void delete_list(ListNode* head) {
    delete head;
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> nums {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    std::vector<ListNode*> list;
    for (auto num : nums) {
        list.emplace_back(generate_list(num));
    }
    ListNode* ans = leetcode_cpp::Solution().mergeKLists_2(list);
    print_list(ans);
    for (auto &l : list) {
        delete l;
    }
    return 0;
}