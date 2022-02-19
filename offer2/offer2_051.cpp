#include <vector>
#include <iostream>
#include <deque>
#include "limits.h"
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-16 20:03:13
author: edinw
@
*/

/*
** 注意：本题与主站 437 题相同：https://leetcode-cn.com/problems/path-sum-iii/
**
** 给定一个二叉树的根节点 root ，和一个整数 targetSum ，求该二叉树里节点值之和等于 targetSum 的 路径 的数目。
**路径 不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
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
    int ret = 0;
public:
    int maxPathSum(TreeNode *root) {
        ret = INT_MIN;
        backtrack(root);
        return ret;
    }

    // 贡献值：该节点为根节点的子树中寻找以该节点为起点的一条路径，使得该路径上的节点值之和最大。
    // 空节点的最大贡献值等于 0。
    // 非空节点的最大贡献值等于节点值与其子节点中的最大贡献值之和（对于叶节点而言，最大贡献值等于节点值）。
private:
    int backtrack(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        
        // 递归计算左右子节点的最大贡献值
        // 只有在最大贡献值大于 0 时，才会选取对应子节点
        int left = std::max(0, backtrack(root->left));
        int right = std::max(0, backtrack(root->right));

        // 节点的最大路径和取决于该节点的值与该节点的左右子节点的最大贡献值
        ret = std::max(ret, left + right + root->val);

        // 返回节点的最大贡献值
        return root->val + std::max(left, right);
    }

};
}