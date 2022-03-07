#include <vector>
#include <iostream>
#include <functional>

/*
@
LeetCode 剑指offer
time: 2022-02-20 22:39:28
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int reversePairs(std::vector<int> &nums) {
        int nSize = nums.size();
        std::vector<int> tmp(nSize);

        std::function<int(int, int)> mergeSort = [&](int lo, int hi) -> int {
            if (lo >= hi) {
                return 0;       // 不存在逆序对
            }

            // 递归划分
            int mid = (lo + hi) >> 1;
            int res = mergeSort(lo, mid) + mergeSort(mid + 1, hi);

            // 合并阶段
            int i = lo, j = mid + 1;
            for (int k = lo; k <= hi; ++k) {
                tmp[k] = nums[k];
            }

            for (int k = lo; k <= hi; ++k) {
                if (i == mid + 1) {
                    nums[k] = tmp[j++];
                } else if (j == hi + 1 || tmp[i] <= tmp[j]) {
                    nums[k] = tmp[i++];
                } else {    // tmp[i] > tmp[j], 所以num[i, ..., m]都为num[j]的逆序数
                    nums[k] = tmp[j++];
                    res += mid - i + 1;
                }
            }

            return res;
        };

        return mergeSort(0, nSize - 1);
    }
};
}

int main(int argc, char **argv) {

}