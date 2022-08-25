#include <bits/stdc++.h>

/*
@
LeetCode 
time: 2022-05-11 12:07:21
author: edinw
@
*/

namespace leetcode_cpp {
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::string s;

        std::function<void(TreeNode*)> rserialize = [&] (TreeNode *root) {
            if (nullptr == root) {
                s += "null,";
                return;
            }

            s += std::to_string(root->val) + ",";
            rserialize(root->left);
            rserialize(root->right);
        };

        rserialize(root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        std::deque<std::string> strs;
        auto split = [&] (char c) {
            std::stringstream ss(data);
            std::string tmp;
            while (std::getline(ss, tmp, c)) {
                strs.emplace_back(tmp);
            }
            if (!tmp.empty() && c == tmp[0]) {
                strs.emplace_back("");
            }
        };

        std::function<TreeNode*()> rdeserialize = [&] () -> TreeNode* {
            if ("null" == strs.front()) {
                strs.pop_front();
                return nullptr;
            }

            int curr = std::stoi(strs.front()); strs.pop_front();
            TreeNode *node = new TreeNode(curr);
            node->left = rdeserialize();
            node->right = rdeserialize();
            return node;
        };

        split(',');
        return rdeserialize();
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
}
