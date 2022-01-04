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
time: 2021-12-08 22:47:54
author: edinw
@
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