#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
/*
@
LeetCode 剑指offer
time: 2022-01-31 09:24:39
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int search(std::vector<int> &nums, int target) {
        std::vector<int>::iterator low = getFirstLowerNumber(nums.begin(), nums.end(), target);
        decltype(low) up = getFirstLowerNumber(nums.begin(), nums.end(), target + 1);
        ptrdiff_t diff = up - low;

        return diff;
    }

private:
    auto getFirstLowerNumber(std::vector<int>::iterator first, std::vector<int>::iterator last, int target) -> decltype(first) {
        std::vector<int>::iterator it;
        std::iterator_traits<std::vector<int>::iterator>::difference_type count, step;
        count = std::distance(first, last);
        while (count > 0) {
            it = first;
            step = count >> 1;
            std::advance(it, step);
            if (*it < target) {
                first = ++it;
                count -= step + 1;
            } else {
                count = step;
            }
            return first;
        }
    }

    int binarySearch(std::vector<int> &nums, int target, bool lower) {
        int lo = 0, hi = (int)nums.size() - 1, ans = (int)nums.size();
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo;
    }
};
}

int main(int argc, char** argv) {
    std::vector<int> nums {5, 7, 7, 8, 8, 10};
    int target = 6;
    std::cout << leetcode_cpp::Solution().search(nums, target) << std::endl;
    return 0;
}