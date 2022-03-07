#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

/*
@
projetc: leetcode
time: 2022-03-07 12:59:22
author: edinw
@
*/

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        int nSize = nums.size();
        
        std::function<void(int, int, int)> qSort = [&] (int lo, int hi, int k){
            if (lo >= hi) {
                return;
            }
            int picked = rand() % (hi - lo + 1) + lo;
            int pivot = nums[picked];
            int left = 0, right = hi;

            std::swap(nums[left], nums[picked]);

            while (left < right) {
                while (left < right && nums[right] <= pivot) {
                    --right;
                }
                while (left < right && nums[left] >= pivot) {
                    ++left;
                }
                std::swap(nums[left], nums[right]);
            }

            std::swap(nums[left], nums[lo]);

            if (left - lo + 1 == k) {
                return;
            } else {
                if (left - lo + 1 > k) {
                    qSort(lo, left - 1, k);
                } else {
                    qSort(left + 1, hi, k - left + lo - 1);
                }
            }
        };

        qSort(0, nSize - 1, k);

        return nums[k - 1];
    }
};

int main(int argc, char **argv) {
    std::vector<int> nums{3,2,3,1,2,4,5,5,6};
    int k = 4;

    std::cout << Solution().findKthLargest(nums, k) << std::endl;

    return 0;
}