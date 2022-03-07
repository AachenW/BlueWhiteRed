#include <vector>
#include <deque>
#include "../lib/BinarySearchTree.h"

/*
@
LeetCode
time: 2022-02-26 21:36:25
author: edinw
@
*/

using namespace binary_search_tree;

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root) {
        std::deque<std::pair<TreeNode*, int>> stk;
        stk.emplace_back(std::make_pair(root, false));
        std::vector<int> ans;
        
        while (!stk.empty()) {
            auto [node, visited] = stk.back();
            stk.pop_back();
            if (nullptr == node) {
                continue;
            } else {
                if (!visited) {
                    stk.emplace_back(std::make_pair(node->right, false));
                    stk.emplace_back((std::make_pair(node->left, false)));
                    stk.emplace_back(std::make_pair(node, true));
                } else {
                    ans.emplace_back(node->val);
                }
            }
        }
        
        return ans;
    }
};
}