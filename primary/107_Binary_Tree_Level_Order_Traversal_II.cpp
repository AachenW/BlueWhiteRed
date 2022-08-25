#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-19 22:44:58 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> levelOrderBottom(TreeNode *root) {
        if (nullptr == root) {
            return {};
        }

        std::deque<TreeNode*> que;
        que.emplace_back(root);
        std::vector<int> tmp;
        std::vector<std::vector<int>> ans;

        while (!que.empty()) {
            int qSize = que.size();
            for (int i = 0; i < qSize; ++i) {
                TreeNode *node = que.front();
                que.pop_front();
                tmp.emplace_back(node->val);
                if (nullptr != node->left) {
                    que.emplace_back(node->left);
                }
                if (nullptr != node->right) {
                    que.emplace_back(node->right);
                }
            }
            ans.emplace_back(tmp);
            tmp.clear();
        }
        
        std::reverse(ans.begin(), ans.end());
        
        return ans;
    }
};

}

