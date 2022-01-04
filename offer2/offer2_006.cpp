#include <vector>
#include <iostream>
#include <algorithm>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-22 19:47:21
author: edinw
@
*/

/*
// 与318. Maximum Product of Word Lengths相同
// 给定一个已按照 升序排列  的整数数组 numbers ，请你从数组中找出两个数满足相加之和等于目标数 target。
// 函数应该以长度为 2 的整数数组的形式返回这两个数的下标值。numbers 的下标 从 0 开始计数 ，所以答案数组应当满足 0 <= answer[0] < answer[1]  // < numbers.length。假设数组中存在且只存在一对符合条件的数字，同时一个数字不能使用两次。
*/

namespace leetcode_cpp {
class Solution{
public:
    std::vector<int> towSum(std::vector<int>& numbers, int target) {
        decltype(numbers.size()) low = 0, high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                return {(int)low + 1, (int)high + 1};
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            }
        }
        return {-1, -1};
    }
};
}

int main(int argc, char **argv) {
    int target = 9;
    std::vector<int> numbers {2, 7, 11, 15};
    auto ans = leetcode_cpp::Solution().towSum(numbers, target);
    for (const auto &i : ans) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}