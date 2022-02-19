#include <vector>
#include <iostream>
#include <deque>
#include <unordered_map>
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
    int targetSum = 0;
public:
    int pathSum(TreeNode *root, int targetSum) {
        if (nullptr == root) {
            return 0;
        }
        return backtrack(root, targetSum);
    }

    int backtrack(TreeNode *node, int targetSum) {
        if (nullptr == node) {
            return 0;
        }
        int ret = 0;
        if (node->val == targetSum) {
            ++ret;
        }
        ret += backtrack(node->left, targetSum - node->val);
        ret += backtrack(node->right, targetSum - node->val);
    }
};

class Solution2 {
    // value: the number of prefix is equal to key
    // key: 由根结点到当前结点的路径上所有节点的和
    std::unordered_map<long long, int> prefix;
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (nullptr == root) {
            return 0;
        }
        // 对于空路径我们也需要保存预先处理一下，此时因为空路径不经过任何节点，因此它的前缀和为 0.
        prefix[0] = 1;
        return backtrack(root, 0, targetSum);
    }

    /*
    **  解释一下curr - targetSum的意思
    **  root,p1,p2,...,pi,pi+1,...,pj
    **  已经储存了 root~pi 前缀和, 0 <= i <= j，当前点为pj
    **  我们现在想要pi+1~pj的和，且和为targetSum
    **  curr = root + p1 +...+pj
    **  targetSum = pi+1 + ... + pj
    **  所以curr - targetSum = root + p1+...+pi，只要curr-target存在，所以当前点就满足targetSum
    */
private:
    // cur: 记录下根节点 root 到当前节点 p 的路径上除当前节点以外所有节点的前缀和
    int backtrack(TreeNode *node, int curr, int targetSum) {
        if (nullptr == node) {
            return 0;
        }
        int ret = 0;
        curr += node->val;
        // 在已保存的路径前缀和中查找是否存在前缀和刚好等于当前节点到根节点的前缀和 curr 减去 targetSum.
        if (prefix.count(curr - targetSum)) {
            ret = prefix.at(curr - targetSum);
        }
        ++prefix[curr];
        ret += backtrack(node->left, curr, targetSum);
        ret += backtrack(node->right, curr, targetSum);
        // backtrack
        --prefix[curr];
        return ret;
    }
};
}