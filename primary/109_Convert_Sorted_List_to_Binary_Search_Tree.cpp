#include <bits/stdc++.h>
#include "../lib/ListNode.h"
#include "../lib/BinaryTree.h"

/*
@
projetc: leetcode
time: 2022-05-11 13:50:07 
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public: 
    TreeNode* sortedListToBST(ListNode *head) {
        auto getLength = [&] (ListNode *head) {
            int ret = 0;
            while (nullptr != head) {
                ++ret;
                head = head->next;
            }
            return ret;
        };

        std::function<TreeNode*(ListNode*&, int, int)> = [&] (ListNode*& head, int left, int right) -> TreeNode* {
            if (left > right) return nullptr;

            int mid = (left + right + 1) / 2;
            TreeNode *root = new TreeNode();    // 构造二叉树的结构
            root->left = build(head, left, mid - 1);
            // 往二叉树的各个节点中插入中序遍历的值
            root->val = head->val;
            head = head->next;
            root->right = build(head, mid + 1, right);
            return root;
        };

        int len = getLength(head);
        return build(head, 0, len - 1);
    }
};
}

