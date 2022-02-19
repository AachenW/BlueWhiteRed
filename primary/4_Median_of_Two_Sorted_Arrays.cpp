#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <numeric>

/*
@
LeetCode 精选 TOP 面试题
time: 2021-12-10 20:52:34
author: edinw
@
*/

namespace leetcode_cpp {
class Solution{
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if (totalLength % 2 == 1) {
            return getKthElement(nums1, nums2, (totalLength + 1) / 2);
        } else {
            return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
        }
    }

private:
    int getKthElement(std::vector<int>& nums1, std::vector<int>& nums2, int k) {
        /* 主要思路：要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
         * 这里的 "/" 表示整除
         * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
         * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
         * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
         * 这样 pivot 本身最大也只能是第 k-1 小的元素
         * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
         * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
         * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
         */

        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0, index2 = 0;

        while (true) {
            // 若此轮nums1的搜索起点越界，则从nums2中搜索第k小的数
            if (index1 == m) {
                return nums2[index2 + k - 1];
            }
            // 若此轮nums2的搜索起点越界，则从nums1中搜索第k小的数
            if (index2 == n) {
                return nums1[index1 + k - 1];
            }
            // 若k为1，则从nums1和nums2中返回较小值
            if (k == 1) {
                return std::min(nums1[index1], nums2[index2]);
            }

            // 设置此轮搜索中nums1的比较点
            int newIndex1 = std::min(index1 + k / 2 - 1, m - 1);
            int pivot1 = nums1[newIndex1];
            // 设置此轮搜索中nums1的比较点
            int newIndex2 = std::min(index2 + k / 2 - 1, n - 1);
            int pivot2 = nums2[newIndex2];

            // 若pivot1 <= pivot2，则nums1中pivot1前的所有数字都被舍弃
            if (pivot1 <= pivot2) {
                // 更新k
                k -= newIndex1 - index1 + 1;
                // 设置新一轮nums1的搜索起点
                index1 = newIndex1 + 1;
            } else {
                // 更新k
                k -= newIndex2 - index2 + 1;
                // 设置新一轮nums2的搜索起点
                index2 = newIndex2 + 1;
            }
        }
    }
};
}