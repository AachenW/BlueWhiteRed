#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-20 20:43:55 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int minMoves2(std::vector<int> &nums) {
        std::srand(time(NULL));
        int n = nums.size(), ans = 0;
        int x = findKthLargest(nums, n / 2);
        for (int i = 0; i < n; ++i) ans += std::abs(nums[i] - x);
        return ans;
    }

private:
    int findKthLargest(std::vector<int> &nums, int k) {
        int lo = 0, hi = nums.size() - 1;
        int i = partition(nums, lo, hi);
        while (i != k - 1) {
            if (i > k - 1) {
                hi = i - 1;
            } else {
                lo = i + 1;
            }
            i = partition(nums, lo, hi);
        }
        return nums[i];
    }

    int partition(std::vector<int> &nums, int lo, int hi) {
        int rad = rand() % (hi - lo + 1) + lo;
        std::swap(nums[lo], nums[rad]);
        int pivot = nums[lo], startIndex = lo;
        
        while (lo < hi) {
            while (lo < hi && nums[hi] >= pivot) {
                --hi;
            }
            while (lo < hi && nums[lo] <= pivot) {
                ++lo;
            }
            std::swap(nums[lo], nums[hi]);
        }
        std::swap(nums[startIndex], nums[lo]);
        return lo;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1, 10, 2, 9};
    std::cout << leetcode_cpp::Solution().minMoves2(nums) << std::endl;
    return 0;
}
