#include <vector>
#include <iostream>
#include <deque>
#include "../lib/BinarySearchTree.h"
#include <unordered_map>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-18 21:32:51
author: edinw
@
*/

/*
** 本题与主站 538 题相同： https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
** 本题与主站 1038 题相同：https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/
** 
**
** 给定一个二叉搜索树，请将它的每个节点的值替换成树中大于或者等于该节点值的所有节点值之和。
*/

using namespace binary_search_tree;

namespace leetcode_cpp {
class Solution {
    std::unordered_map<int, int> prefix;
public:
    TreeNode* covertBST(TreeNode *root) {
        backtrack(root);
        return root;
    }

private:
    int backtrack(TreeNode *node) {
        if (nullptr == node) {
            return 0;
        }

        int right = backtrack(node->right);
        node->val += right;
        int left = backtrack(node->left);
        return node->val;
    }
};
}

int main(int argc, char **argv) {
    BinarySearchTree bst;
    std::vector<int> nums {4,1,6,0,2,5,7,3,8};
    bst.InitTree(nums);
    bst.Traversal(1);
    TreeNode *root = bst.GetRoot();
    TreeNode *newRoot = leetcode_cpp::Solution().covertBST(root);
    bst.SetRoot(newRoot);
    bst.Traversal(1);
    return 0;
}