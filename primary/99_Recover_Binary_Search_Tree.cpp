#include "../lib/BinaryTree.h"

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    void recoverTree(TreeNode *root) {
        std::vector<int> nums;
        inorder(root, nums);
        auto swapped = findTwoSwapped(nums);
        recover(root, 2, swapped.first, swapped.second);
    }

private:
    void inorder(TreeNode *root, std::vector<int> &nums) {
        if (nullptr == root) {
            return;
        }

        inorder(root->left, nums);
        nums.emplace_back(root->val);
        inorder(root->right, nums);
    } 

    std::pair<int, int> findTwoSwapped(std::vector<int> &nums) {
        int n = nums.size();
        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i + 1] < nums[i]) {
                idx2 = i + 1;
                if (-1 == idx1) {
                    idx1 = i;
                } else {
                    break;
                }
            }
        }

        int x = nums[idx1], y = nums[idx2];
        return {x, y};
    }

    void recover(TreeNode *r, int count, int x, int y) {
        if (nullptr != r) {
            if (r->val == x || r->val == y) {
                r->val = r->val == x ? y : x;
                if (--count == 0) {
                    return;
                }
            }

            recover(r->left, count, x, y);
            recover(r->right, count, x, y);
        }
    }
};
}
