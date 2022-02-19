#include <vector>
#include <iostream>
#include <deque>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-18 20:08:40
author: edinw
@
*/

/*
**  注意：本题与主站 297 题相同：https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/ 

**  序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
**  请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
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
public:
    // Encode a tree to a single string.
    std::string serialize(TreeNode *root) {
        std::string str;
        rseralize(root, str);
        return str;
    }

    // Decode your encoded data to tree
    TreeNode* deserialize(std::string data) {
        std::vector<std::string> dataVec;
        std::string str;
        for (const auto &ch: data) {
            if (ch == ',') {
                dataVec.emplace_back(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }

        if (!str.empty()) {
            dataVec.emplace_back(str);
            str.clear();
        }
        return rdeserialize(dataVec);
    }

private:
    void rseralize(TreeNode *root, std::string &str) {
        if (nullptr == root) {
            str += "None,";
        } else {
            str += std::to_string(root->val) + ",";
            rseralize(root->left, str);
            rseralize(root->right, str);   
        }
    }

    TreeNode* rdeserialize(std::vector<std::string> &dataVec) {
        if (dataVec.front() == "None") {
            dataVec.erase(dataVec.begin());
            return nullptr;
        }

        TreeNode *root = new TreeNode(stoi(dataVec.front()));
        dataVec.erase(dataVec.begin());
        root->left = rdeserialize(dataVec);
        root->right = rdeserialize(dataVec);
        return root;
    }
};
}