#include <vector>
#include <iostream>
#include <string>
#include <functional>

/*
@
LeetCode 剑指offer
time: 2022-02-12 21:14:41
author: edinw
@
*/

/*
**  输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string minNumber(std::vector<int> &nums) {
        std::vector<std::string> strs;
        int nSize = nums.size();
        for (const auto &num: nums) {
            strs.emplace_back(std::to_string(num));
        }
        std::function<void(std::vector<std::string>&, int, int)> quickSort;
        quickSort = [&](std::vector<std::string> &strs, int lo, int hi) {
            int selected = rand() % (hi - lo + 1) + lo;
            std::string pivot = strs[selected];

            std::swap(strs[lo], strs[selected]);
            int left = lo, right = hi;
            while (left < right) {
                while (strs[right] + pivot >= pivot + strs[right] && left < right) {
                    --right;
                }
                while (strs[left] + pivot <= pivot + strs[left] && left < right) {
                    ++left;
                }
                std::swap(strs[left], strs[right]);
            }

            std::swap(strs[lo], strs[left]);

            quickSort(strs, lo, left - 1);
            quickSort(strs, left + 1, hi);
        };

        quickSort(strs, 0, strs.size() - 1);
        std::string res;
        for (auto &str: strs) {
            res.append(str);
        }

        return res;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{3, 30, 34, 5, 9};
    std::cout << leetcode_cpp::Solution().minNumber(nums) << std::endl;
    return 0;
}