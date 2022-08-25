#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"
/*
@
project: Leetcode
time: 2022-05-01 10:33:16
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        std::vector<int> nums1;
        std::vector<int> nums2;

        std::function<void(TreeNode*, std::vector<int>&)> inorder = [&] (TreeNode *root, std::vector<int> &nums) {
            if (nullptr == root) {
                return;
            }

            inorder(root->left, nums);
            nums.emplace_back(root->val);
            inorder(root->right, nums);
        };

        inorder(root1, nums1);
        inorder(root2, nums2);
        
        std::vector<int> ans;
        auto merge = [&] () {
            int left1 = 0, right1 = nums1.size();
            int left2 = 0, right2 = nums2.size();

            while (left1 < right1 && left2 < right2) {
                if (nums1[left1] < nums2[left2]) {
                    ans.emplace_back(nums1[left1++]);
                } else {
                    ans.emplace_back(nums2[left2++]);
                }
            }

            while (left1 < right1) {
                ans.emplace_back(nums1[left1++]);
            }
            while (left2 < right2) {
                ans.emplace_back(nums2[left2++]);
            }
        };

        return ans;
    }
};
}

int main(int argc, char **argv) {
    
}