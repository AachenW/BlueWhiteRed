#include <iostream>
#include <vector>
#include <string>
#include "limits.h"
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-23 22:49:52
author: edinw
@
*/

/*
**  注意：本题与主站 421 题相同： https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/
** 
**  Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
*/

namespace leetcode_cpp {
class Trie {
    Trie *left, *right;
    static constexpr int HIGHT_BIT = 30;
public:
    Trie() : left(nullptr), right(nullptr) {}

    void Insert(int n) {
        Trie *node = this;
        for (int i = HIGHT_BIT; i >= 0; --i) {
            int bit = (n >> i) & 1;
            if (0 == bit) {
                if (nullptr == node->left) {
                    node->left = new Trie();
                }
                node = node->left;
            } else {
                if (nullptr == node->right) {
                    node->right = new Trie();
                }
                node = node->right;
            }
        }
    }

    // 返回该数字在字典树种对应的最大异或结果
    int maxXOR(int num) {
        Trie *node = this;
        int ret = 0;
        for (int i = HIGHT_BIT; i >= 0; --i) {
            // 从最高位开始进行查找
            int bit = (num >> i) & 1;
            // 若存在与该位不同的数位则选择不同的数位对应的子节点
            if (0 == bit) {
                if (nullptr != node->right) {
                    node = node->right;
                    ret = ret * 2 + 1;
                } else {
                    node = node->left;
                    ret *= 2;
                }
            } else {
                if (nullptr != node->left) {
                    node = node->left;
                    ret = ret * 2 + 1;
                } else {
                    node = node->right;
                    ret *= 2;
                }
            }
        }
        return ret;
    }
};

/*
**  构造前缀树时每个数的长度都为 32 位，所以插入一个数字的时间复杂度为 O(1)，插入所有数字的时间复杂度为 O(nlogc)，同理查找所有数字的最大异或结果的时间复杂度也为 O(n)，故最终整个
**  算法的时间复杂度为 O(nlogc)。 其中 n 是数组 nums 的长度，C 是数组中的元素范围，在本题中 C < 2^31.
*/
class Solution {    
public:
    int findMaximumXOR(std::vector<int> &nums) {
        Trie *root = new Trie();

        int maxVal = 0;
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            root->Insert(nums[i - 1]);
            maxVal = std::max(maxVal, root->maxXOR(nums[i]));
        }
        delete root;
        return maxVal;
    }
};
}

int main (int argc, char **argv) {
    std::vector<int> nums {14,70,53,83,49,91,36,80,92,51,66,70};
    std::cout << leetcode_cpp::Solution().findMaximumXOR(nums) << std::endl;
    return 0;
}

