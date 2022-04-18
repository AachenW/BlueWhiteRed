#include <vector>
#include <iostream>

/*
@
project: leetcode
time: 2022-03-15 21:19:07
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        std::vector<int> tmp(nums1.begin(), nums1.begin() + m);

        int idx = 0;
        int start1 = 0, end1 = m, start2 = 0, end2 = n;
        while (start1 < end1 && start2 < end2) {
            nums1[idx++] = tmp[start1] < nums2[start2] ? tmp[start1++] : nums2[start2++];
        }

        while (start1 < end1) {
            nums1[idx++] = tmp[start1++];
        }
        while (start2 < end2) {
            nums1[idx++] = nums2[start2++];
        }

        return;
    }
};
}

int main(int argc,char **argv) {
    std::vector<int> nums1 {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 {2, 5 ,6};
    int m = 3, n = 3;

    leetcode_cpp::Solution().merge(nums1, m, nums2, n);

    for (int num: nums1) {
        std::cout << num << std::endl;
    }

    return 0;

}
