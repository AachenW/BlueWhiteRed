#include <vector>
#include <string>
#include <functional>
#include <iostream>

/*
@
LeetCode 
time: 2022-03-17 12:02:22
author: edinw
@
*/


namespace leetcode_cpp {
class Solution {
public:
    std::string largestNumber(std::vector<int>& nums) {
        int nSize = nums.size();
        std::vector<std::string> strs;
        for (const int num: nums) {
            strs.emplace_back(std::to_string(num));
        }

        std::function<void(int, int)> qSort = [&] (int lo, int hi) {
            if (lo >= hi) {
                return;
            }

            int picked = rand() % (hi - lo + 1) + lo;
            std::string pivot = strs[picked];
            int left = lo, right = hi;

            std::swap(strs[left], strs[picked]);

            while (left < right) {
                while (left < right && pivot + strs[right] >= strs[right] + pivot) {
                    --right;
                }

                while (left < right && pivot + strs[left] <= strs[left] + pivot) {
                    ++left;
                }

                std::swap(strs[left], strs[right]);
            }

            std::swap(strs[left], strs[lo]);

            qSort(lo, left - 1);
            qSort(left + 1, hi);
        };

        qSort(0, nSize - 1);

        std::string ans;
        for (int i = 0; i < strs.size(); ++i) {
            if (ans.empty() && "0" == strs[i] && i != strs.size() - 1) {
                continue;
            }
            ans += strs[i];
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {3, 30, 34, 5, 9};

    std::cout << leetcode_cpp::Solution().largestNumber(nums) << std::endl;

    return 0;
}