#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <sstream>
#include "../lib/BinaryTree.h"
/*
@
LeetCode 主站
time: 2022-01-29 22:33:41
author: edinw
@
*/

/*
**  注意：本题与主站 155 题相同：https://leetcode-cn.com/problems/min-stack/
**
**  The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.
**  Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary 
**      tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.
**  Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
struct SubtreeStatus {
    int selected;
    int notSelected;
};

class Solution {
public:
    int rob(TreeNode *root) {
        auto rootStatus = backtrack(root);
        return std::max(rootStatus.notSelected, rootStatus.selected);
    }

private:
    SubtreeStatus backtrack(TreeNode *root) {
        if (nullptr == root) {
            return {0, 0};
        }
        auto l = backtrack(root->left);
        auto r = backtrack(root->right);
        int selected = root->val + l.notSelected + r.notSelected;
        int notSelected = std::max(l.selected, l.notSelected) + std::max(r.selected, r.notSelected);
        return {selected, notSelected};
    }
};
}

void readNumsFromStr(std::string str, std::vector<std::string> &vec) {
    std::stringstream sstr(str);
    std::string buf;
    while (getline(sstr, buf, ',')) {
        vec.emplace_back(buf);
    }
    return ;
}

int main(int argc, char **argv) {
	std::vector<std::string> v;
	std::string str = "3,2,3,null,3,null,1";   //示例，leetcode上测试用例粘贴此处，删去[]
	readNumsFromStr(str, v);
    BinaryTree *bTree = new BinaryTree();
    bTree->InitTreeFromVec(v);
    TreeNode* root = bTree->GetRoot();
    std::cout << leetcode_cpp::Solution().rob(root) << std::endl;

    return 0;
}