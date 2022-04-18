#include <bits/stdc++.h>

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

namespace leetcode_cpp {
class Solution {
public:
    int maxDepth(Node* root) {
        if (nullptr == root) {
            return 0;
        }

        int ans = 1;
        for (auto &&node : root->children) {
            ans = std::max(ans, maxDepth(node) + 1);
        }
        return ans;
    }
};
}