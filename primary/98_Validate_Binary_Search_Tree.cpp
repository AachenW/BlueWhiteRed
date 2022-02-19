#include <iostream>
#include "../lib/BinarySearchTree.h"
#include <algorithm>
#include <vector>
#include "limits.h"
/*
@
projetc: leetcode HOT 100
time: 2022-02-04 22:19:30
author: edinw
@
*/

using namespace binary_search_tree;

namespace leetcode_cpp {
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        std::vector<int> nums;
        std::vector<TreeNode*> stack;
        while (!stack.empty() || nullptr != root) {
            while (nullptr != root) {
                stack.emplace_back(root);
                root = root->left;
            }
            if (!stack.empty()) {
                root = stack.back();
                nums.emplace_back(root->val);
                stack.pop_back();
                root = root->right;
            }
        }
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] >= nums[i + 1]) {
                return false;
            }
        }
        return true;
    }
};

class Solution2 {
public:
    bool isValidBST(TreeNode *root) {
        std::vector<int> nums;
        
        backtrack(root, nums);

        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] >= nums[i + 1]) {
                return false;
            }
        }
        return true;
    }

private:
    void backtrack(TreeNode *root, std::vector<int> &nums) {
        if (nullptr == root) {
            return;
        }

        backtrack(root->left, nums);
        nums.emplace_back(root->val);
        backtrack(root->right, nums);
    }
};

class Solution3 {
public:
    bool isValidBST(TreeNode *root) {
        return backtrack(root, LONG_MIN, LONG_MAX);
    }

private:
    bool backtrack(TreeNode *root, long long lower, long long upper) {
        if (nullptr == root) {
            return;
        }
        if (root->val <= lower || root->val >= upper) {
            return false;
        }
        return backtrack(root->left, lower, root->val) && backtrack(root->right, root->val, upper);
    }
};
}

int main(int argc, char **argv) {
    BinarySearchTree *bTree = new BinarySearchTree();
    std::vector<int> nums{1, 2, 3};
    bTree->InitTree(nums);
    TreeNode *root = bTree->GetRoot();
    std::cout << std::boolalpha << leetcode_cpp::Solution().isValidBST(root) << std::endl;
    delete bTree;
    return 0;
}