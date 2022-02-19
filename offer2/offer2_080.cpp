#include <iostream>
#include <vector>
#include <queue>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-28 19:50:04
author: edinw
@
*/

/*
**  注意：本题与主站 77 题相同： https://leetcode-cn.com/problems/combinations/
** 
**  Given two integers n and k, return all possible combinations of k numbers out of the range [1, n].
**  You may return the answer in any order.
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> combine(int n, int k) {
        backtrack(0, n, k);
        return ans;
    }

private:
    void backtrack(int cur, int n, int k) {
        if (t.size() + (n - cur + 1) < k) {
            return;
        }
        if (k == t.size()) {
            ans.emplace_back(t);
            return;
        }

        t.emplace_back(cur);
        backtrack(cur + 1, n, k);
        t.pop_back();
        backtrack(cur + 1, n, k);
        return;
    }

private:
    std::vector<int> t;
    std::vector<std::vector<int>> ans;
};
}


int main(int argc, char **argv) {
    int n = 4, k = 2;
    auto ans = leetcode_cpp::Solution().combine(n, k);
    for (const auto &nums: ans) {
        std::cout << "[" << nums[0] << "," << nums[1] << "]" << std::endl;
    }
    return 0;
}