#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-25 22:13:37
author: edinw
@
*/

/*
**  注意：本题与主站 215 题相同： https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
** 
**  Given an integer array nums and an integer k, return the kth largest element in the array.
**  Note that it is the kth largest element in the sorted order, not the kth distinct element.
*/

namespace leetcode_cpp {
class Solution {
public:
    int findKthLargest(std::vector<int> &nums, int k) {
        // 小根堆
        std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (const auto &num: nums) {
            pq.emplace(num);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};

class Solution2 {
public:
    int findKthLargest(std::vector<int> &nums, int k) {
        int lo = 0, hi = nums.size() - 1;
        int i = partition(nums, lo, hi);
        while (i != k - 1) {
            i < k - 1 ? lo = i  + 1: hi = i - 1;
            i = partition(nums, lo, hi);
        }
        return nums[i];
    }

private:
    int partition(std::vector<int> &nums, int lo, int hi) {
        int rad = rand() % (hi - lo + 1) + lo;
        std::swap(nums[rad], nums[lo]);
        int pivot = nums[lo], start = lo;
        ++lo;
        while (lo < hi) {
            while (lo < hi && nums[hi] >= pivot) {
                --hi;
            }
            nums[hi] = nums[lo];
            while (lo < hi && nums[lo] <= pivot) {
                ++lo;
            }
            nums[lo] = nums[hi];
        }
        std::swap(nums[lo], nums[start]);
        return lo;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {3,2,1,5,6,4};
    int k = 2;
    std::cout << leetcode_cpp::Solution2().findKthLargest(nums, k) << std::endl;
    return 0;
}