#include <string>
#include <algorithm>
#include <iostream>
#include "../lib/BinaryTree.h"
#include <deque>

/*
@
projetc: leetcode
time: 2022-02-06 22:38:56
author: edinw
@
*/

/*
**  序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
**  请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
**  提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Codec {
public:
    // Encodes a tree a single string.
    std::string serialize(TreeNode* root) {
        std::string str;
        rserialize(root, str);
        return str;
    }

    //Decodes your encoded data to tree.
    TreeNode* deserialize(std::string str) {
        std::deque<std::string> nums;
        splitStr(str, nums);
        return rdeserialize(nums);
    }

private:
    TreeNode* rdeserialize(std::deque<std::string> &nums) {
        if ("null" == nums.front()) {
            nums.pop_front();
            return nullptr;
        }
        int curr = stoi(nums.front());
        nums.pop_front();
        TreeNode *node = new TreeNode(curr);
        node->left = rdeserialize(nums);
        node->right = rdeserialize(nums);
        return node;
    }

    void splitStr(std::string &str, std::deque<std::string> &nums) {
        std::string temp;
        for (const auto &ch: str) {
            if (',' == ch) {
                nums.emplace_back(temp);
                temp.clear();
            } else {
                temp.push_back(ch);
            }
        }

        if (!temp.empty()) {
            nums.emplace_back(temp);
        }
    }
    void rserialize(TreeNode *root, std::string &str) {
        if (nullptr == root) {
            str += "null,";
            return;
        }
        str += std::to_string(root->val) + ",";
        rserialize(root->left, str);
        rserialize(root->right, str);
    }
};
}