#include <unordered_set>
#include <iostream>
#include <vector>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-02 22:11:58
author: edinw
@
*/

/*
注意：本题与主站 160 题相同：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/

给定两个单链表的头节点 headA 和 headB ，请找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (nullptr == headA || nullptr == headB) {
            return nullptr;
        }
        ListNode *pNodeA = headA, *pNodeB = headB;
        // 设headA的不相交部分有a个结点，链表headB的不相交部分有b个结点，两个链表相交的部分有c个结点，则有a+c = m, b+c = n;
        // pNodeA移动了a+b+c次，pNodeB移动了b+c+a次之后，两个指针会同时到达两个链表相交的结点，该结点也是两个指针第一次同时指向的结点，此时返回相交的结点
        while (pNodeA != pNodeB) {
            pNodeA = nullptr == pNodeA ? headB : pNodeA->next;
            pNodeB = nullptr == pNodeB ? headA : pNodeB->next; 
        }
        return pNodeB;
    }
};

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_set<ListNode *> visited;
        ListNode *temp = headA;
        while (nullptr != temp) {
            visited.insert(temp);
            temp = temp->next;
        }
        while (nullptr != headB) {
            if (visited.count(headB)) {
                return headB;
            }
            headB = headB->next;
        }
        return nullptr;
    }
};
}