#include <vector>
#include <iostream>
#include <algorithm>
#include "limits.h"
#include "../lib/BinaryTree.h"

/*
@
LeetCode 剑指offer
time: 2022-02-03 19:25:32
author: edinw
@
*/

/*
**  输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
**  B是A的子结构， 即 A中有出现和B相同的结构和节点值。
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    bool isSubStructure(TreeNode *A, TreeNode *B) {
        return (nullptr != A && nullptr != B) && (recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }

private:
    bool recur(TreeNode *A, TreeNode *B) {
        if (nullptr == B) {
            return true;
        }
        if (nullptr == A || A->val != B->val) {
            return false;
        }
        return recur(A->left, B->left) && recur(A->right, B->right);
    }
};
}