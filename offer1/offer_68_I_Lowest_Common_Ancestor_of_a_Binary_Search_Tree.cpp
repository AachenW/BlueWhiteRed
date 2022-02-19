#include <vector>

/*
@
LeetCode 剑指offer
time: 2022-02-15 22:11:48
author: edinw
@
*/

/*
**  注意：本题与主站 235 题相同：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
**
**  Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
**
**  According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has 
**      both p and q as descendants (where we allow a node to be a descendant of itself).”
*/

typedef struct Node{
    int val;
    TreeNode* left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode;

namespace leetcode_cpp {
class Solution1{
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> path_p = getPath(root, p);
        std::vector<TreeNode*> path_q = getPath(root, q);

        TreeNode* ancestor;
        for (int i = 0; i < path_p.size() && i < path_q.size(); ++i) {
            if (path_p[i] == path_q[i]) {
                ancestor = path_q[i];
            } else {
                break;
            }
        } 
        return ancestor;
    }

private:
    std::vector<TreeNode*> getPath(TreeNode* root, TreeNode* target) {
        std::vector<TreeNode*> path;
        TreeNode* node = root;
        while(node != target) {
            path.emplace_back(node);
            if (node->val < target->val) {
                node = node->right;
            } else {
                node = node->left;
            }
        }
        path.emplace_back(node);
        return path;
    }
};

class Solution2{
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ancestor = root;
        while (true) {
            if (p->val < ancestor->val && q->val < ancestor->val) {
                ancestor = ancestor->left;
            } else if (p->val > ancestor->val && q->val > ancestor->val) {
                ancestor = ancestor->right;
            } else {
                break;
            }
        }
        return ancestor;
    }
};
}