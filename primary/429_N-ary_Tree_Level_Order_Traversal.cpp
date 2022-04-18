#include <bits/stdc++.h>

/*
@
project: leetcode
time: 2022-04-08 16:43:03
author: edinw
@
*/

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    std::vector<std::vector<int>> levelOrder(Node* root) {
        if (!root) {
            return {};
        }

        std::vector<std::vector<int>> ans;
        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int cnt = q.size();
            std::vector<int> level;
            for (int i = 0; i < cnt; ++i) {
                Node* cur = q.front();
                q.pop();
                level.push_back(cur->val);
                for (Node* child: cur->children) {
                    q.push(child);
                }
            }
            ans.push_back(move(level));
        }

        return ans;
    }
};