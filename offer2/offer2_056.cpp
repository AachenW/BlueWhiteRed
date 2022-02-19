#include <iostream>
#include <deque>
#include "BinarySearchTree.h"
#include <unordered_set>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-18 22:27:34
author: edinw
@
*/

/*
**  注意：本题与主站 653 题相同： https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/
** 
**  给定一个二叉搜索树的 根节点 root 和一个整数 k , 请判断该二叉搜索树中是否存在两个节点它们的值之和等于 k 。假设二叉搜索树中节点的值均唯一。
*/

using namespace binary_search_tree;

namespace leetcode_cpp {
class Solution {
    std::unordered_set<int> hashMap;
public:
    bool findTarget(TreeNode *root, int k) {
        bool find = false;
        backtrack(root, k, find);
        return find;
    }

private:
    void backtrack(TreeNode *root, int k, bool &find) {
        if (nullptr == root) {
            return ;
        }

        backtrack(root->left, k, find);
        if (hashMap.count(k - root->val)) {
            find = true;
        }
        if (!hashMap.count(root->val)) {
            hashMap.insert(root->val);
        }
        
        backtrack(root->right, k, find);
    }
};

class Solution2 {
public:
    bool findTarget(TreeNode *root, int k) {
        if (nullptr == root) {
            return false;
        }
        std::unordered_set<int> hashMap;
        std::deque<TreeNode*> stack;
        TreeNode *cur = root;
        while (nullptr != cur || !stack.empty()) {
            while (nullptr != cur) {
                stack.emplace_back(cur);
                cur = cur->left;
            }
            cur = stack.back();
            stack.pop_back();
            if (hashMap.count(k - cur->val)) {
                return true;
            }
            hashMap.insert(cur->val);
            cur = cur->right;
        }
        return false;
    }
};

class Solution3 {
    TreeNode *leftCur;
    TreeNode *rightCur;
    std::deque<TreeNode*> leftStack;
    std::deque<TreeNode*> rightStack;
public:
    bool findTarget(TreeNode *root, int k) {
        if (nullptr == root) {
            return false;
        }
        leftCur = root;
        rightCur = root;
        int left = leftInorderTraverse();
        int right = rightInorderTraverse();
        while (left < right) {
            int sum = left + right;
            if (sum == k) {
                return true;
            }
            if (sum < k) {
                left = leftInorderTraverse();
            } else {
                right = rightInorderTraverse();
            }
        }
        return false;
    }

private:
    int leftInorderTraverse() {
        while (nullptr != leftCur) {
            leftStack.emplace_back(leftCur);
            leftCur = leftCur->left;
        }
        leftCur = leftStack.back();
        leftStack.pop_back();
        int ret = leftCur->val;
        leftCur = leftCur->right;
    }

    int rightInorderTraverse() {
        while (rightCur != nullptr) {
            rightStack.emplace_back(rightCur);
            rightCur = rightCur->right;
        }
        rightCur = rightStack.back();
        rightStack.pop_back();
        int ret = rightCur->val;
        rightCur = rightCur->left;
        return ret;
    }

};
}

int main(int argc, char **argv) {
    BinarySearchTree bst;
    std::vector<int> nums {1,0,4,-2,3};
    bst.InitTree(nums);
    bst.Traversal(1);
    std::cout << std::endl;
    TreeNode *root = bst.GetRoot();
    leetcode_cpp::Solution().findTarget(root, 7);
}