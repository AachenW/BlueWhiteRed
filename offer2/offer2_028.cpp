#include "./lib/ListNode.h"

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-04 20:15:36
author: edinw
@
*/

/*
注意：本题与主站 430 题相同： https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/

多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

给定位于列表第一级的头节点，请扁平化列表，即将这样的多级双向链表展平成普通的双向链表，使所有结点出现在单级双链表中。
*/

namespace leetcode_cpp {
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    Node* flatten(Node* head) {
        dfs(head);
        return head;
    }

private:
    void dfs(Node *node) {
        if (nullptr == node) {
            return;
        }
        Node *next = node->next;    // 将node与node的下一个节点next断开，并保存next指针，因为ans指向node后修改了next指针
        node->prev = ans;
        if (nullptr != ans) {
            ans->next = node;       // 当node不是首节点时，将ans的next指向node
        }
        ans = node;                 // 处理完当前节点，更新ans节点
        if (nullptr != node->child) {
            dfs(node->child);       // 优先搜索child节点
            node->child = nullptr;  // 注意此处一定不能忘！
        }
        if (nullptr != next) {
            dfs(next);              // 后搜索next节点
        }
    }

private:
    Node *ans {nullptr};
};

class Solution2 {
public:
    Node* flatten(Node *head) {
        dfs(head);
        return head;
    }

private:
    Node* dfs(Node *node) {
        Node *cur = node;
        // 记录链表的最后一个节点
        Node *last = nullptr;

        while (cur) {
            Node *next = cur->next;
            // 如果有子节点，那么首先处理子节点
            if (cur->child) {
                Node *child_last = dfs(cur->child);

                next = cur->next;
                // 将node与child相连
                cur->next = cur->child;
                cur->child->prev = cur;

                // 如果next不为空，就将last与next相连
                if (next) {
                    child_last->next = next;
                    next->prev = child_last;
                }

                // 将child置为空
                cur->child = nullptr;
                last = child_last;
            } else {
                last = cur;
            }
            cur = next;
        }
        return last;
    }
};
}