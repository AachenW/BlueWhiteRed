#include "../lib/BinaryTree.h"
#include <bits/stdc++.h>

/*
@
LeetCode 剑指offerⅡ
time: 2022-03-05 18:07:02
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    int pathSum(TreeNode *root, int targetSum) {
        if (nullptr == root) {
            return 0;
        }
        
        std::function<int(TreeNode*, long long)> backtrack = [&] (TreeNode *root, long long targetSum) -> int {
            if (nullptr == root) {
                return 0;
            }

            int ret = 0;
            if (root->val == targetSum) {
                ++ret;
            }
            ret += backtrack(root->left, targetSum - root->val);
            ret += backtrack(root->right, targetSum - root->val);
            return ret;
        };

        int ret = backtrack(root, targetSum);
        ret += pathSum(root->left, targetSum);
        ret += pathSum(root->right, targetSum);
        
        return ret;
    }
};

class Solution2 {
public:
    int pathSum(TreeNode *root, int targetSum) {
        std::unordered_map<long long, int> prefixSum;
        prefixSum[0] = 1;   // 根节点到当前节点的前缀和恰好等于targetSum时，返回1.

        std::function<int(TreeNode*, long long)> backtrack = [&](TreeNode *root, long long curr) -> int {
            if (nullptr == root) {
                return 0;
            }

            int ret = 0;
            curr += root->val;
            if (prefixSum.count(curr - targetSum)) {
                ret = prefixSum[curr - targetSum];
            }

            ++prefixSum[curr];
            ret += backtrack(root->left, curr);
            ret += backtrack(root->right, curr);
            --prefixSum[curr];  // 回溯时，当前节点不再访问，所以要对prefixSum哈希表进行处理

            return ret;
        };

        return backtrack(root, 0);
    }
};
}
