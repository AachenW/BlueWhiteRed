#include <vector>
#include <string>
#include <iostream>
#include "../lib/ListNode.h"

/*
@
LeetCode 剑指offer
time: 2022-02-08 21:13:30
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto getLenOfList = [] (ListNode *root) -> int {
            int len = 0;
            while (nullptr != root) {
                ++len;
                root = root->next;
            }
            return len;
        };

        int lenA = getLenOfList(headA);
        int lenB = getLenOfList(headB);
        int diffLen;
        ListNode *longerList = nullptr, *shorterList = nullptr;

        if (lenA > lenB) {
            longerList = headA;
            shorterList = headB;
            diffLen = lenA - lenB;
        } else {
            longerList = headB;
            shorterList = headA;
            diffLen = lenB - lenA;
        }

        while (diffLen > 0) {
            longerList = longerList->next;
            --diffLen;
        }

        while (nullptr != longerList) {
            if (longerList->val == shorterList->val && longerList == shorterList) {
                return longerList;
            }
            longerList = longerList->next;
            shorterList = shorterList->next;
        }
        return nullptr;
    }

};

class Solution2 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (nullptr == headA || nullptr == headB) {
            return nullptr;
        }
        ListNode *pA = headA, *pB = headB;
        // 设headA的不相交部分有a个结点，链表headB的不相交部分有b个结点，两个链表相交的部分有c个结点，则有a+c = m, b+c = n;
        // pNodeA移动了a+b+c次，pNodeB移动了b+c+a次之后，两个指针会同时到达两个链表相交的结点，该结点也是两个指针第一次同时指向的结点，此时返回相交的结点
        while (pA != pB) {
            pA = pA == nullptr ? headB : pA->next;
            pB = pB == nullptr ? headA : pB->next;
        }
        return pA;
    }
};
}

int main(int argc, char **argv) {
    List *linkListA = new List();
    List *linkListB = new List();
    std::vector<int> numsA {4, 1, 8, 4, 5};
    std::vector<int> numsB {5, 0, 1, 8, 4, 5};

    linkListA->createList(numsA);
    linkListB->createList(numsB);
    ListNode *headA = linkListA->getListHead();
    ListNode *headB = linkListB->getListHead();

    ListNode *ansNode = leetcode_cpp::Solution().getIntersectionNode(headA, headB);
    std::cout << ansNode->val << std::endl;
    linkListA->clearList();
    linkListB->clearList();
    return 0;
}