#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include "ListNode.h"
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-26 22:06:12
author: edinw
@
*/

/*
**  注意：本题与主站 23 题相同： https://leetcode-cn.com/problems/merge-k-sorted-lists/
** 
**  You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
**  Merge all the linked-lists into one sorted linked-list and return it.
*/

namespace leetcode_cpp {
class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*> &lists) {
        return merge(lists, 0, lists.size() - 1);
    }

private:
    ListNode* merge(std::vector<ListNode*> &lists, int lo, int hi) {
        if (lo == hi) {
            return lists[lo];
        }
        if (lo > hi) {
            return nullptr;
        }
        int mid = (lo + hi) >> 1;
        return mergeTwoLists(merge(lists, lo, mid), merge(lists, mid + 1, hi));
    }

    ListNode* mergeTwoLists(ListNode *head1, ListNode *head2) {
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        while (nullptr != head1 && nullptr != head2) {
            if (head1->val < head2->val) {
                curr->next = head1;
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }
        
        curr->next = (nullptr == head1) ? head2 : head1;

        curr = dummy->next;
        delete dummy;
        dummy = nullptr;
        return curr;
    }
};

class Solution2 {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    std::priority_queue<Status> q;
    
    ListNode* mergeKLists(std::vector<ListNode*> &lists) {
        for (const auto &node: lists) {
            if (node) {
                q.push({node->val, node});
            }
        }

        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top();
            q.pop();
            tail->next = f.ptr;
            tail = tail->next;
            if (f.ptr->next) {
                q.push({f.ptr->next->val, f.ptr->next});
            }
        }
        return head.next;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> nums {{1, 4, 5}, {1, 3, 4}, {2, 6}};
    std::vector<ListNode*> lists;
    std::vector<List*> listObjects;
    List *list = nullptr;
    ListNode *head = nullptr;
    for (const auto &num: nums) {
        list = new List();
        list->createList(num);
        lists.emplace_back(list->getListHead());
        listObjects.emplace_back(list);
        list->travelList();
    }
    head = leetcode_cpp::Solution().mergeKLists(lists);
    List *listHead = new List();
    listHead->setListHead(head);
    listHead->travelList();
    delete listHead;
    
    // for (const auto &list: lists) {
    //     delete list;        
    // }
    for (const auto &list: listObjects) {
        list->clearList();
    }
    
    return 0;
}