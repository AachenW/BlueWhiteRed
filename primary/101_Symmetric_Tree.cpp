#include <vector>
#include <string>
#include <iostream>
#include <deque>
/*
@
LeetCode 热题 HOT 100
time: 2022-01-29 21:30:37
author: edinw
@
*/

/*
**  Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

namespace leetcode_cpp {
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return check(root->left, root->right);
    }
private:
    bool check(TreeNode *p, TreeNode *q) {
        if (nullptr == p && nullptr == q) {
            return true;
        }
        if (nullptr == p || nullptr == q) {
            return false;
        }
        return p->val == q->val && check(p->left, q->right) && check(p->right, q->left);
    }
};

class Solution2 {
public:
    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }

private:
    bool check(TreeNode *p, TreeNode *q) {
        std::deque<TreeNode*> queue;
        queue.emplace_back(p);
        queue.emplace_back(q);
        while (!queue.empty()) {
            TreeNode *node1 = queue.front();
            queue.pop_front();
            TreeNode *node2 = queue.front();
            queue.pop_front();
            if (nullptr == node1 && nullptr == node2) {
                continue;
            }
            if ((nullptr == node1 || nullptr == node2) || (node1->val != node2->val)) {
                return false;
            }
            queue.emplace_front(node1->left);
            queue.emplace_front(node2->right);
            queue.emplace_front(node1->right);
            queue.emplace_front(node2->left);
        }
        return true;
    }
};
}