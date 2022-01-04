#include <unordered_set>
#include <iostream>
#include <vector>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-02 21:32:56
author: edinw
@
*/

/*
注意：本题与主站 142 题相同： https://leetcode-cn.com/problems/linked-list-cycle-ii/

给定一个链表，返回链表开始入环的第一个节点。 从链表的头节点开始沿着 next 指针进入环的第一个节点为环的入口节点。如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。
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
    /*
    一个非常直观的思路是：我们遍历链表中的每个节点，并将它记录下来；一旦遇到了此前遍历过的节点，就可以判定链表中存在环。借助哈希表可以很方便地实现。
    */
    ListNode *detectCycle(ListNode *head) {
        std::unordered_set<ListNode*> visited;
        while (nullptr != head) {
            if (visited.count(head)) {
                return head;
            }
            visited.insert(head);
        }
        return nullptr;
    }
};

class Solution2 {
public:
    /*
    a = c + (b + c)(n - 1)
    公式说明a一定是n - 1圈加c的长度，这个时候，让ptr和慢指针同时+1着走， 那么慢指针走c之后，ptr到环入口的距离只剩整n - 1圈的距离了，而且此时慢指针也刚好走到入口处了， （因为我们无法确定c是多少，这个时候还得不出结论，那么：） 他俩一起走完n - 1圈的距离之后就会相遇，而且此时正好是入口
    */
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (nullptr != fast) {
            slow = slow->next;
            if (nullptr == fast->next) {
                return nullptr;
            }
            fast = fast->next->next;
            // slow 到环的入口点还有c个结点的距离
            if (fast == slow) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};
}