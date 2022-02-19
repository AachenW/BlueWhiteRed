#include <vector>
#include <algorithm>
#include <iostream>
#include <deque>
/*
@
project: Leetcode
time: 2022-01-28 18:54:21
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int numberOfWeakCharacters(std::vector<std::vector<int>>& properties) {
        // 攻击递减排列, 让防御力递增排列。这样，防御力如果小于之前记录的最大防御，那么攻击力一定不可能相等，因为攻击力相等时防御力是递增的
        sort(properties.begin(), properties.end(), [] (const auto &vec1, const auto &vec2) {
            return vec1[0] == vec2[0] ? (vec1[1] < vec2[1]) : (vec1[0] > vec2[0]);
        });

        int maxDef = 0;
        int ans = 0;
        for (const auto &p: properties) {
            if (p[1] < maxDef) {
                ++ans;
            } else {
                maxDef = p[1];
            }
        }
        return ans;
    }
};

class Solution2{
public:
    int numberOfWeakCharacters(std::vector<std::vector<int>> &properties) {
        // 按照角色攻击值的大小从低到高依次遍历每个元素，使用单调递增栈保存所有角色的防御值，遍历时如果发现栈顶的角色 p 的防御值小于当前的角色 q 的防御值，则可以认为找到攻击值和防御值都严格大于 p 的角色 q。
        sort(properties.begin(), properties.end(), [](const auto &vec1, const auto &vec2) {
            return vec1[0] == vec2[0] ? (vec1[1] > vec2[1]) : (vec1[0] < vec2[0]);
        });
        
        std::deque<int> stack;
        int ans = 0;
        for (const auto &p: properties) {
            while (!stack.empty() && stack.back() < p[1]) {
                ++ans;
                stack.pop_back();
            }
            stack.emplace_back(p[1]);
        }
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> nums{{1, 5}, {10, 4}, {4, 3}};
    std::cout << leetcode_cpp::Solution().numberOfWeakCharacters(nums) << std::endl;
    return 0;
}